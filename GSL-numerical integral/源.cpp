#include <stdio.h>
#include <gsl/gsl_integration.h>
#include <math.h>
//梯形法对正弦函数积分
double integrand(double x, void* params) {
    return sin(x);
}

int main(void) {
    gsl_integration_workspace* w
        = gsl_integration_workspace_alloc(1000);

    double result, error;

    gsl_function F;
    F.function = &integrand;
    F.params = NULL;

    gsl_integration_qags(&F, 0, M_PI, 0, 1e-7, 1000,
        w, &result, &error);

    printf("result          = % .18f\n", result);
    printf("estimated error = % .18f\n", error);

    gsl_integration_workspace_free(w);

    return 0;
}