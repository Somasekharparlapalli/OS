#include <stdio.h>
int main() {
    int blocks[10], processes[10], bSize, pSize, allocation[10], i, j;
    printf("Enter number of blocks: ");
    scanf("%d", &bSize);
    printf("Enter block sizes: ");
    for (i = 0; i < bSize; i++) scanf("%d", &blocks[i]);
    printf("Enter number of processes: ");
    scanf("%d", &pSize);
    printf("Enter process sizes: ");
    for (i = 0; i < pSize; i++) scanf("%d", &processes[i]);
    for (i = 0; i < pSize; i++) allocation[i] = -1;
    for (i = 0; i < pSize; i++) {
        int bestIndex = -1;
        for (j = 0; j < bSize; j++) {
            if (blocks[j] >= processes[i]) {
                if (bestIndex == -1 || blocks[j] < blocks[bestIndex]) {
                    bestIndex = j;
                }
            }
        }
        if (bestIndex != -1) {
            allocation[i] = bestIndex;
            blocks[bestIndex] -= processes[i];
        }
    }
    printf("\nProcess\tSize\tBlock\n");
    for (i = 0; i < pSize; i++) {
        if (allocation[i] != -1)
            printf("%d\t%d\t%d\n", i + 1, processes[i], allocation[i] + 1);
        else
            printf("%d\t%d\tNot Allocated\n", i + 1, processes[i]);
    }
    return 0;
}

