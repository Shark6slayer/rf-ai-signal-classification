# Results and Verification

## HLS Kernel Verification

The RF HLS kernel was functionally verified using a C/C++ testbench.

### Test Configuration

- Input samples: 1024
- Data type: 32-bit floating point
- Operation: input × 2
- Pipeline target: II = 1

### Verification Result

```text
RF KERNEL TEST PASSED
1024 samples verified
Operation: output = input × 2