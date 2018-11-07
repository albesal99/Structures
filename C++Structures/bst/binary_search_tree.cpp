//
// Created by Alberto Salmeron on 11/6/18.
//

#include <iostream>
#include <bootstrap.h>
#include "binary_search_tree.h"
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int key = key;
    int data = data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* new_node(int key, int data=0) {
    struct TreeNode* new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    new_node->key = key;
    new_node->data = data;
    new_node->left = nullptr;
    new_node->right = nullptr;

    return new_node;
}

struct TreeNode* search_helper(struct TreeNode* node, int key) {
    if (node == nullptr || node->key == key)
        return node;
    if (node->key < key)
        return search_helper(node->right, key);
    return search_helper(node->left, key);
}

bool search(struct TreeNode* root, int key) {
    return search_helper(root, key);
}

struct TreeNode* insert_helper(TreeNode* node, int key, int data) {
    if (search(node, key))
        node->data = data;
    else if (key > node->key)
        if (node->right == nullptr)
            node->right = new_node(key, data);
        else
            return insert_helper(node->right, key, data);
    else
        if (node->left == nullptr)
            node->left = new_node(key, data);
        else
            return insert_helper(node->left, key, data);
}

struct TreeNode* insert(struct TreeNode* node, int key, int data) {
    if (node == nullptr)
        return new_node(key, data);
    else
        return insert_helper(node, key, data);
}

std::tuple<int, int> find_min(struct TreeNode* node) {
    struct TreeNode* current = node;

    while (current->left != nullptr)
        current = current->left;
    return std::make_tuple(current->key, current->data);
}


std::tuple<int, int> find_max(struct TreeNode* node) {
    struct TreeNode* current = node;

    while (current->right != nullptr)
        current = current->right;
    return std::make_tuple(current->key, current->data);
}

int tree_height_helper(TreeNode* node) {
    if (node == nullptr)
        return -1;
    return 1 + std::max(tree_height_helper(node->left), tree_height_helper(node->right));
}

int tree_height(TreeNode* node) {
    return tree_height_helper(node);
}

void print_inorder(TreeNode* root) {
    if (root == nullptr)
        return;
    print_inorder(root->left);
    cout << root->key << " ";
    print_inorder(root->right);
}

void print_preorder(TreeNode* root) {
    if (root == nullptr)
        return;
    cout << root->key << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}

void level_order(TreeNode* root) {
    TreeNode* node = root;
    if (root == nullptr)
        return;
    queue <struct TreeNode*> q;
    q.push(node);
    while (!q.empty())
        node = q.front();
        q.pop();
        cout << node->key << " ";
        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);
}
