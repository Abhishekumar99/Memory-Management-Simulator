#include <iostream>
#include <vector>

using namespace std;

class FirstFit
{
public:
    void allocate(vector<int> blocks, int processSize)
    {
        bool allocated = false;

        for(int i = 0; i < blocks.size(); i++)
        {
            if(blocks[i] >= processSize)
            {
                cout << "\nProcess Size: "
                     << processSize << endl;

                cout << "Allocated Block: "
                     << blocks[i] << endl;

                cout << "Internal Fragmentation: "
                     << blocks[i] - processSize
                     << endl;

                allocated = true;
                break;
            }
        }

        if(!allocated)
        {
            cout << "Allocation Failed" << endl;
        }
    }
};

void runFirstFit()
{
    vector<int> blocks =
    {
        100,
        500,
        200,
        300,
        600
    };

    int processSize = 212;

    FirstFit ff;

    ff.allocate(blocks, processSize);
}