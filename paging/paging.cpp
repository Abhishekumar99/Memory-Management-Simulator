#include <iostream>
using namespace std;

class Paging
{
public:
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
    }
};

int main()
{
    Paging p;
    p.translateAddress();

    return 0;
}