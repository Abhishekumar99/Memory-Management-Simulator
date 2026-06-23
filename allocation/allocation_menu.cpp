#include <iostream>
#include "first_fit.h"
#include "best_fit.h"
#include "worst_fit.h"
#include "compare_allocation.h"

using namespace std;


void runAllocationMenu()
{
    int choice;

    do
    {
        cout << "\n===== Memory Allocation =====\n";

        cout << "1. First Fit\n";
        cout << "2. Best Fit\n";
        cout << "3. Worst Fit\n";
        cout << "4. Compare All\n";
        cout << "5. Back\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                runFirstFit();
                break;

            case 2:
                runBestFit();
                break;

            case 3:
                runWorstFit();
                break;

            case 4:
                runCompareAllocation();
                break;

            case 5:
                break;

            default:
                cout << "\nInvalid Choice\n";
        }

    } while(choice != 5);
}