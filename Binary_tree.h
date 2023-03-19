#pragma once
#include <stdio.h>

struct bin_tree
{
	float data;
	bin_tree* left;
	bin_tree* right;
	bin_tree(float data = 0, bin_tree* left = NULL, bin_tree* right = NULL)
	{
		this->data = data;
		this->left = left;
		this->right = right;

	}
};


class tree
{
private:
	bin_tree* root;
public:
	tree(float data = 0);
	tree(const tree& tree);
	void copy(bin_tree* tr, bin_tree* copy_tr);
	void delete_tree(bin_tree* root);
	~tree();

};
