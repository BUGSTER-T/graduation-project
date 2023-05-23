#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float* input;   // 输入数据
    float* output;  // 输出数据
    float* b;       // 分子系数
    float* a;       // 分母系数
    int order;      // 滤波器阶数
    int n;          // 当前样本数
} IIRState;

void initIIRFilter(IIRState* s, float* b, float* a, int order) {
    s->input = (float*)calloc(order + 1, sizeof(float));
    s->output = (float*)calloc(order + 1, sizeof(float));
    s->b = b;
    s->a = a;
    s->order = order;
    s->n = 0;
    memset(s->input, 0, (order + 1) * sizeof(float));
    memset(s->output, 0, (order + 1) * sizeof(float));
}

float filterIIR(IIRState* s, float x) {
    float y = 0.0;
    int i;
    s->input[0] = x;
    for (i = 0; i <= s->order; i++) {
        y += s->b[i] * s->input[i];
        if (i > 0) {
            y -= s->a[i] * s->output[i - 1];
        }
    }
    for (i = s->order; i > 0; i--) {
        s->input[i] = s->input[i - 1];
        s->output[i - 1] = s->output[i - 2];
    }
    s->output[0] = y;
    s->n++;
    return y;
}

void freeIIRFilter(IIRState* s) {
    free(s->input);
    free(s->output);
}

int main() {
    float b[] = { 1, 2, 1 };
    float a[] = { 1, -0.5, 0.25 };
    IIRState s;
    initIIRFilter(&s, b, a, 2);
    float input[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    int i;
    for (i = 0; i < 5; i++) {
        float output = filterIIR(&s, input[i]);
        printf("Input: %f, Output: %f\n", input[i], output);
    }
    freeIIRFilter(&s);
    return 0;
}