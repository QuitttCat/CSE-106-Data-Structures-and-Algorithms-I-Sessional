//#include "2105044_1_ll_queue.cpp"
#include "2105044_1_a_queue.cpp"


#define EXIT 0
#define CLEAR 1
#define PUSH 2
#define POP 3
#define LENGTH 4
#define TOP_VALUE 5
#define isEMPTY 6


template<class T> class qstack{

private :
    Queue<T> qmain,qtemp;
    int top;
public :
    qstack(int x)
    {
        while(x--)
        {
            T temp;
            cin>>temp;
            push(temp);
        }
    }

    void clear()
    {
        qmain.clear();
    }

    void push(T data)
    {
        qmain.enqueue(data);
    }

    T pop()
    {
           /* while(qmain.length()!=1)
            {
                T dq=qmain.dequeue();
                qtemp.enqueue(dq);
            }
            T ret=qmain.dequeue();
            while(!qtemp.is_empty())
            {
                T dq=qtemp.dequeue();
                qmain.enqueue(dq);
            }
            return ret;*/
            int iterate=qmain.length()-1;
            while(iterate--)
            {
               qmain.enqueue(qmain.dequeue());
            }
            return qmain.dequeue();

    }


    int length()
    {
        return qmain.length();
    }


    T topValue()
    {
        if(qmain.is_empty()) return -1;
        else return qmain.back();
    }


    bool isEmpty()
    {
        return qmain.is_empty();
    }

    void ShowStack()
    {
        return qmain.showQueue();
    }
    ~qstack()
    {

    }
};
