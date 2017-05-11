/* "Copyright 2017 Lucas Zacchi de Medeiros" */
#ifndef STRUCTURES_LINKED_QUEUE_H
#define STRUCTURES_LINKED_QUEUE_H

#include <cstdint>
#include <stdexcept>
#include "./linked_list.h"


namespace structures {


template<typename T>
/*! Linked Queue
*
* class implementing a Linked Queue structure */
class LinkedQueue {
 protected:
 /*! Linked List
*
* Queue specializes a Linked List structure */
    structures::LinkedList<T> list{};

 public:
    LinkedQueue() {}

    ~LinkedQueue() {
        list.clear();
    }

/*! Clear
*
* Clear queue */
    void clear() {
        list.clear();
    }  // limpar

/*! Enqueue
*
* inserts element in the last position */
    void enqueue(const T& data) {
        list.push_back(data);
    }  // enfilerar

/*! Dequeue
*
* removes element from the first */
    T dequeue() {
        return list.pop_front();
    }  // desenfilerar

/*! Something something
*
* blabla */
    const T& front() const {
        return list.at(0);
    }  // primeiro dado

/*! Back
*
* returns top of the queue */
    const T& back() const {
        return list.at(size()-1);
    }  // último dado

/*! Empty
*
* Checks if empty */
    bool empty() const {
        return list.empty();
    }  // fila vazia

/*! Size
*
* Getter: size */
    std::size_t size() const {
        return list.size();
    }  // tamanho

 private:
    class Node {
     public:
        explicit Node(const T& data);
        Node(const T& data, Node* next);

        T& data();  // getter: info
        const T& data() const;  // getter-constante: info

        Node* next();  // getter: próximo
        const Node* next() const;  // getter-constante: próximo

        void next(Node* next);  // setter: próximo
     private:
        T data_;
        Node* next_;
    };

    Node* top_;  // nodo-topo
    std::size_t size_;  // tamanho
};

}  // namespace structures

#endif
