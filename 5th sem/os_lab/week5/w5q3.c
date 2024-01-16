#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void* thread_code(void* args){
int *arr = (int*)args;
int lower_limit = arr[0];
int upper_limit = arr[1];
int *arr1 = (int*)calloc(upper_limit+1, sizeof(int));
for(int i=0;i<=upper_limit;i++){
arr1[i] = 1;
}
arr1[0] = 0;
arr1[1] = 0;
for(int i=2;i*i<=upper_limit;i++){
if(arr1[i] == 1){
for(int j = i*i; j<=upper_limit; j+=i){
arr1[j] = 0;
}
}
}
return (void*)arr1;
}
int main(int argc, char* argv[]){
if(argc<3){
printf("Enter a number!!\n");
exit(EXIT_FAILURE);
}
int lower_limit = atoi(argv[1]);
int upper_limit = atoi(argv[2]);
int packet[] = {lower_limit, upper_limit}, *result;
pthread_t thread;
pthread_create(&thread, 0, &thread_code, (void*)packet);
pthread_join(thread, (void**)&result);
printf("The Prime Numbers are: ");
for(int i=lower_limit;i<upper_limit;i++){
if((result)[i])
printf("%d ", i);
}
printf("\n");
return 0;
}