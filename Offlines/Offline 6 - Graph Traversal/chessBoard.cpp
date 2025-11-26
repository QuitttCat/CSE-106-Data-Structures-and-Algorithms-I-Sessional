#include<bits/stdc++.h>
using namespace std;


vector<pair<int,int>> moves= {{1,2},{2,1},{-1,2},{2,-1},{-1,-2},{-2,-1},{1,-2},{-2,1}};
bool visited[10007][107][107];
int dist[10007][107][107];
int arrayKth[10007];
int n,m;


bool isValidMove(int x,int y,int query)
{
    if(x>=n or y>=m or x<0 or y<0) return false;
    if(visited[query][x][y]) return false;
    return true;
}

void bfsOnGrid(int x,int y,int queryNo)
{
    queue<pair<int,int>> bfsOnGridq;
    visited[queryNo][x][y]=true;
    dist[queryNo][x][y]=0;
    bfsOnGridq.push(make_pair(x,y));

    while(!bfsOnGridq.empty())
    {
        pair<int,int> temp=bfsOnGridq.front();
        bfsOnGridq.pop();
        for(auto moveOnGrid:moves)
        {
            if(isValidMove(temp.first+moveOnGrid.first,temp.second+moveOnGrid.second,queryNo))
            {
                bfsOnGridq.push(make_pair(temp.first+moveOnGrid.first,temp.second+moveOnGrid.second));
                visited[queryNo][temp.first+moveOnGrid.first][temp.second+moveOnGrid.second]=true;
                dist[queryNo][temp.first+moveOnGrid.first][temp.second+moveOnGrid.second]=dist[queryNo][temp.first][temp.second]+1;
            }
        }
    }

}


int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");

    int q,x,y,k;
    in>>n>>m>>q;
    for(int i=1; i<=q; i++)
    {
        in>>x>>y>>k;
        arrayKth[i]=k;
        bfsOnGrid(x,y,i);
    }
    bool possibility=false;
    //int minimumMove=100007;

    long long minimumMove=INT_MAX;


    for(int x=0; x<n; x++)
    {
        for(int y=0; y<m; y++)
        {
            int count=0;
            long long numberOfmove=0;
                for(int z=1; z<=q; z++)
            {
                if(visited[z][x][y])
                {
                    count++;
                    dist[z][x][y]=ceil((float)dist[z][x][y]/(float)arrayKth[z]);
                }
            }
            if(count==q)
            {
                possibility=true;
                //cout<<"debug\n";
                for(int z=1; z<=q; z++)
                {
                    numberOfmove+=dist[z][x][y];
                }
                minimumMove=min(minimumMove,numberOfmove);

            }

        }

    }
     if(possibility==false) out<<"-1\n";
     else out<<minimumMove<<"\n";
}

