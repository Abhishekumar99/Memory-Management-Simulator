#include <iostream>
#include <vector>

using namespace std;

struct AllocationResult
{
    string algorithm;
    int blockAllocated;
    int fragmentation;
};

AllocationResult firstFit(vector<int> blocks,
                          int process)
{
    for(int block : blocks)
    {
        if(block >= process)
        {
            return {
                "First Fit",
                block,
                block - process
            };
        }
    }

    return {"First Fit",-1,-1};
}

AllocationResult bestFit(vector<int> blocks,
                         int process)
{
    int best = -1;

    for(int i = 0; i < blocks.size(); i++)
    {
        if(blocks[i] >= process)
        {
            if(best == -1 ||
               blocks[i] < blocks[best])
            {
                best = i;
            }
        }
    }

    if(best != -1)
    {
        return {
            "Best Fit",
            blocks[best],
            blocks[best] - process
        };
    }

    return {"Best Fit",-1,-1};
}

AllocationResult worstFit(vector<int> blocks,
                          int process)
{
    int worst = -1;

    for(int i = 0; i < blocks.size(); i++)
    {
        if(blocks[i] >= process)
        {
            if(worst == -1 ||
               blocks[i] > blocks[worst])
            {
                worst = i;
            }
        }
    }

    if(worst != -1)
    {
        return {
            "Worst Fit",
            blocks[worst],
            blocks[worst] - process
        };
    }

    return {"Worst Fit",-1,-1};
}

int main()
{
    vector<int> blocks =
    {
        100,
        500,
        200,
        300,
        600
    };

    int process = 212;

    AllocationResult ff =
        firstFit(blocks, process);

    AllocationResult bf =
        bestFit(blocks, process);

    AllocationResult wf =
        worstFit(blocks, process);

    cout << "\n=========================================\n";
    cout << "Memory Allocation Comparison\n";
    cout << "=========================================\n";

    cout << "\nProcess Size: "
         << process << endl;

    cout << "\nAlgorithm\tBlock\tFragmentation\n";

    cout << ff.algorithm
         << "\t"
         << ff.blockAllocated
         << "\t"
         << ff.fragmentation
         << endl;

    cout << bf.algorithm
         << "\t"
         << bf.blockAllocated
         << "\t"
         << bf.fragmentation
         << endl;

    cout << wf.algorithm
         << "\t"
         << wf.blockAllocated
         << "\t"
         << wf.fragmentation
         << endl;

    return 0;
}