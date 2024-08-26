#include <iostream>
#include <string>
#include "Lista/CircList.h"

using namespace std;

void cargaFrases(CircList<string> &lista){
    string frase;
    while (frase != "fin"){
        cout<<"Ingrese una frase"<<endl;
        getline(cin, frase);
        lista.insertarUltimo(frase);
    }
}

void eliminaFrases(CircList<string> &lista){
    string elimina;
    cout<<"Que frase desea eliminar?"<<endl;
    cin>>elimina;
    if (lista.contiene(elimina)){
        lista.eliminarPorValor(elimina);
        cout<<"La frase ha sido eliminada exitosamente"<<endl;
    }
    cout<<"La frase no está en la lista"<<endl;
}

void mostrarFrasesInfinito(CircList<string> &lista){
    while(true){
        if (lista.esVacia()){
        cout<<"La lista está vacia"<<endl;
        return;
    }
    lista.imprimir();
    }
}

void mostrarFrases(CircList<string> &lista){
    if (lista.esVacia()){
        cout<<"La lista está vacia"<<endl;
        return;
    }
    lista.imprimir();
}

int main(){
    CircList<string> lista;
    cargaFrases(lista);
    mostrarFrases(lista);
    eliminaFrases(lista);
    system("pause");
    mostrarFrasesInfinito(lista);
    return 0;
}