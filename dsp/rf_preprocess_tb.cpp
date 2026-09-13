#include <iostream>
#include <cmath>

void rf_preprocess(
    const float *I,
    const float *Q,
    float *magnitude,
    int n
);

int main() {
    const int N = 8;

    float I[N] = {1, 0, 3, 0, 5, 0, 0, 8};
    float Q[N] = {0, 2, 4, 0, 0, 12, 7, 0};
    float magnitude[N];

    rf_preprocess(I, Q, magnitude, N);

    bool pass = true;

    for (int i = 0; i < N; i++) {
        float expected = std::sqrt(I[i] * I[i] + Q[i] * Q[i]);

        if (std::fabs(magnitude[i] - expected) > 1e-5f) {
            pass = false;
            std::cout << "FAIL at index " << i << std::endl;
        }
    }

    if (pass) {
        std::cout << "==================================" << std::endl;
        std::cout << "RF PREPROCESS TEST PASSED" << std::endl;
        std::cout << "I/Q magnitude calculation verified" << std::endl;
        std::cout << "==================================" << std::endl;
        return 0;
    }

    return 1;
}
