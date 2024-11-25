/*This is a store management system which has administrator and buyer menu as its main menu. 
In administerator menu aministerator has to create an account then in its menu he can add, modify and delete the product.
In buyer menu he can see the products with their code, pric and discount. After placing order the reciept will be displayed. */
#include<iostream>
#include<fstream>
using namespace std;

class shopping{
	
private:
   int pcode;
   float price;
   float dis;
   string pname;

public: 
   void menu();
   void administrator();
   void buyer();
   void add();
   void edit();
   void rem();
   void list();
   void reciept();
 
 
};

void shopping::menu()
{
	main:
	int choice;
	string email;
	string password;
		cout<<endl<<endl;
	cout<<"\t\t|++++++++++++++++++++++++++ WELCOME TO MY STORE +++++++++++++++++++++++++++| \n"; 
	cout<<endl<<endl;
	cout<<"\n\t\t\t\t+------------------------------------+";
	cout<<"\n\t\t\t\t |             Main Menu            |"            ;
	cout<<"\n\t\t\t\t+------------------------------------+";
	cout<<"\n\t\t\t\t |    1) Administrator              |"               ;
	cout<<"\n\t\t\t\t |    2) Buyer                      |";
	cout<<"\n\t\t\t\t |    3) Exit                       |";
	cout<<"\n\t\t\t\t+------------------------------------+";
	
	cout<<endl<<endl;
	cout<<"\t\t\t          Please enter your choice -> ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
		{
			cout<<"\n\t\t\t          Please login to your account\n\n";
			cout<<"\t\t\t          Enter login id (admin@gmail.com) :";
			cin>>email;
			cout<<"\t\t\t          Enter password (admin123) : ";
			cin>>password;
			
			if(email == "admin@gmail.com" && password == "admin123"){
				administrator();
			}
			else{
			  cout<<"Authentication Failed !!!";
	     	}
			break;
     	}
     	
		case 2:
		{
		    buyer();
    	} 
    	
		case 3:
		{
			exit(0);
		}
		default: {
			cout<<"Please enter a valid choice. ";
			
		}
		   		
	}
	goto main;
	
}

void shopping :: administrator()
{
	system("cls");
	admenu:
	int choice;
	cout<<"\n\n\n\t\t\t|+------------------------------------+|";
	cout<<"\n\t\t\t|       Administrator Menu             |"            ;
	cout<<"\n\t\t\t|+------------------------------------+|";
	cout<<"\n\t\t\t|    1) Add the product                |"               ;
	cout<<"\n\t\t\t|    2) Modify the product             |";
	cout<<"\n\t\t\t|    3) Delete the product             |";
	cout<<"\n\t\t\t|    4) Back to main menu.             |";
	cout<<"\n\t\t\t|+------------------------------------+|";
	
	cout<<"\n\n\t\t\tPlease enter your choice :  ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
		{
			add();
			break;
		}
			
		case 2:
		{
			edit();
			break;
		}	
		 
		case 3:
		{
			rem();
			break;
		} 
		
		case 4:
		{
			menu();
			break;
		}
		
		default:
			cout<<"Invalid Choice !!";
	}
	goto admenu;
}

void shopping :: buyer()
{
		system("cls");
	buymenu:
	int choice;
	cout<<"\n\n\n\t\t\t|+------------------------------------+|";
	cout<<"\n\t\t\t|       Buyer Menu                     |";
	cout<<"\n\t\t\t|+------------------------------------+|";
	cout<<"\n\t\t\t|    1) Buy product                    |";
	cout<<"\n\t\t\t|    2) Back to main menu.             |";
	cout<<"\n\t\t\t|+------------------------------------+|";
	
	cout<<"\n\n\n\t\t\tPlease enter your choice : ";
	cin>>choice;
	
	switch(choice)
	{
	    case 1:
		   reciept();
		   break;
		  
		case 2:
		    menu();
			break;
			
		default:
		    cout<<"Invalid Choice !!";	   	
	}
	
	goto buymenu;
}

