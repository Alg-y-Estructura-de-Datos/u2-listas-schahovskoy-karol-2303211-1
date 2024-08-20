#include <iostream>
#include "Lista/Lista.h"
using namespace std;

int main(){
    Lista<char> lista;
    int cont;
    char p,v;
    cout << "Ingrese una palabra: ";
    cin >> p;
    while (p != '\n') {
        lista.insertarUltimo(p);
        cin.get(p);
    }
    lista.print();
    cout<<"Ingrese la vocal que desea contar"<<endl;
    cin>>v;
    for(int i=0; i<lista.getTamanio(); i++){
        if (lista.getDato(i)==v){
            cont++;
        }
    }
    cout<<"La vocal "<<v<<" estÃ¡ incluida en la palabra "<<cont<<" veces"<<endl;
    
    return 0;
}