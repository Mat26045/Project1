#include <iostream>
#include <iomanip> 
using namespace std;

double calculateCommission(double sales) {
    if (sales < 10000) return sales * 0.05;
    else if (sales < 15000) return sales * 0.10;
    else if (sales < 18000) return sales * 0.12;
    else if (sales < 22000) return sales * 0.14;
    else return sales * 0.16;
}

int main() {
    char repeat;

    do {
        double sales, advancedPay;

        
        cout << "Enter the salesperson's monthly sales: ";
        cin >> sales;

        while (cin.fail() || sales < 0) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a valid sales amount that is greater than 0: ";
            cin >> sales;
        }

        cout << "Enter the amount of advanced pay for this salesperson: ";
        cin >> advancedPay;

        while (cin.fail() || advancedPay < 0) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a valid advanced pay amount that is greater than 0: ";
            cin >> advancedPay;
        }

        double commission = calculateCommission(sales);

        cout << fixed << setprecision(2);
        cout << "\nPay Results\n";
        cout << "-----------\n";
        cout << "Sales: $" << sales << endl;
        cout << "Commission Rate: " << (commission / sales) * 100 << "%" << endl;
        cout << "Commission: $" << commission << endl;
        cout << "Advanced Pay: $" << advancedPay << endl;

        double remainingPay = commission - advancedPay;

        if (remainingPay > 0) {
            cout << "Remaining Pay: $" << remainingPay << endl;
        }
        else {
            cout << "Amount to repay: $" << -remainingPay << endl; 
        }

        cout << "Do you want to enter another salesperson? (y/n): \n";
        cin >> repeat;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}