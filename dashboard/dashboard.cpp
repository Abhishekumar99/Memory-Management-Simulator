#include <iostream>

using namespace std;

void runDashboard()
{
    // Sample values
    // Later we will connect real statistics

    int fifoFaults = 9;
    int lruFaults = 7;
    int optimalFaults = 6;

    cout << "\n====================================\n";
    cout << "      Performance Dashboard\n";
    cout << "====================================\n";

    cout << "\nPage Replacement Algorithms\n\n";

    cout << "FIFO Faults      : "
         << fifoFaults
         << endl;

    cout << "LRU Faults       : "
         << lruFaults
         << endl;

    cout << "Optimal Faults   : "
         << optimalFaults
         << endl;

    string bestAlgorithm;

    int minimumFaults =
        fifoFaults;

    bestAlgorithm =
        "FIFO";

    if(lruFaults < minimumFaults)
    {
        minimumFaults =
            lruFaults;

        bestAlgorithm =
            "LRU";
    }

    if(optimalFaults < minimumFaults)
    {
        minimumFaults =
            optimalFaults;

        bestAlgorithm =
            "Optimal";
    }

    cout << "\nBest Algorithm : "
         << bestAlgorithm
         << endl;

    cout << "\n====================================\n";
}