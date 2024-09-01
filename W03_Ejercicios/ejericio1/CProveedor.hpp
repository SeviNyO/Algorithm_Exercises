#pragma once 
#include <iostream> 
#include <iomanip> 
using namespace std; 
 
class Proveedor { 
private: 
    int Ruc, telefono; 
    string nombre, Razon_social, categoria, direccion; 
public: 
    Proveedor(); 
    Proveedor(int, int, string, string, string, string); 
    ~Proveedor(); 
    void setRuc(int); 
    void setTelefono(int); 
    void setNombre(string); 
    void setRazonSocial(string); 
    void setCategoria(string); 
    void setDireccion(string); 
    string getNombre(); 
    void mostrar(); 
}; 
Proveedor::Proveedor() { 
    this->nombre = " "; 
    this->Ruc = 0; 
    this->telefono = 0; 
    this->Razon_social = " "; 
    this->categoria = " "; 
    this->direccion = " "; 
} 
Proveedor::Proveedor(int iruc, int icel, string inombre, string irazon, string icategoria, string idireccion) { 
    this->nombre = inombre; 
    this->Ruc = iruc; 
    this->telefono = icel; 
    this->Razon_social = irazon; 
    this->categoria = icategoria; 
    this->direccion = idireccion; 
} 
Proveedor::~Proveedor() {} 
 
void Proveedor::setRuc(int inombre) { 
    this->Ruc = inombre; 
} 
 
void Proveedor::setTelefono(int inombre) { 
    this->telefono = inombre; 
} 
 
void Proveedor::setNombre(string inombre) { 
    this->nombre = inombre; 
} 
 
void Proveedor::setRazonSocial(string inombre) { 
    this->Razon_social = inombre; 
} 
 
void Proveedor::setCategoria(string inombre) { 
    this->categoria = inombre; 
} 
 
void Proveedor::setDireccion(string inombre) { 
    this->direccion = inombre; 
} 
string Proveedor::getNombre() { return this->nombre; } 
 
void Proveedor::mostrar() { 
    cout << setw(4) << "\nNombre: " << this->nombre; 
    cout << setw(4) << "\nRuc: " << this->Ruc; 
    cout << setw(4) << "\nTelefono: " << this->telefono; 
    cout << setw(4) << "\nRazon Social: " << this->Razon_social; 
    cout << setw(4) << "\nCategoria: " << this->categoria; 
    cout << setw(4) << "\nDireccion: " << this->direccion; 
}
