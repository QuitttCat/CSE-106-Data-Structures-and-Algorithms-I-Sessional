#include<iostream>

using namespace std;

class list_array{
private :
    int current_position;
    int array_length;
    int *array;
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
            int *expanded_array=new int[maxSize];
            for(int i=0;i<array_length;i++)
            {
                expanded_array[i]=array[i];
            }
            if(array_length) delete [] array;
            array=expanded_array;
        }
    }

public :
    void init(int length,int maxSize)
    {
        this->maxSize=maxSize;
        this->array_length=length;
        array=new int[maxSize];
        current_position=0;

        for(int i=0;i<length;i++)
        {
            cin>>array[i];
        }
    }


    void insert(int x)
    {
        if(maxSize==array_length) length_double();
        array_length++;
        for(int i=array_length-1;i>current_position;i--)
        {
            array[i]=array[i-1];
        }
        array[current_position]=x;
    }

     int remove()
    {
        int temp_ret;
        if(array_length==0) return -1;
        else
        {
            temp_ret=array[current_position];
            if(array_length==1)
            {
                array_length--;
            }
            else if((current_position==array_length-1))
            {
                array_length--;
                current_position--;
            }
            else if(current_position>=0 and current_position<array_length-1)
            {
                 for(int i=current_position;i<array_length-1;i++)
                 {
                     array[i]=array[i+1];
                 }
                 array_length--;
            }
        } return temp_ret;

    }

    void moveToStart()
    {
        current_position=0;
    }

    void moveToEnd()
    {
        current_position=array_length-1;
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

    int getValue()
    {
        if(array_length) return array[current_position];
    }

    void print_list()
    {
        if(array_length==0) cout<<"<>"<<endl;
        else
        {
            cout<<"<";
            for(int i=0;i<current_position;i++)
            {
                cout<<array[i]<<" ";
            }
            cout<<"|";
            for(int i=current_position;i<array_length-1;i++)
               cout<<array[i]<<" ";

            cout<<array[array_length-1]<<">"<<endl;;
        }
    }
    ~list_array()
    {
        delete [] array;
    }

};



