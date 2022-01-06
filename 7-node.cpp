class node 
{
        public:
                unsigned int code ;
                unsigned int freq ;
                char alph ;
                node *left ,*right ;
                node (char a)
                {
                        alph = a ;
                        left = right = nullptr ;
                        freq = 0 ;
                }
                node()
                {
                        left = nullptr ;
                        right = nullptr ;
                        freq = 0;
                }

};
