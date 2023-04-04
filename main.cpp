#include <stdio.h>
#include "Binary_tree.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <iostream>
using namespace std;


int get_key()
{
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}
int check_int()
{
	int number = 0;
	while (number <= 0)
	{
		while (!(cin >> number) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������� ���������� ��������...\n";
		}
		if (number <= 0) cout << "������� ���������� ��������...\n";

	}

	return number;
}

void intersection(tree* A, bin_tree* B, int** answer, int *i)
{
	
	if (B)
	{
		if (A->contains(B->data) == true)
		{
			(*answer)[*i] = B->data;
			(*i) += 1;
		}
		intersection(A, B->left, answer, i);
		intersection(A, B->right, answer, i);
	}
	
	
}
int checking_for_availability(int number_tree, int size)
{
	number_tree = check_int();
	while (number_tree > size || number_tree < 0)
	{
		cout << "\n������ ������ ���, ������� ���������� �����: ";
		number_tree = check_int();
	}
	return number_tree;
}

tree task(bool check, int counter, int* size, tree* array)
{
	tree new_tree;
	int* answer = new int[100];
	int number_tree = -3, i = 0;
	if (check == 1)
	{
		cout << "������� ����� ������, � ������� �� ������ ��������� ����������� (�� 1 �� "<< *size <<" ) : ";
		number_tree = checking_for_availability(number_tree, *size);
		intersection(&array[counter], array[number_tree - 1].get_root(), &answer, &i);
		
		if (i == 0)
			throw exception();
		for (int j = 0; j < i; j++)
		{
			new_tree.insert(answer[j]);
		}
		new_tree.erase(0);
		return new_tree;
		
	}
	else
	{
		cout << "������� ����� ������, � ������� �� ������ ��������� (�� 0 �� " << size << " ) : ";
		number_tree = checking_for_availability(number_tree, *size);
	}
}

void print_array(tree* array, int current, int size)
{

	if (array == NULL) cout << "� ���� ��� ��������(\n\n";
	else
	{
		cout << "������ �" << (current + 1) << "\n";
		array[current].print_tree(array[current].get_root());
	}
}
tree* add_node(tree* array, int current)
{
	cout << "������� �������� ������ ����  " <<  ":" << endl;
	int data = check_int();
	while (array[current].contains(data) == true)
	{
		cout << "����� �������� ��� ����, ����� ������ �������� �� ����������!" << endl;
		data = check_int();
	}
	bool check = array[current].insert(data);
	if (check)
	{
		cout << "���������� ���� ������ �������!\n";
		system("pause");
	}

	return array;
}
tree* del_node(tree* array, int current)
{
	cout << "������� �������� ���������� ����  " << ":" << endl;
	int data = check_int();
	while (array[current].contains(data) == false)
	{
		cout << "������ �������� ���, ����� ������ ��, ������� ����!" << endl;
		data = check_int();
	}
	bool check = array[current].erase(data);
	if (check)
	{
		cout << "�������� ���� ������ �������!\n";
		system("pause");
	}
	return array;

}
tree create_new_tree()
{
	cout << "������� ���-�� ��������� � ������: ";
	int n = check_int();

	cout << "������� �������� �����: ";
	int a = check_int();
	tree new_tree(a);
	
	for (int i = 0; i < n - 1; i++)
	{
		cout << "������� �������� ���� � " << i + 1 << ":" << endl;
		a = check_int();
		while (new_tree.insert(a) == false)
		{
			cout << "����� �������� ��� ����, ����� ������ �������� �� ����������!" << endl;
			a = check_int();
		}
	}
	return new_tree;
}
tree* add_tree(tree* array, int current, int* size, tree new_tree)
{
	
	tree* new_array = new tree[*size + 1];

	for (int i = 0; i < *size + 1; i++)
	{
		if (i < current)
			new_array[i] = array[i];
		else if (i == current)
			new_array[i] = new_tree;
		else if (i > current)
			new_array[i] = array[i - 1];
	}	
	*size += 1;
	
	return new_array;
}

