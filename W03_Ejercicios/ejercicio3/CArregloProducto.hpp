#pragma once
#include <iostream>
#include "CProducto.hpp"
using namespace std;

class ArregloProducto{
private:
    Producto** productos;
    int nproductos;
public:
    ArregloProducto();
    ~ArregloProducto();
    void mostrar();
    int getTamanio();
    void agregarProducto(Producto *);
    void eliminarProducto(int);
};

ArregloProducto::ArregloProducto(){
    this->productos = nullptr;
    this->nproductos = 0;
}
ArregloProducto::~ArregloProducto(){
    for (int i = 0; i < this->nproductos; ++i){
        delete this->productos[i];
    }
    delete[] this->productos;
}
int ArregloProducto::getTamanio(){
    return this->nproductos;
}
void ArregloProducto::mostrar(){
    cout << "------------ LISTA PRODUCTOS -----------";
    for (int i = 0; i < this->nproductos; ++i){
        this->productos[i]->mostrar();
        cout << "\n==============";
    }
    cout << "\n---------------------------------------";
}
void ArregloProducto::agregarProducto(Producto* nuevoProducto){
    Producto **temp = new Producto*[this->nproductos + 1];
    for (int i = 0; i < this->nproductos; ++i){
        temp[i] = this->productos[i];
    }
    temp[this->nproductos] = nuevoProducto;
    delete[] this->productos;
    this->productos = temp;
    ++this->nproductos;
}
void ArregloProducto::eliminarProducto(int cod){
    bool existe;
    int indice;
    for (int i = 0; i < this->nproductos; ++i)
    {
        if(this->productos[i]->getCod() == cod){
            existe = true;
            indice = i;
            break;
        }
    }
    if(existe){
        --this->nproductos;
        Producto **temp = new Producto*[this->nproductos];
        delete this->productos[indice];
        for (int i = 0; i < this->nproductos; ++i){
            if(i < indice){
                temp[i] = this->productos[i];
            } else{
                temp[i] = this->productos[i + 1];
            }
        }
        delete[] this->productos;
        this->productos = temp;
    } else{
        cout << "\nNo existe un producto con la ID introducida";
    }
}