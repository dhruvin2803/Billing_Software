#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<process.h>
#include<fstream.h>
void BillLayout();
void McName();
void time();
void showbill();
void readbill1(int);
void DeleteOrder(int,int);
void deletebill(int);
void loading();
void writebill(int,int);
void readbill(int);
void password();
void deletewindow();
void name1();
void boxlayout();
void mainwindow();
void addvegmenu();
void readvegmenu();
void addnonvegmenu();
void readnonvegmenu();
void addmccafemenu();
void readmccafemenu();
int  Autoveg();
int  VerifyBillNo(int);
int  VerifyNonVegINo(int);
int  VerifyMcCafeINo(int);
int  VerifyDeleteIno(int,int);
int  autobill();
int  VerifyINo(int);
int  Autononveg();
int  Automccafe();
int j=0;
class menu
{
	double price;
	char item[50];
	int ino;
	int billino;
	char billitem[50];
	int billno;
	int qty;
	int billprice;
	int tprice;
	char time[20];

   public:

	menu()
	{
		price=0;
		tprice=0;
	}
	void getvegdata()
	{
		gotoxy(30,10);
		cout<<"The Item No. Is=";
		ino=Autoveg();
		cout<<ino;
		gotoxy(30,12);
		cout<<"Enter The Item Name=";
		gets(item);
		gotoxy(30,14);
		cout<<"Enter The Price=";
		cin>>price;
	}
	void getnonvegdata()
	{
		gotoxy(30,10);
		cout<<"The Item No. Is=";
		ino=Autononveg();
		cout<<ino;
		gotoxy(30,12);
		cout<<"Enter The Item Name=";
		gets(item);
		gotoxy(30,14);
		cout<<"Enter The Price=";
		cin>>price;
	}
	void getmccafedata()
	{
		gotoxy(30,10);
		cout<<" The Item No. Is=";
		ino=Automccafe();
		cout<<ino;
		gotoxy(30,12);
		cout<<"Enter The Item Name=";
		gets(item);
		gotoxy(30,14);
		cout<<"Enter The Price=";
		cin>>price;
	}

	void putdata(int rowno)
	{
			gotoxy(3,6);
			cout<<"Item Code"<<setw(10)<<"Name"<<setw(16)<<"Price"<<setw(12)<<"| Item Code"<<setw(10)<<"Name"<<setw(16)<<"Price";
			gotoxy(8,rowno);
			cout<<ino<<") ";
			gotoxy(14,rowno);
			cout<<item;
			gotoxy(34,rowno);
			cout<<price;
			gotoxy(39,rowno);
			cout<<"|";
	}
	void putdata1(int rowno1)
	{
			gotoxy(46,rowno1);
			cout<<ino<<") ";
			gotoxy(53,rowno1);
			cout<<item;
			gotoxy(73,rowno1);
			cout<<price;
	}
	void getupdate()
	{
		returnino();
		gotoxy(30,12);
		cout<<"Enter The Item Name=";
		gets(item);
		gotoxy(30,14);
		cout<<"Enter The Price=";
		cin>>price;

	}


	int returnino()
	{
		return ino;
	}
	char *returnname()
	{
		return item;
	}
	int returnprice()
	{
		return billprice;
	}
	int returniprice()
	{
		return price;
	}

	void getbilldata(int INO,int BILNO)
	{
		billno=BILNO;
		gotoxy(5,23);
		cout<<"                                 ";
		billino=INO;
		strcpy(billitem,returnname());
		gotoxy(5,23);
		cout<<"Enter The Quantity=";
		cin>>qty;
		if(qty==0)
		{
			 exit(0);
		}
		gotoxy(60,25);
		cout<<"                    ";
		billprice=returniprice()*qty;
	}

	int returnbillno()
	{
		return billno;
	}
	void putbilldata(int rowno)
	{

			gotoxy(31,3.5);
			cout<<"Bill No.="<<billno;
			gotoxy(3,6);
			cout<<"ICode"<<setw(7)<<"Name"<<setw(12)<<"Qty"<<setw(9)<<"Price"<<setw(9)<<"TPrice";
			gotoxy(5,rowno);
			cout<<billino<<") ";
			gotoxy(10,rowno);
			cout<<billitem;
			gotoxy(25,rowno);
			cout<<qty;
			gotoxy(32,rowno);
			cout<<price;
			gotoxy(40,rowno);
			cout<<billprice;
	}
};


