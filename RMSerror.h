#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
/*
 * функция рассчета ошибки, которой обладает цифровой сигнал по сравнению с аналоговым

double RMSerror(std::vector<float>& analogSignal,std::vector<int>& digitalSignal)
    {
        int index=-1;
        return std::accumulate(analogSignal.begin(), analogSignal.end(), 0.0,
        [&index,&digitalSignal](float accSum, float aSgnl)
        {
            index++;
            return accSum+(pow((aSgnl-digitalSignal[index]),2));
        });
    }
*/
//вычисление с использованием accumulate выглядит довольно громоздко и использует цикл.
//Второй вариант:

double RMSerror(std::vector<float>& analogSignal,std::vector<int>& digitalSignal)
{

    return std::inner_product(analogSignal.begin(),analogSignal.end(),
                              digitalSignal.begin(), 0.0,
                              std::plus<float>{},
                              [](float_t aSgnl, int dSgnl)
                              {return pow((aSgnl-dSgnl),2);});
}
