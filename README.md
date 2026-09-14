# VLSI Accelerated AI-Based RF Signal Classification System

An FPGA-oriented RF signal processing project combining digital signal processing, FFT-based spectral analysis, RF feature extraction, and Vitis HLS hardware acceleration.

## Overview

This project explores an FPGA-based workflow for processing RF I/Q signals and extracting useful signal characteristics for classification.

### Processing Flow

RF I/Q Signal  
↓  
I/Q Preprocessing  
↓  
FFT-Based Spectral Analysis  
↓  
RF Feature Extraction  
↓  
AI Classification  
↓  
Hardware Acceleration

## Current Implementation

- I/Q signal preprocessing
- RF signal magnitude calculation
- 1024-point spectral analysis
- FFT peak detection
- RF spectral feature extraction
- Vitis HLS accelerator kernel
- C/C++ functional testbenches
- HLS synthesis analysis

## Hardware Acceleration

The project includes a Vitis HLS kernel named `rf_kernal`.

The current kernel processes 1024 floating-point samples using a pipelined operation:

```text
output[i] = input[i] × 2