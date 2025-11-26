#include "MaxPriorityQueue.hpp"
int main()
{
    maxPriorityQueue<int> mpq;
    ifstream in("input.txt");
    ofstream out("output.txt");
    string read;
    while(getline(in,read))
    {
        istringstream iss(read);
        string s;
        iss>>s;
        if(s=="1")
        {
            int key;
            iss>>key;
            mpq.Insert(key);
        }
        else if(s=="2")
        {
            int buffer=mpq.FindMax(out);
        }
        else if(s=="3")
        {
            int buffer=mpq.ExtractMax(out);
        }
        else if(s=="4")
        {
            int i,key;
            iss>>i>>key;
            mpq.IncreaseKey(i,key,out);
        }
        else if(s=="5")
        {
            int i,key;
            iss>>i>>key;
            mpq.DecreaseKey(i,key,out);
        }
        else if(s=="6")
        {
            mpq.Print(out);
        }
        else if(s=="7")
        {
            mpq.Sort();
            mpq.Print(out);
            in.close();
            out.close();
            return 0;
        }
        else out<<"Invalid Choice\n";
    }
}

