#include <iostream>
#include <cctype>
#include <string>

using namespace std;


string compresion_rle(const string& input) {
    string result = "";

    const char* ptr = input.c_str();

    while (*ptr != '\0') {

        char actual = *ptr;
        int count = 1;

        while (*(ptr + 1) != '\0' && *(ptr + 1) == actual) {
            count++;
            ptr++;
        }

        result += actual;
        result += to_string(count);

        ptr++;
    }

    return result;
}

string descompresion_rle(const string& input) {
    string result = "";

    const char* ptr = input.c_str();

    while (*ptr != '\0') {

        char letra = *ptr;
        ptr++;

        int numero = 0;

        while (*ptr != '\0' && isdigit(*ptr)) {
            numero = numero * 10 + (*ptr - '0');
            ptr++;
        }

        result.append(numero, letra);
    }

    return result;
}
