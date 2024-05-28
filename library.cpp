#include<iostream>
#include<fstream> //file handling
#include<string>
#include<string.h>
#include<sstream>
#include<conio.h>
#include<windows.h>//to access windows library
#include<ctime>//time and date

using namespace std;


//function declar
void admin();
void librarian();
void add();
void veiw();
void search();
void del();
void issue();
void allissue();
void returnbook();
void update();

//main menu
int main(){
	
	int choice;
	int select;
	int option;
	
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE); //get colors
	
	//main menu
	system("color 04");
	SetConsoleTextAttribute(h,15);//white
	cout<<"\n\n\n\t\t\t===============================================================\n\n";
	cout<<"\t\t\t\t\t    ___             ___   ___    ___\n";
	cout<<"\t\t\t\t  ||\\\\ ||  // \\\\  ||\\\\ ||  // \\\\ ||__   // \\\\ \n";
	cout<<"\t\t\t\t  || \\\\|| //---\\\\ || \\\\|| //---\\\\ __|| //---\\\\ \n";
	SetConsoleTextAttribute(h,3); //cyan
	cout<<"\n\t\t\t\t\t   LIBRARY MANAGMENT SYSTEM \n";
	SetConsoleTextAttribute(h,15);//white
	cout<<"\n\t\t\t===============================================================\n";
	SetConsoleTextAttribute(h,6); //dark yellow
	cout<<"\n\n\t\t\t\t\t | 1. Admin\n";
	SetConsoleTextAttribute(h,14); //yellow
	cout<<"\n\t\t\t\t\t | 2. Librarian\n";
	SetConsoleTextAttribute(h, 4); //red
	cout<<"\n\t\t\t\t\t | 3. Exit System";
	SetConsoleTextAttribute(h, 10); //bright green
	cout<<"\n\n\n\t\t\t Enter your choice : ";
	cin>>choice;
	
	switch(choice){
		//admin
		case 1:{
			
			HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
					
			//bg color
			system("color 60"); //bg yellow text black
			system("cls");
					
			//log variable
			string auser,apw, un , passw;
					
			//admin username and password
			un = "admin";
			passw = "ad@12";
					
			//admin log
			cout<<"\n\n\n";
			cout<<"\n\t\t\t\t\t\t    ADMIN \n";
			cout<<"\n\t\t\t\t===============================================\n";
			cout<<"\n\n\t\t\t\t\t Enter your User Name =>  ";
			cin>>auser;
			cout<<"\n\t\t\t\t\t Enter Your Password =>  ";
			cin>>apw;
			
			//correct login or not
			if(auser == un && apw == passw){
						
				SetConsoleTextAttribute(h, 0x2F); //green
				cout<<"\n\n\t\t\t\t\t\tYour Login Successful!";
				Sleep(500);
				system("cls");
				cout<<"\n\n\n";
				admin();
			}else{
				SetConsoleTextAttribute(h, 4); // red
				cout<<"\n\n\t\t\t\tYour Password or Username is wrong ! Try Again!!";
				Sleep(1000);
				system("cls");
				main();
			}
			
			break;
		}
		
		//librarian
		case 2:{
			
			HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
						
			//bg color
			system("color E0"); //bg light yellow
			system("cls");
					
			//log variable
			string libuser,libpw ,luser,lpw;
			int count;		
			
					
			//librarian log
			cout<<"\n\n\n";
			cout<<"\n\t\t\t\t\t\t    LIBRARIAN \n";
			cout<<"\n\t\t\t\t===============================================\n";
			cout<<"\n\n\t\t\t\t\t Enter Your Password =>  ";
			cin>>libpw;
			cout<<"\n\t\t\t\t\t Enter your User Name =>  ";
			cin>>libuser;

			
			fstream File;
			File.open("usepw.dat", ios::in); //the output file stream
			if(File.is_open()){
				string line;
				
				while(getline(File,line)){   //read end of line
					string apw,aun;
					istringstream iss(line);
					getline(iss, apw, ' ');
					getline(iss, aun, ' ');
					
					//check enter id enter id eual to the librarian id
					if(apw==libpw && aun==libuser){
						
						SetConsoleTextAttribute(h, 0x2F);
						cout<<"\n\n\t\t\t\t\t\tYou can Access";
						SetConsoleTextAttribute(h, 7);
						File.close();
						Sleep(2000);
						system("cls");
						librarian();
					}
				}
				SetConsoleTextAttribute(h, 0x4F);
					cout<<"\n\n\t\t\t\t\tYou can't Access !! wrong password or username";
					SetConsoleTextAttribute(h, 7);
					File.close();
					Sleep(4000);
					system("cls");
					main();
					
			}else{
				SetConsoleTextAttribute(h,4);
				cout<<"\n\n\t\t\t\t\t-----Not found----";
			}
		
			
			break;
		}
		
		//Exit
		case 3:{
			SetConsoleTextAttribute(h,15);
			cout<<"\n\n\t\t\t\t\t\t~~~~~ Have a Nice Day ~~~~~\n\n\n";
			break;
		}
		
		//wrong choice
		default:{
			SetConsoleTextAttribute(h, 0x4F);
			cout<<"\n\n\t\t\t!!! Wrong choise !!";
			Sleep(1000);
			system("cls");
			main();
			break;
		}
		
			
	}
	
	return 0;
}

