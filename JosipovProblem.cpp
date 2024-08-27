#include<iostream>

using namespace std;

class KruznaLista
{
public:
	struct Cvor
	{
		int element;
		Cvor* veza;
		Cvor(int element, Cvor* veza): element(element), veza(veza){};
	};
	
private:
	Cvor *prvi;
	Cvor *zadnji;	
	
public:
	KruznaLista():prvi(0), zadnji(0){};
	Cvor* VratiPrvi(){return prvi;};
	bool Prazna();
	void DodajNaPocetak(int element);
	void IzbrisiIza(Cvor *c);
	void Ponavljaj(void(*akcija)(int&));
};

void KruznaLista::IzbrisiIza(Cvor *c)
{
	if(c->veza==c)
	{
		Cvor *p=c->veza;
		prvi=0;
		zadnji=0;
		delete p;
	}
	
	else if(c->veza==zadnji)
	{
		Cvor *p=c->veza;
		c->veza=c->veza->veza;
		zadnji=c;
		delete p;
	}
	
	else if(c->veza==prvi)
	{
		Cvor *p=c->veza;
		c->veza=c->veza->veza;
		prvi=c->veza;
		delete p;
	}
	
	else
	{
		Cvor *p=c->veza;
		c->veza=c->veza->veza;
		delete p;
	}
}

void KruznaLista::Ponavljaj(void(*akcija)(int&))
{
	for(Cvor* tekuci=prvi; tekuci!=zadnji; tekuci=tekuci->veza)
	{
		akcija(tekuci->element);
	}
	akcija(zadnji->element);
}

void KruznaLista::DodajNaPocetak(int element)
{
	if(prvi==0)
	{
		Cvor *novi=new Cvor(element,0);
		novi->veza=novi;
		prvi=novi;
		zadnji=novi;
		return;
	}
	
	Cvor* novi=new Cvor(element, prvi);
	zadnji->veza=novi;
	prvi=novi;
}

bool KruznaLista::Prazna()
{
	if(prvi==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ispis(int &e)
{
	cout<<e<<" "<<endl;
}

int main()
{
	KruznaLista k;
	
	int n, m;
	int brojac=2;
	
	cout<<"Unesite broj osoba: "<<endl;
	cin>>n;
	cout<<endl;
	cout<<"Unesite broj za izbacivanje: "<<endl;
	cin>>m;
	cout<<endl;
	
	for(int i=n; i>=1; i--)
	{
		k.DodajNaPocetak(i);
	}
	
	KruznaLista::Cvor* trenutni=k.VratiPrvi();
	
	for(int i=0; i<m-2; i++)
	{
		trenutni=trenutni->veza;
	}
	
	cout<<"Izbrisan: ";
	cout<<trenutni->veza->element<<endl;
	k.IzbrisiIza(trenutni);

	for(int i=0; i<n-2; i++)
	{
		for(int j=0; j<m-1; j++)
		{
			trenutni=trenutni->veza;
		}
		
		cout<<"Izbrisan: ";
		cout<<trenutni->veza->element<<endl;
		brojac++;
		k.IzbrisiIza(trenutni);
	}
	
	cout<<"Ziv ostao: "<<k.VratiPrvi()->element<<endl;
	cout<<brojac<<endl;
	
	return 0;
}

