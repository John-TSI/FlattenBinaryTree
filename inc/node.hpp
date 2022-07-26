#ifndef NODE_HPP
#define NODE_HPP


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode();
    explicit TreeNode(int);
    TreeNode(int, TreeNode*, TreeNode*);
};
 

#endif // NODE_HPP