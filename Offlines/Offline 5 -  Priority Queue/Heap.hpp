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
