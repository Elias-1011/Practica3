#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

#include "lectura.h"
#include "escritura.h"
#include "rle.h"
#include "rotacionbits.h"
#include "xor.h"
#include "lz78.h"
#include "encriptacion.h"

int main() {

    cout << "---------------LECTURA--------------------" << endl;

    ifstream file;
    string texto;

    file = leer_archiv("archivoprueba.txt");
    texto = lecturalinea(file);
    file.close();

    cout << "Texto original:\n" << texto << endl;

    cout << "\n---------------RLE COMPRESION--------------------" << endl;

    string rle = compresion_rle(texto);
    cout << rle << endl;

    cout << "\n---------------RLE DESCOMPRESION--------------------" << endl;

    cout << descompresion_rle(rle) << endl;

    cout << "\n---------------LZ78--------------------" << endl;

    Entry salida[1000];
    int n_lz = compresion_LZ78(texto.c_str(), salida);

    cout << "Comprimido LZ78:\n";

    for (int i = 0; i < n_lz; i++) {
        cout << "(" << salida[i].prefix << "," << salida[i].c << ") ";
    }

    cout << "\n\nDescompresion LZ78:\n";
    descompresion_LZ78(salida, n_lz);

    cout << "\n---------------ROTACION DE BITS--------------------" << endl;

    unsigned char c = 'A'; // 65
    unsigned char str2 = 0b01000001;
    unsigned char result;

    result = rotateLeft(c, 2);

    cout << (int)result << endl;
    cout << (int)rotateRight(result, 2) << endl;

    cout << "Original: " << bitset<8>(str2) << endl;
    cout << "Rotado:   " << bitset<8>(result) << endl;

    cout << "\n---------------ENCRIPTACION (ROT + XOR)------------" << endl;

    unsigned char data[] = {'A', 'B', 'C', 'D'};
    int length = 4;

    int n = 2; // rotación
    unsigned char key = 0b10101010;

    cout << "Original:\n";
    for (int i = 0; i < length; i++)
        cout << bitset<8>(data[i]) << " ";
    cout << endl;

    // ENCRIPTAR
    encrypt(data, length, n, key);

    cout << "Cifrado:\n";
    for (int i = 0; i < length; i++)
        cout << bitset<8>(data[i]) << " ";
    cout << endl;

    // DESENCRIPTAR
    decrypt(data, length, n, key);

    cout << "Descifrado:\n";
    for (int i = 0; i < length; i++)
        cout << bitset<8>(data[i]) << " ";
    cout << endl;

    return 0;
}
