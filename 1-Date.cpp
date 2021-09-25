#include<iostream>
#include<charconv>
#include<string.h>
#include<set>
using namespace std ;

class Date {

        private :
                set<int> small {2,4,6,9,11};
                set<int> big {1,3,4,7,8,10,12};
                unsigned int arr[3] ;
                string month[13] = {"  ","January" ,"February","March","April","May","June","July","August","September","October","November","December"}; // I am lazy ,so I write this .

                bool err () // The function is to prevent the wrong seetings of date 
                {
                        if(this->arr[1] ==2 && this->arr[2]>29) return true ; // February 
                        if(small.count(this->arr[1]) && this->arr[2] >= 31 ) return true ; 
                        else if(big.count(this->arr[1]) && this->arr[2] >= 32 ) return true ;
                        else false ;
                }
        public :
                Date ();
                Date (const string str) 
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
                } // Constructor
                void show ()
                {
                        if(err()) cout << "Wrong Input" << endl ;
                        else cout << this->month[arr[1]] << " " << this->arr[2] << ", " << this->arr[0]<< endl  ;
                } // I would like to use ostream at first , but I can't deal with the bug

};


int main ()
{
        string temp ;
        while(cin >> temp) // input the date till EOF , ex: YYYY/MM/DD
        {
                Date a (temp) ;
                a.show(); 
        }
}
