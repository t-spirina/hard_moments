#pragma once

#include "phonenumber.h"
#include "person.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <tuple>
/*

В классе PhoneBook реализуйте метод SortByName, который должен сортировать элементы контейнера по фамилии людей в алфавитном порядке.
Если фамилии будут одинаковыми, то сортировка должна выполняться по именам, если имена будут одинаковы, то сортировка производится по отчествам.
Используйте алгоритмическую функцию sort.
Реализуйте метод SortByPhone, который должен сортировать элементы контейнера по номерам телефонов. Используйте алгоритмическую функцию sort.
Реализуйте метод GetPhoneNumber, который принимает фамилию человека, а возвращает кортеж из строки и PhoneNumber.
Строка должна быть пустой, если найден ровно один человек с заданном фамилией в списке.
Если не найден ни один человек с заданной фамилией, то в строке должна быть запись «not found», если было найдено больше одного человека,
то в строке должно быть «found more than 1».
Реализуйте метод ChangePhoneNumber, который принимает человека и новый номер телефона и, если находит заданного человека в контейнере,
то меняет его номер телефона на новый, иначе ничего не делает.*/

class PhoneBook
{
public:
    PhoneBook(std::ifstream &file);
    void SortByName();
    void SortByPhone();
    std::tuple<std::string, PhoneNumber> GetPhoneNumber(const std::string &surname);
    void ChangePhoneNumber(const Person &person, const PhoneNumber &phonenumber);
    friend std::ostream& operator<< (std::ostream &os, const PhoneBook &PhoneBook);

    std::vector<std::pair<Person, PhoneNumber>> m_data;

};


