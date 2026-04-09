#include <iostream>

void xorCipher(unsigned char* data, int length, unsigned char key) {
    for (int i = 0; i < length; i++) {
        data[i] ^= key;
    }
}
