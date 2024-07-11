#ifndef NODE_H_
#define NODE_H_

template<typename T>
class Node {
private:
    T value;
    Node* next;
public:
    Node(T v, Node* n = nullptr) : value(v), next(n) {};
    ~Node() {}
    Node* getNext() { return next; }
    void setNext(Node* n) { next = n; } 
    const T& getValue() const { return value; }
};
#endif