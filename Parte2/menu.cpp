#include <iostream>

using namespace std;

int mostrarMenu() {
    int opcion = 0;

    while(true){
        cout << "\n===== MENU =====\n";
        cout << "1. Comprimir y Encriptar\n";
        cout << "2. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        if (opcion == 1 || opcion == 2){
            return opcion;
        }
        cout << "Error: Debe ser 1 o 2." << endl;
    }
}

int pedirMetodo() {
    int metodo = 0;

    while(true) {
        cout << "\nSeleccione metodo de compresion:" << endl;
        cout << "  1. RLE" << endl;
        cout << "  2. LZ78" << endl;
        cout << "Opcion: ";
        cin >> metodo;
        if (metodo == 1 || metodo == 2){
            return metodo;
        }
        cout << "Error: Debe ser 1 o 2." << endl;
    }
}


int pedirRotacion() {
    int n = 0;
    while (n <= 0 || n >= 8) {
        cout << "Ingrese rotacion de bits (1-7): ";
        cin >> n;
        if (n <= 0 || n >= 8)
            cout << "Error: Debe ser un valor entre 1 y 7." << endl;
    }
    return n;
}

unsigned char pedirClave(){
    int K_int = -1;
    while (K_int < 0 || K_int > 255) {
        cout << "Ingrese clave K (0-255): ";
        cin >> K_int;
        if (K_int < 0 || K_int > 255)
            cout << "[Error] Debe ser un valor entre 0 y 255." << endl;
    }
    return (unsigned char)K_int;
}
