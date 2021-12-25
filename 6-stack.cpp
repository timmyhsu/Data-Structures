#include<iostream>
template <class T >
class stack
{
        private:
                T* arr ;
                int front = -1 ;
                int siz ;
        public:
                stack()
                {
                        arr = new T [100] ;
                        siz = 100 ;
                }
                bool isEmpty()
                {
                        if (front == -1) return true ;
                        return false ;
                }
                int size()
                {
                        return (front + 1) ;
                }
                T top()
                {
                        if (isEmpty()) std::cout << "Emptytop" << std::endl ;
                        return arr[front] ;
                }
                void push(T inp)
                {
                        if(front+1 == siz) std::cout << "Full" <<std::endl ;
                        else 
                        {
                                ++front ;
                                arr[front] = inp ;
                        }
                }
                void pop()
                {
                        if (isEmpty())std::cout << "Emptypop" ;
                        else
                        {
                                --front ;
                        }
                }

};
   
