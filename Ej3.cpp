#include <iostream>
#include "Lista/Lista.h"
using namespace std;

void intercambiar(Lista<int> &lista1, Lista<int> &lista2){
    Lista<int> aux1;
    Lista<int> aux2;

    for(int i =0; i<lista1.getTamanio(); i++){
        aux1.insertarUltimo(lista1.getDato(i));
    }
    for(int i =0; i<lista2.getTamanio(); i++){
        aux2.insertarUltimo(lista2.getDato(i));
    }

    lista1.vaciar();
    lista2.vaciar();

    for(int i =0; i<aux2.getTamanio(); i++){
        lista1.insertarUltimo(aux2.getDato(i));
    }

    for(int i =0; i<aux1.getTamanio(); i++){
        lista2.insertarUltimo(aux1.getDato(i));
    }
}

int main(){
    Lista<int> lista1;
    Lista<int> lista2;

    int n, dato;
    for (int i=0; i<10; i++){
        cout<<"Ingrese el elemento "<<i+1<<endl;
        cin>>n;
        lista1.insertarUltimo(n);
    }
    for (int i=0; i<8; i++){
        cout<<"Ingrese el elemento "<<i+1<<endl;
        cin>>n;
        lista2.insertarUltimo(n);
    }
    lista1.print();
    lista2.print();
    intercambiar(lista1,lista2);
    lista1.print();
    lista2.print();
    return 0;
}