void updatemenuoptions()
{
TOP:
Top:
	int ch;
	gotoxy(30,8);
	cout<<"1) Veg Menu.";
	gotoxy(30,10);
	cout<<"2) Non - Veg Menu.";
	gotoxy(30,12);
	cout<<"3) Mc Cafe";
	gotoxy(30,14);
	cout<<"4) Delete Record";
	gotoxy(30,16);
	cout<<"5) Delete Bill";
	gotoxy(30,18);
	cout<<"6) Reset Programme";
	gotoxy(30,20);
	cout<<"7) Back";
	gotoxy(30,22);
	cout<<"Esc To Exit.";
	gotoxy(33,3.5);
	textcolor(RED);
	cprintf("Update Menu");
	textcolor(WHITE);
	ch=getche();
	if(ch=='1')
	{
		boxlayout();
		gotoxy(31,3.5);
		textcolor(RED);
		cprintf("UPDATE VEG MENU");
		textcolor(WHITE);

getvegagain:
		addvegmenu();
invalidveg:
		int ch;
		gotoxy(50,23);
		cout<<"Do You Want To Add(Y/N) :- ";
		ch=getche();
		if(ch=='y'||ch=='Y')
		{
			goto getvegagain;
		}
		else if(ch=='n'||ch=='N')
		{
			clrscr();
			boxlayout();
			goto Top;
			getch();

		}
		else
		{
			gotoxy(50,23);
			cout<<"                             ";
			gotoxy(50,23);
			cout<<"Invalid Choice..!!";
			getch();
			gotoxy(50,23);
			cout<<"                             ";
			goto invalidveg;
		}
	}
	else if(ch=='2')
	{
		boxlayout();
		gotoxy(31,3.5);
		textcolor(RED);
		cprintf("UPDATE NON-VEG MENU");
		textcolor(WHITE);
getnonvegagain:
		addnonvegmenu();
invalidnonveg:
		int ch1;
		gotoxy(50,23);
		cout<<"Do You Want Add(Y/N) :- ";
		ch1=getche();
		if(ch1=='y'||ch1=='Y')
		{
			goto getnonvegagain;
		}
		else if(ch1=='n'||ch1=='N')
		{
			clrscr();
			boxlayout();
			goto Top;
			getch();
		}
		else
		{
			gotoxy(50,23);
			cout<<"                             ";
			gotoxy(50,23);
			cout<<"Invalid Choice..!!";
			getch();
			gotoxy(50,23);
			cout<<"                             ";
			goto invalidnonveg;
		}

	}
	else if(ch=='3')
	{
		boxlayout();
		gotoxy(31,3.5);
		textcolor(BLUE);
		cprintf("UPDATE McCAFE MENU");
		textcolor(WHITE);
getmccafeagain:
		addmccafemenu();
invalidmccafe:
		int ch2;
		gotoxy(50,23);
		cout<<"Do You Want Add(Y/N) :- ";
		ch2=getche();
		if(ch2=='y'||ch2=='Y')
		{
			goto getmccafeagain;
		}
		else if(ch2=='n'||ch2=='N')
		{
			clrscr();
			boxlayout();
			goto Top;
			getch();
		}
		else
		{
			gotoxy(50,23);
			cout<<"                             ";
			gotoxy(50,23);
			cout<<"Invalid Choice..!!";
			getch();
			gotoxy(50,23);
			cout<<"                             ";
			goto invalidmccafe;
		}

	}
	else if(ch=='4')
	{
		deletewindow();
	}
	else if(ch=='5')
	{
		menu h;
	    back:
		char a1;
		int a;
		clrscr();
		boxlayout();
		gotoxy(10,10);
		cout<<"Enter The Bill No.=";
		cin>>a;
		if(VerifyBillNo(a)==1)
		{
			deletebill(a);
			gotoxy(10,10);
			cout<<"Record Deleted";
			gotoxy(10,10);
			cout<"                               ";
			gotoxy(10,10);
			cout<<"Do U Want To Add More(Y/N) ";
			char in=getche();
			if(in=='y'||in=='Y')
			{
				goto back;
			}
			else if(in=='n' || in=='N')
			{
				clrscr();
				boxlayout();
				updatemenuoptions();
				getch();
			}


		}
		else
		{
			gotoxy(10,10);
			cout<<"Invalid Choice..";
			getch();
			gotoxy(10,10);
			cout<<"                 ";
			goto back;
		}
		getch();
	}
	else if(ch=='7')
	{
		boxlayout();
		name1();
		mainwindow();
		getch();
	}
	else if(ch=='6')
	{
		clrscr();
		password();

	}
	else if(ch==27)
	{
		exit(0);
	}
	else
	{
		gotoxy(35,23);
		cout<<"Invalid choice";
		getch();
		gotoxy(35,23);
		cout<<"               ";
		goto TOP;
	}

}
void dispHLines()
{
	for(int i=0;i<=79;i++)
	{
		cout<<char(220);
	}
}