//admin task
void admin(){
	
	int select;
	
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

	system("color 04");
	SetConsoleTextAttribute(h, 6);
	
	//admin menu
	cout<<"\n\t\t\t\t\t\t    ADMIN \n";
	cout<<"\n\t\t\t\t===============================================\n";
	cout<<"\n\n\t\t\t\t\t | 1. Sign Up\n";
	cout<<"\n\t\t\t\t\t | 2. Fine Rate\n";
	cout<<"\n\t\t\t\t\t | 3. Borrowing Limits\n";
	cout<<"\n\t\t\t\t\t | 4. Back To Main";
	SetConsoleTextAttribute(h, 10);
	cout<<"\n\n\n\t\t\t\t\t Select your choice : ";
	cin>>select;
	
	
	switch(select){
		
		//librarian registration
		case 1:{
			system("cls");
					
			string sname,sid,semail;
			int sphone;
					
			SetConsoleTextAttribute(h,14);
			cout<<"\n\n\t\t\t\t\t\t       SIGN UP \n";
			cout<<"\n\t\t\t\t-------------------------------------------------\n";
			SetConsoleTextAttribute(h,15);
			cout<<"\n\n\t\t\t\t    Enter ID Number :  \t";
			cin>>sid;
			
			fstream myFile;
			myFile.open("librarian.dat", ios::in); //the output file stream
			if(myFile.is_open()){
				string line;
				while(getline(myFile,line)){   //read line by line
					istringstream ss(line);
					string id;
					getline(ss,id,',');
					
					//check enter id enter id eual to the librarian id
					if(id==sid){
						SetConsoleTextAttribute(h, 0x4F);
						cout<<"\n\n\t\t\t\t\tYou alredy registerd";
						SetConsoleTextAttribute(h, 7);
						myFile.close();
						Sleep(2000);
						system("cls");
						admin();
					}
					
						
				}
			}else{
				SetConsoleTextAttribute(h,4);
				cout<<"\n\n\t\t\t\t\t-----Not found----";
			}
			
			cout<<"\n\t\t\t\t    Enter your Name :  \t";
			cin.ignore();
			getline(cin,sname);
			cout<<"\n\t\t\t\t    Enter Email Address :  ";
			cin>>semail;
			cout<<"\n\t\t\t\t    Enter Phone Number :  ";
			cin>>sphone;
					
			//librarian recode it in notepad
			
				fstream myFile1;
				myFile1.open("librarian.dat", ios::app); //the output file stream
				if(myFile1.is_open()){
					SetConsoleTextAttribute(h, 0x2F);
					cout<<"\n\n\t\t\t\t\t You are registerd";
					myFile1<<sid<<','<<sname<<','<<semail<<','<<sphone<<' '<<endl;	
					myFile1.close();
				}else{
					cout<<"\n\n\t\t\t\t\t File not opend";
				}
			
				
			
						
			//admin give username and password
			SetConsoleTextAttribute(h,14);
			string luser, lpw;
			
			
			cout<<"\n\n\t\t\t\t   Create Username & Password to Librarian \n\n";
			SetConsoleTextAttribute(h,15);
			cout<<"\t\t\t\t\t  Enter Password : ";
			cin>>lpw;
			cout<<"\t\t\t\t\t  Enter Username : ";
			cin>>luser;
			
			//save usernames and pws		
			fstream File;
			File.open("usepw.dat", ios::app);
			if(File.is_open()){
				File<<lpw<<' '<<luser<<endl;
				SetConsoleTextAttribute(h,0x2F);
				cout<<"\n\n\t\t\t\t\t Successfull";
				File.close();
			}else{
				SetConsoleTextAttribute(h,0x4F);
				cout<<" File Open Failed !!";
				
			}
			
			Sleep(1000);
			system("cls");
			system("color 04");
			admin();
			
			break;
		}
		
		//fine rate
		case 2:{
			system("cls");
					
			float rate ;
			int r;
			fstream Frate;
	
			Frate.open("rate.dat",ios::in);
			if(!Frate){
				cout<<" File not Found !!";
		
			}else{
				
				string line;
				while(getline(Frate,line)){
				istringstream iss(line);	
				SetConsoleTextAttribute(h,5);
				cout<<"\n\n\t\t\t\t\t\t        Fine Rate \n";
				cout<<"\n\t\t\t\t---------------------------------------------------\n";
				SetConsoleTextAttribute(h,2);
				cout<<"\n\n\t\t\t\t\t Current Fine Rate is  : Rs."<<line;
				}
		}
				SetConsoleTextAttribute(h,15);
				cout<<"\n\n\t\t\t\t Do you want to change the rate accoding to the rules ?";
				cout<<"\n\t\t\t\t\t\t\t1. Yes";
				cout<<"\n\t\t\t\t\t\t\t2. No";	
				cout<<"\n\n\t\t\t\t Please enter your choice : ";
				cin>>r;
			
				if(r==1){
				
				fstream Frate;		
				Frate.open("rate.dat", ios::out); //overwrite
				if(!Frate){
					SetConsoleTextAttribute(h,0x4F);
					cout<<"\n\t\t\t\t\tFile Open Failed !!";
				}else{
					cout<<"\n\n\t\t\t\t\t Enter new fine rate :  Rs.";
					cin>>rate;
					Frate <<rate<<endl;	
					SetConsoleTextAttribute(h,2);
					cout<<"\n\n\t\t\t\t\t New Fine Rate is  : Rs."<<rate<<endl;
							
				}
				Frate.close();
				SetConsoleTextAttribute(h,15);
				cout<<"\n\n\n\t\t\t\tPress any key to continue.....";
				getche();
               	system("cls");
               	admin();
					
			}else if(r==2){
				SetConsoleTextAttribute(h,15);
				cout<<"\n\n\n\t\t\t\tPress any key to continue.....";
				getche();
                system("cls");
                admin();
			}		
			break;
		}
		
		//borrow limit
		case 3:{
			system("cls");
					
			int limit ;
			int o;
			
			fstream Flimit;
			Flimit.open("limit.dat",ios::in);
			if(!Flimit){
				cout<<" File not Found !!";
		
			}else{
				
				string line;
				while(getline(Flimit,line)){
				istringstream iss(line);	
				SetConsoleTextAttribute(h,5);
				cout<<"\n\n\t\t\t\t\t\t        Borrow Limit \n";
				cout<<"\n\t\t\t\t---------------------------------------------------\n";
				SetConsoleTextAttribute(h,2);
				cout<<"\n\n\t\t\t\t\t Current Borrow Limit is  : "<<line;
				}
			}
				SetConsoleTextAttribute(h,15);
				cout<<"\n\n\t\t\t\t Do you want to change the rate accoding to the rules ?";
				cout<<"\n\t\t\t\t\t\t\t1. Yes";
				cout<<"\n\t\t\t\t\t\t\t2. No";	
				cout<<"\n\n\t\t\t\t Please enter your choice : ";
				cin>>o;
			
				if(o==1){
				
				fstream Flimit;		
				Flimit.open("limit.dat", ios::out); //overwrite
				if(!Flimit){
					SetConsoleTextAttribute(h,0x4F);
					cout<<"\n\t\t\t\t\tFile Open Failed !!";
				}else{
					cout<<"\n\n\t\t\t\t\t Enter new Borrow Limit :  ";
					cin>>limit;
					Flimit <<limit<<endl;	
					SetConsoleTextAttribute(h,2);
					cout<<"\n\n\t\t\t\t\t New Borrow Limit is  :  "<<limit<<endl;
							
				}
				Flimit.close();
				SetConsoleTextAttribute(h,15);
				cout<<"\n\n\n\t\t\t\tPress any key to continue.....";
				getche();
               	system("cls");
               	admin();
					
			}else if(o==2){
				SetConsoleTextAttribute(h,15);
				cout<<"\n\n\n\t\t\t\tPress any key to continue.....";
				getche();
                system("cls");
                admin();
			}		
			break;
		}
		
		//back to main
		case 4:{
			system("cls");
			main();
			break;
		}
		
		//wrong 
		default:
			system("cls");
			main();
				
	}			
					
}

