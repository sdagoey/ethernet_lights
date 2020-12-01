#ifndef __FFT_H
#define __FFT_H

void FFT_PROCESSING();
void fft_basic_lights();
void fft_to_lights();
int light_evaluation(int sum, int prev_sum, int max_delta, int min_value);
#endif /* __FFT_H */
