#pragma once
#include <iostream>
#include "CAnimal.hpp"
#include "CPersonal.hpp"
using namespace std;

class CDiagnostico{
private:
    int fecha;
    string descripcion;
    CAnimal *animal;
    CPersonal *personal;

public:
    CDiagnostico();
    ~CDiagnostico();
    void setFecha(int);
    void setDescripcion(string);
    void setAnimal(CAnimal*);
    void setPersonal(CPersonal*);
    CAnimal *getAnimal();
    CPersonal *getPersonal();
    int getFecha();
    string getDescripcion();
    void mostrar();
};

CDiagnostico::CDiagnostico(){
    this->fecha = 20240909;
    this->descripcion = "";
    this->animal = new CAnimal;
    this->personal = new CPersonal;
}
CDiagnostico::~CDiagnostico(){
    delete animal;
    delete personal;
}
void CDiagnostico::setFecha(int ifecha){
    this->fecha = ifecha;
}
void CDiagnostico::setDescripcion(string ides){
    this->descripcion = ides;
}
void CDiagnostico::CDiagnostico::setAnimal(CAnimal* animal){
    this->animal = animal;
}
void CDiagnostico::setPersonal(CPersonal* personal){
    this->personal = personal;
}
int CDiagnostico::getFecha() { return this->fecha; }
string CDiagnostico::getDescripcion() { return this->descripcion; }
CAnimal *CDiagnostico::getAnimal() { return this->animal; }
CPersonal *CDiagnostico::getPersonal() { return this->personal; }

void CDiagnostico::mostrar(){
    cout << "\n-------- DIAGNOSTICO ----------";
    cout << "\nFecha: " << this->fecha << "\nDescripcion: " << this->descripcion;
    cout << "\n----> Animal";
    animal->mostrar();
    cout << "\nP----> Personal: ";
    personal->mostrar();
}