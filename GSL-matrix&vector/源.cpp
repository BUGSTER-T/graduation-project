#include <stdio.h>
#include <gsl/gsl_matrix.h>
//3X3矩阵
int main(void)
{
    gsl_matrix* m = gsl_matrix_alloc(3, 3); // 创建一个3x3的矩阵

    // 给矩阵赋值
    gsl_matrix_set(m, 0, 0, 1.0);
    gsl_matrix_set(m, 0, 1, 2.0);
    gsl_matrix_set(m, 0, 2, 3.0);
    gsl_matrix_set(m, 1, 0, 4.0);
    gsl_matrix_set(m, 1, 1, 5.0);
    gsl_matrix_set(m, 1, 2, 6.0);
    gsl_matrix_set(m, 2, 0, 7.0);
    gsl_matrix_set(m, 2, 1, 8.0);
    gsl_matrix_set(m, 2, 2, 9.0);

    // 打印矩阵
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%g ", gsl_matrix_get(m, i, j));
        }
        printf("\n");
    }

    gsl_matrix_free(m); // 释放矩阵内存

    return 0;
}
//#include <stdio.h>
//#include <gsl/gsl_vector.h>
////长度为4的向量
//int main()
//{
//    gsl_vector* v = gsl_vector_alloc(4); // 动态分配长度为4的向量
//    gsl_vector_set(v, 0, 1.0); // 设置第1个元素值为1
//    gsl_vector_set(v, 1, 2.0); // 设置第2个元素值为2
//    gsl_vector_set(v, 2, 3.0); // 设置第3个元素值为3
//    gsl_vector_set(v, 3, 4.0); // 设置第4个元素值为4
//
//    printf("Vector v = (%g, %g, %g, %g)\n", gsl_vector_get(v, 0), gsl_vector_get(v, 1), gsl_vector_get(v, 2), gsl_vector_get(v, 3));
//
//    gsl_vector_free(v); // 释放向量内存
//    return 0;
//}