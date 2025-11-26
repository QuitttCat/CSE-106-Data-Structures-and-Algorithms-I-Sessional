#include "2105044_2_stack.cpp"

template<typename t> void options()
{
    cout<<"initial length :"<<endl;
    int n;
    cin>>n;
    qstack<t> s(n);
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


