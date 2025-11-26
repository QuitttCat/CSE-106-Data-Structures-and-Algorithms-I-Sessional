#include "2105044_1_a_queue.h"

using namespace std;

template<typename Ty>class Queue
{
    list_array<Ty> queue;
public :
     void enqueue(Ty item)
    {
        queue.insert(item);
    }

    Ty dequeue()
    {
        Ty temp=queue.remove();
        return temp;
    }
    int length()
    {
        return queue.length();
    }

    void showQueue()
    {
       queue.print_list();
    }
    Ty front()
    {
        if(!is_empty())
    {
        queue.moveToStart();
            return queue.getValue();
        }
        return -1;
    }
    Ty back()
    {
        if(!is_empty())
    {
        queue.moveToEnd();
        return queue.getValue();
        }
        return -1;
    }
    bool is_empty()
    {
        return queue.length()==0;
    }

    void clear()
    {
        while(!is_empty())
        {
            Ty buffer=queue.remove();
        }
    }

};

