#include <stdio.h>
#include <string.h>
#include "mpi.h"
#include<stdlib.h>

#define MAX_BUFFER_SIZE 1000

void countWords(char* text, int* wordCount) {
    int count = 0;
    char* token = strtok(text, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    *wordCount = count;
}

int main(int argc, char* argv[]) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        FILE* file = fopen("input.txt", "r");
        if (file == NULL) {
            printf("Error opening file.\n");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        char buffer[MAX_BUFFER_SIZE];
        char* text;
        int processCount = 0;

        while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
            char* start = strstr(buffer, "<TEXT>");
            char* end = strstr(buffer, "</TEXT>");

            if (start != NULL && end != NULL && start < end) {
                int length = end - start - 6;
                text = malloc((length + 1) * sizeof(char));
                strncpy(text, start + 6, length);
                text[length] = '\0';

                if (processCount < size - 1) {
                    MPI_Send(text, strlen(text) + 1, MPI_CHAR, processCount + 1, 0, MPI_COMM_WORLD);
                    processCount++;
                } else {
                    countWords(text, &processCount);
                    printf("Process %d word count: %d\n", rank, processCount);
                    free(text);
                    processCount = 0;
                }
            }
        }

        fclose(file);
    } else {
        char text[MAX_BUFFER_SIZE];
        MPI_Recv(text, MAX_BUFFER_SIZE, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        int wordCount = 0;
        countWords(text, &wordCount);
        printf("Process %d word count: %d\n", rank, wordCount);
        MPI_Send(&wordCount, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    if (rank == 0) {
        int totalWordCount = 0;
        int processWordCount;
        for (int i = 1; i < size; i++) {
            MPI_Recv(&processWordCount, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            totalWordCount += processWordCount;
        }
        printf("Total word count: %d\n", totalWordCount);
    }

    MPI_Finalize();

    return 0;
}