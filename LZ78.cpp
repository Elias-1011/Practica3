#include <iostream>

using namespace std;


struct Entry {
    int prefix;
    char c;
};

int findEntry(Entry* dict, int size, int prefix, char c) {
    for (int i = 1; i < size; i++) {
        if (dict[i].prefix == prefix && dict[i].c == c) {
            return i;
        }
    }
    return -1;
}

int compresion_LZ78(const char* input, Entry* salida) {

    Entry* dict = new Entry[1000];
    int dictSize = 1;

    int currentPrefix = 0;
    int salidaSize = 0;

    for (int i = 0; input[i] != '\0'; i++) {

        char c = input[i];

        // 🔥 IGNORAR SALTOS DE LINEA
        if (c == '\n' || c == '\r') continue;

        int index = findEntry(dict, dictSize, currentPrefix, c);

        if (index != -1) {
            currentPrefix = index;
        } else {

            salida[salidaSize].prefix = currentPrefix;
            salida[salidaSize].c = c;
            salidaSize++;

            dict[dictSize].prefix = currentPrefix;
            dict[dictSize].c = c;
            dictSize++;

            currentPrefix = 0;
        }
    }

    // último símbolo
    if (currentPrefix != 0) {
        salida[salidaSize].prefix = currentPrefix;
        salida[salidaSize].c = '\0';
        salidaSize++;
    }

    delete[] dict;

    return salidaSize;
}

void imprimirCadena(Entry* dict, int index) {
    if (index == 0) return;

    imprimirCadena(dict, dict[index].prefix);

    if (dict[index].c != '\0') {
        cout << dict[index].c;
    }
}

void descompresion_LZ78(Entry* input, int n) {

    string dict[1000];
    int dictSize = 1;


    for (int i = 0; i < n; i++) {

        string entry = "";

        if (input[i].prefix != 0) {
            entry += dict[input[i].prefix];
        }

        if (input[i].c != '\0') {
            entry += input[i].c;
        }

        cout << entry;

        dict[dictSize++] = entry;
    }

    cout << endl;
}
