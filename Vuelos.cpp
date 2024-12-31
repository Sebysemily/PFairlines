//
// Created by sebas on 7/14/2024.
//

#include "Vuelos.h"


void Vuelos::menu() {
    cout<< "Estos son los vuelos de la linea Quito-Miami\n"<<
        "Si desea ver los vuelos disponibles el lunes ingrese "<< red<< "l.\n"<<reset<<
    "Si desea ver los vuelos disponibles el martes ingrese "<< red<< "m.\n"<<reset<<
    "Si desea ver los vuelos disponibles el jueves ingrese "<< red<< "j.\n"<<reset<<
    "Si desea ver todos los vuelos disponibles ingrese "<< red<< "all.\n"<<reset<<
    "Si desea cancelar una reserva ingrese "<< red<< "cancel.\n"<<reset<<
    "Si desea ver sus reservas actuales ingrese " << red << "show\n"<<reset<<
    "Si desea salir del programa ingrese "<< red<< "x.\n"<<reset<<
    red<< "Opcion:"<<reset;
}

void Vuelos::displayLogo() {
    cout<< "\n"<< "Bienvenido a la aerolina "<< red<<"ProyectoFinal Airlines\n"<< reset;
    for (int i=1; i <=11 ; i++) {
        for (int j=1; j<=21 ;j++) {
            if ((i==1 || (j==1 && i!=5) || (j==16 && i!=5)|| i==10 ) && j<=16 && i<=10) {
                cout<<blue<< "* " << reset;
            }
            else if ( j== 1 && i==5) {
                cout << red <<"*   ProyectoFinal Airlines    * "<<reset<<" * * * *"<<blue<<" Gracias por elegir "<<red <<"ProyectoFinal Airlines"<<reset ;;
            }
            else if (j>16 && (i==4 ||i==6) && j<21 ) {
                cout << "* ";
            }
            else if((i==3 || i==8) && (j==17)){
                cout<< "* ";
            }
            else if ((i==4 || i==7)&&(j>16 && j<=18)){
                cout << "* ";
            }
            else {
                cout<< "  ";
            }
        }
        cout << endl;
    }
}

void Vuelos::displaySeats(int planeOpt) {
    if (planeOpt<1 || planeOpt>5) {
        cout<< "\nEsa no es una opcion de vuelo\n"<<endl;
        return;
    }
    switch (planeOpt) {
        case 1:
            cout << "El avion en el " << planeOpt <<"er horario ";
        break;
        case 2:
            cout << "El avion en el " << planeOpt <<"do horario ";
        break;
        case 3:
            cout << "El avion en el " << planeOpt <<"er horario ";
        break;
        case 4:
            cout << "El avion en el " << planeOpt <<"to horario ";
        break;
        case 5:
            cout << "El avion en el " << planeOpt <<"to horario ";
        break;
        default:
            break;
    }
    cout<< "Tiene los siguientes asientos disponibles\n"
           "Blanco disponible "<<red <<"rojo ocupado"<<reset<<endl<<
            " Fila izq-Fila der"<<endl;
    cout <<"   A B    C D"<<endl;
    for (int i = 0; i < 5; i++) {
        cout<< i+1<<"  ";
        if (planes[planeOpt-1][0][0][i] == 0) {
            cout << "* ";
        } else {
            cout << red << "* " << reset;
        }

        if (planes[planeOpt-1][0][1][i] == 0) {
            cout << "* ";
        } else {
            cout << red << "* " << reset;
        }

        cout << "   ";

        if (planes[planeOpt-1][1][1][i] == 0) {
            cout << "* ";
        } else {
            cout << red << "* " << reset;
        }

        if (planes[planeOpt-1][1][0][i] == 0) {
            cout << "* ";
        } else {
            cout << red << "* " << reset;
        }
        cout << endl;
    }
}


void Vuelos::displaySeats_all() {
    for (int  planeOpt =1; planeOpt<=5 ;planeOpt++) {
        displaySeats(planeOpt);
    }
}

