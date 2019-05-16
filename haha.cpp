#include <iostream>
#include <windows.h>
#include <string.h>
#include <fstream>
#include <conio.h>
using namespace std;
void lihat(),tambah(),hapus();
typedef struct
{
	string nama_user,pass_user;
	
}data_user;
data_user user[100];
int n=1;
int main()
{	string id,pass;
	cout<<"Masukan ID       :";cin>>id;
	cout<<"Masukan Password :";cin>>pass;
	system ("cls");
	if (id=="rahul" && pass=="rahul55")
	{	char nama[100];
		int hasil;
		int temp;
		cout<<"Masukan Nama Lengkap:";cin>>nama;
		hasil=strlen(nama);
		for (int i = 0; i <hasil-1; i++)
		{
			for (int j = 0; j < hasil-1-i; j++)
			{
				if(nama[j]>nama[j+1])
				{
					temp=nama[j];
					nama[j]=nama[j+1];
					nama[j+1]=temp;
				}
			}
			
		}
		cout<<"Hasil Pengurutan Karakter :";
		for (int i = 0; i < hasil; i++)
		{
			cout<<nama[i];
		}
		
		
		
	}
	
	if (id=="pkk" && pass=="atmosfer")
	{	do{
		int pil;
		cout<<"Selamat Datang Admin \n";
		cout<<"1.Lihat Daftar User \n";
		cout<<"2.Tambah User \n";
		cout<<"3.Hapus User \n";
		cout<<"4.Exit \n";
		cout<<"Pilih :";cin>>pil;
		switch (pil)
		{
				case 1:
				lihat();
				break;
				case 2:
				tambah();
				n=n+1;
				break;
				case 3:
				hapus();
				break;
				case 4:
				cout<<"Terima Kasih/n";
				return(0);
				break;
			default:
				cout<<"Serius lah dulu !!";
		}
		
	}while(1);
		
	}
	
}
void lihat()
{
		ifstream buka;
		buka.open("banyaku.txt");
		buka>>n;
		buka.close();
		ifstream keluarkan;
		keluarkan.open("user.txt");
		for (int i = 0; i < n; i++)
		{
			keluarkan>>user[i].nama_user;
			keluarkan>>user[i].pass_user;
			cout<<i+1<<"."<<user[i].nama_user<<endl;
		}
		keluarkan.close();
		system ("pause");
		system ("cls");
		
}
void tambah()
{		
		int banyak_n;
		ofstream open;
		ifstream close;
		close.open("banyaku.txt");
		if (!close.fail())
		{
	 	close >> banyak_n;
		}
		else
		{
	 	banyak_n = 0;
		}
		close.close();
		
		open.open("banyaku.txt");
		open<< banyak_n + n;
		open.close();
	ofstream masuk;
	masuk.open("user.txt",ios::app);
	for (int i = n-1; i < n; i++)
	{
	cout<<"Masukan ID Baru       :";cin>>user[i].nama_user;
	cout<<"Masukan Password Baru :";cin>>user[i].pass_user;
	masuk<<user[i].nama_user<<endl;
	masuk<<user[i].pass_user<<endl;
	}
	masuk.close();
	system ("pause");
	system ("cls");
	
	
}
void hapus()
{	
		string hapus;
		ifstream buka;
		buka.open("banyaku.txt");
		buka>>n;
		buka.close();
		ifstream out;
		cout<<"Masukan Id yang ingin dihapus :";cin>>hapus;
		for (int i = 0; i < n; i++)
		{
			out>>user[i].nama_user;
			out>>user[i].pass_user;
			if(hapus==user[i].nama_user)
			{
				for (int j = i; j <n ; j++)
				{
					user[j].nama_user=user[j+1].nama_user;
					masuklagi<<user[j+1].nama_user;
				}
				
				n=n-1;
			}
		}
		out.close();
		ofstream masukn;
		masukn.open("banyaku.txt");
		masukn<<n;
		masukn.close;
		
		
		
	
}
