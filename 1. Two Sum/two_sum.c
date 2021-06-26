// My solution 
//
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    printf("%d\n", *returnSize);
    * returnSize = 2;
    int* ans = malloc(*returnSize * (sizeof(int)));
    
    for(int i = 0; i < numsSize; i++){
        for(int j = i+1; j<numsSize; j++){
            if(nums[i] + nums[j] == target){
                ans[0] = i;
                ans[1] = j;
                goto LOOP_BREAK;
            }
        }
    }
LOOP_BREAK:
    
    return ans;
}
// Nico's solution is to sort the array
// Then to designate a pointer to the beginning and the end of the array
// Then to add the pointers together, if too low then increase the index of the lower pointer
// If too large then reduce the index of the end pointer
// Repeat until the target is met.
// Then find the true index of these pointers from the unsorted list and return those.
