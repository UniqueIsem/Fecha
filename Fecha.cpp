#include "Fecha.h"

void Fecha::setFecha() {
    cout << "Ingrese el dia:\t";
    cin >> dia;
    cout << "Ingrese el mes:\t";
    cin >> mes;
    cout << "Ingrese el año:\t";
    cin >> año;
    cout << "\033[0;0H\033[2J" << endl;
    formatoFecha();
}

void Fecha::formatoFecha() {
    auto t = time(nullptr);
#pragma warning (suppress : 4996)
    auto tm = *localtime(&t);

    cout << "Elige el tipo de formato de fecha prefieres..." << endl;
    cout << "1- mm/dd/yyyy" << endl;
    cout << "2- dd/mm/yyyy" << endl;
    cout << "3- yyyy/mm/dd" << endl;
    cout << "R = ";
    cin >> formato;

    switch (formato) {
    case 1: cout << "\033[0;0H\033[2J" << endl;
        cout << put_time(&tm, "Fecha actual: %h / %d / %Y") << endl;
        cout << endl << "Fecha ingresada: " << mes << " / " << dia << " / " << año << endl;
        break;
    case 2: cout << "\033[0;0H\033[2J" << endl;
        cout << put_time(&tm, "Fecha actual: %d / %h / %Y") << endl;
        cout << endl << "Fecha ingresada: " << dia << " / " << mes << " / " << año << endl;
        break;
    case 3: cout << "\033[0;0H\033[2J" << endl;
        cout << put_time(&tm, "Fecha actual: %Y / %h / %d") << endl;
        cout << endl << "Fecha ingresada: " << año << " / " << mes << " / " << dia << endl;
        break;
    default:
        cout << "\033[0;0H\033[2J" << endl;
        cout << "Opcion no valida\n" << endl;
        formatoFecha();
    }
    validarFecha();
}

void Fecha::validarFecha() {
    try {
        if (mes >= 1 && mes <= 12) {
            switch (mes) {
            case 1: diaMax = ++diaMax;
                break;
            case 2: if (año % 4 == 0 && año % 100 != 0)
            {
                diaMax = --diaMax;
            }
                  else
            {
                diaMax = 14 << 1;
            }
                  break;
            case 3: diaMax = ++diaMax;
                break;
            case 4: diaMax = 30;
                break;
            case 5: diaMax = ++diaMax;
                break;
            case 6: diaMax = 30;
                break;
            case 7: diaMax = ++diaMax;
                break;
            case 8: diaMax = ++diaMax;
                break;
            case 9: diaMax = 30;
                break;
            case 10: diaMax = ++diaMax;
                break;
            case 11: diaMax = 30;
                break;
            case 12: diaMax = ++diaMax;
                break;
            }
        }
        if (dia >= 1 && dia <= diaMax && mes >= 1 && mes <= 12) {
            fechaCorrecta = 1;
        }

        if (fechaCorrecta == 1) {
            cout << "***FECHA CORRECTA***" << endl;
        }
        else {
            throw 0;
        }
    }
    catch (...) {
        cerr << "***FECHA INCORRECTA***" << endl;
        system("pause");
    }
}