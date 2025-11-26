#include<iostream>
#include "list_LL.h"
//#include "array_list.h"
using namespace std;

class list_user{
    list_LL l;
    //list_array l;
public:
    list_user(int k,int x)
    {
        l.init(k,x);
        l.print_list();
    }
    void Clear()
    {
        l.moveToStart();
        int len=l.length();
        for(int i=0;i<len;i++)
        {
            int temp=l.remove();
        }

    }
    void append(int d)
    {
        if(l.length()==0) l.insert(d);
        else
        {
            int curpos=l.currPos();
            l.moveToEnd();
            int buffer=l.getValue();
            l.insert(d);
            l.insert(buffer);
            l.moveToEnd();
            l.remove();
            l.moveToPos(curpos);
        }
    }
    int search(int key)
    {

        if(l.length()==0) return -1;
        int temp_curpos=l.currPos();
        for(int i=0;i<l.length();i++)
        {
            l.moveToPos(i);
            if(key==l.getValue())
            {
                l.moveToPos(temp_curpos);
                return i;
            }
        }
        l.moveToPos(temp_curpos);
        return -1;
    }
    void print_list()
    {
        return l.print_list();
    }
};


int main()
{
    int K,X;
    cin>>K>>X;
    list_user user(K,X);
    while(1)
    {
        int Q;
        cin>>Q;
        switch(Q)
        {
            case 0:
            {
                return 0;
            }
            case 1:
            {
                user.Clear();
                user.print_list();
                cout<<-1<<endl;
                break;
            }
            case 2:
            {
                int d;
                cin>>d;
                user.append(d);
                user.print_list();
                cout<<-1<<endl;
                break;
            }
            case 3:
            {
                int key;
                cin>>key;
                int out=user.search(key);
                user.print_list();
                cout<<out<<endl;
                break;
            }
            default:
            {
                cout<<"Invalid query"<<endl;
            }
        }
    }
}

