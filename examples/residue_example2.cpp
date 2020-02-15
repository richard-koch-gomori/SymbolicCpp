// Residue Number Class example
// Created by Richárd Koch-Gömöri
// kgomori.richard@gmail.com, github.com/richard-koch-gomori


#include <iostream>

#include "symbolicc++.h"
#include "residue.h"
#include "verylong.h"


int main()
{
    const Residue i1{};
    const Residue i2{11, 6};
    std::cout << i1 << std::endl;
    std::cout << i2 << std::endl << std::endl;

    Residue res1 = i1 + i2;
    std::cout << i1 << std::endl;
    std::cout << i2 << std::endl;
    std::cout << "6 = " << res1 << std::endl << std::endl;

    Residue res2 = i1 - i2;
    std::cout << i1 << std::endl;
    std::cout << i2 << std::endl;
    std::cout << "5 = " << res2 << std::endl << std::endl;

    Residue res3 = i1 * i2;
    std::cout << i1 << std::endl;
    std::cout << i2 << std::endl;
    std::cout << "0 = " << res3 << std::endl << std::endl;

    Residue res4 = i1 / i2;
    std::cout << i1 << std::endl;
    std::cout << i2 << std::endl;
    std::cout << "0 = " << res4 << std::endl << std::endl;

    Residue res5 = i1 % i2;
    std::cout << i1 << std::endl;
    std::cout << i2 << std::endl;
    std::cout << "0 = " << res5 << std::endl << std::endl;

    std::cout << "------------------------------------------------" << std::endl;

    const Residue i3{11, 6};
    Residue r1{Verylong(7)};
    std::cout << r1*r1 << std::endl;
    std::cout << i3*r1 << std::endl;

    std::cout << "------------------------------------------------" << std::endl;

    const Residue r2{13, 5};
    std::cout << r1 << std::endl;
    std::cout << r2 << std::endl;
    r1 += r2;
    std::cout << r1 << std::endl;
    std::cout << r2 << std::endl;

    return 0;
}
