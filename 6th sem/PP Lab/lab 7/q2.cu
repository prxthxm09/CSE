#include <stdio.h>

#define N 10 // Number of elements in input array
#define M 3  // Number of elements in mask array

__global__ void convolution(int *input, int *mask, int *output) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;

    if(tid < N) {
        int result = 0;
        for(int i = 0; i < M; i++) {
            int idx = tid - M/2 + i;
            if(idx >= 0 && idx < N) {
                result += input[idx] * mask[i];
            }
        }
        output[tid] = result;
    }
}

int main() {
    int input[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Input array
    int mask[M] = {1, 0, -1};                       // Mask array
    int output[N];                                  // Resultant array

    int *d_input, *d_mask, *d_output; // Device arrays

    // Allocate memory on device
    cudaMalloc(&d_input, N * sizeof(int));
    cudaMalloc(&d_mask, M * sizeof(int));
    cudaMalloc(&d_output, N * sizeof(int));

    // Copy input and mask arrays from host to device
    cudaMemcpy(d_input, input, N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_mask, mask, M * sizeof(int), cudaMemcpyHostToDevice);

    // Define grid and block dimensions
    int threadsPerBlock = 256;
    int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;

    // Launch kernel
    convolution<<<blocksPerGrid, threadsPerBlock>>>(d_input, d_mask, d_output);

    // Copy result back to host
    cudaMemcpy(output, d_output, N * sizeof(int), cudaMemcpyDeviceToHost);

    // Print result
    printf("Result: ");
    for(int i = 0; i < N; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    // Free device memory
    cudaFree(d_input);
    cudaFree(d_mask);
    cudaFree(d_output);

    return 0;
}
