//Kevin Arturo Alvarado Rosales y Daniel Hidalgo Badilla Tec CVA 25/08/23
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

struct Objeto {
    int peso;
    int valor;

    Objeto() {}
    Objeto(int peso, int valor)
        : peso(peso), valor(valor) {
    }
};

struct Resultado {
    int valor;
    vector<int> objetosSeleccionados;
};

void llenado(vector<Objeto> &obj, int n) {
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        Objeto nuevoObjeto;
        int peso = 0, valor = 0;
        cout << "Ingrese el peso y valor del elemento #" << i + 1 << " (separado con un espacio): ";
        cin >> peso; cin >> valor;
        nuevoObjeto.peso = peso;
        nuevoObjeto.valor = valor;
        obj.push_back(nuevoObjeto);
    }
}

void imprimir(vector<Objeto> &obj, int n) {
    cout << "\nPeso y valor de los items:" << endl;  
    for (int i = 0; i < n; ++i) {
        cout << "{" << obj[i].peso << " , " << obj[i].valor << "} ";
    }
    cout << endl << endl;
}

Resultado mochilaRecursiva(vector<Objeto> &objetos, int capacidad, int indice) {
    if (indice < 0 || capacidad == 0) {
        Resultado res;
        res.valor = 0;
        return res;
    }

    Resultado sinEsteObjeto = mochilaRecursiva(objetos, capacidad, indice - 1);
    if (objetos[indice].peso > capacidad) {
        return sinEsteObjeto;
    }

    Resultado conEsteObjeto = mochilaRecursiva(objetos, capacidad - objetos[indice].peso, indice - 1);
    conEsteObjeto.valor += objetos[indice].valor;

    if (conEsteObjeto.valor > sinEsteObjeto.valor) {
        conEsteObjeto.objetosSeleccionados.push_back(indice);
        return conEsteObjeto;
    } else {
        return sinEsteObjeto;
    }
}

int main() {
    int capacidadMochila = 0, numObject = 0;
    vector<Objeto> objetos;
    cout << "Algoritmo de la mochila\nPeso y valor de los items:" << endl;
    cout << "Capacidad máxima de la mochila: ";
    cin >> capacidadMochila;

    cout << "Número de elementos: ";
    cin >> numObject;
    llenado(objetos, numObject);
  
    Resultado resultado = mochilaRecursiva(objetos, capacidadMochila, objetos.size() - 1);

    imprimir(objetos, numObject);
    cout << "El valor máximo en la mochila es: " << resultado.valor << endl << endl;

    cout << "Objetos en la mochila:" << endl;
    for (int idx : resultado.objetosSeleccionados) {
        cout << "Objeto con peso " << objetos[idx].peso << " y valor " << objetos[idx].valor << endl;
    }

    return 0;
}