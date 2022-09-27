#include<iostream>
#include<stack>
#include<string.h>
#include<set>
#define WEEK 7
#define ORIGIN 1600
using namespace std ;

class Date {

        friend Date& operator + ( Date& , int  );
        friend int operator - ( Date& , Date& );
        friend ostream& operator << (ostream& , Date& );
        private :
                set<int> small {2,4,6,9,11};
                set<int> big {0,1,3,4,7,8,10,12};
                int arr[3] = {0};
                // int cardin [12] = {2,5,0,3,5,1,4,6,2,4,0,3};
                const string month[13] = {"  ","January" ,"February","March","April","May","June","July","August","September","October","November","December"};
                const string week[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" } ;
                bool leap (const unsigned int a ) const
                {
                        if ( (a%4==0 && a%100!=0)|| a%400==0)return true ;
                        else return false ;
                }
                bool err () // The function is to prevent the wrong seetings of date 
                {
                        if ( leap(this->arr[0]) && this->arr[1] == 2 && this->arr[2]==29) return false ;
                        else if (this->arr[1] ==2 && this->arr[2]>28) return true ;
                        if(small.count(this->arr[1]) && this->arr[2] >= 31 ) return true ;
                        else if(big.count(this->arr[1]) && this->arr[2] >= 32 ) return true ;
                        else false ;
                }
                int ten (int a)
                {
                        int re = 1 ;
                        for(int x = 0;x< a;x++)
                        re *= 10 ;
                        return re ;
                }
                int dayofmonth (int year,int month)
                {
                        if(month == 2 && leap(year)) return 29 ;
                        else if ( month ==2 && !leap(year)) return 28 ;
                        else if (big.count(month)) return 31 ;
                        else return 30 ;
                }
        public :
                Date () = default ;
                Date (string str)
                {
                        str += '/' ;
                        int y = 0;
                        stack <char> calc ;
                        for (auto x : str )
                        {
                                if ( x-'0' >=0 && x-'0' <=9 )
                                calc.push(x) ;
                                else if (!calc.empty() ) 
                                {
                                        for(int x = 0 ; !calc.empty() ;++x)
                                        {
                                                arr[y] += (calc.top()-'0')*ten(x) ;
                                                calc.pop();
                                        }
                                        ++y ; 
                                }
                        }
                        /*for (auto aa:arr)
                                cout << aa << endl; */

                        if (err()) cout << "Error!" << endl ;
                } // Constructor 

                bool operator == (const Date &a )const 
                {
                        if (this->arr[0] == a.arr[0] &&this->arr[1] == a.arr[1] && this->arr[2] == a.arr[2]) return true;
                        else return false ;
                }
                void show (int check = 0 )  const 
                {
                        int cardin [12] = {2,5,0,3,5,1,4,6,2,4,0,3};
                        int tmpy = this->arr[0] ,tmpm = this->arr[1]  ; //temporary year ,month
                        if ( tmpm == 1 || tmpm == 2)
                        {
                                tmpy -=1 ; tmpm += 9 ;
                        }
                        else 
                                tmpm -=3 ;
                        int year ;
                        for( year = ORIGIN ; year < tmpy ; ++year)
                        {
                                for (auto &month : cardin)
                                {
                                        if (leap(year+1))
                                                month += 2 ;
                                        else 
                                                month += 1 ;
                                }
                        }
                        cout << month[this->arr[1]] << " " << this->arr[2] << " , " << this->arr[0]  ;
                        if (check == 1 ) cout << " is " << week[(this->arr[2] + cardin[tmpm])%7]  ;
                }// I would like to use ostream at first , but I can't deal with the bug

};

Date& operator+ (Date &front ,int bck)
{
        if(bck >= 0 )
        {
                // cout << " DDDD "<< endl ;
                front.arr[2] += bck ;
                while (front.arr[2] > front.dayofmonth(front.arr[0] ,front.arr[1]) || front.arr[1] > 12 )
                {
                        if(front.arr[1] >12) 
                        { front.arr[1]-=12 ;front.arr[0] += 1 ;}
                        else 
                        {
                                front.arr[2] -= front.dayofmonth(front.arr[0],front.arr[1]);
                                ++front.arr[1] ;
                        }
                }
        }
        else
        {
                front.arr[2] += bck ;
                while(front.arr[2] <= 0 )
                {
                        front.arr[2] += front.dayofmonth(front.arr[0],front.arr[1]-1) ;
                        --front.arr[1] ;
                        while(front.arr[1] <= 0 )
                        {
                                front.arr[1] += 12 ;
                                --front.arr[0] ;
                        }
                }
        }

        return front ;
}

int operator- (Date &front , Date &bck)
{
        int x = 0 ;
        for( ; ;--x)
        {
                Date temp = front ;
                if(temp + x == bck ) break ; //cout << x << endl ;}
        }
        return -x ;

}
/*ostream& operator << (ostream &os , Date &a)
{
        os << a.arr[0]
}*/
int type (const string a )
{
        for(auto x : a)
        {
                if(x =='+')return 1 ;
                else if (x =='-') return 2 ;
        }
        return 3 ;
}

int ten (int a)
{
      int re = 1 ;
      for(int x = 0;x< a;x++)
        re *= 10 ;
      return re ;
}

int main ()
{
        string temp ;
        int x = 0;
        while ( cin >> temp )
        {
                Date a (temp) ;
                cin >> temp ;
                switch (type(temp))
                {
                        case 1:
                                {
                                        int dayafter ; cin >> dayafter ;
                                        cout << dayafter << " after " ;
                                        a.show() ; cout << " is " ;
                                        (a + dayafter).show();cout << endl ; 
                                        break ;
                                }
                        case 2:
                                 {
                                         string tmp ; cin >> tmp ; Date b(tmp) ;
                                         cout << a-b <<  " days from " ;
                                         a.show() ;
                                         cout <<" to ";
                                         b.show() ;
                                         cout << endl;
                                         break ;
                                 }
                        default :
                                a.show(1); cout << endl ;
                                break ;
                }
        }
}
    
