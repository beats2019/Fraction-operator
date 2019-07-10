#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H
#include <iostream>
using namespace std;

class RationalNumber
{
    friend ostream &operator <<( ostream &, const RationalNumber & );

    public:
        RationalNumber( int = 1, int = 1);
        ~RationalNumber();
        void adjustFraction( int &n1, int &n2 );
        int gcd(int a, int b);
        RationalNumber operator +( const RationalNumber & ) const;
        RationalNumber operator +( const int ) const;

        RationalNumber operator -( const RationalNumber & ) const;
        RationalNumber operator -( const int ) const;

        RationalNumber operator *( const RationalNumber & ) const;
        RationalNumber operator *( const int ) const;

        RationalNumber operator /( const  RationalNumber& ) const;
        RationalNumber operator /( const int ) const;

        bool operator ==( const RationalNumber & ) const;
        bool operator !=( const RationalNumber & ) const;




    private:
        int numerator;
        int denominator;
};

#endif // RATIONALNUMBER_H
