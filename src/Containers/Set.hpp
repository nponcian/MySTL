#ifndef SRC_CONTAINERS_SET_HPP
#define SRC_CONTAINERS_SET_HPP

#include <iostream>
#include <iterator>
#include <utility>

namespace mystl
{

template <typename DataType>
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

    std::pair<DataType*, bool> insert(const DataType& data)
    {
        if (!rootNode_)
        {
            rootNode_ = new Node{data, nullptr, nullptr};
            ++size_;
            return {&(rootNode_->data), true};
        }

        Node* currentNode = rootNode_;
        Node* lastNode = nullptr;
        while (currentNode != nullptr)
        {
            lastNode = currentNode;
            if (data == currentNode->data)
            {
                return {&(currentNode->data), false};
            }
            else if (data < currentNode->data)
            {
                currentNode = currentNode->leftChildNode;
            }
            else if (data > currentNode->data)
            {
                currentNode = currentNode->rightChildNode;
            }
        }

        if (lastNode == nullptr)
        {
            return {nullptr, false};
        }
        else if (data < lastNode->data)
        {
            lastNode->leftChildNode = new Node{data, nullptr, nullptr};
            ++size_;
            return {&(lastNode->leftChildNode->data), true};
        }
        else if (data > lastNode->data)
        {
            lastNode->rightChildNode = new Node{data, nullptr, nullptr};
            ++size_;
            return {&(lastNode->rightChildNode->data), true};
        }
        return {nullptr, false};
    }

    unsigned size() const { return size_; }

private:
    struct Node
    {
        DataType data;
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
