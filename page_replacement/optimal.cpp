#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Optimal
{
private:
    int findVictim(vector<int>& pages,
                   vector<int>& frames,
                   int currentIndex)
    {
        int victimIndex = -1;
        int farthestUse = currentIndex;

        for (int i = 0; i < frames.size(); i++)
        {
            int j;

            for (j = currentIndex + 1;
                 j < pages.size();
                 j++)
            {
                if (frames[i] == pages[j])
                {
                    if (j > farthestUse)
                    {
                        farthestUse = j;
                        victimIndex = i;
                    }
                    break;
                }
            }

            // Page never used again
            if (j == pages.size())
            {
                return i;
            }
        }

        if (victimIndex == -1)
        {
            return 0;
        }

        return victimIndex;
    }

public:
    void simulate(vector<int>& pages, int frameCount)
    {
        vector<int> frames;
        unordered_set<int> frameSet;

        int pageFaults = 0;
        int pageHits = 0;

        for (int i = 0; i < pages.size(); i++)
        {
            int page = pages[i];

            cout << "\nPage Reference: "
                 << page << endl;

            // Page Hit
            if (frameSet.find(page) != frameSet.end())
            {
                pageHits++;
                cout << "Status: HIT" << endl;
            }
            else
            {
                pageFaults++;
                cout << "Status: FAULT" << endl;

                // Free frame available
                if (frames.size() < frameCount)
                {
                    frames.push_back(page);
                    frameSet.insert(page);
                }
                else
                {
                    int victimPos =
                        findVictim(pages,
                                   frames,
                                   i);

                    int victimPage =
                        frames[victimPos];

                    cout << "Removed Page: "
                         << victimPage
                         << endl;

                    frameSet.erase(victimPage);

                    frames[victimPos] = page;

                    frameSet.insert(page);
                }
            }

            cout << "Frames: ";

            for (int p : frames)
            {
                cout << p << " ";
            }

            cout << endl;
        }

        cout << "\n=========================\n";

        cout << "Total References : "
             << pages.size()
             << endl;

        cout << "Page Faults      : "
             << pageFaults
             << endl;

        cout << "Page Hits        : "
             << pageHits
             << endl;

        double hitRatio =
            (double)pageHits /
            pages.size();

        double faultRatio =
            (double)pageFaults /
            pages.size();

        cout << "Hit Ratio        : "
             << hitRatio * 100
             << "%"
             << endl;

        cout << "Fault Ratio      : "
             << faultRatio * 100
             << "%"
             << endl;
    }
};

void runOptimal()
{
    vector<int> pages =
    {
        1,2,3,4,
        1,2,5,
        1,2,3,
        4,5
    };

    int frames = 3;

    Optimal optimal;

    optimal.simulate(pages, frames);
}