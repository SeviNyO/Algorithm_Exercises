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
    int getCan();
    Producto* duplicar(int);
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
int Producto::getCan(){
    return this->cantidad;
}
void Producto::mostrar(){
    cout << "\nCodigo producto: " << this->codProducto << "\nNombre: " << this->nombre << "\nCantidad: " << this->cantidad << "\nTipo: " << this->tipo << "\nMarca: " << this->marca << "\nPrecio: " << this->precio;
}
Producto* Producto::duplicar(int cantidad){
    Producto *duplicado = new Producto();
    duplicado->nombre = this->nombre;
    duplicado->cantidad = cantidad;
    duplicado->marca = this->marca;
    duplicado->precio = this->precio;
    duplicado->codProducto = this->codProducto;
    duplicado->tipo = this->tipo;
    return duplicado;
}