#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Untitled5.h"
#define TARGET "y=-15.57343+34.58439*x-17.30704*x^2+3.533262*x^3-0.2523758*x^4-3.420112e-15*x^5"

int main(void)
{
    stdstrtest();
    calculate_polynomial(TARGET,5);
//    // Open the file in Google Chrome using the command line
//    #ifdef _WIN32
//    system("start chrome a.svg");
//    #elif __APPLE__
//    system("open -a 'Google Chrome' a.svg");
//    #else
//    system("google-chrome \"file:///C:/Users/bear/Desktop/ntueecs/n1119/n0120/a.svg\"");
//    #endif

    return 0;
}
