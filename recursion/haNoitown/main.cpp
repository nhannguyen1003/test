#include<iostream>
using namespace std;
//pointer
void move(int n,char source,char Auxiliary,char Distination)
{
    if(n==1) cout<<"Move from " << source<<" to " << Distination<<endl;
    else
    {
        move(n-1,source,Distination,Auxiliary);
        move(1,source,Auxiliary,Distination);
        move(n-1,Auxiliary,source,Distination);
    }
    return;
}
int main()
{
    move(3,'A','B','C');
    return 0;

}