// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

#include<iostream>
#include"../inc/solution.hpp"


void PrintLinkedListTree(TreeNode* root)
{
	while(root->right != nullptr)
	{
		std::cout << root->val << ' ';
		root = root->right;
	}
}

int main()
{
	TreeNode n6(6);
	TreeNode n5(4);
	TreeNode n4(3);
	TreeNode n3(5,nullptr,&n6);
	TreeNode n2(2,&n4,&n5);
	TreeNode root(1,&n2,&n3);

	Solution sol;
	sol.flatten(&root);
	PrintLinkedListTree(&root);
	return 0;
}

