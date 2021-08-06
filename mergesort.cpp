// mergesort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
#include"vector.h"
template<typename T>
void mergesort( vector<T>&);
template<typename T>
void merge( vector<T>&,  vector<T>&,  vector<T>&);
int main()
{
	int value;
	vector<int> obj;
	for (size_t i = 6; i >=1; i--)
	{
		obj.push_back(i);
	}
	cout << "values after merge sort are:\n";
	mergesort(obj);
	for (auto it : obj)
	{
		cout << it << endl;
	}
	system("pause");

}
template<typename T>
void mergesort( vector<T>& obj)
{
	vector<T> S1,S2;
	int size=obj.size();
	if (size <= 1)
		return;
	 typename vector<T>::iterator it = obj.begin();
	for (size_t i = 0; i <size/2; i++)
	{
		S1.push_back(*it);
		++it;
	}
	for (size_t i =size/2; i <size; i++)
	{
		S2.push_back(*it);
		++it;
	}
	obj.clear();
	mergesort(S1);
	mergesort(S2);
	merge(obj, S1, S2);
}
template<typename T>
void merge( vector<T>&S,  vector<T>&S1,  vector<T>& S2)
{
	typename vector<T>::iterator  left = S1.begin();
	typename vector<T>::iterator right = S2.begin();
	while (left!=S1.end() && right!=S2.end())
	{
		if (*left > *right)
		{
			S.push_back(*right);
			++right;
		}
		else
		{
			S.push_back(*left);
			++left;
		}
	}
	while (left!=S1.end())
	{
		S.push_back(*left);
		++left;
	}
	while (right != S2.end())
	{
		S.push_back(*right);
		++right;
	}
	
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
