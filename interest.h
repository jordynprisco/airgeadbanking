#ifndef INTERESTCALCULATOR_H
#define INTERESTCALCULATOR_H

 // Decalres the InterestCalculator Class
class InterestCalculator {
    // Can be accessed by any class
public:
    void DisplayDataInput();
    void OutputWithoutDeposit();
    void OutputWithDeposit();
    void CalculateWithoutDeposit();
    void CalculateWithDeposit();
    double GetInitialInvestment() const;
    double GetMonthlyDeposit() const;
    double GetInterestRate() const;

    // Can only be accessed by the class
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int m_yearMonths;

};

#endif
