Q1:

Code:
#include<iostream>
#include<string>

using namespace std;

class SecurityTool {
	protected:
		string securityLevel;
		double cost;
		int noDevices;
		
		
		public:
		SecurityTool	(	string securityLevel,double cost ,int noDevices):
			securityLevel(securityLevel),cost(cost),noDevices(noDevices)
			{
			
		}
		
			void performScan() {
				cout<<"Checking for virsuse\n";
				}
};




class FirewallTool :public SecurityTool {
	int ports[23];
	 string protocols[6] = {"HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP"};

	
	 public:
	 		FirewallTool(	string securityLevel,double cost ,int noDevices):
	 				SecurityTool(securityLevel,cost ,noDevices){
					 }
					 void generateList(){
					 	for(int i=0;i<23;i++)
					 	ports[i]=6+i+1;//my roll no is 23I-2560//I took digit 6
					 }
					 void performScan() {
					 	if(securityLevel=="high") {
					 		cout<<"Traffic is allowed from ports :\n";
						 for(int i=0;i<23;i++)
						 cout<<ports[i]<<endl;
						 cout<<"And protocols :\n";
						 for(int i=0;i<6;i++)
						 cout<<protocols[i]<<endl;
						 
						 }
				if(securityLevel=="medium") {
					 		cout<<"Traffic is allowed from ports :\n";
						 for(int i=0;i<23;i++)
						 cout<<ports[i]<<endl;
						 cout<<ports[22]+1<<endl;
						  cout<<ports[22]+2<<endl;
						 cout<<"And protocols :\n";
						 for(int i=0;i<6;i++)
						 cout<<protocols[i]<<endl;
						 
						 }			 
						  
						 	if(securityLevel=="low") {
					 		cout<<"Traffic is allowed from ports :\n";
						 for(int i=0;i<23;i++)
						 cout<<ports[i]<<endl;
						 	 for(int i=0;i<5;i++)
						 cout<<ports[22]+i+1<<endl;
						 cout<<"\nAnd protocols :\n";
						 for(int i=0;i<6;i++)
						 cout<<protocols[i]<<endl;
					     cout<<"TCP"<<endl;
					     cout<<"DCN"<<endl;
						 }
						 
						 	
						 
						 
						 
					 }
					 
	
};

int main() {
		string securityLevel;
		double cost;
		int numDevices;
		
		while(1) {
				
cout << "Enter security level (high, medium, low): ";
      cin >> securityLevel;
        if (securityLevel == "high" || securityLevel == "medium" || securityLevel == "low") {
            break;
        } else {
           cout << "Invalid input! Please enter high, medium, or low.\n" <<endl;
        }
    }

    while (true) {
       cout << "Enter cost (greater than 0):\n ";
        cin >> cost;

        if (cost >= 1) {
            break;
        } else {
          cout << "Invalid input! Cost must be greater than 0\n" <<endl;
        }
    }


    while (true) {
     cout << "Enter number of devices (greater than 0,less than 10): ";
       cin >> numDevices;

       
        if (numDevices >= 1&& numDevices<=10) {
            break;
        } else {
            cout << "Invalid input! Number of devices must be greater than 0,less than 11." << endl;
        }
    
			}
	
	FirewallTool f1(securityLevel,cost,numDevices);
	f1.generateList();
	f1.performScan();
	
	return 0;
	
}
