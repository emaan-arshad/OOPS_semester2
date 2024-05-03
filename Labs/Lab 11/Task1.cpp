#include <iostream>
#include <string>

using namespace std;

class  Convert{
protected:
    double value1;
    double value2;


public:
Convert(double value1):value1(value1){}
   virtual  double compute()=0;
};

class l_to_g :public Convert{
public:
l_to_g(double value1):Convert(value1){}
double compute() {
    value2=value1/3.785;//liters to gallons
    return value2;
}
}
;
class f_to_c:public Convert{
public:
f_to_c(double value1):Convert(value1){}
double compute() {
    value2=(value1-32)*(5/9);
    return value2;
}
};

int main() {
Convert *p1,*p2;
p1=new f_to_c(70);
p2=new l_to_g(4);

cout<<"4 liters to gallons: "<<p2->compute();
cout<<"70 Fahrenheit to Celsius :"<<p1->compute();
delete p1;
delete p2;
    return 0;
}
