#include <stdio.h>
#include <limits.h>

// First Fit Memory Allocation
void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n]; // Array to store allocated block for each process
    for (int i = 0; i < n; i++) allocation[i] = -1; // Initialize allocation as -1 (not allocated)
    
    for (int i = 0; i < n; i++) { // Iterate through each process
        for (int j = 0; j < m; j++) { // Iterate through each memory block
            if (blockSize[j] >= processSize[i]) { // Check if block can accommodate process
                allocation[i] = j; // Allocate block j to process i
                blockSize[j] -= processSize[i]; // Reduce available block size
                break; // Move to the next process
            }
        }
    }
    printf("First Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d -> Block %d\n", i+1, allocation[i]+1);
    }
}

// Best Fit Memory Allocation
void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;
    
    for (int i = 0; i < n; i++) { // Iterate through each process
        int bestIdx = -1;
        for (int j = 0; j < m; j++) { // Find the smallest fitting block
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx; // Assign best fitting block
            blockSize[bestIdx] -= processSize[i];
        }
    }
    printf("Best Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d -> Block %d\n", i+1, allocation[i]+1);
    }
}

// Worst Fit Memory Allocation
void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;
    
    for (int i = 0; i < n; i++) { // Iterate through each process
        int worstIdx = -1;
        for (int j = 0; j < m; j++) { // Find the largest fitting block
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx; // Assign worst fitting block
            blockSize[worstIdx] -= processSize[i];
        }
    }
    printf("Worst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d -> Block %d\n", i+1, allocation[i]+1);
    }
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);
    
    firstFit(blockSize, m, processSize, n);
    bestFit(blockSize, m, processSize, n);
    worstFit(blockSize, m, processSize, n);
    
    return 0;
}