void dispVLines()
{
	for(int i=1;i<=24;i++)
	{
		for(int j=1;j<=80;j+=79)
		{
			gotoxy(j,i);
			cout<<char(220);
		}
	}
}
void name()
{
	gotoxy(29,3.5);
	char ch[21]={"Welcome To McDonald's"};
	for(int i=0;i<=20;i++)
	{
		cout<<ch[i];
		delay(200);
	}
	gotoxy(29,3.5);
	cout<<"                               ";
	gotoxy(29,3.5);
	textcolor(YELLOW + BLINK);
	cprintf("Welcome To McDonald's\r\n");
	delay(3000);
	gotoxy(29,3.5);
	textcolor(YELLOW);
	cprintf("Welcome To McDonald's");
	textcolor(WHITE);
}
void name1()
{
	textcolor(YELLOW);
	gotoxy(29,3.5);
	cprintf("Welcome To McDonald's");
	textcolor(WHITE);
}
void mainwindow()
{
	top:
	menu o;
	int ch1;
	char del1;
	int total;
	boxlayout();
	name1();
	char del;
	textcolor(WHITE);
	char a;
	char Veg,NonVeg,McCafe;
	int icode;
	int ch;
	int BNO;
	ifstream fin;
	gotoxy(34,8);
	cout<<"Main Menu:";
	gotoxy(30,12);
	cout<<"1)  Vegeterian.";
	gotoxy(30,14);
	cout<<"2)  Non - Vegeterian.";
	gotoxy(30,16);
	cout<<"3)  Mc Cafe.";
	gotoxy(30,18);
	cout<<"4)  Administrator.";
	gotoxy(30,20);
	cout<<"5)  View Bill.";
	gotoxy(66,23);
	cout<<"Esc To EXIT.";
	a=getche();
	switch(a)
	{

		case '1':
			gotoxy(30,12);
			textcolor(GREEN+BLINK);
			cprintf("1)  Vegeterian.");
			delay(1000);
			textcolor(WHITE);
			clrscr();
			boxlayout();
			gotoxy(34,3.5);
			textcolor(GREEN);
			cprintf(" VEG MENU");
			textcolor(WHITE);
			readvegmenu();
			BNO=autobill();

		VegAgain:
			gotoxy(15,25);
			cout<<"Your Bill No.="<<BNO;
			gotoxy(5,23);
			cout<<"                                           ";
			gotoxy(60,25);
			cout<<"0 To Back";
			gotoxy(5,23);
			cout<<"Enter your choice=";
			cin>>ch;

			if(VerifyINo(ch)==1)
			{
				gotoxy(5,23);
				cout<<"                              ";
				writebill(ch,BNO);                      			gotoxy(5,23);
				cout<<"                              ";
				gotoxy(5,23);
			}
			else if(ch==0)
			{
				clrscr();
				boxlayout();
				name1();
				mainwindow();
			}

			else
			{
				gotoxy(5,23);
				cout<<"                               ";
				gotoxy(5,23);
				cout<<"Invalid Choice";
				getch();
				gotoxy(5,23);
				cout<<"                               ";
				goto VegAgain;
			}
			gotoxy(5,23);
			cout<<"Add More(Y/N) OR";
			gotoxy(22,23);
			textcolor(BLUE);
			cprintf("K=McCafe");
			gotoxy(30,23);
			textcolor(RED);
			cprintf(" L=Non VEG MENU");
			textcolor(WHITE);
			Veg=getche();
			gotoxy(5,23);
			cout<<"                              	   ";

			if(Veg=='y'||Veg=='Y')
			{
				goto VegAgain;
			}
			else if(Veg=='n'|| Veg=='N')
			{
				clrscr();
				BillLayout();
				j=1;
				readbill(BNO);
				j++;
				OvegDelete:
				gotoxy(49,8);
				cout<<"Delete Order(Y/N)";
				del=getche();
				if(del=='y'|| del=='Y')
				{
					delIcode:
					j=1;
					clrscr();
					BillLayout();
					readbill(BNO);
					gotoxy(49,8);
					cout<<"                  ";
					gotoxy(49,8);
					cout<<"Enter ICode=";
					cin>>icode;
					if(VerifyDeleteIno(BNO,icode)==1)
					{

						DeleteOrder(BNO,icode);
						VegdelAgain:
						gotoxy(49,8);
						cout<<"                   ";
						gotoxy(49,8);
						cout<<"Delete More(Y/N)";
						del1=getche();
						if(del1=='Y' || del1=='y')
						{
							goto delIcode;
						}
						else if( del1=='N' || del1=='n')
						{
							goto vegDELETE;
						}
						else
						{
							gotoxy(49,8);
							cout<<"             ";
							gotoxy(49,8);
							cout<<"Invalid";
							getch();
							gotoxy(49,8);
							cout<<"        ";
							goto VegdelAgain;
						}
					}
					else
					{
						gotoxy(49,8);
						cout<<"             ";
						gotoxy(49,8);
						cout<<"Invalid";
						getch();
						gotoxy(49,8);
						cout<<"        ";
						goto delIcode;
					}
				}
				else if(del=='n' || del=='N')
				{
					vegDELETE:
					clrscr();
					BillLayout();
					readbill1(BNO);

				}
				else
				{
					gotoxy(49,8);
					cout<<"                   ";
					gotoxy(49,8);
					cout<<"Invalid";
					getch();
					gotoxy(49,8);
					cout<<"           ";
					goto OvegDelete;
				}
			}
			else if(Veg=='l' || Veg=='L')
			{
				clrscr();
				boxlayout();
				gotoxy(34,3.5);
				textcolor(RED);
				cprintf("NON VEG MENU");
				textcolor(WHITE);
				readnonvegmenu();
				goto NonVegAgain;
			}
			else if(Veg=='k' || Veg=='K')
			{
				clrscr();
				boxlayout();
				gotoxy(34,3.5);
				textcolor(BLUE);
				cprintf("Mc CAFE MENU");
				textcolor(WHITE);
				readmccafemenu();
				goto McCafeAgain;
			}

			else
			{
				gotoxy(58,23);
				cout<<"              ";
				gotoxy(58,23);
				cout<<"Invalid Choice";
			}
			break;
		case '2':
			gotoxy(30,14);
			textcolor(RED+BLINK);
			cprintf("2) Non - Vegeterian.");
			delay(1000);
			textcolor(WHITE);

			clrscr();
			boxlayout();
			gotoxy(34,3.5);
			textcolor(RED);
			cprintf("NON VEG MENU");
			textcolor(WHITE);
			readnonvegmenu();
			BNO=autobill();

		NonVegAgain:
			gotoxy(15,25);
			cout<<"Your Bill No.="<<BNO;
			gotoxy(5,23);
			cout<<"                                           ";
			gotoxy(60,25);
			cout<<"0 To Back";
			gotoxy(5,23);
			cout<<"Enter your choice=";
			cin>>ch;

			if(VerifyNonVegINo(ch)==1)
			{
				gotoxy(5,23);
				cout<<"                              ";
				writebill(ch,BNO);
				gotoxy(5,23);
				cout<<"                              ";
				gotoxy(5,23);
			}
			else if(ch==0)
			{
				clrscr();
				boxlayout();
				name1();
				mainwindow();
			}

			else
			{
				gotoxy(5,23);
				cout<<"                               ";
				gotoxy(5,23);
				cout<<"Invalid Choice";
				getch();
				gotoxy(5,23);
				cout<<"                               ";
				goto NonVegAgain;
			}
			gotoxy(5,23);
			cout<<"Add More(Y/N) OR";
			gotoxy(22,23);
			textcolor(BLUE);
			cprintf("K=McCafe");
			gotoxy(30,23);
			textcolor(GREEN);
			cprintf(" L=VEG MENU");
			textcolor(WHITE);
			NonVeg=getche();
			gotoxy(5,23);
			cout<<"                              	   ";

			if(NonVeg=='y'|| NonVeg=='Y')
			{
				goto NonVegAgain;
			}
			else if(NonVeg=='n'|| NonVeg=='N')
			{
				clrscr();
				BillLayout();
				j=1;
				readbill(BNO);
				j++;
				OnonvegDelete:
				gotoxy(49,8);
				cout<<"Delete Order(Y/N)";
				del=getche();
				if(del=='y'|| del=='Y')
				{
					delNonIcode:
					j=1;
					clrscr();
					BillLayout();
					readbill(BNO);

					gotoxy(49,8);
					cout<<"                  ";
					gotoxy(49,8);
					cout<<"Enter ICode=";
					cin>>icode;
					if(VerifyDeleteIno(BNO,icode)==1)
					{
						DeleteOrder(BNO,icode);
						NonVegdelAgain:
						gotoxy(49,8);
						cout<<"                   ";
						gotoxy(49,8);
						cout<<"Delete More(Y/N)";
						del1=getche();
						if(del1=='Y' || del1=='y')
						{
							goto delNonIcode;
						}
						else if( del1=='N' || del1=='n')
						{
							goto nonvegDELETE;
						}
						else
						{
							gotoxy(49,8);
							cout<<"             ";
							gotoxy(49,8);
							cout<<"Invalid";
							getch();
							gotoxy(49,8);
							cout<<"        ";
							goto NonVegdelAgain;
						}

					}
					else
					{
						gotoxy(49,8);
						cout<<"             ";
						gotoxy(49,8);
						cout<<"Invalid";
						getch();
						gotoxy(49,8);
						cout<<"        ";
						goto delNonIcode;
					}
				}
				else if(del=='n' || del=='N')
				{
					nonvegDELETE:
					clrscr();
					BillLayout();
					readbill1(BNO);

				}
				else
				{
					gotoxy(49,8);
					cout<<"                  ";
					gotoxy(49,8);
					cout<<"Invalid";
					getch();
					gotoxy(49,8);
					cout<<"           ";
					goto OnonvegDelete;
				}
			}
			else if(NonVeg=='l' || NonVeg=='L')
			{
				clrscr();
				boxlayout();
				gotoxy(34,3.5);
				textcolor(GREEN);
				cprintf(" VEG MENU");
				textcolor(WHITE);
				readvegmenu();
				goto VegAgain;
			}
			else if(NonVeg=='k' || NonVeg=='K')
			{
				clrscr();
				boxlayout();
				gotoxy(34,3.5);
				textcolor(BLUE);
				cprintf("Mc CAFE MENU");
				textcolor(WHITE);
				readmccafemenu();
				goto McCafeAgain;
			}

			else
			{
				gotoxy(58,23);
				cout<<"              ";
				gotoxy(58,23);
				cout<<"Invalid Choice";
			}

			break;
		case '3':
			gotoxy(30,16);
			textcolor(BLUE+BLINK);
			cprintf("3)  Mc Cafe.");
			delay(1000);
			textcolor(WHITE);
			clrscr();
			boxlayout();
			gotoxy(34,3.5);
			textcolor(BLUE);
			cprintf("Mc CAFE MENU");
			textcolor(WHITE);
			readmccafemenu();
			BNO=autobill();

		McCafeAgain:
			gotoxy(15,25);
			cout<<"Your Bill No.="<<BNO;
			gotoxy(5,23);
			cout<<"                                           ";
			gotoxy(60,25);
			cout<<"0 To Back";
			gotoxy(5,23);
			cout<<"Enter your choice=";
			cin>>ch;

			if(VerifyMcCafeINo(ch)==1)
			{
				gotoxy(5,23);
				cout<<"                              ";
				writebill(ch,BNO);
				gotoxy(5,23);
				cout<<"                              ";
				gotoxy(5,23);
			}
			else if(ch==0)
			{
				clrscr();
				boxlayout();
				name1();
				mainwindow();
			}

			else
			{
				gotoxy(5,23);
				cout<<"                               ";
				gotoxy(5,23);
				cout<<"Invalid Choice";
				getch();
				gotoxy(5,23);
				cout<<"                               ";
				goto McCafeAgain;
			}
			gotoxy(5,23);
			cout<<"Add More(Y/N) OR";
			gotoxy(22,23);
			textcolor(RED);
			cprintf("K=NonVeg Menu");
			gotoxy(30,23);
			textcolor(GREEN);
			cprintf(" L=VEG MENU");
			textcolor(WHITE);
			McCafe=getche();
			gotoxy(5,23);
			cout<<"                              	   ";

			if(McCafe=='y'|| McCafe=='Y')
			{
				goto McCafeAgain;
			}
			else if(McCafe=='n'|| McCafe=='N')
			{
				clrscr();
				BillLayout();
				j=1;
				readbill(BNO);
				j++;
				OmccafeDelete:
				gotoxy(49,8);
				cout<<"Delete Order(Y/N)";
				del=getche();
				if(del=='y'|| del=='Y')
				{
					delMcIcode:
					j=1;
					clrscr();
					BillLayout();
					readbill(BNO);
					gotoxy(49,8);
					cout<<"                  ";
					gotoxy(49,8);
					cout<<"Enter ICode=";
					cin>>icode;
					if(VerifyDeleteIno(BNO,icode)==1)
					{
						DeleteOrder(BNO,icode);
						McdelAgain:
						gotoxy(49,8);
						cout<<"                   ";
						gotoxy(49,8);
						cout<<"Delete More(Y/N)";
						del1=getche();
						if(del1=='Y' || del1=='y')
						{
							goto delMcIcode;
						}
						else if( del1=='N' || del1=='n')
						{
							goto mcDELETE;
						}
						else
						{
							gotoxy(49,8);
							cout<<"             ";
							gotoxy(49,8);
							cout<<"Invalid";
							getch();
							gotoxy(49,8);
							cout<<"        ";
							goto McdelAgain;
						}
					}
					else
					{
						gotoxy(49,8);
						cout<<"             ";
						gotoxy(49,8);
						cout<<"Invalid";
						getch();
						gotoxy(49,8);
						cout<<"        ";
						goto delMcIcode;
					}
				}
				else if(del=='n' || del=='N')
				{
					mcDELETE:
					clrscr();
					BillLayout();
					readbill1(BNO);
				}
				else
				{
					gotoxy(49,8);
					cout<<"                 ";
					gotoxy(49,8);
					cout<<"Invalid";
					getch();
					gotoxy(49,8);
					cout<<"           ";
					goto OmccafeDelete;
				}
			}
			else if(McCafe=='l' || McCafe=='L')
			{
				clrscr();
				boxlayout();
				gotoxy(34,3.5);
				textcolor(GREEN);
				cprintf(" VEG MENU");
				textcolor(WHITE);
				readvegmenu();
				goto VegAgain;
			}
			else if(McCafe=='k' || McCafe=='K')
			{
				clrscr();
				boxlayout();
				gotoxy(34,3.5);
				textcolor(RED);
				cprintf("NON VEG MENU");
				textcolor(WHITE);
				readnonvegmenu();
				goto NonVegAgain;
			}

			else
			{
				gotoxy(58,23);
				cout<<"              ";
				gotoxy(58,23);
				cout<<"Invalid Choice";
			}


			break;
		case '4':
			clrscr();
			password();
		case '5':
		    InvalidBill:
			clrscr();
			boxlayout();
			gotoxy(50,23);
			cout<<"0 To Back..";
			gotoxy(10,10);
			cout<<"Enter The Bill No=";
			cin>>ch1;
			if( VerifyBillNo(ch1)==1)
			{
				clrscr();
				BillLayout();
				readbill(ch1);
				getch();
			}
			else if(ch1==0)
			{
				clrscr();
				boxlayout();
				name1();
				mainwindow();
			}
			else
			{
				gotoxy(10,10);
				cout<<"                             ";
				gotoxy(10,10);
				cout<<"Invalid Choice..";
				getch();
				gotoxy(10,10);
				cout<"                    ";
				goto InvalidBill;
			}
		case 27:
			exit(0);
		default:
			gotoxy(35,23);
			cout<<"Invalid choice";
			getch();
			gotoxy(35,23);
			cout<<"               ";
			goto top;

	}
}
void addvegmenu()
{
	clrscr();
	boxlayout();
	ofstream vegout;
	vegout.open("vegmenu.dat",ios::app|ios::binary);
	menu s;
	s.getvegdata();
	vegout.write((char*)&s,sizeof(s));
	vegout.close();
}
void readvegmenu()
{
	menu s;
	ifstream vegin;
	vegin.open("vegmenu.dat",ios::in|ios::binary);
	int rno=8;
	int rno1=8;
	while(vegin.read((char*)&s,sizeof(s)))
	{

		if(rno<23)
		{
			s.putdata(rno++);
		}

		else
		{
			 s.putdata1(rno1++);
		}

	}
	vegin.close();
}
void addnonvegmenu()
{
	clrscr();
	boxlayout();
	ofstream nonvegout;
	nonvegout.open("nonvegmenu.dat",ios::app|ios::binary);
	menu s;
	s.getnonvegdata();
	nonvegout.write((char*)&s,sizeof(s));
	nonvegout.close();
}

