#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

class CPersonal{
private:
    string nombre, apellido;
    int fechaContrato;
public:
    CPersonal();
    ~CPersonal();
    void setNombre(string);
    void setApellido(string);
    void setFechaContrato(int);
    string getNombre();
    string getApellido();
    int getAnio();
    int getFechaContrato();
    void mostrar();
    int fechaRandom();
};

CPersonal::CPersonal(){
    this->nombre = "Prueba";
    this->apellido = "Prueba";
    this->fechaContrato = fechaRandom();
}
CPersonal::~CPersonal(){}
void CPersonal::setNombre(string inombre){
    this->nombre = inombre;
}
void CPersonal::setApellido(string iapellido){
    this->apellido = iapellido;
}
void CPersonal::setFechaContrato(int ifc){
    this->fechaContrato = ifc;
}
string CPersonal::getNombre() { return this->nombre; }
string CPersonal::getApellido() { return this->apellido; }
int CPersonal::getFechaContrato() { return this->fechaContrato; }

void CPersonal::mostrar(){
    cout << "\nNombre: " << this->nombre << "\nApellido: " << this->apellido << "\nFecha Contrato: " << this->fechaContrato;
}
int CPersonal::fechaRandom(){
    int anio = rand() % (2024 - 1990 + 1) + 1990;
    int mes = rand() % 12 + 1;
    int dia = rand() % 28 + 1;
    return (anio * 10000) + (mes * 100) + dia;
}

int CPersonal::getAnio(){
    return this->fechaContrato / 10000;
}