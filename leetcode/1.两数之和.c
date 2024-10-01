/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i=0;
    int j=0;
    int y=0;
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(target-nums[i]==nums[j])
            {
                y=1;
                break;
            }
        }
        if(y==1)
        {
            break;
        }
    }
    if(y==1)
    {
        int *ret=malloc(sizeof(int)*2);
        ret[0]=i;
        ret[1]=j;
        *returnSize =2;
        return ret;
    }
    else
    {
        *returnSize=0;
        return NULL;
    }
}
//break只能跳出一层循环；；
// @lc code=end