void readnonvegmenu()
{
	menu s;
	ifstream nonvegin;
	nonvegin.open("nonvegmenu.dat",ios::in|ios::binary);
	int rno=8;
	int rno1=8;
	while(nonvegin.read((char*)&s,sizeof(s)))
	{
		if(rno<23)
		{
			s.putdata(rno++);
		}

		else
		{
			s.putdata1(rno1++);
		}
	}
	nonvegin.close();
}
void addmccafemenu()
{
	clrscr();
	boxlayout();
	ofstream mcout;
	mcout.open("mccafemenu.dat",ios::app|ios::binary);
	menu s;
	s.getmccafedata();
	mcout.write((char*)&s,sizeof(s));
	mcout.close();
}
void readmccafemenu()
{
	menu s;
	ifstream mcin;
	mcin.open("mccafemenu.dat",ios::in|ios::binary);
	int rno=8;
	int rno1=8;
	while(mcin.read((char*)&s,sizeof(s)))
	{

		if(rno<23)
		{
			s.putdata(rno++);
		}

		else
		{
			 s.putdata1(rno1++);
		}

	}
	mcin.close();
}
void boxlayout()
{
	clrscr();
	textcolor(WHITE);
	dispHLines();
	gotoxy(1,24);
	dispHLines();
	gotoxy(1,4);
	dispHLines();
	dispVLines();

}
int Autoveg()
{
	int max=0,c=1;
	menu o;
	ifstream fin;
	fin.open("vegmenu.dat",ios::in|ios::binary);
	while(fin.read((char*)&o,sizeof(o)))
	{
		if(c==1)
		{
			max=o.returnino();
		}
		else if(max<o.returnino())
		{
			max=o.returnino();
		}

	}
	fin.close();
	return max+1;

}
int Autononveg()
{
	int max=100,c=1;
	menu o;
	ifstream fin;
	fin.open("nonvegmenu.dat",ios::in|ios::binary);
	while(fin.read((char*)&o,sizeof(o)))
	{
		if(c==1)
		{
			max=o.returnino();
		}
		else if(max<o.returnino())
		{
			max=o.returnino();
		}

	}
	fin.close();
	return max+1;
}
int Automccafe()
{
	int max=200,c=1;
	menu o;
	ifstream fin;
	fin.open("mccafemenu.dat",ios::in|ios::binary);
	while(fin.read((char*)&o,sizeof(o)))
	{
		if(c==1)
		{
			max=o.returnino();
		}
		else if(max<o.returnino())
		{
			max=o.returnino();
		}

	}
	fin.close();
	return max+1;
}
void deletevegmenu(int r)
{

	menu o;
	fstream fio;
	fio.open("vegmenu.dat",ios::in|ios::out|ios::binary);
	while(fio.read((char*)&o,sizeof(o)))
	{
		if(o.returnino()==r)
		{
			o.getupdate();
			fio.seekg(fio.tellg()-sizeof(o),ios::beg);
			fio.write((char*)&o,sizeof(o));
		}

	}
	fio.close();

}

