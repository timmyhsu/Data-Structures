#include <iostream>
#include "sparsePoly.h"
using namespace std ;

int main ()
{
	int arr[6] = {1,4,2,2,3,0};
	sparsePoly a {arr,3};
	sparsePoly b {arr,3};
	sparsePoly c (a +b) ;
	cout << c << endl ;

}
