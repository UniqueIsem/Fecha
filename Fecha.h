#pragma once
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <iomanip>

using namespace std;

class Fecha {
protected:
	int dia, mes, año;
	int formato, fechaCorrecta, diaMax = 30;
public:
	Fecha(){}
	void setFecha();
	void formatoFecha();
	void validarFecha();
	Fecha(int inMonth, int inDay, int inYear) : mes(inMonth), dia(inDay), año(inYear) {};

	Fecha& operator ++ () { // prefix incremento
		++dia;
		return *this;
	}

	Fecha& operator -- () { // prefix decremento
		--dia;
		return *this;
	}
};


