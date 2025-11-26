#include<iostream>
using namespace std;

template<typename T> class list_array{
private :
    int current_position;
    int array_length;
    T *array;
    int maxSize;
    int front;
    int back;


    void length_double()
    {
        if(maxSize==1)
        {
            maxSize=2;
            array=new T[2];
        }
        else
        {
            maxSize=2*array_length+1;
            T *expanded_array=new T[maxSize];
            for(int i=0;i<array_length;i++)
            {
                expanded_array[i]=array[(front+i)%maxSize];
            }
            front=0;
            back=array_length-1;
            if(array_length) delete [] array;
            array=expanded_array;
            //detete []expanded array;
        }
    }

public :
    list_array()
    {
       current_position=0;
       array_length=0;
       maxSize=1;
       front=0;
       back=-1;
       /*int x=5;
       while(x--)
       {
           T temp;
           cin>>temp;
           insert(temp);
       }*/
    }


    void insert(T x)
    {
        if(array_length==(maxSize-1)) length_double();
        back=(back+1)%maxSize;
        array[back]=x;
        array_length++;
    }

    T remove()
    {
        if(array_length!=0)
        {
            T ret=array[front];
            front=(front+1)%maxSize;
            array_length--;
            return ret;
        }

    }

    void moveToStart()
    {
        current_position=front;
    }

    void moveToEnd()
    {
        current_position=back;
    }

    void prev()
    {
        if(current_position>0) current_position--;
    }

    void next()
    {
        if(current_position<array_length-1) current_position++;
    }

    int length()
    {
        return array_length;
    }

    int currPos()
    {
        return current_position;
    }

    void moveToPos(int current_position)
    {
        if(current_position<0 or current_position>=array_length) cout<<"Invalid Positon"<<endl;
        else this->current_position=current_position;
    }

    T getValue()
    {
        if(array_length) return array[current_position];
    }

    void print_list()
    {
        if(array_length==0) cout<<"<>"<<endl;
        else
        {
            cout<<"< ";
            for(int i=front;i<front+array_length;i++)
            {
                i%=maxSize;
                cout<<array[i]<<" ";
            }
            cout<<">"<<endl;;
        }
    }
    ~list_array()
    {
        delete [] array;
    }

};

/*

int main()
{

    list_array <int> l;
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
                break;
            }
            case 2:
            {
               double out=l.remove();
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

*/

