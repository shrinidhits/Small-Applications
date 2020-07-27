#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<string.h>
#include<stdio.h>
#include<conio.h>

using namespace std;

class library
{
private:
    int bookId;
    char bookName[50];
    int numOfCopies;
public:
    void addBook()
    {
        cout<<"\n\n\n\n\n\t\t============================================";
        cout<<"\n\t\t\tENTER BOOK ID:    ";
        cin>>bookId;
        cout<<"\n\t\t\tENTER BOOK NAME:    ";
        cin.ignore();
	    cin.getline(bookName,50);
        cout<<"\n\t\t\tENTER NUMBER OF COPIES:    ";
        cin>>numOfCopies;
        cout<<"\n\n\n\n\n\t\t============================================";
    }
    void modify()
    {
        cout<<"\n\n\t\tModify Book ID: ";
        cin>>bookId;
	    cout<<"\n\t\tModify Book Name : ";
	    cin.ignore();
	    cin.getline(bookName,50);
	    cout<<"\n\t\tModify Number of copies : ";
	    cin>>numOfCopies;
    }
    void report()
    {
        cout<<"\t\t"<<setw(6)<<bookId<<" "<<setw(20)<<bookName<<" "<<setw(10)<<numOfCopies<<endl;
    }
    int getId()
    {
        return bookId;
    }
    void getName(char a[])
    {
        strcpy(a,bookName);
    }
    int getNum()
    {
        return numOfCopies;
    }
    void borrow()
    {
        numOfCopies--;
    }
    void returned()
    {
        numOfCopies++;
    }
    void show()
    {
        cout<<"\n\n\t\tBOOK ID: "<<bookId<<endl;
        cout<<"\n\t\tBOOK NAME: "<<bookName<<endl;
        cout<<"\n\t\tNUMBER OF COPIES: "<<numOfCopies<<endl;
    }
};


class libHolder
{
private:
     int holdId;
     char holdName[50];
     char bookTaken[50];
public:
    void create()
    {
        cout<<"\n\n\n\n\n\t\t============================================";
        cout<<"\n\t\t\tENTER ACCOUNT ID:    ";
        cin>>holdId;
        cout<<"\n\t\t\tENTER ACCOUNT HOLDER NAME: ";
        cin.ignore();
	    cin.getline(holdName,50);
        cout<<"\n\n\t\t============================================";
        strcpy(bookTaken,"NTA");
    }
    void take(char a[])
    {
        strcpy(bookTaken,a);
    }
    void ret()
    {
        strcpy(bookTaken,"NTA");
    }
    int getId()
    {
        return holdId;
    }
    void getName()
    {
        cout<<holdName<<endl;
    }
    void report()
    {
        if(strcmp(bookTaken,"NTA")==0)
            cout<<"\t\t"<<setw(10)<<holdId<<"    "<<setw(10)<<holdName<<"      "<<setw(10)<<"Not taken any book"<<setw(10)<<endl;
        else
            {cout<<"\t\t"<<setw(10)<<holdId<<"    "<<setw(10)<<holdName<<"      "<<setw(10)<<bookTaken<<endl;}
    }
    void show()
    {
        if(strcmp(bookTaken,"NTA")==0)
        {
            cout<<"\n\n\t\tHOLDER ID: "<<holdId<<endl;
            cout<<"\n\n\t\tHOLDER NAME: "<<holdName<<endl;
            cout<<"\n\n\t\tNAME OF BOOK BORROWED: "<<"NOT TAKEN ANY BOOK"<<endl;
        }
        else
        {
            cout<<"\n\n\t\tHOLDER ID: "<<holdId<<endl;
            cout<<"\n\n\t\tHOLDER NAME: "<<holdName<<endl;
            cout<<"\n\n\t\tNAME OF BOOK BORROWED: "<<bookTaken<<endl;
        }

    }
    void modify()
    {
        cout<<"\n\n\t\tModify Account ID: ";
        cin>>holdId;
	    cout<<"\n\t\tModify Account Holder's Name : ";
	    cin.ignore();
	    cin.getline(holdName,50);
    }
};

void writeBook()
{
    library li;
	ofstream outFile;
	outFile.open("library.dat",ios::binary|ios::app);
	li.addBook();
	outFile.write(reinterpret_cast<char *> (&li), sizeof(library));
	outFile.close();
}

