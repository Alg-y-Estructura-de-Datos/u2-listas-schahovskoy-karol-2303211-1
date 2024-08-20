#include <iostream>
#include "Lista/Lista.h"
using namespace std;

void remover(Lista<int> &lista, int dato){
    for (int i=0; i<lista.getTamanio(); i++){
        if (lista.getDato(i)==dato){
            lista.remover(i);
            i--;
            cout<<"Dato eliminado"<<endl;
        }
    }
}

int main(){
    Lista<int> lista;
    int n, dato;
    for (int i=0; i<10; i++){
        cout<<"Ingrese el elemento "<<i+1<<endl;
        cin>>n;
        lista.insertarUltimo(n);
    }
    lista.print();
    cout<<"Ingrese el dato que desea eliminar"<<endl;
    cin>>dato;
    remover(lista, dato);
    lista.print();
    return 0;
}
