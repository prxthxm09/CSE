#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SOURCE_SIZE (0x100000)

int main(void)
{
    char input_string[100];
    int N;
    
    // Input string
    printf("Enter string: ");
    scanf("%s", input_string);
    
    // Number of repetitions
    printf("Enter times to repeat: ");
    scanf("%d", &N);

    // Get the length of the input string
    int str_length = strlen(input_string);

    // Load the kernel source code into the array source_str
    FILE *fp;
    char *source_str;
    size_t source_size;
    fp = fopen("1k.cl", "r");

    if (!fp) 
    {
        fprintf(stderr, "Failed to load kernel.\n");
        getchar();
        exit(1);
    }

    source_str = (char*)malloc(MAX_SOURCE_SIZE);
    source_size = fread( source_str, 1, MAX_SOURCE_SIZE, fp);
    fclose( fp );

    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_uint ret_num_devices;
    cl_uint ret_num_platforms;
    cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
    ret = clGetDeviceIDs( platform_id, CL_DEVICE_TYPE_GPU, 1,&device_id, &ret_num_devices);

    // Create an OpenCL context
    cl_context context = clCreateContext( NULL, 1, &device_id, NULL, NULL, &ret);

    // Create a command queue
    cl_command_queue command_queue = clCreateCommandQueue(context, device_id, 0, &ret);

    // Create memory buffers on the device for input and output string
    cl_mem input_string_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, str_length * sizeof(char), NULL, &ret);
    cl_mem output_string_mem_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, str_length * N * sizeof(char), NULL, &ret);

    // Copy the input string into respective memory buffer
    ret = clEnqueueWriteBuffer(command_queue, input_string_mem_obj, CL_TRUE, 0, str_length * sizeof(char), input_string, 0, NULL, NULL);

    // Create a program from the kernel source
    cl_program program = clCreateProgramWithSource(context, 1,(const char**)&source_str, (const size_t *)&source_size, &ret);

    // Build the program
    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

    // Create the OpenCL kernel
    cl_kernel kernel = clCreateKernel(program, "repeat_string", &ret);

    // Set the arguments of the kernel
    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&input_string_mem_obj);
    ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&output_string_mem_obj);
    ret = clSetKernelArg(kernel, 2, sizeof(int), (void *)&N);
    ret = clSetKernelArg(kernel, 3, sizeof(int), (void *)&str_length);

    // Execute the OpenCL kernel
    size_t global_item_size = str_length * N;
    size_t local_item_size = 1;
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL,
    &global_item_size, &local_item_size, 0, NULL, NULL);

    // Read the result in memory buffer on the device to the local variable result
    char *result = (char*)malloc(sizeof(char) * str_length * N);
    ret = clEnqueueReadBuffer(command_queue, output_string_mem_obj, CL_TRUE, 0,
    str_length * N * sizeof(char), result, 0, NULL, NULL);
    result[str_length * N] = '\0'; // Null terminate the string

    // Display the result
    printf("Output String: %s\n", result);

    // Clean up
    ret = clFlush(command_queue);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(program);
    ret = clReleaseMemObject(input_string_mem_obj);
    ret = clReleaseMemObject(output_string_mem_obj);
    ret = clReleaseCommandQueue(command_queue);
    ret = clReleaseContext(context);
    free(source_str);
    free(result);

    return 0;
}
