#ifndef __FFT_H
#define __FFT_H

void FFT_PROCESSING();
void fft_basic_lights();
void fft_to_lights();
int light_evaluation_integral(int sum, int prev_sum, int max_delta, int min_value);
int light_evaluation_differential(int sum, int prev_sum, int max_delta, int min_value);
int is_greater_val(int sumr, int compare);
int light_evaluation_moving_average(int sum, int prev_sum, int max_delta, int min_value);
#endif /* __FFT_H */
