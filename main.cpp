#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <set>
#include <future>
#include <chrono>
#include <queue>

/*
Создайте потокобезопасную оболочку для объекта cout. Назовите ее pcout.
Необходимо, чтобы несколько потоков могли обращаться к pcout и информация выводилась в консоль.
Продемонстрируйте работу pcout.
*/
std::mutex pcoutMutex;
template <typename T>
void pcout(T dataForPrint)
{
       std::lock_guard<std::mutex> lock{pcoutMutex};
       std::cout << dataForPrint;
}


/*
Реализовать функцию, возвращающую i-ое простое число (например, миллионное простое число равно 15485863).
Вычисления реализовать во вторичном потоке. В консоли отображать прогресс вычисления. */
std::mutex simpleMutex;
bool isSimple(int num)
{
    if (num==2) return true;
    if ((num<2)||(num%2==0)) return false;
    for(int i=3;i<num/2;i=i+2)
        if (num%i==0) return false;
    return true;
}

void getSimpleNum (int Smpl_i, int &count, int &simpleNum)
{
    for (simpleNum=0; count<Smpl_i;simpleNum++)
    {
        if (isSimple(simpleNum))
        {
            simpleMutex.lock();
            count++;
            if (count==Smpl_i)
            {
                simpleMutex.unlock();
                break;
            }
            simpleMutex.unlock();
        }
    }
    return;
}
/*
Промоделировать следующую ситуацию. Есть два человека (2 потока): хозяин и вор.
Хозяин приносит домой вещи (функция добавляющая случайное число в вектор с периодичностью 1 раз в секунду).
При этом у каждой вещи есть своя ценность. Вор забирает вещи (функция, которая находит наибольшее число и удаляет из вектора
с периодичностью 1 раз в 0.5 секунд), каждый раз забирает вещь с наибольшей ценностью.*/
using namespace std::chrono_literals;
std::mutex  lock_boxes;
struct Box
{
    int16_t m_id;
    int16_t price;
    Box(int16_t box_num, int16_t box_price): m_id(box_num), price(box_price) {}
};

bool operator< (const Box &lbox, const Box &rbox)
{
    return lbox.price < rbox.price;
}

//std::priority_queue<Box> shelf;
std::multiset <Box> shelf;
const int numberOfBoxes = 10;
bool end;

void Human()
{
    for (int i = 0; i < numberOfBoxes; ++i)
    {
        std::this_thread::sleep_for(1000ms);
        {
            std::lock_guard shelf_lock_guard(lock_boxes);
            const std::pair<size_t, int16_t> box {i + 1, rand()% 300};
            shelf.insert(Box(box.first, box.second));
            std::cout << "new box on the shelf:   " << box.first << " price " << box.second << std::endl;
        }
        std::lock_guard shelf_lock_guard(lock_boxes);
        end = true;
    }
}

void Thief()
{
    for (int i = 0; i < numberOfBoxes; ++i)
    {
        std::this_thread::sleep_for(1500ms);
        {
            std::lock_guard shelf_lock_guard(lock_boxes);
            std::cout << "Stollen box " << shelf.end()->m_id << std::endl;

            shelf.erase(--shelf.end());

        }
    }
}




int main()
{

   int count=0;
   int num=10000;
   int simple=0;
   std::thread countSimple(getSimpleNum, num, std::ref(count), std::ref(simple));
   countSimple.detach();
   while(count!=num)
   {
       std::this_thread::sleep_for(50ms);
       simpleMutex.lock();
           std::cout<<count*100/num<<" \n";
       simpleMutex.unlock();
   }
   std::cout<<simple<<std::endl;

   std::thread human (Human);
   std::thread thief (Thief);
      human.join();
      thief.join();


   return 0;
}
