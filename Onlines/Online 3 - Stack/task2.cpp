#include "stackArray.h"
#include<string>


class Calculator
{
    stack_array<char> operators;
    stack_array<float> operands;
    stack_array<char> bracketStore;
    bool validity=true;


public :
    bool getValidity()
    {
        return validity;
    }
    void setvalidity(bool x)
    {
        validity=x;
    }
    bool isBracket(char symbol)
    {
        if(symbol=='(' or symbol==')') return true;
        return false;
    }

    bool isFirstBracket(char symbol)
    {
        if(symbol=='(') return true;
        return false;
    }

    bool isSecondBracket(char symbol)
    {
        if(symbol==')') return true;
        return false;
    }
    //Bracket parity check
    bool isPair(char a,char b)
    {
        if(a=='(' and b==')') return true;
        else if(a==')' and b=='(') return true;
        else return false;
    }

    bool isOperand(char symbol)
    {

        if(symbol >= '0' and symbol <= '9') return true;
        return false;
    }

    bool isOperator(char symbol)
    {
        if(symbol=='+' or symbol=='-' or symbol=='*' or symbol=='/') return true;
        return false;
    }

    bool isUnaryOperator(char symbol)
    {
        if(symbol=='-') return true;
        return false;
    }

    int precedence(char op)
    {

        switch(op)
        {
        case '+':
            return 1;
        case '-':
            return 1;//lower precedence
        case '*':
            return 2;
        case '/':
            return 2;//higher precedence
        default :
            return 0;
        }
    }


    void operation()
    {
        char operatorTemp=operators.pop();
        float secondOperand=operands.pop();
        float firstOperand=operands.pop();
        float push_val=0.0;

        if(operatorTemp=='+')
        {
            push_val=firstOperand+secondOperand;
        }
        else if(operatorTemp=='-')
        {
            push_val=firstOperand-secondOperand;
        }
        else if(operatorTemp=='*')
        {
            push_val=firstOperand*secondOperand;
        }
        else if(operatorTemp=='/')
        {
            if(secondOperand)
            {
                push_val=firstOperand/secondOperand;
            }
            else
            {
                setvalidity(false);
                return;

            }

        }
        operands.push(push_val);
        //operands.ShowStack();

    }



    bool isValid(string expression)
    {

        if(isSecondBracket(expression[0]) or (isOperator(expression[0]) and !isUnaryOperator(expression[0]))) return false;
        if(isOperator(expression[expression.size()-1])) return false;

        for(int i=0; i<expression.size(); i++)
        {
            char temp=expression[i];
            if(!isOperand(temp) and !isOperator(temp) and !isBracket(temp) and temp!=' ') return false;
        }

        for(int i=0; i<expression.size()-1; i++)
        {
            if(isFirstBracket(expression[i]) and expression[i+1]==' ')
            {
                i++;
                while(expression[i]==' ') i++;
                if(isSecondBracket(expression[i])) return false;
            }
        }
        for(int i=0; i<expression.size()-1; i++)
        {
            if(isOperand(expression[i]) and expression[i+1]==' ')
            {
                i++;
                while(expression[i]==' ') i++;
                if(isOperand(expression[i])) return false;
            }
        }


        for(int i=1; i<expression.size()-1; i++)
        {
            char temp=expression[i];
            if(isOperator(temp) and (isOperator(expression[i+1]) or isSecondBracket(expression[i+1]))) return false;
        }

        //bracket parity check

        for(int i=0; i<expression.size(); i++)
        {
            char temp=expression[i];
            if(isFirstBracket(temp)) bracketStore.push(temp);//bracketStore.ShowStack();
            else if(isSecondBracket(temp))
            {
                if(bracketStore.isEmpty() or !isPair(bracketStore.topValue(),temp)) return false;
                else char buffer=bracketStore.pop(); //as popped char has no use in this case
            }
        }
        if(!bracketStore.isEmpty()) return false;
        return true;
    }

    float calculate(string expression)
    {
        for(int i=1; i<expression.size()-1; i++)
        {
            if(expression[i]==')' and expression[i+1]=='(')
                expression.insert(i+1,"*",1);
        }//()() is replaced by ()*()

        int index=0;

        while(index<expression.size())
        {
            if(isOperand(expression[index]))
            {
                float pushVal=0.0;//the value will be finally pushed into the stack
                while(index<expression.size() and isOperand(expression[index]))
                {
                    pushVal=pushVal*10+expression[index]-48;
                    //cout<<pushVal<<endl;
                    index++;
                }
                operands.push(pushVal);
                //operands.ShowStack();
            }
            else if(isFirstBracket(expression[index]))
            {
                operators.push(expression[index]);
                index++;
            }
            else if(isSecondBracket(expression[index]))
            {
                if(isFirstBracket(operators.topValue()))
                {
                    char buffer=operators.pop();
                    index++;
                }
                else
                {
                    while(!isPair(operators.topValue(),expression[index]))
                    {
                        if(getValidity()==true) operation();
                        else return 0;
                    }
                }
            }
            else if(isOperator(expression[index]))
            {
                if(isUnaryOperator(expression[index]) and (index==0 or isFirstBracket(expression[index-1])))
                {
                    operands.push(0.0);  //unary operation -3 is equivalent to 0-3
                }
                else
                {
                    while(!operators.isEmpty() and !isFirstBracket(operators.topValue()) and precedence(expression[index])<=precedence(operators.topValue()))
                    {
                        if(getValidity()==true) operation();
                        else return 0;
                    }
                }
                operators.push(expression[index]);
                index++;
            }
            else if(expression[index]==' ') index++;
        }
        while(!operators.isEmpty())
        {
            if(getValidity()==true) operation();
            else return 0;
        }
        return operands.pop();

    }
    ~Calculator()
    {

    }



};

int main()
{
    string expression;
    getline(cin,expression);
    Calculator fx;
    if(fx.isValid(expression) and fx.getValidity())
    {
        cout<<"Valid expression!"<<endl;
        cout<<"Computed Value : "<<fx.calculate(expression)<<endl;
    }
    else cout<<"Not valid!"<<endl;
}
