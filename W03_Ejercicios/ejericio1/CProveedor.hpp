#pragma
#include <iostream>
#include <iomanip>
using namespace std;

class Proveedor{
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
Proveedor::Proveedor(){
    this->nombre = " ";
    this->Ruc = 0;
    this->telefono = 0;
    this->Razon_social = " ";
    this->categoria = " ";
    this->direccion = " ";
}
Proveedor::Proveedor(int iruc, int icel, string inombre, string irazon, string icategoria, string idireccion){
    this->nombre = inombre;
    this->Ruc = iruc;
    this->telefono = icel;
    this->Razon_social = irazon;
    this->categoria = icategoria;
    this->direccion = idireccion;
}
Proveedor::~Proveedor(){}

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
string Proveedor::getNombre(){return this->nombre;}

void Proveedor::mostrar(){
    cout << "\nRuc" << setw(4) << "Telefono" << setw(4) << "Razon social" << setw(4) << "Categoria" << setw(4) << "Direccion";
    cout << this->Ruc << setw(4) << this->telefono << setw(4) << this->Razon_social << setw(4) << this->categoria << setw(4) << this->direccion;
}