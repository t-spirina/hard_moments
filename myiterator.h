#pragma once
#include<iostream>
#include<vector>
/*
3. Реализовать собственный класс итератора, с помощью которого можно будет
проитерироваться по диапазону целых чисел в цикле for-range-based.
*/
class myIterator
{
private:
    int *p_begin;
    int *p_end;
public:
    myIterator(std::vector<int>& vecIn);
    int* begin();
    int* end();
    int* operator ++();
    int  operator *();
};

