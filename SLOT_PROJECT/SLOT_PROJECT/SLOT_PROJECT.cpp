#include "pch.h"
#include <iostream>
#include<time.h>
#include<string>
using namespace std;

int slot(int);
void startbet();
int main()
{
	int account, bet;
	int earn = 0;
	cout << "How much money you have? ";
	cin >> account;
	startbet();
	do
	{
		cout << "Your account: " << account << endl;
		cout << "How much would you like to bet ";
		cin >> bet;
		if (account - bet < 0)
		{
			cout << "Sorry , you have less amount in your account" << endl;
			cout << "You can enter the ammount of money you have in your account" << endl;
			cout << "How much would you like to bet ";
			cin >> bet;
		}
		cout << endl;
		int i = 0, j = 0, k = 0;
		srand(time(0));
		i = slot(i);
		j = slot(j);
		k = slot(k);
		if (i == j && j == k) {
			cout << "#####WIN#####" << endl;
			cout << "# " << i << " | ";
			cout << j << " | ";
			cout << k << " #" << endl;
			cout << "#############";
			cout << endl;
			account = account + (i * bet * 10);
			earn = earn + (i * bet * 10);
			cout << "Your account: " << account << endl;
			cout << "Congrats,you have won" << i * bet * 10 << endl;
			startbet();
			cout << endl;
		}
		else
		{
			cout << "####LOSE#####" << endl;
			cout << "# " << i << " | ";
			cout << j << " | ";
			cout << k << " #" << endl;
			cout << "#############";
			cout << endl;
			account = account - bet;
			earn = earn - bet;
			cout << "Your account: " << account << endl;
			cout << "Sorry,you have lost " << bet << endl;
			startbet();
			cout << endl;
		}
	} while (account > 0 && earn <= 20000);
	if (account <= 0)
	{
		cout << "Insufficient balance";
	}
	else
	{
		cout << "You have reached maximum earn limit";
	}
}
int slot(int)
{
	int randum = rand();
	int numinrange = (randum % 3) + 1;
	return numinrange;
}
void startbet()
{
	cout << "####SLOT#####" << endl;
	cout << "# " << " " << " | ";
	cout << " " << " | ";
	cout << " " << " #" << endl;
	cout << "#############";
	cout << endl;
}
