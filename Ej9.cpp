#include <iostream>
#include "Lista/ListaDoble.h"

using namespace std;

void inicializar(ListaDoble<string> &lista){
    lista.insertarUltimo("https://hola.com");
    lista.insertarUltimo("https://chau.com");
    lista.insertarUltimo("https://google.com");
    lista.insertarUltimo("https://youtube.com");
    lista.insertarUltimo("https://facebook.com");
}

void mostrar(ListaDoble<string> &lista){
    if (lista.esVacia()){
        cout<<"La lista está vacía"<<endl;
        return;
    }
    for(int i=0; i<lista.getTamanio(); i++){
        cout<<lista.getDato(i)<<endl;
    }
}

void retroceder(ListaDoble<string> &lista, int &pos){
    if (lista.esVacia()){
        cout<<"La lista está vacía"<<endl;
        return;
    }
    if (pos==0){
        cout<<"No se puede retroceder más"<<endl;
        return;
    }
    cout<<lista.getDato(pos-1)<<endl;
    pos=pos-1;
}

void avanzar(ListaDoble<string> &lista, int &pos){
    if (lista.esVacia()){
        cout<<"La lista está vacía"<<endl;
        return;
    }
    if (pos==lista.getTamanio()-1){
        cout<<"No se puede avanzar más"<<endl;
        return;
    }
    cout<<lista.getDato(pos+1)<<endl;
    pos=pos+1;
}

void menu(ListaDoble<string> &lista, int &pos){
    int opcion;
    do{
        cout<<"1. Mostrar lista"<<endl;
        cout<<"2. Retroceder"<<endl;
        cout<<"3. Avanzar"<<endl;
        cout<<"4. Ver posicion actual"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Ingrese una opcion"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                mostrar(lista);
                break;
            case 2:
                retroceder(lista, pos);
                break;
            case 3:
                avanzar(lista, pos);
                break;
            case 4:
                cout<<lista.getDato(pos)<<endl;
                break;
            case 5:
                cout<<"Adios"<<endl;
                break;
            default:
                cout<<"Opcion invalida"<<endl;
        }
    } while(opcion!=5);
}

int main(){
    ListaDoble<string> lista;
    int pos=0;
    inicializar(lista);
    menu(lista,pos);
    return 0;
}