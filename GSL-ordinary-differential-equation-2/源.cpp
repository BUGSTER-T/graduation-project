#include <iostream>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_odeiv2.h>
//龙格库塔法（RK4）来解决常微分方程y'' + y = 0
int func(double t, const double y[], double f[], void* params) {
    f[0] = y[1];
    f[1] = -y[0];
    return GSL_SUCCESS;
}

int main() {
    const double y0[] = { 1.0, 0.0 };
    const double t0 = 0.0;
    const double h = 0.1;
    const double tf = 10.0;

    gsl_odeiv2_system sys = { func, NULL, 2, NULL };

    gsl_odeiv2_driver* driver = gsl_odeiv2_driver_alloc_y_new(
        &sys, gsl_odeiv2_step_rk4, h, 1e-6, 1e-6);

    double t = t0;
    double y[2] = { y0[0], y0[1] };

    std::cout << "t\ty[0]\ty[1]" << std::endl;

    while (t < tf) {
        int status = gsl_odeiv2_driver_apply(driver, &t, t + h, y);

        if (status != GSL_SUCCESS) {
            std::cerr << "error: driver returned " << status << std::endl;
            break;
        }

        std::cout << t << "\t" << y[0] << "\t" << y[1] << std::endl;
    }

    gsl_odeiv2_driver_free(driver);
    return 0;
}