/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if(returnSize == NULL)
        returnSize = (int*)malloc(sizeof(int));
    returnSize = (int*)realloc(returnSize, sizeof(int));
    while(root){
        *(returnSize ++ ) = root -> val;
        inorderTraversal(root ->left, returnSize);
        inorderTraversal(root ->right, returnSize);
    }
        return returnSize;

}
// @lc code=end

