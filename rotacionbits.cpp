#include <iostream>

unsigned char rotateLeft(unsigned char c, int n) {
    return (c << n) | (c >> (8 - n));
}

unsigned char rotateRight(unsigned char c, int n) {
    return (c >> n) | (c << (8 - n));
}
