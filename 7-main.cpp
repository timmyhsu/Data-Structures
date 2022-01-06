#include<iostream>
#include<fstream>
#include"node.cpp"
#include<bitset>
#define N 99999999
using namespace std ;

void traversal (node *tree ,unsigned int value) //give the code to every node by recursive function
{
        tree->code = value ;
        if(tree->left) traversal(tree->left ,value << 1 ) ;
        if(tree->right) traversal(tree->right,(value << 1) +1);
}

int main()
{
        fstream file ,file2;
        file.open("read.txt",ios::in);
        file2.open("read.txt",ios::in);
        if (!file) cout << "Open Denied!" << endl ;

        node *arr = new node [256];// create an array that is souble to the capacity of ascii code 
        string input ;
        int zero = 0 ;
        while(getline(file,input)) // get every line
        {
                for(auto x : input)
                {
                        arr[x].alph = x ;
                        ++arr[x].freq ; //get the times of alphabat 
                }
                ++ arr[10].freq ; //arr[10] is newline 
        }
        for (int x = 0 ;x < 256;++x)
        {
                unsigned int &temp = arr[x].freq ; // give N to the node.freq if it's zero .
                if (temp == 0)
                        temp = N ;
                else ++zero ;
        }
        arr[10].alph = '\x0a' ; //give arr[10] be newline

        for (int x = 128 ; x < 128+zero-1 ; ++x ) //create a tree ,and the root is at arr[128+zero-2]
        {
                int count = 0 ;
                node min[2] ; // let min[0] min[1] be the two minimum freq in arr
                min[0].freq = min[1].freq = N ;
                for (int y = 0 ,stop = 0 ; y <= x && count < 2  ;++y )
                {
                        if ( y == x ) { ++count ;arr[stop].freq = N ;y = -1 ; continue ;}
                        if ( min[count].freq >= arr[y].freq )
                        {
                                min[count].freq = arr[y].freq ;
                                min[count].left = &arr[y] ;
                                stop = y ;
                        }
                }
                count = 0 ;
                arr[x].freq = min[0].freq + min[1].freq ;
                arr[x].left = min[0].left ;
                arr[x].right = min[1].left ;
        }


        traversal ( &arr[128+zero-2] , 1 ) ; //use recursive to give code to nodes .

        /*for (int x = 97 ; x <= 122 ; ++x )
        {
                bitset<11>bs2(arr[x].code) ;
                cout << (char)x << ":" << bs2 << endl ;
        }

        bitset<11>bs2(arr['I'].code) ;
        cout << "I: " << bs2 ;*/

        ofstream out("binary.txt",ios::binary); // create a binary file
        string inp ;
        while(getline(file2,inp))
        {
                for(auto x : inp)
                {
                        unsigned int temp = 1 << 31 ;
                        while(!(temp & arr[x].code)) 
                        {
                                temp >>= 1 ;
                        }
                        while (temp)
                        {
                                if (temp & arr[x].code) out.put('1');
                                else out.put('0') ;
                                temp >>= 1 ;
                        }
                }
                // It's give the newline to the file 
                unsigned int temp = 1 << 31 ; 
                while(!(temp & arr[10].code)) temp >>= 1 ;
                while (temp)
                {
                        if (temp & arr[10].code) out.put('1');
                        else out.put('0') ;
                        temp >>= 1 ;
                }
        }
        out.close();
        //================decode========================
        ifstream in("binary.txt",ios::binary);
        char ch ;
        while(in)
        {
                in.get(ch) ;
                node *temp = &arr[128+zero-2];
                while(temp->left != nullptr  && temp->right != nullptr )
                {
                        in.get(ch);
                        if(ch=='1')temp = temp->right ;
                        else temp = temp -> left ;
                }
                cout << temp->alph  ;
        }
        in.close();
}
