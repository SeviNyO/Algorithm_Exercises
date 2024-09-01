#include <iostream>
#include "CControladora.hpp"
using namespace std;
//Me tarde 4 horas, tengo que mejorar mi velocidad
int main() {
    int opcion;
    Controladora* lista = new Controladora();
    do {
        
        cout << "\n--------- FlowerFull S.A.C, ---------";
        cout << "\n[1]Insertar producto" << "\n[2]Insertar proveedor" << "\n[3]Modificar producto" << "\n[4]Elimiar productos vencidos" << "\n[5]Reporte stock" << "\n[6]Eliminar productos de prov. Herbalife" << "\n[7]Reporte prov. Natura" << "\n[8]Salir";
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
            cout << "\nId de objeto a modificar: " << "\n----->";
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
            lista->eliminarHerbalife();
            cout << "\nEliminación exitosa";
            break;
        case 7:
            lista->reporteNatura();
            break;
        case 8:
            cout << "\nSaliendo del programa...";
            break;
        default:
            cout << "\nIngresa una opcion valida";
            break;
        }
    } while (opcion != 8);
    delete lista;
}