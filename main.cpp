#include <iostream>
#include <cmath>


int sumap_1(int a, int b) {
    int suma = 0;
    for(int i = a; i <= b; i++) {
        if(i % 2 == 0) {
            suma += i;
        }
    }
    return suma;
}


int sumap_2(int a, int b) {
    int suma = 0;
    int start;
    if(a % 2 == 0) {
        start = a;
    } else {
        start = a + 1;
    }
    for(int i = start; i <= b; i+=2) {
        suma += i;
    }
    return suma;
}


int sumap_3(int a, int b) {
    int suma = 0;
    for(int i = a + (a % 2 == 1); i <= b; i+=2) {
        suma += i;
    }
    return suma;
}


double distance_1(int ax, int ay, int bx, int by) {
    int dx = ax - bx;
    int dy = ay - by;
    return sqrt(dx * dx + dy * dy);
}


double distance_2(int ax, int ay, int bx, int by) {
    int dx = ax - bx;
    int dy = ay - by;
    return sqrt(pow(dx, 2) + pow(dy, 2));
}


bool czy_przestepny(int rok) {
    return rok % 4 == 0;
}


int ile_dni_w_roku_1(int rok) {
    if(czy_przestepny(rok)) {
        return 366;
    } else {
        return 365;
    }
}


int ile_dni_w_roku_2(int rok) {
    return czy_przestepny(rok) ? 366 : 365;
}


int ile_dni_w_roku_3(int rok) {
    return 365 + czy_przestepny(rok);
}


int ile_dni_w_miesiacu(int rok, int miesiac) {
    if(miesiac == 2) {
        return czy_przestepny(rok) ? 29 : 28;
    } else if (
               miesiac == 1
            || miesiac == 3
            || miesiac == 5
            || miesiac == 7
            || miesiac == 8
            || miesiac == 10
            || miesiac == 12
            ) {
        return 31;
    } else {
        return 30;
    }
}


int ile_dni_w_miesiacu_switch_case(int rok, int miesiac) {
    switch(miesiac) {
        case 2:
            return czy_przestepny(rok) ? 29 : 28;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        default:
            return 30;
    }
}


int ile_dni(int dzien, int miesiac, int rok) {
    int suma = 0;
    for(int y = 1900; y < rok; y++) {
        suma += ile_dni_w_roku_1(y);
    }
    // tu mamy sumę dni z pełnych lat
    for(int m = 1; m < miesiac; m++) {
        suma += ile_dni_w_miesiacu(rok, miesiac);
    }
    // tu mamy sumę dni z pełnych lat i sumę dni z pełnych miesięcy danego roku
    suma += dzien;
    return suma - 1;
}


int main() {

    return 0;
}
