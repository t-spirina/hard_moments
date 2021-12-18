#pragma once
#include <iostream>
#include <optional>
#include <tuple>
/*
Создайте структуру PhoneNumber с 4 полями:
·         код страны (целое число)
·         код города (целое число)
·         номер (строка)
·         добавочный номер (целое число, опциональный тип)
Для этой структуры перегрузите оператор вывода.
Необходимо, чтобы номер телефона выводился в формате: +7(911)1234567 12,
где 7 – это номер страны,
911 – номер города,
1234567 – номер,
12 – добавочный номер.
Если добавочного номера нет, то его выводить не надо.
Также перегрузите операторы < и == (используйте tie)
*/
struct PhoneNumber
{
    PhoneNumber();
    PhoneNumber(int32_t countryCode=0, int32_t cityCode=0, std::string number="",  std::optional<int32_t> addNumber=std::nullopt):
                        m_countryCode(countryCode),
                        m_cityCode(cityCode),
                        m_number(number){
                        if (addNumber.has_value())
                                m_addNumber=addNumber;}
     friend std::ostream& operator<< (std::ostream& os, const PhoneNumber& phNum);
     friend bool operator<(const PhoneNumber& p1, const PhoneNumber& p2);
     friend bool operator==(const PhoneNumber& p1, const PhoneNumber& p2);

    int32_t m_countryCode{};
    int32_t m_cityCode{};
    std::string m_number{};
    std::optional<int32_t> m_addNumber{};
};

