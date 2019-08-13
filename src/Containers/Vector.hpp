#ifndef SRC_CONTAINERS_VECTOR_HPP
#define SRC_CONTAINERS_VECTOR_HPP

#include <iostream>
#include <iterator>
#include <string>

namespace mystl
{

template <typename DataType>
class vector
{
public:
    vector() :
        capacity_(DEFAULT_CAPACITY_),
        size_(EMPTY_SIZE_)
    {
        std::cout << "\n" << "vector Constructor() " << capacity_ << " " << size_;
        data_ = static_cast<DataType*>(::operator new(sizeof(DataType) * capacity_));
    }

    ~vector()
    {
        cleanUpData();
    }

    void push_back(const DataType& data)
    {
        std::cout << "\n" << "push_back";
        if (size_ < capacity_)
        {
            new (data_ + size_) DataType(data);
            ++size_;
            return;
        }

        std::cout << "\n" << "moving... " << capacity_ << " " << size_;
        DataType* temporaryData = static_cast<DataType*>(::operator new(
                                    sizeof(DataType) * capacity_ * MEMORY_EXPANSION_MULTIPLIER_));
        for (unsigned index = 0u; index < capacity_; ++index)
        {
            std::cout << "\n" << "moving from " << data_ + index << " to " << temporaryData + index;
            new (temporaryData + index) DataType(data_[index]);
        }
        ::operator delete (data_);
        data_ = temporaryData;
        capacity_ *= MEMORY_EXPANSION_MULTIPLIER_;
        std::cout << "\n" << "moving done " << capacity_ << " " << size_;

        push_back(data);
    }

    DataType& at(const unsigned index) const
    {
        return data_[index];
    }

    DataType& operator[](const unsigned index)
    {
        return data_[index];
    }

    DataType& front()
    {
        return data_[0];
    }

    DataType& back()
    {
        return data_[size_ - 1];
    }

    unsigned capacity() const
    {
        return capacity_;
    }

    unsigned size() const
    {
        return size_;
    }

    class iterator : public std::iterator<std::random_access_iterator_tag, DataType>
    {
    public:
        iterator() :
            pointer_(nullptr)
        {
        }

        iterator(const iterator& other) :
            pointer_(other.pointer_)
        {
        }

        iterator& operator=(const iterator& other)
        {
            pointer_ = other.pointer_;
        }

        iterator& operator++() // prefix ++a
        {
            ++pointer_;
            return *this;
        }

        iterator operator++(int) // postfix a++
        {
            iterator temp(*this);
            operator++();
            return temp;
        }

        iterator& operator--() // prefix --a
        {
            --pointer_;
            return *this;
        }

        iterator operator--(int) // postfix a--
        {
            iterator temp(*this);
            operator--();
            return temp;
        }

        iterator operator+(typename iterator::difference_type n)
        {
            iterator temp(*this);
            return temp += n;
        }

        iterator operator-(typename iterator::difference_type n)
        {
            iterator temp(*this);
            return temp -= n;
        }

        iterator& operator+=(typename iterator::difference_type n)
        {
            pointer_ += n;
            return *this;
        }

        iterator& operator-=(typename iterator::difference_type n)
        {
            pointer_ -= n;
            return *this;
        }

        bool operator<(const iterator& other) const
        {
            return pointer_ < other.pointer_;
        }

        bool operator>(const iterator& other) const
        {
            return pointer_ > other.pointer_;
        }

        bool operator<=(const iterator& other) const
        {
            return pointer_ <= other.pointer_;
        }

        bool operator>=(const iterator& other) const
        {
            return pointer_ >= other.pointer_;
        }

        bool operator==(const iterator& other) const
        {
            return pointer_ == other.pointer_;
        }

        bool operator!=(const iterator& other) const
        {
            return pointer_ != other.pointer_; // similar to: return !(*this == other);
        }

        typename iterator::reference operator*()
        {
            return *pointer_;
        }

        typename iterator::pointer operator->()
        {
            return pointer_;
        }

        typename iterator::reference operator[](typename iterator::difference_type n)
        {
            return *(pointer_ + n);
        }

    private:
        typename iterator::pointer pointer_; // similar to: DataType* it_; // Please see std::iterator template arguments and typedefs
    };

private:
    void cleanUpData()
    {
        ::operator delete (data_);
    }

    static const unsigned EMPTY_SIZE_ = 0u;
    static const unsigned DEFAULT_CAPACITY_ = 2u;
    static const unsigned MEMORY_EXPANSION_MULTIPLIER_ = 2u;

    unsigned capacity_;
    unsigned size_;
    DataType* data_;
};

} // namespace mystl

#endif // SRC_CONTAINERS_VECTOR_HPP



/*
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
        std::cout << "\n" << "my_vector Constructor() " << size_ << " " << length_;
    }

    ~vector()
    {
        cleanUpData();
    }

    void push_back(const DataType& data)
    {
        std::cout << "\n" << "PUSH_BACK";
        if (size_ >= length_)
        {
            std::cout << "\n" << "MOVING ELEMENTS " << size_ << " " << length_;
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
            std::cout << "\n" << "MOVING ELEMENTS DONE " << size_ << " " << length_;
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
*/