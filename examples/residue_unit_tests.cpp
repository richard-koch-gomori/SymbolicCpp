// Residue Number Class test cases
// Created by Richárd Koch-Gömöri
// kgomori.richard@gmail.com, github.com/richard-koch-gomori


#include <iostream>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "symbolicc++.h"
#include "residue.h"
#include "verylong.h"


TEST_CASE("constructor(int, int)", "[Residue]")
{
    Residue num(11, 8);
    REQUIRE(num.GetModulus() == Verylong(11));
    REQUIRE(num.GetRepresentant() == Verylong(8));
}

TEST_CASE("constructor(Verylong, int)", "[Residue]")
{
    Residue num(Verylong(11), 8);
    REQUIRE(num.GetModulus() == Verylong(11));
    REQUIRE(num.GetRepresentant() == Verylong(8));
}

TEST_CASE("constructor(int, Verylong)", "[Residue]")
{
    Residue num(11, Verylong(8));
    REQUIRE(num.GetModulus() == Verylong(11));
    REQUIRE(num.GetRepresentant() == Verylong(8));
}

TEST_CASE("constructor(Verylong, Verylong)", "[Residue]")
{
    Residue num(Verylong(11), Verylong(8));
    REQUIRE(num.GetModulus() == Verylong(11));
    REQUIRE(num.GetRepresentant() == Verylong(8));
}

TEST_CASE("constructor(Residue)", "[Residue]")
{
    Residue other(11, 8);
    Residue num(other);
    REQUIRE(num.GetModulus() == Verylong(11));
    REQUIRE(num.GetRepresentant() == Verylong(8));
}

TEST_CASE("int() conversion", "[Residue]")
{
    Residue num(12, 10);
    REQUIRE(int(num) == 10);
}

TEST_CASE("std::string() conversion", "[Residue]")
{
    Residue num(12, 10);
    REQUIRE(std::string(num) == "10");
}

TEST_CASE("operator =", "[Residue]")
{
    Residue num(12, 10);
    Residue other = num;
    REQUIRE(other.GetModulus() == Verylong(12));
    REQUIRE(other.GetRepresentant() == Verylong(10));
}

TEST_CASE("operator - (negate operand)", "[Residue]")
{
    Residue num(12, 10);
    Residue other = -num;
    REQUIRE(other.GetModulus() == Verylong(12));
    REQUIRE(other.GetRepresentant() == Verylong(2));
}

TEST_CASE("operator - (negate operand) (2nd)", "[Residue]")
{
    Residue num(12, 3);
    Residue other = -num;
    REQUIRE(other.GetModulus() == Verylong(12));
    REQUIRE(other.GetRepresentant() == Verylong(9));
}

TEST_CASE("prefix operator ++", "[Residue]")
{
    Residue num(12, 10);
    Residue other = ++num;
    REQUIRE(num.GetModulus() == Verylong(12));
    REQUIRE(num.GetRepresentant() == Verylong(11));
    REQUIRE(other.GetModulus() == Verylong(12));
    REQUIRE(other.GetRepresentant() == Verylong(11));
}

TEST_CASE("postfix operator ++ (check return value)", "[Residue]")
{
    Residue num(12, 10);
    Residue other = num++;
    REQUIRE(num.GetModulus() == Verylong(12));
    REQUIRE(num.GetRepresentant() == Verylong(11));
    REQUIRE(other.GetModulus() == Verylong(12));
    REQUIRE(other.GetRepresentant() == Verylong(10));
}

TEST_CASE("postfix operator ++", "[Residue]")
{
    Residue num(12, 11);
    num++;
    REQUIRE(num.GetModulus() == Verylong(12));
    REQUIRE(num.GetRepresentant() == Verylong(0));
}

TEST_CASE("prefix operator --", "[Residue]")
{
    Residue num(12, 10);
    Residue other = --num;
    REQUIRE(num.GetModulus() == Verylong(12));
    REQUIRE(num.GetRepresentant() == Verylong(9));
    REQUIRE(other.GetModulus() == Verylong(12));
    REQUIRE(other.GetRepresentant() == Verylong(9));
}

