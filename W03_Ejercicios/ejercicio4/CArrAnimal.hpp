#pragma once
#include <iostream>
#include "CAnimal.hpp"
using namespace std;

class CArrAnimal{
private:
    CAnimal **ArrAnimal;
    int nanimales;
public:
    CArrAnimal();
    ~CArrAnimal();
    int getTam();
    void agregarAnimal(CAnimal *);
    void eliminarIndex(int);
    void mostrar();
};

CArrAnimal::CArrAnimal(){
    this->ArrAnimal = nullptr;
    this->nanimales = 0;
}
CArrAnimal::~CArrAnimal(){
    for (int i = 0; i < this->nanimales; ++i){
        delete this->ArrAnimal[i];
    }
    delete[] this->ArrAnimal;
}
int CArrAnimal::getTam() { return this->nanimales; }
void CArrAnimal::agregarAnimal(CAnimal *nuevoAnimal){
    CAnimal **aux = new CAnimal*[nanimales + 1];
    for (int i = 0; i < this->nanimales; ++i){
        aux[i] = this->ArrAnimal[i];
    }
    aux[this->nanimales] = nuevoAnimal;
    delete[] this->ArrAnimal;
    this->ArrAnimal = aux;
    ++this->nanimales;
}
void CArrAnimal::eliminarIndex(int indice){
    delete this->ArrAnimal[indice];
    --this->nanimales;
    CAnimal **aux = new CAnimal *[this->nanimales];
    for (int i = 0; i < this->nanimales; ++i){
        if(i < indice)
            aux[i] = this->ArrAnimal[i];
        else
            aux[i] = this->ArrAnimal[i + 1];
    }
    delete[] this->ArrAnimal;
    this->ArrAnimal = aux;
}
void CArrAnimal::mostrar(){
    for (int i = 0; i < this->nanimales; ++i){
        this->ArrAnimal[i]->mostrar();
    }
}