#include "2105044_1_ll_queue.cpp"
//#include "2105044_1_a_queue.cpp"

#define EXIT 0
#define ENQUEUE 1
#define DEQUEUE 2
#define LENGTH 3
#define FRONT 4
#define BACK 5
#define isEMPTY 6
#define CLEAR 7




template<typename t> void options()
{
    Queue<t> q;
    q.showQueue();

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
        case ENQUEUE:
        {
            t item;
            cin>>item;
            q.enqueue(item);
            q.showQueue();
            break;
        }
        case DEQUEUE:
        {
            if(q.is_empty())
            {
                cout<<"Queue is Empty!"<<endl;
                q.showQueue();
            }

            else
            {
                t out=q.dequeue();
                q.showQueue();
                cout<<out<<endl;
            }
            break;
        }
        case LENGTH:
        {
            q.showQueue();
            cout<<q.length()<<endl;
            break;
        }
        case FRONT:
        {
            if(q.is_empty())
            {
                cout<<"Queue is Empty!"<<endl;
                q.showQueue();
            }
            else
            {
                q.showQueue();
                cout<<q.front()<<endl;
            }
            break;

        }
        case BACK:
        {
            if(q.is_empty())
            {
                cout<<"Queue is Empty!"<<endl;
                q.showQueue();
            }
            else
            {
                q.showQueue();
                cout<<q.back()<<endl;
            }
            break;
        }
        case isEMPTY:
        {
            q.showQueue();
            if(q.is_empty()) cout<<"Queue is empty!"<<endl;
            else cout<<"Queue is not empty!"<<endl;
            break;
        }
        case CLEAR:
        {
            q.clear();
            q.showQueue();
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
    cout<<"int / long long / char / float /double"<<endl;
    getline(cin,choice);
    if(choice=="int") options<int>();
    else if(choice=="long long") options<long long>();
    else if(choice=="char") options<char>();
    else if(choice=="float") options<float>();
    else if(choice=="double") options<double>();
    else cout<<"Invalid data type!"<<endl;

    return 0;
}
