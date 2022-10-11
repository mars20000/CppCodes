// Recursive optimized C program to find the diameter of a
// Binary Tree
#include <bits/stdc++.h>
using namespace std;

// A binary tree TreeNode has data, pointer to left child
// and a pointer to right child
struct TreeNode {
	int data;
	struct TreeNode *left, *right;
};

// function to create a new TreeNode of tree and returns pointer
struct TreeNode* newTreeNode(int data);

// returns max of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// function to Compute height of a tree.
int height(struct TreeNode* TreeNode);

// Function to get diameter of a binary tree
int diameter(struct TreeNode* tree)
{
	// base case where tree is empty
	if (tree == NULL)
		return 0;

	// get the height of left and right sub-trees
	int lheight = height(tree->left);
	int rheight = height(tree->right);

	// get the diameter of left and right sub-trees
	int ldiameter = diameter(tree->left);
	int rdiameter = diameter(tree->right);

	// Return max of following three
	// 1) Diameter of left subtree
	// 2) Diameter of right subtree
	// 3) Height of left subtree + height of right subtree +
	// 1
	return max(lheight + rheight + 1,
			max(ldiameter, rdiameter));
}



// The function Compute the "height" of a tree. Height is
// the number f TreeNodes along the longest path from the root
// TreeNode down to the farthest leaf TreeNode.
int height(struct TreeNode* TreeNode)
{
	
	if (TreeNode == NULL)
		return 0;
	return 1 + max(height(TreeNode->left), height(TreeNode->right));
}


struct TreeNode* newTreeNode(int data)
{
	struct TreeNode* TreeNode
		= (struct TreeNode*)malloc(sizeof(struct TreeNode));
	TreeNode->data = data;
	TreeNode->left = NULL;
	TreeNode->right = NULL;

	return (TreeNode);
}

// Main Method
int main()
{

	/* Constructed binary tree is
			1
			/ \
		2	 3
		/ \
	4	 5
	*/
	struct TreeNode* root = newTreeNode(1);
	root->left = newTreeNode(2);
	root->right = newTreeNode(3);
	root->left->left = newTreeNode(4);
	root->left->right = newTreeNode(5);

	// Function Call
	cout << "Diameter of the given binary tree is "
		<< diameter(root);

	return 0;
}


