#include <iostream>
#include "Lista/ListaDoble.h"
using namespace std;

class Estudiante{
    private:
    int edad;
    string nombre;
    public:
    Estudiante(int e, string n): edad(e), nombre(n){}
    bool operator==(const Estudiante& other) const {
        return nombre == other.nombre;
    }
    friend ostream& operator<<(ostream &os, const Estudiante &c) {
        os << "Nombre: " << c.nombre << ", Edad: " << c.edad;
        return os;
    }
    string getNombre() const {
        return nombre;
    }
    int getEdad() const {
        return edad;
    }
};

void mostrar(ListaDoble<Estudiante> &lista){
    if (lista.esVacia()){
        cout<<"La lista esta vacia"<<endl;
    }
    lista.imprimir();
}

bool buscar(ListaDoble<Estudiante> &lista, string &nombre){
    int tama=lista.getTamanio();
    for (int i=0; i<tama; i++){
        Estudiante c = lista.getDato(i);
        if (c.getNombre() == nombre){
            return true;
        }
    }
    return false;
}

void borrar(ListaDoble<Estudiante> &lista, string &nombre) {
    int tamanio = lista.getTamanio();
    for (int i = 0; i < tamanio; i++) {
        Estudiante c = lista.getDato(i);
        if (c.getNombre() == nombre) {
            lista.remover(i);
            return;
        }
    }
}

int main(){
    ListaDoble<Estudiante> lista;
    lista.insertarUltimo(Estudiante(20, "Alice"));
    lista.insertarUltimo(Estudiante(21, "Bob"));
    lista.insertarUltimo(Estudiante(22, "Charlie"));
    lista.insertarUltimo(Estudiante(23, "Diana"));
    lista.insertarUltimo(Estudiante(24, "Eve"));
    mostrar(lista);

    cout << "Lista de Alumnos:" << endl;
    mostrar(lista);

    string nombreABuscar = "Charlie";
    cout << "Buscando alumno con nombre " << nombreABuscar << ":" << endl;
    buscar(lista, nombreABuscar);

    string nombreAEliminar = "Bob";
    cout << "Eliminando alumno con nombre " << nombreAEliminar << ":" << endl;
    borrar(lista, nombreAEliminar);

    cout << "Lista de alumnos después de la eliminación:" << endl;
    mostrar(lista);

    cout << "Número de alumnos en la lista: " << lista.getTamanio() << endl;

    return 0;
}