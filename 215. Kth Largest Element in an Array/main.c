//
//  main.c
//  215. Kth Largest Element in an Array
//
//  Created by 장재연 on 2021/03/08.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findKthLargest(int* nums, int numsSize, int k){
    int max, i, j, index;
    for(i=0;i<k;i++){
        max = -2147483648;
        for(j=0;j<numsSize;j++){
            if(nums[j]>max){
                index = j;
                max = nums[j];
            }
        }
        nums[index] = -2147483648;
    }
    return max;
}
