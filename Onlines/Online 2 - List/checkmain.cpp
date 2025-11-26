#include<iostream>
#include "array_list.h"
//#include "list_LL.h"
using namespace std;




int main()
{
    int K,X;//k denotes initial length, x denotes memory chunk size
    list_array l;
    //list_LL l;
    cin>>K>>X;
    l.init(K,X);
    l.print_list();

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
                int item;
                cin>>item;
                l.insert(item);
                l.print_list();
                cout<<-1<<endl;
                break;
            }
            case 2:
            {
               int out=l.remove();
               l.print_list();
               cout<<out<<endl;
               break;
            }
            case 3:
            {
                l.moveToStart();
                l.print_list();
                cout<<-1<<endl;
                break;
            }
             case 4:
            {
                l.moveToEnd();
                l.print_list();
                cout<<-1<<endl;
                break;
            }
             case 5:
            {
                l.prev();
                l.print_list();
                cout<<-1<<endl;
                break;
            }
             case 6:
            {
                l.next();
                l.print_list();
                cout<<-1<<endl;
                break;
            }
             case 7:
            {
                l.print_list();
                cout<<l.length()<<endl;
                break;
            }
             case 8:
            {
                l.print_list();
                cout<<l.currPos()<<endl;
                break;
            }
            case 9:
            {
                int pos;
                cin>>pos;
                l.moveToPos(pos);
                l.print_list();
                cout<<-1<<endl;
                break;
            }
            case 10:
            {
                l.print_list();
                cout<<l.getValue()<<endl;
                break;
            }
            default:
            {
                cout<<"Invalid query"<<endl;
            }

        }
    }



}
