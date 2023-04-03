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

	if (array == NULL) cout << "В лесу нет деревьев(\n\n";
	else
	{
		cout << "Дерево №" << (current + 1) << "\n";
		array[current].print_tree(array[current].get_root());
	}
}
tree* add_node(tree* array, int current)
{
	cout << "Введите значение нового узла  " <<  ":" << endl;
	int data = check_int();
	while (array[current].contains(data) == true)
	{
		cout << "Такое значение уже есть, нужно ввести отличное от предыдущих!" << endl;
		data = check_int();
	}
	bool check = array[current].insert(data);
	if (check)
	{
		cout << "Добавление узла прошло успешно!\n";
		system("pause");
	}

	return array;
}
tree* del_node(tree* array, int current)
{
	cout << "Введите значение удаляемого узла  " << ":" << endl;
	int data = check_int();
	while (array[current].contains(data) == false)
	{
		cout << "Такого значения нет, нужно ввести то, которое есть!" << endl;
		data = check_int();
	}
	bool check = array[current].erase(data);
	if (check)
	{
		cout << "Удаление узла прошло успешно!\n";
		system("pause");
	}
	return array;

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

tree* delete_all_tree(tree* array, int* current, int* size)
{
	delete[] array;
	*current = 0;
	*size = 0;
	cout << "Лес вырублен!\n";
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
	cout << "Удаление дерева прошло успешно!\n";
	system("pause");	
	return new_array;
}
void info()
{
	cout << "1 - Создать дерево" << endl;
	cout << "2 - Удалить текущее дерево " << endl;
	cout << "3 - Удалить все деревья" << endl;
	cout << "4 - Добавить узел в текущее дерево" << endl;
	cout << "5 - Удалить узел в текущем дереве" << endl;
	cout << "6 - Посчитать высоту текущего дерева" << endl;
	cout << "7 - Выполнить задание" << endl;
	cout << "0 - Завершить работу" << endl;
	cout << "-> Вправо\n-< Влево\n" << endl;
}
void menu1()
{
	int key = 0;
	bool menu1 = true;
	int current = 0, size = 0, height = 0, count = 0;
	tree* array = NULL;
	while (menu1)
	{

		system("cls");
		cout << "\tМОЙ ЛЕС\n" << endl;
		print_array(array, current, size);

		info();
		key = get_key();
		switch (key)
		{
		case 48:
			menu1 = false;
			break;
		case 49:
			array = add_tree(array, current, &size);
			break;
		case 50:
			if (size == 0)
			{
				cout << "Если деревьев нет, то и удалять нечего)\n";
				system("pause");
				break;
			}
			array = delete_one_tree( array, &current, &size);
			break;
		case 51:
			if (size == 0)
			{
				cout << "Если деревьев нет, то и удалять нечего)\n";
				system("pause");
				break;
			}
			array = delete_all_tree(array, &current, &size);
			break;
		case 52:
			if (size == 0)
			{
				cout << "Если деревьев нет, то и добавить некуда)\n";
				system("pause");
				break;
			}
			array = add_node(array, current);
			break;
		case 53:
			if (size == 0)
			{
				cout << "Если деревьев нет, то и удалять нечего)\n";
				system("pause");
				break;
			}
			array = del_node(array, current);
			break;
		case 54:
			if (size == 0)
			{
				cout << "Если деревьев нет, то и считать нечего)\n";
				system("pause");
				break;
			}
			height = array[current].height(array[current].get_root());
			cout << "Высота = " << height << endl;
			system("pause");
			break;
		case 55:
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

	cout << "Здравствуйте! Вас приветствует программа \"ЛЕС\"\n" << endl;
	system("pause");
	menu1();

	return 0;
}