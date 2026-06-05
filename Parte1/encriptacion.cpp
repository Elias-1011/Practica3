#include "encriptacion.h"
#include <stdexcept>

using namespace std;

unsigned char rotateLeft(unsigned char c, int n) {
    n &= 7;
    if (n == 0) return c;
    return (unsigned char)((c << n) | (c >> (8 - n)));
}

unsigned char rotateRight(unsigned char c, int n) {
    n &= 7;
    if (n == 0) return c;
    return (unsigned char)((c >> n) | (c << (8 - n)));
}

void encrypt(unsigned char* data, int length, int n, unsigned char key) {
    if (n <= 0 || n >= 8)
        throw invalid_argument("Encrypt: n debe estar en (0, 8)");
    for (int i = 0; i < length; i++) {
        data[i] = rotateLeft(data[i], n);
        data[i] ^= key;
    }
}

void decrypt(unsigned char* data, int length, int n, unsigned char key) {
    if (n <= 0 || n >= 8)
        throw invalid_argument("Decrypt: n debe estar en (0, 8)");
    for (int i = 0; i < length; i++) {
        data[i] ^= key;
        data[i] = rotateRight(data[i], n);
    }
}
