#include <stdio.h>

// Define the maximum segment size
#define MAX_SEGMENT_SIZE 1024

// Define the number of segments
#define NUM_SEGMENTS 5

// Structure to represent a segment entry in the segment table
typedef struct {
    int base;  // Base address of the segment in physical memory
    int limit; // Size of the segment
} SegmentEntry;

// Function to create a segment table with random base addresses and limits
void createSegmentTable(SegmentEntry segmentTable[], int numSegments) {
    // Randomly assign base addresses and limits
    for (int i = 0; i < numSegments; i++) {
        segmentTable[i].base = i * MAX_SEGMENT_SIZE;
        segmentTable[i].limit = MAX_SEGMENT_SIZE;
    }
}

// Function to convert logical address to physical address
int convertToPhysicalAddress(SegmentEntry segmentTable[], int segment, int offset) {
    if (segment < 0 || segment >= NUM_SEGMENTS) {
        printf("Segment number out of range\n");
        return -1;
    }

    if (offset < 0 || offset >= segmentTable[segment].limit) {
        printf("Offset is out of the segment's range\n");
        return -1;
    }

    int physicalAddress = segmentTable[segment].base + offset;
    return physicalAddress;
}

int main() {
    // Create a segment table
    SegmentEntry segmentTable[NUM_SEGMENTS];
    createSegmentTable(segmentTable, NUM_SEGMENTS);

    // Compute physical addresses for the given scenarios
    int segment, offset, physicalAddress;

    // Scenario (i): 53 bytes of segment 2
    segment = 2;
    offset = 53;
    physicalAddress = convertToPhysicalAddress(segmentTable, segment, offset);
    if (physicalAddress != -1) {
        printf("(i) Physical Address: %d\n", physicalAddress);
    }

    // Scenario (ii): 852 bytes of segment 3
    segment = 3;
    offset = 852;
    physicalAddress = convertToPhysicalAddress(segmentTable, segment, offset);
    if (physicalAddress != -1) {
        printf("(ii) Physical Address: %d\n", physicalAddress);
    }

    // Scenario (iii): 1222 bytes of segment 0
    segment = 0;
    offset = 1222;
    if (offset >= 0 && offset < segmentTable[segment].limit) {
        physicalAddress = convertToPhysicalAddress(segmentTable, segment, offset);
        printf("(iii) Physical Address: %d\n", physicalAddress);
    }

    return 0;
}