#ifndef SRC_CONTAINERTESTER_HPP
#define SRC_CONTAINERTESTER_HPP

#include <iostream>

namespace src
{

void testContainer();

template <typename T>
void printUsingBeginToEnd(const T& t)
{
    std::cout << "\n" << "Printing Container (begin to end)...";
    for (const auto& item : t)
    {
        std::cout << "\n\t" << item << " " << &item;
    }
}

template <typename T>
void printUsingAtAndSize(const T& t)
{
    std::cout << "\n" << "Printing Container (at and size)...";
    for (unsigned index = 0; index < t.size(); ++index)
    {
        std::cout << "\n\t" << t.at(index) << " " << &(t.at(index));
    }
}

template <typename T>
void printUsingBracketAndSize(T& t)
{
    std::cout << "\n" << "Printing Container ([] and size)...";
    for (unsigned index = 0; index < t.size(); ++index)
    {
        std::cout << "\n\t" << t[index] << " " << &(t[index]);
    }
}

} // namespace src

#endif // SRC_CONTAINERTESTER_HPP
