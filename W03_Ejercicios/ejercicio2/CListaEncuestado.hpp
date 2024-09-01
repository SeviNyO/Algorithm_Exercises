#pragma once
#include <iostream>
#include "CEncuestado.hpp"
using namespace std;

class ListaEncuestado{
private:
    Encuestado **lista;
    int tam;
public:
    ListaEncuestado();
    ~ListaEncuestado();
    void generarEncuestado(Encuestado*);
    void eliminarEncuestado(int dni);
    void mostrarEncuestados();
};

ListaEncuestado::ListaEncuestado(){
    this->lista = nullptr;
    this->tam = 0;
}
ListaEncuestado::~ListaEncuestado(){
    for (int i = 0; i < this->tam; ++i){
        delete this->lista[i];
    }
    delete[] this->lista;
}
void ListaEncuestado::generarEncuestado(Encuestado* nuevoEncuestado){
    Encuestado **temp = new Encuestado *[this->tam + 1];
    for (int i = 0; i < this->tam; ++i){
        temp[i] = this->lista[i];
    }
    temp[this->tam] = nuevoEncuestado;
    delete[] this->lista;
    this->lista = temp;
    ++tam;
    nuevoEncuestado->mostrar();
}
void ListaEncuestado::eliminarEncuestado(int dni){
    bool existe = false;
    int indice;
    for (int i = 0; i < this->tam; ++i)
    {
        if(this->lista[i]->getDNI() == dni){
            indice = i;
            existe = true;
            break;
        }
    }
    if(!existe){
        cout << "\nEl DNI ingresado no existe";
    } else{
        delete this->lista[indice];
        --this->tam;
        Encuestado** temp = new Encuestado*[this->tam];
        for (int i = 0; i < this->tam; ++i){
            if(i < indice)
                temp[i] = lista[i];
            else
                temp[i] = this->lista[i + 1];
        }
        delete[] this->lista;
        lista = temp;
    }
}
void ListaEncuestado::mostrarEncuestados(){
    cout << "\n-----------  LISTA DE ENCUESTADOS -----------";
    for (int i = 0; i < this->tam; ++i)
    {
        this->lista[i]->mostrar();
    }
}