#include "main.h"
#include "fft.h"
#include "type_def.h"
#include "arm_common_tables.h"
#include "arm_const_structs.h"
#include "udp_scratch.h"
#define FFT_Length_Tab 256
#define FFT_INVERSE_FLAG 0
#define FFT_BIT_REVERSAL_FLAG 1
#define FFT_CENTER 1
extern float32_t fft_dataset[FFT_Length_Tab*2];
float32_t fft_half_dataset[FFT_Length_Tab];
uint16_t txdata[FFT_Length_Tab];
extern int compute_done;
float32_t fft_mag_data[2*FFT_Length_Tab];
uint32_t maxIndex;
float32_t maxValue;
extern TIM_HandleTypeDef htim4;

void FFT_PROCESSING(){
	/**
	  * @brief  This function Calculate FFT in F32.
	  * @param  FFT Length : 1024, 256, 64
	  * @retval None
	  */
	float32_t fft_double_dataset[FFT_Length_Tab*4];
	memset(fft_double_dataset,0,sizeof(fft_double_dataset));
	memcpy(fft_double_dataset,fft_dataset,sizeof(fft_dataset));
	arm_cfft_f32(&arm_cfft_sR_f32_len512, fft_double_dataset, FFT_INVERSE_FLAG,FFT_BIT_REVERSAL_FLAG);
	arm_cmplx_mag_f32(fft_double_dataset, fft_mag_data, FFT_Length_Tab);
	fft_mag_data[0] = 0;
	//udp_scratch_send(fft_dataset, 256*2);
	//memcpy(fft_half_mag_data,fft_mag_data+FFT_CENTER,128);
	arm_max_f32(fft_mag_data,FFT_Length_Tab*2,&maxValue, &maxIndex);
	//udp_scratch_send(fft_mag_data, 256);
//	udp_scratch_send(&maxValue, 1);
//	udp_scratch_send(&maxIndex, 1);
//	for(int i = 0; i<256; i++){
//		gcvt(fft_mag_data[i],2,fft_string_data[i]);
//	}
	//char * test_string = {"TEST_STRING"};
	//udp_scratch_send(fft_dataset, 256*2);
	//udp_scratch_send(fft_dataset, 256*2);
	compute_done = 1;
	fft_to_lights();
	//txdata = fft_mag_data;

}

void fft_basic_lights(){
//	int b = 0;
//	int g = 0;
//	int r = 0;
	int bass_end = 3;
	int high_end = 24;
	HAL_GPIO_WritePin(GPIOB,LD1_Pin,0);
	HAL_GPIO_WritePin(GPIOB,LD2_Pin,0);
	HAL_GPIO_WritePin(GPIOB,LD3_Pin,0);
	if(maxIndex <= bass_end){
		HAL_GPIO_WritePin(GPIOB,LD2_Pin,1);
	}
	else if(maxIndex > bass_end && maxIndex <= high_end){
		HAL_GPIO_WritePin(GPIOB,LD1_Pin,1);
	}
	else HAL_GPIO_WritePin(GPIOB,LD3_Pin,1);

}
int prev_sumb = 0;
int prev_sumg = 0;
int prev_sumr = 0;
#define MAX_DELTA_HIGH 10
#define MIN_VAL_HIGH 0
#define MIN_VAL_MID 0
#define MAX_DELTA_MID 2
#define MAX_DELTA_LOW 1
#define MIN_VAL_LOW 0
int bass_start = 0;
int bass_end = 9;
int mid_start = 10;
int mid_end = 30;
int high_start = 40;
int high_end = 250;


void fft_to_lights(){
	  //TIM_CHANNEL_1 = Blue LEDs
	  //TIM_CHANNEL_2 = Red LEDs
	  //TIM_CHANNEL_3 = Green LEDs
	  	int b = 0;
	  	int g = 0;
	  	int r = 0;
	  	float32_t sumb = 0;
	  	float32_t sumg = 0;
	  	float32_t sumr = 0;
	  	float32_t local_max_value = fft_mag_data[1];

	  for(b=bass_start; b <= bass_end;b++){
		  sumb += fft_mag_data[b];
		  if(local_max_value < fft_mag_data[b]){
			  local_max_value = fft_mag_data[b];
		  }
	  }
	  for(g=mid_start; g <= mid_end;g++){
		  sumg += fft_mag_data[g];
		  if(local_max_value < fft_mag_data[g]){
			  local_max_value = fft_mag_data[g];
		  }
	  }
	  for(r=high_start; r <= high_end;r++){
		  sumr += fft_mag_data[r];
		  if(local_max_value < fft_mag_data[r]){
			  local_max_value = fft_mag_data[r];
		  }
	  }
	  sumb /= bass_end - bass_start + 1;
	  sumg /= mid_end - mid_start + 1;
	  sumr /= high_end - high_start + 1;
	  sumb = (int) (sumb / local_max_value * 100);
 	  sumg = (int) ((sumg / local_max_value  * 100));
 	  sumr = (int) ((sumr / local_max_value  * 255));
//	  sumb = (int) ((sumb / maxValue * 255));
//	  sumg = (int) (sumg / maxValue * 255);
//	  sumr = (int) (sumr / maxValue * 255);
//	  sumb = light_evaluation_integral(sumb,prev_sumb,MAX_DELTA_LOW, MIN_VAL_LOW);
//	  sumg = light_evaluation_integral(sumg,prev_sumg,MAX_DELTA_MID, MIN_VAL_MID);
//	  sumr = light_evaluation_integral(sumr,prev_sumr,MAX_DELTA_HIGH, MIN_VAL_HIGH);

	  sumb = light_evaluation_moving_average(sumb,prev_sumb,MAX_DELTA_LOW, MIN_VAL_LOW);
 	  sumg = light_evaluation_moving_average(sumg,prev_sumg,MAX_DELTA_MID, MIN_VAL_MID);
 	  sumr = light_evaluation_moving_average(sumr,prev_sumr,MAX_DELTA_HIGH, MIN_VAL_HIGH);
 	  sumb = is_greater_val(sumb,250);
 	  sumg = is_greater_val(sumg,250);
 	  sumr = is_greater_val(sumr,250);

	  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1, sumb);
	  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_3, sumg);
	  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2, sumr);
//	  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_3, 0);
//	  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2, 0);
	  prev_sumb = sumb;
	  prev_sumg = sumg;
	  prev_sumr = sumr;
}

int light_evaluation_integral(int sum, int prev_sum, int max_delta, int min_value){
	int final_sum = 0;
	if((sum < min_value) || (sum < max_delta)){
			  final_sum = 0;
		  }
		  else if((sum > max_delta + prev_sum)){
			  final_sum = prev_sum + max_delta;
		  }
		  else if(sum < prev_sum - max_delta){
			  final_sum = prev_sum - max_delta;
		  }
	return final_sum;
}

int light_evaluation_differential(int sum, int prev_sum, int max_delta, int min_value){
	int final_sum = 0;
	if (prev_sum > sum){
		final_sum = (int) (prev_sum - sum);
	}
	else if (prev_sum < sum){
		final_sum = (int) (sum - prev_sum);
	}
	//udp_scratch_send(&final_sum, 1);
	return final_sum;
}

int light_evaluation_moving_average(int sum, int prev_sum, int max_delta, int min_value){
	int final_sum = 0;
	final_sum = (prev_sum + sum) /2;
	return final_sum;
}

int is_greater_val(int sumr, int compare){
	if(sumr >= compare){
		sumr = compare;
	}
	return sumr;

}
