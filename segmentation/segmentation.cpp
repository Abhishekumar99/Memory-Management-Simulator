#include <iostream>
#include <vector>

using namespace std;

struct Segment
{
    int base;
    int limit;
};

class Segmentation
{
private:
    vector<Segment> segmentTable;

public:
    Segmentation()
    {
        // Segment 0 -> Code
        segmentTable.push_back({1000, 500});

        // Segment 1 -> Data
        segmentTable.push_back({2000, 300});

        // Segment 2 -> Heap
        segmentTable.push_back({3000, 800});

        // Segment 3 -> Stack
        segmentTable.push_back({5000, 400});
    }

    void displaySegmentTable()
    {
        cout << "\n========== Segment Table ==========\n";

        cout << "Segment\tBase\tLimit\n";

        for (int i = 0; i < segmentTable.size(); i++)
        {
            cout << i << "\t"
                 << segmentTable[i].base << "\t"
                 << segmentTable[i].limit
                 << endl;
        }

        cout << "===================================\n";
    }

    void translateAddress()
    {
        int segmentNumber;
        int offset;

        cout << "\nEnter Segment Number: ";
        cin >> segmentNumber;

        cout << "Enter Offset: ";
        cin >> offset;

        // Check valid segment
        if (segmentNumber < 0 ||
            segmentNumber >= segmentTable.size())
        {
            cout << "\nInvalid Segment Number\n";
            return;
        }

        Segment seg =
            segmentTable[segmentNumber];

        // Check limit violation
        if (offset >= seg.limit)
        {
            cout << "\nSegmentation Fault!" << endl;

            cout << "Offset exceeds segment limit."
                 << endl;

            return;
        }

        int physicalAddress =
            seg.base + offset;

        cout << "\nSegment Number : "
             << segmentNumber
             << endl;

        cout << "Base Address   : "
             << seg.base
             << endl;

        cout << "Limit          : "
             << seg.limit
             << endl;

        cout << "Offset         : "
             << offset
             << endl;

        cout << "\nPhysical Address = "
             << physicalAddress
             << endl;
    }
};

void runSegmentation()
{
    Segmentation segmentation;

    segmentation.displaySegmentTable();

    segmentation.translateAddress();
}