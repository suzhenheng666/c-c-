#include "TreeNode.h"

//创建新节点
TreeNode* createNode(int value)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//插入节点
void insert(TreeNode** root, int value)
{
    if (*root == NULL) {
        *root = createNode(value);
        return;
    }
    if (value < (*root)->val) {
        insert(&((*root)->left), value);
    } else {
        insert(&((*root)->right), value);
    }
}

//先序遍历
void preorderTraversal(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ", root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//中序遍历
void inorderTraversal(TreeNode* root)
{
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->val);
    inorderTraversal(root->right);
}

//后序遍历
void postorderTraversal(TreeNode* root)
{
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->val);
}

//查找节点
void localNode(TreeNode *root,int value)
{
    if(root==NULL)
    {
        return;
    }
    if(root->val==value)
    {
        printf("找到节点，地址为：%p，数据为：%d\n",root,root->val);
        return;
    }
    localNode(root->left,value);
    localNode(root->right,value);
}


//查找叶子节点
void leavesNode(TreeNode *root)
{
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("找到叶子节点,数据为：%d\n",root->val);
    }
    leavesNode(root->left);
    leavesNode(root->right);
}

//获取树的深度
int get_depth(TreeNode*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left_depth=get_depth(root->left);
    int right_depth=get_depth(root->right);
    return left_depth>right_depth?left_depth+1:right_depth+1;
}


//获取指定深度的节点
void get_depth_Node(TreeNode *root,int depth)
{
    if(root==NULL)
    {
        return;
    }
    if(depth==1)
    {
        printf("找到深度为%d的节点，数据为：%d\n",depth,root->val);
    }
    get_depth_Node(root->left,depth-1);
    get_depth_Node(root->right,depth-1);
}

//获取指定值的节点
TreeNode* get_Node(TreeNode *root,int value)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->val==value)
    {
        return root;
    }
    TreeNode *left=get_Node(root->left,value);
    if(left)
    {
        return left;
    }
    return get_Node(root->right,value);
}

//释放树的内存
void freeTree(TreeNode* root)
{
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

//层序遍历
void SequentialTraversal(TreeNode* root) {
    assert(root != NULL);
    Queue q;
    initQueue(&q);
    queuePush(&q, root->val);
    while(!queueIsEmpty(&q))
    {
        TreeNode* current = get_Node(root, queuePop(&q));
        printf("%d ", current->val);
        if (current->left) {
            queuePush(&q, current->left->val);
        }
        if (current->right) {
            queuePush(&q, current->right->val);
        }
    }
    freeQueue(&q);
}

//查找最大节点
int TreeMaxNode(TreeNode* root)
{
    assert(root != NULL);
    TreeNode* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->val;
}

//递归删除指定节点并保持二叉搜索树性质
void DeleteNode(TreeNode** root,int value)
{
    if(*root==NULL)
    {
        return;
    }
    if((*root)->val>value)
    {
        DeleteNode(&((*root)->left),value);
    }
    if((*root)->val<value)
    {
        DeleteNode(&((*root)->right),value);
    }
    if((*root)->val==value)
    {
        if((*root)->left==NULL && (*root)->right==NULL)
        {
            free(*root);
            *root = NULL;
        }
        if((*root)->left==NULL)
        {
            TreeNode* cur=(*root)->left;
            while(cur->right!=NULL)
            {
                cur=cur->right;
            }
            (*root)->val=cur->val;
            free(cur);
        }
        else{
            TreeNode* cur=(*root)->right;
            while(cur->left!=NULL)
            {
                cur=cur->left;
            }
            (*root)->val=cur->val;
            free(cur);
        }
    }
}

//打印树结构
void printTree(TreeNode* root, int space) {
    if (root == NULL)
        return;

    space += 10;

    printTree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->val);

    printTree(root->left, space);
}

//非递归-----------------------------------------------------------------------------------------------------------------------------
//先序遍历
void PreorderTraversal(TreeNode* root) {
    assert(root != NULL);
    Stack* stack = create_stack(4);
    push(stack, root->val);
    while (!is_empty(stack)) {
        TreeNode* cur=get_Node(root,pop(stack));
        printf("%d ", cur->val);
        if (cur->right) {
            push(stack, cur->right->val);
        }
        if (cur->left) {
            push(stack, cur->left->val);
        }
    }
    free_stack(stack);
}

//中序遍历
void InorderTraversal(TreeNode* root) {
    assert(root != NULL);
    Stack* stack = create_stack(4);
    TreeNode* cur = root;
    while(cur !=NULL || !is_empty(stack))
    {
        while(cur !=NULL)
        {
            push(stack, cur->val);
            cur=cur->left;
        }
        cur=get_Node(root,pop(stack));
        printf("%d ", cur->val);
        cur=cur->right;
    }
    free_stack(stack);
}

//后序遍历
void PostorderTraversal(TreeNode* root) {
    assert(root!=NULL);
    Stack* stack = create_stack(4);
    TreeNode* cur = root;
    TreeNode* pre=NULL;
    while(cur !=NULL || !is_empty(stack))
    {
        while(cur !=NULL)
        {
            push(stack, cur->val);
            cur=cur->left;
        }
        cur=get_Node(root,peek(stack));
        if(cur->right==NULL || cur->right==pre)
        {
            printf("%d ", cur->val);
            pop(stack);
            pre=cur;
            cur=NULL;
        }
        else
        {
            cur=cur->right;
        }
    }
    free_stack(stack);
}