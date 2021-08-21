#include"Rational.h"
#include<iostream>

Rational::Rational(int num):numer{num},denom{1}{}

Rational::Rational(int num ,int den):numer{num},denom{den}{}

void Rational::show()
{
	simplicity();
	if (denom==1)std::cout << numer << std::endl ; 
	else std::cout << numer << "/" << denom ;
}

Rational::~Rational(){}
Rational::Rational():numer{0},denom{1}{}
Rational::Rational(const Rational& a)
{
	*this= a ;
}
int Rational::gcd(int numer ,int denom)
{
	if (denom == 0 ) return numer ;	
	return gcd(denom,numer%denom);
}
void Rational::simplicity()
{
	bool negative = (numer*denom<0);
	numer = abs(numer) ; denom = abs(denom);
	int g = gcd(numer,denom);
	denom /= g ;
	numer = negative ? -numer : numer ;
	numer/=g ;
}
int Rational::abs(int a)
{
	return (a>0 ? a :-a);
}
Rational& Rational::operator=(const Rational &a )
{
	numer = a.numer ;
	denom = a.denom ;
	return *this ;
}
const Rational Rational::operator+(const Rational &other)
{
	Rational temp {1};
	temp.numer = numer * other.denom + denom * other.numer;
	temp.denom = denom * other.denom;
	return temp ;
}
const Rational Rational::operator+=(const Rational &a)
{
	Rational temp = *this + a ;
	return temp ;
}
/*Rational Rational::operator-(const Rational &a)
{
	Rational temp = *this + a*(-1);
	return temp ;
}*/
const Rational& Rational::operator*(int a)
{
	numer = numer * a ;
	simplicity ();
	return *this ;
}
const Rational& Rational::operator*(const Rational& a)
{
	numer = numer * a.numer ;
	denom = denom * a.denom ;
	return *this ;

}


