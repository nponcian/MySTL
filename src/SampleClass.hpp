#ifndef SRC_SAMPLECLASS_HPP
#define SRC_SAMPLECLASS_HPP

#include <iostream>
#include <string>

struct SampleClass
{
    SampleClass(
        const int intVar,
        const std::string& strVar) :
            intVar_(intVar),
            strVar_(strVar)
    {
        std::cout << "\n SampleClass Constructor() " << intVar << " " << strVar;
    }

    SampleClass(const SampleClass& other)
    {
        std::cout << "\n SampleClass Copy Constructor(const& lvalue or rvalue) "
                    << other.intVar_ << " " << other.strVar_;
        intVar_ = other.intVar_;
        strVar_ = other.strVar_;
    }

    SampleClass(SampleClass&& other)
    {
        std::cout << "\n SampleClass Copy Constructor(&& rvalue) "
                    << other.intVar_ << " " << other.strVar_;
        intVar_ = other.intVar_;
        strVar_ = other.strVar_;
    }

    SampleClass& operator=(const SampleClass& other)
    {
        std::cout << "\n SampleClass Assignment Operator(const& lvalue or rvalue) "
                    << intVar_ << " " << strVar_;
        intVar_ = other.intVar_;
        strVar_ = other.strVar_;
        return *this;
    }

    SampleClass& operator=(SampleClass&& other)
    {
        std::cout << "\n SampleClass Assignment Operator(&& rvalue) "
                    << intVar_ << " " << strVar_;
        intVar_ = other.intVar_;
        strVar_ = other.strVar_;
        return *this;
    }

    ~SampleClass()
    {
        std::cout << "\n SampleClass Destructor() "
                    << intVar_ << " " << strVar_;
    }

    friend std::ostream& operator<<(std::ostream& os, const SampleClass& obj);

    int intVar_;
    std::string strVar_;
};

std::ostream& operator<<(std::ostream& os, const SampleClass& obj)
{
    return os << "print_SampleClass " << obj.intVar_ << " " << obj.strVar_;
}

#endif // SRC_SAMPLECLASS_HPP
