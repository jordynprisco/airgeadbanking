#include <iostream>
#include <string>
#include <iomanip>
#include "interest.h"
using namespace std;

// Gets inital investment from the user's previous input
double InterestCalculator::GetInitialInvestment() const {
    return m_initialInvestment;
}

// Gets monthly deposit from the user's previous input
double InterestCalculator::GetMonthlyDeposit() const {
    return m_monthlyDeposit;
}

// Gets interest rate from the user's previous input
double InterestCalculator::GetInterestRate() const {
    return m_annualInterestRate;
}

// Calculates and outputs year-end balance and year-end interest based on the user's prior input (no monthly deposit)
void InterestCalculator::CalculateWithoutDeposit() {
    int i;
    int year = 1;
    double openingBalance = GetInitialInvestment();
    double interest;
    double interestSoFar = 0.00;
    double closingBalance;

    // Makes outputs format with two decimal places
    cout << fixed << setprecision(2);

    // Calculates interest earned for each month and adds it to total balance
    for (i = 0; i < m_yearMonths; ++i) {
        interest = openingBalance * ((GetInterestRate() / 100) / 12);
        interestSoFar += interest; // Increments total interest earned for the year
        closingBalance = openingBalance + interest;
        // Displays year-end balance and year-end interest for each year
        if (i % 12 == 11) {
            cout << setw(20) << left << year << setw(20) << left << closingBalance << setw(20) << right << interestSoFar << endl;
            ++year;
            interestSoFar = 0.00; // Resets interest earned for year
        }
        // Update value for next iteration
        openingBalance = closingBalance;
    }
}

// Calculates and outputs year-end balance and year-end interest based on the user's prior input (monthly deposit)
void InterestCalculator::CalculateWithDeposit() {
    int i;
    int year = 1;
    double openingBalance = GetInitialInvestment();
    double interest;
    double interestSoFar = 0.00;
    double closingBalance;
    double monthlyDeposit = GetMonthlyDeposit();

    // Makes outputs format with two decimal places
    cout << fixed << setprecision(2);

    // Calculates interest earned for each month and adds it to total balance
    for (i = 0; i < m_yearMonths; ++i) {
        interest = (openingBalance + monthlyDeposit) * ((GetInterestRate() / 100) / 12);
        interestSoFar += interest; // Increments total interest earned for the year
        closingBalance = (openingBalance + monthlyDeposit) + interest;
        // Displays year-end balance and year-end interest for each year
        if (i % 12 == 11) {
            cout << setw(20) << left << year << setw(20) << left << closingBalance << setw(20) << right << interestSoFar << endl;
            ++year;
            interestSoFar = 0.00; // Resets interest earned for year
        }
        // Update value for next iteration
        openingBalance = closingBalance;
    }
}

// Displays input to get data from user
void InterestCalculator::DisplayDataInput() {
    string exit;
    int numberOfYears;

    cout << "************************************************************" << endl;
    cout << "                         DATA INPUT" << endl;
    cout << "************************************************************" << endl;
    cout << "Initial Investment Amount: $";
    cin >> m_initialInvestment;
    // Makes sure user enters a positive number
    while (m_initialInvestment < 0) {
        cout << "Invalid input. Please enter a positive number." << endl;
        cout << "Initial Investment Amount: $";
        cin >> m_initialInvestment;
    }
    cout << endl;

    cout << "Monthly Deposit: $";
    cin >> m_monthlyDeposit;
    // Makes sure user enters a positive number
    while (m_monthlyDeposit < 0) {
        cout << "Invalid input. Please enter a positive number." << endl;
        cout << "Monthly Deposit: $";
        cin >> m_monthlyDeposit;
    }
    cout << endl;

    cout << "Annual Interest Rate: %";
    cin >> m_annualInterestRate;
    // Makes sure user enters a positive number
    while (m_annualInterestRate < 0) {
        cout << "Invalid input. Please enter a positive number." << endl;
        cout << "Annual Interest Rate: %";
        cin >> m_annualInterestRate;
    }
    cout << endl;

    cout << "Number of Years: ";
    cin >> numberOfYears;
    // Makes sure user enters a positive number
    while (numberOfYears < 0) {
        cout << "Invalid input. Please enter a positive number." << endl;
        cout << "Number of Years: ";
        cin >> numberOfYears;
    }
    // Converts number of years to months
    m_yearMonths = numberOfYears * 12;
    cout << endl;

    cout << "Type anything and hit enter to continue: ";
    cin >> exit;
    cout << endl;
}

// Displays interest output for user without the monthly deposit
void InterestCalculator::OutputWithoutDeposit() {
    cout << "************************************************************" << endl;
    cout << "  Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "************************************************************" << endl;
    cout << "Year           Year-End Balance            Year-End Interest" << endl;
    cout << "============================================================" << endl;
    CalculateWithoutDeposit(); // Outputs the calculated numbers
}

// Displays interest output for user with the monthly deposit
void InterestCalculator::OutputWithDeposit() {
    cout << "************************************************************" << endl;
    cout << "         Balance and Interest With Monthly Deposits" << endl;
    cout << "************************************************************" << endl;
    cout << "Year           Year-End Balance            Year-End Interest" << endl;
    cout << "============================================================" << endl;
    CalculateWithDeposit(); // Outputs the calculated numbers
}
