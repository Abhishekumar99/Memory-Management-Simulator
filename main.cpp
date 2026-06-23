#include <iostream>
#include "paging/paging.h"
#include "page_replacement/fifo.h"
#include "page_replacement/lru.h"
#include "page_replacement/optimal.h"
#include "allocation/allocation.h"
#include "segmentation/segmentation.h"
#include "virtual_memory/virtual_memory.h"
#include "page_replacement/belady.h"
#include "dashboard/dashboard.h"
#include "visualization/visualization.h"

using namespace std;

void showMenu()
{
    cout << "\n===================================\n";
    cout << " Memory Management Simulator\n";
    cout << "===================================\n";

    cout << "1. Paging\n";
    cout << "2. FIFO Page Replacement\n";
    cout << "3. LRU Page Replacement\n";
    cout << "4. Optimal Page Replacement\n";
    cout << "5. Memory Allocation\n";
    cout << "6. Segmentation\n";
    cout << "7. Virtual Memory\n";
    cout << "8. Belady's Anomaly Demo\n";
    cout << "9. Performance Dashboard\n";
    cout << "10. Memory Visualization\n";
    cout << "11. Exit\n";
}

int main()
{
    int choice;

    do
    {
        showMenu();

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                runPaging;
                break;

            case 2:
                runFIFO();
                break;

            case 3:
                runLRU();
                break;

            case 4:
                runOptimal();
                break;

            case 5:
                runAllocationMenu();
                break;

            case 6:
                runSegmentation();
                break;

            case 7:
                runVirtualMemory();
                break;

            case 8:
                runBeladyDemo();
                break;
            case 9:
                 runDashboard();
                 break;
            case 10:
                 runVisualization();
                 break;
            case 11:
                cout<<"\nExiting Simulator...\n";
                break;
            default:
                cout << "\nInvalid Choice\n";
        }

    } while(choice != 11);

    return 0;
}