//librarian tasks
void librarian(){
	
	system("cls");
	int option;
	
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	
	system("color 04");
	SetConsoleTextAttribute(h, 14);
	cout<<"\n\t\t\t\t\t\t    LIBRARIAN \n";
	cout<<"\n\t\t\t\t===============================================\n";
	cout<<"\n\n\t\t\t\t\t | 1. Add Details\n";
	cout<<"\n\t\t\t\t\t | 2. Delete Details\n";
	cout<<"\n\t\t\t\t\t | 3. Search Details\n";
	cout<<"\n\t\t\t\t\t | 4. All Details\n";
	cout<<"\n\t\t\t\t\t | 5. Issue Books\n";
	cout<<"\n\t\t\t\t\t | 6. All Issue Books\n";
	cout<<"\n\t\t\t\t\t | 7. Return Books\n";
	SetConsoleTextAttribute(h, 4);
	cout<<"\n\t\t\t\t\t | 8. Back To Main";
	SetConsoleTextAttribute(h, 10);
	cout<<"\n\n\n\t\t\t\t\t Select your choice : ";
	cin>>option;
	
	switch(option){
		
		case 1:{
			//add books and borrowers 
			add();
	
			break;
		}
		case 2:{
			//delete books and borrowers
			del();
			
			break;
		}
		case 3:{
			//search books and borrowers
			search();
			break;
		}
		case 4:{
			//display all details added
			system("cls");
		    veiw();
		    librarian();
			break;
		}
		
		case 5:{
			//issue books
			issue();
			break;
		}
		case 6:{
			allissue();
			break;
		}
		case 7:{
			//return books
			returnbook();
			break;
		}
		
		case 8:{
			system("cls");
			//back to start
			main();
			break;
		}
		default:
			SetConsoleTextAttribute(h,0x4F);
			cout<<" \n\n\t\t\t\t\tchoose wrong  !! Try again ***";
			Sleep(1000);
			system("color 04");	
			librarian();
	}
}

