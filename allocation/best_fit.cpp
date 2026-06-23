#include <iostream>
#include <vector>

using namespace std;

class BestFit
{
public:
    void allocate(vector<int> blocks, int processSize)
    {
        int bestIndex = -1;

        for(int i = 0; i < blocks.size(); i++)
        {
            if(blocks[i] >= processSize)
            {
                if(bestIndex == -1 ||
                   blocks[i] < blocks[bestIndex])
                {
                    bestIndex = i;
                }
            }
        }

        if(bestIndex != -1)
        {
            cout << "\nProcess Size: "
                 << processSize << endl;

            cout << "Allocated Block: "
                 << blocks[bestIndex] << endl;

            cout << "Internal Fragmentation: "
                 << blocks[bestIndex] - processSize
                 << endl;
        }
        else
        {
            cout << "Allocation Failed" << endl;
        }
    }
};

void runBestFit()
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

    BestFit bf;

    bf.allocate(blocks, processSize);
}