void deletenonvegmenu(int r)
{

	menu o;
	fstream fio;
	fio.open("nonvegmenu.dat",ios::in|ios::out|ios::binary);
	while(fio.read((char*)&o,sizeof(o)))
	{
		if(o.returnino()==r)
		{
			o.getupdate();
			fio.seekg(fio.tellg()-sizeof(o),ios::beg);
			fio.write((char*)&o,sizeof(o));
		}
		else
		{

			gotoxy(24,12);
			cout<<"Record Not Found!!..";
			getch();
			gotoxy(24,12);
			cout<<"                    ";
			clrscr();
			boxlayout();
			updatemenuoptions();
		}
	}
	fio.close();
}

void deletemccafemenu(int r)
{

	menu o;
	fstream fio;
	fio.open("mccafemenu.dat",ios::in|ios::out|ios::binary);
	while(fio.read((char*)&o,sizeof(o)))
	{
		if(o.returnino()==r)
		{
			o.getupdate();
			fio.seekg(fio.tellg()-sizeof(o),ios::beg);
			fio.write((char*)&o,sizeof(o));
		}
		else
		{

			gotoxy(24,12);
			cout<<"Record Not Found!!..";
			getch();
			gotoxy(24,12);
			cout<<"                    ";
			clrscr();
			boxlayout();
			updatemenuoptions();
		}


	}
	fio.close();

}



