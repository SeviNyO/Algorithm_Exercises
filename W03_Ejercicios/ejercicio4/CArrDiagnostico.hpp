#pragma once
#include <iostream>
#include "CDiagnostico.hpp"
using namespace std;

class CArrDiagnostico{
private:
    CDiagnostico **ArrDiagnostico;
    int ndiagnostico;
public:
    CArrDiagnostico();
    ~CArrDiagnostico();
    int getTam();
    void agregarDiagnostico(CDiagnostico *);
    void eliminarIndex(int);
    void mostrar();
    void mostrar_nAnios_animal();
    void mostrar_nAnios_afterContrato();
};

CArrDiagnostico::CArrDiagnostico(){
    this->ArrDiagnostico = nullptr;
    this->ndiagnostico = 0;
}
CArrDiagnostico::~CArrDiagnostico(){
    for (int i = 0; i < this->ndiagnostico; ++i){
        delete this->ArrDiagnostico[i];
    }
    delete[] this->ArrDiagnostico;
}
int CArrDiagnostico::getTam() { return this->ndiagnostico; }
void CArrDiagnostico::agregarDiagnostico(CDiagnostico *nuevoDiagnostico){
    CDiagnostico **aux = new CDiagnostico*[ndiagnostico + 1];
    for (int i = 0; i < this->ndiagnostico; ++i){
        aux[i] = this->ArrDiagnostico[i];
    }
    aux[this->ndiagnostico] = nuevoDiagnostico;
    delete[] this->ArrDiagnostico;
    this->ArrDiagnostico = aux;
    ++this->ndiagnostico;
}
void CArrDiagnostico::eliminarIndex(int indice){
    delete this->ArrDiagnostico[indice];
    --this->ndiagnostico;
    CDiagnostico **aux = new CDiagnostico *[this->ndiagnostico];
    for (int i = 0; i < this->ndiagnostico; ++i){
        if(i < indice)
            aux[i] = this->ArrDiagnostico[i];
        else
            aux[i] = this->ArrDiagnostico[i + 1];
    }
    delete[] this->ArrDiagnostico;
    this->ArrDiagnostico = aux;
}
void CArrDiagnostico::mostrar(){
    for (int i = 0; i < this->ndiagnostico; ++i){
        this->ArrDiagnostico[i]->mostrar();
    }
}

void CArrDiagnostico::mostrar_nAnios_animal(){
    cout << "\n==ANIMALES CON MENOS DE 5 ANIOS";
    int contador = 0;
    for (int i = 0; i < this->ndiagnostico; ++i)
    {
        if(this->ArrDiagnostico[i]->getAnimal()->getEdad() < 5){
            this->ArrDiagnostico[i]->mostrar();
            ++contador;
        }
    }
    if(contador == 0){
        cout << "\n--->No se encontro ningun animal con esa caracteristica";
    }
}
void CArrDiagnostico::mostrar_nAnios_afterContrato(){
    int contador = 0;
    int anios;
    cout << "\n==PERSONAL CON UNA FECHA DE CONTRATO DESPUES DE :";
    cin >> anios;
    if(anios < 1990){
        cout << "\nFecha muy antigua, debe ser superior a 1990";
        return;
    }
    for (int i = 0; i < this->ndiagnostico; ++i)
    {
        if(this->ArrDiagnostico[i]->getPersonal()->getAnio()>= anios){
            this->ArrDiagnostico[i]->mostrar();
            ++contador;
        }
    }
    if(contador == 0){
        cout << "\n--->NO se encontro ningun personal con esa caracteristica";
    }
}
