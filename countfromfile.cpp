#include "countfromfile.h"
#include "timer.h"

int32_t CountFromFile::counIfFind(std::ifstream &file)
{
    int32_t  count=0;
    const std::string vowels("aAeEyYuUiIoO");
    Timer timer("Count_if & find");
    for(std::string word; file>>word;)
    {
        count+=std::count_if(word.begin(),word.end(), [&vowels](const char &ch)
                             {return vowels.find(ch)!=std::string::npos;});
    }
    timer.print();
    return count;
}
bool iFVower(char ch)
{
    return ((ch=='a')||(ch=='A')||
            (ch=='e')||(ch=='E')||
            (ch=='o')||(ch=='O')||
            (ch=='u')||(ch=='U')||
            (ch=='i')||(ch=='I')||
            (ch=='y')||(ch=='Y'));
}

int32_t CountFromFile::countIfFor(std::ifstream &file)
{
    int32_t  count=0;

    Timer timer("Cont_if & for");
    for(std::string word; file>>word;)
    {
         auto c=std::count_if(word.begin(),word.end(), iFVower);
         count+=c;
    }
    timer.print();
    return count;
}
bool ifInVower(char ch)
{
    const std::string vowels("aAeEyYuUiIoO");
    for (char v :vowels)
        if (ch==v) return true;
    return false;
}
int32_t CountFromFile::countIfForfor(std::ifstream &file)
{
    int32_t  count=0;
    Timer timer("Cont_if & 2for");
    for(std::string word; file>>word;)
    {
         auto c=std::count_if(word.begin(),word.end(), ifInVower);
         count+=c;
    }
    timer.print();
    return count;
}
int32_t CountFromFile::forFind(std::ifstream &file)
{
    int32_t count=0;
    const std::string vowels("aAeEyYuUiIoO");
    Timer timer("For & find");
    for(char ch; file.get(ch);)
    {
        vowels.find(ch)!=std::string::npos ? ++count : 0 ;
    }
    timer.print();
    return count;

}
int32_t CountFromFile::forFor(std::ifstream &file)
{
    int32_t count=0;
    Timer timer("For & for");
    for(char ch; file.get(ch);)
    {
            if(iFVower(ch))
                count++;

    }
    timer.print();
    return count;
}
