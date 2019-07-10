#include <iostream>
using namespace std;
#include "RationalNumber.h"

    int main()
    {
        RationalNumber n1( 28 , 5 );
        RationalNumber n2(  136 , 5 );

        if( n1 != n2 )
            cout << "DIFF";
        else
            cout << "SAME";


        return 0;
    }
