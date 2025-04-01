#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// FIFO Page Replacement Algorithm
void fifoPageReplacement(int pages[], int n, int capacity) {
    int frame[capacity], front = 0, faults = 0;
    for (int i = 0; i < capacity; i++) frame[i] = -1;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            frame[front] = pages[i];
            front = (front + 1) % capacity;
            faults++;
        }
    }
    printf("FIFO Page Faults: %d\n", faults);
}

// LRU Page Replacement Algorithm
void lruPageReplacement(int pages[], int n, int capacity) {
    int frame[capacity], count[capacity], faults = 0;
    for (int i = 0; i < capacity; i++) frame[i] = -1, count[i] = 0;
    for (int i = 0; i < n; i++) {
        int least = 0, found = false;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                count[j] = i;
                found = true;
                break;
            }
        }
        if (!found) {
            for (int j = 1; j < capacity; j++)
                if (count[j] < count[least])
                    least = j;
            frame[least] = pages[i];
            count[least] = i;
            faults++;
        }
    }
    printf("LRU Page Faults: %d\n", faults);
}

// Optimal Page Replacement Algorithm
void optimalPageReplacement(int pages[], int n, int capacity) {
    int frame[capacity], faults = 0;
    for (int i = 0; i < capacity; i++) frame[i] = -1;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            int farthest = -1, replaceIdx = -1;
            for (int j = 0; j < capacity; j++) {
                int nextUse = INT_MAX;
                for (int k = i + 1; k < n; k++) {
                    if (frame[j] == pages[k]) {
                        nextUse = k;
                        break;
                    }
                }
                if (nextUse > farthest) {
                    farthest = nextUse;
                    replaceIdx = j;
                }
            }
            frame[replaceIdx] = pages[i];
            faults++;
        }
    }
    printf("Optimal Page Faults: %d\n", faults);
}

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int capacity = 3;
    fifoPageReplacement(pages, 7, capacity);
    lruPageReplacement(pages, 7, capacity);
    optimalPageReplacement(pages, 7, capacity);
    return 0;
}
