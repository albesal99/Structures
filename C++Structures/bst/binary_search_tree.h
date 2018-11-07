//
// Created by Alberto Salmeron on 11/6/18.
//
#include <tuple>

#ifndef BST_BINARY_SEARCH_TREE_H
#define BST_BINARY_SEARCH_TREE_H


class binary_search_tree {
};

struct TreeNode;
struct TreeNode* new_node(int key, int data);
struct TreeNode* search_helper(struct TreeNode* node, int key);
bool search(struct TreeNode* root, int key);
struct TreeNode* insert_helper(TreeNode* node, int key, int data);
struct TreeNode* insert(struct TreeNode* node, int key, int data=0);
std::tuple<int, int> find_min(struct TreeNode* node);
std::tuple<int, int> find_max(struct TreeNode* node);
int tree_height_helper(TreeNode* node);
int tree_height(TreeNode* node);
void print_inorder(TreeNode* root);
void print_preorder(TreeNode* root);
void level_order(TreeNode* root);


#endif //BST_BINARY_SEARCH_TREE_H
