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

    std::pair<KeyDataType*, bool> insert(const KeyDataType& key)
    {
        if (!rootNode_)
        {
            rootNode_ = new Node{key, nullptr, nullptr};
            ++size_;
            return {&(rootNode_->key), true};
        }

        Node* currentNode = rootNode_;
        Node* lastNode = nullptr;
        while (currentNode != nullptr)
        {
            lastNode = currentNode;
            if (key == currentNode->key)
            {
                return {&(currentNode->key), false};
            }
            else if (key < currentNode->key)
            {
                currentNode = currentNode->leftChildNode;
            }
            else if (key > currentNode->key)
            {
                currentNode = currentNode->rightChildNode;
            }
        }

        if (lastNode == nullptr)
        {
            return {nullptr, false};
        }
        else if (key < lastNode->key)
        {
            lastNode->leftChildNode = new Node{key, nullptr, nullptr};
            ++size_;
            return {&(lastNode->leftChildNode->key), true};
        }
        else if (key > lastNode->key)
        {
            lastNode->rightChildNode = new Node{key, nullptr, nullptr};
            ++size_;
            return {&(lastNode->rightChildNode->key), true};
        }
        return {nullptr, false};
    }

    unsigned size() const { return size_; }

private:
    struct Node
    {
        KeyDataType key;
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
        delete currentNode;
    }

    static const unsigned EMPTY_SIZE_ = 0u;

    unsigned size_;
    Node* rootNode_;
};

} // namespace mystl

#endif // SRC_CONTAINERS_SET_HPP
