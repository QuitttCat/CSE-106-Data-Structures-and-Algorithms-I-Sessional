
#include<queue>
#include<iostream>
#include<string>
using namespace std;


int main()
{
  queue<int> a,b,c;
  while(true)
  {
      string s;
      getline(cin,s);

      if(s=="A approve")
      {
          if(a.size()!=0)
          {
          int temp=a.pop();
          cout<<"Customer "<<<temp<<" gets the loan"<<endl;
          }
          else cout<<"Queue A was already empty"<<endl;
      }
       else if(s=="B approve")
      {
          int temp=b.pop();
          a.push(temp);
      }
      else if(s=="C approve")
      {
          int temp=c.pop();
          a.push(temp);
      }
      else if(s=="C reject")
      {
          int x=c.pop();
          if(b.size()>=c.size())
          {
              b.push(x);
          }
          else
          {
              c.push(x);
          }

      }
      else if(s=="B reject")
      {
          int x=b.pop();
          if(b.size()>=c.size())
          {
              b.push(x);
          }
          else
          {
              c.push(x);
          }

      }
      else if(s=="terminate") return 0;
      else
      {
          int x=stoi(s[s.size()-1]);
          if(b.size()>=c.size())
          {
              c.push(x);
          }
          else
          {
              b.push(x);
          }
      }



  }


}
