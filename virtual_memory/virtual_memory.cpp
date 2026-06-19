#include <iostream>
#include <unordered_map>

using namespace std;

struct PageTableEntry
{
    int frameNumber;
    bool valid;
};

class VirtualMemory
{
private:
    unordered_map<int, int> tlb;

    unordered_map<int, PageTableEntry> pageTable;

    int pageSize;

public:
    VirtualMemory()
    {
        pageSize = 1024;

        // TLB Entries
        tlb[0] = 3;
        tlb[1] = 1;
        tlb[2] = 5;

        // Page Table Entries
        pageTable[0] = {3, true};
        pageTable[1] = {1, true};
        pageTable[2] = {5, true};
        pageTable[3] = {7, true};
        pageTable[4] = {2, true};
    }

    void translateAddress()
    {
        int logicalAddress;

        cout << "Enter Logical Address: ";
        cin >> logicalAddress;

        int pageNumber =
            logicalAddress / pageSize;

        int offset =
            logicalAddress % pageSize;

        cout << "\n========== Address Translation ==========\n";

        cout << "Logical Address : "
             << logicalAddress
             << endl;

        cout << "Page Number     : "
             << pageNumber
             << endl;

        cout << "Offset          : "
             << offset
             << endl;

        int frameNumber;

        // Step 1: TLB Lookup
        if (tlb.find(pageNumber) != tlb.end())
        {
            cout << "\nTLB HIT" << endl;

            frameNumber = tlb[pageNumber];
        }
        else
        {
            cout << "\nTLB MISS" << endl;

            // Step 2: Page Table Lookup
            if (pageTable.find(pageNumber) != pageTable.end()
                && pageTable[pageNumber].valid)
            {
                cout << "PAGE TABLE HIT" << endl;

                frameNumber =
                    pageTable[pageNumber].frameNumber;

                // Update TLB
                tlb[pageNumber] = frameNumber;

                cout << "TLB Updated" << endl;
            }
            else
            {
                cout << "\nPAGE FAULT!" << endl;
                return;
            }
        }

        int physicalAddress =
            frameNumber * pageSize + offset;

        cout << "\nFrame Number    : "
             << frameNumber
             << endl;

        cout << "Physical Address: "
             << physicalAddress
             << endl;

        cout << "\n=========================================\n";
    }

    void displayTLB()
    {
        cout << "\n========== TLB ==========\n";

        cout << "Page\tFrame\n";

        for (auto entry : tlb)
        {
            cout << entry.first
                 << "\t"
                 << entry.second
                 << endl;
        }

        cout << "=========================\n";
    }

    void displayPageTable()
    {
        cout << "\n======= PAGE TABLE =======\n";

        cout << "Page\tFrame\tValid\n";

        for (auto entry : pageTable)
        {
            cout << entry.first
                 << "\t"
                 << entry.second.frameNumber
                 << "\t"
                 << entry.second.valid
                 << endl;
        }

        cout << "==========================\n";
    }
};

int main()
{
    VirtualMemory vm;

    vm.displayTLB();

    vm.displayPageTable();

    vm.translateAddress();

    return 0;
}