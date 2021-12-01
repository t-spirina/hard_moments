#include <iostream>
#include <deque>
#include <list>
#include <numeric>
#include "insert_sorted.h"
#include "RMSerror.h"
namespace conteiner {
template <class CONTEINER>
void cout(CONTEINER& forOutput)
{
    for(auto element:forOutput)
        std::cout<<element<<" ";
    std::cout<<std::endl;
}
}

int main()
{
    /*
    1. имеется отсвортированный массив целых чисел. Необходимо разработать функцию insert_sorted,
    которая принимает вектор и новое число и вставляет новое число в определенную позицию в векторе, чтобы упорядоченность контейнера сохранялась.
    реализуйте шаблонную функцию insert_sorted, которая сможет аналогично работать с любым контейнером, содержащим любой тип значений
    */
    std::vector<int> vect1 ={1,2,4,7,9,0};
    int n=5;
    std::cout<<"vector1:"<<std::endl;
    std::sort(vect1.rbegin(),vect1.rend());
    conteiner::cout(vect1);
    insert_sorted_vect(vect1,n);
    conteiner::cout(vect1);

    std::cout<<"vector:"<<std::endl;
    insert_sorted(vect1,n);
    conteiner::cout(vect1);

    std::cout<<"list:"<<std::endl;
    std::list <int> list={3,5,7};
    insert_sorted(list,n);
    conteiner::cout(list);

    std::cout<<"deque:"<<std::endl;
    std::deque <int> deque={7,3,5,2,0};
    std::sort(deque.begin(),deque.end());
    insert_sorted(deque,n);
    conteiner::cout(deque);

    std::vector<float> analogSignal(100);
    std::generate(analogSignal.begin(), analogSignal.end(), [] () mutable { return (std::rand()%100)/3.5; });
    conteiner::cout(analogSignal);

    std::vector<int> digitalSignal(analogSignal.begin(), analogSignal.end());
    conteiner::cout(digitalSignal);
    std::cout<<"RMS error: "<<RMSerror(analogSignal,digitalSignal)<<std::endl;
    return 0;
}
