#include "Binary_tree.h"
#include <stdio.h>
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
//void tree::print(bin_tree* p, int indent = 0)
//{
//	if (p != NULL) {
//		if (p->left) print(p->left, indent + 4);
//		if (p->right) print(p->right, indent + 4);
//		if (indent) {
//			std::cout << std::setw(indent) << ' ';
//		}
//		cout << p->data << "\n ";
//	}
//}
void tree::erase(int data)
{
    bin_tree* curr = root;
    bin_tree* parent = NULL;
    while (curr && curr->data != data)
    {
        parent = curr;
        if (curr->data > data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    if (!curr)
        return;
    if (curr->left == NULL)
    {
        // Вместо curr подвешивается его правое поддерево
        if (parent && parent->left == curr)
            parent->left = curr->right;
        if (parent && parent->right == curr)
            parent->right = curr->right;
        
        delete curr;
        return;
    }
    if (curr->right == NULL)
    {
        // Вместо curr подвешивается его левое поддерево
        if (parent && parent->left == curr)
            parent->left = curr->left;
        if (parent && parent->right == curr)
            parent->right = curr->left;
       
        delete curr;
        return;
    }
    // У элемента есть два потомка, тогда на место элемента поставим
    // наименьший элемент из его правого поддерева
    bin_tree* replace = curr->right;
    while (replace->left)
        replace = replace->left;
    int replace_value = replace->data;
    erase(replace_value);
    curr->data = replace_value;
}


