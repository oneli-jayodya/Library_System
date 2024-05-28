#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	float price;
	string id,name,eid,aname;
	string c;
	do{
	
	cout<<"Enter book id :";
	cin>>id;
	cout<<" Enter Book name : ";
	cin.ignore();
	getline(cin,name);
	cout<<" Enter Book name : ";
	getline(cin,aname);
	cout<<" Enter Book price : ";
	cin>>price;
	
	//add to file
	fstream file;
	file.open("delbook.dat",ios::app);
	if(file.is_open()){
		file<<id<<' '<<name<<' '<<aname<<' '<<' '<<price<<endl;
		cout<<" Recode added ";
		file.close();
	}else{
		cout<<"\n\tnot opend";
	}	
	
	cout<<"\n\t\t DO you want add more (y/n) :";
	cin>>c;
	}while(c=="y");

	system("cls");
	bool found =false;
	
	cout<<" Enter id ";
	cin>>eid;
	
	fstream file1;
	fstream temp;
	
	file1.open("delbook.dat",ios::in);
	temp.open("temdelbook.dat",ios::out);
	
	if(!file1 || !temp){
		cout<<" File not open"<<endl;
	}else{
		
		while(file1>>id>>name){
			if(id==eid){
				found = true;
			}else{
				temp<<id<<name<<endl;
			}
		}
		
	}
	file1.close();
	temp.close();
	
	if(found){
		remove("delbook.dat");
		rename("temdelbook.dat","delbook.dat");
		cout<<" Deleted"<<endl;
	}else{
		remove("temdelbook.dat");
		cout<<" Not found"<<endl;
		file1.close();
	}
	return 0;
}
