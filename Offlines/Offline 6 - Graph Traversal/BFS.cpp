#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define maximum 100007
#define reverse(v) reverse(v.begin(),v.end())

vector<ll> v[maximum];//adjacency list of the graph
bool visited[maximum];
ll parentTracking[maximum];
ll dist[maximum];

void BFS(ll n)
{
    queue<ll> bfsq;
    bfsq.push(n);
    visited[n]=true;
    dist[n]=0;
    parentTracking[n]=-1;
    while(!bfsq.empty())
    {
        ll topValue=bfsq.front();
        bfsq.pop();
        for(auto x:v[topValue])
        if(!visited[x])
        {
            bfsq.push(x);
            visited[x]=true;
            dist[x]=1+dist[topValue];
            parentTracking[x]=topValue;
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
            BFS(i);
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
    BFS(source);
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
        out<<dist[destination]<<"\n";
        for(auto x:backTrack) out<<x<<" ";
        out<<"\n";
    }
    memset(visited,0,maximum);
}
