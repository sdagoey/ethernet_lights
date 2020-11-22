#include "sams_discount_fft.h"
//Real index_in = 0
//img index_in = 1

float** fft_stage(float x_in[][2]){
    int N = (int) (sizeof(x_in[0])/sizeof(x_in[0][0]));
    float X_OUT[N][2];

    if(N == 2){

        X_OUT[0][0] = x_in[0][0] + x_in[1][0];
        X_OUT[0][1] = x_in[0][1] + x_in[1][1];
        X_OUT[1][0] = x_in[0][0] - x_in[1][0];
        X_OUT[1][1] = x_in[0][1] - x_in[1][1];
    }
    else{
        float *sam_twiddleCoef;
        switch (N) {
        case 4 :
             sam_twiddleCoef = sam_twiddleCoef_4;
            break;
        case 8 :
            sam_twiddleCoef = sam_twiddleCoef_8;
            break;
        case 16 :
            sam_twiddleCoef = sam_twiddleCoef_16;
            break;
        case 32:
            sam_twiddleCoef = sam_twiddleCoef_32;
            break;
        case 64:
            sam_twiddleCoef = sam_twiddleCoef_64;
            break;
        case 128:
            sam_twiddleCoef = sam_twiddleCoef_128;
            break;
        case 256:
            sam_twiddleCoef = sam_twiddleCoef_256;
            break;

        }
        int size_n = N/2 -1;
        //float W = sam_twiddleCoef_128[N]
        float evenx_in[size_n][2];
        float oddx_in[size_n][2];
        //float X_OUT0[size_n][2];
        //float X_OUT1[size_n][2];
        float WX_OUT1[size_n][2];

        for(int i =  0; i< size_n; ++i){
            //n[i] = i;
            evenx_in[i][0] = x_in[2*i][0];
            evenx_in[i][1] = x_in[2*i][1];
            oddx_in[i][0] = x_in[2*i+1][0];
            oddx_in[i][1] = x_in[2*i+1][1];
        }

        float** X_OUT0 = fft_stage(evenx_in);
        float** X_OUT1 = fft_stage(oddx_in);
        for(int i = 0; i < N; i++){
            WX_OUT1[i][0] = X_OUT1[i][0] * sam_twiddleCoef[2*i];
            WX_OUT1[i][1] = X_OUT1[i][0] * sam_twiddleCoef[2*i+1];

        }

        for(int i = 0; i < N/2; ++i){
            X_OUT[i][0] = X_OUT0[i][0] + WX_OUT1[i][0];
        }
    }
    return X_OUT;
};

