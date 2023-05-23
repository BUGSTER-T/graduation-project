#include <stdio.h>
#include <math.h>

#define N 1024
#define M 21
//长度为1024的FIR滤波器，待滤波为正弦函数
float h[M] = { 0.0392, 0.0271, -0.0053, -0.0643, -0.1034, -0.0917, -0.0087, 0.1568, 0.3362, 0.4899, 0.5715, 0.5568, 0.4554, 0.3042, 0.1516, 0.0465, -0.0158, -0.0372, -0.0270, -0.0114, -0.0042 }; // FIR滤波器系数
float  M_PI = 3.14;
int main()
{
    float x[N]; // 输入信号
    float y[N]; // 输出信号

    // 生成正弦函数作为输入信号
    float f = 500; // 正弦函数的频率
    float fs = 8000; // 采样率
    for (int i = 0; i < N; i++)
    {
        x[i] = sin(2 * M_PI * f * i / fs);
    }

    // FIR滤波器
    for (int n = 0; n < N; n++)
    {
        y[n] = 0;
        for (int k = 0; k < M; k++)
        {
            if (n - k >= 0)
            {
                y[n] += h[k] * x[n - k];
            }
        }
    }

    // 输出滤波后的信号
    for (int i = 0; i < N; i++)
    {
        printf("%f\n", y[i]);
    }

    return 0;
}