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

void FFT_PROCESSING(){
	/**
	  * @brief  This function Calculate FFT in F32.
	  * @param  FFT Length : 1024, 256, 64
	  * @retval None
	  */

	float32_t maxValue;


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
	fft_basic_lights();
	//txdata = fft_mag_data;

}

void fft_basic_lights(){
//	int b = 0;
//	int g = 0;
//	int r = 0;
	int bass_limit = 3;
	int high_limit = 24;
	HAL_GPIO_WritePin(GPIOB,LD1_Pin,0);
	HAL_GPIO_WritePin(GPIOB,LD2_Pin,0);
	HAL_GPIO_WritePin(GPIOB,LD3_Pin,0);
	if(maxIndex <= bass_limit){
		HAL_GPIO_WritePin(GPIOB,LD2_Pin,1);
	}
	else if(maxIndex > bass_limit && maxIndex <= high_limit){
		HAL_GPIO_WritePin(GPIOB,LD1_Pin,1);
	}
	else HAL_GPIO_WritePin(GPIOB,LD3_Pin,1);

}

void fft_to_lights(){

}
