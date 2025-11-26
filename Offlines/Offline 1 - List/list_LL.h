#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next_node;
};

class list_LL{
    node *head;
    node *tail;
    node *current_node;
    int length_ll;
    int current_position;

public :


    void init(int length_ll,int k)
    {
        current_node=head=tail=NULL;

        if(length_ll!=0)
        {
        int d;
        cin>>d;
        node *new_node=new node;
        new_node->data=d;
        new_node->next_node=NULL;
        current_node=new_node;
        head=new_node;

        for(int i=1;i<length_ll;i++)
        {
            cin>>d;
            node *node_new= new node;
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

    void insert(int d)
    {
        if(length_ll==0)
        {
            node *new_node= new node;
            new_node->data=d;
            new_node->next_node=NULL;
            head=new_node;
            tail=new_node;
            current_node=new_node;
        }

        else if(current_position==0)
        {
            node *new_node= new node;
            new_node->data=d;
            new_node->next_node=current_node;
            current_node=new_node;
            head=new_node;
        }

        else if(length_ll>1 and current_position>0 and current_position<=length_ll-1)
        {
            node *temp=head;
            while(temp->next_node!=current_node) temp=temp->next_node;
            node *new_node= new node;
            new_node->data=d;
            new_node->next_node=current_node;
            current_node=new_node;
            temp->next_node=new_node;
        }
        length_ll++;
    }

    int remove()
    {
        int rmv;
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
                node *temp=head;
                while(temp->next_node!=current_node) temp=temp->next_node;
                temp->next_node=current_node->next_node;
                delete current_node;
                current_node=temp->next_node;
            }
            else if(current_position==length_ll-1)
            {
                node *temp=head;
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
            node *temp=head;
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

    int getValue()
    {
        return current_node->data;
    }

    void print_list()
    {
        if(length_ll==0) cout<<"<>"<<endl;
        else if(length_ll==1) cout<<"<|"<<getValue()<<">"<<endl;
        else
        {
             cout<<"<";
             node *temp=head;
             while(temp!=current_node)
        {
            cout<<temp->data<<" ";
            temp=temp->next_node;
        }
        cout<<"|";
        while(temp->next_node!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next_node;
        }
        cout<<temp->data<<">"<<endl;
        }
    }

};








