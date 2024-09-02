#pragma once
#include <iostream>
#include "CCliente.hpp"
using namespace std;

class ArregloCliente{
private:
    Cliente **clientes;
    int nclientes;
public:
    ArregloCliente();
    ~ArregloCliente();
    int getTamanio();
    int obtenerDNI(int);
    void agregarCliente(Cliente *);
    void mostrar();
};

ArregloCliente::ArregloCliente(){
    this->clientes = nullptr;
    this->nclientes = 0;
}
ArregloCliente::~ArregloCliente(){
    for (int i = 0; i < this->nclientes; ++i){
        delete this->clientes[i];
    }
    delete[] this->clientes;
}
int ArregloCliente::getTamanio(){
    return this->nclientes;
}
int ArregloCliente::obtenerDNI(int dni){
    for (int i = 0; i < this->nclientes; ++i){
        if(this->clientes[i]->getDNI() == dni){
            return this->clientes[i]->getDNI();
        }
    }
    return -1;
}
void ArregloCliente::agregarCliente(Cliente* nuevoCliente){
    Cliente **temp = new Cliente*[this->nclientes + 1];
    for (int i = 0; i < this->nclientes; ++i){
        temp[i] = this->clientes[i];
    }
    temp[this->nclientes] = nuevoCliente;
    delete[] this->clientes;
    this->clientes = temp;
    ++this->nclientes;
}
void ArregloCliente::mostrar(){
    cout << "\n------------------ LISTA DE CLIENTES ------------------";
    for (int i = 0; i < this->nclientes; ++i)
    {
        cout << "->";
        this->clientes[i]->mostrar();
    }
    cout << "\n-------------------------------------------------------";
}