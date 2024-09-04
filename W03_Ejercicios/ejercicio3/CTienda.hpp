#pragma once
#include <iostream>
#include "CArregloCompra.hpp"
#include "CArregloCliente.hpp"

using namespace std;

class Tienda{
private:
    ArregloCompra *compras;
    ArregloCliente *clientes;
    ArregloProducto *stock;
    int dniClienteActual;
public:
    Tienda();
    ~Tienda();
    void comprarProducto(Compra*,int, int);
    bool comprobarStockProducto(int, int);
    void realizarCompra();
    void registrar();
    void logear();
    void dejarProducto(Compra*, int id, int cantidad);
    int getClienteActual();
    void mostrarStock();
    void resumenCompras();
    void mostrarClientes();
};
Tienda::Tienda(){
    this->compras = new ArregloCompra();
    this->clientes = new ArregloCliente();
    this->stock = new ArregloProducto();
}
Tienda::~Tienda(){
    delete compras;
    delete clientes;
    delete stock;
}
bool Tienda::comprobarStockProducto(int codigo, int cantidad){
    Producto *aux = stock->obtenerProductoCodigo(codigo);
    return (aux->getCan() >= cantidad);
}
int Tienda::getClienteActual(){
    return this->dniClienteActual;
}
void Tienda::registrar(){
    cout << "\n--- Estamos registrandote...";
    Cliente *nuevoCliente = new Cliente();
    this->clientes->agregarCliente(nuevoCliente);
    cout << "\n---Registro exitoso! Bienvenido" << nuevoCliente->getNombre() << "con DNI: " << nuevoCliente->getDNI();
}
void Tienda::logear(){
    int dni;
    bool existe;
    cout << "\nIngresa tu DNI de usuario";
    cin >> dni;
    for (int i = 0; i < this->clientes->getTamanio(); ++i)
    {
        if(this->clientes[i].obtenerDNI(dni) == dni){
            this->dniClienteActual = dni;
            cout << "\nLogeado correctamente: ";
        }
        else if (this->clientes[i].obtenerDNI(dni) == -1)
        {
            cout << "\nTu DNI no ha sido registrado, deseas hacerlo? S/N";
            char opcion;
            cin >> opcion;
            if(tolower(opcion) == 'S'){
                this->registrar();
            } else if( tolower(opcion) == 'N'){
                cout << "\nEs necesario registrarse para continuar con la compra!"
                << "\nVolviendo al menu...";
            } else{
                cout << "\nOpcion tecleada no valida!";
            }
        }
    }
}
void Tienda::comprarProducto(Compra* comprita, int codigo, int cantidad)
{
    if(!comprobarStockProducto(codigo, cantidad)){
        cout << "\nSin stock suficiente...";
        return;
    }
    Producto *producto = stock->obtenerProductoCodigo(codigo);
    Producto *productoComprado = producto->duplicar(cantidad);
    comprita->agregarProducto(productoComprado);
    producto->setCantidad(producto->getCan() - cantidad);
}
void Tienda::dejarProducto(Compra* comprita, int codigo, int cantidad){
    Producto *producto = stock->obtenerProductoCodigo(codigo);
    comprita->eliminarProducto(codigo, cantidad);
}
void Tienda::realizarCompra(){
    int codigo, cantidad, eleccion;
    Compra *nuevacompra = new Compra();
    cout << "----> MENU DE COMPRA" << "\n[1] Elegir producto" << "\n[2]Dejar Producto" << "\n[3] Mostrar carrito actual" << "\n[4]Salir..." << "\nUsuario actual: " << this->getClienteActual() << ": ";
    cin >> eleccion;
    switch (eleccion)
    {
    case 1:
        cout << "\nIngrese la ID:";
        cin >> codigo;
        cout << "\nIngrese la cantidad a comprar:";
        cin >> cantidad;
        comprarProducto(nuevacompra, codigo, cantidad);
    case 2:
    case 3:
        nuevacompra->mostrar();
    case 4:
    default:
        cout << "\nOpcion no valida";
        break;
    }
}

