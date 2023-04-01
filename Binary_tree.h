#pragma once
#include <stdio.h>

struct bin_tree
{
	int data;
	bin_tree* left;
	bin_tree* right;
	bin_tree(int data = 0, bin_tree* left = NULL, bin_tree* right = NULL)
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
	tree(int data = 0);
	tree(const tree& tree);
	void copy(bin_tree* tr, bin_tree* copy_tr);
	void delete_tree(bin_tree* root);
	~tree();
	bin_tree* find(int data);
	bool insert(int data);
	void print(bin_tree* p, int indent = 0) const;
	bin_tree* find_max(bin_tree* root);
	bin_tree* find_parent(int data);
	bool erase(int data);
};
