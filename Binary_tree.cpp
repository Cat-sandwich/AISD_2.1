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
bin_tree* tree::find(int data)
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
bin_tree* tree::find_parent(int data)
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

bin_tree* tree::find_max(bin_tree* root)
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

void tree::print(bin_tree* root, int indent ) const
{
	if (root != NULL) {
		if (root->left) print(root->left, indent + 4);
		if (root->right) print(root->right, indent + 4);
		cout << root->data << "\n ";
	}
}



