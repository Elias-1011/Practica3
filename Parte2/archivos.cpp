#include <iostream>
#include <fstream>
#include <stdexcept>
#include "LZ78.h"

using namespace std;

void escribirArchivo(const string& ruta, const string& contenido) {
    ofstream archivo(ruta);
    if (!archivo.is_open())
        throw runtime_error("No se pudo escribir: " + ruta);
    archivo << contenido;
}

string leerArchivo(const string& ruta) {
    ifstream archivo(ruta);
    if (!archivo.is_open())
        throw runtime_error("No se pudo abrir: " + ruta);
    string contenido((istreambuf_iterator<char>(archivo)),
                     istreambuf_iterator<char>());
    if (contenido.empty())
        throw runtime_error("El archivo esta vacio: " + ruta);
    return contenido;
}

string pedirArchivo() {
    string texto = "";
    while (texto.empty()) {
        try {
            string nombreArchivo;
            cout << "\nIngrese nombre del archivo de entrada: ";
            cin >> nombreArchivo;
            texto = leerArchivo(nombreArchivo);
            cout << "Archivo leido: " << texto.size() << " caracteres\n";
        } catch (const runtime_error& e) {
            cerr << "[Error] " << e.what() << "\n";
            cout << "Intente con otro archivo.\n";
        }
    }
    return texto;
}

string serializarPares(Entry* pares, int n) {
    string out;
    for (int i = 0; i < n; i++) {
        out += to_string(pares[i].prefix);
        out += ',';
        out += to_string((int)(unsigned char)pares[i].c);
        if (i + 1 < n) out += '|';
    }
    return out;
}

Entry* deserializarPares(const string& s, int& outN) {
    outN = 0;
    if (s.empty()) return nullptr;
    for (char c : s) if (c == '|') outN++;
    outN++;
    Entry* pares = new Entry[outN];
    int idx = 0;
    size_t pos = 0;
    while (pos < s.size()) {
        size_t bar   = s.find('|', pos);
        string token = s.substr(pos, bar == string::npos ? string::npos : bar - pos);
        size_t coma  = token.find(',');
        if (coma == string::npos)
            throw runtime_error("Par LZ78 mal formado: " + token);
        pares[idx].prefix = stoi(token.substr(0, coma));
        pares[idx].c      = (char)stoi(token.substr(coma + 1));
        idx++;
        if (bar == string::npos) break;
        pos = bar + 1;
    }
    return pares;
}
