// The income tax rate for individuals in business depends on the income bracket in which the individual falls.
// Resident individuals enjoy a tax free annual income threshold of UGX. 2,820,000 per annum. The
// balance is taxed at 10%, 20% or 30% depending on the income bracket. Individuals who earn
// above UGX 120,000,000 pa pay an additional 10% on the income above 120m.
// +----------------------+------------------------------------------+------------------------------------------+
// | CHARGEABLE INCOME, CY| RESIDENTS                                | NON-RESIDENTS                             |
// | (UGX Annual)         | RATE OF TAX                              | RATE OF TAX                               |
// +----------------------+------------------------------------------+------------------------------------------+
// | 0 to 2,820,000       | Nil                                      | CY x 10%                                  |
// | 2,820,000 to         | (CY - 2,820,000) x 10%                   | CY x 10%                                  |
// | 4,020,000            |                                          |                                           |
// | 4,020,000 to         | (CY - 4,020,000) x 20% + 120,000         | (CY - 4,020,000) x 20% + 402,000          |
// | 4,920,000            |                                          |                                           |
// | 4,920,000 to         | (CY - 4,920,000) x 30% + 300,000         | (CY - 4,920,000) x 30% + 582,000          |
// | 120,000,000          |                                          |                                           |
// | Above 120,000,000    | [(CY - 4,920,000) x 30% + 300,000]       | [(CY - 4,920,000) x 30% + 582,000]        |
// |                      | + [(CY - 120,000,000) x 10%]             | + [(CY - 120,000,000) x 10%]              |
// +----------------------+------------------------------------------+------------------------------------------+

// You are to write a program to compute personal income tax. Your program should prompt
// the user to enter the residence status and taxable income and then compute the tax. Enter 0 for
// resident and 1 for non-resident.

// Output
// (0-Resident, 1-Non-resident)
// Enter the residence status: 0
// Enter the taxable income: 4,000,000
// Tax is 118000.
import std;
using namespace std;

// Computes personal income tax based on Uganda's PAYE-style brackets.
// residenceStatus: 0 = Resident, 1 = Non-resident
double computeTax(int residenceStatus, double income) {
    double tax = 0.0;

    if (residenceStatus == 0) {
        // Resident
        if (income <= 2'820'000) {
            tax = 0;
        } else if (income <= 4'020'000) {
            tax = (income - 2'820'000) * 0.10;
        } else if (income <= 4'920'000) {
            tax = (income - 4'020'000) * 0.20 + 120'000;
        } else if (income <= 120'000'000) {
            tax = (income - 4'920'000) * 0.30 + 300'000;
        } else {
            tax = (income - 4'920'000) * 0.30 + 300'000
                  + (income - 120'000'000) * 0.10;
        }
    } else {
        // Non-resident
        if (income <= 4'020'000) {
            tax = income * 0.10;
        } else if (income <= 4'920'000) {
            tax = (income - 4'020'000) * 0.20 + 402'000;
        } else if (income <= 120'000'000) {
            tax = (income - 4'920'000) * 0.30 + 582'000;
        } else {
            tax = (income - 4'920'000) * 0.30 + 582'000
                  + (income - 120'000'000) * 0.10;
        }
    }

    return tax;
}

int main() {
    int residenceStatus;
    string incomeStr;

    cout << "(0-Resident, 1-Non-resident)\n";
    cout << "Enter the residence status: ";
    cin >> residenceStatus;

    cout << "Enter the taxable income: ";
    cin >> incomeStr;

    // Strip thousand-separator commas (e.g. "4,000,000") before parsing.
    erase(incomeStr, ',');
    double income = stod(incomeStr);

    double tax = computeTax(residenceStatus, income);

    cout << "Tax is " << tax << ".\n";

    return 0;
}