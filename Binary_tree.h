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
	bin_tree* copy(bin_tree* tr, bin_tree* copy_tr);
	void delete_tree(bin_tree* root);
	~tree();
	bin_tree* find(int data) const;
	bool insert(int data);
	void print_tree(bin_tree* p, int ident = 0, int level = 3) const;
	bin_tree* find_min( bin_tree* root) const;
	bin_tree* find_parent(int data) const;
	bool erase(int data);
	tree operator=(const tree& t);
	bool contains(int data) const;
	bin_tree* get_root();
	int height(bin_tree* root) const;
	int count_node(bin_tree* root) const;
};
