#include <iostream>
#include "lz78.h"
#include <iostream>

using namespace std;

int findEntry(Entry* dict, int size, int prefix, char c) {
    for (int i = 1; i <= size; i++) {
        if (dict[i].prefix == prefix && dict[i].c == c)
            return i;
    }
    return -1;
}

int compresion_LZ78(const char* input, Entry* salida) {
    if (!input || input[0] == '\0') return 0;
    Entry* dict = new Entry[10000];
    int dictSize = 0;
    int currentPrefix = 0;
    int salidaSize = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        int index = findEntry(dict, dictSize, currentPrefix, c);
        if (index != -1) {
            currentPrefix = index;
        } else {
            salida[salidaSize].prefix = currentPrefix;
            salida[salidaSize].c = c;
            salidaSize++;

            dictSize++;
            dict[dictSize].prefix = currentPrefix;
            dict[dictSize].c = c;
            currentPrefix = 0;
        }
    }

    if (currentPrefix != 0) {
        salida[salidaSize].prefix = currentPrefix;
        salida[salidaSize].c = '\0';
        salidaSize++;
    }
    delete[] dict;
    return salidaSize;
}

void reconstruirEntrada(Entry* dict, int index, char* buffer, int& pos) {
    if (index == 0) return;
    reconstruirEntrada(dict, dict[index].prefix, buffer, pos);
    if (dict[index].c != '\0')
        buffer[pos++] = dict[index].c;
}

char* descompresion_LZ78_str(Entry* input, int n, int& longSalida) {
    if (!input || n <= 0) {
        char* vacio = new char[1];
        vacio[0] = '\0';
        longSalida = 0;
        return vacio;
    }
    Entry* dict = new Entry[10000];
    int dictSize = 0;

    char* resultado = new char[n * 1000 + 1];
    longSalida = 0;

    for (int i = 0; i < n; i++) {
        int pref = input[i].prefix;
        char c   = input[i].c;
        reconstruirEntrada(dict, pref, resultado, longSalida);
        if (c != '\0') resultado[longSalida++] = c;
        // Mismo patrón base-1 que en compresion
        dictSize++;
        dict[dictSize].prefix = pref;
        dict[dictSize].c = c;
    }
    resultado[longSalida] = '\0';
    delete[] dict;
    return resultado;
}