void shopping :: add()
{
	
	admenu:
	fstream data; //data is the object of the fstream class
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\t<-------Add new product------->";
	cout<<"\n\n\t\t\tEntet product code : ";
	cin>>pcode;
	cout<<"\n\n\t\t\tEntet product name : ";
	cin>>pname;
	cout<<"\n\n\t\t\tEntet product price : ";
	cin>>price;
	cout<<"\n\n\t\t\tEntet product discount : ";
	cin>>dis;
	
	data.open("database.txt" , ios::in);
	//dat is the name of the object. it will help open database file(nameof the file).
	//ios::in open file in reading mode
	//ios::out wil open file in writing mode
	
	if(!data) //if this file doesn't exist.
	{
		data.open("database.txt", ios::app |ios::out); //app=apend file and out=write in file
		//here we are opening file in wrirting if this file doesn't exist.
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else  	//if file exist
	{
		//initialising file becz we have to use while loop to iterate through the file
		data>>c>>n>>p>>d; //we are initializing the index of the file
		
		 while(!data.eof()) //the condition will check every content of the file one by one till the end of file(eof()) is reached
		 {
			if(c == pcode) //if their is a duplicacy
			{
			  token++;
			}
			data>>c>>n>>p>>d;
		 }
		data.close();
	
    	if(token == 1) //if their is duplicacy
	    { 
	        goto admenu;
	    }
	    else
		{
	    	data.open("database.txt", ios::app |ios::out);
	    	data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		    data.close();
	    }
   }
	cout<<"\n\n\t\tRecord Inserted.";
}

void shopping :: edit()
{
	fstream data , data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\t<-------Modify The Product------->";
	cout<<"\n\t\t\t+---------------------------------+";
	cout<<"\n\t\t\t    Enter Product Code -> ";
	cin>>pkey;
	cout<<"\n\t\t\t+---------------------------------+";
	cout<<endl<<endl;
	
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"\n File doesn't exist.";
	}
	else
	{
	    data1.open("database1.txt", ios::app|ios::out);  //edited data will be stored in this file
		data>>pcode>>pname>>price>>dis;
		
		while(!data.eof()){
			if(pkey ==pcode) //pkey is the code that is entered by the administrator which he wants to edit
			{
				cout<<"\n\t\t\t Product new code : ";
				cin>>c;
				cout<<"\n\t\t\t Name : ";
				cin>>n;
				cout<<"\n\t\t\t Price : ";
				cin>>p;
				cout<<"\n\t\t\t Discount : ";
				cin>>d; 
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";  //updated details will be entered with the help of data1 obj
				cout<"\n\n\t\t Record Edited.";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}	
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt", "database.txt"); //to rename the file
		
		if(token == 0)
		{
			cout<<"\n\n Record not found...";
	    } 
	}
}

void shopping :: rem()
{
	fstream data, data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t\t\t<-------Delete The Product------->";
	cout<<"\n\t\t\t+---------------------------------+";
	cout<<"\n\t\t\t    Enter Product Code -> ";
	cin>>pkey;
	cout<<"\n\t\t\t+---------------------------------+";
	cout<<endl<<endl;
	
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"\n File doesn't exist.";
	}
	else
	{
	    data1.open("database1.txt", ios::app|ios::out);  //edited data will be stored in this file
		data>>pcode>>pname>>price>>dis;
		
		while(!data.eof()){
			if(pkey ==pcode) //pkey is the code that is entered by the administrator which he wants to edit
			{
				
				cout<"\n\n\t\t Product deleted succesfully...!";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}	
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt", "database.txt"); //to rename the file
		
		if(token == 0)
		{
			cout<<"\n\n Record not found...";
	    } 
	}
}

void shopping :: list()
{
	fstream data;
	data.open("database.txt", ios::in);
	cout<<"\n\n\t\t++-------------------------------------------------++\n";
	cout<<"\t\t        ProNo.          Name            Price\n";
	cout<<"\t\t++-----------------------------------------------------++\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<"\t\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}
void shopping::reciept() {
    fstream data;
    int arrc[100];
    int arrq[100];
    string choice;
    int c = 0;
    float total = 0; // Initialize total to zero
    float dis;
    
    cout << "\n\n\t\t\t<---------- RECEIPT ---------->";
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n\t\tEmpty Database!";
    } else {
        data.close();
        list();
        cout << "\n\t\t\t---------------------------------";
        cout << "\n\t\t\t     Please Place your Order  ";
        cout << "\n\t\t\t---------------------------------";
        do {
            m:
            cout << "\n\t\t\t Enter Product code : ";
            cin >> arrc[c];
            cout << "\n\t\t\t Enter Product quantity : ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n\t\t\tDuplicate product code. Please try again! ";
                    goto m;
                }
            }
            c++;
            cout << "\n\n\t\t\t\t Do you want to buy another product? If y or n  -> ";
            cin >> choice;
        } while (choice == "y");
        system("cls");
        cout << "\n\n\n\t+++--------------------------------- RECEIPT ---------------------------------------+++";
        cout << "\n\t\tProd.No.\tName    \tQuantity\tPrice\tAmount\tAmount with Discount \n ";
        cout << "\t+++---------------------------------------------------------------------------------+++";
        data.open("database.txt", ios::in); // Open file once before the loop
        for (int i = 0; i < c; i++) {
            data >> pcode >> pname >> price >> dis;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    float amount = price * arrq[i];
                    float discountedAmount = amount - (amount * dis / 100);
                    total += discountedAmount; // Update total
                    cout << "\n\t\t" << pcode << "\t\t    " << pname << "   \t" << arrq[i] << "           \t" << price << " \t" << amount << "    \t" << discountedAmount;
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.clear(); // Clear any error flags
            data.seekg(0, ios::beg); // Reset file pointer to beginning for the next iteration
        }
        data.close(); // Close file after the loop

        cout << "\n\n\t\t---------------------------------------------------------------------";
        cout << "\n\t\t                 Total Amount : " << total;
        cout << "\n\t\t-----------------------------------------------------------------------";
        
    }
}


int main(){
	shopping s;
	s.menu();
}




























