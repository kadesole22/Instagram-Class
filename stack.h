#ifndef STACK_H
#define STACK_H
#include <iostream>
template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* topPtr;

public:
    Stack() : topPtr(nullptr) {}
    ~Stack() {
        makeEmpty();
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            topPtr = newNode;
        } else {
            newNode->next = topPtr;
            topPtr = newNode;
        }
    }

    T pop() {
        if (isEmpty()) {
            // Handle error when stack is empty
        } else {
            T poppedValue = topPtr->data;
            Node* temp = topPtr;
            topPtr = topPtr->next;
            delete temp;
            return poppedValue;
        }
    }

    T peek() const {
        if (isEmpty()) {
            // Handle error when stack is empty
        } else {
            return topPtr->data;
        }
    }

    bool isEmpty() const {
        return topPtr == nullptr;
    }

    void makeEmpty() {
        while (!isEmpty()) {
            pop();
        }
    }

    void print() const {
        Node* current = topPtr;
        while (current != nullptr) {
            std::cout << current->data << " \n";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif /* STACK_H */
