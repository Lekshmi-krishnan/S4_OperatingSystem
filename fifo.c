#include <stdio.h>
#define MAX 50

// Function to check if a page is already present in the frame
int isPresent(int frame[], int f, int page) {
    for (int i = 0; i < f; i++) {
        if (frame[i] == page)
            return 1;
    }
    return 0;
}

// FIFO Page Replacement Algorithm
void fifo(int page[], int n, int f) {
    int frame[MAX], index = 0, fault = 0, hit = 0;

    // Initialize all frames to -1 (empty)
    for (int i = 0; i < f; i++)
        frame[i] = -1;

    printf("\n--- FIFO Page Replacement ---\n");

    for (int i = 0; i < n; i++) {
        if (!isPresent(frame, f, page[i])) {
            // Page fault: replace using FIFO
            frame[index] = page[i];
            index = (index + 1) % f;
            fault++;
            printf("%d F -> ", page[i]);
        } else {
            // Page hit
            hit++;
            printf("%d H -> ", page[i]);
        }

        // Print current frame status
        for (int j = 0; j < f; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Hits: %d\n", hit);
    printf("Total Faults: %d\n", fault);
    
}

int main() {
    int page[MAX], n, f;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter %d page reference numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &page[i]);
    }

    printf("\nReference string entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", page[i]);
    }
    printf("\n");

    fifo(page, n, f);

    return 0;
}