//add details
void add(){
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	int ad;
	system("cls");
	
	system("color 04");	
	SetConsoleTextAttribute(h, 7);
	cout<<"\n\t\t\t\t\t\t   ADD DETAILS \n";
	cout<<"\n\t\t\t\t===============================================\n";
	cout<<"\n\n\t\t\t\t\t | 1. Add Book Details\n";
	cout<<"\n\t\t\t\t\t | 2. Add Borrower Details\n";
	SetConsoleTextAttribute(h, 4);
	cout<<"\n\t\t\t\t\t | 3. Back ";
			
	SetConsoleTextAttribute(h, 10);
	cout<<"\n\n\n\t\t\t\t\t Select your choice : ";
	cin>>ad;
	
	//add book details		
	if(ad==1){
				
		float price;
		string bname, aname, isbn,genre,pub;
		string status="Available";
		
		system("cls");
		SetConsoleTextAttribute(h, 8);
		cout<<"\n\n\t\t\t\t\t\t   ADD BOOK DETAILS \n";
		cout<<"\n\t\t\t\t===============================================\n";
		SetConsoleTextAttribute(h, 15);
		cout<<"\n\n\t\t\t\t Enter Book's ISBN No. : ";
		cin>>isbn;
		fstream cbook;
			cbook.open("book.dat", ios::in); //the output file stream
			if(cbook.is_open()){
				string line;
				while(getline(cbook,line)){   //read line by line
					istringstream ss(line);
					string id;
					getline(ss,id,'\t');
					
					//check is equal to the book isbn
					if(id==isbn){
						SetConsoleTextAttribute(h, 0x4F);
						cout<<"\n\n\t\t\t\t\t Book is alredy Added"; //if it equal show this
						SetConsoleTextAttribute(h, 7);
						cbook.close();
						Sleep(2000);
						system("cls");
						add();
					}
			}
		}else{
		cout<<"\n\n\t\t\t\t\t Not Found";
		}	
		cout<<"\n\n\t\t\t\t Enter Book's Name : ";
		cin.ignore();
		getline(cin,bname);
		cout<<"\n\n\t\t\t\t Enter Author's Name : ";
		getline(cin,aname);
		cout<<"\n\n\t\t\t\t Enter Publisher : ";
		getline(cin,pub);
		cout<<"\n\n\t\t\t\t Enter Genre of Book : ";
		cin>>genre;
		cout<<"\n\n\t\t\t\t Enter Price of Book : Rs. ";
		cin>>price;
		cout<<"\n\n\t\t\t\t Status of Availability : ";
		cout<<status;
		
		
		
			//not equal then add
		fstream mybook;
		mybook.open("book.dat", ios::app); //the output file stream
		if(mybook.is_open()){
				
			mybook<<isbn<<'\t'<<bname<<'\t'<<aname<<'\t'<<pub<<'\t'<<genre<<'\t'<<price<<'\t'<<status<<endl;
			SetConsoleTextAttribute(h, 0x2F);
			cout<<"\n\n\t\t\t\t\t Book is Added";
			SetConsoleTextAttribute(h, 15);
			mybook.close();
			Sleep(2000);
			system("cls");
			add();
		}else{
			cout<<"\n\n\t\t\t\t\t File not opend!!";
		}
	
				
	//add borrowers			
	}else if(ad==2){
		string mname,date,mid;
		int pnum;
				
		system("cls");
		SetConsoleTextAttribute(h, 8);
		cout<<"\n\n\t\t\t\t\t\t   ADD BORROWER DETAILS \n";
		cout<<"\n\t\t\t\t\t===============================================\n";
		SetConsoleTextAttribute(h, 15);
		cout<<"\n\n\t\t\t\t\tEnter ID :  ";
		cin.ignore();
		getline(cin,mid);
		fstream cborrow;
			cborrow.open("barrower.dat", ios::in); //the output file stream
			if(cborrow.is_open()){
				string line;
				while(getline(cborrow,line)){   //read line by line
					istringstream ss(line);
					string id;
					getline(ss,id,'\t');
					
					//check is equal to the borrower id
					if(id==mid){
						SetConsoleTextAttribute(h, 0x4F);
						cout<<"\n\n\t\t\t\t\t Borrower is alredy Added"; //if it equal show this
						SetConsoleTextAttribute(h, 7);
						cborrow.close();
						Sleep(2000);
						system("cls");
						add();
					}
			}
			}else{
				cout<<"\n\n\t\t\t\t\t NOT FOUND ";
			}
		cout<<"\n\n\t\t\t\t\tEnter Name :  ";
		getline(cin,mname);
		cout<<"\n\t\t\t\t\tEnter Join Date : ";
		getline(cin,date);
		cout<<"\n\t\t\t\t\tEnter phone Number : ";
		cin>>pnum;
		
			
				
		fstream addbarrow;
		addbarrow.open("barrower.dat", ios::app); //the output file stream
		if(addbarrow.is_open()){
			addbarrow<<mid<<'\t'<<mname<<'\t'<<date<<'\t'<<pnum<<endl;	
		//	addbarrow<<mid<<','<<mname<<','<<date<<','<<pnum<<endl;
			SetConsoleTextAttribute(h, 0x2F);
			cout<<"\n\n\t\t\t\t\t Borrow is Added";
			SetConsoleTextAttribute(h, 15);
			addbarrow.close();
			Sleep(2000);
			system("cls");
			add();
		}else{
			cout<<"\n\n\t\t\t\t\t File not opend!!";
		}
	
	}else if(ad==3){
				
		system("cls");
		librarian();
				
	}else{
		SetConsoleTextAttribute(h, 0x4F);
		cout<<"\n\n\t\t\t\t\t Wrong number !! ";
		Sleep(2000);
		system("cls");
		add();
	}
}

