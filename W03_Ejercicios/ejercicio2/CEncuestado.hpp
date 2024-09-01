#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

class Encuestado{
private:
    int DNI;
    int preferencia;
public:
    Encuestado();
    ~Encuestado();
    int getDNI();
    int getPreferencia();
    void generarDATOS();
    void mostrar();
};

Encuestado::Encuestado(){
    generarDATOS();
}
Encuestado::~Encuestado(){};
int Encuestado::getDNI(){
    return this->DNI;
}
int Encuestado::getPreferencia(){
    return this->preferencia;
}
void Encuestado::generarDATOS(){
    this->DNI = rand() % (9999 - 1000 + 1) + 1000;
    this->preferencia = rand() % 4 + 1;
}
void Encuestado::mostrar(){
    cout << "\nDNI: " << this->DNI << " -- Preferencia: " << this->preferencia;
}