#ifndef ARRAY_T_H
#define ARRAY_T_H

#pragma once

#include <iostream>
#include <assert.h> 
#include <fstream>
#include <limits.h>
#include <time.h>
#include <Windows.h>

char* Mult_Over = "Переполнение при умножении вектора!";
char* Sum_Over = "Переполнение при сложении векторов!";
char* Dif_Over = "Переполнение при вычитании векторов!";
char* Div_Exc = "Деление векторов невозможно!";
char* Zero_Exc = "Деление на ноль невозможно!";
char* Ecxeption = "!!!!!!!! Введены неверные данные !!!!!!!!";

using namespace std;

template <class TypeArray>
class Array
{
	template<typename TypeArray> 
    friend ostream &operator<<(ostream &, const Array <TypeArray> &);
	template<typename TypeArray> 
	friend istream &operator>>(istream &, Array <TypeArray> &);

public:
	Array(int=1);        
	Array(const Array &); 
	~Array(); 

	Array& operator=(const Array&);
	Array& operator=(const TypeArray &b);

	int operator==(const Array&) const;
	int operator!=(const Array&) const;

	int operator<(const Array&) const;
	int operator>(const Array&) const;

	Array operator/(const Array& b);
	Array operator-(const TypeArray& b);
	Array operator-();
	Array operator-=(const Array& b);
	Array operator-=(const TypeArray& b);
	Array operator*(const Array& b);

	TypeArray& operator[](int);

	int getsize() const
	{
		return size;
	}

	static int getArrayCount()
	{
		return arrayCount;
	}

