#include "TreeNode.h"
#include <stdio.h>

int main()
{
    TreeNode* root = NULL;
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    printf("Preorder: ");
    preorderTraversal(root);
    printf("\n");
    printf("Inorder: ");
    inorderTraversal(root);
    printf("\n");
    printf("Postorder: ");
    postorderTraversal(root);
    printf("\n");
    printf("Level order: ");
    SequentialTraversal(root);
    printf("\n");
    freeTree(root);
    return 0;
}