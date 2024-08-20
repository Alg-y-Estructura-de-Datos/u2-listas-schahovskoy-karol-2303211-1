#include <iostream>
#include "Lista/CircList.h"

using namespace std;

class Contacto {
public:
    string nombre;
    string telefono;

    Contacto() : nombre(""), telefono("") {}
    Contacto(const string &n, const string &t) : nombre(n), telefono(t) {}

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream &os, const Contacto &c) {
        os << "Nombre: " << c.nombre << ", Teléfono: " << c.telefono;
        return os;
    }

    bool operator==(const Contacto& other) const {
        return nombre == other.nombre;
    }

    string getNombre() const {
        return nombre;
    }
};

void cargaContactos(CircList<Contacto> &lista){
    lista.insertarUltimo(Contacto("Alice", "123456"));
    lista.insertarUltimo(Contacto("Bob", "654321"));
    lista.insertarUltimo(Contacto("Charlie", "789012"));
    lista.insertarUltimo(Contacto("Diana", "345678"));
    lista.insertarUltimo(Contacto("Eve", "901234"));
}

void mostrarContactos(CircList<Contacto> &lista){
    if (lista.esVacia()){
        cout<<"La lista esta vacia"<<endl;
    }
    lista.imprimir();
}

bool busqueda (CircList<Contacto> &lista, string &nombre){
    int tama=lista.getTamanio();
    for (int i=0; i<tama; i++){
        Contacto c = lista.getDato(i);
        if (c.getNombre() == nombre){
            return true;
        }
    }
    return false;
}

void borrarContacto(CircList<Contacto> &lista, string &nombre) {
    int tamanio = lista.getTamanio();
    for (int i = 0; i < tamanio; i++) {
        Contacto c = lista.getDato(i);
        if (c.nombre == nombre) {
            lista.eliminarPorValor(c);
            cout << "Contacto eliminado: " << c << endl;
            return;
        }
    }
    cout << "Contacto no encontrado para eliminar." << endl;
}


int main() {
    CircList<Contacto> lista;

    cargaContactos(lista);

    cout << "Lista de contactos:" << endl;
    mostrarContactos(lista);

    string nombreABuscar = "Charlie";
    cout << "Buscando contacto con nombre " << nombreABuscar << ":" << endl;
    busqueda(lista, nombreABuscar);

    string nombreAEliminar = "Bob";
    cout << "Eliminando contacto con nombre " << nombreAEliminar << ":" << endl;
    borrarContacto(lista, nombreAEliminar);

    cout << "Lista de contactos después de la eliminación:" << endl;
    mostrarContactos(lista);

    cout << "Número de contactos en la lista: " << lista.getTamanio() << endl;

    return 0;
}
