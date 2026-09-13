#include <iostream>
#include <cmath>

#define N 1024

void rf_fft_magnitude(
    const float *input,
    float *magnitude
);

int main() {

    float input[N] = {0};
    float magnitude[N] = {0};

    // Simple sinusoidal RF-like test signal
    const int frequency_bin = 8;

    for (int n = 0; n < N; n++) {
        input[n] = std::sin(
            2.0 * M_PI * frequency_bin * n / N
        );
    }

    rf_fft_magnitude(input, magnitude);

    int peak_bin = 0;
    float peak_value = magnitude[0];

    for (int k = 1; k < N; k++) {
        if (magnitude[k] > peak_value) {
            peak_value = magnitude[k];
            peak_bin = k;
        }
    }

    std::cout << "FFT Peak Bin : " << peak_bin << std::endl;
    std::cout << "Peak Magnitude : " << peak_value << std::endl;

    if (peak_bin == frequency_bin ||
        peak_bin == N - frequency_bin) {

        std::cout << "==================================" << std::endl;
        std::cout << "FFT TEST PASSED" << std::endl;
        std::cout << "Peak frequency correctly detected" << std::endl;
        std::cout << "==================================" << std::endl;

        return 0;
    }

    std::cout << "FFT TEST FAILED" << std::endl;
    return 1;
}
