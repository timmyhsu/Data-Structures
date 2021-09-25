#include<iostream>
#include<charconv>
#include<string.h>
using namespace std ;

class Date {

        private :
                int arr[3] ;
                string month[13] = {"  ","January" ,"February","March","April","May","June","July","August","September","October","November","December"};
        public :
                Date ();
                Date (string str) 
                {
                        char *a = new char [str.length()+1] ;
                        strcpy(a,str.c_str());
                        strcat(a,"/") ;
                        char *start = a , *tail = a ;
                        int x = 0 ;
                        while(*start != '\0')
                        {
                                if(*tail == '/' || *tail == '\0' )
                                {
                                        from_chars(start,tail,arr[x]);
                                        start = tail +1 ;tail += 1;++x ;
                                }
                                ++tail ;
                        }
                }
                void show ()
                {
                        cout << this->month[arr[1]] << " " << this->arr[2] << ", " << this->arr[0] ;
                }

};


int main ()
{
        string temp ;
        while(cin >> temp)
        {
                Date a (temp) ;
                a.show();
        }
}
