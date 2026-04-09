#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream leer_archiv(const string& nombre_archivo) {
    ifstream file(nombre_archivo);

    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
    }

    return file;
}

// 🔥 lectura limpia (sin \n ni \r)
string lecturalinea(ifstream& file) {
    string texto = "";
    char c;

    while (file.get(c)) {
        if (c != '\n' && c != '\r') {
            texto += c;
        }
    }

    return texto;
}

// char por char (para debug)
void lecturachar(ifstream& file) {
    char c;

    while (file.get(c)) {
        if (c == '\n')
            cout << endl;
        else
            cout << c;
    }

    cout << endl;
}
