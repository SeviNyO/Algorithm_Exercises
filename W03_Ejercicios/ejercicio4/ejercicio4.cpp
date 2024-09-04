#include <iostream>
#include <stdlib.h>
#include "CArrDiagnostico.hpp"
#include "CArrPersonal.hpp"
#include "CArrAnimal.hpp"
using namespace std;

int main(){
    srand(time(nullptr));
    int opcion;
    CArrAnimal *listaAnimal = new CArrAnimal();
    CArrPersonal *listaPersonal = new CArrPersonal();
    CArrDiagnostico *listaDiagnostico = new CArrDiagnostico();
    do
    {
        cout << "\n------------- MENU-------------" << "\n[1] Insertar personal\n[2] Insertar animal\n[3] Realizar diagnostico\n[4] Reportes\n[5] Personal existente\n[6] Animales existentes\n[7] Salir";
        cout << "\n-Eleccion--->";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            listaPersonal->agregarPersonal(new CPersonal());
            break;
        case 2:
            listaAnimal->agregarAnimal(new CAnimal());
            break;
        case 3:
            listaDiagnostico->agregarDiagnostico(new CDiagnostico());
            break;
        case 4:
            int x;
            cout << "\nReporte de Personal que realizaron un diagnostico despues de x fecha:";
            cout << "\nIngrese n: ";
            cin >> x;
            listaDiagnostico->mostrar_nAnios_afterContrato(x);
            cout << "\nReporte de animales con menos de 5 anios";
            listaDiagnostico->mostrar_nAnios_animal();
            break;
        case 5:
            listaPersonal->mostrar();
            break;
        case 6:
            listaAnimal->mostrar();
            break;
        case 7:
            cout << "\nSaliendo del programa...";
            break;
        default:
            cout << "\nIngrese una opcion valida";
            break;
        }
    } while (opcion != 7);
    delete listaAnimal;
    delete listaDiagnostico;
    delete listaPersonal;
    return 707;
}