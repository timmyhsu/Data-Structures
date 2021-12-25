#include <iostream>
#include "matrix.cpp"
using namespace std ;


sparseMatrix in(char a)
{
        int height ,width ;
        cout << "Please input Matrix " << a << " :\n height and width ?" << endl ;
        cin >> height >> width ;
        cout << "input the nonzero element :" <<endl ;
        sparseMatrix temp(height,width);
        for ( int x =0 ;x < height;++x)
        {
                int column , coef ;
                while ( cin >> column && column != 0 )
                {
                        cin >> coef ;
                        temp.push( x , column-1 , coef ) ;
                }
        }
        return temp ;
}
int main()
{

        sparseMatrix A = in('A') ; 
        sparseMatrix B = in('B') ;
        cout << "A's transpose" << endl ;
        A.T().show();
        cout << "B's transpose" << endl ;
        cout << "A+B = " << endl ;
        (A+B).show();
        cout << "A*B = " << endl ;
        (A*B).show() ;
}
