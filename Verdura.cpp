#include "Verdura.h"

Verdura::Verdura(){
    temporada = "Invierno";
}
Verdura::Verdura(string _nombre, int _precio, int _peso, string _temporada) : Producto(_nombre, _precio, _peso)
{
    temporada = _temporada;
}

string Verdura::str(){
    return nombre + '-' + '$' + to_string(precio) + '-' + to_string(peso) + '-' + '$' + to_string(calculaTotalPagar()) + '-' + temporada; 
}
int Verdura::calculaTotalPagar(){
    int total;

    if (temporada == "Junio"){
        total = precio * peso * 2;

    } else if (temporada == "Regalado") {
        total = precio * peso * 3; 

    } else {
        total = precio * peso * 10;

    }


    return total;
}