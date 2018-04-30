#include "Lista.h"

template <typename T>
Lista<T>::Lista() {
    primero=NULL;
    ultimo=NULL;
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
        p=q;
    }
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& l) {
    this->primero=l.primero;
    this->ultimo=l.ultimo;
}

template <typename T>
void Lista<T>::agregarAdelante(const T& elem) {
    Nodo* n = new Nodo(elem, primero, NULL);
    if(primero==NULL){
        primero=n;
        ultimo=n;
    }
    else{
        primero->_anterior=n;
        primero=n;
    }
}

template <typename T>
void Lista<T>::agregarAtras(const T& elem) {
    Nodo* n= new Nodo(elem,NULL,ultimo);
    if(primero==NULL){
        primero=n;
        ultimo=n;
    }else{
        ultimo->_siguiente=n;
        n->_siguiente=NULL;
        ultimo=n;
    }
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
    Nodo* p=primero;
    for(int j=0; j<i;j++){
        p=p->_siguiente;
    }
    const T& k=p->_valor;
    return k;
}

template <typename T>
void Lista<T>::eliminar(Nat i) {
    Nodo*p=primero;
    if(primero->_valor==iesimo(i)){
        primero=p->_siguiente;
    }
    else if(ultimo->_valor==iesimo(i)) {
        ultimo->_anterior->_siguiente=NULL;
    }
    else{
        while(p!=NULL) {
            if (p->_valor == iesimo(i)) {
                p->_anterior->_siguiente=p->_siguiente;
                p->_siguiente->_anterior=p->_anterior;
                break;
            }
            else{
            p = p->_siguiente;}
            }
        }
}

template <typename T>
T& Lista<T>::iesimo(Nat i) {
    // Completar (hint: es igual a la anterior...)
    Nodo*p=primero;
    for(int j=0; j<i;j++){
        p=p->_siguiente;
    }
    return p->_valor;
}

template <typename T>
void Lista<T>::mostrar(std::ostream& o) {
    Nodo*p=primero;
    while(p!=NULL){
        std::cout<<"<";
        std::cout<<p->_valor;
        p=p->_siguiente;
        std::cout<<" ,";
        std::cout<<">";
    }
}
