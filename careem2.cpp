#include<iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;

struct ride{
	string ridername;
	float charges;
	float distance;
	ride *forward=NULL;
};
struct car{
	string drivername;
	string carname;
	string registration_number;
    float km;
    int car_type;
	car *forward=NULL;
	car *backward=NULL;
	ride *details=NULL;
	


};
car *first=NULL, *Last=NULL, *current=NULL;
void carregistration(){
	current=new car;
	cout<<"Enter the car details: \n";
	cout<<"Enter the name of the driver:";
	cout<<
	cin>>current->drivername;
	cout<<"Enter the car name:";
	cin>>current->carname;
	cout<<"Enter the registration number: ";
	cin>>current->registration_number;
	cout<<"Enter the car type:";
	cin>>current->car_type;
	cout<<"Enter the distance in km:";
	cin>>current->km;
	if(first==NULL){
		first=Last=current;
		
	}
	else{
		Last->forward=current;
		current->backward=Last;
		Last=current;
	}
	cout<<"\n\tsucessfully registered!";
}
void add_ride(){
	car *p=first;
	cout<<"\n \tcars are available \n ";
	while(p!=NULL){
		cout<<""<<p->carname<< endl;
		p=p->forward;
	}
	string choice;
	cout<<"Enter the name of the car for the ride:\n";
	cin>>choice;
	car *r=first;
	while(r->carname!= choice && r!=NULL){
		r=r->forward;
	}
	if(r->carname==choice){
		ride *current=new ride;
		cout<<"\n Enter the details of the car:\n";
		cout<<"Enter the rider name:";
		cin>>current->ridername;
		cout<<"Enter the charges:";
		cin>>current->charges;
		cout<<"Enter the distance in km:";
		cin>>current->distance;
		if(r->details==NULL){
			r->details=current;
		}
		else{
			current->forward=r->details;
			r->details=current;
		}
		cout<<" you have sucessfully book the ride:";
	}
	else{
		cout<<"you have entered wrong car: ";
	}
}
void calearning(){
	car *p = first;
    if (p != NULL && p -> details != NULL) {
        double earnings = 0.0;
        cout << "\n\t\tAll Cars\n";
        while (p != NULL) {
            cout << p -> carname << endl;
            p = p ->forward;
        }
        string choice;
        cout << "\nEnter car name to check earnings: ";
        cin >> choice;
        car *q = first;
        while (q -> carname != choice && q != NULL) {
            q = q -> forward;
        }
        if (q -> carname == choice) {
            ride *p = q -> details;
            while (p != NULL) {
                earnings += p -> charges;
                p = p -> forward;
            }
            cout << "\nTotal earnings of this car " << earnings << endl;
        }
        else cout << "\nCar not found!\n";
    }
    else cout << "\nNo earnings yet!\n";
	
}
void allearning(){
	car *p=first;
	if(p!=NULL & p->details!=NULL){
		double earning=0.0;
		while (p != NULL) {
            ride *q = p -> details;
            while (q != NULL) {
                earning += q -> charges;
                q = q -> forward;
            }
            p = p -> forward;
        }
        cout << "\nTotal earning of all cars " << earning << endl;
    }
    else cout << "\nNo earnings yet! " << endl;
		
		
}
void displaycardetails(){
	car *p=first;
	if(p!=NULL){
		while(p!=NULL){
			cout<<"\n \t car details/n :";
			cout<<"car name:"<<p->carname<<endl;
			cout<<"driver name:"<<p->drivername<<endl;
			cout<<"car type:"<<p->car_type<<endl;
			cout<<"Distance in :"<<p->km<<endl;
			cout<<"registration number:"<<p->registration_number<<endl;
			p=p->forward;
		}
	}
	else{
		cout<<"no information to display";
	}
}
void displayType2() {
    car *p = first;
    if (p != NULL) {
        while (p != NULL) {
            if (p ->car_type == 2) {
                cout << "\n\t\tCar Details \n";
                cout << "Driver Name: " << p -> drivername << endl;
                cout << "Car Name : " << p -> carname << endl;
                cout << "Reg No. " << p ->registration_number << endl;
                cout << "Car type: " << p -> car_type << endl;
                cout << "No of KMs: " << p -> km << endl;
                p = p -> forward;
            }
            else p = p -> forward;
        }
    }
    else cout << "\nNo information to display!" << endl;
}

void ridedisplay(){
	car *p=first;
	if(p!=NULL){
		while(p!=NULL){
			ride *n=p->details;
			while(n!=NULL){
				cout<<"details of the ride:";
				cout<<"driver name:"<<n->ridername<<endl;
				cout<<"charges:"<<n->charges<<endl;
				cout<<"distance"<<n->distance<<endl;
				n=n->forward;
				
			}
			p=p->forward;
		}
	}
	else{
		cout<<"no information to display:";
	}
}
int main(){
	int option;
	do{
		cout<<" \n \t \t  welcome to careem management system \t \n";
		cout<<"\n  1):  Register new car \n  2):  Display information of all registered car \n  3):  Display type-2 car \n  4):  Add new ride \n  5):  Display ride details \n  6):  Display total earning of the specific car \n  7):  Display total earning of all cars \n  0):  exist \n";
		cin>>option;
		switch(option){
			case 0:
				break;
			case 1:
				carregistration();
				break;
			case 2:
				displaycardetails();
				break;
			case 3:
				displayType2();
				break;
			case 4:
				add_ride();
				break;
			case 5:
				ridedisplay();
				break;
			case 6:
				calearning();
				break;
			case 7:
				allearning();
				break;
			default:
				cout<<" \n you have selected invalid option";
				break;
				
				
				
				
		}
		}
		
		while(option!=0);
		return 0;
	}
	




	

