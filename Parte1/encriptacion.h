#ifndef ENCRIPTACION_H
#define ENCRIPTACION_H

unsigned char rotateLeft (unsigned char c, int n);
unsigned char rotateRight(unsigned char c, int n);
void encrypt(unsigned char* data, int length, int n, unsigned char key);
void decrypt(unsigned char* data, int length, int n, unsigned char key);

#endif // ENCRIPTACION_H
