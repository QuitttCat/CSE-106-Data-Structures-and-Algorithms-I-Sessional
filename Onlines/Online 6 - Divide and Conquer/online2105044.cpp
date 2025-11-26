//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int peak(vector<int>&v,int left,int right)
{
    if(left==right) return v[left];
    int mid=(left+right)/2;
    return max(peak(v,left,mid),peak(v,mid+1,right));
}


int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    cout<<peak(v,0,n-1)<<endl;
}
