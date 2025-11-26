#include "Heap.hpp"
template<class t>class maxPriorityQueue
{
    Heap<t> max_priority_queue;
public :
    void Insert(t x)
    {
        max_priority_queue.insert(x);
    }
    //assuming our priority will never be fully empty!
    t FindMax(ofstream &out)
    {
        t temp=max_priority_queue.findMax();
        if(max_priority_queue.getLength()==0)
        {

            out<<"Max priority queue is Empty!\n";
            return temp;
        }
        else
        {
            out<<"Max: "<<temp<<"\n";
            return temp;
        }

    }
    t ExtractMax(ofstream &out)
    {


        t temp=max_priority_queue.deleteMax();
        if(max_priority_queue.getLength()==0)
        {

            out<<"Max priority queue is Empty!\n";
            return temp;
        }
        else
        {
            out<<"Max: "<<temp<<" has been extracted.\n";
            return temp;
        }
    }
    void IncreaseKey(int i,t newKey,ofstream &out)
    {
        if(i<1 or i>max_priority_queue.getLength())
        {
            out<<"\n Index out of bound\n";
            return;
        }
        t key=max_priority_queue.getElementAtIndex(i);
        if(newKey<=key) out<<"New key is not larger than the previous key\n";
        else
        {
            max_priority_queue.setElementAtIndex(i,newKey);
            max_priority_queue.shiftDown(i);
            out<<"Key increased!\n";
        }
    }
    void DecreaseKey(int i,t newKey,ofstream &out)
    {
        if(i<1 or i>max_priority_queue.getLength())
        {
            out<<"\n Index out of bound\n";
            return;
        }
        t key=max_priority_queue.getElementAtIndex(i);
        if(newKey>=key) out<<"New key is not smaller than the previous key\n";
        else
        {
            max_priority_queue.setElementAtIndex(i,newKey);
            max_priority_queue.maxHeapify(i);
            out<<"Key decreased!\n";
        }
    }
    void Print(ofstream &out)
    {
        int temp=1;
        int backTemp=1;
        int power=1;
        out<<"No of elements: "<<max_priority_queue.getLength()<<"\n";
        for(int i=1; i<=max_priority_queue.getLength(); i++)
        {
            out<<max_priority_queue.getElementAtIndex(i);
            if(i==temp)
            {
                backTemp=temp;
                out<<"\n";
                power*=2;
                temp+=power;
            }
            else out<<"    ";
        }
        if(max_priority_queue.getLength()!=backTemp)out<<"\n";
    }
    void Sort()
    {
        return max_priority_queue.HeapSort();
    }
};
