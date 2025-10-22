#ifndef TREENODE_H
#define TREENODE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "queue.h"
#include "stack.h"

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

//递归------------------------------------------------------------------------------------------
TreeNode* createNode(int value);  // 创建新节点
void insert(TreeNode** root, int value); // 插入节点
void inorderTraversal(TreeNode* root); // 中序遍历
void preorderTraversal(TreeNode* root); // 先序遍历
void postorderTraversal(TreeNode* root);// 后序遍历
void localNode(TreeNode *root,int value); // 查找节点
void leavesNode(TreeNode *root); // 查找叶子节点
int get_depth(TreeNode* root); // 获取树的深度
void get_depth_Node(TreeNode *root,int depth); // 获取指定深度的节点
TreeNode* get_Node(TreeNode *root,int value); // 获取指定值的节点
void freeTree(TreeNode* root); // 释放树的内存
void SequentialTraversal(TreeNode* root); // 层序遍历
void DeleteNode(TreeNode** root, int value); // 删除节点,并且保持二叉搜索树结构
void printTree(TreeNode* root, int space); // 打印树结构
//非递归----------------------------------------------------------------------------------------
void PreorderTraversal(TreeNode* root); // 先序遍历非递归
void InorderTraversal(TreeNode* root);  // 中序遍历非递归
void PostorderTraversal(TreeNode* root); // 后序遍历非递归

#endif // TREENODE_H