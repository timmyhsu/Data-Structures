// template < class T >
#include <iostream> 
using namespace std ;

class row ;
class sparseMatrix ;
class node
{
        public:
                friend class row ;
                friend class sparseMatrix ;
                double coef ;
                unsigned int column ;
                node *next ;
                node() : next{nullptr}{}
};

class row 
{
        friend class sparseMatrix ;
        private :
                // node<T> *arr ;
                node  *first ;
                int size ;
                bool isEmpty ()
                {
                        if (this->first == nullptr)
                                return true ;
                        return false ;
                }
                void insert (const unsigned int column ,const double coef) //To insert node simply and efficiently , I devided into three case .
                {
                        if(isEmpty()) // first case ,if the row is empty ,I'll add the node ,and the pointer first point to new node 
                        {
                                node *newNode = new node ;
                                first = newNode ;
                                first->next = nullptr ;
                                first->column = column ; first->coef = coef ;
                        }
                        else if (column < first->column) // when I want to insert the element that is in front of the pointer first 
                                                         // , I'll create a node ,and let the new node be the first .
                        {
                                node *newNode = new node ;
                                newNode->next  = first; 
                                newNode->column = column ; newNode->coef = coef ;
                        }
                        else // this case is that if two cases above aren't available ,it run this area is ok .
                        {
                                node *step = first ;
                                if(first->next != nullptr)
                                {
                                        while(step->next->column < column && step->next != nullptr )
                                        {step = step->next ;
                                                if (step->next ==nullptr) break ;}
                                }
                                node *newNode = new node ;
                                newNode->next = step->next ;
                                step->next = newNode ;
                                newNode->column = column ; newNode->coef = coef ;
                        }
                }
                /*void insert (const unsigned int column ,const double coef)
                {
                        ++size ;
                        //cout <<"column :" << column << "coef:"<<coef <<"sum:" << size << endl ;
                        if(isEmpty())
                        {
                                node *newNode = new node ;
                                first = newNode ;
                                first->next = nullptr ;
                                first->column = column ; first->coef = coef ;
                        }
                        else 
                        {
                                node *newNode = new node ;
                                node *step = first ; 
                                while (step->next != nullptr)
                                        step = step->next ;
                                step->next = newNode ;
                                step->next->column = column ; step->next->coef = coef ;
                        }
                }*/
        public: 
                row()
                {
                        first = nullptr;
                }
};

class sparseMatrix 
{
        private :
                int height ,width ;
                row *arr ;
                sparseMatrix transpose() // the member function to transpose the metrix .
                {
                        sparseMatrix temp (width,height); // swap the height and width
                        for (int x = 0; x<height;++x)
                        {
                                node *step = arr[x].first ;
                                while (step != nullptr)
                                {
                                        temp.push(step->column,x,step->coef); //swap column to row
                                        step = step->next ;
                                }
                        }
                        return temp ;
                }
        public :
                sparseMatrix(int ro = 0 ,int col = 0) // constructor
                {
                        height = ro ; width = col ;
                        arr = new row [height] ;
                }

                void push (const unsigned int raw ,const unsigned int column ,const double coef) // I can directly insert node to the matrix by the member function .
                {
                        this->arr[raw].insert(column,coef);
                }
                sparseMatrix operator+ (const sparseMatrix &rhs) // operator + 
                {
                        if (this->height != rhs.height || this->width != rhs.width) //
                                cout << "Cannot add" << endl ;
                        sparseMatrix temp(height ,width ) ;
                        for (int x = 0 ;x < height ;++x)
                        {
                                node *lhs_t = this->arr[x].first , *rhs_t = rhs.arr[x].first ;
                                while(lhs_t != nullptr)// the while loop is copy the xth row to the temp .
                                {                    
                                        temp.arr[x].insert(lhs_t->column,lhs_t->coef);
                                        lhs_t = lhs_t->next ;
                                }
                                lhs_t = temp.arr[x].first ;
                                while(rhs_t != nullptr) // the while loop is to merge the xth row to temp .
                                {
                                        while (rhs_t->column <= lhs_t->column)
                                        {
                                                if ( lhs_t->column == rhs_t->column)
                                                        lhs_t->coef += rhs_t->coef ;
                                                else 
                                                        temp.arr[x].insert(rhs_t->column ,rhs_t->coef);
                                                rhs_t = rhs_t->next ;
                                                if (rhs_t ==nullptr) break ;
                                        }
                                        lhs_t = lhs_t->next ;
                                }
                        }
                        return temp ;
                }
  
                sparseMatrix operator*(sparseMatrix &rhs)
                {
                        if (width != rhs.height) cout << "Wrong Type !" << endl ;
                        sparseMatrix trr_matrix = rhs.T(); // create an object to store the transpose of right side .
                        sparseMatrix temp(height,rhs.width); // when creating  A (a*b) and B(c*d) matrix , A*B is equal to C (a*d)
                        for (int x = 0 ; x< height ;++x)
                        {
                                for (int y = 0; y<rhs.width;++y)
                                {
                                        node *lhs_t = this->arr[x].first , *rhs_t = trr_matrix.arr[y].first ;
                                        double coef_t = 0 ;
                                        while(rhs_t != nullptr && lhs_t!= nullptr )// The method is similar to the operator + .
                                        {
                                                        while (rhs_t->column <= lhs_t->column)
                                                        {
                                                                if ( lhs_t->column == rhs_t->column)
                                                                        coef_t += (lhs_t->coef * rhs_t->coef );
                                                                rhs_t = rhs_t->next ;
                                                                if (rhs_t ==nullptr) break ;
                                                        }
                                                        lhs_t = lhs_t->next ;
                                        }

                                        temp.push(x,y,coef_t);
                                }
                        }
                        return temp ;
                }
                sparseMatrix T()
                {
                        return this->transpose();
                }

                void show()
                {
                        double matrix[height][width] ;
                        for (int x = 0 ;x <height ;++x)
                        {
                                for(int y = 0 ;y < width;++y)
                                matrix[x][y] = 0 ;
                        }
                        for (int x = 0 ;x <height ;++x)
                        {
                                for(node *temp = arr[x].first ;temp!=nullptr;temp=temp->next)
                                        matrix[x][temp->column] = temp->coef ;
                        }
                        for (int x = 0 ;x <height ;++x)
                        {
                                cout << "[" ;
                                for(int y = 0 ;y < width;++y)
                                        cout << matrix[x][y] << " \t" ;
                                cout << "]" << endl ;
                        }
                }

};

