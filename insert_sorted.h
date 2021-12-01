#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <list>
/*
    insert_sorted_vect принимает упорядоченный вектор и новое число и вставляет новое число в определенную позицию в векторе,
    чтобы упорядоченность контейнера сохранялась
*/
void insert_sorted_vect(std::vector<int> &vectIn, const int insertion)
{
    std::vector<int>::iterator it;
    if(vectIn.front()<vectIn.back())
        it=std::lower_bound(vectIn.begin(),vectIn.end(), insertion);
    else
        it=(std::lower_bound(vectIn.rbegin(),vectIn.rend(), insertion)).base();

    vectIn.insert(it, insertion);
}


/*
 шаблонная функцию insert_sorted, принимает:
 упорядоченный контейнер, содержащим любой тип значений,
 значение, которое нужно вставить в контейнер, не нарушив последовательность
 данная фукция применима только к контейнерам, у которых определен методы insert, front, back
*/

template <class CONTAINER, typename T>
void insert_sorted(CONTAINER& cntnr, const T insertion)
{
    typename CONTAINER::iterator it;
    if(cntnr.front()<cntnr.back())
        it=std::lower_bound(cntnr.begin(),cntnr.end(), insertion);
    else
        //в случае последовательности, отсортированной в обратном порядке,
        //позиция для вставки определяется через reverxe iterator
        it = (std::lower_bound(cntnr.rbegin(),cntnr.rend(), insertion)).base();
    cntnr.insert(it, insertion);
}
