#include <iostream>
#include <vector>

using namespace std;

class WorstFit
{
public:
    void allocate(vector<int> blocks, int processSize)
    {
        int worstIndex = -1;

        for(int i = 0; i < blocks.size(); i++)
        {
            if(blocks[i] >= processSize)
            {
                if(worstIndex == -1 ||
                   blocks[i] > blocks[worstIndex])
                {
                    worstIndex = i;
                }
            }
        }

        if(worstIndex != -1)
        {
            cout << "\nProcess Size: "
                 << processSize << endl;

            cout << "Allocated Block: "
                 << blocks[worstIndex] << endl;

            cout << "Internal Fragmentation: "
                 << blocks[worstIndex] - processSize
                 << endl;
        }
        else
        {
            cout << "Allocation Failed" << endl;
        }
    }
};

void runWorstFit()
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

    WorstFit wf;

    wf.allocate(blocks, processSize);
}