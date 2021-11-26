#include "vowelscount.h"
#include "timer.h"

void vowelsCount::readToVec()
{
  Timer timer("read file for ");
  std::string line;
    while (std::getline(file,line))
        book.push_back(line);
    book.shrink_to_fit();
    timer.print();
}
bool isVower(char ch)
{
    return ((ch=='a')||(ch=='A')||
            (ch=='e')||(ch=='E')||
            (ch=='o')||(ch=='O')||
            (ch=='u')||(ch=='U')||
            (ch=='i')||(ch=='I')||
            (ch=='y')||(ch=='Y'));
}

bool isInVower(char ch)
{
    const std::string vowels("aAeEyYuUiIoO");
    for (char v :vowels)
        if (ch==v) return true;
    return false;
}

int32_t vowelsCount::counIfFind()
{
    int32_t  count=0;
     const std::string vowels("aAeEyYuUiIoO");
     Timer timer("Cont_if & find");
    for(size_t i=0; i<book.size();i++)
    {
        auto c=std::count_if(book[i].begin(),book[i].end(), [&vowels](char ch)
                            {return vowels.find(ch)!=std::string::npos;});
        count+=c;
    }
    timer.print();
    return count;
}

int32_t vowelsCount::countIfFor()
{
   int32_t  count=0;

   Timer timer("Cont_if & for");
   for(size_t i=0; i<book.size();i++)
   {
        auto c=std::count_if(book[i].begin(),book[i].end(), isVower);
        count+=c;
   }
   timer.print();
   return count;
}
int32_t vowelsCount::countIfForfor()
{
   int32_t  count=0;
   Timer timer("Cont_if & 2for");
   for(size_t i=0; i<book.size();i++)
   {
        auto c=std::count_if(book[i].begin(),book[i].end(), isInVower);
        count+=c;
   }
   timer.print();
   return count;
}
int32_t vowelsCount::forFind()
{
    int32_t count=0;
    const std::string vowels("aAeEyYuUiIoO");
    Timer timer("For & find");
    for(size_t i=0; i<book.size();i++)
    {
        std::for_each(book[i].begin(), book[i].end(), [&count,&vowels](char ch)
        {vowels.find(ch)!=std::string::npos ? ++count : 0 ;});
    }
    timer.print();
    return count;
}
int32_t vowelsCount::forFor()
{
    int32_t count=0;
    Timer timer("For & for");
    for(size_t i=0; i<book.size();i++)
    {
        for (size_t j=0;j<book[i].size();j++)
        {
            if(isVower(book[i][j]))
                count++;
        }
    }
    timer.print();
    return count;
}




