#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <string>   // 🔥 IMPORTANTE

using namespace std;

string leerArchivo(const string& ruta);
void escribirArchivo(const string& ruta, const string& contenido);
string pedirArchivo();

#endif // ARCHIVOS_H
