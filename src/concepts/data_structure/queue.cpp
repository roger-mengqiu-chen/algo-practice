#include <iostream>
#include "node.hpp"


template <typename T>
class Queue {
private:
    Node<T>* first;
    Node<T>* last;
    int size;

public:
    Queue() : first(nullptr), last(nullptr), size(0) {}
    ~Queue() {
        while (first != nullptr) {
            Node<T>* tmp = first;
            first = first->getNext();
            delete first;
        }
    }

    bool isEmpty() {
        return first == nullptr;
    }

    void enqueue(T val) {
        Node<T>* t = new Node(val);  
        if (isEmpty()) {
            first = t;
            last = t;
        }
        else {
            last->setNext(t);
            last = t;
        }

        size++;
    }

    T dequeue() {
        if (size == 0) {
            throw std::out_of_range("Queue is empty");
        }

        Node<T>* next = first->getNext();
        T result = first->getValue();
        delete first;
        first = next;
        if (isEmpty()) {
            last = nullptr;
        }
        size--;
        return result;
    }

    void reverse() {
        if (size == 0 || size == 1) return;

        Node<T>* cur = first->getNext();
        first->setNext(nullptr);
        while (cur != nullptr) {
            Node<T>* next = cur->getNext();
            cur->setNext(first);
            first = cur;
            cur = next;
        }
    }
};


int main() {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.reverse();
    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;
    std::cout << q.dequeue() << std::endl;
    return 0;
}