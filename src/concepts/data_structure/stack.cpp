#include <iostream>
#include "node.hpp"


template<typename T>
class Stack {
private:
    Node<T>* first;
    Node<T>* last;
    int size;

public:
    Stack() : first(nullptr), last(nullptr), size(0) {}

    ~Stack() {
        while (first != nullptr) {
            Node<T>* tmp = first;
            first = first->getNext();
            delete tmp;
        }
    }

    class Iterator {
    private:
        Node<T>* current;
    public:
        Iterator(Node<T>* node) : current(node) {} 

        Iterator& operator++() {
            if(current) current = current->getNext();
            return *this;
        }

        const T& operator*() const {
            return current->getValue();
        }

        bool operator!= (const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() {
        return Iterator(first);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    void push(T val) {
        Node<T>* ptr_new_node = new Node(val, first);
        first = ptr_new_node;
        size ++;
    }

    T pop() {
        if(size == 0) {
            throw std::out_of_range("Stack is empty");
        }

        Node<T>* tmp = first;
        T val = first->getValue();
        first = first->getNext();
        delete tmp;
        size --;
        return val;
    }

    int getSize() const { return size; }
};


int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(1);
    Stack<int>::Iterator i = s.begin();
    std::cout << *i << std::endl;
    return 0;
}
