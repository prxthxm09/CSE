#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 4
#define MAX_PAGES 12

// Structure to represent a page frame
typedef struct {
    int page_number;
    int second_chance_bit;
} PageFrame;

// Function to initialize the page frames
void initializeFrames(PageFrame frames[], int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        frames[i].page_number = -1;
        frames[i].second_chance_bit = 0;
    }
}

// Function to check if a page is present in the frames
int isPageInFrames(PageFrame frames[], int num_frames, int page_number) {
    for (int i = 0; i < num_frames; i++) {
        if (frames[i].page_number == page_number) {
            return 1;
        }
    }
    return 0;
}

// Function to find the index of the page to be replaced (using the second chance algorithm)
int findReplacementIndex(PageFrame frames[], int num_frames, int current_index) {
    int index = current_index;
    while (1) {
        if (frames[index].second_chance_bit == 0) {
            return index;
        } else {
            frames[index].second_chance_bit = 0; // Give it a second chance
            index = (index + 1) % num_frames;
        }
    }
}

int main() {
    int page_references[MAX_PAGES] = {1, 2, 3, 2, 4, 3, 5, 6, 7, 6, 8, 1};

    PageFrame frames[MAX_FRAMES];
    int num_page_faults = 0;
    int current_frame_index = 0;

    initializeFrames(frames, MAX_FRAMES);

    printf("Page References: ");
    for (int i = 0; i < MAX_PAGES; i++) {
        int page_number = page_references[i];
        printf("%d ", page_number);

        if (!isPageInFrames(frames, MAX_FRAMES, page_number)) {
            num_page_faults++;
            int replacement_index = findReplacementIndex(frames, MAX_FRAMES, current_frame_index);
            frames[replacement_index].page_number = page_number;
            frames[replacement_index].second_chance_bit = 0;
            current_frame_index = (replacement_index + 1) % MAX_FRAMES;
        } else {
            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j].page_number == page_number) {
                    frames[j].second_chance_bit = 1;
                    break;
                }
            }
        }
    }

    float hit_ratio = 1.0 - (float)num_page_faults / MAX_PAGES;

    printf("\nTotal Page Faults: %d\n", num_page_faults);
    printf("Hit Ratio: %.2f\n", hit_ratio);

    return 0;
}