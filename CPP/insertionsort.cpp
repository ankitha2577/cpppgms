#include<iostream>
using namespace std;
int main ()
{
 int a[100],n,i,j,lb,ub,key;
 cout<<"Enter size of array: "<<"\n";
 cin>>n;
 cout<<"Enter elements of array: "<<"\n";
    for(i=0;i<n;i++)
    {
    cin>>a[i];
    }
cout<<"The elements of array are: "<<"\n";
    for(i=0;i<n;i++)
    {
    cout<<a[i]<<"\t";
    }
cout<<endl<<"enter lb of array: "<<"\n";
cin>>lb;
cout<<"enter ub of array: "<<"\n";
cin>>ub;
for(i=lb+1;i<=ub;i++)
{
        
        key=a[i];
        j=i-1;
        while(j>=lb && a[j]>key)
        {
            a[j+1]=a[j];
            j=j--;
        }
        a[j+1]=key;  
}
for (int i = 0; i < n; i++)
{
    cout<<a[i]<<"\t";
}
return 0;
}