int Vuelos::reserveSeat(int planeOpt, string &seat) {
    if (seat.length()<2 && seat.length()>2 ) {
        cout<< "\n"<< red<< "El formato de asiento no es correcto\nRecuerde que tiene que usar mayusculas y el siguiente formato: ejemplo A1\n"<<reset<< endl;
        return 0;
    }
    char rowChar = seat[0];
    char colChar = seat[1];
    int rowNum, side, seatType;

    switch (rowChar) {
        case 'A':
            side = 0; seatType = 0; break;
        case 'B':
            side = 0; seatType = 1; break;
        case 'C':
            side = 1; seatType = 1; break;
        case 'D':
            side = 1; seatType = 0; break;
        default:
            cout << "\n"<<red<<"Numero de asiento no valido, intente otra vez\n" <<reset<< endl;
        return 0;
    }
    switch (colChar) {
        case '1': rowNum = 0; break;
        case '2': rowNum = 1; break;
        case '3': rowNum = 2; break;
        case '4': rowNum = 3; break;
        case '5': rowNum = 4; break;
        default:
            cout << "\n"<<red<<"Numero de asiento no valido, intente otra vez.\n" <<reset<< endl;
        return 0;
    }
    if (planes[planeOpt-1][side][seatType][rowNum] == 1) {
        cout << "\n"<<red<<"Asiento ya reservado, intente otra vez.\n" << reset<<endl;
        return 0;
    }
    else {
        planes[planeOpt-1][side][seatType][rowNum] = 1;
        cout << "Asiento " << seat << " Ha sido reservado de manera correcta.\n"
                                   "Para pagar su boleto porfavor acerce al mostrador de la arelinea el dia del vuelo minimo 1:30h antes del despegue\n" << endl;
        return 1;
    }
}
void Vuelos::cancelReservation(string cancelDay) {
    if (reservations.empty()) {
        return;
    }
    int cancelOpt;
    cout << "Ingrese el numero de la reserva que desea cancelar (o \"-1\" para no cancelar ninguna reserva): ";
    cin >> cancelOpt;
    if (cancelOpt== -1){
        cout<< "\nNinguna reserva ha sido cancelada\n"<< endl;
        return;
    }
    else if (cancelOpt < 1 || cancelOpt > reservations.size() ) {
        cout << "\nOpcion invalida.\n" << endl;
    }
    int planeOpt = reservations[cancelOpt - 1].first;
    string seat = reservations[cancelOpt - 1].second;

    char rowChar = seat[0];
    int rowNum = seat[1] - '1';
    int side, seatType;

    switch (rowChar) {
        case 'A':
            side = 0;
            seatType = 0;
            break;
        case 'B':
            side = 0;
            seatType = 1;
            break;
        case 'C':
            side = 1;
            seatType = 1;
            break;
        case 'D':
            side = 1;
            seatType = 0;
            break;
        default:
            return;
    }
    string Day;
    if (cancelDay== "l" || cancelDay == "L"){
        Day= "lunes";
    }
    if (cancelDay== "M" || cancelDay == "m"){
        Day = "martes";
    }
    if (cancelDay== "J" || cancelDay == "j"){
        Day = "jueves";
    }
    planes[planeOpt - 1][side][seatType][rowNum] = 0;
    cout << "\nReserva de asiento " << seat << " en el avion " << planeOpt <<" del dia "<< Day<<  " ha sido cancelada." << endl;
}
void Vuelos::showReservations() {
    reservations.clear();
    for (int planeOpt = 1; planeOpt <= 5; planeOpt++) {
        for (int i =   0; i < 5; i++) {
            if (planes[planeOpt - 1][0][0][i] == 1) {
                reservations.push_back(make_pair(planeOpt, "A" + to_string(i + 1)));
            }
            if (planes[planeOpt - 1][0][1][i] == 1) {
                reservations.push_back(make_pair(planeOpt, "B" + to_string(i + 1)));
            }
            if (planes[planeOpt - 1][1][1][i] == 1) {
                reservations.push_back(make_pair(planeOpt, "C" + to_string(i + 1)));
            }
            if (planes[planeOpt - 1][1][0][i] == 1) {
                reservations.push_back(make_pair(planeOpt, "D" + to_string(i + 1)));
            }
        }
    }

    cout << "Reservas actuales:" << endl;
    for (int i = 0; i < reservations.size(); i++) {
        cout << i + 1 << ". Avion " << reservations[i].first << ", Asiento " << reservations[i].second << endl;
    }

    if (reservations.empty()) {
        cout << "No hay reservas actuales." << endl;
        return;
    }
}
