/* 
 * File:   main.cpp
 * Author: alan.calderon
 *
 * Created on 1 de septiembre de 2016, 06:48 PM
 */

#include <iostream>
#include <memory>
#include <iostream>
#include <fstream>
using namespace std;

#include "Grafo.h"
#include "Simulador.h"
#include "Visualizador.h"
/*
 * 
 */


int main(int argc, char** argv) {
    Grafo grf(20, 0,0.5);
    Simulador sml(&grf);
    Visualizador vsl(grf,sml);
    
    LstAdy a;
    a.agr(3); 
    a.agr(2); 
    a.agr(1); 
    cout << "A: " << a.aHil() << endl;
    
    a.bus(14);
    a.elm(2);
    cout << "A: " << a.aHil() << endl;
   // a.totAdy();
    //a.obtAdy();
    return 0;
}
 /*
int main(int argc, char** argv) {
    int pe;
    
    ifstream archivoEnterosEntrada("redmuypeq.txt", ios::in);
    //bool pru = archivoEnterosEntrada.eof();
    char finLinea = ' ';

    if (!archivoEnterosEntrada) { // operador ! sobrecargado
        cerr << "No se pudo abrir el archivo de entrada" << endl;
        return 1;
    }

    archivoEnterosEntrada >> pe;
    archivoEnterosEntrada.get(); // consume un blanco
    finLinea = archivoEnterosEntrada.peek(); // intenta leer fin de línea
    while (!archivoEnterosEntrada.eof()) {
        while (!archivoEnterosEntrada.eof()&&(finLinea != 10)) { // 10 ascii de fin de línea
            cout << pe << ' ';
            archivoEnterosEntrada >> pe;
            archivoEnterosEntrada.get(); // consume un blanco
            finLinea = archivoEnterosEntrada.peek(); // intenta leer fin de línea
        }
        if (!archivoEnterosEntrada.eof())
            cout << pe << endl;
        archivoEnterosEntrada >> pe;
        finLinea = archivoEnterosEntrada.peek();
    }
    return 0;
}*/
