#include<iostream>
#include "list_LL.h"

using namespace std;

int main()
{
    list_LL l;
    int x;
    cin>>x;
    l.init(x,x+1);
    l.print_list();
    int len=l.length();
    for(int i=1;i<len-1;i+=2)
    {

        l.moveToPos(l.length()-1);
        int temp=l.remove();
        l.moveToPos(i);
        l.insert(temp);

    }
    l.moveToStart();
    l.print_list();



}
