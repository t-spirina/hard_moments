#include <iostream>
#include <list>
#include <numeric>
#include "myiterator.h"
#include "matrix.h"
/*
1. Написать функцию, добавляющую в конец списка вещественных чисел
элемент, значение которого равно среднему арифметическому всех его
элементов.

*/
void listAddAverageBack(std::list<int> &lst)
{
    int sum=std::accumulate(lst.begin(),lst.end(),0);
    lst.push_back(sum/lst.size());
}
void printList(std::list<int> &lst)
{
    for(int i:lst)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

int main()
{
    std::list<int> lst{ 0, 9, 5, 9, 6, 0 , 2 };
    printList(lst);
    listAddAverageBack(lst);
    printList(lst);

    std::vector<int> v{2,5,3,8,4,0};
    auto it = myIterator(v);
    std::cout<<"my iterator:\n";
    for( auto i:it)
        std::cout<<i<<" ";
    std::cout<<std::endl;

    Matrix m(3);
    m.fillMatrix();
    std::cout<<"matrix: "<<std::endl;
    m.printMatrix();
    std::cout<<std::endl<<"определитель матрицы: "<<m.determinant()<<std::endl;
    m.determinant();
    return 0;
}
