#include<iostream>
#include<random>
#include<time.h>
#include<vector>
#include<stdio.h>
using namespace std ;
typedef int T ;
//template <class T>

class Sort{

        //typedef struct 
                // friend void quick(Sort&,int,int) ;
        private:
                vector <T> arr {} ;
                unsigned int size ;
                double cputime [5] ;
                string name[5] = {"Insertion" ,"Selection" ,"Quick     ","Merge     ","Heap     "} ;
                void swap (T &a,T &b)
                {
                        int temp = a ;
                        a = b ;
                        b = temp ;
                }
                vector<T> merge (vector<T>& vec ,int l1,int r1, vector<T>& vec2, int l2,int r2)
                {
                        int i = l1 ,j = l2,k = l1;
                        vector<T> temp {} ;
                        while((i<=r1) && (j <= r2))
                        {
                                if(vec[i] < vec2[j])
                                {
                                        temp.push_back(vec[i]); ++i ;
                                }
                                else
                                {
                                        temp.push_back(vec[j]); ++j ;
                                }
                                ++k ;
                        }
                        while (i<=r1) 
                        {
                                temp.push_back(vec[i]); ++i ; ++k ;
                        }
                        while (j<= r2)
                        {
                                temp.push_back(vec[j]) ; ++j ;++k ;
                        }
                        return temp ;
                }
                void displit (vector<T>& vec ,int l ,int r )
                {
                        if (l<r)
                        {
                                int mid =(l+r)/2 ;
                                displit(vec ,l,mid) ;
                                displit(vec,mid+1,l);
                                auto tempvec = merge( vec ,l,mid,vec,mid+1,r);
                                vec.assign(tempvec.begin(),tempvec.end());
                        }

                }
                void sift (vector<T> vec,int r ,int n)
                {
                        int i = r ,j = 2*i ,x = vec[i] ;
                        while(j<=n)
                        {
                                if(j<n)
                                        if(vec[j] < vec[j+1])++j ;
                                if(x >=vec[j]) break ;
                                vec[i] = vec[j] ;i = j;j = 2*i ;
                        }
                        vec[i] = x ;
                }
        void quick (vector<T>& vec , int l ,int r)
        {
                int i = l ,j = r ;
                int temp = vec[l+1] ;
                while (i <=j)
                {
                        while(vec[i] < temp) ++i ;
                        while(vec[j] > temp) --j ;
                        if (i<=j) 
                        {
                                swap(vec[i], vec[j]);
                                ++i ,--j ;
                        }

                }
                if (l<j) quick(vec,l,j) ;
                if(i<r) quick(vec,i,r) ;
        }

        public:
                Sort (int siz)
                {
                        size = siz ;
                        cout << "--------------------------------\t" << endl ;
                        cout << "|\tName \t" ;
#ifdef DEBUG
                        cout << "|\tvalue \t|" << endl  ;
#else 
                        cout << "|\tcputime\t| " << endl ;
#endif 
                        cout << "--------------------------------\t" << endl ;
                        for ( int x = 0; x<5 ;++x)
                        {
                                cout << "|" <<name[x] << "\t" ;
                                srand(1);
#ifdef DEBUG
                                cout << "\tOriginal value:\t" << endl ; 
#endif
                                for (int x = 0; x<size ; ++x)
                                {
                                        arr.push_back(rand()) ;
#ifdef DEBUG
                                        cout <<"|\t\t|" << arr[x] << "|" << endl ;
#endif 
                                }
                                switch (x) 
                                {
                                        case 0 :
                                                insertion(); break ;
                                        case 1 :
                                                selection(); break;
                                        case 2 :
                                                quicksort(); break ;
                                        case 3 :
                                                mergesort(); break;
                                        case 4 :
                                                heap(); break ;
                                }
                        }

                        cout << "--------------------------------\t" << endl ;
                }
                void insertion ()
                {
                        clock_t start ,finish ;
                        start = clock() ;
                        for (int x = 1; x < size ;++x )
                        {
                                for(int y = x - 1 ;y>=0; --y )
                                {
                                        if (arr[y+1] >  arr[y])
                                                break ;
                                        swap(arr[y+1],arr[y]) ;
                                }
                        }
                        finish = clock () ;
                        cputime[0] = (double)(finish - start) / CLOCKS_PER_SEC;
#ifdef DEBUG
                        this->show() ;
#else 
                        //cout << "|\t" << cputime[0] <<"\t|" << endl ; 
                        printf ("|\t%.4f\t|\n",cputime[0]) ;
#endif
                }
                void selection()
                {
                        clock_t start ,finish ;
                        start = clock() ;
                        for (int x = 0; x < size; ++x )
                        {
                                int temp = arr[x] ;
                                int index = x ;
                                for ( int y = x+1 ;y < size ;++y)
                                        if ( temp > arr[y]) index = y ;
                                swap(arr[x],arr[index]) ;
                        }
                        finish = clock () ;
                        cputime[1] = (double)(finish - start) / CLOCKS_PER_SEC;
#ifdef DEBUG
                        this->show() ;
#else 
                        //cout << "|\t" << cputime[1] <<"\t|" << endl ; 
                        printf ("|\t%.4f\t|\n",cputime[1]) ;
#endif
                }
                void quicksort()
                {
                        clock_t start ,finish ;
                        start = clock() ;
                        quick(arr,0,size) ; // sorting 
                        finish = clock () ;
                        cputime[2] = (double)(finish - start) / CLOCKS_PER_SEC;
#ifdef DEBUG
                        this->show() ;
#else 
                        //cout << "|\t" << cputime[2] <<"\t|" << endl ; 
                        printf ("|\t%.4f\t|\n",cputime[2]) ;
#endif
                }
                void mergesort ()
                {
                        // T *temparr = new T [size] ;
                        //for (int x = 0; x<size ; ++x)
                        //      temparr[x] = arr[x] ;
                        clock_t start ,finish ;
                        start = clock() ;
                        displit(arr ,0,size);
                        finish = clock () ;
                        cputime[3] = (double)(finish - start) / CLOCKS_PER_SEC;
#ifdef DEBUG
                        this->show() ;
#else 
                        //cout << "|\t" << cputime[3] <<"\t|" << endl ; 
                        printf ("|\t%.5f\t|\n",cputime[3]) ;
#endif
                }
                void heap()
                {
                        clock_t start ,finish ;
                        start = clock() ;
                        int r = size/2;
                        while (r>0)
                        {
                                sift(arr,r,size) ;
                                --r ;
                        }
                        int m = size;
                        while (m>0)
                        {
                                swap(arr[1],arr[m]) ; m-=1 ;
                                sift(arr,0,m) ;
                        }
                        finish = clock () ;
                        cputime[4] = (double)(finish - start) / CLOCKS_PER_SEC;
#ifdef DEBUG
                        this->show() ;
#else 
                        //cout << "|\t" << cputime[4] <<"\t|" << endl ; 
                        printf ("|\t%.4f\t|\n",cputime[4]) ;
#endif
                }

                void show()
                {
                        for(auto x : arr)
                                cout << x << endl ;
                }

};



int main()
{
        int input ;
        while( cin >> input )
        {
                Sort a(input) ;
        }
}
