#pragma once
#include <iostream>
#include "CPersonal.hpp"
using namespace std;

class CArrPersonal{
private:
    CPersonal **ArrPersonal;
    int npersonal;
public:
    CArrPersonal();
    ~CArrPersonal();
    int getTam();
    void agregarPersonal(CPersonal *);
    void eliminarIndex(int);
    void mostrar();
};

CArrPersonal::CArrPersonal(){
    this->ArrPersonal = nullptr;
    this->npersonal = 0;
}
CArrPersonal::~CArrPersonal(){
    for (int i = 0; i < this->npersonal; ++i){
        delete this->ArrPersonal[i];
    }
    delete[] this->ArrPersonal;
}
int CArrPersonal::getTam() { return this->npersonal; }
void CArrPersonal::agregarPersonal(CPersonal *nuevoPersonal){
    CPersonal **aux = new CPersonal*[npersonal + 1];
    for (int i = 0; i < this->npersonal; ++i){
        aux[i] = this->ArrPersonal[i];
    }
    aux[this->npersonal] = nuevoPersonal;
    delete[] this->ArrPersonal;
    this->ArrPersonal = aux;
    ++this->npersonal;
}
void CArrPersonal::eliminarIndex(int indice){
    delete this->ArrPersonal[indice];
    --this->npersonal;
    CPersonal **aux = new CPersonal *[this->npersonal];
    for (int i = 0; i < this->npersonal; ++i){
        if(i < indice)
            aux[i] = this->ArrPersonal[i];
        else
            aux[i] = this->ArrPersonal[i + 1];
    }
    delete[] this->ArrPersonal;
    this->ArrPersonal = aux;
}
void CArrPersonal::mostrar(){
    cout << "\n--------- PERSONAL EXISTENTE ----------";
    for (int i = 0; i < this->npersonal; ++i)
    {
        cout << "\nPersonal #" << i;
        this->ArrPersonal[i]->mostrar();
        cout << "\n-------------------";
    }
}