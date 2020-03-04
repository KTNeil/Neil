#include <conio.h>
#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <windows.h>

void menu_chinh();

void menu_in_ds();

void menu_tim_kiem();

void Ke_dong_tren_cung_rolster();

void Ke_dong_giua_rolster();

void Ke_dong_duoi_cung_rolster();

void Ke_dong_tren_cung_sandbox();

void Ke_dong_giua_sandbox();

void Ke_dong_duoi_cung_sandbox();

void Ke_dong_tren_cung_damwon();

void Ke_dong_giua_damwon();

void Ke_dong_duoi_cung_damwon();

void menu_add();

class book
{
    protected:
        string id, name, theme, author, pbs, tp, tt;
        int page, number;
    public:
        book()
        {
			tt = "roi";
        }
        
        virtual void add()
        {
            fflush(stdin);
            cout << "Nhap ma so: ";
            getline(cin, id);

			fflush(stdin);
            cout << "Nhap ten sach: ";
            getline(cin, name);
			
			fflush(stdin);
            cout << "Nhap chu de: ";
            getline(cin, theme);

			fflush(stdin);
            cout << "Nhap tac gia: ";
            getline(cin, author);

			fflush(stdin);
            cout << "Nhap NXB: ";
            getline(cin, pbs);
            
            fflush(stdin);
            cout << "Nhap ngay xuat ban theo dinh dang dd/mm/yyyy: ";
            getline(cin, tp);

            cout << "Nhap so trang: ";
            cin >> page;

            cout << "Nhap so luong: ";
            cin >> number;
        }
        
        book(book&a)
        {
            id = a.id;
            name = a.name;
            theme = a.theme;
            author = a.author;
            pbs = a.pbs;
            tp = a.tp;
            page = a.page;
            number = a.number;
        }
        
        virtual void display()
        {		
			cout << char(186) << setw(7) << left << id << char(186) << setw(30) << left << name << char(186) << setw(15) << left << theme << char(186) << setw(25) << left << author << char(186) << setw(15) << left << pbs << char(186) << setw(15) << left << tp << char(186) << setw(10) << left << page << char(186) << setw(10) << left << number << char(186) << setw(10) << left << tt << char(186) << endl;
        }
        
        virtual void readf(ifstream &filein)
        {
            getline(filein, id);

            getline(filein, name);

            getline(filein, theme);

            getline(filein, author);

            getline(filein, pbs);

            getline(filein, tp);

            filein >> page;
            filein.ignore();

            filein >> number;
            filein.ignore();
        }
        
        virtual void writef(fstream &fileout)
        {
			fileout << endl << id << endl;
			fileout << name << endl;
			fileout << theme << endl;
			fileout << author << endl;
			fileout << pbs << endl;
			fileout << tp << endl;
			fileout << page << endl;
			fileout << number;
        }
        
        virtual string getid()
        {
        	return id;
		}
};

class borrow : public book
{
    protected:
        string db, dp;
    public:
        borrow()
        {
			tt = "muon ve";
        }
        void add()
        {
            book :: add();
						
			fflush(stdin);
            cout << "Nhap ngay muon theo dinh dang dd/mm/yyyy: ";
            getline(cin, db);
	
			fflush(stdin);
            cout << "Nhap ngay tra theo dinh dang dd/mm/yyyy: ";
            getline(cin, dp);
        }

        borrow(borrow &a) : book((book&) a)
        {
            db = a.db;
            dp = a.dp;
        }

        void display()
        {
			cout << char(186) << setw(7) << left << id << char(186) << setw(30) << left << name << char(186) << setw(15) << left << theme << char(186) << setw(25) << left << author << char(186) << setw(15) << left << pbs << char(186) << setw(15) << left << tp << char(186) << setw(10) << left << page << char(186) << setw(10) << left << number << char(186) << setw(15) << setw(10) << left << tt << char(186) << setw(15) << left << db << char(186) << setw(15) << left << dp << char(186) << endl;
        }

        void readf(ifstream &filein)
        {
            book :: readf(filein);

            getline(filein, db);

            getline(filein, dp);
        }

        void writef(fstream &fileout)
        {
			book :: writef(fileout);
			
			fileout << endl;
			
			fileout << db << endl;
			
			fileout << dp;
        }
};

class read : public book
{
	protected:
		string tb, tpay;
	public:
		read()
		{
			tt = "muon doc";
		}
		
