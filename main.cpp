#include "Vuelos.h"


int main() {
    string UserOpt;
    string seat;
    int planeOpt;
    int Num_bol;
    Vuelos vuelosL;
    Vuelos vuelosM;
    Vuelos vuelosJ;

    vuelosL.displayLogo();
    while (UserOpt != "x" && UserOpt!="x") {
        vuelosL.menu();
        cin >> UserOpt;
        if (UserOpt == "l"||UserOpt == "L") {
            cout << "Para el lunes tenemos 5 opciones de vuelo\n1.6:00 AM\n2.7:00 AM\n3.8:00 AM\n4.9:00 AM\n5.10:00 AM\n6.Muestra todos los vuelos del lunes\n"
            "Ingrese el numero de opcion para mostrar la informacion del vuelo.( o \"-1\" para regresar)\n" + red +"Opcion:" <<reset;
              cin >> planeOpt;
              if (planeOpt ==-1){
                  continue;
              }
            if (planeOpt == 6) {
            vuelosL.displaySeats_all();
            }
            else if (planeOpt ==1 ||planeOpt ==2|| planeOpt ==3|| planeOpt ==4||planeOpt ==5||planeOpt ==6) {
                Num_bol=0;
                cout << "Ingrese la cantidad de boletos que dessee comprar. ( o \"-1\" para regresar)\n"<<red<<"Num:"<<reset;
                cin >> Num_bol;
                if (Num_bol==-1){
                    continue;
                }
                while(Num_bol!=0) {
                    vuelosL.displaySeats(planeOpt);
                    cout << "Ingrese el asiento que desea comprar indicado por su Columna y fila ej: A1 (recuerde usar mayusculas)\n"
                            "si desea cancelar la orden de sus siguienetes boletos (sin perder los ya reservados) ingrese x\n"
                            << red<< "Asiento:"<<reset;
                    cin >> seat;
                    if (seat == "x" ||seat == "X") {
                        cout<< "su orden ha sido cancelada de manera correcta.\n"
                               "si desea salir del programa ingrese de nuevo x\n";
                        break;
                    }
                    Num_bol-=vuelosL.reserveSeat(planeOpt,seat);
                }
                cout << "Su reserva quedaria como: "<<endl;
                vuelosL.displaySeats(planeOpt);
            }
            else {
                cout << "Esa no es una opcion valida.\nIntente otra vez.\n";
            }
        }
        else if (UserOpt == "m"|| UserOpt == "M") {
            cout << "Para el martes tenemos 5 opciones de vuelo\n1.6:00 AM\n2.7:00 AM\n3.8:00 AM\n4.9:00 AM\n5.10:00 AM\n6.Muestra todos los vuelos del martes\n"
            "Ingrese el numero de opcion para mostrar la informacion del vuelo. ( o \"-1\" para regresar)\n" << red <<"Opcion:" <<reset;
            cin >> planeOpt;
            if (planeOpt==-1){
                continue;
            }
            if (planeOpt == 6) {
                vuelosM.displaySeats_all();
            }
            else if (planeOpt ==1 ||planeOpt ==2|| planeOpt ==3|| planeOpt ==4||planeOpt ==5||planeOpt ==6) {
                Num_bol =0;
                cout << "Ingrese la cantidad de boletos que dessee comprar.( o \"-1\" para regresar) \n"<<red<<"Num:"<<reset <<endl;
                cin >> Num_bol;
                if (Num_bol==-1){
                    continue;
                }
                while(Num_bol!=0) {
                    vuelosM.displaySeats(planeOpt);
                    cout << "Ingrese el asiento que desea comprar indicado por su Columna y fila ej: A1 (recuerde usar mayusculas)\n"
                            "si desea cancelar la orden de sus siguienetes boletos (sin perder los ya reservados) ingrese x\n"
                            << red<< "Asiento:"<<reset;
                    cin >> seat;
                    if (seat == "x" ||seat == "X") {
                        cout<< "su orden ha sido cancelada de manera correcta.\n"
                               "si desea salir del programa ingrese de nuevo x\n";
                        break;
                    }
                    Num_bol-=vuelosM.reserveSeat(planeOpt,seat);
                }
                cout << "Su reserva quedaria como: "<<endl;
                vuelosM.displaySeats(planeOpt);
            }
            else {
                cout << "Esa no es una opcion valida.\nIntente otra vez.";
            }
        }
        else if (UserOpt == "j"|| UserOpt == "J") {
            cout << "Para el jueves tenemos 5 opciones de vuelo\n1.6:00 AM\n2.7:00 AM\n3.8:00 AM\n4.9:00 AM\n5.10:00 AM\n6.Muestra todos los vuelos del jueves\n"
            "Ingrese el numero de opcion para mostrar la informacion del vuelo.( o \"-1\" para regresar) \n" + red +"Opcion:" <<reset;
            cin >> planeOpt;
            if (planeOpt==-1){
                continue;
            }
            if (planeOpt == 6) {
                vuelosJ.displaySeats_all();
            }
            else if (planeOpt ==1 ||planeOpt ==2|| planeOpt ==3|| planeOpt ==4||planeOpt ==5||planeOpt ==6) {
                Num_bol=0;
                cout << "Ingrese la cantidad de boletos que dessee comprar.( o \"-1\" para regresar)\n"<<red<<"Num:"<<reset<<endl;
                cin >> Num_bol;
                if (Num_bol==-1){
                    continue;
                }
                while(Num_bol!=0) {
                    vuelosJ.displaySeats(planeOpt);
                    cout << "Ingrese el asiento que desea comprar indicado por su Columna y fila ej: A1 (recuerde usar mayusculas)\n"
                            "si desea cancelar la orden de sus siguienetes boletos (sin perder los ya reservados) ingrese x\n"
                            << red<< "Asiento:"<<reset;
                    cin >> seat;
                    if (seat == "x" ||seat == "X") {
                        cout<< "su orden ha sido cancelada de manera correcta.\n"
                               "si desea salir del programa ingrese de nuevo x\n";
                        break;
                    }
                    Num_bol-=vuelosJ.reserveSeat(planeOpt,seat);
                }
                cout << "Su reserva quedaria como: "<<endl;
                vuelosJ.displaySeats(planeOpt);
            }
            else {
                cout << "Esa no es una opcion valida.\nIntente otra vez."<<endl;
            }
        }
        else if(UserOpt == "all"|| UserOpt == "ALL") {
            cout<< "\nLos vuelos disponibles para el lunes son:\n"<<endl;
            vuelosL.displaySeats_all();
            cout<< "\nLos vuelos disponibles para el martes son:\n"<<endl;
            vuelosM.displaySeats_all();
            cout<< "\nLos vuelos disponibles para el jueves son:\n"<<endl;
            vuelosJ.displaySeats_all();
        }
        else if (UserOpt == "cancel"|| UserOpt == "Cancel"){
            string cancelDay;
            cout << "Para que dia desea cancelar su reserva?\n"
                    "1. Lunes, escriba "<<red<<"\"l\"\n" <<reset<<
                    "2. Martes, escriba "<<red<< "\"m\"\n" <<reset<<
                    "3. jueves, escriba "<<red<< "\"j\"\n"<<reset<<
                    "4. No cancelar, escriba "<< red<< "x"<< reset<< " para regresar al menu."<<red
                    << "Opcion:"<< reset;
            cin >> cancelDay;
            if (cancelDay == "x"||cancelDay =="X"){
                continue;
            }
            if (cancelDay== "l" || cancelDay == "L"){
                vuelosL.showReservations();
                vuelosL.cancelReservation(cancelDay);
            }
            if (cancelDay== "M" || cancelDay == "m"){
                vuelosM.showReservations();
                vuelosM.cancelReservation(cancelDay);
            }
            if (cancelDay== "J" || cancelDay == "j"){
                vuelosM.showReservations();
                vuelosJ.cancelReservation(cancelDay);
            }
            else {
                cout<< "esa no es una opcion valida"<<endl;
            }
        }
        else if (UserOpt == "show"|| UserOpt == "SHOW"){
            cout << "Para el dia lunes tiene las siguientes ";
            vuelosL.showReservations();
            cout << "\nPara el dia martes tiene las siguientes ";
            vuelosM.showReservations();
            cout << "\nPara el dia jueves tiene las siguientes ";
            vuelosJ.showReservations();
        }
        else if (UserOpt == "x"|| UserOpt == "X") {
            cout << "Gracias por utilizar este programa."<<endl;

        }

        else {
            cout << "Esa no es una opcion valida";
        }
    }

    return 0;
}


