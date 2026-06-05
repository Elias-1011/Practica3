#include <iostream>
#include <string>
#include <stdexcept>
#include <cstring>
#include "RLE.h"
#include "LZ78.h"
#include "encriptacion.h"

using namespace std;

void probarRLE() {
    cout << "=== MODULO 1: RLE ===\n";

    string original   = "AAAABBBCC";
    string esperado   = "4A3B2C";
    string comprimido = compresion_rle(original);
    string recuperado = descompresion_rle(comprimido);

    cout << "Original:    " << original   << "\n";
    cout << "Comprimido:  " << comprimido << "\n";
    cout << "Esperado:    " << esperado   << "\n";
    cout << "Recuperado:  " << recuperado << "\n";
    cout << (recuperado == original ? "[OK] Recuperacion correcta" : "[FAIL] Recuperacion incorrecta") << "\n";
}

void probarLZ78() {
    cout << "\n=== MODULO 2: LZ78 ===\n";

    const char* original = "ABAABABA";
    Entry salida[1000];
    int n = compresion_LZ78(original, salida);

    cout << "Original: " << original << "\n";
    cout << "Pares generados: " << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << "  (" << salida[i].prefix << ", '";
        if (salida[i].c == '\0') cout << "\\0";
        else cout << salida[i].c;
        cout << "')\n";
    }

    int longSalida = 0;
    char* recuperado = descompresion_LZ78_str(salida, n, longSalida);
    cout << "Recuperado: " << recuperado << "\n";
    cout << (strcmp(recuperado, original) == 0 ? "[OK] Recuperacion correcta" : "[FAIL] Recuperacion incorrecta") << "\n";
    delete[] recuperado;
}

void probarEncriptacion() {
    cout << "\n=== MODULO 3: ENCRIPTACION ===\n";

    string msg = "Hola Mundo!";
    int len    = (int)msg.size();
    int n      = 3;
    unsigned char key = 0x5F;

    unsigned char* buf = new unsigned char[len];
    for (int i = 0; i < len; i++) buf[i] = (unsigned char)msg[i];

    encrypt(buf, len, n, key);
    cout << "Original:    " << msg << "\n";
    cout << "Encriptado:   " << buf << "\n";

    decrypt(buf, len, n, key);
    string recuperado(reinterpret_cast<char*>(buf), len);
    delete[] buf;

    cout << "Recuperado:  " << recuperado << "\n";
    cout << (recuperado == msg ? "[OK] Recuperacion correcta" : "[FAIL] Recuperacion incorrecta") << "\n";
}

int main() {
    try {
        probarRLE();
        probarLZ78();
        probarEncriptacion();
    } catch (const exception& e) {
        cerr << "[Error] " << e.what() << "\n";
        return 1;
    }
    return 0;
}
