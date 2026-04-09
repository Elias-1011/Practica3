// 🔹 Escribir string a archivo
#include <iostream>
#include <fstream>
using namespace std;

// 🔹 Escritura
void escritura(){
    char str[256];

    cout << "Ingrese caracteres: ";
    cin.getline(str, 256);

    ofstream fout("archivoprueba.txt", ios::app);
    fout << str << endl;
    fout.close();
}
