#include <iostream>
#include <cctype>
#include <string>

using namespace std;


string compresion_rle(const string& input) {
    if (input.empty()) return "";
    string result = "";
    const char* ptr = input.c_str();
    while (*ptr != '\0') {
        char actual = *ptr;
        int count = 1;
        while (*(ptr + 1) != '\0' && *(ptr + 1) == actual) {
            count++;
            ptr++;
        }
        result += to_string(count);
        result += actual;
        ptr++;
    }
    return result;
}


string descompresion_rle(const string& input) {
    if (input.empty()) return "";
    string result = "";
    const char* ptr = input.c_str();
    while (*ptr != '\0') {
        int numero = 0;
        bool hayDigito = false;
        while (*ptr != '\0' && isdigit((unsigned char)*ptr)) {
            numero = numero * 10 + (*ptr - '0');
            ptr++;
            hayDigito = true;
        }
        if (!hayDigito)
            throw runtime_error("RLE: formato invalido, caracter sin conteo");
        if (*ptr == '\0')
            throw runtime_error("RLE: formato invalido, numero sin caracter");
        char letra = *ptr;
        ptr++;
        result.append(numero, letra);
    }
    return result;
}