	private:
	TypeArray *ptr;
	int size;
	static int arrayCount;
};

	template <class TypeArray> Array <TypeArray>::Array (int arraysize)
	{
		++arrayCount;
		size = arraysize;
		ptr = new TypeArray[size];
		assert(ptr!=0);
		for (int i=0; i<size; i++)
			ptr[i]=rand();
	}

	template <class TypeArray> Array<TypeArray>::Array (const Array &b)
	{
		++arrayCount;
		size = b.size;
		ptr = new TypeArray[size];
		assert(ptr!=0);

		for(int i=0; i<b.size; i++)
			ptr[i]=b.ptr[i];
	}

	template <class TypeArray> Array<TypeArray>::~Array()
	{
		--arrayCount;
		delete[] ptr;
	}

	template <class TypeArray>
	Array<TypeArray>& Array<TypeArray>::operator=(const Array<TypeArray> &b)
	{
		if (&b!=this)
		{
			delete[] ptr;
			size = b.size;
			ptr = new TypeArray[size];
			assert(ptr!=0);

			for(int i=0; i<size; i++)
				ptr[i]=b.ptr[i];
		}
		return *this;
	}

	template <class TypeArray>
	Array<TypeArray>& Array<TypeArray>::operator=(const TypeArray &b)
	{
		for (int i = 0; i < size; i++)
			ptr[i]=b;
		return *this;
	}

	template <class TypeArray>
	int Array<TypeArray>::operator==(const Array &b) const
	{
		long double s1=0, s2=0;
		for(int i=0; i<size; i++)
			s1+=ptr[i];

		for(int i=0; i<b.size; i++)
			s2+=b.ptr[i];

	if (s1==s2) return 1;
	return 0;
	}

	template <class TypeArray>
	int Array<TypeArray>::operator!=(const Array &b) const
	{
		return !(this==b);
	}

	template <class TypeArray>
	int Array<TypeArray>::operator>(const Array &b) const
	{
		long double s1=0, s2=0;

		for(int i=0; i<size; i++)
			s1+=ptr[i];

		for(int i=0; i<b.size; i++)
			s2+=b.ptr[i];

		if (s1>s2) return 1;
		return 0;
	}

	template <class TypeArray>
	int Array<TypeArray>::operator<(const Array &b) const
	{
		long double s1=0, s2=0;

		for(int i=0; i<size; i++)
			s1+=ptr[i];

		for(int i=0; i<b.size; i++)
			s2+=b.ptr[i];

		if (s1<s2) return 1;
		return 0;
	}

	template <class TypeArray>
	Array<TypeArray> Array<TypeArray>::operator/(const Array<TypeArray> &b)
	{
		if (size <= b.size)
	{
		Array<TypeArray> x(b.size);
		for (int i = 0; i < size; i++)
		{
			if (b.ptr[i] == 0) 	throw Zero_Exc;
			else x[i] = ptr[i] / b.ptr[i];
		}
		for (int i = size; i < b.size; i++)
		{
			if (b.ptr[i] == 0) throw Zero_Exc;
			else x[i] = 0;
		}
		return x;
	}
	else throw Div_Exc;
	}

	template <class TypeArray>
	Array<TypeArray> Array<TypeArray>::operator-(const TypeArray &b)
	{
		Array<TypeArray> X(ptr);
		for(int i=0; i<size; i++)
			{
				long double d = ptr[i]*1.0-b;
				if (d>INT_MAX || d<INT_MIN) throw Sum_Over;
				else X[i]-=b;
			}
		return X;
	}
	template <class TypeArray>
	Array<TypeArray> Array<TypeArray>::operator-()
	{
		Array<TypeArray> X;
		for(int i=0; i<size; i++)
			{
				 X[i]=-X[i];
			}
		return X;
	}


	template <class TypeArray>
	Array<TypeArray> Array<TypeArray>::operator-=(const TypeArray &b)
	{
		for(int i=0; i<size; i++)
		{
			long double d = ptr[i]*1.0-b;
			if (d>INT_MAX || d<INT_MIN) throw Sum_Over;
			else ptr[i]-=b;
		}
	return *this;
	}
	template <class TypeArray>
	Array<TypeArray> Array<TypeArray>::operator-=(const Array<TypeArray> &b)
	{
		for(int i=0; i<size; i++)
		{
			long double d = ptr[i]*1.0-b.ptr[i];
			if (d>INT_MAX || d<INT_MIN) throw Sum_Over;
			else ptr[i]-=b.ptr[i];
		}
	return *this;
	}

	template <class TypeArray>
	Array<TypeArray> Array<TypeArray>::operator*(const Array<TypeArray> &b)
	{
		if (size<=b.size) 	
		{
			Array<TypeArray> X(b.size);
			for(int i=0; i<b.size; i++)
				{
					long double m = ptr[i]*1.0*b.ptr[i];
					if (m>INT_MAX || m<INT_MIN) throw Mult_Over;
					X[i]=ptr[i]*b.ptr[i];
				}
			return X;
		}
		else 
		{
			Array<TypeArray> X(size);
			for(int i=0; i<b.size; i++)
				{
					long double m = ptr[i]*1.0*b.ptr[i];
					if (m>INT_MAX || m<INT_MIN) throw Mult_Over;
					X[i]=ptr[i]*b.ptr[i];
				}
			return X;
		}
	}

	template <class TypeArray>
	TypeArray &Array<TypeArray>::operator[] (int n)
	{
		assert(n>=0 && n<size);
		return ptr[n];
	}

	template <class TypeArray>
	istream& operator>>(istream& inp, Array <TypeArray>& Arr)
	{
		for (int i=0; i<Arr.size; i++)
		{
			for (;;)
			{
				cout<<"Введите "<<i<<"-ый элемент: ";
				ifstream inp("CON");
				inp>>Arr.ptr[i];
				if (inp.fail() || inp.bad() )
					cout<<"Ошибка ввода данных!!!"<<endl;
				else break;
			}
		}
	return inp;
	}

	template <class TypeArray>
	ostream& operator<<(ostream& ost, const Array <TypeArray>& Arr)
	{
		for(int i=0; i<Arr.size; i++)
		{
			ost<<Arr.ptr[i]<< "\t";
			if((i+1)!=Arr.size && (i+1)%10==0) ost<<endl;
		}
	return ost;
	}

#endif