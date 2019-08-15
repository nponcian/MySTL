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

    unsigned size() const { return size_; }

private:
    struct Node
    {
        key_type key;
        Node* leftChildNode;
        Node* rightChildNode;
    };

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
