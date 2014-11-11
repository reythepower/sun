#include <iostream>
#include <conio.h>
#include "Array_h.h"
#include <assert.h>

using namespace std;

char* CONTINUE = "Нажмите любую клавишу для продолжения, ESC - выход!";

template <class TypeArray>
int Array <TypeArray>::arrayCount=0;

void input(int& k, const char* n)
{
	while (true)
	{
		cout<<"Введите размер вектора "<<n<<": ";
		ifstream inp("CON");
		inp>>k;
		if (inp.fail() || inp.bad() )
			cout<<"Введенные данные неверны!!!!"<<endl;
		else if ( k<1 || k>1000) cout<<"Неверный размер массива!!!"<<endl;
		else break;
	}
}

void main()
{
	setlocale(LC_ALL, "RUS");
	srand((unsigned) time(NULL));
	int asize=0, bsize=0;
	int t=0;
	
	for (;;)
		{
			cout<<"<======test======> #"<< ++t <<endl;
			cout<<"Вариант 42:"<<endl;
			cout<<"   1) a/b - a, если a<b"<<endl;
			cout<<"X= 2) -b ,если a=b"<<endl;
			cout<<"   3) (a*b-8)/a ,если a>b"<<endl;
			
			try{
				cout <<"Количество созданных целочисленных массивов = " 
					<< Array<int>::getArrayCount() <<endl;
				input(asize, "a");
				input(bsize, "b");
				//*** создание челочисленных массивов ***
				Array<int> a(asize), b(bsize), X;
				cout <<"А теперь количество созданных массивов = " 
					<< Array<int>::getArrayCount()<< endl;
				if (asize <= 10)
				{
					cout<<"Ввод элементов массива а: "<<endl;
					cin>>a;
				}
				if (bsize <= 10)
				{
					cout<<"Ввод элементов массива b: "<<endl;
					cin>>b;
				}
				if (a==b)
				{
				#ifdef _DEBUG
					cout<<" a=b: X=-b"<<endl;
				#endif // _DEBUG
					X=-b;
				}
				else if (a<b)
				{
				#ifdef _DEBUG
					cout<<" a<b: X=a/b - a"<<endl;
					cout<<" a/b= ";
				#endif // _DEBUG
					X=a/b;
				#ifdef _DEBUG
					cout << X << endl;
				#endif
					X -= a;
				}
				else if (a>b)
				{
				#ifdef _DEBUG
					cout<<" a>b: X = (a*b-8) / a"<<endl;
					cout<<" a*b=  "<<endl;
				#endif // _DEBUG
					X = a*b;
				#ifdef _DEBUG
					cout << X << endl;
					cout<<"X= a*b-8"<<endl;
				#endif // _DEBUG
					X -= 8;
				#ifdef _DEBUG
					cout << X << endl;
					cout<<"X= (a*b-8) / а "<<endl;
				#endif // _DEBUG
					X = X/a;
				}
				cout << "Результат X: " << X << endl;
				
				cout <<"Количество созданных вещественных массивов = " 
					<< Array<double>::getArrayCount() <<endl;
				Array<double>::getArrayCount();
				asize=0; bsize=0;
				input(asize, "a");
				input(bsize, "b");
				Array<double> aa(asize), bb(bsize), XX;
				cout <<"А теперь количество созданных массивов = " 
					<< Array<double>::getArrayCount()<< endl;
				if (asize <= 10)
				{
					cout<<"Ввод элементов массива а: "<<endl;
					cin>>aa;
				}
				if (bsize <= 10)
				{
					cout<<"Ввод элементов массива b: "<<endl;
					cin>>bb;
				}
				if (aa==bb)
				{
				#ifdef _DEBUG
					cout<<" a=b: X=-b"<<endl;
				#endif // _DEBUG
					XX=-bb;
				}
				else if (aa<bb)
				{
				#ifdef _DEBUG
					cout<<" a<b: X=a/b - a"<<endl;
					cout<<" a/b= ";
				#endif // _DEBUG
					XX = aa/bb;
				#ifdef _DEBUG
					cout << XX << endl;
				#endif
					XX -= aa;
				}
				else if (aa>bb)
				{
				#ifdef _DEBUG
					cout<<" a>b: X = (a*b-8) / a"<<endl;
					cout<<" a*b=  "<<endl;
				#endif // _DEBUG
					XX = aa*bb;
				#ifdef _DEBUG
					cout << XX << endl;
					cout<<"X= a*b-8"<<endl;
				#endif // _DEBUG
					XX -= 8;
				#ifdef _DEBUG
					cout << XX << endl;
					cout<<"X= (a*b-8) / а "<<endl;
				#endif // _DEBUG
					XX = XX/aa;
				}
				cout << "Результат X: " << XX << endl;

				cout<<CONTINUE<<endl;
			}
			catch(char* exc)
			{
				cout<<"Ошибка: Исключение: "<<exc<< endl;
			}
			catch(...)
			{
				cout<<"Ошибка: Обработка непредвиденной ситуации!"<<endl;
			}
			if (_getch() == 27) return;
		}
}