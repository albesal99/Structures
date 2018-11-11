#include <iostream>
#include "binary_search_tree.h"

int main() {
    struct TreeNode *root = nullptr;
    root = insert(root, 12);
    insert(root, 7);
    insert(root, 18);
    insert(root, 2);
    insert(root, 10);
    insert(root, 14);
    insert(root, 23);
    insert(root, 8);
    insert(root, 9);
    printf("Preorder traversal of the binary tree:\n");
    print_preorder(root);
    printf("\nInorder traversal of the binary tree:\n");
    print_inorder(root);
    printf("\nLevel Order traversal of the binary tree:\n");
    level_order(root);
    return 0;
}