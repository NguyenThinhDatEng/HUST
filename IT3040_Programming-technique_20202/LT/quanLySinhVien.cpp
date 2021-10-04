#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;
fstream f;

typedef struct SinhVien
{
	string class_name;
	string MSSV;
	string fullName;
	int sex; // 1 is male, 0 is female
	int yearOfBirth;
	double mark;
};

typedef struct Lop
{
	string class_name;
	vector<SinhVien> studentList;
};

vector<Lop> classList;

string chuanHoaXau(string line);

// take the student's name
string name(string fullName);

// return true if name1 < name2
bool soSanhTen(string fullName1, string fullName2); 

// NHẬP THÔNG TIN SINH VIÊN
SinhVien newStudent();

void addA_New_Student(SinhVien sinhvien);

void deleteA_Student(string mssv);

// IN DANH SÁCH SINH VIEN
void instudentList();

// INPUT DỮ LIỆU ĐÃ CÓ
void input();

void menu();

int main()
{
	input();
	bool check = false;
	int choose;
	do
	{
		menu();
		cout << "Nhap vao lua chon cua ban: ";
		cin >> choose;
		fflush(stdin);
		switch (choose)
		{
		case 1:
		{
			cout << "Them sinh vien: " << endl;
			SinhVien sinhvien = newStudent();
			addA_New_Student(sinhvien);

			break;
		}
		case 2:
		{
			cout << "Nhap mssv cua Sinh Vien muon xoa: " << endl;
			string mssv;
			cin >> mssv;
			deleteA_Student(mssv);
			break;
		}
		case 3:
		{
			cout << "\nSap xep danh sach theo thu tu ABC\n" << endl;
			break;
		}
		case 4:
		{
			cout << "\nthe list is already written in your file\n" << endl;
			instudentList();
			break;
		}
		default:
		{
			cout << "Cam on ban da su dung chuong trinh" << endl;
			check = true;
			break;
		}
		}

	} while (check == false);

	return 0;
}

void menu()
{
	printf("************QUAN LY SINH VIEN*****************\n");
	printf("         1. THEM SINH VIEN   \n");
	printf("         2. XOA SINH VIEN   \n");
	printf("         3. SAP XEP DANH SACH SINH VIEN \n");
	printf("         4. IN DANH SACH SINH VIEN\n");
	printf("         VUI LONG CHON TU 1-3, AN PHIM KHAC DE THOAT\n");
}

string chuanHoaXau(string line)
{
	while (isspace(line[0]))
		line.erase(0, 1);

	while (isspace(line.back()))
		line.pop_back();

	for (int i = 0; i < line.length();)
	{
		if (isspace(line[i]) && line[i] != ' ')
			line[i] = ' ';
		if (isspace(line[i]) && isspace(line[i + 1]))
			line.erase(i + 1, 1);
		else
			i++;

	}
	return line;
}

string name(string fullName)
{

	string name;
	for (int i = fullName.length() - 1; i >= 0; i--)
	{
		if (fullName[i] != ' ')
		{
			name = fullName[i] + name;
		}
		else
			break;
	}
	return name;
}

bool soSanhTen(string fullName1, string fullName2) // return true if name1 < name2
{
	string name1 = name(fullName1);
	string name2 = name(fullName2);
	if (name1 < name2)
		return true;
	else if (name1 > name2)
		return false;
	else
	{
		if (fullName1 < fullName2)
			return true;
		else
			return false;
	}
}

SinhVien newStudent()
{
	SinhVien sinhvien;
	string s;

	getline(cin, s);
	cout << "Nhap vao lop sinh vien: ";
	getline(cin, sinhvien.class_name);

	cout << "Nhap vao ma sinh vien: ";
	getline(cin, sinhvien.MSSV);

	cout << "Nhap vao ho ten sinh vien: ";
	getline(cin, s);
	sinhvien.fullName = chuanHoaXau(s);

	cout << "Gioi tinh cua sinh vien (enter number) : Nu - 0   Nam - 1:  ";
	cin >> sinhvien.sex;

	cout << "Nam sinh: ";
	cin >> sinhvien.yearOfBirth;

	cout << "Diem thi cuoi ky: ";
	cin >> sinhvien.mark;

	cout << endl;
	return sinhvien;
}

