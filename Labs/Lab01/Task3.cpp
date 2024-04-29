#include <iostream>

using namespace std;







int main()
{
    int size;
  // size=new int;
cout<<"enter the size of array:\n";
cin>>size;
int *arr;
arr=new int[size];
for(int i=0;i<size;i++) {
    cout<<"element no "<<i+1<<" :";
    cin>>arr[i];
}
int target;int flag=0;
cout<<"enter the target number of array:\n";
cin>>target;
for(int i=0;i<size;i++) {
    cout<<arr[i]<<",";
}
for(int k=0;k<size;k++) {
for(int i=1;i<size;i++) {
if (target==arr[k]+arr[i]) {
    cout<<"Indices are :"<<i<<" "<<k;
    flag=1;break;
}}
if (flag==1) break;
}
if (flag==0) cout<<"no such indices found";
 delete[] arr;
    return 0;
}
