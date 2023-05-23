#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv.h>
 //自适应步长法解常微分方程
int func (double t, const double y[], double f[], void *params)
{// 定义微分方程组
 double mu = *(double *)params;
 f[0] = y[1];
 f[1] = -y[0] - mu*y[1]*(y[0]*y[0] - 1);
 return GSL_SUCCESS;
}
 
int jac (double t, const double y[], double *dfdy, double dfdt[], void *params)
{
 double mu = *(double *)params;
 gsl_matrix_view dfdy_mat = gsl_matrix_view_array (dfdy, 2, 2);
 gsl_matrix * m = &dfdy_mat.matrix;
 gsl_matrix_set (m, 0, 0, 0.0);
 gsl_matrix_set (m, 0, 1, 1.0);
 gsl_matrix_set (m, 1, 0, -2.0*mu*y[0]*y[1] - 1.0);
 gsl_matrix_set (m, 1, 1, -mu*(y[0]*y[0] - 1.0));
 dfdt[0] = 0.0;
 dfdt[1] = 0.0;
 return GSL_SUCCESS;
}

int main(void)
{
    const gsl_odeiv_step_type* T = gsl_odeiv_step_rk8pd;
    gsl_odeiv_step* s = gsl_odeiv_step_alloc(T, 2);
    gsl_odeiv_control* c = gsl_odeiv_control_y_new(1e-5, 0.0);
    double mu = 10;
    gsl_odeiv_system sys = { func, jac, 2, &mu };
    double t = 0.0, t1 = 100.0;
    double h = 1e-2; // 步进为 h
    double* ph = &h;
    double y[2] = { 1.0, 0.0 }; //初值
    double y_const[2];
    double y_err[2];
    double dydt_in[2], dydt_out[2];
    int status;

    GSL_ODEIV_FN_EVAL(&sys, t, y, dydt_in); //计算初始时刻的dy/dt
    while (t < t1)
    {
        gsl_odeiv_step_apply(s, t, h, y_const, y_err, dydt_in, dydt_out, &sys);
        status = gsl_odeiv_control_hadjust(c, s, y_const, y_err, dydt_in, ph);
        gsl_odeiv_step_reset(s);

        status = gsl_odeiv_step_apply(s, t, h, y, y_err, dydt_in, dydt_out, &sys);

        y_const[0] = y[0];
        y_const[1] = y[1];

        if (status != GSL_SUCCESS) break;
        dydt_in[0] = dydt_out[0];
        dydt_in[1] = dydt_out[1];
        t += h;
        printf("%.5e %.5e %.5e\n", t, y[0], y[1]);
    }
    gsl_odeiv_control_free(c);
    gsl_odeiv_step_free(s);
    return 0;
}