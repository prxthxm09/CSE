#include <stdio.h>
#include <math.h>

#define N 10 // Size of array

__global__ void computeSine(float *angles, float *sine) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;

    if(tid < N) {
        sine[tid] = sinf(angles[tid]);
    }
}

int main() {
    float angles[N]; // Input array containing angles in radians
    float sine[N];   // Output array containing sine values

    // Initialize input array with example angles
    for(int i = 0; i < N; i++) {
        angles[i] = (i + 1) * 0.1; // Example values
    }

    float *d_angles, *d_sine; // Device arrays

    // Allocate memory on device
    cudaMalloc(&d_angles, N * sizeof(float));
    cudaMalloc(&d_sine, N * sizeof(float));

    // Copy input array from host to device
    cudaMemcpy(d_angles, angles, N * sizeof(float), cudaMemcpyHostToDevice);

    // Define grid and block dimensions
    int threadsPerBlock = 256;
    int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;

    // Launch kernel
    computeSine<<<blocksPerGrid, threadsPerBlock>>>(d_angles, d_sine);

    // Copy result back to host
    cudaMemcpy(sine, d_sine, N * sizeof(float), cudaMemcpyDeviceToHost);

    // Print result
    printf("Sine values:\n");
    for(int i = 0; i < N; i++) {
        printf("sin(%.2f) = %.6f\n", angles[i], sine[i]);
    }

    // Free device memory
    cudaFree(d_angles);
    cudaFree(d_sine);

    return 0;
}
