#include "Binary_tree.h"
#include <stdio.h>
#include <iomanip>
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
bool tree::contains(int data) const
{
	bin_tree* tmp_root = root;
	while (tmp_root)
	{
		if (tmp_root->data == data) return true;
		if (tmp_root->data > data)  tmp_root = tmp_root->left;
		else if (tmp_root->data < data)  tmp_root = tmp_root->right;
	}
	return false;
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
        if (tmp_root->data > data)  tmp_root = tmp_root->left;
        if (tmp_root->data < data)  tmp_root = tmp_root->right;
    }
    return NULL;
}
bin_tree* tree::find_parent(int data, bin_tree* root) const
{
	bin_tree* tmp_root = root;

	while (tmp_root)
	{
		if (tmp_root->left && (tmp_root->left)->data == data)
			return tmp_root;
		if (tmp_root->right && (tmp_root->right)->data == data)
			return tmp_root;
		if (tmp_root->data > data)
			tmp_root = tmp_root->left;
		else if (tmp_root->data < data)
			tmp_root = tmp_root->right;
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

		if (tmp_root->data > data)
			tmp_root = tmp_root->left;
		else
			tmp_root = tmp_root->right;
	}
	return false;
}

bin_tree* tree::find_min(bin_tree* root) const
{
	if (!root)
		return NULL;
	bin_tree* tmp_root = root;
	while (tmp_root->left)
		tmp_root = tmp_root->left;
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
	if (erase_root == NULL)
		return false;
	if (erase_root == root)
	{
		if (root->left == NULL && root->right == NULL)
		{
			cout << "Вы не можете удалить корень!" << endl;
			system("pause");
			return false;
		}
		if (erase_root->left != NULL && erase_root->right == NULL) // если есть левое поддерево, но нет правого
		{
			root = root->left;
			delete erase_root;
			return true;
		}
		if (erase_root->left == NULL && erase_root->right != NULL) // если есть правое поддерево, но нет левого
		{
			root = root->right;
			delete erase_root;
			return true;
		}
	}
	
	
	if (erase_root->left == NULL && erase_root->right == NULL) // удаление листа
	{
		bin_tree* parent_erase = find_parent(data, root);
		if (parent_erase->left == erase_root)
			parent_erase->left = NULL;
		else
			parent_erase->right = NULL;
		delete erase_root;
		return true;
	}
	if (erase_root->left != NULL && erase_root->right == NULL) // если есть левое поддерево, но нет правого
	{
		bin_tree* parent_erase = find_parent(data, root);
		if (parent_erase->left == erase_root)
			parent_erase->left = erase_root->left;
		else
			parent_erase->right = erase_root->left;
		delete erase_root;
		return true;
	}
	if (erase_root->left == NULL && erase_root->right != NULL) // если есть правое поддерево, но нет левого
	{
		bin_tree* parent_erase = find_parent(data, root);
		if (parent_erase->left == erase_root)
			parent_erase->left = erase_root->right;
		else
			parent_erase->right = erase_root->right;
		delete erase_root;
		return true;
	}
	if (erase_root->left != NULL && erase_root->right != NULL) // есть оба поддерева
	{
		bin_tree* min_node = find_min(erase_root->right);
		bin_tree* parent_min_node = find_parent(min_node->data, root);
		if (min_node->right == NULL) // у минимального нет поддеревьев
		{
			erase_root->data = min_node->data;
			parent_min_node->right = NULL;
			delete min_node;
			return true;
		}
		else // у минимального есть правое поддерево
		{
			erase_root->data = min_node->data;
			parent_min_node->right = min_node->right;
			delete min_node;
			return true;
		}
	}
	

	
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
void tree::print_tree(bin_tree* root, int ident, int level) const
{		
	if (root)
	{
		print_tree(root->left,-1, level + 2);
		for (int i = 0; i < level; i++) cout << "   ";
		if (ident == 0)
			cout << "к: "<< root->data << "----------------------------------" << endl;
		if (ident == 1)
			cout << "п : "<< root->data << endl;
		if (ident == -1)
			cout << "л: "<< root->data << endl;
		print_tree(root->right,1, level + 2);
	}	
	
}



