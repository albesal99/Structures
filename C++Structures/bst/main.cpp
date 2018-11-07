#include <iostream>
#include "binary_search_tree.h"

int main() {
    struct TreeNode *root = nullptr;
    root = insert(root, 12);
    root = insert(root, 7);
    root = insert(root, 18);
    root = insert(root, 2);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 23);
    root = insert(root, 8);
    root = insert(root, 9);
    printf("Preorder traversal of the binary tree:\n");
    print_preorder(root);
    return 0;
}