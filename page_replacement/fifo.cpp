#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class FIFO
{
public:
    void simulate(vector<int> &pages, int frameCount)
    {
        queue<int> q;
        unordered_set<int> frames;

        int pageFaults = 0;
        int pageHits = 0;

        for (int page : pages)
        {
            cout << "\nPage Reference: " << page << endl;

            // Page Hit
            if (frames.find(page) != frames.end())
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
                    frames.insert(page);
                    q.push(page);
                }
                else
                {
                    int victim = q.front();
                    q.pop();

                    frames.erase(victim);

                    cout << "Removed Page: "
                         << victim << endl;

                    frames.insert(page);
                    q.push(page);
                }
            }

            cout << "Frames: ";

            queue<int> temp = q;

            while (!temp.empty())
            {
                cout << temp.front() << " ";
                temp.pop();
            }

            cout << endl;
        }

        cout << "\n=========================\n";
        cout << "Total References : "
             << pages.size() << endl;

        cout << "Page Faults      : "
             << pageFaults << endl;

        cout << "Page Hits        : "
             << pageHits << endl;

        double hitRatio =
            (double)pageHits / pages.size();

        double faultRatio =
            (double)pageFaults / pages.size();

        cout << "Hit Ratio        : "
             << hitRatio * 100
             << "%" << endl;

        cout << "Fault Ratio      : "
             << faultRatio * 100
             << "%" << endl;
    }
};

int main()
{
    vector<int> pages =
    {
        1, 2, 3, 4,
        1, 2, 5,
        1, 2, 3,
        4, 5
    };

    int frames = 3;

    FIFO fifo;

    fifo.simulate(pages, frames);

    return 0;
}