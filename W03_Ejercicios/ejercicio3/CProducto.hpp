#pragma once
#include <iostream>
using namespace std;

class Producto{
private:
    int codProducto, cantidad;
    string nombre, tipo, marca;
    double precio;
public:
    Producto();
    ~Producto();
    void setCod(int);
    void setCantidad(int);
    void setNombre(string);
    void setTipo(string);
    void setMarca(string);
    void setPrecio(double);
    int getCod();
    void mostrar();
};

Producto::Producto(){

}
Producto::~Producto() {};
void Producto::setCod(int icod){
    this->codProducto = icod;
}
void Producto::setCantidad(int ican){
    this->cantidad = ican;
}
void Producto::setNombre(string inom){
    this->nombre = inom;
}
void Producto::setTipo(string itipo){
    this->tipo = itipo;
}
void Producto::setMarca(string ima){
    this->marca = ima;
}
void Producto::setPrecio(double ipre){
    this->precio = ipre;
}
int Producto::getCod(){
    return this->codProducto;
}
void Producto::mostrar(){
    cout << "\nCodigo producto: " << this->codProducto << "\nNombre: " << this->nombre << "\nCantidad: " << this->cantidad << "\nTipo: " << this->tipo << "\nMarca: " << this->marca << "\nPrecio: " << this->precio;
}