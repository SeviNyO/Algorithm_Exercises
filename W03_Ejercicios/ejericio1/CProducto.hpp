
#include <iostream>
#include "CProveedor.hpp"
#include <iomanip>
using namespace std;

class Producto{
private:
    int IdProducto, cantidad, anio;
    string Nombre, tipo;
    char categoria;
    double precio;
    Proveedor* proveedor;
    
public:
    Producto();
    ~Producto();
    void setId(int);
    void setCantidad(int);
    void setAnio(int);
    void setTipo(string);
    void setNombre(string);
    void setCategoria(char);
    void setPrecio(double);
    void setProveedor(Proveedor*);

    int getId();
    int getCantidad();
    int getAnio();
    string getTipo();
    string getNombre();
    char getCategoria();
    double getPrecio();
    Proveedor* getProveedor();
    void mostrar();
};
Producto::Producto(){
    this->IdProducto = 0;
    this->cantidad = 0;
    this->anio = 0;
    this->tipo = " ";
    this->Nombre = " ";
    this->categoria = ' ';
    this->precio = 0;
    this->proveedor = nullptr;
}
Producto::~Producto() {};
void Producto::setId(int iid)
{
    this->IdProducto = iid;
}
void Producto::setCantidad(int icantidad){
    this->cantidad = icantidad;
}
void Producto::setAnio(int ianio){
    this->anio = ianio;
}
void Producto::setTipo(string itipo){
    this->tipo = itipo;
}
void Producto::setNombre(string inombre){
    this->Nombre = inombre;
}
void Producto::setCategoria(char icategoria){
    this->categoria = icategoria;
}
void Producto::setPrecio(double iprecio){
    this->precio = iprecio;
}
void Producto::setProveedor(Proveedor* iproveedor){
    this->proveedor = iproveedor;
}

int Producto::getId(){return this->IdProducto;}
int Producto::getCantidad(){return this->cantidad;}
int Producto::getAnio(){return this->anio;}
string Producto::getTipo(){return this->tipo;}
string Producto::getNombre(){return this->Nombre;}
char Producto::getCategoria(){return this->categoria;}
double Producto::getPrecio(){return this->precio;}
Proveedor* Producto::getProveedor(){return this->proveedor;}

void Producto::mostrar(){
    cout << "\nId producto: " << this->IdProducto;
    cout << "\nCantidad: " << this->cantidad;
    cout << "\nAnio vencimiento: " << this->anio;
    cout << "\nTipo: " << this->tipo;
    cout << "\nNombre: " << this-> Nombre;
    cout << "\nCategoria: " << this->categoria;
    cout << "\nPrecio: " << this->precio;
    proveedor->mostrar();
}

