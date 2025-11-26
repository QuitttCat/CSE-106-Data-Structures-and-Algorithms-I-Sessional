#include<iostream>
#include "stackArray.h"
#include<string>

using namespace std;

stack_array<float> operands;



bool isOperator(string symbol)
    {
        if(symbol=="+" or symbol=="-" or symbol=="*" or symbol=="/") return true;
        return false;
    }


void operation(string operatorTemp)
    {
        float secondOperand=operands.pop();
        float firstOperand=operands.pop();
        float push_val=0.0;

        if(operatorTemp=="+")
        {
            push_val=firstOperand+secondOperand;
        }
        else if(operatorTemp=="-")
        {
            push_val=firstOperand-secondOperand;
        }
        else if(operatorTemp=="*")
        {
            push_val=firstOperand*secondOperand;
        }
        else if(operatorTemp=="/")
        {

                push_val=firstOperand/secondOperand;
        }

        operands.push(push_val);
        }




void calculate(string* expression,int n)
    {

        int index=0;

        while(index<n)
        {
            if(!isOperator(expression[index]))
            {
                operands.push(1.00*stoi(expression[index]));
                //operands.ShowStack();

            }


            else if(isOperator(expression[index]))
            {

                    operation(expression[index]);

            }
                index++;
            }

        }



int main()
{
    stack_array<int> s;
    int n;
    cin>>n;
    string *seq=new string[n];
    for(int i=0;i<n;i++) cin>>seq[i];
    calculate(seq,n);
    //operands.ShowStack();
    cout<<operands.pop()<<endl;


}
