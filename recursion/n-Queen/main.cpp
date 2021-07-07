#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>> v,int row,int col)
{
    for(int i= 0; i< col; i++)
    {
        if(v[row][i])
        return false;
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(v[i][j]) return false;
    }
    for(int i=row,j=col;i<v[0].size() &&j >=0;i++,j--) if(v[i][j]) return false;
    return true;

}
bool putQueen(vector<vector<int>> v,int col)
{
    if(col>=v[0].size()) return true;
    for(int i=0;i<v[0].size();i++)
    if(isSafe(v,i,col))
    {
        v[i][col]=1 ;
        if(putQueen(v,col+1)) return true;
        v[i][col]=0;

    }
    return false;
}
int main(){
    int n;cin>>n;
    vector<vector<int>> v(n,vector<int>(n,0));
    putQueen(v,n);
    cout<<v[1][0];
}