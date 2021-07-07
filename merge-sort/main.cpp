#include<vector>
#include<fstream>
#include<iostream>
using namespace std;
void Merge(vector<int>& v,int p,int q, int r)
{
    int n1=q-p+1;
    int n2=r-q;
    vector<int> L;
    vector<int> R;
    for(int i=0;i<n1;i++) L.push_back(v[p+i]);
    for(int i=0;i<n2;i++) R.push_back(v[q+1+i]);
    L.push_back(9999);
    R.push_back(9999);
    int i=0,j=0;
    for(int k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
            {   v[k]=L[i];
                i++;
            }
        else{
            v[k]=R[j];
            j++;
        }
    }
}
void MergeSort(vector<int>& v,int p,int r)
{
    if(p<r)
    {
    int q=(p+r)/2;
    MergeSort(v,p,q);
    MergeSort(v,q+1,r);
    Merge(v,p,q,r);
    }
    else return;
}
int main()
{
    vector<int>v;
    fstream read;
    read.open("input.txt",ios::in);
    while (!read.eof())
    {
        int x;
        read>>x;
        v.push_back(x);
    }
    read.close();
    MergeSort(v,0,v.size()-1);
    for(int i=0;i<v.size();i++) cout<<v[i]<<' ';
    
}


