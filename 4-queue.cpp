#include<iostream>
using namespace std ;

template <class T>
class Queue 
{
        private:
                T *arr ;
                unsigned int first = 0 ,rear = 0 ,size ;
                bool tag = false ;
        public:
                Queue (int siz)
                {
                        size = siz ;
                        arr = new T [size] ;
                }
                void push(T inp)
                {
                        if (tag && rear == first)
                                std::cout << "Full!" << std::endl ;
                        else
                        {
                                rear = (rear + 1) % size ;
                                arr[rear] = inp ;
                                if (rear == first) tag = true ;
                        }

                }
                void pop()
                {
                        if (isEmpty()) 
                                std::cout << "Empty!" << std::endl ;
                        else 
                        {
                                tag = false ;
                                first = (first + 1) % size ;
                        }

                }
                bool isEmpty()
                {
                        if (rear == first && !tag )
                                return true ;
                        return false ;
                }

                T front ()
                {
                        if(isEmpty()) cout << "Empty" << endl ;
                        return arr[first + 1 ] ;
                }
                T back ()
                {
                        return arr[rear] ;
                }
};
