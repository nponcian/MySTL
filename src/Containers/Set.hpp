#ifndef SRC_CONTAINERS_SET_HPP
#define SRC_CONTAINERS_SET_HPP

#include <iostream>
#include <iterator>
#include <utility>

namespace mystl
{

template <typename KeyDataType>
class set
{
public:
    using key_type = KeyDataType;
    using value_type = KeyDataType;
    using pointer = value_type*;
    using reference = value_type&;

    struct Node
    {
        key_type key;
        Node* leftChildNode;
        Node* rightChildNode;
    };

    class iterator : public std::iterator<std::bidirectional_iterator_tag, KeyDataType>
    {
    public:
        using difference_type = typename std::iterator<std::bidirectional_iterator_tag, KeyDataType>::difference_type;
        using pointer = typename std::iterator<std::bidirectional_iterator_tag, KeyDataType>::pointer;
        using reference = typename std::iterator<std::bidirectional_iterator_tag, KeyDataType>::reference;

        iterator() : mySet_(nullptr), lastProcessedKey_(nullptr) {}
        iterator(mystl::set<KeyDataType>* mySet) : mySet_(mySet) { lastProcessedKey_ = &(mySet_->goToLeftmostNode()->key); }
        // iterator(const iterator& other) : pointer_(other.pointer_) {}
        // iterator& operator=(const iterator& other) { pointer_ = other.pointer_; }

        iterator& operator++() { if (mySet_ && lastProcessedKey_) {lastProcessedKey_ = mySet_->upper_bound(*lastProcessedKey_);} return *this; } // prefix ++a
        iterator operator++(int) { iterator temp(*this); operator++(); return temp; } // postfix a++

        // iterator& operator--() { --pointer_; return *this; } // prefix --a
        // iterator operator--(int) { iterator temp(*this); operator--(); return temp; } // postfix a--

        // bool operator<(const iterator& other) const { return pointer_ < other.pointer_; }
        // bool operator>(const iterator& other) const { return pointer_ > other.pointer_; }
        // bool operator<=(const iterator& other) const { return pointer_ <= other.pointer_; }
        // bool operator>=(const iterator& other) const { return pointer_ >= other.pointer_; }
        // bool operator==(const iterator& other) const { return pointer_ == other.pointer_; }
        bool operator!=(const iterator& other) const { return lastProcessedKey_ != other.lastProcessedKey_; }

        reference operator*() const { return *lastProcessedKey_; }
        // pointer operator->() const { return pointer_; }

    private:
        mystl::set<KeyDataType>* mySet_;
        KeyDataType* lastProcessedKey_;
    };

    set() :
        size_(EMPTY_SIZE_),
        rootNode_(nullptr)
    {
        std::cout << "\n" << "set Constructor() " << size_;
    }

    ~set()
    {
        cleanUpData();
    }

    std::pair<pointer, bool> insert(const value_type& value)
    {
        if (!rootNode_)
        {
            rootNode_ = new Node{value, nullptr, nullptr};
            ++size_;
            return {&(rootNode_->key), true};
        }

        Node* currentNode = rootNode_;
        Node* lastNode = nullptr;
        while (currentNode)
        {
            lastNode = currentNode;
            if (value == currentNode->key)
            {
                return {&(currentNode->key), false};
            }
            else if (value < currentNode->key)
            {
                currentNode = currentNode->leftChildNode;
            }
            else if (value > currentNode->key)
            {
                currentNode = currentNode->rightChildNode;
            }
        }

        if (!lastNode)
        {
            return {nullptr, false};
        }
        else if (value < lastNode->key)
        {
            lastNode->leftChildNode = new Node{value, nullptr, nullptr};
            ++size_;
            return {&(lastNode->leftChildNode->key), true};
        }
        else if (value > lastNode->key)
        {
            lastNode->rightChildNode = new Node{value, nullptr, nullptr};
            ++size_;
            return {&(lastNode->rightChildNode->key), true};
        }
        return {nullptr, false};
    }

    pointer upper_bound(const value_type& value)
    {
        pointer upper = nullptr;
        Node* currentNode = rootNode_;
        while (currentNode)
        {
            if (currentNode->key > value)
            {
                upper = &(currentNode->key);
                currentNode = currentNode->leftChildNode;
            }
            else
            {
                currentNode = currentNode->rightChildNode;
            }
        }
        return upper;
    }

    Node* goToLeftmostNode()
    {
        Node* leftmost = rootNode_;
        Node* currentNode = rootNode_;
        while (currentNode)
        {
            leftmost = currentNode;
            currentNode = currentNode->leftChildNode;
        }
        return leftmost;
    }

    unsigned size() const { return size_; }

    iterator begin()
    {
        return iterator(this);
    }

    iterator end()
    {
        return iterator();
    }

private:
    void cleanUpData()
    {
        deleteTree(rootNode_);
    }

    void deleteTree(Node* currentNode)
    {
        if (currentNode == nullptr) return;
        deleteTree(currentNode->leftChildNode);
        deleteTree(currentNode->rightChildNode);
        std::cout << "\ndeleting " << currentNode->key;
        delete currentNode;
    }

    static const unsigned EMPTY_SIZE_ = 0u;

    unsigned size_;
    Node* rootNode_;
};

} // namespace mystl

#endif // SRC_CONTAINERS_SET_HPP
