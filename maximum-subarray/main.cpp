#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
///library
int FindMaxCross(vector<int>a,int low,int mid,int high)
{
    int leftSum=-999;
    int sum=0;
    for(int i=mid;i>=low;i--)
    {
        sum+=a[i];
        if(sum>leftSum) leftSum=sum;
        //may to trace
    }
    sum=0;
    int rightSum=-999;
    for(int i=mid+1;i<=high;i++)
    {
        sum+=a[i];
        if(sum>rightSum) rightSum=sum;
        //may to trace
    }
    return rightSum+leftSum;
}
int maxSubArrayRecursion(vector<int> a,int low, int high)
{
    if(high==low) return a[low];
    else{
       int mid=(low+high)/2;
      int leftMax= maxSubArrayRecursion(a,low,mid);
      int rightMax= maxSubArrayRecursion(a,mid+1,high);
      int crossMax= FindMaxCross(a,low,mid,high);
      if(leftMax>=rightMax && leftMax>=crossMax) return leftMax;
      else if(rightMax>leftMax && rightMax>crossMax) return rightMax;
      else return crossMax;
    }
}
int main()
{
    vector<int>v;
    fstream read;
    read.open("input.txt",ios::in);
    while(!read.eof())
    {
        int x;
        read>>x;
        v.push_back(x);
    }
    read.close();
    vector<int> u;u.push_back(0);
    for(int i=1;i<v.size();i++)
    {
        u.push_back(v[i]-v[i-1]);
    }
    cout<<maxSubArrayRecursion(u,0,u.size()-1);
}