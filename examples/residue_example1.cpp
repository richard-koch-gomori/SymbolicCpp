// Residue Number Class example
// Created by Richárd Koch-Gömöri
// kgomori.richard@gmail.com, github.com/richard-koch-gomori


#include <iostream>

#include "symbolicc++.h"
#include "residue.h"
#include "verylong.h"


int main()
{
    Residue i1(7, 5);
    Residue i2(7, 8);
    Residue res = i1 + i2;
    std::cout << "5 + 8 mod 7 = 13 mod 7 = 6 = " << res << std::endl;
    std::cout << "5 - 8 mod 7 = -3 mod 7 = 4 = " << i1 - i2 << std::endl;
    std::cout << "2 * 5 mod 7 = 10 mod 7 = 3 = " << Residue(7, 2) * i1 << std::endl;
    std::cout << "5 / 8 mod 7 = 40 / 8 mod 7 = 5 mod 7 = 5 = " << i1 / i2 << std::endl;
    std::cout << "44 - 23 mod 11 = 10 = " << Residue(11, 44) - Residue(11, 23) << std::endl;
    std::cout << "23 - 44 mod 11 = 1 = " << Residue(11, 23) - Residue(11, 44) << std::endl;
    std::cout << " ... is the same as = " << -(Residue(11, 44) - Residue(11, 23)) << std::endl;

    std::cout << "5 mod 7 == 8 mod 7 = 0 = " << (i1 == i2) << std::endl;

    std::cout << "-5 mod 11 = 6 = " << -Residue(11, 5) << std::endl;
    std::cout << "-5 mod 7 = 2 = " << -i1 << std::endl;

    std::cout << "Verylong(-5) % Verylong(11) = " << Verylong(-5) % Verylong(11) << std::endl;
    std::cout << "Residue(13, -5) % Residue(13, 11) = 8 = " << Residue(13, -5) % Residue(13, 11) << std::endl;

    std::cout << "-100 + 23 mod 11 = 0 = " << Residue(11, -100) + Residue(11, 23) << std::endl;
    std::cout << "-98 + 23 mod 11 = 2 = " << Residue(11, -98) + Residue(11, 23) << std::endl;
    //std::cout << "-98 + 23 mod 11 = 2 = " << Residue(11, -98) + Residue(13, 23) << std::endl; // error

    return 0;
}
