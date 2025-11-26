#include<iostream>
using namespace std;

template <class t>  class node{
public:
    t data;
    node *next_node;
};

template <class T>  class list_LL{

    node<T> *head;
    node<T> *tail;
    node<T> *current_node;
    int length_ll;
    int current_position;

public :
    list_LL()
    {
        init(0,0);
    }

    void init(int length_ll,int k)
    {
        current_node=head=tail=NULL;

        if(length_ll!=0)
        {
        T d;
        cin>>d;
        node<T>* new_node=new node<T>;
        new_node->data=d;
        new_node->next_node=NULL;
        current_node=new_node;
        head=new_node;

        for(int i=1;i<length_ll;i++)
        {
            cin>>d;
            node<T>* node_new= new node<T>;
            current_node->next_node=node_new;
            node_new->data=d;
            node_new->next_node=NULL;
            current_node=node_new;
        }

        tail=current_node;
        current_node=head;
        }

        this->length_ll=length_ll;
        current_position=0;

    }

    void insert(T d)
    {
        if(length_ll==0)
        {
            node<T>* new_node= new node<T>;
            new_node->data=d;
            new_node->next_node=NULL;
            head=new_node;
            tail=new_node;
            current_node=new_node;
        }

        else if(current_position==0)
        {
            node<T>* new_node= new node<T>;
            new_node->data=d;
            new_node->next_node=current_node;
            current_node=new_node;
            head=new_node;
        }

        else if(length_ll>1 and current_position>0 and current_position<=length_ll-1)
        {
            node<T>* temp=head;
            while(temp->next_node!=current_node) temp=temp->next_node;
            node<T>* new_node= new node<T>;
            new_node->data=d;
            new_node->next_node=current_node;
            current_node=new_node;
            temp->next_node=new_node;
        }
        length_ll++;
    }

    T remove()
    {
        T rmv;
        if(length_ll==0) rmv=-1;
        else
        {
            rmv=getValue();
            if(length_ll==1)
            {
                delete current_node;
                head=tail=current_node=NULL;
            }
            else if(current_position==0 and length_ll>1)
            {
                head=current_node->next_node;
                delete current_node;
                current_node=head;
            }
            else if(length_ll>1 and current_position>0 and current_position<length_ll-1)
            {
                node<T>* temp=head;
                while(temp->next_node!=current_node) temp=temp->next_node;
                temp->next_node=current_node->next_node;
                delete current_node;
                current_node=temp->next_node;
            }
            else if(current_position==length_ll-1)
            {
                node<T>* temp=head;
                while(temp->next_node!=current_node) temp=temp->next_node;
                temp->next_node=current_node->next_node;
                delete current_node;
                current_node=temp;
                tail=current_node;
                current_position--;

            }
            length_ll--;
        }

        return rmv;
    }

    void moveToStart()
    {
        current_node=head;
        current_position=0;
    }

    void moveToEnd()
    {
        current_node=tail;
        current_position=length_ll-1;
    }

    void prev()
    {
        if(current_position>0)
        {
            current_position--;
            node<T>* temp=head;
            while(temp->next_node!=current_node) temp=temp->next_node;
            current_node=temp;
        }
    }

    void next()
    {
        if(current_position<length_ll-1)
        {
            current_position++;
            current_node=current_node->next_node;
        }
    }

    int length()
    {
        return length_ll;
    }

    int currPos()
    {
        return current_position;
    }

    void moveToPos(int pos)
    {
        if(pos<0 or pos>=length_ll) cout<<"Invalid Postion"<<endl;
        else if(pos>current_position)
        {
            while(current_position!=pos) next();
        }


        else if(pos<current_position)
        {
            while(current_position!=pos) prev();
        }




    }

    T getValue()
    {
        return current_node->data;
    }

    void print_list()
    {
        if(length_ll==0) cout<<"<>"<<endl;
        else if(length_ll==1) cout<<"<"<<getValue()<<">"<<endl;
        else
        {
             cout<<"<";
             node<T>* temp=head;
        while(temp->next_node!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next_node;
        }
        cout<<temp->data<<">"<<endl;
        }
    }

};

/*

int main()
{

    list_LL l;
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
                cout<<-1<<endl;
                break;
            }
            case 2:
            {
               int out=l.remove();
               l.print_list();
               cout<<out<<endl;
               break;
            }

            case 3:
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






