#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* stableMountains(int* height, int heightSize, int threshold, int* returnSize) {
    int *answer = (int *)malloc(sizeof(int) * (heightSize - 1));
    int i = 0, j = 0;
    for(i = 1; i <= heightSize - 1; i++){
        if(height[i-1] > threshold){
            answer[j++] = i;
        }
    }
    *returnSize = j;
    return answer;
}