#include "Lista.h"

template <typename T>
Lista<T>::Lista() {
    primero=NULL;
}

// Inicializa una lista vacía y luego utiliza operator= para no duplicar el
// código de la copia de una lista.
template <typename T>
Lista<T>::Lista(const Lista<T>& l) : Lista() { *this = l; }

template <typename T>
Lista<T>::~Lista() {
    Nodo* p=primero;
    while(p!=NULL){
        Nodo* q=p->_siguiente;
        delete p;
        p->_siguiente=q;
        p->_anterior=NULL;
        
    }
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& l) {
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    Nodo* n = new Nodo(elem, primero, NULL);
    primero = n;
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    Nodo* n;
    n->_valor;
    n->_siguiente=NULL;
    if(primero==NULL){
        primero=n;
    } else{
        Nodo* p=primero;
        while(p->_siguiente!=NULL){
            p=p->_siguiente;
        }
        p->_siguiente=n;
    }
    //ultimo=n;
}

template <typename T>
int Lista<T>::longitud() const {
    Nodo* p= primero;
    int i=0;
    while(p!=NULL){
        i++;
        p=p->_siguiente;
    }
    return i;
}

template <typename T>
const T& Lista<T>::iesimo(Nat i) const {
    // Completar
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    // Completar
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
}

template <typename T>
void Lista<T>::mostrar(std::ostream& o) {
	// Completar
}
