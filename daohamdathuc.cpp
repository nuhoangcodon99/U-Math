#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
struct DonThuc
{
	float heso;
	int somu;
};
struct node
{
	DonThuc info;
	node *next;
};
struct DaThuc
{
	node *head;
	node *tail;
};
node* getnode(DonThuc x)
{
	node *p;
	p=new node;
	if(p==NULL)
	{
		cout<<"\n khong du bo nho";
		return NULL;
	}
	p->info=x;
	p->next=NULL;
	return p;
}
void khoitao(DaThuc &L)
{
	L.head=NULL;
	L.tail=NULL;
}
void addhead(DaThuc &L,node *p)
{
	if(L.tail==NULL)
	{
		L.head=p;
		L.tail=p;
	}
	else
	{
		p->next=L.head;
		L.head=p;
	}

}
void themdau(DaThuc &L,DonThuc x)
{
	node *p;
	p=getnode(x);
	addhead(L,p);
}
void nhap(DonThuc &x)
{
	cout<<"\n Nhap Vao don Thuc gom :";
	cout<<"\nNhap vao he so: ";
	cin>>x.heso;
	cout<<"\nNhap so mu: ";
	cin>>x.somu;
}
void nhapDaThuc(DaThuc &L)
{
	int n;
	DonThuc x;
	node *p;
	p=L.head;
	cout << "TMU.Ngoccoder - TINH DAO HAM DA THUC GOM CAC DON THUC.\n";
	cout<<"nhap vao so luong don thuc: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\n Don Thuc "<<i+1 <<" = ";
		nhap(x);

		themdau(L,x);
	}
}
DaThuc daohamDaThuc(DaThuc a)
{
	node *p; 
	p=a.head;
	while(p!=NULL)
	{
		p->info.heso*=p->info.somu;
		p->info.somu-=1;
		p=p->next;
	}
}

void xuatDaThuc(DaThuc L)
{
	cout<<"\n";
	node *p;
	p=L.head;
	while(p!=NULL)
	{
		cout<<(p->info).heso<<"x^"<<(p->info).somu;
		if(p->next!=NULL)
		cout<<"+";
		p=p->next;
	}
}
main()
{
	DaThuc D;
	khoitao(D);
	DonThuc x;
	nhapDaThuc(D);
	cout<<"da thuc vua nhap la :";
	xuatDaThuc(D);cout<<"\n";
	daohamDaThuc(D);
	cout<<"da thuc duoc dao ham la :";
	xuatDaThuc(D);
	getch();
}
