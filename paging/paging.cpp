#include <iostream>
#include <unordered_map>

using namespace std;

class Paging
{
private:
    unordered_map<int, int> pageTable;

public:
    Paging()
    {
        pageTable[0] = 3;
        pageTable[1] = 1;
        pageTable[2] = 5;
        pageTable[3] = 2;
    }

    void translateAddress()
    {
        int logicalAddress;
        int pageSize;

        cout << "Enter Logical Address: ";
        cin >> logicalAddress;

        cout << "Enter Page Size: ";
        cin >> pageSize;

        int pageNumber = logicalAddress / pageSize;
        int offset = logicalAddress % pageSize;

        cout << "\nPage Number : "
             << pageNumber << endl;

        cout << "Offset : "
             << offset << endl;

        if(pageTable.find(pageNumber) == pageTable.end())
        {
            cout << "\nPage not found in page table!" << endl;
            return;
        }

        int frameNumber = pageTable[pageNumber];

        int physicalAddress =
            frameNumber * pageSize + offset;

        cout << "\nFrame Number : "
             << frameNumber << endl;

        cout << "Physical Address : "
             << physicalAddress << endl;
    }
};

void runPaging()
{
    Paging p;
    p.translateAddress();
}