void deletewindow()
{
	menu o;
up:
	clrscr();
	boxlayout();
	int ch;
	gotoxy(30,10);
	cout<<"1) Veg Menu.";
	gotoxy(30,12);
	cout<<"2) Non - Veg Menu.";
	gotoxy(30,14);
	cout<<"3) Mc Cafe";
	gotoxy(30,16);
	cout<<"4) Back";
	gotoxy(33,3.5);
	textcolor(RED);
	cprintf("Delete Menu");
	textcolor(WHITE);
	ch=getche();

	if(ch=='1')
	{
	top:
		clrscr();
		boxlayout();
		int i;
		gotoxy(22,10);
		cout<<"Enter The Item Code No. To Be Deleted=";
		cin>>i;
		if(VerifyINo(i)==1)
		{
			deletevegmenu(i);
			gotoxy(24,12);
			cout<<"Your Record Has Been Edited..!!";
			getch();
			gotoxy(24,12);
			cout<<"                                ";
		}
		else
		{
			gotoxy(30,12);
			cout<<"                                 ";
			gotoxy(30,12);
			cout<<"Invalid Choice";
			getch();
		}
		gotoxy(30,12);
		cout<<"                            ";
		gotoxy(30,14);
		cout<<"                             ";
		gotoxy(24,12);
		cout<<"Do You Want To Delete More(Y/N)=";
		char ch1;
		ch1=getche();
		if(ch1=='y'||ch1=='Y')
		{
			goto top;
		}
		else if(ch1=='n'|| ch1=='N')
		{
			clrscr();
			boxlayout();
			updatemenuoptions();
		}
	}

	else if(ch=='2')
	{
	top1:
		clrscr();
		boxlayout();
		int i;
		gotoxy(22,10);
		cout<<"Enter The Item Code No. To Be Deleted=";
		cin>>i;
		if(VerifyNonVegINo(i)==1)
		{
			deletenonvegmenu(i);
			gotoxy(24,12);
			cout<<"Your Record Has Been Edited..!!";
			getch();
			gotoxy(24,12);
			cout<<"                                ";
		}
		else
		{
			gotoxy(30,12);
			cout<<"                                 ";
			gotoxy(30,12);
			cout<<"Invalid Choice";
			getch();
			gotoxy(30,12);
			cout<<"                    ";
		}
		char ch2;
		gotoxy(24,12);
		cout<<"Do You Want To Delete More(Y/N)=";
		ch2=getche();
		if(ch2=='y'||ch2=='Y')
		{
			goto top1;
		}
		else if(ch2=='n'|| ch2=='N')
		{
			clrscr();
			boxlayout();
			name1();
			mainwindow();
		}
	}
	else if(ch=='3')
	{
	top2:
		clrscr();
		boxlayout();
		int i;
		gotoxy(22,10);
		cout<<"Enter The Item Code No. To Be Deleted=";
		cin>>i;
		if(VerifyMcCafeINo(i)==1)
		{
			deletemccafemenu(i);
			gotoxy(24,12);
			cout<<"Your Record Has Been Edited..!!";
			getch();
			gotoxy(24,12);
			cout<<"                                ";
		}
		else
		{
			gotoxy(30,12);
			cout<<"                                 ";
			gotoxy(30,12);
			cout<<"Invalid Choice";
			getch();
			gotoxy(30,12);
			cout<<"                    ";
		}
		char ch3;
		gotoxy(24,12);
		cout<<"Do You Want To Delete More(Y/N)=";
		ch3=getche();
		if(ch3=='y'||ch3=='Y')
		{
			goto top2;
		}
		else if(ch3=='n'|| ch3=='N')
		{
			clrscr();
			boxlayout();
			name1();
			mainwindow();
		}
	}
	else if(ch=='4')
	{
		clrscr();
		boxlayout();
		updatemenuoptions();
	}
	else
	{
		gotoxy(35,23);
		cout<<"Invalid choice";
		getch();
		gotoxy(35,23);
		cout<<"               ";
		goto up;

	}

}


