#include <iostream>
#include <iomanip>
#include "Header.h"
using namespace std;

    //Overview of all data for user, when function is called, a series of print statements are output to the user.
    void outputData() {
        cout << "******************************** " << endl;
        cout << "********** Data Input ********** " << endl;
        cout << "Initial Investment Amount: " << endl;
        cout << "Monthly Deposit: " << endl;
        cout << "Annual Interest: " << endl;
        cout << "Number of years: " << endl;
        //Waiting for user input to continue
        system("PAUSE");
    }

    //Initial Investment function. User must provide input.
    double initialInvestment() {
        cout << "******************************** " << endl;
        cout << "********** Data Input ********** " << endl;
        double intiInv;
        cout << "Enter Initial Investment: $";
        cin >> intiInv;
        while (intiInv < 0) {
            cout << "Please enter a positive real number ";
            cin >> intiInv;
        }
        return intiInv;
    }
    //Monthly Deposit function. User must provide input.
    double monthlyDeposit() {
        double monDepo;
        cout << "Enter Monthly Deposit: $";
        cin >> monDepo;
        while (monDepo < 0) {
            cout << "Please enter a positive real number ";
            cin >> monDepo;
        }
        return monDepo;
    }

    //Annual Interest function. User must provide input.
    double annualInterest() {
        double anInt;
        cout << "Enter Annual Interest: %";
        cin >> anInt;
        while (anInt < 0) {
            cout << "Please enter a positive real number ";
            cin >> anInt;
        }
        return anInt;
    }

    //Number Years function. User must provide input.
    double numberYears() {
        double numYears;
        cout << "Enter Number of Years: ";
        cin >> numYears;
        while (numYears < 0) {
            cout << "Please enter a positive real number ";
            cin >> numYears;
        }
        return numYears;
    }

    //First data table for balance and interest without monthly deposits. 
    void dataTable() {
        system("PAUSE");
        cout << endl;
        cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
        cout << "========================================================================" << endl;
        cout << "Year\t\tYear End Balance\tYear End Earned Interest" << endl;
        cout << "------------------------------------------------------------------------" << endl;
    }

    //Second data table for balance and interest WITH monthly deposits.
    void dataTable2() {
        cout << endl;
        cout << "Balance and Interest With Additional Monthly Deposits" << endl;
        cout << "========================================================================" << endl;
        cout << "Year\t\tYear End Balance\tYear End Earned Interest" << endl;
        cout << "------------------------------------------------------------------------" << endl;
    }
 
    //MAIN
    int main() {

        //Calling outputData for introductionary print statements for user.
        outputData();

        //Calling our functions and storing our varibles for later use.
        double intiInv = initialInvestment();
        double monthlyDepo = monthlyDeposit();
        double anInt = annualInterest();
        double numYears = numberYears();

        //Declaring variables we will use later.
        double monthlyInt;
        double yearlyInt;

        //Temporary total
        double totalBal = intiInv;

        //Calling our data table function.
        dataTable();
        
        //Make a for loop to fill the table out.
        for (int i = 1; i <= numYears; i++) {

            //Yearly interest is calculated.
            yearlyInt = (totalBal) * ((anInt / 100));

            //Total at the years end is updated.
            totalBal += yearlyInt;

            //Results are now printed to finish the table. setprecision(2) is used to eliminate additional decimal places 
            cout << (i) << "\t\t$" << fixed << setprecision(2) << totalBal << " \t\t\t $" << yearlyInt << endl;
        }
        //Reset total for next table.
        totalBal = intiInv;

        //Calling dataTable2 now, showing Monthly Deposits.
        dataTable2();

        //For loop to fill table out (with Monthly Deposit).
        for (int i = 1; i <= numYears; i++) {
            yearlyInt = 0;
                //Must use a nested loop to calculate monthly deposit and interest at end of each month.
            for (int j = 1; j <= 12; j++) {

                //Monthly interest is calculated.
                monthlyInt = (totalBal + monthlyDepo) * ((anInt / 100) / 12);

                //Yearly interest is calculated.
                yearlyInt = yearlyInt + monthlyInt;

                //Total at the years end is updated.
                totalBal = totalBal + monthlyDepo + monthlyInt;
            }
                //Results are now printed to finish the table. setprecision(2) is used to eliminate additional decimal places. 
                cout << (i) << "\t\t$" << fixed << setprecision(2) << totalBal << " \t\t\t $" << yearlyInt << endl;
        }
        return 0;
    }