#include "sparsePoly.h"
#include<iostream>
std::ostream&  operator<< (std::ostream& os ,const sparsePoly &a)
{
	for (auto x =0 ;x < a.__nonum ;++x )
	{
		os << a.__nonarr[x].__coef << "^" << a.__nonarr[x].__exp << "\n";  
	}
	return os ;
}
		for (;runexpa < __nonum; ++runexpa)
		{
			res.addnonzero( __nonarr[runexpa].__coef , __nonarr[runexpa].__exp) ;
		}
		for (;runexpb < __nonum; ++runexpb)
		{
			res.addnonzero( b.__nonarr[runexpb].__coef , b.__nonarr[runexpb].__exp) ;
		}
	}
	return res ;ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
}

sparsePoly::sparsePoly (int nonzeronum)
{
	__nonarr = new nonzero [nonzeronum] ;
	__nonum = 0;
}
//sparsePoly::sparsePoly (){}
sparsePoly::sparsePoly (int* arr ,int nonzeronum)
{
	__nonarr = new nonzero [nonzeronum] ;
	__nonum = 0;
	for (auto x = 0;x < nonzeronum ;++x)
	{
		__nonarr[x].__coef = arr[2*x];
		__nonarr[x].__exp = arr[2*x+1];
		++__nonum ;
	}
}

sparsePoly::~sparsePoly ()
{
	delete [] __nonarr ;
}

void sparsePoly::addnonzero (int co ,int expe )
{
	__nonarr[__nonum].__coef = co ;
	__nonarr[__nonum].__exp = expe ;
	++__nonum ;
}