void password()
{
	int c=1;
	top:
	struct abc
	{
		char username[50];
		char PWD[10];
	};
	abc obj;
	char a[100];
	gotoxy(30,10);
	cout<<"UserName=";
	gotoxy(30,13);
	cout<<"Password=";
	gotoxy(40,10);
	cin>>obj.username;
	PWD:
	if(strcmpi("DHRUVIN",obj.username)==0 || strcmpi("JENISH",obj.username)==0 || strcmpi("HARSH",obj.username)==0)
	{
		int x=40,y=13,index=0;
		for(int i=0;i<=100;i++)
		{
			gotoxy(x,y);
			char ch=getche();

			if(ch==13)
			{

				a[index]='\0';
				if(strcmpi(a,"HACKERS")==0)
				{
				        clrscr();
				        boxlayout();
				        updatemenuoptions();
				}
				else if(strcmpi(a,"RESET")==0)
				{
					remove("bill.dat");
					remove("vegmenu.dat");
					remove("nonvegmenu.dat");
					remove("mccafe.dat");
					clrscr();
					McName();
					gotoxy(30,16);
					cout<<"Programme Reseted..";
					getch();
					clrscr();
					boxlayout();
					updatemenuoptions();
				}
				else
				{
					gotoxy(40,13);
					cout<<"INVALID PASSWORD";
					delay(1000);
					gotoxy(40,13);
					cout<<"                 ";
					c++;
					if(c<=3)
					{

						goto PWD;

					}
					else if(c==4)
					{
						gotoxy(34,18);
						cout<<"DISABLED FOR 5 SEC";
						delay(5000);
						gotoxy(34,18);
						cout<<"                   ";
						goto PWD;
					}
					else if(c==5)
					{
						gotoxy(34,18);
						cout<<"DISABLED FOR 10 SEC";
						delay(10000);
						gotoxy(34,18);
						cout<<"                   ";
						goto PWD;
					}
					else if(c==6)
					{
						gotoxy(34,18);
						cout<<"DISABLED FOR 15 SEC";
						delay(15000);
						gotoxy(34,18);
						cout<<"                   ";
						goto PWD;
					}
					else
					{
						gotoxy(30,18);
						cout<<"SORRY U DON'T KNOW THE PASSWORD...";
						delay(2000);
						gotoxy(30,18);
						cout<<"                                  ";
						exit(0);
					}
				}
			}

			else if(ch==8)
			{
					index--;
					a[index]=0;
					x--;
					gotoxy(x,y);
					cout<<" ";
					x--;
			}
			else
			{
				a[index]=ch;
				gotoxy(x,y);
				cout<<"*";
				index++;
			}
			x++;

		}
	}
	else
	{
		gotoxy(40,10);
		cout<<"INVALID USERNAME";
		delay(1000);
		gotoxy(40,10);
		cout<<"                ";
		goto top;
	}



}
void loading()
{
	gotoxy(30,21);
	cout<<"PLEASE WAIT..!";
	gotoxy(30,22);
	for(int i=0;i<=13;i++)
	{
		cout<<char(177);
	}
	gotoxy(30,22);
	for(i=0;i<=13;i++)
	{
		delay(100);
		cout<<char(219);
	}

}
void writebill(int ch,int B)
{
	menu o;
	ofstream fout;
	ifstream Veg,NonVeg,McCafe;
	Veg.open("vegmenu.dat",ios::in|ios::binary);
	NonVeg.open("nonvegmenu.dat",ios::in|ios::binary);
	McCafe.open("mccafemenu.dat",ios::in|ios::binary);
	fout.open("bill.dat",ios::app|ios::binary);
	while(Veg.read((char*)&o,sizeof(o)) || NonVeg.read((char*)&o,sizeof(o)) || McCafe.read((char*)&o,sizeof(o)))
	{
		if(ch==o.returnino())
		{
			o.getbilldata(ch,B);
			fout.write((char*)&o,sizeof(o));
			break;
		}

	}
	fout.close();
	Veg.close();
	NonVeg.close();
	McCafe.close();
}
void readbill(int ch1)
{
	menu o;
	ifstream fin;
	int rno=7;
	int total=0;
	int rno1=7;
	fin.open("bill.dat",ios::in|ios::binary);
	while(fin.read((char*)&o,sizeof(o)))
	{
		if(ch1==o.returnbillno())
		{
			if(rno<23)
			{
				o.putbilldata(rno++);
				total+=o.returnprice();
			}
		}
	}
	fin.close();
	if(j!=1)
	{
	int Sgst=0.08*total;
	int Cgst=0.05*total;
	int BillTotal=total+Cgst+Sgst;
	int Cash;
	gotoxy(49,10);
	cout<<"YOUR S-GST (8%) Was="<<Sgst;
	gotoxy(49,12);
	cout<<"YOUR C-GST (5%) Was="<<Cgst;
	gotoxy(49,14);
	cout<<"Total="<<BillTotal;
	}
}

int autobill()
{
	int max=1000,d=1;
	menu o;
	ifstream fin;
	fin.open("bill.dat",ios::in|ios::binary);
	while(fin.read((char*)&o,sizeof(o)))
	{
		if(d==1)
		{
			max=o.returnbillno();
		}
		else if(max<o.returnbillno())
		{
			max=o.returnbillno();
		}

	}
	fin.close();
	return max+1;
}

