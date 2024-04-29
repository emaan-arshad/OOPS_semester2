//I232560
 //Emaan Arshad
 //Task 4
 #include <iostream>
using namespace std;





int main(){
int n;
cout<<"Enter number of elements of the array\n";
cin>>n;
int arr[n];
for (int i=0; i<n; i++){
cout<<"Enter elemnent"<<i+1<< "\n";
cin>>arr[i];
}
int i;
int max=arr[0];
	for ( i=0;i<n;i++)
 {
 	if(max<arr[i]){
	  max=arr[i];break;}
 }
//cout << max;
//cout<<max;
int x = (n-i-1); 
int area;
//cout<<x;
if (x>=i+1){
//if (height[n-1] > max){
area = arr[n-1]*x;
cout<<"The maximum area is:"<< area;
}

else if (x<i+1){
//if (height[0] > max){
area = arr[0]*(i+1);
cout<<"The maximum area is:"<< area;
}


return 0;
}
