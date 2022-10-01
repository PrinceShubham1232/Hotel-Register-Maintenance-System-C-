#include<iostream>
#include<fstream>
using namespace std;
class hotel
{
	char name[50],add[50];
	long int ph,addhr;
	int room_no;
	public:
	
		int main_menu();
		int add_room();
		int display_room();
		int edit_room();
		int delete_room(int);
		int modify_room(int);
}; hotel h;
ofstream fout;
ofstream ft;
ifstream fin;
fstream f;
int hotel::main_menu()
{
	int pass,p,ch;
	pass=1234;
	cout<<"\n\t\t\t\tHOTEL REGISTER MAINTENANCE SYSTEM";
   	cout<<"\nEnter the administrator password: ";
   	cin>>p;
    if(p==pass)
    {
   	while(1)
	{
	cout<<"\n";
	cout<<"\n|=====MAIN MENU======|";
	cout<<"\n|    1.Add room      |";
	cout<<"\n|    2.Display room  |";
	cout<<"\n|    3.Edit room     |";
	cout<<"\n|    4.Exit          |";
	cout<<"\n|====================|";
	cout<<"\n-->Enter your choice here: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
				add_room();
				break;
			}
		case 2:
			{
				display_room();
				break;
			}
		case 3:
		{
			edit_room();
            break;			
		}
		case 4:
		exit(0);
		default:
		cout<<"\nWrong choice please enter right choice";	
	}
}
}
else
{
	cout<<"\nWrong password";
}
}

int hotel::add_room()
{
	int a,r1;
	system("cls");
	cout<<"\nEnter room no: ";
	cin>>r1;
	fout.open("main_file.txt",ios::out|ios::app);
	fin.open("main_file.txt",ios::in);

    while(fin.read((char*)&h,sizeof(hotel)))
	{

	    if(h.room_no==r1)
	   {
		a=1;
		cout<<"\nRoom already booked";
		break;
	    }
	    else
	    {
	    	a=0;
	    }
    }
     if(a==0)
    {
        h.room_no=r1;
      	cout<<"\n-----------Enter the details------------";
		cout<<"\nEnter name       :";
		cin.ignore();
		cin.getline(name,50);
		cout<<"\nEnter address:   :";
		cin.getline(add,50);
		cout<<"\nEnter addhar no: :";
		cin>>addhr;
		cout<<"\nEnter phone no:  :";
		cin>>ph;
		fout.write((char*)&h,sizeof(hotel));
		cout<<"\nRoom booked";
		}
	fout.close();
	fin.close();
		
	}
int hotel::display_room()
{

	fin.open("main_file.txt",ios::in);
	int r2,a=0;
	system("cls");
	cout<<"\nEnter the room no :";

	cin>>r2;

while(fin.read((char*)&h,sizeof(hotel)))
	{
	
		if(h.room_no==r2)
		{
			cout<<"\nName:      | "<<name;
			cout<<"\n"<<"           | ";         
			cout<<"\nAddress:   | "<<add;
			cout<<"\n"<<"           | ";
			cout<<"\nAddhar no: | "<<addhr;
			cout<<"\n"<<"           | ";
			cout<<"\nPhone no:  | "<<ph;
			a=1;
			break;
		}
	}
	if(a==0)
	cout<<"\nRoom not booked";
	fin.close();
}
int hotel::edit_room()
{
	int ch,r3;
	system("cls");
	cout<<"\n1.Delete room permanently";
	cout<<"\n2.Modify room details";
	cout<<"\n3.Exit";
	cout<<"\nEnter your choice";
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
			cout<<"\nEnter the room no: ";
			cin>>r3;
			delete_room(r3);
			break;
		}
			case 2:
				{
				cout<<"\nEnter the room no: ";
				cin>>r3;
				modify_room(r3);
				break;
			}
			case 3:
				exit(0);
				default:
					cout<<"\nWrong choice";
	}
}
int hotel::delete_room(int r3)
{
int a=0;
fin.open("main_file.txt",ios::in);
ft.open("temp_file.txt",ios::out);
fin.seekg(0,ios::beg);

while(fin.read((char*)&h,sizeof(hotel)))
{

	if(h.room_no==r3)
	{
		a=1;
		
	}
    else
	{
     ft.write((char*)&h,sizeof(hotel));	
	 
	}
}
ft.close();
fin.close();
if(a==0)
{
	cout<<"\nRoom not booked";
	remove("main_file.txt");
	cin.ignore();
    rename("temp_file.txt","main_file.txt");
  
}
else
{
	cout<<"\nRoom deleted";
	remove("main_file.txt");
	cin.ignore();
    rename("temp_file.txt","main_file.txt");
   
}
}
int hotel::modify_room(int r3)
{
long int b;
int a=0;
system("cls");
f.open("main_file.txt",ios::out|ios::in|ios::binary);
while(!f.eof())
{
	b=f.tellg();
	f.read((char*)&h,sizeof(hotel));
		if(h.room_no==r3)
		{
			cout<<"\nEnter new details";
			cout<<"\nEnter name: ";
			cin.ignore();
			gets(name);
			cout<<"\nEnter address: ";
			gets(add);
			cout<<"\nEnter addhar no: ";
			cin>>addhr;
			cout<<"\nEnter phone no: ";
			cin>>ph;
			f.seekg(b);
			f.write((char*)&h,sizeof(hotel));
			cout<<"\nDetails modified";
			a=1;
			break;
		}
	}
	if(a==0)
	cout<<"\nRoom not booked";
	f.close();
			}
int main()
{
	h.main_menu();
	return 0;
}

