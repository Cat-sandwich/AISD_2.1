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
	while (number <= 1)
	{
		while (!(cin >> number) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Введите корректное значение...\n";
		}
		if (number <= 1) cout << "Введите корректное значение...\n";

	}

	return number;
}

void print_array(tree* array, int current, int size)
{

	if (array == NULL) cout << "Деревьев нет(\n\n";
	else
	{
		cout << "Дерево №" << (current + 1) << "\n";
		array[current].print_tree(array[current].get_root());
	}
}
tree create_new_tree()
{
	cout << "Введите кол-во элементов в дереве: ";
	int n = check_int();

	cout << "Введите значение корня: ";
	int a = check_int();
	tree new_tree(a);
	
	for (int i = 0; i < n - 1; i++)
	{
		cout << "Введите значение узла № " << i + 1 << ":" << endl;
		a = check_int();
		while (new_tree.insert(a) == false)
		{
			cout << "Такое значение уже есть, нужно ввести отличное от предыдущих!" << endl;
			a = check_int();
		}
	}
	return new_tree;
}
tree* add_tree(tree* array, int current, int* size)
{
	
	tree* new_array = new tree[*size + 1];

	for (int i = 0; i < *size + 1; i++)
	{
		if (i < current)
			new_array[i] = array[i];
		else if (i == current)
			new_array[i] = create_new_tree();
		else if (i > current)
			new_array[i] = array[i - 1];
	}	
	*size += 1;
	
	return new_array;
}

tree* delete_one_tree(tree* array,int* current, int* size)
{
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
	*current -= 1;
	return new_array;
}
tree* delete_all_tree(tree* array, int *current, int *size)
{
	delete[] array;
	*current = 0;
	*size = 0;
	return NULL;
}
void menu1()
{
	int key = 0;
	bool menu1 = true;
	int current = 0, size = 0;
	tree* array = NULL;
	while (menu1)
	{

		system("cls");
		cout << "\tМОИ ДЕРЕВЬЯ\n" << endl;
		print_array(array, current, size);

		cout << "1 - Создать дерево\n2 - Удалить текущее дерево \n3 - Удалить все деревья" << endl;
		cout << "0 - Завершить работу" << endl;
		cout << "-> Вправо\n-< Влево\n" << endl;

		key = get_key();
		switch (key)
		{
		case 49:
			array = add_tree(array, current, &size);
			break;
		case 50:
			if (size == 0)
			{
				cout << "Если деревьев нет, то и удалять нечего)";
				break;
			}
			array = delete_one_tree( array, &current, &size);
			break;
		case 51:
			if (size == 0)
			{
				cout << "Если деревьев нет, то и удалять нечего)";
				break;
			}
			array = delete_all_tree(array, &current, &size);
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

	cout << "Здравствуйте! Вас приветствует программа \"МНОГО МАТРИЦ\"\n" << endl;
	system("pause");
	menu1();

	return 0;
}