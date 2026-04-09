#ifndef LZ78_H
#define LZ78_H

struct Entry {
    int prefix;
    char c;
};

string compresion_rle(const string&);
string descompresion_rle(const string&);
int compresion_LZ78(const char*, Entry*);
void descompresion_LZ78(Entry*, int);

#endif // LZ78_H
