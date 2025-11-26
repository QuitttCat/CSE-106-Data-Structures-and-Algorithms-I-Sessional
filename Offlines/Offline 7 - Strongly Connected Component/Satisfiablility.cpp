#include<bits/stdc++.h>
using namespace std;


vector<int> adjacencyList[100000],transposeAdjacencyList[100000];
vector<bool> visited;
vector<int> topoOrder,componentNumber;
vector<bool> assignment;

void TopoSort(int n)
{
    visited[n]=true;
    for(auto child :adjacencyList[n])
        if(!visited[child]) TopoSort(child);
    topoOrder.push_back(n);
}

void stronglyConnectedComponent(int n,int componentId)
{
    componentNumber[n]=componentId;
    for(auto child:transposeAdjacencyList[n])
        if(componentNumber[child]==0) stronglyConnectedComponent(child,componentId);
}

bool satisfable(int n)
{
    topoOrder.clear();
    visited.assign(n,false);

    for(int i=0; i<n; i++)
    {
        if(!visited[i]) TopoSort(i);
    }
    reverse(topoOrder.begin(),topoOrder.end());

    componentNumber.assign(n,0);

    //for(int i=0;i<n;i++) cout<<componentNumber[i]<<" ";

    int Id=0;

    for(auto x:topoOrder)
    {
        if(componentNumber[x]==0)
        {
            Id++;
            //cout<<Id<<endl;
            stronglyConnectedComponent(x,Id);
            //cout<<"error"<<x<<" "<<componentNumber[x]<<endl;
        }
    }
    /*for(int i=0,componentId=0; i<n; i++)
    {
        if(!componentNumber[i]) stronglyConnectedComponent(i,++componentId);
    }*/

    assignment.assign(n/2, false);


    for (int i = 0; i <n; i += 2)
    {
        if (componentNumber[i] == componentNumber[i + 1] and componentNumber[i]!=0)
            return false;
        assignment[i/2] = componentNumber[i] > componentNumber[i + 1];
    }
    return true;

}

void addImplication(int a, bool nega, int b, bool negb)
{
    a = 2*a ^ nega;
    b = 2*b  ^ negb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adjacencyList[neg_a].push_back(b);
    adjacencyList[neg_b].push_back(a);
    transposeAdjacencyList[b].push_back(neg_a);
    transposeAdjacencyList[a].push_back(neg_b);
    //cout<<"debugff\n";
}

int main()
{

    ifstream in("in48_.txt");
   // ifstream in("in91_.txt");//no assignment possible
   // ifstream in("in92_.txt");
   // ifstream in("in96_.txt");
   // ifstream in("in97_.txt");
   // ifstream in("in98_.txt");
   //t ifstream in("in99_.txt");//no assignment possible
    ofstream out("out.txt");


    string n;
    getline(in,n);
    cout<<n<<endl;
    //getchar();
    //int temp=n;
    map<char,int> mp;
    int cnt=-1;
    string inp;
    while(getline(in,inp))
    {
        cout<<inp<<endl;
        stringstream ss;
        ss<<inp;
        string a,b;
        ss>>a>>b;
        if(b=="") b=a;
        char ca=a[a.size()-1];
        char cb=b[b.size()-1];

        if(!mp.count(ca))
        {
            int co_a=ca-'a'+1;
            mp[ca]=co_a;
            cnt=max(cnt,co_a);
        }

        if(!mp.count(cb))
        {
            int co_b=cb-'a'+1;
            mp[cb]=co_b;
            cnt=max(cnt,co_b);
        }

        bool negA=(a[0]=='~');
        bool negB=(b[0]=='~');
        //cout<<"debug\n";

        addImplication(mp[ca]-1,negA,mp[cb]-1,negB);
        //cout<<"debugfinal\n";
    }
    int index=0;
    bool temp1=satisfable(2*cnt);

    if(!temp1) out<<"No assignment possible\n";
    else
    {
        //cout<<mp.size()<<endl;
        for(auto it:mp)
        {
            out<<it.first<<" ";//<<it.second<<" ";
            if(assignment[it.second-1]) out<<"True\n";
            else out<<"False\n";
        }
    }

    //for(int i=0;i<2*cnt+1;i++) cout<<componentNumber[i]<<" ";


}

