/*
File Name: Exam1.cpp
Programmer: Morgan Thorne
Date: March 2025
Requirments:
Write a program that uses Crazy Al’s Computer Emporium commission rate on sales
Employees get paid $1500 in advance, program this amount to be subtracted from commission rate
If advance payment is more than commission payment then dispaly that salesman owes Crazy Al
*/


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double Sales = 0;
	double CommissionRate = 0;
	double Commission = 0;
	double AdvancePay = 0;
	double RemainingPay = 0;
	double CrazyAlPayment = 0;

	cout << setw(18) << right << "" << "Commission Rates\n" << setw(15) << right << "" << "Less than $10,000  5%\n";
	cout << setw(15) << right << "" << "$10,000-$14,999   10%\n" << setw(15) << right << "" << "$15,000-$17,999   12%\n";
	cout << setw(15) << right << "" << "$18,000-$21,999   14%\n" << setw(15) << right << "" << "$22,000 or more   16%\n";

	//User enters monthly sales, while statement will display error and allow user to enter a valid value
	cout << endl;
	cout << "Enter your monthly sales: $";
	cin >> Sales;
	while (Sales < 0) {
		cout << "Your sales must be a positive integer\n";
		cout << "Enter your monthly sales: $";
		cin >> Sales;
	}

	//User enters their advance pay, while statement will display error and allow user to enter a valid value
	cout << "Enter your Advance Pay: $";
	cin >> AdvancePay;
	while (AdvancePay < 0 || AdvancePay > 1500) {
		cout << "Your advance pay must be a positive integer from 0 to 1500\n";
		cout << "Enter your Advance Pay: $";
		cin >> AdvancePay;
	}
	
	//If and else if statements determine what the commission rate is based of user's sales
	if (Sales <= 10000) {
		CommissionRate = 0.05;
	}
		else if (Sales >= 10000 || Sales < 15000) {
				CommissionRate = 0.10;
		}
			else if (Sales >= 15000 || Sales < 18000) {
					CommissionRate = 0.12;
			}
				else if (Sales >= 18000 || Sales < 22000) {
						CommissionRate = 0.14;
				}
					else if (Sales >= 22000) {
							CommissionRate = 0.16;
					}

	//Giving value to commission and remaining pay after Commission rate was determined
	Commission = (Sales * CommissionRate);
	RemainingPay = (Commission - AdvancePay);

	//Warning if Sales are lower than Advance Payment
	if (Commission < AdvancePay) {
		CrazyAlPayment = AdvancePay - Sales;
		cout << "WARNING!\n";
		cout << "You owe Crazy Al's $" << CrazyAlPayment;
	}
	
	//Display for payment
	cout << "\n";
	cout << setw(23) << right << "" <<"Payment\n";
	cout << fixed << setprecision(2) << setw(15) << right << "" << "Monthly Sales: $" << Sales << endl;
	cout << setw(15) << right << "" << "Commission Rate: " << setw(7) << right << CommissionRate << endl;
	cout << setw(15) << right << "" << "Commission: " << setw(5) << right << "$" << Commission << endl;
	cout << setw(15) << right << "" << "Advance: " << setw(9) << right << "$" << AdvancePay << endl;
	cout << setw(15) << right << "" << "Remaining Pay: " << setw(2) << right << "$" << RemainingPay << endl;
}


