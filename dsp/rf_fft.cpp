#include <cmath>

#define N 1024

void rf_fft_magnitude(
    const float *input,
    float *magnitude
) {
    for (int k = 0; k < N; k++) {

        float real = 0.0f;
        float imag = 0.0f;

        for (int n = 0; n < N; n++) {
            float angle = -2.0f * M_PI * k * n / N;

            real += input[n] * std::cos(angle);
            imag += input[n] * std::sin(angle);
        }

        magnitude[k] = std::sqrt(
            real * real +
            imag * imag
        );
    }
}
