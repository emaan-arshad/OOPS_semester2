#include <iostream>
#include <cmath>
using namespace std;


int isPrime(int n) {
if (n<1) {
cout << "not prime" ;
}

for(int i=2;i<=sqrt(n);i++) {
if (n%i==0)
{ return 1;

}
}

return 0;
}



int main() {


int n;

cin >> n;

if (isPrime(n)==1){
cout << "not a prime";
}
else {
cout << "prime";
}

	return 0;
}
