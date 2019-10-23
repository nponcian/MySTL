#ifndef SRC_SAMPLECLASS_HPP
#define SRC_SAMPLECLASS_HPP

#include <iostream>
#include <string>

struct SampleClass
{
    SampleClass()
    {
        std::cout << "\n" << "SampleClass Constructor() ";
    }

    SampleClass(const SampleClass&)
    {
        std::cout << "\n" << "SampleClass Copy Constructor(const& lvalue or rvalue) ";
    }

    SampleClass(SampleClass&&) /* noexcept */
    {
        std::cout << "\n" << "SampleClass Copy Constructor(&& rvalue) ";
    }

    SampleClass& operator=(const SampleClass&)
    {
        std::cout << "\n" << "SampleClass Assignment Operator(const& lvalue or rvalue) ";
        return *this;
    }

    SampleClass& operator=(SampleClass&&)
    {
        std::cout << "\n" << "SampleClass Assignment Operator(&& rvalue) ";
        return *this;
    }

    ~SampleClass()
    {
        std::cout << "\n" << "SampleClass Destructor() ";
    }

    friend std::ostream& operator<<(std::ostream& os, const SampleClass& obj);
};

std::ostream& operator<<(std::ostream& os, const SampleClass&)
{
    return os << "print_SampleClass_";
}

struct SampleClassInt
{
    SampleClassInt(const int intVar) :
        intVar_(intVar)
    {
        std::cout << "\n" << "SampleClassInt Constructor() " << intVar;
    }

    SampleClassInt(const SampleClassInt& other)
    {
        std::cout << "\n" << "SampleClassInt Copy Constructor(const& lvalue or rvalue) " << other.intVar_;
        intVar_ = other.intVar_;
    }

    SampleClassInt(SampleClassInt&& other) /* noexcept */
    {
        std::cout << "\n" << "SampleClassInt Copy Constructor(&& rvalue) " << other.intVar_;
        intVar_ = other.intVar_;
    }

    SampleClassInt(std::initializer_list<int> params) :
        intVar_(*params.begin())
    {
        std::cout << "\n" << "SampleClassInt Constructor(initializer_list) " << *params.begin();
    }

    SampleClassInt& operator=(const SampleClassInt& other)
    {
        std::cout << "\n" << "SampleClassInt Assignment Operator(const& lvalue or rvalue) " << intVar_;
        intVar_ = other.intVar_;
        return *this;
    }

    SampleClassInt& operator=(SampleClassInt&& other)
    {
        std::cout << "\n" << "SampleClassInt Assignment Operator(&& rvalue) " << intVar_;
        intVar_ = other.intVar_;
        return *this;
    }

    ~SampleClassInt()
    {
        std::cout << "\n" << "SampleClassInt Destructor() " << intVar_;
    }

    bool operator==(const SampleClassInt& other) const
    {
        return intVar_ == other.intVar_;
    }

    bool operator!=(const SampleClassInt& other) const
    {
        return intVar_ != other.intVar_;
    }

    bool operator<(const SampleClassInt& other) const
    {
        return intVar_ < other.intVar_;
    }

    bool operator<=(const SampleClassInt& other) const
    {
        return intVar_ <= other.intVar_;
    }

    bool operator>(const SampleClassInt& other) const
    {
        return intVar_ > other.intVar_;
    }

    bool operator>=(const SampleClassInt& other) const
    {
        return intVar_ >= other.intVar_;
    }

    friend std::ostream& operator<<(std::ostream& os, const SampleClassInt& obj);

    int intVar_;
};

std::ostream& operator<<(std::ostream& os, const SampleClassInt& obj)
{
    return os << "print_SampleClassInt_" << obj.intVar_;
}

struct SampleClassIntAndStr
{
    SampleClassIntAndStr(
        const int intVar,
        const std::string& strVar) :
            intVar_(intVar),
            strVar_(strVar)
    {
        std::cout << "\n" << "SampleClassIntAndStr Constructor() " << intVar << " " << strVar;
    }

    SampleClassIntAndStr(const SampleClassIntAndStr& other)
    {
        std::cout << "\n" << "SampleClassIntAndStr Copy Constructor(const& lvalue or rvalue) "
                    << other.intVar_ << " " << other.strVar_;
        intVar_ = other.intVar_;
        strVar_ = other.strVar_;
    }

    SampleClassIntAndStr(SampleClassIntAndStr&& other)
    {
        std::cout << "\n" << "SampleClassIntAndStr Copy Constructor(&& rvalue) "
                    << other.intVar_ << " " << other.strVar_;
        intVar_ = other.intVar_;
        strVar_ = other.strVar_;
    }

    SampleClassIntAndStr& operator=(const SampleClassIntAndStr& other)
    {
        std::cout << "\n" << "SampleClassIntAndStr Assignment Operator(const& lvalue or rvalue) "
                    << intVar_ << " " << strVar_;
        intVar_ = other.intVar_;
        strVar_ = other.strVar_;
        return *this;
    }

    SampleClassIntAndStr& operator=(SampleClassIntAndStr&& other)
    {
        std::cout << "\n" << "SampleClassIntAndStr Assignment Operator(&& rvalue) "
                    << intVar_ << " " << strVar_;
        intVar_ = other.intVar_;
        strVar_ = other.strVar_;
        return *this;
    }

    ~SampleClassIntAndStr()
    {
        std::cout << "\n" << "SampleClassIntAndStr Destructor() "
                    << intVar_ << " " << strVar_;
    }

    bool operator==(const SampleClassIntAndStr& other) const
    {
        return intVar_ == other.intVar_;
    }

    bool operator!=(const SampleClassIntAndStr& other) const
    {
        return intVar_ != other.intVar_;
    }

    bool operator<(const SampleClassIntAndStr& other) const
    {
        return intVar_ < other.intVar_;
    }

    bool operator<=(const SampleClassIntAndStr& other) const
    {
        return intVar_ <= other.intVar_;
    }

    bool operator>(const SampleClassIntAndStr& other) const
    {
        return intVar_ > other.intVar_;
    }

    bool operator>=(const SampleClassIntAndStr& other) const
    {
        return intVar_ >= other.intVar_;
    }

    friend std::ostream& operator<<(std::ostream& os, const SampleClassIntAndStr& obj);

    int intVar_;
    std::string strVar_;
};

std::ostream& operator<<(std::ostream& os, const SampleClassIntAndStr& obj)
{
    return os << "print_SampleClassIntAndStr_" << obj.intVar_ << "_" << obj.strVar_;
}

#endif // SRC_SAMPLECLASS_HPP
