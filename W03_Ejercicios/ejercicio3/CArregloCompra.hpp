#pragma once
#include <iostream>
#include "CCompra.hpp"
using namespace std;

class ArregloCompra{
private:
    Compra **compras;
    int ncompras;
public:
    ArregloCompra();
    ~ArregloCompra();
    void agregarCompra(Compra*);
    void eliminarCompra(int);
    void mostrar();
};
ArregloCompra::ArregloCompra(){
    this->compras = nullptr;
    this->ncompras = 0;
}
ArregloCompra::~ArregloCompra(){
    for (int i = 0; i < this->ncompras; ++i){
        delete this->compras[i];
    }
    delete[] this->compras;
}
void ArregloCompra::agregarCompra(Compra* nuevaCompra){
    Compra **temp = new Compra*[this->ncompras + 1];
    for (int i = 0; i < this->ncompras; ++i){
        temp[i] = this->compras[i];
    }
    temp[this->ncompras] = nuevaCompra;
    delete[] this->compras;
    this->compras = temp;
    ++this->ncompras;
}
void ArregloCompra::eliminarCompra(int cod){
    bool existe;
    int indice;
    for (int i = 0; i < this->ncompras; ++i)
    {
        if(this->compras[i]->getId() == cod){
            existe = true;
            indice = i;
            break;
        }
    }
    if(existe){
        --this->ncompras;
        Compra **temp = new Compra*[this->ncompras];
        delete this->compras[indice];
        for (int i = 0; i < this->ncompras; ++i){
            if(i < indice){
                temp[i] = this->compras[i];
            } else{
                temp[i] = this->compras[i + 1];
            }
        }
        delete[] this->compras;
        this->compras = temp;
    } else{
        cout << "\nNo existe una compra hecha con la ID introducida";
    }
}
void ArregloCompra::mostrar(){
    cout << "\n=========================== COMPRAS REALIZADAS ===========================";
    for (int i = 0; i < this->ncompras; ++i)
    {
        this->compras[i]->mostrar();
    }
    cout << "\n===========================================================================";
}