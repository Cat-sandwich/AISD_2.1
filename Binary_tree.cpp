#include "Binary_tree.h"
#include <stdio.h>
#include <iostream>
using namespace std;

tree::tree(int data)
{
	root = new bin_tree(data, NULL, NULL);
}

tree::tree(const tree& tr)
{

	root = new bin_tree();
	root = copy(tr.root, root);

}
bin_tree* tree::copy(bin_tree* old_tree, bin_tree* new_tree)
{
	if (!old_tree)
	{
		return NULL ;
	}
	new_tree = new bin_tree(old_tree->data, NULL, NULL);
	if (old_tree->left != NULL)
		new_tree->left = copy(old_tree->left, new_tree->left);
	else
		new_tree->left = NULL;

	if (old_tree->right != NULL)
		new_tree->right = copy(old_tree->right, new_tree->right);
	else
		new_tree->right = NULL;


	return new_tree;
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
bin_tree* tree::find(int data) const
{
    bin_tree* tmp_root = root;

    while (tmp_root)
    {
        if (tmp_root->data == data) return tmp_root;
        if (tmp_root->data > data) return tmp_root->left;
        if (tmp_root->data < data) return tmp_root->right;
    }
    return NULL;
}
bin_tree* tree::find_parent(int data) const
{
	bin_tree* tmp_root = root;

	while (tmp_root)
	{
		if (tmp_root->left && (tmp_root->left)->data == data) return tmp_root;
		if (tmp_root->right && (tmp_root->right)->data == data) return tmp_root;
		if (tmp_root->data > data) return tmp_root->left;
		if (tmp_root->data < data) return tmp_root->right;
	}
	return NULL;
}
bool tree::insert(int data)
{
	if (!root)
	{
		root = new bin_tree(data);
		return true;
	}
	bin_tree* tmp_root = root;
	while (tmp_root && tmp_root->data != data)
	{
		if (tmp_root->data > data && tmp_root->left == NULL)
		{
			tmp_root->left = new bin_tree(data);

			return true;
		}
		if (tmp_root->data < data && tmp_root->right == NULL)
		{
			tmp_root->right = new bin_tree(data);
			return true;
		}
		if (data == tmp_root->data)
			return false;

		if (tmp_root->data > data)
			tmp_root = tmp_root->left;
		else
			tmp_root = tmp_root->right;
	}
}

bin_tree* tree::find_max(bin_tree* root) const
{
	if (!root)
		return NULL;
	bin_tree* tmp_root = root;
	while (tmp_root->right)
		tmp_root = tmp_root->right;
	if (tmp_root->left)
		return tmp_root->left;
	return tmp_root;
}
tree tree::operator=(const tree& t)
{
	root = new bin_tree(0, NULL, NULL);
	root = copy(t.root, root);
	return *this;
}

bin_tree* tree::get_root()
{
	return root;
}
bool tree::erase(int data)
{
	if (!root)
		return false;
	bin_tree* erase_root = find(data);
	if (!erase_root)
		return NULL;

	if (erase_root->left == NULL && erase_root->right == NULL)
	{
		delete erase_root;
		erase_root = NULL;
	}
	bin_tree* parent_root = find_parent(data);
	if (erase_root->left && !(erase_root->right))
	{
		if ((parent_root->left)->data == data)
		{
			parent_root->left = erase_root->left;
			delete erase_root;
			erase_root = NULL;
			return true;
		}
		if ((parent_root->right)->data == data)
		{
			parent_root->right = erase_root->left;
			delete erase_root;
			erase_root = NULL;
			return true;
		}
	}

	if (erase_root->right && !(erase_root->left))
	{
		if ((parent_root->left)->data == data)
		{
			parent_root->left = erase_root->right;
			delete erase_root;
			erase_root = NULL;
			return true;
		}
		if ((parent_root->right)->data == data)
		{
			parent_root->right = erase_root->right;
			delete erase_root;
			erase_root = NULL;
			return true;
		}
	}
	if (erase_root->left && erase_root->right)
	{
		bin_tree* max_root = find_max(erase_root->left);
		bin_tree* parent_max_root = find_parent(max_root->data);
		if (!(max_root->left))
		{			
			if(erase_root->left == max_root)
				max_root->left = NULL;
			else max_root->left = erase_root->left;
			max_root->right = erase_root->right;
			if(parent_root->left == erase_root)
				parent_root->left = max_root;
			else parent_root->right = max_root;
			delete erase_root;
			erase_root = NULL;
			if (parent_max_root != erase_root)
				parent_max_root->right = NULL;
			return true;
		}
		if (max_root->left)
		{
			
			if (erase_root->left == max_root)
				parent_max_root->left = max_root->left;
			else parent_max_root->right = max_root->left;
			max_root->right = erase_root->right;
			max_root->left = erase_root->left;
			if (parent_root->left == erase_root)
				parent_root->left = max_root;
			else parent_root->right = max_root;
			delete erase_root;
			erase_root = NULL;
			if (parent_max_root != erase_root)
				parent_max_root->right = NULL;
			return true;
		}
	}
	return false;
}

int tree::height(bin_tree* root) const 
{
	if (!root)
		return 0;
	int r = height(root->right);
	int l = height(root->left);
	if (r > l)
		return r + 1;
	else
		return l + 1;

}
void tree::print_tree(bin_tree* root, int level) const
{
	if (!root)
		return;
	int h = height(root);
	cout << string(h, ' ')<< root->data << endl;
	for (int i=0; i<)


	
	if (root != NULL) {
		print_tree(root->left, indent + 3);
		for (int i = 0; i < indent; i++) cout << "   ";
		cout << root->data << endl;
		print_tree(root->right, indent + 6);
	}
}



