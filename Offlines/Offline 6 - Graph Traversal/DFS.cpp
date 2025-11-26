#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define maximum 100007
#define reverse(v) reverse(v.begin(),v.end())

vector<ll> v[maximum];//adjacency list of the graph
bool visited[maximum];
ll parentTracking[maximum];

void DFS(ll child,ll parent)
{
    parentTracking[child]=parent;
    visited[child]=true;
    for(auto x:v[child])
    {
        if(!visited[x])
        {
           DFS(x,child);
        }

    }
}

ll numberOfConnectedComponent(ll size)
{
    ll count=0;
    memset(visited,0,maximum);
    for(ll i=0;i<size;i++)
    {
        if(!visited[i])
        {
            count++;
            cout<<i<<endl;
            DFS(i,-1);
        }
    }
    memset(visited,0,maximum);
    return count;
}

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");


    ll n,m,a,b,source,destination;


    in>>n>>m;
    while(m--)
    {
        in>>a>>b;
        v[a].push_back(b);//there is a directed edge from a to b;
    }

    in>>source>>destination;
    //cout<<numberOfConnectedComponent(n)<<"\n";
    DFS(source,-1);
    if(!visited[destination]) out<<"-1\n";
    else
    {
        vector<ll> backTrack;
        ll currentState=destination;
        while(currentState!=-1)
        {
            backTrack.push_back(currentState);
            currentState=parentTracking[currentState];
        }
        reverse(backTrack);
        out<<backTrack.size()-1<<"\n";
        for(auto x:backTrack) out<<x<<" ";
        out<<"\n";
    }
    memset(visited,0,maximum);
}
