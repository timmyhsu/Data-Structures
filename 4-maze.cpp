                                                                                                                                                         1 ⚙
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
        int **maze = new int* [height + 2] ; // made a width+2  * height+2  maze 

        for (int x = 0 ; x<height + 2 ; ++x )
                maze[x] = new int [width + 2] ;

        for(int x =0 ; x<height+2 ;++x) // first , let all of them is -1
        {
                for (int y = 0;y<width+2;++y)
                {
                        maze[x][y] = -1 ;
                }
        }

        for(int x =1;x<=height;++x)
        {
                for(int y= 1;y<=width;++y)
                {
                        maze[x][y] = N ; // second , let the variable in [1 -> height][1 -> width] be N , see it as the path doesn't walk yet 
                }
        }
        node start ,tail ;
        for (int x = 1 ; x <= height ;++x )
        {
                int fir ;
                char sec ;
                while (cin >> fir && fir != 0 ) // input the first number 
                {
                        cin >> sec ; // input the second number and identify it is 'x' ,'s' ,or 't'
                        if (sec == 'x') maze[x][fir] = -1 ;
                        else if (sec == 's') 
                        {
                                start.x = x ; start.y = fir ;start.step = 0 ;
                                maze[x][fir] = 0 ;
                        }
                        else if (sec == 't')
                                tail.x = x ; tail.y = fir ;tail.step = -1 ;
                }
        }

        Queue<node> path (height * width) ; // I create a queue with capacity of height*width 
        path.push(start) ; // push the point if start 

        while (!((path.front().x == tail.x) && (path.front().y == tail.y))) //until the front of queue is equal to the tail 
        {
                if ( maze[path.front().x][path.front().y-1] > maze[path.front().x][path.front().y] && maze[path.front().x][path.front().y-1] != -1) // left
                {
                        node temp (path.front().x ,path.front().y-1,path.front().step+1) ;
                        path.push(temp) ;
                        maze[path.front().x][path.front().y-1] = path.front().step + 1 ;
                }
                if ( maze[path.front().x][path.front().y+1] > maze[path.front().x][path.front().y] && maze[path.front().x][path.front().y+1] != -1) // right
                {
                        node temp (path.front().x ,path.front().y+1,path.front().step+1) ;
                        path.push(temp) ;
                        maze[path.front().x][path.front().y+1] = path.front().step + 1 ;
                }
                if ( maze[path.front().x-1][path.front().y] > maze[path.front().x][path.front().y] && maze[path.front().x-1][path.front().y] != -1) // up
                {
                        node temp (path.front().x-1 ,path.front().y,path.front().step+1) ;
                        path.push(temp) ;
                        maze[path.front().x-1][path.front().y] = path.front().step + 1 ;
                }
                if ( maze[path.front().x+1][path.front().y] > maze[path.front().x][path.front().y] && maze[path.front().x+1][path.front().y] != -1) // down
                {
                        node temp (path.front().x+1 ,path.front().y,path.front().step+1) ;
                        path.push(temp) ;
                        maze[path.front().x+1][path.front().y] = path.front().step + 1 ;
                }

                path.pop();
        }
        // =========the output of the path of the maze ========
        tail = path.front() ; 
        int x = tail.x ,y = tail.y ;
        node arr [tail.step+1] = {} ; // this array is to store the step of the shortest path 
        arr[tail.step] = tail ;
        for (int i = tail.step -1 ; i >=0 ; --i) // this for loop is to store the route from the last point to the start point
        {
                if ( maze[x+1][y] == i) //down
                {
                        node temp (x+1,y,i) ;
                        arr[i] = temp ; ++x; 
                }
                else if ( maze[x][y+1] == i)//right
                {       
                        node temp (x,y+1,i) ;
                        arr[i] = temp  ; ++y ;
                }
                else if ( maze[x-1][y] == i) //up
                {
                        node temp (x-1,y,i) ;
                        arr[i] = temp  ; --x ;
                }
                else if ( maze[x][y-1] == i)  //left
                {
                        node temp (x,y-1,i) ;
                        arr[i] = temp  ; --y ;
                }
        }

        for (int i = 0 ; i<=tail.step ;++i) //output the array that store the shortest path of the maze 
        {
                cout << "(" << arr[i].x << "," << arr[i].y << ")" << endl ;
        }


        // ===============output the maze ===================
        int maze_t[height+2][width+2] ; // temporary maze 
        for (int x =0 ;x< height+2 ;++x ) // initialize the maze all to 0 
        {
                for( int y = 0 ;y < width+2 ; ++y )
                        maze_t[x][y] = 0 ;
        }

        for (int x =0 ;x< height+2 ;++x ) // let the boundary and th e wall be -1 
        {
                for( int y = 0 ;y < width+2 ; ++y )
                        if ( maze[x][y] == -1 ) maze_t[x][y] = -1 ;
        }

        for (int i = 0 ; i<=tail.step ;++i) //output the array that store the shortest path of the maze 
        {
                maze_t[arr[i].x][arr[i].y] = i ;
        }

        for (int x =0 ;x < height +2 ; ++x ) // output the maze 
        {
                for (int y = 0; y < width +2 ;++y )
                {
                        if ( maze_t[x][y] == -1) cout << "x " ;
                        else cout << maze_t[x][y] << " " ;
                }
                cout << endl ;
        }

        // ==============delete the maze ===============
        for (int x = 0 ;x < height +2 ; ++x )
                delete [] maze[x] ;
        delete [] maze ;

}
