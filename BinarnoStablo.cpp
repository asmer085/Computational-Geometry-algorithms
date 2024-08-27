#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

class Stablo
{
	struct Cvor
	{
		int element;
		Cvor *lijevi, *desni;
		Cvor(int element): element(element), lijevi(0), desni(0) {}
	};

	Cvor *korijen;
	void InOrder(void(*Akcija)(int&), Cvor *tekuci);
	void BrisiListove(Cvor *tekuci);

	public:
		Stablo(): korijen(0) {}
		void Umetni(int element);
		void BrisiListove() {BrisiListove(korijen), korijen=0;};
		void Ispisi(void(*akcija)(int&));
};


void Stablo::Umetni(int element)
{
	Cvor *novi=new Cvor(element);

	if(!korijen)
	{
		korijen=novi;
	}

	else
	{
		Cvor *prethodni;
		Cvor *tekuci=korijen;

		while(tekuci)
		{
			prethodni=tekuci;
			if(element<tekuci->element) tekuci=tekuci->lijevi;
			else tekuci=tekuci->desni;
		}

		if(element<prethodni->element) prethodni->lijevi=novi;
		else prethodni->desni=novi;
	}
}


void Stablo::Ispisi(void(*akcija)(int&))
{
    queue<Cvor*> red;
    red.push(korijen);
    while(red.empty()== false)
    {
        Cvor *trenutni = red.front();
        red.pop();
        akcija(trenutni->element);
        if(trenutni->lijevi != nullptr)
            red.push(trenutni->lijevi);
        if(trenutni->desni != nullptr)
            red.push(trenutni->desni);
    }
}
void Stablo::BrisiListove()
{
    korijen->lijevi = BrisiListove(korijen->lijevi);
    korijen->desni = BrisiListove(korijen->desni);
}


void Ispis(int &e)
{
	cout<<e<<endl;
}


int main()
{
	Stablo s;
	s.Umetni(3);
	s.Umetni(4);
	s.Umetni(1);
	s.Umetni(44);

	s.Ispisi(Ispis);
    //s.BrisiListove();
	cout<<endl<<"Nakon brisanja: ";
	s.Ispisi(Ispis);
	cout<<endl;

	return 0;
}