//display details
void veiw(){

	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	int v;
	system("cls");
	
	system("color 04");		
	SetConsoleTextAttribute(h, 7);
	cout<<"\n\t\t\t\t\t\t   ALL DETAILS \n";
	cout<<"\n\t\t\t\t===============================================\n";
	cout<<"\n\n\t\t\t\t\t | 1. All Book Details\n";
	cout<<"\n\t\t\t\t\t | 2. All Borrower Details\n";
	SetConsoleTextAttribute(h, 4);
	cout<<"\n\t\t\t\t\t | 3. Back\n";
			
	SetConsoleTextAttribute(h, 10);
	cout<<"\n\n\n\t\t\t\t\t Select your choice : ";
	cin>>v;
	
	//display books
	if(v==1){
	
	    system("cls");
	    SetConsoleTextAttribute(h, 9);
		cout<<"\n\n\t\t\t\t\t\t      BOOKS LIST";
		cout<<"\n\t\t\t\t\t-------------------------------------";
	 	SetConsoleTextAttribute(h, 15);
	 	
	    // Open the file in input mode
	    ifstream all("book.dat");
	    if(all.is_open()){
	    	string line;
	    	SetConsoleTextAttribute(h, 11);
	    	cout << "\n\n\n\t\t\tISBN\tBOOK NAME\tAUTHOR\tPUBLISHER\tGENRE\tPRICE\tSTATUS\n";
	    	cout << "\n\t\t\t=======================================================================\n";
	    	while(getline(all,line)){
	    		SetConsoleTextAttribute(h, 15);
	    		//display line
	    		cout<<'\n'<<'\t'<<'\t'<<'\t'<<line<<endl;
			}
			all.close();
		}
		else{
			cout<<"not opened !";
		}
	    cout<<"\n\n\n\t\t\t\tPress any key to continue.....";
		getche();
	    system("cls");
	    veiw();
	}
	
	//display borrowers
	else if(v==2){
	
	    system("cls");
	    SetConsoleTextAttribute(h, 9);
		cout<<"\n\n\t\t\t\t\t\t      BORROWER LIST";
		cout<<"\n\t\t\t\t\t---------------------------------------------";
	 	
	 	
	    // Open the file in input mode
	    ifstream all("barrower.dat");
	    if(all.is_open()){
	    	string line;
	    	SetConsoleTextAttribute(h, 11);
	    	cout << "\n\n\n\t\t\t\tID"<<"\tNAME"<<"\t\tJOIN DATE"<<"\tContact Number\n";
	    	cout << "\t\t\t\t=====\t=========\t===========\t===============\n";
	    	while(getline(all,line)){
	    		SetConsoleTextAttribute(h, 15);
	    		cout<<'\n'<<'\n'<<'\t'<<'\t'<<'\t'<<'\t'<<line<<endl;
	    		
			}
		
			all.close();
		}
		else{
			cout<<"not opened !";
		}
	    cout<<"\n\n\n\t\t\t\tPress any key to continue.....";
		getche();
	    system("cls");
		veiw();
	//back to menu
	}else if(v==3){
		librarian();
	
	//wrong number
	}else{
		SetConsoleTextAttribute(h, 0x4F);
		cout<<"\n\n\t\t\t\t\t Wrong number !! ";
		Sleep(2000);
		system("cls");
		librarian();
	}
}

