#include <stdio.h>
#include <gsl/gsl_matrix.h>
//3X3����
int main(void)
{
    gsl_matrix* m = gsl_matrix_alloc(3, 3); // ����һ��3x3�ľ���

    // ������ֵ
    gsl_matrix_set(m, 0, 0, 1.0);
    gsl_matrix_set(m, 0, 1, 2.0);
    gsl_matrix_set(m, 0, 2, 3.0);
    gsl_matrix_set(m, 1, 0, 4.0);
    gsl_matrix_set(m, 1, 1, 5.0);
    gsl_matrix_set(m, 1, 2, 6.0);
    gsl_matrix_set(m, 2, 0, 7.0);
    gsl_matrix_set(m, 2, 1, 8.0);
    gsl_matrix_set(m, 2, 2, 9.0);

    // ��ӡ����
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%g ", gsl_matrix_get(m, i, j));
        }
        printf("\n");
    }

    gsl_matrix_free(m); // �ͷž����ڴ�

    return 0;
}
//#include <stdio.h>
//#include <gsl/gsl_vector.h>
////����Ϊ4������
//int main()
//{
//    gsl_vector* v = gsl_vector_alloc(4); // ��̬���䳤��Ϊ4������
//    gsl_vector_set(v, 0, 1.0); // ���õ�1��Ԫ��ֵΪ1
//    gsl_vector_set(v, 1, 2.0); // ���õ�2��Ԫ��ֵΪ2
//    gsl_vector_set(v, 2, 3.0); // ���õ�3��Ԫ��ֵΪ3
//    gsl_vector_set(v, 3, 4.0); // ���õ�4��Ԫ��ֵΪ4
//
//    printf("Vector v = (%g, %g, %g, %g)\n", gsl_vector_get(v, 0), gsl_vector_get(v, 1), gsl_vector_get(v, 2), gsl_vector_get(v, 3));
//
//    gsl_vector_free(v); // �ͷ������ڴ�
//    return 0;
//}