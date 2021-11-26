#pragma once
#include <vector>
/*
 * Реализуйте шаблонную функцию Swap, которая принимает два указателя и обменивает местами значения,
 * на которые указывают эти указатели (нужно обменивать именно сами указатели,
 * переменные должны оставаться в тех же адресах памяти).
*/
template<typename T>
void Swap(T &a, T &b)
 {
      const T temp = a;
      a = b;
      b = temp;
 }
/*
 * Реализуйте шаблонную функцию SortPointers,
 * которая принимает вектор указателей и сортирует указатели по значениям,
 * на которые они указывают.
 */
template<typename T>
void SortPointers(std::vector<T*> &ptrVec)
{
    size_t size = ptrVec.size();
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - 1; j++)
            if (*ptrVec[j] > *ptrVec[j + 1])
                Swap(ptrVec[j], ptrVec[j + 1]);
    }

}
//печать значений в векторе
template<typename T>
void PrintVec(std::vector<T*> &v)
{
    for(auto vi:v)
        std::cout << (*vi) << "  ";
    std::cout<<std::endl;
}
