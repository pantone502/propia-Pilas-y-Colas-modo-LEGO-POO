#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* siguiente;
};

//  CLASE PADRE 
class Lista {
protected:
    Nodo* cabeza;

public:
    Lista() : cabeza(nullptr) {}

    // Mostrar lectura
    void mostrar() {
        Nodo* actual = cabeza;
        while (actual) {
            cout << actual->valor << " -> ";
            actual = actual->siguiente;
        }
        cout << "NULL" << endl;
    }

    ~Lista() {
        while (cabeza) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

//  CLASE HIJA: PILA (LIFO) 
class Pila : public Lista {
public:

    // push_it → agrega al tope (frente)
    void push_it(int valor) {
        Nodo* nuevo = new Nodo{valor, cabeza};
        cabeza = nuevo;
        cout << "[Pila] push_it: " << valor << endl;
    }

    // pop → elimina del tope (frente)
    void pop() {
        if (!cabeza) {
            cout << "[Pila] pop: pila vacía" << endl;
            return;
        }
        Nodo* temp = cabeza;
        cout << "[Pila] pop: " << temp->valor << endl;
        cabeza = cabeza->siguiente;
        delete temp;
    }
};

//   CLASE HIJA: COLA (FIFO) 
class Cola : public Lista {
public:

    // push → agrega al final
    void push(int valor) {
        Nodo* nuevo = new Nodo{valor, nullptr};
        if (!cabeza) {
            cabeza = nuevo;
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente)
                actual = actual->siguiente;
            actual->siguiente = nuevo;
        }
        cout << "[Cola] push: " << valor << endl;
    }

    // pull → elimina del frente
    void pull() {
        if (!cabeza) {
            cout << "[Cola] pull: cola vacía" << endl;
            return;
        }
        Nodo* temp = cabeza;
        cout << "[Cola] pull: " << temp->valor << endl;
        cabeza = cabeza->siguiente;
        delete temp;
    }
};

//   MAIN 
int main() {

    // --- Pila ---
    Pila pila;
    pila.push_it(4);
    pila.push_it(10);
    pila.push_it(8);
    cout << "Pila: ";
    pila.mostrar();
    pila.pop();
    cout << "Pila tras pop: ";
    pila.mostrar();

    cout << endl;

    // --- Cola ---
    Cola cola;
    cola.push(12);
    cola.push(5);
    cola.push(7);
    cout << "Cola: ";
    cola.mostrar();
    cola.pull();
    cout << "Cola tras pull: ";
    cola.mostrar();

    return 0;
}