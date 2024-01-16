#include <stdio.h>
#include <stdlib.h>

// Define the memory allocation block structure
struct mab {
    int offset;
    int size;
    int allocated;
    struct mab* next;
    struct mab* prev;
};

typedef struct mab Mab;
typedef Mab* MabPtr;
MabPtr memSplit(MabPtr m, int size);
MabPtr memMerge(MabPtr m);

// Function to check if memory is available
MabPtr memChk(MabPtr m, int size) {
    MabPtr current = m;
    while (current != NULL) {
        if (!current->allocated && current->size >= size) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to allocate memory using First Fit
MabPtr memAllocFirstFit(MabPtr m, int size) {
    MabPtr block = memChk(m, size);
    if (block != NULL) {
        if (block->size == size) {
            block->allocated = 1;
        } else {
            MabPtr newBlock = memSplit(block, size);
            newBlock->allocated = 1;
        }
    }
    return m;
}

// Function to allocate memory using Best Fit
MabPtr memAllocBestFit(MabPtr m, int size) {
    MabPtr bestBlock = NULL;
    MabPtr current = m;
    while (current != NULL) {
        if (!current->allocated && current->size >= size) {
            if (bestBlock == NULL || current->size < bestBlock->size) {
                bestBlock = current;
            }
        }
        current = current->next;
    }
    if (bestBlock != NULL) {
        if (bestBlock->size == size) {
            bestBlock->allocated = 1;
        } else {
            MabPtr newBlock = memSplit(bestBlock, size);
            newBlock->allocated = 1;
        }
    }
    return m;
}

// Function to allocate memory using Worst Fit
MabPtr memAllocWorstFit(MabPtr m, int size) {
    MabPtr worstBlock = NULL;
    MabPtr current = m;
    while (current != NULL) {
        if (!current->allocated && current->size >= size) {
            if (worstBlock == NULL || current->size > worstBlock->size) {
                worstBlock = current;
            }
        }
        current = current->next;
    }
    if (worstBlock != NULL) {
        if (worstBlock->size == size) {
            worstBlock->allocated = 1;
        } else {
            MabPtr newBlock = memSplit(worstBlock, size);
            newBlock->allocated = 1;
        }
    }
    return m;
}

// Function to free memory block
MabPtr memFree(MabPtr m) {
    m->allocated = 0;
    return memMerge(m);
}

// Function to merge two memory blocks
MabPtr memMerge(MabPtr m) {
    if (m->next != NULL && !m->next->allocated) {
        m->size += m->next->size;
        m->next = m->next->next;
        if (m->next != NULL) {
            m->next->prev = m;
        }
    }
    if (m->prev != NULL && !m->prev->allocated) {
        m->prev->size += m->size;
        m->prev->next = m->next;
        if (m->next != NULL) {
            m->next->prev = m->prev;
        }
        return m->prev;
    }
    return m;
}

// Function to split a memory block
MabPtr memSplit(MabPtr m, int size) {
    MabPtr newBlock = (MabPtr)malloc(sizeof(Mab));
    newBlock->offset = m->offset + size;
    newBlock->size = m->size - size;
    newBlock->allocated = 0;
    newBlock->prev = m;
    newBlock->next = m->next;
    if (m->next != NULL) {
        m->next->prev = newBlock;
    }
    m->size = size;
    m->next = newBlock;
    return newBlock;
}

int main() {
    // Initialize memory blocks using your linked list structure
    MabPtr memory = (MabPtr)malloc(sizeof(Mab));
    memory->offset = 0;
    memory->size = 128;
    memory->allocated = 0;
    memory->next = NULL;
    memory->prev = NULL;

    // Example usage of memory allocation policies

    // First Fit
    printf("First Fit:\n");
    memory = memAllocFirstFit(memory, 64);
    memory = memAllocFirstFit(memory, 32);
    memory = memAllocFirstFit(memory, 16);

    MabPtr current = memory;
    while (current != NULL) {
        printf("Block: offset=%d, size=%d, allocated=%d\n", current->offset, current->size, current->allocated);
        current = current->next;
    }

    // Reset memory for the next policy
    free(memory);
    memory = (MabPtr)malloc(sizeof(Mab));
    memory->offset = 0;
    memory->size = 128;
    memory->allocated = 0;
    memory->next = NULL;
    memory->prev = NULL;

    // Best Fit
    printf("\nBest Fit:\n");
    memory = memAllocBestFit(memory, 16);
    memory = memAllocBestFit(memory, 32);
    memory = memAllocBestFit(memory, 64);

    current = memory;
    while (current != NULL) {
        printf("Block: offset=%d, size=%d, allocated=%d\n", current->offset, current->size, current->allocated);
        current = current->next;
    }

    // Reset memory for the next policy
    free(memory);
    memory = (MabPtr)malloc(sizeof(Mab));
    memory->offset = 0;
    memory->size = 128;
    memory->allocated = 0;
    memory->next = NULL;
    memory->prev = NULL;

    // Worst Fit
    printf("\nWorst Fit:\n");
    memory = memAllocWorstFit(memory, 64);
    memory = memAllocWorstFit(memory, 32);
    memory = memAllocWorstFit(memory, 16);

    current = memory;
    while (current != NULL) {
        printf("Block: offset=%d, size=%d, allocated=%d\n", current->offset, current->size, current->allocated);
        current = current->next;
    }

    // Clean up allocated memory
    while (memory != NULL) {
        MabPtr temp = memory;
        memory = memory->next;
        free(temp);
    }

    return 0;
}