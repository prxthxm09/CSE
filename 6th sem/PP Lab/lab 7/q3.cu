#include <stdio.h>

#define N 10 // Size of vectors

__global__ void axpy(float alpha, float *x, float *y) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;

    if(tid < N) {
        y[tid] = alpha * x[tid] + y[tid];
    }
}

int main() {
    float alpha = 2.0;       // Scalar value
    float x[N], y[N];        // Input and output vectors

    // Initialize input vectors
    for(int i = 0; i < N; i++) {
        x[i] = i + 1;         // Example values
        y[i] = 10 - i;        // Example values
    }

    float *d_x, *d_y;        // Device arrays

    // Allocate memory on device
    cudaMalloc(&d_x, N * sizeof(float));
    cudaMalloc(&d_y, N * sizeof(float));

    // Copy input vectors from host to device
    cudaMemcpy(d_x, x, N * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_y, y, N * sizeof(float), cudaMemcpyHostToDevice);

    // Define grid and block dimensions
    int threadsPerBlock = 256;
    int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;

    // Launch kernel
    axpy<<<blocksPerGrid, threadsPerBlock>>>(alpha, d_x, d_y);

    // Copy result back to host
    cudaMemcpy(y, d_y, N * sizeof(float), cudaMemcpyDeviceToHost);

    // Print result
    printf("Result: ");
    for(int i = 0; i < N; i++) {
        printf("%.2f ", y[i]);
    }
    printf("\n");

    // Free device memory
    cudaFree(d_x);
    cudaFree(d_y);

    return 0;
}