TEST_CASE("postfix operator -- (check return value)", "[Residue]")
{
    Residue num(12, 10);
    Residue other = num--;
    REQUIRE(num.GetModulus() == Verylong(12));
    REQUIRE(num.GetRepresentant() == Verylong(9));
    REQUIRE(other.GetModulus() == Verylong(12));
    REQUIRE(other.GetRepresentant() == Verylong(10));
}

TEST_CASE("postfix operator --", "[Residue]")
{
    Residue num(12, 0);
    num--;
    REQUIRE(num.GetModulus() == Verylong(12));
    REQUIRE(num.GetRepresentant() == Verylong(11));
}

TEST_CASE("operator +=", "[Residue]")
{
    Residue num(12, 6);
    num += Residue(12, 3);
    REQUIRE(num.GetModulus() == Verylong(12));
    REQUIRE(num.GetRepresentant() == Verylong(9));
    num += Residue(12, 3);
    REQUIRE(num.GetModulus() == Verylong(12));
    REQUIRE(num.GetRepresentant() == Verylong(0));
    num += Residue(12, 3);
    REQUIRE(num.GetModulus() == Verylong(12));
    REQUIRE(num.GetRepresentant() == Verylong(3));
}

TEST_CASE("operator -=", "[Residue]")
{
    Residue num(12, 6);
    num -= Residue(12, 3);
    REQUIRE(num.GetModulus() == Verylong(12));
    REQUIRE(num.GetRepresentant() == Verylong(3));
    num -= Residue(12, 5);
    REQUIRE(num.GetModulus() == Verylong(12));
    REQUIRE(num.GetRepresentant() == Verylong(10));
}

TEST_CASE("operator *=", "[Residue]")
{
    Residue num(12, 6);
    num *= Residue(12, 3);
    REQUIRE(num.GetModulus() == Verylong(12));
    REQUIRE(num.GetRepresentant() == Verylong(6));
}

TEST_CASE("operator /=", "[Residue]")
{
    Residue num(11, 6);
    num /= Residue(11, 3);
    REQUIRE(num.GetModulus() == Verylong(11));
    REQUIRE(num.GetRepresentant() == Verylong(2));
}

TEST_CASE("operator /= (2nd)", "[Residue]")
{
    Residue num(11, 6);
    num /= Residue(11, 5);
    REQUIRE(num.GetModulus() == Verylong(11));
    REQUIRE(num.GetRepresentant() == Verylong(10));
}

TEST_CASE("operator %=", "[Residue]")
{
    Residue num(11, 6);
    num %= Residue(11, 3);
    REQUIRE(num.GetModulus() == Verylong(11));
    REQUIRE(num.GetRepresentant() == Verylong(0));
}

TEST_CASE("operator %= (2nd)", "[Residue]")
{
    Residue num(11, 5);
    num %= Residue(11, 3);
    REQUIRE(num.GetModulus() == Verylong(11));
    REQUIRE(num.GetRepresentant() == Verylong(2));
}

TEST_CASE("operator %= (3rd)", "[Residue]")
{
    Residue num(11, -6);
    num %= Residue(11, 4);
    REQUIRE(num.GetModulus() == Verylong(11));
    REQUIRE(num.GetRepresentant() == Verylong(1));
}

TEST_CASE("operator +", "[Residue]")
{
    Residue num1(11, 4);
    Residue num2(11, 6);
    Residue result = num1 + num2;
    REQUIRE(result.GetModulus() == Verylong(11));
    REQUIRE(result.GetRepresentant() == Verylong(10));
}

TEST_CASE("operator + (result is greater than modulus)", "[Residue]")
{
    Residue num1(11, 4);
    Residue num2(11, 7);
    Residue result = num1 + num2;
    REQUIRE(result.GetModulus() == Verylong(11));
    REQUIRE(result.GetRepresentant() == Verylong(0));
}

