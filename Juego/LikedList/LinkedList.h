//
// Created by mariano on 07/11/18.
//

#ifndef PROYECTO2_LINKEDLIST_H
#define PROYECTO2_LINKEDLIST_H


#include "Node.h"
/**
 * Clase Linked List, estructura de enlace sencillo de clases tipo Nodo
 * @tparam T
 */
template <class T>
class LinkedList {

public:
    //Declaracion de atributos de la clase
    int size;
    Node<T>* head;

    //Declaracion de metodos de la clase
    bool isEmpty();
    void addInPos(T var, int pos);
    void add(T var);
    void remove(T value);
    Node<T>* getNode(int pos);
    Node<T>* getLastNode();
    Node<T>* search(T var);
    bool searchB(T var);
    T get(int i);
    Node<T>* deleteNode(T var);
    void printList();

    //Constructor de la clase
    LinkedList();

    //Destructor de la clase
    ~LinkedList() = default;

};

/**
 * Construcor de la clase
 * Se inicialilza vacio para poder agregar mas nodos posteriormente
 * @tparam T
 */
template <class T>
LinkedList<T>::LinkedList() {
    head = NULL;
    size = 0;
}

/**
 * Inserta un valor en una posicion dada
 * @tparam T
 * @param var : valor a insertar
 * @param pos : posicion en la cual se incertara el valor
 */
template <class T>
void LinkedList<T>::addInPos(T var, int pos) {
    getNode(pos)->data = var;
}
/**
 * Verifica si la lista esta vacia, retorna verdadero en caso de que no contenga elementos
 * @tparam T
 * @return : booleano
 */
template <class T>
bool LinkedList<T>::isEmpty() {
    if (head == NULL) {
        return true;
    } else {
        return false;
    }
}
/**
 * Obtiene el valor del nodo en el indice especificado
 * @tparam T
 * @param i : numero de indice de la lista
 * @return : valor que contiene el NODO
 */
template <class T>
T LinkedList<T>::get(int i){
    Node<T>* ptr = head;
    int x = 0;
    while(x != i){
        ptr = ptr->next;
        x++;
    }if(ptr == nullptr){
        return NULL;
    }
    return ptr->data;
}
/**
 * retorna el NODO en el indice especificado
 * @tparam T
 * @param pos : posicion en la lista
 * @return : NODO solicitado
 */
template <class T>
Node<T>* LinkedList<T>::getNode(int pos)
{
    Node<T>* aux = head;
    int x = 0;
    while (x != pos) {
        aux = aux->next;
        x++;
    }
    if (aux == NULL) {
        return NULL;
    }
    return aux;
}

/**
 * Agrega un Nodo al final de la lista
 * @tparam T
 * @param var : Valor a agregar
 */
template<class T>
void LinkedList<T>::add(T var) {
    if (size == 0) {
        auto* aux = new Node<T>(var);
        head = aux;
        head->next = NULL;
        size++;
    } else {
        Node<T>* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        auto* aux = new Node<T>(var);
        aux->next = NULL;
        current->next = aux;
        size++;
    }
}

/**
 * remueve el nodo de la posicion solicitada
 * @tparam T
 * @param pos : indice a eliminar
 */
template <class T>
void LinkedList<T>::remove(T value) {
    Node<T>* n = search(value);
    Node<T>* ptr = head;
    if (ptr == n) {
        head = n->next;
    } else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = n->next;
    }
}

/**
 * retorna el ultimo valor de la lista
 * @tparam T
 * @return : ultimo NODO enlistado
 */
template <class T>
Node<T>* LinkedList<T>::getLastNode() {
    Node<T>* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    return ptr;
}

/**
 * Busca un valor dado
 * @tparam T
 * @param var : Valor a buscar
 * @return : valor encontrado
 */
template <class T>
Node<T>* LinkedList<T>::search(T var) {
    Node<T>* ptr = head;
    while (ptr != NULL && ptr->data != var) {
        ptr = ptr->next;
    }

    return ptr;
}

template <class T>
bool LinkedList<T>::searchB(T var) {
    if(this->isEmpty()){
        return false;
    }else{
        Node<T>* ptr = head;
        while (ptr != NULL && ptr->data != var) {
            ptr = ptr->next;
        }
        return true;
    }
}



/**
 * Busca un NODO por su valor, y si lo encuentra lo elimina de la lista
 * @tparam T
 * @param var : Valor a eliminar
 * @return : Nodo eliminado
 */
template <class T>
Node<T>* LinkedList<T>::deleteNode(T var) {
    Node<T>* n = search(var);
    Node<T>* ptr = head;
    if (ptr == n) {
        head = n->next;
        return n;
    } else {
        while (ptr->next != n) {
            ptr = ptr->next;
        }
        ptr->next = n->next;
        return n;
    }
}
/**
 * imprime los valores contenidos dentro de los Nodos de las Listas
 * @tparam T
 */

template <class T>
void LinkedList<T>::printList() {
    Node<T>* ptr = head;
    while (ptr != NULL) {
        std::cout << ptr->data << "; " << std::flush;
        ptr = ptr->next;

    }std::cout<<std::endl;
}




#endif //PROYECTO2_LINKEDLIST_H
