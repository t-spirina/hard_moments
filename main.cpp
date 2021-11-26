#include <iostream>
#include "header.h"
#include <vector>
#include "vowelscount.h"
#include "countfromfile.h"

int main()
{
    int a=10;
    int b=12;
    int *pa=&a;
    int *pb=&b;

    std::cout << "pa= "<<pa << "  "<<*pa<<std::endl;
    std::cout << "pb= "<<pb << "  "<<*pb<< std::endl;
    Swap(pa,pb);
    std::cout << "pa= "<<pa <<"  "<<*pa<< std::endl;
    std::cout << "pb= "<<pb << "  "<<*pb<<std::endl;


    std::vector<int*> v;
    for(int i = 0; i < 8; i++)
    {
        int *c = new int;
        *c = rand()%1000;
        v.push_back(c);
    }
    PrintVec(v);
    SortPointers(v);
    PrintVec(v);

    // сначала сделела через разовое считывание в вектор из файла,
    //потом подумала, что напрямую читать и считать получится быстрее,
    //но на сама деле нет - быстрее в вектор, а потом обрабатывать его
    // тут оставила обе версии.
    std::cout<<"Операции с данными из вектора: "<<std::endl;
    vowelsCount WaP("./WaP.txt");
    std::vector<int32_t> count;
    WaP.readToVec();
    count.push_back(WaP.counIfFind());
    count.push_back(WaP.countIfFor());
    count.push_back(WaP.countIfForfor());
    count.push_back(WaP.forFind());
    count.push_back(WaP.forFor());

    std::cout<<"Операции с данными из файла: "<<std::endl;
    CountFromFile WaP2;
    std::ifstream file;
    file.open("./WaP.txt");
    if (file.is_open())
    {
        count.push_back(WaP2.counIfFind(file));
        file.close();
        // пробовала тут делать через file.seekg(0), но не получилось,
        //не стала переделывать оставила через open/close
        file.open("./WaP.txt");
        count.push_back(WaP2.countIfFor(file));
        file.close();

        file.open("./WaP.txt");
        count.push_back(WaP2.countIfForfor(file));
        file.close();

        file.open("./WaP.txt");
        count.push_back(WaP2.forFind(file));
        file.close();

        file.open("./WaP.txt");
        count.push_back(WaP2.forFor(file));
        file.close();
    }
    std::cout<<"результат подсчета: "<<std::endl;
    for(auto c:count){std::cout<<c<<" ";}

    return 0;
}
