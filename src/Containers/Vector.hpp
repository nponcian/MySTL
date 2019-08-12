#ifndef SRC_CONTAINERS_VECTOR_HPP
#define SRC_CONTAINERS_VECTOR_HPP

#include <iostream>
#include <string>

namespace mystl
{

template <typename DataType>
class vector
{
public:
    vector() :
        length_(DEFAULT_LENGTH_),
        size_(EMPTY_SIZE_)
    {
        data_ = static_cast<DataType*>(::operator new(sizeof(DataType) * length_));
        // if using char* data_ // data_ = new char[sizeof(DataType) * length_];
        std::cout << "\n my_vector Constructor() " << size_ << " " << length_;
    }

    ~vector()
    {
        cleanUpData();
    }

    void push_back(const DataType& data)
    {
        std::cout << "\n PUSH_BACK";
        if (size_ >= length_)
        {
            std::cout << "\n MOVING ELEMENTS " << size_ << " " << length_;
            DataType* temporaryData = static_cast<DataType*>(::operator new(sizeof(DataType) * length_ * MEMORY_EXPANSION_MULTIPLIER_));
            // if using char* data_ // char* temporaryData = new char[sizeof(DataType) * length_ * MEMORY_EXPANSION_MULTIPLIER_];
            for (unsigned index = 0u; index < length_; ++index)
            {
                new (temporaryData + index) DataType(data_[index]);
                // or // new (temporaryData + index) DataType(*(data_ + index));
                // if using char* data_ // new (temporaryData + (sizeof(DataType) * index)) DataType(*(reinterpret_cast<DataType*>(data_ + (sizeof(DataType) * index))));
            }
            ::operator delete (data_);
            length_ *= MEMORY_EXPANSION_MULTIPLIER_;
            data_ = temporaryData;
            std::cout << "\n MOVING ELEMENTS DONE " << size_ << " " << length_;
        }
        // if using char* data_ // new (data_ + (sizeof(DataType) * size_)) DataType(data);
        new (data_ + size_) DataType(data);
        ++size_;
    }

    // if using char* data_
    // DataType at(const unsigned index)
    // {
    //     return *(reinterpret_cast<DataType*>(data_ + sizeof(DataType) * index));
    // }
    DataType& at(const unsigned index)
    {
        // if using char* data_ // return data_[sizeof(DataType) * index];
        return data_[index];
    }

    unsigned size()
    {
        return size_;
    }

private:
    void cleanUpData()
    {
        for (unsigned index = 0u; index < length_; ++index)
        {
            // delete[] data_[index];
        }
        ::operator delete (data_);
    }

    static const unsigned EMPTY_SIZE_ = 0u;
    static const unsigned DEFAULT_LENGTH_ = 5u;
    static const unsigned MEMORY_EXPANSION_MULTIPLIER_ = 2u;

    unsigned length_;
    unsigned size_;
    DataType* data_;
};

} // namespace mystl

#endif // SRC_CONTAINERS_VECTOR_HPP
