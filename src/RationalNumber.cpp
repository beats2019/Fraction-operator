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
        cout << "Object deleted";
    }

    void RationalNumber:: adjustFraction( int &n1, int &n2 )
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

     RationalNumber RationalNumber::operator +( const RationalNumber &n2 ) const
    {
        RationalNumber temp;

        temp.numerator = (this->numerator * n2.denominator) + ( this->denominator * n2.numerator );
        temp.denominator = this->denominator * n2.denominator;

        return temp;

    }

    RationalNumber RationalNumber::operator +( const int n2, const int d2 ) const
    {
        RationalNumber temp;

        temp.numerator = (this->numerator * d2 ) + ( this->denominator * n2);
        temp.denominator = this->denominator * d2;

        return temp;

    }



    ostream &operator <<( ostream &output, const RationalNumber &a )
    {
        output << a.numerator << " / " << a.denominator;
        return output;
    }













