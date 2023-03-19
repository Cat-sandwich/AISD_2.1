#include "Binary_tree.h"
#include <stdio.h>

tree::tree(float data)
{
	root = new bin_tree(data, NULL, NULL);
}

tree::tree(const tree& tr)
{
	
	root = new bin_tree();
	copy(tr.root, root);
	
}
void tree::copy(bin_tree* tr, bin_tree* copy_tr)
{
	if (!tr)
	{
		copy_tr = NULL;
		return;
	}
	copy_tr->data = tr->data;
	copy(tr->right, copy_tr->right);
	copy(tr->left, copy_tr->left);
}

tree::~tree()
{
	delete_tree(root);
}

void tree::delete_tree(bin_tree* root)
{
	if (root)
	{
		delete_tree(root->left);
		delete_tree(root->right);
		delete root;
	}
}

