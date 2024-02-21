__kernel void repeat_string(__global char *input_string, __global char *output_string, const int N, const int str_length)
{
    int idx = get_global_id(0);

    if (idx < str_length * N) {
        int string_idx = idx % str_length;
        output_string[idx] = input_string[string_idx];
    }
}
