#include<iostream>
#include<cstring>

#define EXIT 0
#define CLEAR 1
#define PUSH 2
#define POP 3
#define LENGTH 4
#define TOP_VALUE 5
#define isEMPTY 6

using namespace std;

template<class T>


class stack_array
{
private :
    T *array;
    int top;
    int maxSize;

    void length_double()
    {
        if(maxSize==0)
        {
            maxSize=1;
        }
        else
        {
            maxSize*=2;
            T *expanded_array=new T[maxSize];
            for(int i=0; i<top; i++)
            {
                expanded_array[i]=array[i];
            }
            if(top) delete [] array;
            array=expanded_array;
        }
    }

public :
    void init(int maxSize,int length)
    {
        this->maxSize=maxSize;
        top=length;
        array=new T[maxSize];

        for(int i=0; i<top; i++)
        {
            cin>>array[i];
        }
    }
    void clear()
    {
        if(top==0) return;
        else top=0;
    }

    void push(T data)
    {
        array[top++]=data;
    }

    T pop()
    {
        if(top==0) return -1;
        else return array[--top];
    }


    int length()
    {
        return top;
    }


    T topValue()
    {
        if(top==0) return -1;
        else return array[top-1];
    }


    bool isEmpty()
    {
        return top==0;
    }

    void ShowStack()
    {
        if(top==0) cout<<"<>"<<endl;
        else
        {
            cout<<"<";
            for(int i=0; i<top-1; i++)
                cout<<array[i]<<", ";

            cout<<array[top-1]<<">"<<endl;;
        }
    }
    ~stack_array()
    {
        delete [] array;
    }
};

template<typename t>

void options()
{
    cout<<"Input memory chunck size & initial length"<<endl;
    int X,K;//X denotes memory chunk size, K denotes initial length
    cin>>X>>K;
    stack_array<t> s;
    s.init(X,K);
    s.ShowStack();

    while(true)
    {
        int option;
        cin>>option;

        switch(option)
        {
        case EXIT:
        {
            return;
        }
        case CLEAR:
        {
            if(s.isEmpty()) cout<<"Stack is already empty!"<<endl;
            else s.clear();
            s.ShowStack();
            break;
        }
        case PUSH:
        {
            t item;
            cin>>item;
            s.push(item);
            s.ShowStack();
            break;
        }
        case POP:
        {
            if(s.length()==0)
            {
                s.ShowStack();
                cout<<"Empty Stack! No element to pop!"<<endl;
            }
            else
            {
               t res=s.pop();
               s.ShowStack();
               cout<<"The popped element is :"<<res<<endl;
            }

            break;
        }
        case LENGTH:
        {
            s.ShowStack();
            cout<<"Length of stack is : "<<s.length()<<endl;
            break;
        }
        case TOP_VALUE:
        {
            s.ShowStack();
            if(s.isEmpty()) cout<<"Stack is empty!"<<endl;
            else cout<<"The top element in the stack :"<<s.topValue()<<endl;
            break;
        }
        case isEMPTY:
        {
            s.ShowStack();
            if(s.isEmpty()) cout<<"Stack is empty!"<<endl;
            else cout<<"Stack is not empty!"<<endl;
            break;
        }
        default :
        {
            cout<<"Invalid Operation"<<endl;
        }
        }
    }
}


int main()
{
    string choice;
    cout<<"Choice your data type :"<<endl;
    cout<<"int / long long int / char / float /double"<<endl;
    getline(cin,choice);
    if(choice=="int") options<int>();
    else if(choice=="long long") options<long long>();
    else if(choice=="char") options<char>();
    else if(choice=="float") options<float>();
    else if(choice=="double") options<double>();
    else cout<<"Invalid data type!"<<endl;

    return 0;
}