//search books
void search(){
	
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	int c;
	string sname;
	int schoice;
	
	system("cls");
	
	system("color 04");
	//search menu		
	SetConsoleTextAttribute(h, 7);
	cout<<"\n\t\t\t\t\t\t   SEARCH DETAILS \n";
	cout<<"\n\t\t\t\t===============================================\n";
	cout<<"\n\n\t\t\t\t\t | 1. Search Book Details\n";
	cout<<"\n\t\t\t\t\t | 2. Search Borrower Details\n";
	SetConsoleTextAttribute(h, 4);
	cout<<"\n\t\t\t\t\t | 3. Back\n";
			
	SetConsoleTextAttribute(h, 10);
	cout<<"\n\n\n\t\t\t\t\t Select your choice : ";
	cin>>c;
	
	//search book
	if(c==1){
	
	    system("cls");
	    string sid;
	    SetConsoleTextAttribute(h, 1);
		cout<<"\n\n\t\t\t\t\t\t     SEARCH BOOKS";
		cout<<"\n\t\t\t\t\t-------------------------------------";
	 	SetConsoleTextAttribute(h, 15);
	 	cout<<"\n\n\n\t\t\t\t\t  1. By Enter Book ISBN number  ";
	 	cout<<"\n\n\n\t\t\t\t\t  2. By Enter Book Name  ";
	 	SetConsoleTextAttribute(h, 2);
	 	cout<<"\n\n\t\t\t\t Enter your choice : ";
	 	cin>>schoice;
	 	SetConsoleTextAttribute(h, 15);
	 	switch(schoice){
		 
	 		case 1:{
			 	cout<<"\n\n\n\n\t\t\t\t\t\t  Enter Book ISBN number  :";
			 	cin>>sid;
			   // check isbn are equal and print
			    ifstream sbook("book.dat");
			    if(sbook.is_open()){
			    	string line;
			    	SetConsoleTextAttribute(h, 11);
			    	//cout << "\n\n\n"<<'\t'<<'\t'<<'\t'<<"ISBN"<<'\t'<<"BOOK NAME"<<'\t'<<"AUTHOR"<<'\t'<<' '<<"PRICE"<<'\t'<<"STATUS \n";
			    	while(getline(sbook,line)){
			    		string spw;
						istringstream iss(line);
						getline(iss, spw, '\t');
					//	cout<<spw;
						if(spw==sid){
		
							
			    			SetConsoleTextAttribute(h, 15);
			    			cout << "\n\n\n\t\t\tISBN\tBOOK NAME\tAUTHOR\tPUBLISHER\tGENRE\tPRICE\tSTATUS\n";
			    			cout << "\n\t\t\t===================================================================\n";
			    			cout<<"\n\t\t\t"<<line<<endl;
			    			
			    		}
					}
		
			    		cout<<"\n\n\n\t\t\t\tPress any key to continue.....";
						getche();
		   				search();
						
						sbook.close();
				}else{
					cout<<"\n\t\t\t\t Not Open ";
				}
			break;
		}
		case 2:{
			cout<<"\n\n\n\n\t\t\t\t\t\t  Enter Book Name  :";
		 	cin>>sname;
		   // check isbn are equal and print
		    ifstream sbook("book.dat");
		    if(sbook.is_open()){
		    	string line;
		    	SetConsoleTextAttribute(h, 11);
		    	while(getline(sbook,line)){
		    		string spw;
		    		string snm;
					istringstream iss(line);
					getline(iss, spw, '\t');
					getline(iss, snm, '\t');
					if(snm==sname){
	
						
		    			SetConsoleTextAttribute(h, 15);
		    			cout << "\n\n\n\t\t\tISBN\tBOOK NAME\tAUTHOR\tPUBLISHER\tGENRE\tPRICE\tSTATUS\n";
		    			cout << "\n\t\t\t=======================================================================\n";
		    			cout<<"\n\t\t\t"<<line<<endl;
		    			
		    		}
				}
	
		    		cout<<"\n\n\n\t\t\t\tPress any key to continue.....";
					getche();
	   				search();
					
					sbook.close();
			}else{
				cout<<"\n\t\t\t\t Not Open ";
			}
			break;
		}
	}
	//search borrower
	}else if(c==2){
	
	    system("cls");
	    string sbid;
	    SetConsoleTextAttribute(h, 1);
		cout<<"\n\n\t\t\t\t\t\t     SEARCH BORROWERS";
		cout<<"\n\t\t\t\t\t-------------------------------------";
	 	SetConsoleTextAttribute(h, 15);
	 	cout<<"\n\n\n\t\t\t\t\t Enter  ID number : ";
	 	cin>>sbid;
	 	
	    // check id are equal and print
	    ifstream sborrow("barrower.dat");
	    if(sborrow.is_open()){
	    	string line;
	    	SetConsoleTextAttribute(h, 11);
	    	while(getline(sborrow,line)){
	    		string sidd;
				istringstream iss(line);
				getline(iss, sidd, '\t');
				if(sidd==sbid){
	    			SetConsoleTextAttribute(h, 15);
	    			cout << "\n\n\n\t\t\t\tID"<<"\tNAME"<<"\t\tJOIN DATE"<<"\tContact Number\n";
	    			cout << "\n\t\t\t\t=====\t=========\t===========\t===============\n";
	    			cout<<"\n\t\t\t\t"<<line<<endl;
	    			sborrow.close();
	    			
	    		}
	    			
			}
				cout<<"\n\n\n\t\t\t\tPress any key to continue.....";
				getche();
	   			search();
	   			cout<<" \n\t\t\t\tNOT AVAILABLE THIS BOOK !";
	    		sborrow.close();
			
			}else{
				cout<<"\n\t\t\t\t Not Open ";
			}
			
		}else if(c==3){
			librarian();
		}else{
			SetConsoleTextAttribute(h, 0x4F);
			cout<<"\n\n\t\t\t\t\t Wrong number !! ";
			Sleep(2000);
			system("cls");
			librarian();
		}
}
			
//delete details
void del(){
	
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	int d;
	system("cls");
	
	system("color 04");		
	SetConsoleTextAttribute(h, 7);
	cout<<"\n\t\t\t\t\t\t   DELETE DETAILS \n";
	cout<<"\n\t\t\t\t===============================================\n";
	cout<<"\n\n\t\t\t\t\t | 1. Delete Book Details\n";
	cout<<"\n\t\t\t\t\t | 2. Delete Borrower Details\n";
	SetConsoleTextAttribute(h, 4);
	cout<<"\n\t\t\t\t\t | 3. Back ";
			
	SetConsoleTextAttribute(h, 10);
	cout<<"\n\n\n\t\t\t\t\t Select your choice : ";
	cin>>d;
	
	//book delete
	if(d==1){
		
		system("cls");
		float tprice;
		string tbname, taname, tgenre, tstatus, tpub ,isbn;
		string tisbn;
		int count;
		bool found =false;
		
	    SetConsoleTextAttribute(h, 7);
		cout<<"\n\n\t\t\t\t\t\t     DELETE BOOKS";
		cout<<"\n\t\t\t\t\t-------------------------------------";
	 	
	 	fstream bfile;
		fstream tfile;
		
		//file in output mode
	    tfile.open("tempbk.dat", ios::out);
	    bfile.open("book.dat",ios::in);
	    
	    
	    if(!tfile||!bfile){
	    
			cout<<" File not open"<<endl;
			
		}else{
			
			SetConsoleTextAttribute(h, 15);
	 		cout<<"\n\n\n\t\t\t\t\t Enter Book ISBN number : ";
	 		cin>>isbn;
	 		while(bfile>>tisbn>>tbname>>taname>>tpub>>tgenre>>tprice>>tstatus){
	 		//	cout<<tisbn;
	 		//	cout<<isbn;
	 			if(tisbn==isbn){
	 				//cout << "Book found true" << endl;
	 				found = true;
	 				
				}else{
					tfile<<tisbn<<'\t'<<tbname<<'\t'<<taname<<'\t'<<tpub<<'\t'<<tgenre<<'\t'<<tprice<<'\t'<<tstatus;
				}
			}			
		
		bfile.close();
		tfile.close();
		
		if(found==true){
			remove("book.dat");
			rename("tempbk.dat","book.dat");
			SetConsoleTextAttribute(h, 0x2F);
			cout<<"\n\t\t\t\tDeleted Successfully "<<endl;
			Sleep(3000);
			del();
		}else{
			remove("tempbk.dat");
			cout<<" Not found"<<endl;
			//bfile.close();
			Sleep(3000);
			del();
		}
	}
	
	//borrow delete	
	}else if(d==2){
	
		system("cls");
		string mname,date,mid,id;
		int pnum;
				
		int count;
		bool found =false;
		
	    SetConsoleTextAttribute(h, 7);
		cout<<"\n\n\t\t\t\t\t\t     DELETE BORROWERS";
		cout<<"\n\t\t\t\t\t-------------------------------------";
	 	
	 	
	 	fstream tborrowfile;
		fstream bborrowfile;
		
		//file in output mode
	    tborrowfile.open("tempborrow.dat", ios::out);
	    bborrowfile.open("barrower.dat",ios::in);
	    
	    
	    if(!tborrowfile||!bborrowfile){
	    
			cout<<" File not open"<<endl;
			
		}else{
			
			SetConsoleTextAttribute(h, 15);
	 		cout<<"\n\n\n\t\t\t\t\t Enter borrow ID number : ";
	 		cin>>id;
	 		while(bborrowfile>>mid>>mname>>date>>pnum){
	 			cout<<mid;
	 			cout<<id;
	 			if(mid==id){
	 			//	cout << "Borrow found true" << endl;
	 				found = true;
	 				
				}else{
					tborrowfile<<mid<<'\t'<<mname<<'\t'<<date<<'\t'<<pnum;
				}
			}
			
		}
		
		bborrowfile.close();
		tborrowfile.close();
		
		if(found==true){
			remove("barrower.dat");
			rename("tempborrow.dat","barrower.dat");
			SetConsoleTextAttribute(h, 0x2F);
			cout<<"\n\t\t\t\tDeleted Successfully "<<endl;
			Sleep(3000);
			del();
		}else{
			remove("tempborrow.dat");
			cout<<" Not found"<<endl;
			Sleep(3000);
			del();
		}
	
		
	//back to menu	
	}else if(d==3){
		
		librarian();
		
	//enter wrong num
	}else{
		
		SetConsoleTextAttribute(h, 0x4F);
		cout<<"\n\n\t\t\t\t\t Wrong number !! ";
		Sleep(2000);
		system("cls");
		librarian();
	}
}



