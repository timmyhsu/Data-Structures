#ifndef SPARSE_H
#define SPARSE_H
#include<iostream>
class nonzero
{
	public :
	friend class sparsePoly ;
	friend class ostream;
		int __coef ;
		int __exp ;

};
class sparsePoly
{
	private:
		int __nonum;
		int __degree ;
		nonzero *__nonarr ;
	public :
		sparsePoly () = default;
		sparsePoly (int);
		sparsePoly (int*,int);
		~sparsePoly();
		sparsePoly operator+ (sparsePoly);
		void addnonzero (int ,int);
		friend std::ostream& operator<<(std::ostream& ,const sparsePoly& ) ;

};




#endif 
