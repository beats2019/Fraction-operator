#include "RationalNumber.h"
#include <cmath>
#include <iostream>
using namespace std;

    RationalNumber::RationalNumber( int n, int d )
    {
        if( d != 0 )
        {
            adjustFraction( n, d );
            numerator = n;
            denominator = d;

        }else
            throw out_of_range("Div by 0 undefined");
    }

   RationalNumber::~RationalNumber()
    {

    }

    void RationalNumber::adjustFraction( int &n1, int &n2 )
    {

         int value = gcd( n1 , n2 );

         n1 /= value;//Reduce fraction
         n2 /= value;

         if( n2 < 0 and n1 > 0) // avoids negative denominators
         {
             n1 *= -1;
             n2 = abs( n2 );
         }

    }

    int RationalNumber:: gcd(int a, int b)
    {
       if (b == 0)
          return a;
       return gcd(b, a % b);
    }
/////////////////////////////SUM OPERATOR ( + ) ///////////////////////////////////////////
    RationalNumber RationalNumber::operator +( const RationalNumber &n2 ) const
    {
        RationalNumber temp;

        temp.numerator = (this->numerator * n2.denominator) + ( this->denominator * n2.numerator );
        temp.denominator = this->denominator * n2.denominator;

        return temp;

    }

    RationalNumber RationalNumber::operator +( const int n ) const
    {
        RationalNumber temp;

        temp.numerator = this->numerator  + ( this->denominator * n);
        temp.denominator = this->denominator;

        return temp;

    }
/////////////////////////////DIFFERENCE OPERATOR ( - ) ///////////////////////////////////////////
    RationalNumber RationalNumber::operator -( const RationalNumber &n2 ) const
    {
        RationalNumber temp;

        temp.numerator = (this->numerator * n2.denominator) - ( this->denominator * n2.numerator );
        temp.denominator = this->denominator * n2.denominator;

        return temp;

    }

    RationalNumber RationalNumber::operator -( const int n ) const
    {
        RationalNumber temp;

        temp.numerator = this->numerator  - ( this->denominator * n);
        temp.denominator = this->denominator;

        return temp;

    }
/////////////////////////////MULTIPLICATION OPERATOR ( * ) ///////////////////////////////////////////

    RationalNumber RationalNumber::operator *( const RationalNumber &n2 ) const
    {
        RationalNumber temp;

        int num = this->numerator * n2.numerator;
        int den = this->denominator * n2.denominator;

        temp.numerator = num;
        temp.denominator = den;

        return temp;
    }

    RationalNumber RationalNumber::operator *( const int n ) const
    {
        RationalNumber temp;

        int num = this->numerator  * n ;
        int den = this->denominator;

        temp.adjustFraction( num, den );

        temp.numerator = num;
        temp.denominator = den;

        return temp;

    }
/////////////////////////////DIVISION OPERATOR ( * ) ///////////////////////////////////////////

    RationalNumber RationalNumber::operator /( const RationalNumber &n2 ) const
    {
        RationalNumber temp;

        int num = this->numerator * n2.denominator;
        int den = this->denominator * n2.numerator;

        temp.numerator = num;
        temp.denominator = den;

        return temp;
    }

    RationalNumber RationalNumber::operator /( const int n ) const
    {
        RationalNumber temp;

        int num = this->numerator;
        int den = this->denominator * n;

        temp.adjustFraction( num, den );

        temp.numerator = num;
        temp.denominator = den;

        return temp;

    }

    /////////////////////////////RELATIONAl OPERATORS/////////////////////////////////////////////

    bool RationalNumber::operator ==( const RationalNumber &n2 ) const
    {
        if( this->numerator == n2.numerator and this->denominator == n2.denominator )
            return true;
        else
            return false;
    }

    bool RationalNumber::operator !=( const RationalNumber &n2 ) const
    {
        if( this->numerator != n2.numerator or this->denominator != n2.denominator )
            return true;
        else
            return false;
    }




  /////////////////////////////OUTPUT/////////////////////////////////////////////
    ostream &operator <<( ostream &output, const RationalNumber &a )
    {
        output << a.numerator;

        if( a.denominator != 1 )
            cout << " / " << a.denominator << endl;
        if( a.denominator == 0 )
            throw out_of_range("Zero is a non valid denominator");

        return output;
    }













