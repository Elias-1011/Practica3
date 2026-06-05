#ifndef LZ78_H
#define LZ78_H

struct Entry {
    int prefix;
    char c;
};

int     compresion_LZ78      (const char* input, Entry* salida);
char*   descompresion_LZ78_str(Entry* input, int n, int& longSalida);
std::string serializarPares  (Entry* pares, int n);
Entry*  deserializarPares    (const std::string& s, int& outN);

#endif // LZ78_H
