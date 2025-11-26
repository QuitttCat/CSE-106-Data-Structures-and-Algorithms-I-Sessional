//#include<bits/stdc++.h>
#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>
#include<utility>
#include<fstream>
#include<string>
#include<streambuf>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<map>

using namespace std;

#define sort(v) sort(v.begin(),v.end(),compare)

typedef long long ll;


bool compare(tuple<int,bool,int>&a,tuple<int,bool,int>&b)
{
    if(get<2>(a)!=get<2>(b))
    {
        if(get<0>(a)==get<0>(b))
        {
            if(get<1>(a)==false) return true;
            return false;
        }
        return get<0>(a)<get<0>(b);
    }
    else
    {
        if(get<0>(a)==get<0>(b))
        {
            if(get<1>(a)==true) return true;
            return false;
        }
        return get<0>(a)<get<0>(b);
    }
}



int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    vector<tuple<int,bool,int>> v;
    map<pair<int,int>,int> mp;
    ll n;
    in>>n;
    for(ll i=0; i<n; i++)
    {
        ll arr,dep;
        in>>arr>>dep;
        if(arr==dep)
        {
            pair<int,int> tempPair=make_pair(arr,dep);
            if(mp.count(tempPair))
            {

            }
            else
            {
                v.push_back(make_tuple(arr,true,i));
                v.push_back(make_tuple(dep,false,i));
                 mp[tempPair]=1;
            }
        }
        else
        {
              v.push_back(make_tuple(arr,true,i));
               v.push_back(make_tuple(dep,false,i));

        }
    }
    sort(v);
    ll maxCross=0;
    ll answer=-1;
    for(ll i=0; i<v.size(); i++)
    {
        if(get<1>(v[i]))
        {
            maxCross++;
            cout<<"Arrival time  :  "   <<get<0>(v[i])<<" "<<"   Platform Needed : "<<maxCross<<" "<<endl;
            cout<<"\n";
        }
        else
        {
            answer=max(maxCross,answer);
            maxCross--;
            cout<<"Departure time  :  "   <<get<0>(v[i])<<" "<<"   Platform Needed : "<<maxCross<<" "<<endl;
            cout<<"\n";
        }
    }

    cout<<"minimum number of platform needed : "<<answer<<endl;
    out<<answer<<endl;
}

