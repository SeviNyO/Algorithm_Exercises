#pragma once
#include <iostream>
#include "CCliente.hpp"
#include "CArregloProducto.hpp"
using namespace std;

class Compra{
private:
    int IdCompra, Fecha;
    Cliente *cliente;
    ArregloProducto *productos;

public:
    Compra();
    ~Compra();
    int getId();
    void mostrar();
};

Compra::Compra(){}
Compra::~Compra(){}

int Compra::getId(){
    return this->IdCompra;
}
void Compra::mostrar(){
    cout << "\nId Compra: " << this->IdCompra << " - Fecha: " << this->Fecha;
    cout << "\n----> Productos comprados: ";
    this->productos->mostrar();
    cout << "\n-----------------------------";
}