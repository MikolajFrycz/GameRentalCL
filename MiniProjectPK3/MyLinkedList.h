#pragma once

#include <iostream>

using namespace std;


/// Doubly linked list template class.
///
/// Used to construct doubly linked list objects of given type. Such lists store data used by the program.
template <typename T>
class MyLinkedList 
{
private:
    /// Node structure which defines nodes of the list.
    struct Node 
    {
    /// Data of a given type, that stored in the node.
    T data;
    /// Pointer, which points to the previous node in the list.
    std::shared_ptr<Node> prev;
    /// Pointer, which points to the next node in the list.
    std::shared_ptr<Node> next;
    /// Zero-argument node constructor.
    Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
    };
    /// Node-type pointer, which points to the head of the list.
    std::shared_ptr<Node> head;
    /// Node-type pointer, which points to the tail of the list.
    std::shared_ptr<Node> tail;
    /// Variable which stores the current size of the list.
    int size = 0;

public:
    /// Overloaded << operator.
    /// 
    /// @param os       ostream type variable, used to print node data.
    /// @param list     MyLinkedList type variable, used to operate on list arguments.
    friend std::ostream& operator<<(std::ostream& os, const MyLinkedList<T>& list)
    {
        auto current = list.head;
        int i = 1;
        while (current)
        {
            os << i << ". " << current->data << "\n";
            current = current->next;
            i++;
        }
        return os;
    }

    /// Zero-argument constructor.
    MyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    /// Copy-constructor
    MyLinkedList(const MyLinkedList& linked_list)
    {
        head = linked_list.head;
        tail = linked_list.tail;
        size = linked_list.size;
    }

    /// Destructor
    ~MyLinkedList()
    {
        cout << "Destructor executed\n";
    };

    /// Method used to push data to the front of the list, creating a new node there.
    /// 
    /// @param data     Data of a given type, inserted to the new node at the front.
    void pushFront(const T& data) 
    {
        auto newNode = std::make_shared<Node>(data);
        if (head) 
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else 
        {
            head = tail = newNode;
        }
        size++;
    }

    /// Method used to push data to the back of the list, creating a new node there.
    /// 
    /// @param data     Data of a given type, inserted to the new node at the back.
    void pushBack(const T& data) 
    {
        auto newNode = std::make_shared<Node>(data);
        if (tail) 
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        else 
        {
            head = tail = newNode;
        }
        size++;
    }

    /// Method used to delete a node at the front of the list.
    void popFront() 
    {
        if (head) 
        {
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            else 
            {
                tail = nullptr;
            }
        }
        size--;
    }

    /// Method used to delete a node at the back of the list.
    void popBack() 
    {
        if (tail) 
        {
            tail = tail->prev;
            if (tail) 
            {
                tail->next = nullptr;
            }
            else 
            {
                head = nullptr;
            }
        }
        size--;
    }

    /// Method used to sort data in the list.
    void sort() {
        std::shared_ptr<Node> current = head;
        while (current) {
            std::shared_ptr<Node> nextNode = current->next;
            while (nextNode) {
                if (current->data > nextNode->data) {
                    std::swap(current->data, nextNode->data);
                }
                nextNode = nextNode->next;
            }
            current = current->next;
        }
    }

    /// Method used to search for a Node with wanted data.
    /// 
    /// @param data     Data stored in a node.
    /// @param compare      Compare function used to compare.
    bool search(const T& data, bool (*compare)(const T&, const T&)) 
    {
        for (auto i = head; i; i = i->next) 
        {
            if (compare(i->data, data)) 
            {
                return true;
            }
        }
        return false;
    }

    /// Method used to delete a node at given position.
    ///
    /// @param position         Integer that stores location number of a node, that is meant to be deleted.
    void deleteNode(int position) 
    {
        if (position <= 0 or position > size) 
        {
            return;
        }

        std::shared_ptr<Node> current = head;
        for (int i = 0; i < position-1; i++)
        {
            current = current->next;
        }
        if (current == head)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else if (current == tail) 
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else 
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        size--;
    }

    /// Method that returns size of the list.
    int getSize()
    {
        return size;
    }

    /// Method used to get data stored in a node.
    /// 
    /// @param num      Position of the node, which data is wanted to be returned.
    T getNodeData(int num)
    {
        if (num <= 0 or num > size)
        {
            throw 1;
            cout << "Number out of range\n";
        }
        std::shared_ptr<Node> current = head;
        for (int i = 0; i < num - 1; i++)
        {
            current = current->next;
        }
        Node searched_node = *current;
        return searched_node.data;
    }

};