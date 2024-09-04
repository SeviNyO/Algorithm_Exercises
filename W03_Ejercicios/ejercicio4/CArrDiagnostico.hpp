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
    void mostrar_nAnios_afterContrato(int);
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
    for (int i = 0; i < this->ndiagnostico; ++i){
        if(this->ArrDiagnostico[i]->getAnimal()->getEdad() < 5)
            this->ArrDiagnostico[i]->mostrar();
    }
}
void CArrDiagnostico::mostrar_nAnios_afterContrato(int anios){
     for (int i = 0; i < this->ndiagnostico; ++i){
        if(this->ArrDiagnostico[i]->getPersonal()->getFechaContrato() >= anios)
            this->ArrDiagnostico[i]->mostrar();
    }
}
