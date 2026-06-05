#include <iostream>
#include <string>
#include <stdexcept>
#include "archivos.h"
#include "encriptacion.h"
#include "LZ78.h"
#include "RLE.h"
#include "menu.h"

using namespace std;

int main() {
    try {
        cout << "=== Practica: Compresion + Encriptacion ===\n";

        int metodo        = pedirMetodo();
        int n             = pedirRotacion();
        unsigned char key = pedirClave();
        string original   = pedirArchivo();

        string archivoSalida;
        cout << "Archivo de salida: ";
        cin >> archivoSalida;

        cout << "\n[OK] Leido: " << original.size() << " bytes\n";

        // Compresion
        string comprimido;
        Entry* lzPares = nullptr;
        int    lzN     = 0;

        if (metodo == 1) {
            comprimido = compresion_rle(original);
            cout << "[OK] RLE: " << original.size()
                 << " -> " << comprimido.size() << " bytes\n";
        } else {
            lzPares    = new Entry[original.size() + 10];
            lzN        = compresion_LZ78(original.c_str(), lzPares);
            comprimido = serializarPares(lzPares, lzN);
            cout << "[OK] LZ78: " << lzN << " pares\n";
        }

        // Encriptacion
        int len = (int)comprimido.size();
        unsigned char* buf = new unsigned char[len];
        for (int i = 0; i < len; i++) buf[i] = (unsigned char)comprimido[i];
        encrypt(buf, len, n, key);
        cout << "[OK] Encriptado (n=" << n << ", K=" << (int)key << ")\n";

        // Desencriptacion
        decrypt(buf, len, n, key);
        string desencriptado(reinterpret_cast<char*>(buf), len);
        delete[] buf;
        cout << "[OK] Desencriptado\n";

        // Descompresion
        string recuperado;
        if (metodo == 1) {
            recuperado = descompresion_rle(desencriptado);
            cout << "[OK] RLE descomprimido: " << recuperado.size() << " bytes\n";
        } else {
            int    lzN2       = 0;
            Entry* pares2     = deserializarPares(desencriptado, lzN2);
            int    longSalida = 0;
            char*  raw        = descompresion_LZ78_str(pares2, lzN2, longSalida);
            recuperado = string(raw, longSalida);
            delete[] raw;
            delete[] pares2;
            cout << "[OK] LZ78 descomprimido: " << recuperado.size() << " bytes\n";
        }
        if (lzPares) delete[] lzPares;

        // Verificacion
        if (original == recuperado)
            cout << "\nVerificacion EXITOSA: textos identicos.\n";
        else
            cerr << "\nVerificacion FALLIDA.\n";

        // Escritura
        escribirArchivo(archivoSalida, recuperado);
        cout << "[OK] Resultado en: " << archivoSalida << "\n";

    } catch (const invalid_argument& e) {
        cerr << "[Error de argumento] " << e.what() << "\n"; return 1;
    } catch (const runtime_error& e) {
        cerr << "[Error de ejecucion] " << e.what() << "\n"; return 2;
    } catch (const exception& e) {
        cerr << "[Error] " << e.what() << "\n"; return 3;
    }
    return 0;
}
