//
// Created by mariano on 07/11/18.
//

#ifndef PROYECTO2_NODO_H
#define PROYECTO2_NODO_H
#include <iostream>
/**
 * Clase Nodo, utilizada para almacenar
 * @tparam T
 */
template <class T>
class Node {
public:
    T data;
    Node* next;
    Node<T> (T var);
};
/**
 * Constructor de la clase Nodo
 * @tparam T
 * @param var : valor a almacenar
 */
template <class T>
Node<T>::Node(T var) {
    this->data = var;
    this->next = nullptr;
}
#endif //PROYECTO2_NODO_H