void writeholder()
{
    libHolder ho;
    ofstream outFile;
	outFile.open("libHolder.dat",ios::binary|ios::app);
	ho.create();
	outFile.write(reinterpret_cast<char *> (&ho), sizeof(libHolder));
	outFile.close();
}
void modify_book(int n)
{
    bool found=false;
	library li;
	fstream File;
	File.open("library.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&li), sizeof(library));
		if(li.getId()==n)
		{
			li.show();
			cout<<"\n\n\t\tEnter The New Details of book"<<endl;
			li.modify();
			int pos=(-1)*static_cast<int>(sizeof(library));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&li), sizeof(library));
			cout<<"\n\n\t\tRecord Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}

void modifyholder(int n)
{
    bool found=false;
	libHolder ho;
	fstream File;
	File.open("libHolder.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ho), sizeof(libHolder));
		if(ho.getId()==n)
		{
			ho.show();
			cout<<"\n\n\t\tEnter The New Details of account"<<endl;
			ho.modify();
			int pos=(-1)*static_cast<int>(sizeof(libHolder));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ho), sizeof(libHolder));
			cout<<"\n\n\t\tRecord Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}
void displayBook(int n)
{
    library li;
	bool flag=false;
	ifstream inFile;
	inFile.open("library.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be opened !! Press any Key...";
		return;
	}
	cout<<"\n\t\tBOOK DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&li), sizeof(library)))
	{
		if(li.getId()==n)
		{
			li.show();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\n\t\tBOOK IS UNAVAILABLE";
}

void displayHolder(int n)
{
    libHolder ho;
	bool flag=false;
	ifstream inFile;
	inFile.open("libHolder.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be opened !! Press any Key...";
		return;
	}


    while(inFile.read(reinterpret_cast<char *> (&ho), sizeof(libHolder)))
	{
		if(ho.getId()==n)
		{
		    cout<<"\n\t\tHOLDER DETAILS\n";
			ho.show();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\n\t\tACCOUNT DOES NOT EXIST";
}

void deletebook(int n)
{
	library li;
	ifstream inFile;
	ofstream outFile;
	inFile.open("library.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&li), sizeof(library)))
	{
		if(li.getId()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&li), sizeof(library));
		}
	}
	inFile.close();
	outFile.close();
	remove("library.dat");
	rename("Temp.dat","library.dat");
	cout<<"\n\n\t\tRecord Deleted ..";
}

void deleteholder(int n)
{
	libHolder ho;
	ifstream inFile;
	ofstream outFile;
	inFile.open("libHolder.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ho), sizeof(libHolder)))
	{
		if(ho.getId()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ho), sizeof(libHolder));
		}
	}
	inFile.close();
	outFile.close();
	remove("libHolder.dat");
	rename("Temp.dat","libHolder.dat");
	cout<<"\n\n\t\tRecord Deleted ..";
}

void displayallbook()
{
	library li;
	ifstream inFile;
	inFile.open("library.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tBOOKS LIST\n\n";
	cout<<"\t\t====================================================\n";
	cout<<"\t\tBOOK ID      BOOK NAME        NUMBER OF COPIES\n";
	cout<<"\t\t====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&li), sizeof(library)))
	{
		li.report();
		cout<<"\n\n";
	}
	inFile.close();
}

void displayallholder()
{
	libHolder ho;
	ifstream inFile;
	inFile.open("libHolder.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tHOLDERS LIST\n\n";
	cout<<"\t\t====================================================\n";
	cout<<"\t\tHOLDER ID      HOLDER NAME        BOOK BORROWED\n";
	cout<<"\t\t====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ho), sizeof(libHolder)))
	{
		ho.report();
		cout<<"\n\n";
	}
	inFile.close();
}

void borrow_ret(int hi,char a[],int option)
{
	bool found=false;
	bool fin=false;
	libHolder ho;
	library li;
	fstream File;
	fstream f2;
	File.open("libHolder.dat", ios::binary|ios::in|ios::out);
	f2.open("library.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	if(!f2)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    while(!f2.eof() && found==false)
	{
		f2.read(reinterpret_cast<char *> (&li), sizeof(library));
		char b[50];
		li.getName(b);
		if(strcmp(b,a) == 0)
		{

			if(option == 1)
			{
				if(li.getNum()>0)
                {
                    fin = true;
                }
				li.borrow();
			}
			if(option == 2)
			{
				li.returned();
			}

			int pos = (-1)*static_cast<int>(sizeof(library));
			f2.seekp(pos,ios::cur);
			f2.write(reinterpret_cast<char *> (&li), sizeof(library));
			found = true;
        }
    }
    found = false;
    while(!File.eof() && found==false)
    {
        File.read(reinterpret_cast<char *> (&ho), sizeof(libHolder));
        if(ho.getId()==hi)
        {

            if(option==1)
            {
                if(fin == true)
                {
                    cout<<"\n\n\t\tBORROWED BOOK ";
                    ho.take(a);
                }
                else
                {
                    cout<<"\n\n\t\tBOOK OUT OF STOCK ";
                }
            }
            if(option == 2)
            {
                cout<<"\n\n\t\tRETURNED BOOK ";
                ho.ret();
            }
            ho.show();
            int pos = (-1)*static_cast<int>(sizeof(libHolder));
            File.seekp(pos,ios::cur);
            File.write(reinterpret_cast<char *> (&ho), sizeof(libHolder));
            cout<<"\n\n\t\tRecord Updated";
            found = true;
        }
    }
	File.close();
	f2.close();
	if(found == false)
		cout<<"\n\n\t\tACCOUNT DOES NOT EXIST";
}

void intro()
{
    cout<<"\n\n\t\t==================================================\n\t\t==================================================";
	cout<<"\n\t\t%%\t\t\t\t\t\t%%\n\t\t%%\t\t\t\t\t\t%%\n\t\t%%\t\t  LIBRARY\t\t\t%%";
	cout<<"\n\t\t%%\t\t\t\t\t\t%%\n\t\t%%\t\tMANAGEMENT\t\t\t%%";
	cout<<"\n\t\t%%\t\t\t\t\t\t%%\n\t\t%%\t\t  SYSTEM\t\t\t%%";
	cout<<"\n\t\t%%\t\t\t\t\t\t%%\n\t\t%%\t\t\t\t\t\t%%\n\t\t%%\t\t\t\t\t\t%%\n\t\t%%\t\tMADE BY : SHRINIDHI\t\t%%";
	cout<<"\n\t\t%%\t\t\t\t\t\t%%\n\t\t==================================================\n\t\t==================================================";
	cin.get();
}

int main()
{
	int ch;
	int num;
	int n;
	int h;
	intro();
	system("cls");
	cout<<"\n\n\n\n\n\t\t\tDEAR ADMIN PLEASE ENTER PASSWORD";
	char password[30];
	cout<<"\n\n\n\t\t\tPASSWORD:   ";
	int p = 0;
    do
    {
        password[p] = getch();
        if(password[p]!= '\r'){
            printf("*");
        }
        p++;
    }while(password[p-1]!= '\r');
    password[p-1] = '\0';
    int i = 0;
    string pass = "";
    while(password[i])
    {
        pass += password[i];
        i++;
    }
    cout<<pass;
	bool f = false;
    string line;
    ifstream myfile ("systemfile.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
          if(line==pass) f=true;
        }
        myfile.close();
    }
	if(f)
	{
	    do
	    {
		    system("cls");
		    cout<<"\n\n\n\n\n\n\t\tMAIN MENU";
		    cout<<"\n\n\t\t01. ADD/DELETE/MODIFY ACCOUNT";
		    cout<<"\n\n\t\t02. ADD/DELETE/MODIFY BOOK";
		    cout<<"\n\n\t\t03. BORROW/RETURN BOOK";
		    cout<<"\n\n\t\t04. SHOW BOOK DETAILS";
		    cout<<"\n\n\t\t05. SHOW ACCOUNT DETAILS";
		    cout<<"\n\n\t\t06. EXIT";
		    cout<<"\n\n\t\tSelect Your Option (1-6) ";
		    cin>>ch;
		    system("cls");
		    switch(ch)
		    {
		    case 1:
		        cout<<"\n\n\n\t\t\t01. ADD\n\n\n\t\t\t02.DELETE\n\n\n\t\t\t03.MODIFY\n\n\n\t\t\t04.BACK\n\n\n\t\t\t";
                cin>>h;
		        system("cls");
		        if(h==1)
                {
                    writeholder();
                }
			    else if(h==2)
			    {
                    cout<<"\n\n\t\tENTER ACCOUNT HOLDER'S ID:";
                    cin>>n;
			        deleteholder(n);
                }
			    else if(h==3)
			    {
                    cout<<"\n\n\t\tENTER ACCOUNT HOLDER'S ID:";
                    cin>>n;
			        modifyholder(n);
			    }
			    else
                {
                    cout<<"\n\n\n\n\n\n\t\t\tPRESS ENTER TO GO BACK TO MAIN MENU";
                    break;
                }
			    break;
		    case 2:
			    cout<<"\n\n\n\t\t\t01.ADD\n\n\n\t\t\t02.DELETE\n\n\n\t\t\t03.MODIFY\n\n\n\t\t\t04.BACK\n\n\n\t\t\t";
		        cin>>h;
		        system("cls");
		        if(h==1)
                {
                    writeBook();
                }
			    else if(h==2)
			    {
                    cout<<"\n\n\t\tENTER BOOK ID:";
                    cin>>n;
			        deletebook(n);
                }
			    else if(h==3)
			    {
                    cout<<"\n\n\t\tENTER BOOK ID:";
                    cin>>n;
			        modify_book(n);
			    }
			    else
                {
                    cout<<"\n\n\n\n\n\n\t\t\tPRESS ENTER TO GO BACK TO MAIN MENU";
                    break;
                }
			    break;
		    case 3:
		        cout<<"\n\n\t\t01.BORROW\n\n\n\t\t02.RETURN\n\n\n\t\t03.BACK\n\n\n\t\t\t";
		        cin>>h;
		        system("cls");
		        if(h==1)
			    {
			        cout<<"\n\n\t\tENTER ACCOUNT ID: "; cin>>num;
			        cout<<"\n\n\t\tENTER BOOK NAME: "; char y[50];
			        cin.ignore();
			        cin.getline(y,50);
			        borrow_ret(num,y, 1);
                }
			    else if(h==2)
                {
                    cout<<"\n\n\t\tENTER ACCOUNT ID: "; cin>>num;
			        cout<<"\n\n\t\tENTER BOOK NAME: "; char x[50];
			        cin.ignore();
			        cin.getline(x,50);
			        borrow_ret(num,x, 2);
                }
                else
                {
                    cout<<"\n\n\n\n\n\n\t\t\tPRESS ENTERTO GO BACK TO MAIN MENU";
                    break;
                }
                break;
		    case 4:
		        cout<<"\n\n\n\t\t01.BY ID\n\n\n\t\t02.ALL\n\n\n\t\t03.BACK\n\n\n\t\t\t";
		        cin>>h;
		        system("cls");
		        if(h==1)
		        {
		            cout<<"\n\n\t\tENTER BOOK ID : ";
                    cin>>n;
			        displayBook(n);
                }
                else if(h==2)
                {
                    displayallbook();
                }
                else
                {
                    cout<<"\n\n\n\n\n\n\t\t\tPRESS ENTER TO GO BACK TO MAIN MENU";
                    break;
                }
			    break;
		    case 5:
			    cout<<"\n\n\t\t01.BY ID\n\n\n\t\t02.ALL\n\n\n\t\t03.BACK\n\n\n\t\t";
		        cin>>h;
		        system("cls");
		        if(h==1)
		        {
		            cout<<"\n\n\t\tENTER ACCOUNT ID : ";
		            cin>>n;
			        displayHolder(n);
                }
                else if(h==2)
                {
                    displayallholder();
                }
			    else
                {
                    cout<<"\n\n\n\n\n\n\t\t\tPRESS ENTER TO GO BACK TO MAIN MENU";
                    break;
                }
                break;
		     default :cout<<"\a";
		    }
		    cin.ignore();
		    cin.get();
	    }
	    while(ch!=6);
    }
	else
    {
        cout<<"\n\n\n\n\n\n\t\t\tPASSWORD ENTERED IS WRONG........ EXITING APPLICATION\n\n\n\n\n";
	}
	return 0;
}

