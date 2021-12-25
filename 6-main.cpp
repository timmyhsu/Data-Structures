#include<iostream>
#include"stack.cpp"
#include<string>
using namespace std ;

class data
{
        public:
                double value ;
                int stat ;
                data() = default ;
                data (double valu ,int stat):value{valu},stat{stat}{}
};

data typecheck(const string c)
{
        if (c[0]-'a' >=0 && 'z'-c[0] <= 26) return data((double)c[0],1) ;
        else if (c[0]-'0' >= 0&& '9'-c[0] <= 9) return data(stod(c),0) ;
        switch (c[0])
        {
                case '(' : case ')' : 
                        return data((double)c[0],2) ;break ;
                case '+': 
                        return data(1,3) ;break ;
                case '-' : 
                        return data(2,3) ;break ;
                case '*' :
                        return data(3,4) ;break ;
                case '/' : 
                        return data(4,4) ;break ;
        }

}

double compute (double a ,double b ,int c)
{
        switch (c)
        {
                case 1:
                        return a+b ;
                        break ;
                case 2:
                        return b-a ;
                        break ;
                case 3:
                        return a*b ;
                        break ;
                case 4:
                        return b/a ;
                        break ;
        }
}

void do_compute(stack<data> &operand ,stack<data> &operatorr)
{
        if (operand.top().stat==1)
        {
                data temp = operand.top(); operand.pop();
                cout << "input " << (char)temp.value <<"'s value :" ;
                double t ; cin >> t  ;
                temp.value = t ;temp.stat = 0 ;
                operand.push(temp);
        }
        double temp1 = operand.top().value; operand.pop();
        if (operand.top().stat==1)
        {
                data temp = operand.top(); operand.pop();
                cout << "input " << (char)temp.value <<"'s value :" ;
                double t ; cin >> t  ;
                temp.value = t ;temp.stat = 0 ;
                operand.push(temp);
        }
        double temp2 = operand.top().value ; operand.pop();
        operand.push(data(compute(temp1,temp2,operatorr.top().value),0));
        operatorr.pop();
}

void readandprocess ()
{
        string input ;
        stack <data> operatorr ;
        stack <data> operand ;
        while(cin >> input && input[0] != 'e')
        {
                data temp = typecheck(input);
                if (temp.stat <=1 )  // variable or number
                {
                        /*if(temp.stat == 1 )
                        {
                                cout << "input " << (char)temp.value <<"'s value :" ;
                                double t ; cin >> t  ;
                                temp.value = t ;temp.stat = 0 ;
                                operand.push(temp);
                        }
                        else */
                                operand.push(temp);
                }
                else //operator 
                {
                        if (input[0] == ')')
                        {
                                while(operatorr.top().stat != 2)
                                {
                                        do_compute(operand,operatorr);
                                }
                                operatorr.pop();//pop '(' 
                        }
                        else if (!operatorr.isEmpty() && (operatorr.top().stat > temp.stat && temp.value != (double)'(' ))
                        {
                                do_compute(operand,operatorr);
                                operatorr.push(temp);
                        }
                        else operatorr.push(temp);

                }
                ///////////////////

        }
        while(!operatorr.isEmpty())
        {
                do_compute(operand,operatorr);
        }
        cout << operand.top().value << endl ;
        operand.pop();
}
int main()
{
        char a , b ;
        while ( cin >> a >> b )
        {
        cout << a << " " << b << " " ;
        readandprocess() ;
        }
}
