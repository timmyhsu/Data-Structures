#include <iostream>
#include "queue.cpp"
#include<stack>
#define N 100000000
using namespace std ;

class node
{
        public :
        int x ;
        int y ;
        int step ;
        node (int a , int b , int c) :x{a},y{b},step{c}{}
        node(){}
};

int main()
{
        int height , width ;
        cin >> height >> width ;
        int **maze = new int* [height + 2] ;

        for (int x = 0 ; x<height + 2 ; ++x )
                maze[x] = new int [width + 2] ;

        for(int x =0 ; x<height+2 ;++x)
        {
                for (int y = 0;y<width+2;++y)
                {
                        maze[x][y] = N ;
                }
        }

        for(int x =1;x<=height;++x)
        {
                for(int y= 1;y<=width;++y)
                {
                        maze[x][y] = -1 ;
                }
        }
        node start ,tail ;
        for (int x = 1 ; x <= height ;++x )
        {
                int fir ;
                char sec ;
                while (cin >> fir && fir != 0 )
                {
                        cin >> sec ;
                        if (sec == 'x') maze[x][fir] = N ;
                        else if (sec == 's') 
                        {
                                start.x = x ; start.y = fir ;start.step = 0 ;
                                maze[x][fir] = 0 ;
                        }
                        else if (sec == 't')
                                tail.x = x ; tail.y = fir ;tail.step = -1 ;
                }
        }

        Queue<node> path (height * width) ;
        path.push(start) ;

        while (!((path.front().x == tail.x) && (path.front().y == tail.y)))
        {
                if ( maze[path.front().x][path.front().y-1] != N && maze[path.front().x][path.front().y-1] == -1) // left
                {
                        node temp (path.front().x ,path.front().y-1,path.front().step+1) ;
                        path.push(temp) ;
                        maze[path.front().x][path.front().y-1] = path.front().step + 1 ;
                }
                if ( maze[path.front().x][path.front().y+1] != N && maze[path.front().x][path.front().y+1] == -1) // right
                {
                        node temp (path.front().x ,path.front().y+1,path.front().step+1) ;
                        path.push(temp) ;
                        maze[path.front().x][path.front().y+1] = path.front().step + 1 ;
                }
                if ( maze[path.front().x-1][path.front().y] != N && maze[path.front().x-1][path.front().y] == -1) // up
                {
                        node temp (path.front().x-1 ,path.front().y,path.front().step+1) ;
                        path.push(temp) ;
                        maze[path.front().x-1][path.front().y] = path.front().step + 1 ;
                }
                if ( maze[path.front().x+1][path.front().y] != N && maze[path.front().x+1][path.front().y] == -1) // down
                {
                        node temp (path.front().x+1 ,path.front().y,path.front().step+1) ;
                        path.push(temp) ;
                        maze[path.front().x+1][path.front().y] = path.front().step + 1 ;
                }

                path.pop();
        }
        tail = path.front() ;
        int x = tail.x ,y = tail.y ;
        node arr [tail.step+1] = {} ;
        arr[tail.step] = tail ;
        for (int i = tail.step -1 ; i >=0 ; --i)
        {
                if ( maze[x+1][y] == i) 
                {
                        node temp (x+1,y,i) ;
                        arr[i] = temp ; ++x; 
                }
                else if ( maze[x][y+1] == i)
                {       
                        node temp (x,y+1,i) ;
                        arr[i] = temp  ; ++y ;
                }
                else if ( maze[x-1][y] == i) 
                {
                        node temp (x-1,y,i) ;
                        arr[i] = temp  ; --x ;
                }
                else if ( maze[x][y-1] == i) 
                {
                        node temp (x,y-1,i) ;
                        arr[i] = temp  ; --y ;
                }
        }

        for (int i = 0 ; i<=tail.step ;++i)
        {
                cout << "(" << arr[i].x << "," << arr[i].y << ")" << endl ;
        }


}