void issue(){
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	string isdate,boid,bonam,is,due;
	string i;
	int month,day,year,date;
	
	system("cls");
	
	system("color 04");	
	
		
	fstream ratee;
	ratee.open("limit.dat", ios::in);
	if(ratee.is_open()){
		string line;
		while(getline(ratee,line)){
			istringstream iss(line);
			SetConsoleTextAttribute(h, 1);
			cout<<"\n\t\t\t\t\t\t   ISSUE BOOK \n";
			cout<<"\n\t\t\t\t===============================================\n";
			
			SetConsoleTextAttribute(h, 8);
			cout<<" \n\n\t\t\t\tyou can borrow "<<line<<" books at once ";
			
			do{
			SetConsoleTextAttribute(h, 7);
			cout<<" \n\n\t\t\t\tEnter Borrower id : ";
		    cin>>boid;
		    
		    ifstream sborrow("barrower.dat");
	    if(sborrow.is_open()){
	    	string line;
	    	SetConsoleTextAttribute(h, 11);
	    	while(getline(sborrow,line)){
	    		string idd;
				istringstream iss(line);
				getline(iss, idd, '\t');
				if(idd==boid){
	    			SetConsoleTextAttribute(h, 2);
	    			cout << "\n\t\t\t\tID"<<"\t\tNAME"<<"\t\tJOIN DATE"<<"\tContact Number\n";
	    			cout<<"\n\t\t\t\t"<<line<<endl;
	    			sborrow.close();
	    			
	    		}else{
	    			SetConsoleTextAttribute(h, 0x4F);
					cout<<"\n\n\t\t\t\tBorrower is not in Recode !! ";
					Sleep(2500);
					system("cls");
					librarian();
				}
	    			
			}
			}else{
				cout<<"\n\t\t\tNot Opend ! ";
			}
		    SetConsoleTextAttribute(h, 15);
			cout<<" \n\t\t\t\t\t Enter book ISBN :";
			cin>>is;
			
			ifstream isbook("book.dat");
	   		if(isbook.is_open()){
	    	string linen;
	    	SetConsoleTextAttribute(h, 11);
	    	while(getline(isbook,linen)){
	    		string isnum;
				istringstream iss(linen);
				getline(iss, isnum, '\t');
			
				if(isnum==is){
	    			SetConsoleTextAttribute(h, 2);
	    			cout << "\n\t\t\tISBN\tBOOK NAME\tAUTHOR\tPUBLISHER\tPRICE\tSTATUS\n";
	    			cout<<"\n\t\t\t"<<linen<<endl;
	    			isbook.close();
	    			
	    		}else{
	    			SetConsoleTextAttribute(h, 0x4F);
					cout<<"\n\n\t\t\t\tBook is not in Recode or It's unavailable now !! ";
					Sleep(2500);
					system("cls");
					librarian();	
				}
			}
			}else{
				cout<<"\n\t\t\tNot Open !";
			}
			SetConsoleTextAttribute(h, 15);
		    cout<<" \n\t\t\t\tEnter Day of issue : ";
		    cin>>day;
		    cout<<" \n\t\t\t\tEnter Month of issue : ";
		    cin>>month;
		    cout<<" \n\t\t\t\tEnter year of issue : ";
		    cin>>year;
		    cout<<"\n\t\t\t\tReturn Date : ";
		    date=day*14;
		    
		    if(date>=30){
		    	
		    	month= month+1;
			}else if(month>12){
				year=year+1;
			}
		    cout<<date<<'/'<<month<<'/'<<year;
		    
			fstream issue;
			issue.open("issuebook.dat", ios::app); //the output file stream
			if(issue.is_open()){
				issue<<boid<<'\t'<<is<<'\t'<<isdate<<'\t'<<day<<'\t'<<month<<'\t'<<year<<'\t'<<date<<endl;	
				SetConsoleTextAttribute(h, 0x2F);
				cout<<"\n\n\t\t\t\t\t Issued a book ";
				SetConsoleTextAttribute(h, 15);
				issue.close();
					
			}else{
				cout<<"\n\n\t\t\t\t\t File not opend!!";
			}
			
		/*	ifstream issbook("issuebook.dat");
		    if(issbook.is_open()){
		    	string line;
		    	SetConsoleTextAttribute(h, 11);
		    	while(getline(issbook,line)){
		    		string s;
					istringstream iss(line);
					getline(iss, s, '\t');
					if(s==boid){
						SetConsoleTextAttribute(h, 15);
						cout<<"\n\n\n\t\t\t\t"<<line<<endl;
					}
		    		
			}
			}else{
				cout<<"\n\t\t\tNot opend";
			}
			issbook.close();*/
			cout<<"\n\t\t\t\tDo you want issue another book (y/n)  : ";
			cin>>i;
			}while(i=="y");
			}
		}
		ratee.close();
		
	
	Sleep(2000);
	librarian();	
}

