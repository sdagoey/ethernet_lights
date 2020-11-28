#include "main.h"
#include "fft.h"
#include "type_def.h"
#include "arm_common_tables.h"
#include "arm_const_structs.h"
#define FFT_Length_Tab 256
#define FFT_INVERSE_FLAG 0
#define FFT_Normal_OUTPUT_FLAG 1
#define FFT_BIT_REVERSAL_FLAG 1
#define FFT_CENTER 127
float32_t fft_dataset[FFT_Length_Tab*2];
float32_t fft_mag_data[FFT_Length_Tab];
uint16_t txdata[FFT_Length_Tab];
extern int compute_done;
//arm_cfft_instance_f32  FFT_F32_struct;

void FFT_PROCESSING(){
	/**
	  * @brief  This function Calculate FFT in F32.
	  * @param  FFT Length : 1024, 256, 64
	  * @retval None
	  */

	float32_t maxValue;
	uint32_t maxIndex;
	//arm_cfft_init_f32(&FFT_F32_struct, FFT_Length, FFT_INVERSE_FLAG, FFT_Normal_OUTPUT_FLAG);
	//arm_status status=arm_cfft_init_f32(&FFT_F32_struct,FFT_Length);
	//FFT_F32_struct.fftLen = FFT_Length;
	//FFT_F32_struct.pTwiddle = twiddleCoef_256;
	//FFT_F32_struct.pBitRevTable = armBitRevIndexTable256;
	//FFT_F32_struct.bitRevLength = ARMBITREVINDEXTABLE_256_TABLE_LENGTH;
	arm_cfft_f32(&arm_cfft_sR_f32_len256, fft_dataset, FFT_INVERSE_FLAG,FFT_BIT_REVERSAL_FLAG);
	arm_cmplx_mag_f32(fft_dataset, fft_mag_data, FFT_Length_Tab);
	fft_mag_data[0] = 0;
	arm_max_f32(fft_mag_data,FFT_Length_Tab,&maxValue, &maxIndex);
	fft_to_lights();
	//txdata = fft_mag_data;
	udp_scratch_send((uint16_t) maxIndex,2);
}

void fft_to_lights(){
	int b = 0;
	int g = 0;
	int r = 0;
	int bass_limit = 3+FFT_CENTER;
	int high_limit = 60+FFT_CENTER;
	int mid_limit = 24+FFT_CENTER;
	uint32_t sumb = 0;
	uint32_t sumg = 0;
	uint32_t sumr = 0;
	HAL_GPIO_WritePin(GPIOB,LD1_Pin,0);
	HAL_GPIO_WritePin(GPIOB,LD2_Pin,0);
	HAL_GPIO_WritePin(GPIOB,LD3_Pin,0);
	for(b=FFT_CENTER; b < (bass_limit); b++){
		sumb += (uint32_t) fft_mag_data[b];
	}
	for(g = b; g < mid_limit; g++){
		sumg += (uint32_t) fft_mag_data[g];
	}
	for(r=g; r < high_limit; r++){
		sumr += (uint32_t) fft_mag_data[r];
	}
	sumb = sumb / (bass_limit-FFT_CENTER);
	sumg = sumg / (mid_limit-FFT_CENTER);
	sumr = sumr / (high_limit-FFT_CENTER);
	if(sumb > sumg){
		if(sumb > sumr){
			HAL_GPIO_WritePin(GPIOB,LD2_Pin,1);
		}
		else{
			HAL_GPIO_WritePin(GPIOB,LD3_Pin,1);
		}
	}
	else if(sumg > sumr){
		HAL_GPIO_WritePin(GPIOB,LD1_Pin,1);
	}
	else if(sumr > 1){
		HAL_GPIO_WritePin(GPIOB,LD3_Pin,1);
	}
	compute_done = 1;

}