		void add()
		{
			book :: add();
			
			
			fflush(stdin);
			cout << "Nhap gio muon: " << endl;
			getline(cin, tb);
			
			fflush(stdin);
			cout << "Nhap gio tra: " << endl;
			getline(cin, tpay);
		}
		
		read(read &a) : book((book &) a)
		{
			tb = a.tb;
			tpay = a.tpay;
		}
		
		void display()
		{
			cout << char(186) << setw(7) << left << id << char(186) << setw(30) << left << name << char(186) << setw(15) << left << theme << char(186) << setw(25) << left << author << char(186) << setw(15) << left << pbs << char(186) << setw(15) << left << tp << char(186) << setw(10) << left << page << char(186) << setw(10) << left << number << char(186) << setw(10) << left << tt << char(186) << setw(20) << left << tb << char(186) << setw(20) << left << tpay << char(186) << endl;
		}
		
		void readf(ifstream &filein)
		{
			book :: readf(filein);
			
			getline(filein, tb);
			
			getline(filein, tpay);
		}
		
		void writef(fstream &fileout)
		{
			book :: writef(fileout);
			
			fileout << endl << tb << endl;
			
			fileout << tpay;
		}
};

class Kho : public borrow, public read
{
    private:
        vector <book *> rolster;
        vector <book *> sandbox;
        vector <book *> damwon;
    public:
        void readf(ifstream &filein);
        
        void readf_rolster(ifstream &filein);
        
        void readf_sandbox(ifstream &filein);
        
        void readf_damwon(ifstream &filein);
        
        void display_rolster();
        		
		void writef_rolster(fstream &fileout);
				
		void display_sandbox();
			
		void writef_sandbox(fstream &fileout);
				
		void display_damwon();
			
		void writef_damwon(fstream &fileout);		
		
		book* search_rolster(string ms);
		
		book* search_sandbox(string ms);
		
		book* search_damwon(string ms);
		
		void add_rolster();
		
		void add_sandbox();
		
		void add_damwon();
};


void Kho :: readf_rolster(ifstream &filein)
{
	book *tempt = new book;

    tempt -> readf(filein);

    rolster.push_back(tempt);
}


void Kho :: readf_sandbox(ifstream &filein)
{
	borrow *tempt = new borrow;
	
	tempt -> readf(filein);
	
	sandbox.push_back(tempt);
	
}

void Kho :: readf_damwon(ifstream &filein)
{
	
	read *tempt = new read;
	
	tempt -> readf(filein);
	
	damwon.push_back(tempt);
}


void Kho :: readf(ifstream &filein)
{
    while (!filein.eof())
    {
        int n;
        filein >> n;
        filein.ignore();

        string tmp;
        getline(filein, tmp);

        if (n == 1)
        {
			readf_rolster(filein);
        }

        if (n == 2)
        {
			readf_sandbox(filein);
        }
				
		if (n == 3)
		{
			readf_damwon(filein);	
		}
				
        getline(filein, tmp);
	}
}


void Kho :: display_rolster()
{	
	cout << "              =========================================== DANH SACH SACH TRONG KHO ===========================================" << endl;

	Ke_dong_tren_cung_rolster();
	
	cout << char(186) << setw(7) << left << "ID" << char(186) << setw(30) << left << "Ten sach" << char(186) << setw(15) << left << "Chu de" << char(186) << setw(25) << left << "Tac gia" << char(186) << setw(15) << left << "Nha xuat ban" << char(186) << setw(15) << left << "Ngay xuat ban" << char(186) << setw(10) << left << "So trang" << char(186) << setw(10) << left << "So luong" << char(186) << setw(10) << left << "Tinh trang" << char(186) << endl;
    
	Ke_dong_giua_rolster();	
	for (int i = 0; i < rolster.size(); i++)
    {
        rolster[i] -> display();
		if(i == rolster.size() - 1)
		{
			Ke_dong_duoi_cung_rolster();
		}
		else Ke_dong_giua_rolster();
    }
}

