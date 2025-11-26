#include<bits/stdc++.h>
using namespace std;

template<class T> class Heap
{
    T *array;
    int maxsize;
    int length;
    void capacityExpand()
    {
        if(maxsize==1) maxsize=2;
        else maxsize=2*length+1;
        T *expandedArray=new T[maxsize];
        for(int i=1; i<=length; i++)
        {
            expandedArray[i]=array[i];
        }
        if(length!=0) delete [] array;
        array=expandedArray;
    }
public :
    Heap()
    {
        array=new T[1];
        maxsize=1;
        length=0;
    }

    int leftChild(int i)
    {
        return i<<1;
    }
    int rightChild(int i)
    {
        return leftChild(i) | 1;
    }
    int parent(int i)
    {
        return i>>1;
    }
    void shiftDown(int i)
    {
        while(i>1)
        {
            if(array[i]>array[parent(i)]) swap(array[i],array[parent(i)]);
            i=parent(i);
        }
    }
    void maxHeapify(int i)
    {
        int largest;
        int left=leftChild(i);
        int right=rightChild(i);
        if(left<=length and array[left]>array[i]) largest=left;
        else largest=i;
        if(right<=length and array[right]>array[largest]) largest=right;
        if(largest!=i)
        {
            swap(array[i],array[largest]);
            maxHeapify(largest);
        }
    }
    void BuildMaxHeap()
    {
        for(int i=length/2; i>=1; i++) maxHeapify(i);
    }

    T deleteMax()
    {
        if(length==0)
        {
            T dummy;
            return dummy;
        }
        T temp=array[1];
        array[1]=array[length];
        length--;
        maxHeapify(1);
        return temp;
    }
    void insert(T key)
    {
        if(length==maxsize-1) capacityExpand();
        array[++length]=key;
        shiftDown(length);
    }
    T findMax()
    {
        if(length==0)
        {
            T dummy;
            return dummy;
        }
        return array[1];
    }
    void HeapSort()
    {
        int temp=length;
        for(int i=length; i>1; i--)
        {
            swap(array[1],array[length]);
            length--;
            maxHeapify(1);
        }
        length=temp;
    }

    T getElementAtIndex(int i)
    {
        return array[i];
    }
    void setElementAtIndex(int i,T newElement)
    {
        array[i]=newElement;
    }
    int getLength()
    {
        return length;
    }
};
/*
class Element{
public:
    int key;//based on which priority is given
    //information field of Element class is implementation dependant;
};

bool operator<(Element a,Element b)
{
    return a.key<b.key;
}
bool operator<=(Element a,Element b)
{
    return a.key<=b.key;
}
bool operator>(Element a,Element b)
{
    return a.key>b.key;
}
bool operator>=(Element a,Element b)
{
    return a.key>=b.key;
}
bool operator==(Element a,Element b)
{
    return a.key==b.key;
}
bool operator!=(Element a,Element b)
{
    return a.key!=b.key;
}

*/
template<class t>class maxPriorityQueue
{
    Heap<t> max_priority_queue;
public :
    void Insert(t x)
    {
        max_priority_queue.insert(x);
    }
    //assuming our priority will never be fully empty!
    t FindMax()
    {
        return max_priority_queue.findMax();
    }
    t ExtractMax()
    {
        t temp=max_priority_queue.deleteMax();
        cout<<"Max: "<<temp<<" has been extracted.\n";
            return temp;
    }
    void IncreaseKey(int i,t newKey)
    {
        if(i<1 or i>max_priority_queue.getLength())
        {
            cout<<"\n index out of bound\n";
            return;
        }
        t key=max_priority_queue.getElementAtIndex(i);
        if(newKey<=key) cout<<"New key is not larger than the previous key\n";
        else
        {
            max_priority_queue.setElementAtIndex(i,newKey);
            max_priority_queue.shiftDown(i);
            cout<<"Key increased!\n";
        }
    }
    void DecreaseKey(int i,t newKey)
    {
        if(i<1 or i>max_priority_queue.getLength())
        {
            cout<<"\n index out of bound\n";
            return;
        }
        t key=max_priority_queue.getElementAtIndex(i);
        if(newKey>=key) cout<<"New key is not smaller than the previous key\n";
        else
        {
            max_priority_queue.setElementAtIndex(i,newKey);
            max_priority_queue.maxHeapify(i);
            cout<<"Key decreased!\n";
        }
    }
    void Print()
    {
        int temp=1;
        int backTemp=1;
        int power=1;
        cout<<"No of elements: "<<max_priority_queue.getLength()<<"\n";
        for(int i=1; i<=max_priority_queue.getLength(); i++)
        {
            cout<<max_priority_queue.getElementAtIndex(i)<<"    ";
            if(i==temp)
            {
                backTemp=temp;
                cout<<"\n";
                power*=2;
                temp+=power;
            }
        }
        if(max_priority_queue.getLength()!=backTemp)cout<<"\n";
    }
    void Sort()
    {
        return max_priority_queue.HeapSort();
    }
};


int main()
{
    maxPriorityQueue<int> mpq;
    while(true)
    {
        int choice;
        cout<<"choice 1 : Insert an element!\n";
        cout<<"choice 2 : Find the max element!\n";
        cout<<"choice 3 : Extract the max element!\n";
        cout<<"choice 4 : Insert an element!\n";
        cout<<"choice 5 : Increase Key!\n";
        cout<<"choice 6 : Decrease Key!\n";
        cout<<"choice 7 : Terminate!\n\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
        {
            cout<<"Element to be inserted : ";
            int key;
            cin>>key;
            mpq.Insert(key);
            break;
        }
        case 2:
        {
            cout<<"Max: "<<mpq.FindMax()<<"\n";
            break;
        }
        case 3:
        {
            int buffer=mpq.ExtractMax();
            break;
        }
        case 4:
        {
            int i,key;
            cout<<"Enter index at which key to be increased : ";
            cin>>i;
            cout<<"Enter the key : ";
            cin>>key;
            cout<<"\n";
            mpq.IncreaseKey(i,key);
            break;
        }
        case 5:
        {
            int i,key;
            cout<<"Enter index at which key to be decreased : ";
            cin>>i;
            cout<<"Enter the key : ";
            cin>>key;
            cout<<"\n";
            mpq.DecreaseKey(i,key);
            break;
        }
        case 6:
        {
            mpq.Print();
            break;
        }
        case 7:
        {
            mpq.Sort();
            mpq.Print();
            return 0;
        }
        default :
            cout<<"Invalid Choice\n";

        }
        cout<<"\n";
    }
}
