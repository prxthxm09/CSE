__kernel void vector_add(__global int *A, __global int *C)
{
    int tid = get_global_id(0); // OpenCL intrinsic function
    int quotient = A[tid];
    int octalNumber[100];
    int i = 0;

    // Storing remainders until quotient is equal to zero
    while (quotient != 0)
    {
        octalNumber[i++] = quotient % 8;
        quotient = quotient / 8;
    }

    int octalnum = 0;
    for (int j = i - 1; j >= 0; j--)
        octalnum = octalnum * 10 + octalNumber[j];

    C[tid] = octalnum;
}