void allissue(){
	system("cls");
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	
	    SetConsoleTextAttribute(h, 9);
		cout<<"\n\n\t\t\t\t\t\t      ALL ISSUE DETAILS ";
		cout<<"\n\t\t\t\t\t-------------------------------------";
	 	SetConsoleTextAttribute(h, 15);
	 	
	    // Open the file in input mode
	    ifstream allis("issuebook.dat");
	    if(allis.is_open()){
	    	string line;
	    	SetConsoleTextAttribute(h, 11);
	    	cout << "\n\n\n\n\t\t\t\tBORROWER ID\tBOOK ID\t  ISSUE DATE\tDUE DATE\n";
	    	cout << "\n\t\t\t\t================================================================\n";
	    	while(getline(allis,line)){
	    		SetConsoleTextAttribute(h, 15);
	    		//display line
	    		cout<<'\n'<<'\t'<<'\t'<<"\t\t     "<<line<<endl;
			}
			allis.close();
		}
		else{
			cout<<"not opened !";
		}
	    cout<<"\n\n\n\t\t\t\tPress any key to continue.....";
		getche();
	    system("cls");
	    librarian();
	
}

void returnbook(){
	
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	
	
	system("cls");
	
	system("color 04");	
	string borrower,rdate ,r;
	int day,amount;
	
		
	fstream isb;
	isb.open("issuebook.dat",ios::in);
	if(isb.is_open()){
		string line1;
		while(getline(isb,line1)){
			istringstream iss(line1);
			getline(iss, line1, '\t');
			SetConsoleTextAttribute(h, 1);
			cout<<"\n\t\t\t\t\t\t   RETURN BOOK \n";
			cout<<"\n\t\t\t\t===============================================\n";
		
			SetConsoleTextAttribute(h, 15);
			cout<<"\n\t\t\t\tEnter Borrower ID : ";
			cin>>borrower;
			if(line1==borrower){
				cout<<"\n\n\t\t\t\tIssue details : \n";
				cout<<"\t\t\t\t"<<line1<<endl;
				isb.close();
		
			//cout<<"\n\t\t\t\tEnter Return Date : ";
		//	cin>>rdate;
			time_t now=time(0); //current date and time based on computer
			char* rdate=ctime(&now);//convert it to string
			cout<<"\n\t\t\t\tEnter Return Date : "<<rdate<<endl;
			
			cout<<"\n\t\t\t\tBook is return on due date or not ? (y/n) :  ";
			cin>>r;
			
			if(r=="n" || r=="N"){
				cout<<"\n\n\t\t\t\t How many late days : ";
				cin>>day;
				
				fstream lim;
				lim.open("rate.dat", ios::in);
				if(lim.is_open()){
					string line;
					while(getline(lim,line)){
						stringstream ss(line);
						int a;
						ss>>a;
						SetConsoleTextAttribute(h, 8);
						cout<<" \n\t\t\t\tCurrent Library fine rate is : "<<line<<endl;
						
						SetConsoleTextAttribute(h, 15);
					//	int a = stoi(line); //string to int
					
						cout<<"\n\t\t\t\tLate days Fine : "<<a<<"*"<<day<<" = "<<day*a;
						lim.close();
				 }
				}else{
					lim.close();
					cout<<"\n\t\t\t\t Not opened ";
				}
			}else if(r=="y" || r=="Y"){
				SetConsoleTextAttribute(h, 0x11F);
				cout<<"\n\t\t\t\t :) You returned on due date :) ";
			}else{
				cout<<"\n\t\t\tInvalid !";
				Sleep(1000);
				returnbook();
			}
		}else{
			SetConsoleTextAttribute(h, 0x4F);
			cout<<"\n\t\t\t\t :( Wrong id please check \n ";
		}
		}
	}else{
		cout<<"\n\t\t\t\t Not opend ";
		isb.close();
	}
	
	Sleep(3000);
	librarian();	
	
}


