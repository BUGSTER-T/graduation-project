#include <stdio.h>
#include <math.h>
#include <gsl/gsl_fft_real.h>
//实数FFT
#define N 16

int main(void)
{
    double data[N] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0,
                      9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0 };
    double spectrum[N / 2 + 1];

    gsl_fft_real_radix2_transform(data, 1, N);

    for (size_t i = 0; i < N / 2 + 1; i++) {
        spectrum[i] = sqrt(data[2 * i] * data[2 * i] + data[2 * i + 1] * data[2 * i + 1]);
    }

    printf("初始数据:\n");
    for (size_t i = 0; i < N; i++) {
        printf("%g ", data[i]);
    }
    printf("\n");

    printf("变换后:\n");
    for (size_t i = 0; i < N / 2 + 1; i++) {
        printf("%g ", spectrum[i]);
    }
    printf("\n");

    return 0;
}