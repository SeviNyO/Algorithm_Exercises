#pragma
#include <iostream>
#include "funcionesValidacion.hpp"
#include <CProducto.hpp>
using namespace std;

class ListaProductos{
private:
    Producto** listaProductos;
    Proveedor** listaProveedores;
    int nproductos;
    int nproveedores;
public:
    ListaProductos();
    ~ListaProductos();
    void insertarProducto(Producto*);
    void insertarProveedor(Proveedor*);
    void modificar(int);
    void eliminarVencidos();
    void reporteStock();
};
ListaProductos::ListaProductos(){
    this->listaProductos = nullptr;
    this->nproductos = 0;
}
ListaProductos::~ListaProductos(){
    for(int i = 0; i < this->nproductos; ++i){
        delete this->listaProductos[i];
    }
    delete[] this->listaProductos;
    for(int i = 0; i < this->nproveedores; ++i){
        delete this->listaProveedores[i];
    }
    delete[] this->listaProveedores;
}
void ListaProductos::insertarProducto(Producto* nuevoProducto){
    Producto** temp = new Producto*[nproductos + 1];
    for(int i = 0; i < this->nproductos; ++i){
        temp[i] = this->listaProductos[i];
    }
    int IdProducto, cantidad, anio;
    string Nombre, tipo;
    char categoria;
    double precio;
    string proveedor;

    cout << "\nId Producto: "; cin >> IdProducto;
    while(true){
        if (IdProducto >= 0) {
            nuevoProducto->setId(IdProducto); 
        } else cout << "Id del producto debe ser positivo";
    }
    
    while(true){
        cout << "\nCantidad: "; cin >> cantidad;
        if (cantidad >= 0){
            nuevoProducto->setCantidad(cantidad);
            break;
        }
        else cout << "La cantidad debe ser positiva";
    }

    while(true){
        cout << "\nAnio de Vencimiento: "; cin >> anio;
        if(anio > 1900){
            nuevoProducto->setAnio(anio);
            break;
        }
        else cout << "Fecha muy antigua, debe ser posterior a 1900";
    }

    cin.ignore();
    cout << "\nNombre: "; getline(cin, Nombre);
    nuevoProducto->setNombre(Nombre);
    while(true){
        int temp;
        cout << "\nTipo: [1] Polvo - [2] Liquido"; cin >> temp;
        if(temp == 1){
            nuevoProducto->setTipo("Polvo");
            break;
        } else if(temp == 2){
            nuevoProducto->setTipo("Liquido");
            break;
        } else{
            cout << "\nIngresa una opcion valida";
        }
    }
    
    while (true){
        cout << "\nCategoria: [A][B][C]"; cin >> categoria;
        categoria = tolower(categoria);
        if(categoria == 'A' || categoria == 'B' || categoria == 'C'){
            nuevoProducto->setCategoria(categoria); break;
        } else{
            cout << "\nIntroduce una categoria valida";
        }
    }
    
    cout << "\nPrecio: "; cin >> precio;
        if (cantidad >= 0){
            nuevoProducto->setPrecio(precio);
        }
        else cout << "El precio debe ser positivo";
    
    cout << "\nProveedor:";
    int eleccion;
    for(int i = 0; i < this->nproveedores; ++i){
        cout << "\n[" << i << "]" << this->listaProveedores[i]->getNombre();
    }
    cout << "\n"; cin >> eleccion;
    nuevoProducto->setProveedor(this->listaProveedores[eleccion]);
    
    cout << "\nProducto agregado exitosamente....";
        
    temp[nproductos] = nuevoProducto;
    delete[] this->listaProductos;
    this->listaProductos = temp;
    ++this->nproductos;
}
void ListaProductos::insertarProveedor(Proveedor* nuevoProveedor){
    Proveedor** temp = new Proveedor*[nproveedores + 1];
    for(int i = 0; i < this->nproveedores; ++i){
        temp[i] = this->listaProveedores[i];
    }
    int Ruc, telefono;
    string nombre, Razon_social, categoria, direccion;
    cout << "\n----------- AGREGAR PROVEEDOR -----------";
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
void ListaProductos::modificar(int i){
    if(i < 0 || i >= this->nproductos){
        cout << "\nIngrese un indice dentro del rango (0 - " << this->nproductos << ")";
    } else{
    int IdProducto, cantidad, anio;
    string Nombre, tipo;
    char categoria;
    double precio;
    string proveedor;
        int opcion;
        cout << "\nProducto a modificar: "; 
        this->listaProductos[i]->mostrar();
        while(true){
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
            switch (opcion)
            {
            case 1:
                while(true){
                    cout << "\nId Producto: "; cin >> IdProducto;
                    if (IdProducto >= 0) {
                        this->listaProductos[i]->setId(IdProducto); 
                        break;
                    }
                    else cout << "Id del producto debe ser positivo";
                }
                break;
            case 2:
                while(true){
                    cout << "\nCantidad: "; cin >> cantidad;
                    if (cantidad >= 0){
                        this->listaProductos[i]->setCantidad(cantidad);
                        break;
                    }
                    else cout << "La cantidad debe ser positiva";
                }
                break;
            case 3:
                while(true){
                    cout << "\nAnio de Vencimiento: "; cin >> anio;
                    if(anio > 1900){
                        this->listaProductos[i]->setAnio(anio);
                        break;
                    }
                    else cout << "Fecha muy antigua, debe ser posterior a 1900";
                }
                break;
            case 4:
                cin.ignore();
                cout << "\nNombre: "; getline(cin, Nombre);
                this->listaProductos[i]->setNombre(Nombre);
                break;
            case 5:
                int temp;
                while(true){
                    cout << "\nTipo: [1] Polvo - [2] Liquido"; cin >> temp;
                    if(temp == 1){
                        this->listaProductos[i]->setTipo("Polvo");
                        break;
                    } else if(temp == 2){
                        this->listaProductos[i]->setTipo("Liquido");
                        break;
                    } else{
                        cout << "\nIngresa una opcion valida";
                    }
                }
                break;
            case 6:
                while (true){
                    cout << "\nCategoria: [A][B][C]"; cin >> categoria;
                    categoria = tolower(categoria);
                    if(categoria == 'A' || categoria == 'B' || categoria == 'C'){
                        this->listaProductos[i]->setCategoria(categoria); break;
                    } else{
                        cout << "\nIntroduce una categoria valida";
                    }
                }
                break;
            case 7:
                cout << "\nPrecio: "; cin >> precio;
                    if (cantidad >= 0){
                        this->listaProductos[i]->setPrecio(precio);
                        break;
                    }
                    else cout << "El precio debe ser positivo";
                break;
            case 8:
                cout << "\nProveedor:";
                int eleccion;
                for(int i = 0; i < this->nproveedores; ++i){
                    cout << "\n[" << i << "]" << this->listaProveedores[i]->getNombre();
                }
                cout << "\n"; cin >> eleccion;
                this->listaProductos[i]->setProveedor(this->listaProveedores[eleccion]);
                break;
            case 9:
                cout << "\nSaliendo del modificador....";
                break;      
            default:
                cout << "\nElije una opcion valida";
                break;
            }
        }
    }
}
void ListaProductos::eliminarVencidos(){
    int contadorVencidos = 0;
    for(int i = 0; i < nproductos; ++i){
        if(this->listaProductos[i]->getAnio() < 2020){
            delete this->listaProductos[i];
            for(int j = i; j < nproductos; ++j){
                this->listaProductos[j] = this->listaProductos[j + 1];
            }
            --i;
            ++contadorVencidos;
        }
    }
}
void ListaProductos::reporteStock(){
    cout << "---------------- PRODUCTOS EN STOCK ----------------";
    for(int i = 0; i < this->nproductos; ++i){
        if(this->listaProductos[i]->getCantidad() > 0){
            this->listaProductos[i]->mostrar();
            cout << "\n--------------------------------------------";
        }
    }
}