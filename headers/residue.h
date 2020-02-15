/*
    SymbolicC++ : An object oriented computer algebra system written in C++

    Copyright (C) 2008 Yorick Hardy and Willi-Hans Steeb

    This library is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


// residue.h
// Residue Number Class
// Created by Richárd Koch-Gömöri
// kgomori.richard@gmail.com, github.com/richard-koch-gomori

#ifndef RESIDUE_H
#define RESIDUE_H

#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include "identity.h"
#include "verylong.h"
using namespace std;

class Residue
{
   private:
      // Data Fields
      Verylong modulus;
      Verylong representant;

      static Verylong make_representant(const Verylong&, const Verylong&);

   public:
      // Constructors and destructor
      Residue();
      Residue(const Verylong&);
      Residue(const Residue&);
      Residue(const Verylong&, const Verylong&);
      Residue(int, int);
      Residue(const Verylong&, int);
      Residue(int, const Verylong&);
      ~Residue();

      // Getters, setters
      Verylong GetModulus() const { return modulus; }
      Verylong GetRepresentant() const { return representant; }

      // Conversion operators
      operator int () const;
      operator string () const;

      // Arithmetic operators and Relational operators
      const Residue & operator = (const Residue&);  // assignment operator
      Residue operator - () const;     // negate  operator
      Residue operator ++ ();          // prefix  increment operator
      Residue operator ++ (int);       // postfix increment operator
      Residue operator -- ();          // prefix  decrement operator
      Residue operator -- (int);       // postfix decrement operator

      Residue operator += (const Residue&);
      Residue operator -= (const Residue&);
      Residue operator *= (const Residue&);
      Residue operator /= (const Residue&);
      Residue operator %= (const Residue&);

      friend Residue operator + (const Residue&, const Residue&);
      friend Residue operator - (const Residue&, const Residue&);
      friend Residue operator * (const Residue&, const Residue&);
      friend Residue operator / (const Residue&, const Residue&);
      friend Residue operator % (const Residue&, const Residue&);
      friend int operator == (const Residue&,const Residue&);
      friend int operator != (const Residue&,const Residue&);
      friend int EqualsByModulus(const Residue&,const Residue&);

      // Class Data
      static const Residue zero;
      static const Residue one;
      static const Residue two;

      // I/O stream functions
      friend ostream & operator << (ostream&,const Residue&);
      friend istream & operator >> (istream&,Residue&);
};

#define LIBSYMBOLICCPLUSPLUS

// Class Data

const Residue Residue::zero = Residue(Verylong::zero);
const Residue Residue::one = Residue(Verylong::one);
const Residue Residue::two = Residue(Verylong::two);

// Constructors, Destructors and Conversion operators.

Verylong Residue::make_representant(const Verylong& value, const Verylong& modulus)
{
   if (modulus < Verylong::zero)
   {
      std::cerr << "Error: make_representant() with negative modulus" << std::endl;
      return Verylong::zero;
   }
   else if (modulus == Verylong::zero)
   {
      return value;
   }
   else
   {
      if (value >= Verylong::zero)
         return value % modulus;
      else
         return -(abs(value) % modulus) + modulus;
   }
}

Residue::Residue()
{
    this->modulus = Verylong::zero;
    this->representant = Verylong::zero;
}

Residue::Residue(const Verylong& value)
{
   this->modulus = Verylong::zero;
   this->representant = value;
}

Residue::Residue(const Residue& residue)
{
   this->modulus = residue.modulus;
   this->representant = residue.representant;
}

Residue::Residue(const Verylong& modulus, const Verylong& value)
{
   this->modulus = modulus;
   this->representant = Residue::make_representant(value, modulus);
}

Residue::Residue(int modulus, int value)
{
   const Verylong modulus_verylong(modulus);
   const Verylong value_verylong(value);
   this->modulus = modulus_verylong;
   this->representant = Residue::make_representant(value_verylong, modulus_verylong);
}

Residue::Residue(const Verylong& modulus, int value)
{
   const Verylong value_verylong(value);
   this->modulus = modulus;
   this->representant = Residue::make_representant(value_verylong, modulus);
}

Residue::Residue(int modulus, const Verylong& value)
{
   const Verylong modulus_verylong(modulus);
   this->modulus = modulus_verylong;
   this->representant = Residue::make_representant(value, modulus_verylong);
}

Residue::~Residue() { }

Residue::operator int() const
{
   return representant;
}

Residue::operator string () const
{
   return representant;
}

// Various member operators

const Residue & Residue::operator = (const Residue &rhs)
{
   if(this == &rhs) return *this;

   this->modulus = rhs.modulus;
   this->representant = rhs.representant;

   return *this;
}

// Unary - operator
Residue Residue::operator -() const
{ return Residue(this->modulus, -this->representant); }

// Prefix increment operator
Residue Residue::operator ++ ()
{ return *this = *this + Residue(this->modulus, Verylong::one); }

// Postfix increment operator
Residue Residue::operator ++ (int)
{
   Residue result(*this);
   *this = *this + Residue(this->modulus, Verylong::one);
   return result;
}

// Prefix decrement operator
Residue Residue::operator -- ()
{ return *this = *this - Residue(this->modulus, Verylong::one); }

// Postfix decrement operator
Residue Residue::operator -- (int)
{
   Residue result(*this);
   *this = *this - Residue(this->modulus, Verylong::one);
   return result;
}

Residue Residue::operator += (const Residue &v)
{
   if (this->modulus == Verylong::zero || v.modulus == Verylong::zero || this->modulus == v.modulus)
   {
      return *this = *this + v;
   }
   else
   {
      cerr << "Error: Different modulus in residue number objects" << endl;
      return *this;
   }
}

Residue Residue::operator -= (const Residue &v)
{
   if (this->modulus == Verylong::zero || v.modulus == Verylong::zero || this->modulus == v.modulus)
   {
      return *this = *this - v;
   }
   else
   {
      cerr << "Error: Different modulus in residue number objects" << endl;
      return *this;
   }
}

Residue Residue::operator *= (const Residue &v)
{
   if (this->modulus == Verylong::zero || v.modulus == Verylong::zero || this->modulus == v.modulus)
   {
      return *this = *this * v;
   }
   else
   {
      cerr << "Error: Different modulus in residue number objects" << endl;
      return *this;
   }
}

Residue Residue::operator /= (const Residue &v)
{
   if (this->modulus == Verylong::zero || v.modulus == Verylong::zero || this->modulus == v.modulus)
   {
      return *this = *this / v;
   }
   else
   {
      cerr << "Error: Different modulus in residue number objects" << endl;
      return *this;
   }
}

Residue Residue::operator %= (const Residue &v)
{
   if (this->modulus == Verylong::zero || v.modulus == Verylong::zero || this->modulus == v.modulus)
   {
      return *this = *this % v;
   }
   else
   {
      cerr << "Error: Different modulus in residue number objects" << endl;
      return *this;
   }
}

// Various friendship operators and functions.

Residue operator + (const Residue &u,const Residue &v)
{
   Verylong result_modulus;
   if (u.modulus == v.modulus)
   {
      result_modulus = u.modulus;
   }
   else if (u.modulus == Verylong::zero)
   {
      result_modulus = v.modulus;
   }
   else if (v.modulus == Verylong::zero)
   {
      result_modulus = u.modulus;
   }
   else
   {
      cerr << "Error: Different modulus in residue number objects" << endl;
      return Residue::zero;
   }
   return Residue(result_modulus, Residue::make_representant((u.representant + v.representant), result_modulus));
}

Residue operator - (const Residue &u,const Residue &v)
{
   Verylong result_modulus;
   if (u.modulus == v.modulus)
   {
      result_modulus = u.modulus;
   }
   else if (u.modulus == Verylong::zero)
   {
      result_modulus = v.modulus;
   }
   else if (v.modulus == Verylong::zero)
   {
      result_modulus = u.modulus;
   }
   else
   {
      cerr << "Error: Different modulus in residue number objects" << endl;
      return Residue::zero;
   }
   return Residue(result_modulus, Residue::make_representant((u.representant - v.representant), result_modulus));
}

Residue operator * (const Residue &u,const Residue &v)
{
   Verylong result_modulus;
   if (u.modulus == v.modulus)
   {
      result_modulus = u.modulus;
   }
   else if (u.modulus == Verylong::zero)
   {
      result_modulus = v.modulus;
   }
   else if (v.modulus == Verylong::zero)
   {
      result_modulus = u.modulus;
   }
   else
   {
      cerr << "Error: Different modulus in residue number objects" << endl;
      return Residue::zero;
   }
   return Residue(result_modulus, Residue::make_representant((u.representant * v.representant), result_modulus));
}

Residue operator / (const Residue &u,const Residue &v)
{
   Verylong result_modulus;

   if (u.modulus == v.modulus && u.modulus == Verylong::zero)
   {
      cerr << "Error: Residue remainder can't be calculated when both operand's modulus is 0" << endl;
      return Residue::zero;
   }
   else if (u.modulus == v.modulus)
   {
      result_modulus = u.modulus;
   }
   else if (u.modulus == Verylong::zero)
   {
      result_modulus = v.modulus;
   }
   else if (v.modulus == Verylong::zero)
   {
      result_modulus = u.modulus;
   }
   else
   {
      cerr << "Error: Different modulus in residue number objects" << endl;
      return Residue::zero;
   }

   Verylong counter = Verylong::one;
   while (counter % v.representant != Verylong::zero)
      counter += result_modulus;
   const Verylong v_inverse = counter / v.representant;

   return Residue(result_modulus, Residue::make_representant((u.representant * v_inverse), result_modulus));
}

Residue operator % (const Residue &u,const Residue &v)
{
   Verylong result_modulus;

   if (u.modulus == v.modulus && u.modulus == Verylong::zero)
   {
      cerr << "Error: Residue remainder can't be calculated when both operand's modulus is 0" << endl;
      return Residue::zero;
   }
   else if (u.modulus == v.modulus)
   {
      result_modulus = u.modulus;
   }
   else if (u.modulus == Verylong::zero)
   {
      result_modulus = v.modulus;
   }
   else if (v.modulus == Verylong::zero)
   {
      result_modulus = u.modulus;
   }
   else
   {
      cerr << "Error: Different modulus in residue number objects" << endl;
      return Residue::zero;
   }

   return Residue(result_modulus, Residue::make_representant((u.representant % v.representant), result_modulus));
}

int operator == (const Residue &u,const Residue &v)
{ return u.representant == v.representant; }

int operator != (const Residue &u,const Residue &v)
{ return !(u==v); }

int EqualsByModulus(const Residue &u,const Residue &v)
{ return u.modulus == v.modulus && u.representant == v.representant; }

ostream & operator << (ostream &s,const Residue &v)
{
   s << v.representant << " (mod " << v.modulus << ")";
   return s;
}

istream & operator >> (istream &s,Residue &v)
{
   Verylong modulus, value;
   s >> modulus;
   s >> value;
   v = Residue(modulus, value);
   return s;
}

template <> Residue zero(Residue) { return Residue::zero; }
template <> Residue one(Residue) { return Residue::one; }

#undef LIBSYMBOLICCPLUSPLUS

template <> Residue zero(Residue);
template <> Residue one(Residue);

#endif
