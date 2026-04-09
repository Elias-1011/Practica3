#include "rotacionbits.h"
#include "xor.h"

void encrypt(unsigned char* data, int length, int n, unsigned char key) {
    for (int i = 0; i < length; i++) {
        data[i] = rotateLeft(data[i], n);
        data[i] ^= key;
    }
}

void decrypt(unsigned char* data, int length, int n, unsigned char key) {
    for (int i = 0; i < length; i++) {
        data[i] ^= key;
        data[i] = rotateRight(data[i], n);
    }
}
