#include <iostream>

using std::cout;
using std::endl;

template<typename T>
class Node{
public:
    Node(T data);
    void appendToTail(T data);
    Node* nextNode();
    bool hasNext();
    void setNext(T data);
    T getData();
private:
    T data;
    Node* next;
};

template<typename T>
Node<T>::Node(T data){
    this->data = data;
    this->next = nullptr;
}

template<typename T>
bool Node<T>::hasNext(){
    return (this->next != nullptr);
}

template<typename T>
void Node<T>::appendToTail(T data){
    Node* current = this;
    while(current->hasNext()){
        current = current->nextNode();
    }
    current->setNext(data);
}

template<typename T>
void Node<T>::setNext(T data){
    if(!this->hasNext())
        this->next = new Node(data);
    else
        throw "Error";
}

template<typename T>
Node<T>* Node<T>::nextNode(){
    return next;
}

template<typename T>
T Node<T>::getData(){
    return data;
}

int main(int argc, char* argv[]){
    Node<int> head(5);
    head.appendToTail(4);
    head.appendToTail(3);
    head.appendToTail(2);
    head.appendToTail(8);
    
    Node<int>* traverse = &head;
    while(traverse != nullptr){
        cout << traverse->getData() << endl;
        traverse = traverse->nextNode();
    }
}