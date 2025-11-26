#include<bits/stdc++.h>
using namespace std;


int price[107];
int weight[107];
int dp[107][100007];

int maxCost(int n,int Capacity)
{
    if(n<0) return 0;
    else if(Capacity==0) return 0;
    else if(dp[n][Capacity]) return dp[n][Capacity];
    else
    {
        int ans=maxCost(n-1,Capacity);
        if(Capacity>=weight[n])
            ans=max(ans,maxCost(n,Capacity-weight[n])+price[n]);
        return dp[n][Capacity]=ans;
    }

}


int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n,maxCap;
    in>>n;

    for(int i=0;i<n;i++)
    {
        in>>weight[i]>>price[i];
    }
    in>>maxCap;
    cout<<maxCost(n-1,maxCap)<<endl;
    out<<maxCost(n-1,maxCap)<<endl;

}


