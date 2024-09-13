#pragma once
#include <iostream>
#include "funciones.hpp"
using namespace std;
using namespace System;

class CTransporte {
protected:
	int velocidad, metrosRecorrido;
	int alto, ancho;
	int x, y, dx;
public:
	CTransporte(int alto, int ancho) {
		this->x = 0;
		this->y = 0;
		this->dx = 1;
		this->alto = alto;
		this->ancho = ancho;
	}
	~CTransporte() {}
	virtual void dibujar() {
	}
	void borrar() {
		for (int i = 0; i < alto; ++i) {
			for (int j = 0; j < ancho; ++j) {
				osuChar(x + j, y + i, ' ');
			}
		}
	}
	virtual void mover() {
		if (x >= 0 && x + this->ancho < ANCHO) {
			x += dx;
		}
	}

};

class CCoche : public CTransporte {
private:
public:
	CCoche() : CTransporte(3,5) {}
	void dibujar() override {
		osuString(x, y, " --- ");
		osuString(x, y + 1, "[---]");
		osuString(x, y + 2, ",   ,");
	}
};

class CBiclicleta : public CTransporte {
private:
public:
	CBiclicleta() : CTransporte(4, 5) {}
	void dibujar() override {
		osuString(x, y, " -?- ");
		osuString(x, y + 1, "[---]");
		osuString(x, y + 2, " / \ ");
		osuString(x, y + 3, ",   ,");
	}
};