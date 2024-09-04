#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

class CAnimal{
private:
    string nombre;
    char tipo;
    int edad;
public:
    CAnimal();
    ~CAnimal();
    void setNombre(string);
    void setTipo(char);
    void setEdad(int);
    string getNombre();
    char getTipo();
    int getEdad();
    void mostrar();
};

CAnimal::CAnimal(){
    this->nombre = "Prueba";
    this->tipo = rand() % (90 - 65 + 1) + 65;
    this->edad = rand() % 15 + 1;
}
CAnimal::~CAnimal(){}
void CAnimal::setNombre(string inombre){
    this->nombre = inombre;
}
void CAnimal::setTipo(char itipo){
    this->tipo = itipo;
}
void CAnimal::setEdad(int iedad){
    this->edad = iedad;
}
string CAnimal::getNombre() { return this->nombre; }
char CAnimal::getTipo() { return this->tipo; }
int CAnimal::getEdad() { return this->edad; }

void CAnimal::mostrar(){
    cout << "\nNombre: " << this->nombre;
    cout << "\nTipo: " << this->tipo;
    cout << "\nEdad: " << this->edad;
}