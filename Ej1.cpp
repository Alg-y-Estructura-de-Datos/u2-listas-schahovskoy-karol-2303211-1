#include <iostream>
#include "Lista/Lista.h"

using namespace std;

void printLista(Lista<int> lista, int p){
int tama= lista.getTamanio();

if (p>=tama||p<0){
    cout<<"Posicion invalida"<<endl;
    return;
} else {
    for (int i=p; i<tama;i++){
        cout<<lista.getDato(i)<<"->";
    }
    cout<<"NULL"<<endl;
    }
}

int main(){
    Lista<int> lista;
    int n,d,p;
    cout<<"Ingrese la cantidad de elementos de la lista"<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Ingrese el dato "<<i+1<<endl;
        cin>>d;
        lista.insertarUltimo(d);
    }

    cout<<"Ingrese la posicion desde donde quiere ver la lista"<<endl;
    cin>>p;

    printLista(lista,p);

    return 0;
}