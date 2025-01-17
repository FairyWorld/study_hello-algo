/**
 * File: preorder_traversal_ii_compact.c
 * Created Time: 2023-05-28
 * Author: Gonglja (glj0@outlook.com)
 */

#include "../utils/common.h"

// 假设路径和结果长度不超过 100
#define MAX_SIZE 100
#define MAX_RES_SIZE 100

TreeNode *path[MAX_SIZE];
TreeNode *res[MAX_RES_SIZE][MAX_SIZE];
int pathSize = 0, resSize = 0;

/* 前序遍历：例题二 */
static void preOrder(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    // 尝试
    path[pathSize++] = root;
    if (root->val == 7) {
        // 记录解
        for (int i = 0; i < pathSize; ++i) {
            res[resSize][i] = path[i];
        }
        resSize++;
    }
    preOrder(root->left);
    preOrder(root->right);
    // 回退
    pathSize--;
}

/* Driver Code */
int main() {
    int arr[] = {1, 7, 3, 4, 5, 6, 7};
    TreeNode *root = arrayToTree(arr, sizeof(arr) / sizeof(arr[0]));
    printf("\n初始化二叉树\n");
    printTree(root);

    // 前序遍历
    preOrder(root);

    printf("\n输出所有根节点到节点 7 的路径\n");
    for (int i = 0; i < resSize; ++i) {
        int vals[MAX_SIZE];
        int size = 0;
        for (int j = 0; res[i][j] != NULL; ++j) {
            vals[size++] = res[i][j]->val;
        }
        printArray(vals, size);
    }

    // 释放内存
    freeMemoryTree(root);
    return 0;
}
