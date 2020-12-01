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
float32_t fft_mag_data[FFT_Length_Tab];
uint32_t maxIndex;
float32_t maxValue;
extern TIM_HandleTypeDef htim4;

void FFT_PROCESSING(){
	/**
	  * @brief  This function Calculate FFT in F32.
	  * @param  FFT Length : 1024, 256, 64
	  * @retval None
	  */
	arm_cfft_f32(&arm_cfft_sR_f32_len256, fft_dataset, FFT_INVERSE_FLAG,FFT_BIT_REVERSAL_FLAG);
	arm_cmplx_mag_f32(fft_dataset, fft_mag_data, FFT_Length_Tab);
	fft_mag_data[0] = 0;
	//udp_scratch_send(fft_dataset, 256*2);
	//memcpy(fft_half_mag_data,fft_mag_data+FFT_CENTER,128);
	arm_max_f32(fft_mag_data,FFT_Length_Tab,&maxValue, &maxIndex);
	//udp_scratch_send(fft_mag_data, 256);
//	udp_scratch_send(&maxValue, 1);
	udp_scratch_send(&maxIndex, 1);
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
#define MAX_DELTA_HIGH 100
#define MIN_VAL_HIGH 10
#define MIN_VAL_MID 100
#define MAX_DELTA_MID 5
#define MAX_DELTA_LOW 5
#define MIN_VAL_LOW 0
int bass_start = 1;
int bass_end = 2;
int mid_start = 3;
int mid_end = 10;
int high_start = 11;
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
	  sumb /= bass_end - bass_start;
	  sumg /= mid_end - mid_start;
	  sumr /= high_end - high_start;
	  sumb = (uint16_t) (sumb / local_max_value * 255 / 2);
 	  sumg = (int) (sumg / local_max_value * 255);
 	  sumr = (int) (sumr / local_max_value * 255);
//	  sumb = (int) (sumb / maxValue * 255);
//	  sumg = (int) (sumg / maxValue * 255);
//	  sumr = (int) (sumr / maxValue * 255);
	  sumb = light_evaluation(sumb,prev_sumb,MAX_DELTA_LOW, MIN_VAL_LOW);
	  sumg = light_evaluation(sumg,prev_sumg,MAX_DELTA_MID, MIN_VAL_MID);
	  sumr = light_evaluation(sumr,prev_sumr,MAX_DELTA_HIGH, MIN_VAL_HIGH);
	  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1, sumb);
//	  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_3,(int) sumg);
//	  __HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_2,(int) sumr);
	  prev_sumb = sumb;
	  prev_sumg = sumg;
	  prev_sumr = sumr;
}

int light_evaluation(int sum, int prev_sum, int max_delta, int min_value){
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
