#include <stdio.h>
#define MAX_FRAMES 10
int main() {
    int n, frames, page_faults = 0, hit = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int reference_string[n];
    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &reference_string[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    int page_frames[frames];
    for (int i = 0; i < frames; i++) {
        page_frames[i] = -1;  
    }
    int front = 0;  
    printf("\nPage Faults Sequence: ");
    for (int i = 0; i < n; i++) {
        int page_found = 0;
        for (int j = 0; j < frames; j++) {
            if (page_frames[j] == reference_string[i]) {
                page_found = 1;
                hit++;
                break;
            }
        }
        if (!page_found) {
            page_faults++;
            page_frames[front] = reference_string[i];
            front = (front + 1) % frames;  
        }
        for (int j = 0; j < frames; j++) {
            if (page_frames[j] != -1)
                printf("%d ", page_frames[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    printf("Total Hits: %d\n", hit);
    printf("Page Fault Rate: %.2f\n", (float)page_faults / n);
    printf("Hit Rate: %.2f\n", (float)hit / n);

    return 0;
}

