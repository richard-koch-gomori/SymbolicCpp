// Residue Number Class example
// Created by Richárd Koch-Gömöri
// kgomori.richard@gmail.com, github.com/richard-koch-gomori


#include <iostream>

#include "symbolicc++.h"
#include "residue.h"
#include "verylong.h"
#include "polynomial.h"


int main()
{
    Residue r1(7, 4);
    Residue r2(7, 3);
    Residue r3(7, 5);

    std::cout << r1 << std::endl;
    std::cout << r2 << std::endl;
    std::cout << r3 << std::endl;

    Polynomial<Residue> x("x");
    Polynomial<Residue> poly = (x^2);
    std::cout << x << std::endl;
    std::cout << poly << std::endl;

    poly = r1*x;
    std::cout << poly << std::endl;

    poly = r1*(x^2) + r2*x + r3;
    std::cout << poly << std::endl;

    std::cout << poly(Residue(7, 1)) << std::endl; // 5
    std::cout << poly(Residue(7, 2)) << std::endl; // 6
    std::cout << poly(Residue(7, 3)) << std::endl; // 1
    std::cout << poly(Residue(7, 4)) << std::endl; // 4

    return 0;
}

