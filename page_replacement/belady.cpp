#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int calculateFIFOFaults(vector<int>& pages, int frameCount)
{
    queue<int> q;
    unordered_set<int> frames;

    int pageFaults = 0;

    for(int page : pages)
    {
        if(frames.find(page) == frames.end())
        {
            pageFaults++;

            if(frames.size() < frameCount)
            {
                frames.insert(page);
                q.push(page);
            }
            else
            {
                int victim = q.front();

                q.pop();

                frames.erase(victim);

                frames.insert(page);

                q.push(page);
            }
        }
    }

    return pageFaults;
}

void runBeladyDemo()
{
    vector<int> pages =
    {
        1,2,3,4,
        1,2,5,
        1,2,3,
        4,5
    };

    int faults3 =
        calculateFIFOFaults(pages,3);

    int faults4 =
        calculateFIFOFaults(pages,4);

    cout << "\n====================================\n";
    cout << "      Belady's Anomaly Demo\n";
    cout << "====================================\n";

    cout << "\nReference String:\n";

    for(int page : pages)
    {
        cout << page << " ";
    }

    cout << "\n\nFrames = 3";
    cout << "\nPage Faults = "
         << faults3
         << endl;

    cout << "\nFrames = 4";
    cout << "\nPage Faults = "
         << faults4
         << endl;

    if(faults4 > faults3)
    {
        cout << "\nBelady's Anomaly Detected!\n";
    }
    else
    {
        cout << "\nNo Anomaly Detected.\n";
    }

    cout << "\n====================================\n";
}