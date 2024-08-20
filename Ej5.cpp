#include <iostream>
#include "Lista/Lista.h"
using namespace std;

int main(){
    Lista<int> lista1, lista2;
    int n;
    for (int i=0; i<10; i++){
        cout<<"Ingrese el elemento "<<i+1<<endl;
        cin>>n;
        lista1.insertarUltimo(n);
    }
    int tama1=lista1.getTamanio();
    for(int i=0; i<tama1 - 1; i++){
        if (lista1.getDato(i)==lista1.getDato(i+1)){
            if (!lista2.contiene(lista1.getDato(i))) {
                lista2.insertarUltimo(lista1.getDato(i));
            }
        }
    }
    lista1.print();
    lista2.print();
    return 0;
}