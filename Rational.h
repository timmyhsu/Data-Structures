#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
	private :
		int denom ;
		int numer ;
		void simplicity();
		int gcd(int ,int);
		int abs (int);
	public :
	Rational();
	Rational(int);
	Rational(int,int);
	void show();
	~Rational();
	Rational(const Rational&);
	Rational& operator= (const Rational&);
	const Rational operator+(const Rational&);
	const Rational operator+=(const Rational&);
	const Rational& operator*(int);
	const Rational& operator*(const Rational&);
	//Rational operator-(const Rational&);
};

#endif
