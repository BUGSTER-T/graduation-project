#include <stdio.h>
#include <gsl/gsl_wavelet.h>
//对数组进行小波变换
int main()
{
    int i;
    const int n = 8;
    double data[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };
    gsl_wavelet* w;
    gsl_wavelet_workspace* work;

    // 创建小波对象
    w = gsl_wavelet_alloc(gsl_wavelet_daubechies, 4);

    // 创建工作空间
    work = gsl_wavelet_workspace_alloc(n);

    // 进行小波变换
    gsl_wavelet_transform_forward(w, data, 1, n, work);

    // 输出小波变换结果

    printf("Wavelet coefficients:\n");
    for (i = 0; i < n; i++) {
        printf("%g ", data[i]);
    }
    printf("\n");

    // 释放资源
    gsl_wavelet_free(w);
    gsl_wavelet_workspace_free(work);

    return 0;
}