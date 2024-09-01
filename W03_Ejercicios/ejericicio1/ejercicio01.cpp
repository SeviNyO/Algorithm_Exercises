#include <iostream>
#include "CListaTienda.hpp"
using namespace std;
//Me tarde 4 horas, tengo que mejorar mi velocidad
int main() {
    int opcion;
    ListaProductos* lista = new ListaProductos();
    do {
        
        cout << "\n--------- FlowerFull S.A.C, ---------";
        cout << "\n[1]Insertar producto" << "\n[2]Insertar proveedor" << "\n[3]Modificar producto" << "\n[4]Elimiar productos vencidos" << "\n[5]Reporte stock" << "\n[6]Salir";
        cout << "\n-----> ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            lista->insertarProducto(new Producto());
            break;
        case 2:
            lista->insertarProveedor(new Proveedor());
            break;
        case 3:
            int i;
            cout << "\nId de objeto a modificar: ";
            cin >> i;
            lista->modificar(i);
            break;
        case 4:
            lista->eliminarVencidos();
            break;
        case 5:
            lista->reporteStock();
            break;
        case 6:
            cout << "\nSaliendo del programa...";
            break;
        default:
            cout << "\nIngresa una opcion valida";
            break;
        }
    } while (opcion != 6);
    delete lista;
}