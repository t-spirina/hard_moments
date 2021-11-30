#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
/*
2. Создать класс, представляющий матрицу. Реализовать в нем метод,
вычисляющий определитель матрицы.
*/

class Matrix
{
public:
    Matrix(int matixSize);
    void printMatrix();
    void fillMatrix();
    int determinant();
private:
    int m_size;
    int m_determinant;
    int getDeterminant(std::vector<std::vector <int>> matrix,int size);
    std::vector<std::vector <int>>m_matrix;

};


