#pragma once
#include <iostream>
#include <string>
#include "CProducto.hpp"
using namespace std;

class Controladora {
private:
    Producto** listaProductos;
    Proveedor** listaProveedores;
    int nproductos;
    int nproveedores;
public:
    Controladora();
    ~Controladora();
    void insertarProducto(Producto*);
    void insertarProveedor(Proveedor*);
    void modificar(int);
    void eliminarVencidos();
    void reporteStock();
    void eliminarHerbalife();
    void reporteNatura();
};
Controladora::Controladora() {
    this->listaProductos = nullptr;
    this->nproductos = 0;
    this->listaProveedores = nullptr;
    this->nproveedores = 0;
}
Controladora::~Controladora() {
    for (int i = 0; i < this->nproductos; ++i) {
        delete this->listaProductos[i];
    }
    delete[] this->listaProductos;
    for (int i = 0; i < this->nproveedores; ++i) {
        delete this->listaProveedores[i];
    }
    delete[] this->listaProveedores;
}
void Controladora::insertarProducto(Producto* nuevoProducto) {
    Producto** temp = new Producto * [nproductos + 1];
    for (int i = 0; i < this->nproductos; ++i) {
        temp[i] = this->listaProductos[i];
    }
    int IdProducto, cantidad, anio;
    string Nombre, tipo;
    char categoria;
    double precio;
    string proveedor;

    while (true) {
        cout << "\nId Producto: "; cin >> IdProducto;
        if (IdProducto >= 0) {
            nuevoProducto->setId(IdProducto); break;
        }
        else cout << "Id del producto debe ser positivo";
    }

    while (true) {
        cout << "\nCantidad: "; cin >> cantidad;
        if (cantidad >= 0) {
            nuevoProducto->setCantidad(cantidad);
            break;
        }
        else cout << "La cantidad debe ser positiva";
    }

    while (true) {
        cout << "\nAnio de Vencimiento: "; cin >> anio;
        if (anio > 1900) {
            nuevoProducto->setAnio(anio);
            break;
        }
        else cout << "Fecha muy antigua, debe ser posterior a 1900";
    }

    cin.ignore();
    cout << "\nNombre: "; getline(cin, Nombre);
    nuevoProducto->setNombre(Nombre);
    while (true) {
        int temp;
        cout << "\nTipo: [1] Polvo - [2] Liquido --->"; cin >> temp;
        if (temp == 1) {
            nuevoProducto->setTipo("Polvo");
            break;
        }
        else if (temp == 2) {
            nuevoProducto->setTipo("Liquido");
            break;
        }
        else {
            cout << "\nIngresa una opcion valida";
        }
    }

    while (true) {
        cout << "\nCategoria: [A][B][C] ---> "; cin >> categoria;
        categoria = tolower(categoria);
        if (categoria == 'a' || categoria == 'b' || categoria == 'c') {
            nuevoProducto->setCategoria(categoria);
            break;
        }
        else {
            cout << "\nIntroduce una categoria valida";
        }
    }

    cout << "\nPrecio: "; cin >> precio;
    if (cantidad >= 0) {
        nuevoProducto->setPrecio(precio);
    }
    else cout << "El precio debe ser positivo";

    cout << "\nProveedor:";
    int eleccion;
    for (int i = 0; i < this->nproveedores; ++i) {
        cout << "\n[" << i << "]" << this->listaProveedores[i]->getNombre();
    }
    if (this->nproveedores > 0) {
        cout << "\n"; cin >> eleccion;
        nuevoProducto->setProveedor(this->listaProveedores[eleccion]);
    }
    else {
        cout << "\nNo hay proveedores aun, agregalos en el menu!";
        cout << "\nNo se logro agregar el producto";
        return;
    }
    cout << "\nProducto agregado exitosamente....";

    temp[nproductos] = nuevoProducto;
    delete[] this->listaProductos;
    this->listaProductos = temp;
    ++this->nproductos;
}
void Controladora::insertarProveedor(Proveedor* nuevoProveedor) {
    Proveedor** temp = new Proveedor * [nproveedores + 1];
    for (int i = 0; i < this->nproveedores; ++i) {
        temp[i] = this->listaProveedores[i];
    }
    int Ruc, telefono;
    string nombre, Razon_social, categoria, direccion;
    cout << "\n----------- AGREGAR PROVEEDOR -----------";
    cin.ignore();
    cout << "\nNombre: ";
    getline(cin, nombre);
    cout << "\nRazon social: ";
    getline(cin, Razon_social);
    cout << "\nCategoria: ";
    getline(cin, categoria);
    cout << "\nDireccion: ";
    getline(cin, direccion);
    cout << "\nRUC: ";
    cin >> Ruc;
    cout << "\nTelefono: ";
    cin >> telefono;

    nuevoProveedor->setNombre(nombre);
    nuevoProveedor->setCategoria(categoria);
    nuevoProveedor->setDireccion(direccion);
    nuevoProveedor->setRazonSocial(Razon_social);
    nuevoProveedor->setRuc(Ruc);
    nuevoProveedor->setTelefono(telefono);
    temp[this->nproveedores] = nuevoProveedor;
    delete[] this->listaProveedores;
    this->listaProveedores = temp;
    ++this->nproveedores;
}
void Controladora::modificar(int i) {
    bool existe = false;
    int posicion;
    for (int j = 0; j < this->nproductos; ++j) {
        if (listaProductos[j]->getId() == i) {
            existe = true;
            posicion = j;
            break;
        }
    }
    if (!existe) {
        cout << "\nLa ID ingresada no existe, intente de nuevo: "; return;
    }
    else {
        int IdProducto, cantidad, anio;
        string Nombre, tipo;
        char categoria;
        double precio;
        string proveedor;
        int opcion;
        cout << "\nProducto a modificar: ";
        this->listaProductos[posicion]->mostrar();
        while (true) {
            cout << "\n----------- MENU PARA MODIFICAR -----------";
            cout << "\n[1] IdProducto: ";
            cout << "\n[2] Cantidad: ";
            cout << "\n[3] Anio de vencimiento: ";
            cout << "\n[4] Nombre: ";
            cout << "\n[5] Tipo: ";
            cout << "\n[6] Categoria: ";
            cout << "\n[7] Precio:";
            cout << "\n[8] Proveedor: ";
            cout << "\n[9] Salir ";
            cout << "\n----->"; cin >> opcion;
            switch (opcion)
            {
            case 1:
                while (true) {
                    cout << "\nId Producto: "; cin >> IdProducto;
                    if (IdProducto >= 0) {
                        this->listaProductos[posicion]->setId(IdProducto);
                        break;
                    }
                    else cout << "Id del producto debe ser positivo";
                }
                break;
            case 2:
                while (true) {
                    cout << "\nCantidad: "; cin >> cantidad;
                    if (cantidad >= 0) {
                        this->listaProductos[posicion]->setCantidad(cantidad);
                        break;
                    }
                    else cout << "La cantidad debe ser positiva";
                }
                break;
            case 3:
                while (true) {
                    cout << "\nAnio de Vencimiento: "; cin >> anio;
                    if (anio > 1900) {
                        this->listaProductos[posicion]->setAnio(anio);
                        break;
                    }
                    else cout << "Fecha muy antigua, debe ser posterior a 1900";
                }
                break;
            case 4:
                cin.ignore();
                cout << "\nNombre: "; getline(cin, Nombre);
                this->listaProductos[posicion]->setNombre(Nombre);
                break;
            case 5:
                int temp;
                while (true) {
                    cout << "\nTipo: [1] Polvo - [2] Liquido"; cin >> temp;
                    if (temp == 1) {
                        this->listaProductos[posicion]->setTipo("Polvo");
                        break;
                    }
                    else if (temp == 2) {
                        this->listaProductos[posicion]->setTipo("Liquido");
                        break;
                    }
                    else {
                        cout << "\nIngresa una opcion valida";
                    }
                }
                break;
            case 6:
                while (true) {
                    cout << "\nCategoria: [A][B][C] en MAYUSCULA"; cin >> categoria;
                    categoria = tolower(categoria);
                    if (categoria == 'A' || categoria == 'B' || categoria == 'C') {
                        this->listaProductos[posicion]->setCategoria(categoria); break;
                    }
                    else {
                        cout << "\nIntroduce una categoria valida";
                    }
                }
                break;
            case 7:
                cout << "\nPrecio: "; cin >> precio;
                if (precio >= 0) {
                    this->listaProductos[posicion]->setPrecio(precio);
                    break;
                }
                else cout << "El precio debe ser positivo";
                break;
            case 8:
                cout << "\nProveedor:";
                int eleccion;
                for (int i = 0; i < this->nproveedores; ++i) {
                    cout << "\n[" << i << "]" << this->listaProveedores[i]->getNombre();
                }
                cout << "\n"; cin >> eleccion;
                this->listaProductos[posicion]->setProveedor(this->listaProveedores[eleccion]);
                break;
            case 9:
                cout << "\nSaliendo del modificador....";
                break;
            default:
                cout << "\nElije una opcion valida";
                break;
            }
            if (opcion == 9) break;
        }
    }
}
void Controladora::eliminarVencidos() {
    for (int i = 0; i < nproductos; ++i) {
        if (this->listaProductos[i]->getAnio() < 2020) {
            delete this->listaProductos[i];
            for (int j = i; j < nproductos; ++j) {
                this->listaProductos[j] = this->listaProductos[j + 1];
            }
            --i;
            --this->nproductos;
        }
    }

}
void Controladora::reporteStock() {
    cout << "---------------- PRODUCTOS EN STOCK ----------------";
    int sinstock = 0;
    for (int i = 0; i < this->nproductos; ++i) {
        if (this->listaProductos[i]->getCantidad() > 0) {
            this->listaProductos[i]->mostrar();
            cout << "\n--------------------------------------------";
            ++sinstock;
        }
    }
    if (sinstock == 0) cout << "\nNo hay productos en stock";
}

void Controladora::eliminarHerbalife(){
    for (int i = 0; i < nproductos; ++i) {
        if (this->listaProductos[i]->getProveedor()->getNombre() == "Herbalife") {
            delete this->listaProductos[i];
            for (int j = i; j < nproductos; ++j) {
                this->listaProductos[j] = this->listaProductos[j + 1];
            }
            --i;
            --this->nproductos;
        }
    }
}
void Controladora::reporteNatura(){
    cout << "---------------- PRODUCTOS PROV. NATURA y CATEGORIA A----------------";
    int sinNaturaA = 0;
    for (int i = 0; i < this->nproductos; ++i) {
        if(this->listaProductos[i]->getCategoria() == 'A'){
            if (this->listaProductos[i]->getProveedor()->getNombre() == "Natura") {
                this->listaProductos[i]->mostrar();
                cout << "\n--------------------------------------------";
                ++sinNaturaA;
            }
        }
    }
    if (sinNaturaA == 0) cout << "\nNo hay productos CATEGORIA A del proveedor Natura";
}