void Kho :: display_sandbox()
{
	cout << "\n\n              =========================================== DANH SACH SACH DANG CHO MUON VE ===========================================" << endl;
	
	Ke_dong_tren_cung_sandbox();
	
	cout << char(186) << setw(7) << left << "ID" << char(186) << setw(30) << left << "Ten sach" << char(186) << setw(15) << left << "Chu de" << char(186) << setw(25) << left << "Tac gia" << char(186) << setw(15) << left << "Nha xuat ban" << char(186) << setw(15) << left << "Ngay xuat ban" << char(186) << setw(10) << left << "So trang" << char(186) << setw(10) << left << "So luong" << char(186) << setw(10) << left << "Tinh trang" << char(186) << setw(15) << left << "Ngay muon" << char(186) << setw(15) << left << "Ngay tra" << char(186) << endl;
	
	Ke_dong_giua_sandbox();
	for (int i = 0; i < sandbox.size(); i++)
	{
		sandbox[i] -> display();
		if (i == sandbox.size() - 1)
		{
			Ke_dong_duoi_cung_sandbox();
		}
		else Ke_dong_giua_sandbox();
	}
}

void Kho :: display_damwon()
{
	cout << "\n\n                    =========================================== DANH SACH SACH DANG CHO MUON DOC ===========================================" << endl;
	
	Ke_dong_tren_cung_damwon();
	
	cout << char(186) << setw(7) << left << "ID" << char(186) << setw(30) << left << "Ten sach" << char(186) << setw(15) << left << "Chu de" << char(186) << setw(25) << left << "Tac gia" << char(186) << setw(15) << left << "Nha xuat ban" << char(186) << setw(15) << left << "Ngay xuat ban" << char(186) << setw(10) << left << "So trang" << char(186) << setw(10) << left << "So luong" << char(186) << setw(10) << left << "Tinh trang" << char(186) << setw(20) << left << "Gio muon" << char(186) << setw(20) << left << "Gio tra" << char(186) << endl;
	
	Ke_dong_giua_damwon();
	for (int i = 0; i < damwon.size(); i++)
	{
		damwon[i] -> display();
		if (i == damwon.size() - 1)
		{
			Ke_dong_duoi_cung_damwon();
		}		
		else Ke_dong_giua_damwon();
	}
}

void Kho :: writef_rolster(fstream &fileout)
{
	for (int i = 0; i < rolster.size(); i++)
	{
		rolster[i]->writef(fileout);
	}
}

void Kho :: writef_sandbox(fstream &fileout)
{
	for (int i = 0; i < sandbox.size(); i ++)
	{
		sandbox[i] -> writef(fileout);
	}
}

void Kho :: writef_damwon(fstream &fileout)
{
	for (int i = 0; i < damwon.size(); i++)
	{
		damwon[i] -> writef(fileout);
	}
}

book* Kho :: search_rolster(string ms)
{	
	bool check = false;
		
	for (int i = 0; i < rolster.size(); i++)
	{
		if(rolster[i]->getid() == ms)
		{
			check = true;
			return rolster[i];
		}
	}
	if (!check) return NULL;
}

book* Kho :: search_sandbox(string ms)
{	
	bool check = false;
		
	for (int i = 0; i < sandbox.size(); i++)
	{
		if(ms == sandbox[i] -> getid())
		{
			check = true;
			return sandbox[i];
		}
	}
	if (!check) return NULL;
}

book* Kho :: search_damwon(string ms)
{
	bool check = false;
	
	for (int i = 0; i < damwon.size(); i++)
	{
		if(ms == damwon[i] -> getid())
		{
			check = true;
			
			return damwon[i];
		}
	}
	if (!check) return NULL;
}


void Kho :: add_rolster()
{
	fstream fileout;
	fileout.open("ds_sach_kho.txt", ios :: app);
	
	int n;
	cout << "Nhap so sach can them " << endl;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cout << "Sach thu " << i + 1 << endl;
		
		book *tempt = new  book;
		
		tempt->add();
		
		rolster.push_back(tempt);
		
		fileout << endl << endl << 1 << endl;
		
		tempt->writef(fileout);
	}
	
	fileout.close();
}

void Kho :: add_sandbox()
{
	fstream fileout;
	fileout.open("ds_sach_kho.txt", ios :: app);
	
	int n;
	cout << "Nhap so sach can them " << endl;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cout << "Sach thu " << i + 1 << endl;
		
		borrow *tempt = new  borrow;
		
		tempt->add();
		
		sandbox.push_back(tempt);
		
		fileout << endl << endl << 2 << endl;
		
		tempt->writef(fileout);
	}
	
	fileout.close();
}

