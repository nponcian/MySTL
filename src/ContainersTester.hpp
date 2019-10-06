#ifndef SRC_CONTAINERSTESTER_HPP
#define SRC_CONTAINERSTESTER_HPP

#include <iostream>

namespace src
{

void testContainers();

template <typename T>
void printUsingBeginToEndUsingLessCompare(T& t)
{
    std::cout << "\n" << __FUNCTION__;
    for (auto it = t.begin(); it < t.end(); ++it)
    {
        std::cout << "\n\t" << *it << " " << &(*it);
    }
}

template <typename T>
void printUsingConstBeginToEndUsingLessCompare(const T& t)
{
    std::cout << "\n" << __FUNCTION__ << "...";
    for (auto it = t.begin(); it < t.end(); ++it)
    {
        std::cout << "\n\t" << *it << " " << &(*it);
    }
}

template <typename T>
void printUsingBeginToEndUsingNotEqualCompare(T& t)
{
    std::cout << "\n" << __FUNCTION__;
    for (auto it = t.begin(); it != t.end(); ++it)
    {
        std::cout << "\n\t" << *it << " " << &(*it);
    }
}

template <typename T>
void printUsingConstBeginToEndUsingNotEqualCompare(const T& t)
{
    std::cout << "\n" << __FUNCTION__ << "...";
    for (auto it = t.begin(); it != t.end(); ++it)
    {
        std::cout << "\n\t" << *it << " " << &(*it);
    }
}

template <typename T>
void printUsingRangeBasedForLoop(T& t)
{
    std::cout << "\n" << __FUNCTION__ << "...";
    for (auto& item : t)
    {
        std::cout << "\n\t" << item << " " << &item;
    }
}

template <typename T>
void printUsingConstRangeBasedForLoop(const T& t)
{
    std::cout << "\n" << __FUNCTION__ << "...";
    for (const auto& item : t)
    {
        std::cout << "\n\t" << item << " " << &item;
    }
}

template <typename T>
void printUsingAtAndSize(const T& t)
{
    std::cout << "\n" << __FUNCTION__ << "...";
    for (unsigned index = 0; index < t.size(); ++index)
    {
        std::cout << "\n\t" << t.at(index) << " " << &(t.at(index));
    }
}

template <typename T>
void printUsingBracketAndSize(T& t)
{
    std::cout << "\n" << __FUNCTION__ << "...";
    for (unsigned index = 0; index < t.size(); ++index)
    {
        std::cout << "\n\t" << t[index] << " " << &(t[index]);
    }
}

} // namespace src

#endif // SRC_CONTAINERSTESTER_HPP
