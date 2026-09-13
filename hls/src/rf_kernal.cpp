#include <cmath>

extern "C" void rf_kernal(float *input, float *output) {

#pragma HLS INTERFACE m_axi port=input  offset=slave bundle=gmem depth=1024
#pragma HLS INTERFACE m_axi port=output offset=slave bundle=gmem depth=1024

#pragma HLS INTERFACE s_axilite port=input  bundle=control
#pragma HLS INTERFACE s_axilite port=output bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    for (int i = 0; i < 1024; i++) {
#pragma HLS PIPELINE II=1
        output[i] = input[i] * 2.0f;
    }
}
