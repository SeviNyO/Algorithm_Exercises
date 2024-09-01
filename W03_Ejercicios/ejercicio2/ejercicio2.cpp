#include <iostream>
#include <stdlib.h>
#include "CListaEncuestado.hpp"
using namespace std;

int main(){
    srand(time(nullptr));
    int opcion;
    int dni;
    ListaEncuestado *lista = new ListaEncuestado();
    do{
        cout << "\n--------- LECHERA SAC ---------" << "\n[1] Generar" << "\n[2] Eliminar" << "\n[3] Mostrar" << "\n[4] Salir" << "\n------>";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "\nGenerando encuestado..." << "\nEncuestado generado exitosamente!\n";
            lista->generarEncuestado(new Encuestado());
            break;
        case 2:
            cout << "\nIngrese el DNI de encuestado a eliminar: ";
            cin >> dni;
            lista->eliminarEncuestado(dni);
            break;
        case 3:
            lista->mostrarEncuestados();
            break;
        case 4:
            cout << "\nSaliendo del programa...";
        default:
            break;
        }
    } while (opcion != 4);
    delete lista;
    
    return 0;
}