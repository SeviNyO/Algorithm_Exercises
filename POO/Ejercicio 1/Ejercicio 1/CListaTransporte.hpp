#pragma once
#include <iostream>
#include <vector>
#include "CTransporte.hpp"
using namespace std;

class CListaTransporte {
private:
	vector<CTransporte*> listaTranporte;
public:
	CListaTransporte(){}
	~CListaTransporte() {

	}
	void agregarTransporte(CTransporte* nuevoTransporte) {
		listaTranporte.push_back(nuevoTransporte);
	}
	void eliminarTransporte() {
		listaTranporte.pop_back();
	}
	void dibujar() {
		for (auto i : listaTranporte) {
			if (i != nullptr) {
				i->dibujar();
			}
		}
	}
	void borrar() {
		for (auto i : listaTranporte) {
			if (i != nullptr) {
				i->borrar();
			}
		}
	}
	void mover() {
		for (auto i : listaTranporte) {
			if (i != nullptr) {
				i->mover();
			}
		}
	}
	void animacion() {
		borrar();
		mover();
		dibujar();
		_sleep(100);
	}
};