void addA_New_Student(SinhVien sinhvien)
{
	Lop lop;
	lop.class_name = sinhvien.class_name;

	if (classList.empty())
	{
		lop.studentList.push_back(sinhvien);
		classList.push_back(lop);
	}
	else
	{
		bool dathemlop = false;
		for (int i = 0; i < classList.size(); i++)
		{
			if (lop.class_name == classList.at(i).class_name)
			{
				dathemlop = true;
				break;
			}
			if (lop.class_name < classList.at(i).class_name)
			{
				classList.insert(classList.begin() + i, lop);
				dathemlop = true;
				break;
			}
		}
		if (dathemlop == false)
		{
			classList.push_back(lop);
		}
		bool kt = false;
		int vitri = 0;
		for (int i = 0; i < classList.size(); i++)
		{
			if (classList.at(i).class_name == sinhvien.class_name)
			{
				kt = true;
				vitri = i;
				break;
			}
		}
		if (kt == false)
		{
			classList.push_back(lop);
		}
		else
		{
			bool dathem = false;
			for (int i = 0; i < classList.at(vitri).studentList.size(); i++)
			{
				string hoten = classList.at(vitri).studentList.at(i).fullName;
				if (soSanhTen(sinhvien.fullName, hoten))
				{
					classList.at(vitri).studentList.insert(classList.at(vitri).studentList.begin() + i, sinhvien);
					dathem = true;
					break;
				}
			}
			if (dathem == false)
			{
				classList.at(vitri).studentList.push_back(sinhvien);
			}
		}
	}
}

void instudentList()
{
	f.open("D://NguyenThinhDatSci//Cpp//HUST_IT3040_KTLT_LT//StudentList.txt", ios::out);
	f << setw(30) << left << "Ten lop" << setw(10) << left << "MSSV"
		<< setw(50) << left << "Ho va ten"
		<< setw(20) << left << "Gioi tinh"
		<< setw(20) << left << "Nam sinh"
		<< setw(20) << left << "Diem thi"
		<< endl;

	for (int i = 0; i < classList.size(); i++)
	{
		for (SinhVien sinhvien : classList.at(i).studentList)
		{
			if (sinhvien.sex == 1)
			{
				f << setw(30) << left << sinhvien.class_name << setw(10) << left << sinhvien.MSSV << setw(50) << left << sinhvien.fullName << setw(20) << left
					<< "Nam"
					<< setw(20) << left << sinhvien.yearOfBirth << setw(20) << left << sinhvien.mark << endl;
			}
			if (sinhvien.sex == 0)
			{
				f << setw(30) << left << sinhvien.class_name << setw(10) << left << sinhvien.MSSV << setw(50) << left << sinhvien.fullName << setw(20) << left
					<< "Nu"
					<< setw(20) << left << sinhvien.yearOfBirth << setw(20) << left << sinhvien.mark << endl;
			}
		}
	}

	f.close();
};

void input()
{
	f.open("D://NguyenThinhDatSci//Cpp//HUST_IT3040_KTLT_LT//oldList.txt");

	if (f.fail())
	{
		cout << "file is fail";
		exit(0);
	}

	string line;
	do
	{
		SinhVien sinhvien;

		getline(f, line);
		sinhvien.class_name = chuanHoaXau(line);

		getline(f, line);
		sinhvien.MSSV = chuanHoaXau(line);

		getline(f, line);
		sinhvien.fullName = chuanHoaXau(line);

		getline(f, line);
		line = chuanHoaXau(line);
		if (line.length() == 3)
			sinhvien.sex = 1;
		else
			sinhvien.sex = 0;

		getline(f, line);
		line = chuanHoaXau(line);
		sinhvien.yearOfBirth = stoi(line);

		getline(f, line);
		line = chuanHoaXau(line);
		sinhvien.mark = stod(line);

		addA_New_Student(sinhvien);

		getline(f, line);
	} while (!f.eof());

	f.close();
}

void deleteA_Student(string mssv)
{
	bool check = true;
	for (int i = 0; i < classList.size() && check; i++)
	{
		vector<SinhVien>::iterator it = classList.at(i).studentList.begin();
		for (SinhVien sinhvien : classList.at(i).studentList)
		{
			if (sinhvien.MSSV.compare(mssv) == 0)
			{
				classList.at(i).studentList.erase(it);
				cout << "\nDa xoa thanh cong!!!\n";
				check = false;
				break;
			}
			else
				it++;
		}
	}
	if (check) cout << "\nKhong tim thay sinh vien!\n";
}