#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
void insertionRecursive(vector<int>v,int n)
{
    if(n==v.size()-1) return;
    else{
        int key=v[n];
        int i=n-1;
        while(i>=0 && key<v[i] )
        {
            v[i+1]=v[i];
            i--;
        }
        v[i+1]=key;
    }
    insertionRecursive(v,n+1);

}
main()
{
    vector<int> v;
    fstream read;
    read.open("input.txt",ios::in);
    while(!read.eof())
    {
        int tmp;
        read>>tmp;
        v.push_back(tmp);
    }
    for(int j=1;j<v.size();j++)
    {
        int key=v[j];
        int  i=j-1;
        while(i>=0 && key<v[i])
        {
            v[i+1]=v[i];
            i--;
        }
        v[i+1]=key;
    }
    for(int i=0;i<v.size();i++) cout<<v[i]<<' ';
    read.close();
  ///  system("pause");
}