void Kho :: add_damwon()
{
	fstream fileout;
	fileout.open("ds_sach_kho.txt", ios :: app);
	
	int n;
	cout << "Nhap so sach can them " << endl;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cout << "Sach thu " << i + 1 << endl;
		
		read *tempt = new read;
		
		tempt->add();
		
		damwon.push_back(tempt);
		
		fileout << endl << endl << 3 << endl;
		
		tempt->writef(fileout);
	}
	
	fileout.close();
}


void menu_in_ds()
{
	ifstream filein;
    filein.open("ds_sach_kho.txt", ios_base :: in);
	
	Kho i;
	i.readf(filein);
	
	unsigned int x;
	do
	{
		system("cls");
		cout <<  "      -------------------Menu In danh sach-------------------" << endl;
		
		cout << setw(15) << right << char(201);
		
		for (int j = 1; j <= 36; j ++)
		{
			cout << char(205);
		}
		cout << char(187) << endl;
		
		cout << setw(15) << right << char(186) << setw(36) << left << "1. In tat ca sach dang quan ly" << char(186) << endl;
		cout << setw(15) << right << char(186) << setw(36) << left << "2. In danh sach sach trong kho" << char(186) << endl;
		cout << setw(15) << right << char(186) << setw(36) << left << "3. In danh sach sach dang muon ve " << char(186) << endl;
		cout << setw(15) << right << char(186) << setw(36) << left << "4. In danh sach sach dang muon doc " << char(186) << endl;
		cout << setw(15) << right << char(186) << setw(36) << left << "5. Tro ve Menu chinh " << char(186) << endl;
		cout << setw(15) << right << char(200);
		
		for (int j = 1; j <= 36; j ++)
		{
			cout << char(205);
		}
		cout << char(188) << endl;
		
		cin >> x;
		
		if (x == 1)
		{
			system("cls");
			
			i.display_rolster();
			
			i.display_sandbox();
			
			i.display_damwon();
			
			getch();
			
			menu_in_ds();
		}
		if (x == 2)
		{
			system("cls");
			
			i.display_rolster();
			
			getch();
			menu_in_ds();
		}
		if (x == 3)
		{
			system("cls");
			
			i.display_sandbox();
			
			getch();
			menu_in_ds();
		}
		if (x == 4)
		{
			system("cls");
			
			i.display_damwon();
			
			getch();
			menu_in_ds();
		}
		if (x == 5) 
		{
			system("cls");
			menu_chinh();
		}
		
	}while(x > 5);
	
	filein.close();
}