tree* delete_all_tree(tree* array, int* current, int* size)
{
	delete[] array;
	*current = 0;
	*size = 0;
	cout << "��� ��������!\n";
	system("pause");
	return NULL;
}

tree* delete_one_tree(tree* array,int* current, int* size)
{
	if (*size == 1)
		return delete_all_tree(array, current, size);
	int tmp_current = *current;
	tree* new_array = new tree[*size - 1];
	for (int i = 0; i < *size; i++)
	{
		if (i < tmp_current)
			new_array[i] = array[i];
		else if (i == tmp_current)
		{
			array[i].delete_tree(array[i].get_root());
		}
		else  if (i >= tmp_current)
			new_array[i - 1] = array[i];
	}
	*size -= 1;
	cout << "�������� ������ ������ �������!\n";
	system("pause");	
	return new_array;
}
void info()
{
	cout << "1 - ������� ������" << endl;
	cout << "2 - ������� ������� ������ " << endl;
	cout << "3 - ������� ��� �������" << endl;
	cout << "4 - �������� ���� � ������� ������" << endl;
	cout << "5 - ������� ���� � ������� ������" << endl;
	cout << "6 - ��������� ������ �������� ������" << endl;
	cout << "7 - ��������� �������" << endl;
	cout << "0 - ��������� ������" << endl;
	cout << "-> ������\n-< �����\n" << endl;
}
void menu1()
{
	int key = 0;
	bool menu1 = true;
	int current = 0, size = 0, height = 0, check = 0;
	tree* array = NULL;
	while (menu1)
	{

		system("cls");
		cout << "\t��� ���\n" << endl;
		print_array(array, current, size);

		info();
		key = get_key();
		switch (key)
		{
		case 48:
			menu1 = false;
			break;
		case 49:
			array = add_tree(array, current, &size, create_new_tree());
			break;
		case 50:
			if (size == 0)
			{
				cout << "���� �������� ���, �� � ������� ������)\n";
				system("pause");
				break;
			}
			array = delete_one_tree( array, &current, &size);
			break;
		case 51:
			if (size == 0)
			{
				cout << "���� �������� ���, �� � ������� ������)\n";
				system("pause");
				break;
			}
			array = delete_all_tree(array, &current, &size);
			break;
		case 52:
			if (size == 0)
			{
				cout << "���� �������� ���, �� � �������� ������)\n";
				system("pause");
				break;
			}
			array = add_node(array, current);
			break;
		case 53:
			if (size == 0)
			{
				cout << "���� �������� ���, �� � ������� ������)\n";
				system("pause");
				break;
			}
			array = del_node(array, current);
			break;
		case 54:
			if (size == 0)
			{
				cout << "���� �������� ���, �� � ������� ������)\n";
				system("pause");
				break;
			}
			height = array[current].height(array[current].get_root());
			cout << "������ = " << height << endl;
			system("pause");
			break;
		case 55:
			if (size < 2)
			{
				cout << "� ��� ������ ���� ���� �� ��� ������!" << endl;
				system("pause");
				break;
			}
			cout << "������� 1, ����� ��������� �����������, 0 - �������� " << endl;
			check = check_int();
			while ((check < 0) || (check > 1))
			{
				cout << "������� ���������� ��������" << endl;
				check = check_int();
			}
			try
			{
				array = add_tree(array, current, &size, task(check, current, &size, array));
			}
			catch (const std::exception&)
			{
				cout << "����������� ���!";
				system("pause");
			}
			
			break;
		case 75:
			if (current > 0) current--;
			break;
		case 77:
			if (current < size - 1) current++;
			break;
		default:
			break;
		}

	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "������������! ��� ������������ ��������� \"���\"\n" << endl;
	system("pause");
	menu1();

	return 0;
}