void deletebill(int r)
{
	menu o;
	ifstream fin;
	ofstream fout;
	fin.open("bill.dat",ios::in|ios::binary);
	fout.open("tbill.dat",ios::out|ios::binary);
	while(fin.read((char*)&o,sizeof(o)))
	{
		if(o.returnbillno()!=r)
		{
			fout.write((char*)&o,sizeof(o));
		}
	}
	fin.close();
	fout.close();
	remove("bill.dat");
	rename("tbill.dat","bill.dat");
}
void DeleteOrder(int bno,int r)
{
	menu o;
	ifstream fin;
	ofstream fout;
	fin.open("bill.dat",ios::in|ios::binary);
	fout.open("tbill.dat",ios::out|ios::binary);
	while(fin.read((char*)&o,sizeof(o)))
	{
		if(o.returnbillno()==bno)
		{
			if(o.returnino()!=r)
			{
				fout.write((char*)&o,sizeof(o));
			}
		}
	}
	fin.close();
	fout.close();
	remove("bill.dat");
	rename("tbill.dat","bill.dat");
}
void time()
{
	time_t m;
	time (&m);
	cout<<ctime (&m);

}
int VerifyBillNo(int a)
{
	menu C;
	ifstream fin;
	fin.open("bill.dat",ios::in|ios::binary);
	while(fin.read((char *) &C, sizeof(C)))
	{
		if(a==C.returnbillno())
		{
			fin.close();
			return 1;
		}
	}
	fin.close();
	return 0;
}
int VerifyINo(int a)
{
	menu C;
	ifstream veg ,nonveg, mccafe;
	veg.open("vegmenu.dat",ios::in|ios::binary);
	mccafe.open("mccafemenu.dat",ios::in|ios::binary);

	while(veg.read((char *) &C, sizeof(C)))
	{
		if(a==C.returnino())
		{
			veg.close();
			return 1;
		}
	}
	veg.close();
	return 0;
}
int VerifyNonVegINo(int a)
{
	menu C;
	ifstream nonveg;
	nonveg.open("nonvegmenu.dat",ios::in|ios::binary);
	while( nonveg.read((char *) &C, sizeof(C)))
	{
		if(a==C.returnino())
		{
			nonveg.close();
			return 1;
		}
	}

	nonveg.close();
	return 0;
}
int VerifyMcCafeINo(int a)
{
	menu C;
	ifstream mccafe;
	mccafe.open("mccafemenu.dat",ios::in|ios::binary);
	while(mccafe.read((char *) &C, sizeof(C)))
	{
		if(a==C.returnino())
		{
			mccafe.close();
			return 1;
		}
	}

	mccafe.close();
	return 0;
}
int VerifyDeleteIno(int Bno,int a)
{
	menu C;
	ifstream fin;
	fin.open("bill.dat",ios::in|ios::binary);
	while(fin.read((char *) &C, sizeof(C)))
	{

		if(Bno==C.returnbillno())
		{
			if(a==C.returnino())
			{
				fin.close();
				return 1;
			}
		}
	}

	fin.close();
	return 0;
}

void BillLayout()
{
	clrscr();
	textcolor(WHITE);
	dispHLines();

	gotoxy(1,24);
	dispHLines();
	for(float i=5;i<=24;i++)
	{
		gotoxy(46,i);
		cout<<char(176);
	}

	gotoxy(1,4);
	dispHLines();
	dispVLines();


}

void readbill1(int ch1)
{
	menu o;
	ifstream fin;
	int rno=7;
	int total=0;
	int rno1=7;
	fin.open("bill.dat",ios::in|ios::binary);
	while(fin.read((char*)&o,sizeof(o)))
	{
		if(ch1==o.returnbillno())
		{
			if(rno<23)
			{
				total+=o.returnprice();
				o.putbilldata(rno++);
			}

		}
	}
	fin.close();
	int Sgst=0.08*total;
	int Cgst=0.05*total;
	int BillTotal=total+Cgst+Sgst;
	int Cash=0;
	gotoxy(49,10);
	time();
	gotoxy(49,12);
	cout<<"S-GST (8%)="<<Sgst;
	gotoxy(49,14);
	cout<<"C-GST (5%)="<<Cgst;
	gotoxy(49,16);
	cout<<"Total="<<BillTotal;
	top:
	gotoxy(49,18);
	cout<<"Cash Tandered=";
	cin>>Cash;
	if(Cash<BillTotal)
	{
	         gotoxy(63,18);
	         cout<<"INVALID";
	         getch();
	         gotoxy(49,18);
	         cout<<"                        ";
	         goto top;
	}
	else
	{
		gotoxy(49,20);
		cout<<"Change="<<Cash-BillTotal;
		getch();
		exit(0);
	}
}
void McName()
{
	textcolor(YELLOW);
	cout<<"\t   _____         ________                        __      _\n";
	cout<<"\t  /     \\   ____ \\       \\   ____   ____ _____  |  |  __| | ______\n";
	cout<<"\t /  \\ /  \\_/ ___\\ |   |   \\ /  _ \\ /    \\\\__  \\ |  | / __ |/  ___/\n";
	cout<<"\t/    Y    \\  \\___ |   |    (  <_> )   |  \\/ __ \\|  |/ /_/ |\\___ \\\n";
	cout<<"\t\\____|__  /\\_____>_________/\\____/|___|___|_____|__|\\____/\\_____/\n\n";
	textcolor(WHITE);

}
void main()
{
clrscr();
	textcolor(YELLOW);
	cout<<"\t       __      __        __\n";
	cout<<"\t      /  \\    /  \\ ____ |  | ____  ____    _____   ____ \n";
	cout<<"\t      \\   \\/\\/   // __ \\|  |/ ___\\/  _ \\  /     \\ / __ \\\n";
	cout<<"\t       \\        /|  ___/|  |  \\__(  <_> )|  Y Y  \|  ___/\n";
	cout<<"\t        \\__/\\__/  \\____\\|__|\\_____>____/ |__|_|__|\\____\\\n";
	cout<<"\t   _____         ________                        __      _\n";
	cout<<"\t  /     \\   ____ \\       \\   ____   ____ _____  |  |  __| | ______\n";
	cout<<"\t /  \\ /  \\_/ ___\\ |   |   \\ /  _ \\ /    \\\\__  \\ |  | / __ |/  ___/\n";
	cout<<"\t/    Y    \\  \\___ |   |    (  <_> )   |  \\/ __ \\|  |/ /_/ |\\___ \\\n";
	cout<<"\t\\____|__  /\\_____>_________/\\____/|___|___|_____|__|\\____/\\_____/\n\n";
	textcolor(WHITE);
	gotoxy(32,16);
	textcolor(10+128);
	cprintf("Press Any Key!!");
	getch();
	clrscr();
	textcolor(WHITE);
	boxlayout();
	name();
	mainwindow();
getch();
}
