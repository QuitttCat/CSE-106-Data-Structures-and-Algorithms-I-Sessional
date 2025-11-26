#include<iostream>
#include<cstring>
#include "2105044_1_ll_queue.h"



template<typename T>class Queue
{
    list_LL<T> queue;
public :
    Queue()
    {
       queue.init(0,0);
    }
    T dequeue()
    {
        queue.moveToStart();
        return queue.remove();
    }
    int length()
    {
        return queue.length();
    }

    void showQueue()
    {
       return queue.print_list();
    }
    T front()
    {
        queue.moveToStart();
        return queue.getValue();
    }
    T back()
    {
        queue.moveToEnd();
        return queue.getValue();
    }
    bool is_empty()
    {
        return queue.length()==0;
    }
    void enqueue(T item)
    {
        if(is_empty())
        {
            queue.insert(item);
            return;
        }
        queue.moveToEnd();
        T temp=queue.getValue();
        queue.insert(item);
        queue.insert(temp);
        queue.moveToEnd();
        T buffer=queue.remove();
    }
    void clear()
    {
        while(!is_empty())
        {
            T buffer=queue.remove();
        }
    }

};