TEST_CASE("operator + (result is greater than modulus) (2nd)", "[Residue]")
{
    Residue num1(11, 10);
    Residue num2(11, 30);
    Residue result = num1 + num2;
    REQUIRE(result.GetModulus() == Verylong(11));
    REQUIRE(result.GetRepresentant() == Verylong(7));
}

TEST_CASE("operator + (one operand is negative)", "[Residue]")
{
    Residue num1(11, -4);
    Residue num2(11, 1);
    Residue result = num1 + num2;
    REQUIRE(result.GetModulus() == Verylong(11));
    REQUIRE(result.GetRepresentant() == Verylong(8));
}

TEST_CASE("operator -", "[Residue]")
{
    Residue num1(11, 4);
    Residue num2(11, 6);
    Residue result = num1 - num2;
    REQUIRE(result.GetModulus() == Verylong(11));
    REQUIRE(result.GetRepresentant() == Verylong(9));
}

TEST_CASE("operator *", "[Residue]")
{
    Residue num1(11, 9);
    Residue num2(11, 6);
    Residue result = num1 * num2;
    REQUIRE(result.GetModulus() == Verylong(11));
    REQUIRE(result.GetRepresentant() == Verylong(10));
}

TEST_CASE("operator / (nontrivial)", "[Residue]")
{
    Residue num1(11, 4);
    Residue num2(11, 6);
    Residue result = num1 / num2;
    REQUIRE(result.GetModulus() == Verylong(11));
    REQUIRE(result.GetRepresentant() == Verylong(8));
}

TEST_CASE("operator / (trivial)", "[Residue]")
{
    Residue num1(11, 10);
    Residue num2(11, 2);
    Residue result = num1 / num2;
    REQUIRE(result.GetModulus() == Verylong(11));
    REQUIRE(result.GetRepresentant() == Verylong(5));
}

TEST_CASE("operator / (inversion)", "[Residue]")
{
    Residue num1(11, 1);
    Residue num2(11, 6);
    Residue result = num1 / num2;
    REQUIRE(result.GetModulus() == Verylong(11));
    REQUIRE(result.GetRepresentant() == Verylong(2));
}

TEST_CASE("operator / (one operand is negative)", "[Residue]")
{
    Residue num1(11, -3);
    Residue num2(11, 8);
    Residue result = num1 / num2;
    REQUIRE(result.GetModulus() == Verylong(11));
    REQUIRE(result.GetRepresentant() == Verylong(1));
}

TEST_CASE("operator == (equal modulus)", "[Residue]")
{
    Residue num1(11, 6);
    Residue num2(11, 6);
    REQUIRE(num1 == num2);
}

TEST_CASE("operator == (inequal modulus)", "[Residue]")
{
    Residue num1(10, 6);
    Residue num2(11, 6);
    REQUIRE(num1 == num2);
}

TEST_CASE("operator == (one operand is equal to modulus)", "[Residue]")
{
    Residue num1(11, 11);
    Residue num2(11, 0);
    REQUIRE(num1 == num2);
}

TEST_CASE("operator != (equal modulus)", "[Residue]")
{
    Residue num1(11, 5);
    Residue num2(11, 6);
    REQUIRE(num1 != num2);
}

TEST_CASE("operator != (inequal modulus)", "[Residue]")
{
    Residue num1(10, 6);
    Residue num2(11, 6);
    REQUIRE(num1 == num2);
}

TEST_CASE("EqualsByModulus", "[Residue]")
{
    Residue num1(11, 6);
    Residue num2(11, 6);
    REQUIRE(EqualsByModulus(num1, num2) == 1);
}

TEST_CASE("EqualsByModulus (equal modulus, inequal representant)", "[Residue]")
{
    Residue num1(11, 6);
    Residue num2(11, 5);
    REQUIRE(EqualsByModulus(num1, num2) == 0);
}

TEST_CASE("EqualsByModulus (inequal modulus, equal representant)", "[Residue]")
{
    Residue num1(10, 6);
    Residue num2(11, 6);
    REQUIRE(EqualsByModulus(num1, num2) == 0);
}

