//
// Created by sebas on 7/14/2024.
//

#ifndef VUELOS_H
#define VUELOS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;
const string red = "\033[31m";
const  string reset = "\033[0m";
const string blue = "\033[34m";

class Vuelos {
private:

    string Opt;
    string Opt_VuelosH;
    vector<vector<vector<vector<int>>>> planes;
    vector<pair<int, string>> reservations;

public:
    Vuelos() {
        planes.resize(5);
        for (int plane =0; plane <5; plane++) {
            planes[plane].resize(2);

            for (int side =0 ; side<2; side++) {
                planes[plane][side].resize(2);

                for (int seatType =0; seatType <2; seatType++) {
                    planes [plane][side][seatType].resize(5,0);
                }
            }
        }
    }
    void setplaneOpt(int UserplaneOpt);
    void displayLogo();
    void menu();
    void displaySeats(int planeOpt);
    void displaySeats_all();
    int reserveSeat(int planeOpt, string &seat);
    void cancelReservation(string cancelDay);
    void showReservations();
};



#endif //VUELOS_H
