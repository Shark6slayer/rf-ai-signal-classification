#include <cmath>

void rf_preprocess(
    const float *I,
    const float *Q,
    float *magnitude,
    int n
) {
    for (int i = 0; i < n; i++) {
        magnitude[i] = std::sqrt(
            I[i] * I[i] +
            Q[i] * Q[i]
        );
    }
}
