#include <stdio.h>
#include <gsl/gsl_wavelet.h>
//���������С���任
int main()
{
    int i;
    const int n = 8;
    double data[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0 };
    gsl_wavelet* w;
    gsl_wavelet_workspace* work;

    // ����С������
    w = gsl_wavelet_alloc(gsl_wavelet_daubechies, 4);

    // ���������ռ�
    work = gsl_wavelet_workspace_alloc(n);

    // ����С���任
    gsl_wavelet_transform_forward(w, data, 1, n, work);

    // ���С���任���

    printf("Wavelet coefficients:\n");
    for (i = 0; i < n; i++) {
        printf("%g ", data[i]);
    }
    printf("\n");

    // �ͷ���Դ
    gsl_wavelet_free(w);
    gsl_wavelet_workspace_free(work);

    return 0;
}