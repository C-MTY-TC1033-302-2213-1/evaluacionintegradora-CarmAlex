#include "Combo.h"

Combo::Combo(){
    clave = 0;
}
Combo::Combo(string _nombre, int _precio, int _peso, int _clave) : Producto(_nombre, _precio, _peso)
{
    clave = _clave;
}

string Combo::str(){
    return nombre + '-' + '$' + to_string(precio) + '-' + to_string(peso) + '-' + '$' + to_string(calculaTotalPagar()) + '-' + to_string(clave);
}
int Combo::calculaTotalPagar(){
    int algo, totalPagar, descuento;

    algo = precio * peso * clave;

    if( clave == 1 ){
        descuento = ( algo / 100 ) * 25;
        totalPagar = algo - descuento;
    } else if ( clave == 2 ) {
        descuento = ( algo / 100 ) * 30;
        totalPagar = algo - descuento;
    } else {
        totalPagar = precio * peso;
    }

    return totalPagar;


}