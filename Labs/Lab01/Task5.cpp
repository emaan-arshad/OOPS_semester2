//I232560
//Emaan Arshad
//Task 5
//Lab 01
#include <iostream>
#include <string>
using namespace std;
//making struct to store information regarding events
struct event{
    string name;
    string venue;
    string date;
    string organizer;
};
//function to display all data(event vise)
void display(struct event ev[],int n) {
    for(int i=0;i<n;i++){
        cout<<"\nEvent no: "<<i+1<<endl;
        cout<<"Name: "<<ev[i].name<<endl;
        cout<<"Date: " << ev[i].date<<endl;
        cout<<"Venue: "<<ev[i].venue<<endl;
        cout<<"Organizer: "<<ev[i].organizer<<endl;
    }
}
//function to search event based on date
int search_using_date(struct event ev[],int n,string Date) {
  //  int j=1;
    int flag =0;
    for(int i=0;i<n;i++){
        if(Date==ev[i].date){
        cout<<"\nEvent no: "<<i+1<<endl;
        cout<<"Name: "<<ev[i].name<<endl;
        cout<<"Date: " << ev[i].date<<endl;
        cout<<"Venue: "<<ev[i].venue<<endl;
        cout<<"Organizer: "<<ev[i].organizer<<endl;
       // j++;
         flag=1;
    }
    }
  return flag;  
}
//function to take input of events data
void    input(struct event ev[],int n,int i) {
for ( i=i; i<n; i++){
cout<<"\nEnter event no: "<<i+1<<endl;
cout << "Enter event name\n";
getline(cin, ev[i].name);
cout<<"Enter event date\n";
getline(cin, ev[i].date);
cout<<"Enter event venue\n";
getline(cin, ev[i].venue);
cout<<"Enter event organizer\n";
getline(cin, ev[i].organizer);
}
}

//function to add events (reallocating memory for a bigger struct)
struct event* add_event(struct event ev[],int m,int n){
    struct event *ev1=new event[n+m];
     for (int i = 0; i < n; i++) 
        ev1[i] = ev[i];
       
        delete[] ev;
        
        return ev1;
    
}

int main()
{
     
    int choice;
    int n;
    cout<<"enter number of events u want to manage:";
    cin>>n;
   struct event *ev=new event[n];
    cin.ignore();
 input( ev, n,0);
  
    
    
    
    int m;
//the menu
    for(;;) {
cout<<"\n\nPress 1 to add events\nPress 2 to see details of all events\nPress 3 to search for events based on a specific date\nPress 4 to quit the menu : ";
   
   cin>>choice; 
   if(choice==1) {
       cout<<"Add number of events u want to add";
       cin>>m;
         cin.ignore();
      struct event* ev1=add_event(ev,m,n);
    //  delete[] ev;
      ev=ev1;
       
       input(ev,n+m,n);
       n+=m;
   }
    if(choice==2) {
       display(ev,n);
   }
   if(choice==3) {
         cin.ignore();
       cout<<"Enter the date you want details for";
       string Date;
       getline(cin,Date);
     if   (search_using_date(ev,n,Date)==0) cout<<"\nNo event found for entered date\n";
   }
   if(choice==4) {
       break;
   }
    }
    
    
    
    delete[] ev;
    return 0;
}
