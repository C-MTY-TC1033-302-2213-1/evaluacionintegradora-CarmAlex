#include "Pedido.h"

Pedido::Pedido(){
    for (int index = 0; index < MAX_PROD; index++){
        arrPtrProductos[index] = nullptr;
    }

    cantidad = 0;

}

void Pedido::leerArchivo(string nombre){
    fstream archivo;
    string row[5];
    string line, word;
    archivo.open(nombre, ios::in);
    cantidad = 0;
    // lee una línea del archivo y la almacena en line
    while ( getline(archivo, line)) {
        stringstream s(line);
        int iR = 0;
        // extrae caracteres de s y los almacena en word hasta que encuentra el delimitador ','
        while (getline(s, word, ',')) {
            row[iR++] = word;
        }
        if (row[0] == "V"){ // Verdura
            arrPtrProductos[cantidad] = new Verdura( "", 0, 0, row[1]);
            arrPtrProductos[cantidad]->setNombre(row[2]);
            arrPtrProductos[cantidad]->setPrecio( stoi(row[3]));
            arrPtrProductos[cantidad]->setPeso(stoi(row[4]));
        } else if (row[0] == "C"){ // Combo
            arrPtrProductos[cantidad] = new Combo( row[1], stoi(row[2]),
            stoi(row[3]), stoi(row[4]));
        }
        else if (row[0] == "P"){ // Producto
            arrPtrProductos[cantidad] = new Producto( row[1], stoi(row[2]),
            stoi(row[3]));
        }
        // incrementar el contador de apuntadores de arrPtrProductos
        cantidad = cantidad + 1;
    }

archivo.close();
}


void Pedido::ticketCliente(){
    int cont = 0;
    int totalPagar = 0;

    for (int index = 0; index < cantidad; index++){
        cout << arrPtrProductos[index] -> str() << endl; 
        cont += 1;
        totalPagar += arrPtrProductos[index] -> calculaTotalPagar();
    }

    cout << cont << " articulos" << endl;
    cout << "Total a pagar $" << totalPagar << endl;
}