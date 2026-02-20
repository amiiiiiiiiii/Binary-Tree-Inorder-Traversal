#include <stdlib.h>
int* inorderTraversal(struct TreeNode* root, int* returnSize) 
{
    int* result = (int*)malloc(100 * sizeof(int));
    struct TreeNode* stack[100];
    int top = -1;
    *returnSize = 0;
    struct TreeNode* current = root;
    while (current != NULL || top != -1) 
    {
        while (current != NULL) 
        {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        result[(*returnSize)++] = current->val;
        current = current->right;
    }
    return result;
}
