#include<iostream>
using namespace std ;

template <class T> //the template
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
                        if (tag && rear == first) // when tag is true and rear == first , it's full
                                std::cout << "Full!" << std::endl ;
                        else
                        {
                                rear = (rear + 1) % size ;
                                arr[rear] = inp ;
                                if (rear == first) tag = true ; // after rear +1 , if rear == first ,we have to let tag be true 
                                                                // because when tag is true ,and rear == first ,it's full .
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
