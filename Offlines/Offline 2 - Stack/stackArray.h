
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

    stack_array()
    {
        init(0,0);
    }
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
