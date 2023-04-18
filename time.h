#pragma once
#include <iostream>
#include "Binary_tree.h"
#include <vector>
#include <chrono>


using namespace std;

size_t lcg() {
    static size_t x = 0;
    x = (1021 * x + 24631) % 116640;
    return x;
}

float create_time(int number_nodes)
{
    chrono::duration<float> result(0), one_res(0);
    float res = 0;

    for (int i = 0; i < 100; i += 1)
    {
        auto start = chrono::high_resolution_clock::now();
        tree tmp_tree;
        
        for (int j = 0; j < number_nodes; j++)
            tmp_tree.insert(int(lcg()));

        auto end = chrono::high_resolution_clock::now();
        result += end - start;        
    }
    
    result /= 100;
    cout << endl << "�� �������� ������ �� " << number_nodes << " ��������� ����: " << result.count() << endl;
    return result.count();
}

float find_time(int number_nodes)
{
    tree tmp_tree;
    auto start = chrono::high_resolution_clock::now();
    chrono::duration<float> result(0);

    for (int j = 0; j < number_nodes; j++)
        tmp_tree.insert(int(lcg()));
    
    for (int i = 0; i < 1000; i += 1)
    {
        auto start = chrono::high_resolution_clock::now();

        tmp_tree.contains(int(lcg()));

        auto end = chrono::high_resolution_clock::now();
        result += end - start;
    }
    result /= 1000;
    cout << endl << "�� ����� ���������� �������� � ������ �� " << number_nodes << " ��������� ����: " << result.count() << endl;
    return result.count();
}

float insert_time(int number_nodes)
{
    
    tree tmp_tree;
    
    chrono::duration<float> result(0);

    for (int j = 0; j < number_nodes; j++)
        tmp_tree.insert(int(lcg()));

    for (int i = 0; i < 1000; i += 1)
    {        
        auto start = chrono::high_resolution_clock::now();
        tmp_tree.insert(int(lcg()));
        auto end = chrono::high_resolution_clock::now();
        result += end - start;
       
    }
    result /= 1000;
    cout << endl << "�� ���������� ���������� �������� � ������ �� " << number_nodes << " ��������� ����: " << result.count() << endl;
    return result.count();
}

float erase_time(int number_nodes)
{    
    tree tmp_tree;
   
    chrono::duration<float> result(0);

    for (int j = 0; j < number_nodes; j++)
        tmp_tree.insert(int(lcg()));

    for (int i = 0; i < 1000; i += 1)
    {        
        auto start = chrono::high_resolution_clock::now();
        tmp_tree.erase(int(lcg()));
        auto end = chrono::high_resolution_clock::now();
        result += end - start;
       
    }
    result /= 1000;
    cout << endl << "�� �������� ���������� �������� � ������ �� " << number_nodes << " ��������� ����: " << result.count() << endl;
    return result.count();
}

// � �������-�����������
float create_time_vector(int number_nodes)
{
    chrono::duration<float> result(0);

    for (int i = 0; i < 100; i += 1)
    {
        vector<int> tmp_vector;
        auto start = chrono::high_resolution_clock::now();
        for (int j = 0; j < number_nodes; j++)
            tmp_vector.push_back(int(lcg()));
        auto end = chrono::high_resolution_clock::now();
        result += end - start;
    }
    result /= 100;
    cout << endl << "�� �������� ������ �� " << number_nodes << " ��������� ����: " << result.count() << endl;
    return result.count();
}

float find_time_vector(int number_nodes)
{
    vector<int> tmp_vector(number_nodes);    
    chrono::duration<float> result(0);

    for (int j = 0; j < number_nodes; j++)
        tmp_vector.push_back(int(lcg()));

    for (int i = 0; i < 1000; i += 1)
    {
        auto start = chrono::high_resolution_clock::now();
        find(tmp_vector.begin(), tmp_vector.end(), int(lcg()));
        auto end = chrono::high_resolution_clock::now();
        result += end - start;
        
    }
    result /= 1000;
    cout << endl << "�� ����� ���������� �������� � ������� �� " << number_nodes << " ��������� ����: " << result.count() << endl;
    return result.count();
}

float insert_time_vector(int number_nodes)
{
    vector<int> tmp_vector(number_nodes);
    chrono::duration<float> result(0);

    for (int j = 0; j < number_nodes; j++)
        tmp_vector.push_back(int(lcg()));

    for (int i = 0; i < 1000; i += 1)
    {
        auto start = chrono::high_resolution_clock::now();
        tmp_vector.push_back(int(lcg()));
        auto end = chrono::high_resolution_clock::now();
        result += end - start;
    }
    result /= 1000;
    cout << endl << "�� ������� ���������� �������� � ������ �� " << number_nodes << " ��������� ����: " << result.count() << endl;
    return result.count();
}

float erase_time_vector(int number_nodes)
{
    vector<int> tmp_vector(number_nodes);
    chrono::duration<float> result(0);

    for (int j = 0; j < number_nodes; j++)
        tmp_vector.push_back(int(lcg()));

    for (int i = 0; i < 1000; i += 1)
    {
        auto start = chrono::high_resolution_clock::now();
        for (auto it = tmp_vector.begin(); it != tmp_vector.end(); )
        {
            if (*it == int(lcg()))
            {
                it = tmp_vector.erase(it);
                break;
            }
            else
                ++it;
        }
        auto end = chrono::high_resolution_clock::now();
        result += end - start;
    }
    result /= 1000;
    cout << endl << "�� �������� ���������� �������� � ������� �� " << number_nodes << " ��������� ����: " << result.count() << endl;
    return result.count();
}