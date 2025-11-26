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
#include<set>

using namespace std;



class Point
{
    public:
    int x,y;
    void read(ifstream &in)
    {
        in>>x>>y;
    }
      Point operator-(const Point& p)
    {
        return Point{x - p.x , y - p.y};
    }
    void operator-=(const Point& p)
    {
        x-=p.x;
        y-=p.y;
    }
    int operator*(const Point& p)
    {
        return x * p.y - y * p.x;
    }
    //checking ccw/cw rotation
    int triangle(const Point &b,const Point &c)
    {
        Point temp1{b.x,b.y};
        Point temp2{c.x,c.y};
        return (temp1-*this)*(temp2-*this);
    }
};

int sideCheck(Point a,Point x,Point y)
{
    //if point a is upside of line xy return 1;
    //on line return 0
    //else return 1;
    if(x.triangle(y,a)>0) return 1;
    if(x.triangle(y,a)<0) return -1;
    return 0;
}


int crossArea(Point a,Point x,Point y)
{
    return abs((x.triangle(y,a)));
}

set<pair<int,int>> convexHullPoint;


void divideHull(vector<Point> points,int side,Point x,Point y)
{
    int index=-1;
    int maxCrossArea=0;

    for(int i=0;i<points.size();i++)
    {
        int tempArea=crossArea(points[i],x,y);
        if(tempArea>maxCrossArea and sideCheck(points[i],x,y)==side)
        {
            index=i;
            maxCrossArea=tempArea;
        }
    }

    if(index==-1) {convexHullPoint.insert(make_pair(x.x,x.y));convexHullPoint.insert(make_pair(y.x,y.y));return;}

    divideHull(points,-sideCheck(y,points[index],x),points[index],x);
    divideHull(points,-sideCheck(x,points[index],y),points[index],y);

}

void convexHull(vector<Point> &points,ofstream &out)
{
    int minimumX=0;
    int maximumX=0;

    for(int i=1;i<points.size();i++)
    {
        if(points[minimumX].x>points[i].x) minimumX=i;
        if(points[maximumX].x<points[i].x) maximumX=i;
    }
    divideHull(points,1,points[minimumX],points[maximumX]);
    divideHull(points,-1,points[minimumX],points[maximumX]);


    for(auto c: convexHullPoint) cout<<c.first<<" "<<c.second<<"\n";
    for(auto c: convexHullPoint) out<<c.first<<" "<<c.second<<"\n";
}



int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    vector<Point> vp;
    int n;
    in>>n;
    while(n--)
    {
        Point temp;
        temp.read(in);
        vp.push_back(temp);
    }
    convexHull(vp,out);

}
