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

    unordered_map<int,int> tlb;

    unordered_map<int,PageTableEntry> pageTable;

    unordered_map<int,int> disk;

    int pageSize;

    int nextFreeFrame;

    int tlbHits;
    int tlbMisses;
    int pageFaults;

public:

    VirtualMemory()
    {
        pageSize = 1024;

        nextFreeFrame = 10;

        tlbHits = 0;
        tlbMisses = 0;
        pageFaults = 0;

        // TLB

        tlb[0] = 3;
        tlb[1] = 1;
        tlb[2] = 5;

        // Page Table

        pageTable[0] = {3,true};
        pageTable[1] = {1,true};
        pageTable[2] = {5,true};
        pageTable[3] = {7,true};

        // Pages stored on disk

        disk[10] = 1;
        disk[11] = 1;
        disk[12] = 1;
        disk[13] = 1;
        disk[14] = 1;
    }

    void translateAddress()
    {
        int logicalAddress;

        cout << "\nEnter Logical Address: ";
        cin >> logicalAddress;

        int pageNumber =
            logicalAddress / pageSize;

        int offset =
            logicalAddress % pageSize;

        cout << "\nPage Number : "
             << pageNumber
             << endl;

        cout << "Offset      : "
             << offset
             << endl;

        int frameNumber;

        // TLB HIT

        if(tlb.find(pageNumber) != tlb.end())
        {
            tlbHits++;

            cout << "\nTLB HIT\n";

            frameNumber =
                tlb[pageNumber];
        }
        else
        {
            tlbMisses++;

            cout << "\nTLB MISS\n";

            // PAGE TABLE HIT

            if(pageTable.find(pageNumber)
                != pageTable.end()
                &&
               pageTable[pageNumber].valid)
            {
                cout
                << "PAGE TABLE HIT\n";

                frameNumber =
                pageTable[pageNumber]
                .frameNumber;

                tlb[pageNumber] =
                frameNumber;

                cout
                << "TLB UPDATED\n";
            }

            // PAGE FAULT

            else
            {
                pageFaults++;

                cout
                << "\nPAGE FAULT!\n";

                if(disk.find(pageNumber)
                    != disk.end())
                {
                    cout
                    << "Loading page from disk...\n";

                    frameNumber =
                    nextFreeFrame++;

                    pageTable[pageNumber]
                    =
                    {frameNumber,true};

                    tlb[pageNumber]
                    =
                    frameNumber;

                    cout
                    << "Page Loaded Successfully\n";

                    cout
                    << "Frame Allocated : "
                    << frameNumber
                    << endl;
                }
                else
                {
                    cout
                    << "Page not found on disk\n";

                    return;
                }
            }
        }

        int physicalAddress =
            frameNumber *
            pageSize +
            offset;

        cout
        << "\nPhysical Address : "
        << physicalAddress
        << endl;
    }

    void displayStatistics()
    {
        cout
        << "\n========== Statistics ==========\n";

        cout
        << "TLB Hits     : "
        << tlbHits
        << endl;

        cout
        << "TLB Misses   : "
        << tlbMisses
        << endl;

        cout
        << "Page Faults  : "
        << pageFaults
        << endl;

        int total =
            tlbHits + tlbMisses;

        if(total > 0)
        {
            double hitRate =
                ((double)tlbHits
                / total) * 100;

            cout
            << "TLB Hit Rate : "
            << hitRate
            << "%"
            << endl;
        }

        cout
        << "================================\n";
    }
};

int main()
{
    VirtualMemory vm;

    int choice;

    do
    {
        cout
        << "\n===== Virtual Memory Simulator =====\n";

        cout
        << "1. Translate Address\n";

        cout
        << "2. Show Statistics\n";

        cout
        << "3. Exit\n";

        cout
        << "Choice: ";

        cin >> choice;

        switch(choice)
        {
            case 1:
                vm.translateAddress();
                break;

            case 2:
                vm.displayStatistics();
                break;
        }

    } while(choice != 3);

    return 0;
}