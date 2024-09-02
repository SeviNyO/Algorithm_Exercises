#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

class Cliente{
private:
    int dni;
    string nombre;
public:
    Cliente();
    ~Cliente();
    string getNombre();
    int getDNI();
    void mostrar();
};

Cliente::Cliente(){
    this->dni = rand() % (99999999 - 1000000 + 1) + 10000000;
    this->nombre = "Prueba";
}
Cliente::~Cliente(){}
string Cliente::getNombre(){
    return this->nombre;
}
int Cliente::getDNI(){
    return this->dni;
}
void Cliente::mostrar(){
    cout << "\nDNI: " << this->dni << " - Nombre: " << this->nombre;
}