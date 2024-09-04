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
    void agregarProducto(Producto*);
    void eliminarProducto(int id, int cantidad);
    Producto *accederPorId(int);
    void mostrar();
};

Compra::Compra(){}
Compra::~Compra(){}

int Compra::getId(){
    return this->IdCompra;
}
void Compra::agregarProducto(Producto* produc){
    productos->agregarProducto(produc);
}
void Compra::eliminarProducto(int id, int cantidad){
    productos->eliminarProducto(id);
    productos->obtenerProductoCodigo(id)->setCantidad(cantidad);
}
Producto* Compra::accederPorId(int id){
    
}
void Compra::mostrar(){
    cout << "\nId Compra: " << this->IdCompra << " - Fecha: " << this->Fecha;
    cout << "\n----> Productos comprados: ";
    this->productos->mostrar();
    cout << "\n-----------------------------";
}