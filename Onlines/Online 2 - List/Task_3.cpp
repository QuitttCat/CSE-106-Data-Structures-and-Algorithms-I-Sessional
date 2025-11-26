#include<iostream>
#include<cstring>
#include <sstream>
//#include "list_LL.h"
#include "array_list.h"
using namespace std;

class CRS
{
    //list_LL cars;
    list_array cars;
public:
    void init(int x,int k)
    {
        cars.init(x,k);
    }
    int length()
    {
        return cars.length();
    }
    void remove()
    {
        cars.remove();
    }
    void append(int d)
    {
        if(cars.length()==0) cars.insert(d);
        else
        {
            int curpos=cars.currPos();
            cars.moveToEnd();
            int buffer=cars.getValue();
            cars.insert(d);
            cars.insert(buffer);
            cars.moveToEnd();
            cars.remove();
            cars.moveToPos(curpos);
        }
    }
    void print_cars()
    {
        for(int i=0;i<cars.length();i++)
        {
            cars.moveToPos(i);
            cout<<cars.getValue()<<" ";
        }
        cout<<"\n";
        cars.moveToStart();
    }
    void assignLeastLabel()
    {
        cars.moveToStart();
        int least=cars.getValue();

        for(int i=1;i<length();i++)
        {
            cars.moveToPos(i);
            if(least>cars.getValue()) least=cars.getValue();
        }

        cars.moveToStart();
        for(int i=0;i<length();i++)
        {
            cars.moveToPos(i);
            if(cars.getValue()==least)
            {
                int bfr=cars.remove();
                break;
            }
        }
        cars.moveToStart();
    }

    void returnAfterHighestLabel(int car_ret)
    {
        if(length()==0)
        {
            cars.insert(car_ret);
            return;
        }
        cars.moveToStart();
        int highest=cars.getValue();

        for(int i=1;i<length();i++)
        {
            cars.moveToPos(i);
            if(highest<cars.getValue()) highest=cars.getValue();
        }

        cars.moveToStart();
        for(int i=0;i<length();i++)
        {
            cars.moveToPos(i);
            if(cars.getValue()==highest and i<length()-1)
            {
                cars.moveToPos(i+1);
                cars.insert(car_ret);
                break;
            }
            else if(cars.getValue()==highest and i==length()-1)
            {
                append(car_ret);
                break;
            }
        }
        cars.moveToStart();
    }
};
int main()
{
    //x total car,y number of garages,z = max car in a garage;
    int x,y,z;
    cin>>x>>y>>z;
    CRS garage[y];
    for(int i=0;i<y;i++)
    {
        int gar_no;
        cin>>gar_no;
        garage[gar_no-1].init(0,0);

        string str;
        getline(cin,str);
        stringstream ss(str);

        int d;
        while(ss>>d) garage[gar_no-1].append(d);
    }
    for(int i=0;i<y;i++) garage[i].print_cars();
    while(1)
    {
        string event;
        getline(cin,event);
        if(event=="end") return 0;
        else if(event=="req")
        {
            int index=0;
            int flag=0;
            while(index<y)
            {
                if(garage[index].length()==0) index++;
                else
                {
                    garage[index].assignLeastLabel();
                    flag=1;
                    for(int i=0;i<y;i++) garage[i].print_cars();
                    break;
                }
            }
            if(flag==0) cout<<"All garages are empty!!"<<endl;
        }
        else
        {
            stringstream sss(event);
            int ret_car;
            string buff;
            while(sss>>buff) sss>>ret_car;
            int index=y-1;
            int flag=0;
            while(index>=0)
            {
                if(garage[index].length()==z) index--;
                else
                {
                    garage[index].returnAfterHighestLabel(ret_car);
                    flag=1;
                    for(int i=0;i<y;i++) garage[i].print_cars();
                    break;
                }
            }
            if(flag==0) cout<<"garages are full to their capacity!!"<<endl;
        }
    }
}


