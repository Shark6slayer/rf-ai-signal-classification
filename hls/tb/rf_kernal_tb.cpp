#include <iostream>
#include <cmath>

extern "C" void rf_kernal(float *input, float *output);

int main() {
    float input[1024];
    float output[1024];

    for (int i = 0; i < 1024; i++) {
        input[i] = (float)i / 1024.0f;
        output[i] = 0.0f;
    }

    rf_kernal(input, output);

    bool pass = true;

    for (int i = 0; i < 1024; i++) {
        float expected = input[i] * 2.0f;

        if (std::fabs(output[i] - expected) > 1e-5f) {
            std::cout << "FAIL at index " << i
                      << ": expected " << expected
                      << ", got " << output[i] << std::endl;
            pass = false;
            break;
        }
    }

    if (pass) {
        std::cout << "==================================" << std::endl;
        std::cout << "RF KERNEL TEST PASSED" << std::endl;
        std::cout << "1024 samples verified" << std::endl;
        std::cout << "Operation: output = input * 2" << std::endl;
        std::cout << "==================================" << std::endl;
        return 0;
    }

    return 1;
}