void menu_tim_kiem()
{
	ifstream filein;
    filein.open("ds_sach_kho.txt", ios_base :: in);
    
	Kho i;
	i.readf(filein);
	
	unsigned int kt;
	do
	{
		system("cls");
		cout << "  ---------------------Menu Tim kiem---------------------" << endl;

		cout << setw(15) << right << char(201);
		
		for (int j = 1; j <= 26; j ++)
		{
			cout << char(205);
		}
		cout << char(187) << endl;
		
		cout << setw(15) << right << char(186) << setw(26) << left << "1. Tim sach trong kho" << char(186) << endl;
		cout << setw(15) << right << char(186) << setw(26) << left << "2. Tim sach dang muon ve " << char(186) << endl;
		cout << setw(15) << right << char(186) << setw(26) << left << "3. Tim sach dang muon doc " << char(186) << endl;
		cout << setw(15) << right << char(186) << setw(26) << left << "4. Tro ve Menu chinh " << char(186) << endl;
		cout << setw(15) << right << char(200);
		for (int j = 1; j <= 26; j ++)
		{
			cout << char(205);
		}
		cout << char(188) << endl;

		cin >> kt;
		if (kt == 1)
		{
			system("cls");
			
			string ms;
			cout << "Nhap id can tim kiem: " << endl;
			cin.ignore();
			getline(cin, ms);			
			
			cout << "---------------------------------------------------------------- KET QUA TIM KIEM ----------------------------------------------------------------" << endl;
			
			book *b = i.search_rolster(ms);
			if (b == NULL)
			{
				cout << "Khong tim thay sach co id tren" << endl;
			}
			else
			{
				Ke_dong_tren_cung_rolster();
			
				cout << char(186) << setw(7) << left << "ID" << char(186) << setw(30) << left << "Ten sach" << char(186) << setw(15) << left << "Chu de" << char(186) << setw(25) << left << "Tac gia" << char(186) << setw(15) << left << "Nha xuat ban" << char(186) << setw(15) << left << "Ngay xuat ban" << char(186) << setw(10) << left << "So trang" << char(186) << setw(10) << left << "So luong" << char(186) << setw(10) << left << "Tinh trang" << char(186) << endl;
	
				Ke_dong_giua_rolster();
				
				b -> display();
				
				Ke_dong_duoi_cung_rolster();
			}
			getch();
			
			menu_tim_kiem();
		}
		
		if (kt == 2)
		{
			system("cls");
			
			string ms;
			cout << "Nhap id can tim: " << endl;
			cin.ignore();
			getline(cin, ms);
			
			cout << "---------------------------------------------------------------- KET QUA TIM KIEM ----------------------------------------------------------------" << endl;
	
			
			book *b = i.search_sandbox(ms);
			if (b == NULL)
			{
				cout << "Khong tim thay sach co id tren" << endl;
			}
			else
			{
				Ke_dong_tren_cung_sandbox();
			
				cout << char(186) << setw(7) << left << "ID" << char(186) << setw(30) << left << "Ten sach" << char(186) << setw(15) << left << "Chu de" << char(186) << setw(25) << left << "Tac gia" << char(186) << setw(15) << left << "Nha xuat ban" << char(186) << setw(15) << left << "Ngay xuat ban" << char(186) << setw(10) << left << "So trang" << char(186) << setw(10) << left << "So luong" << char(186) << setw(10) << left << "Tinh trang" << char(186) << setw(15) << left << "Ngay muon" << char(186) << setw(15) << left << "Ngay tra" << char(186) << endl;
	
				Ke_dong_giua_sandbox();
				
				b -> display();
				
				Ke_dong_duoi_cung_sandbox();
			}
			getch();
			menu_tim_kiem();
		}
		
		if (kt == 3)
		{
			system("cls");
			
			string ms;
			cout << "Nhap id can tim: " << endl;
			cin.ignore();
			getline(cin, ms);
			
			cout << "---------------------------------------------------------------- KET QUA TIM KIEM ----------------------------------------------------------------" << endl;
	
			
			book * b = i.search_damwon(ms);
			
			if (b == NULL)
			{
				cout << "Khong tim thay sach co id tren " << endl;
			}
			else
			{
				Ke_dong_tren_cung_damwon();

				cout << char(186) << setw(7) << left << "ID" << char(186) << setw(30) << left << "Ten sach" << char(186) << setw(15) << left << "Chu de" << char(186) << setw(25) << left << "Tac gia" << char(186) << setw(15) << left << "Nha xuat ban" << char(186) << setw(15) << left << "Ngay xuat ban" << char(186) << setw(10) << left << "So trang" << char(186) << setw(10) << left << "So luong" << char(186) << setw(10) << left << "Tinh trang" << char(186) << setw(20) << left << "Gio muon" << char(186) << setw(20) << left << "Gio tra" << char(186) << endl;
	
				Ke_dong_giua_damwon();
	
				b -> display();
	
				Ke_dong_duoi_cung_damwon();
			}
			getch();
			menu_tim_kiem();
		}
		
		if (kt == 4)
		{
			system("cls");
			menu_chinh();
		}
		
	}while(kt > 4);
	
	filein.close();
}

void menu_add()
{
	ifstream filein;
    filein.open("ds_sach_kho.txt", ios_base :: in);
    
	Kho i;
	i.readf(filein);
	
	unsigned int kt;
	do
	{
		system("cls");
		cout << "  ---------------------Menu Them sach---------------------" << endl;

		cout << setw(15) << right << char(201);
		
		for (int j = 1; j <= 30; j ++)
		{
			cout << char(205);
		}
		cout << char(187) << endl;
		
		cout << setw(15) << right << char(186) << setw(30) << left << "1. Them sach vao kho" << char(186) << endl;
		cout << setw(15) << right << char(186) << setw(30) << left << "2. Them sach dang muon ve " << char(186) << endl;
		cout << setw(15) << right << char(186) << setw(30) << left << "3. Them sach dang muon doc " << char(186) << endl;
		cout << setw(15) << right << char(186) << setw(30) << left << "4. Tro ve Menu chinh " << char(186) << endl;
		cout << setw(15) << right << char(200);
		for (int j = 1; j <= 30; j ++)
		{
			cout << char(205);
		}
		cout << char(188) << endl;

		cin >> kt;
		if (kt == 1)
		{
			system("cls");
			
			i.add_rolster();
			
			
			i.display_rolster();
			
			getch();
			
			menu_add();
		}
		
		if (kt == 2)
		{
			
			system("cls");
			
			i.add_sandbox();
			
			i.display_sandbox();
			
			getch();
			
			menu_add();
		}
		
		if (kt == 3)
		{
			system("cls");
			
			i.add_damwon();
			
			i.display_damwon();
			
			getch();
			
			menu_add();
		}
		
		if (kt == 4)
		{
			system("cls");
			menu_chinh();
		}
		
	}while(kt > 4);
	
	filein.close();
}


void menu_chinh()
{	
	unsigned int lc;
	
	do
	{
		system("cls");
		cout << "  -----------------Menu chinh-----------------" << endl;

		cout << setw(15) << right << char(201);
		
		for (int i = 1; i <= 16; i ++)
		{
			cout << char(205);
		}
		cout << char(187) << endl;
		
		
		cout << setw(15) << right << char(186) << setw(16) << left << "1. Them sach" << char(186) << endl;
		cout << setw(15) << right << char(186) << setw(16) << left << "2. In danh sach" << char(186) << endl;
		cout << setw(15) << right << char(186) << setw(16) << left << "3. Tim kiem " << char(186) << endl;
		cout << setw(15) << right << char(186) << setw(16) << left << "4. Thoat " << char(186) << endl;
		
		cout << setw(15) << right << char(200);
		for (int i = 2; i <= 17; i ++)
		{
			cout << char(205);
		}
		cout << char(188) << endl;
		
		cin >> lc;
			
			if (lc == 1)
			{
				menu_add();
			}
			
			if (lc == 2)
			{
				menu_in_ds();
			}
			
			if (lc == 3)
			{
				menu_tim_kiem();
			}
			
			if (lc == 4)
			{
				system("cls");
				break;
			}
			
	}while(lc > 4);		
}


int main()
{	
	menu_chinh();	

    return 0;
}

void Ke_dong_tren_cung_rolster()
{
	cout << char(201);
        	
	for (int i = 1; i <= 7; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 30; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 25; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(187) << endl;
}

void Ke_dong_giua_rolster()
{
	cout << char(204);
        	
	for (int i = 1; i <= 7; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 30; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 25; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(185) << endl;
}

void Ke_dong_duoi_cung_rolster()
{
	cout << char(200);
        	
	for (int i = 1; i <= 7; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 30; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 25; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(188) << endl;
}

void Ke_dong_tren_cung_sandbox()
{
	cout << char(201);
        	
	for (int i = 1; i <= 7; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 30; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 25; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);

	for(int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}

	cout << char(187) << endl;
}

void Ke_dong_giua_sandbox()
{
	cout << char(204);
        	
	for (int i = 1; i <= 7; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 30; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 25; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}

	cout << char(206);

	for(int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}

	cout << char(185) << endl;
}

void Ke_dong_duoi_cung_sandbox()
{
	cout << char(200);
        	
	for (int i = 1; i <= 7; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 30; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 25; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}

	cout << char(202);

	for(int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}

	cout << char(188) << endl;
}

void Ke_dong_tren_cung_damwon()
{
	cout << char(201);
        	
	for (int i = 1; i <= 7; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 30; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 25; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);
	
	for (int i = 1; i <= 20; i++)
	{
		cout << char(205);
	}
	
	cout << char(203);

	for(int i = 1; i <= 20; i++)
	{
		cout << char(205);
	}

	cout << char(187) << endl;
}

void Ke_dong_giua_damwon()
{
	cout << char(204);
        	
	for (int i = 1; i <= 7; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 30; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 25; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(206);
	
	for (int i = 1; i <= 20; i++)
	{
		cout << char(205);
	}

	cout << char(206);

	for(int i = 1; i <= 20; i++)
	{
		cout << char(205);
	}

	cout << char(185) << endl;
}

void Ke_dong_duoi_cung_damwon()
{
	cout << char(200);
        	
	for (int i = 1; i <= 7; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 30; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 25; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 15; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);

	for (int i = 1; i <= 10; i++)
	{
		cout << char(205);
	}
	
	cout << char(202);
	
	for (int i = 1; i <= 20; i++)
	{
		cout << char(205);
	}

	cout << char(202);

	for(int i = 1; i <= 20; i++)
	{
		cout << char(205);
	}

	cout << char(188) << endl;
}
