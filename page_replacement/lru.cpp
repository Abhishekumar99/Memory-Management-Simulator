#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

class LRU
{
public:
    void simulate(vector<int>& pages, int frameCount)
    {
        list<int> frames;
        unordered_map<int, list<int>::iterator> pageMap;

        int pageHits = 0;
        int pageFaults = 0;

        for (int page : pages)
        {
            cout << "\nPage Reference: " << page << endl;

            // Page Hit
            if (pageMap.find(page) != pageMap.end())
            {
                pageHits++;

                cout << "Status: HIT" << endl;

                // Move page to front (most recently used)
                frames.erase(pageMap[page]);
                frames.push_front(page);
                pageMap[page] = frames.begin();
            }
            else
            {
                pageFaults++;

                cout << "Status: FAULT" << endl;

                // Frames full
                if ((int)frames.size() == frameCount)
                {
                    int victim = frames.back();

                    cout << "Removed Page: "
                         << victim << endl;

                    frames.pop_back();
                    pageMap.erase(victim);
                }

                frames.push_front(page);
                pageMap[page] = frames.begin();
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

    LRU lru;
    lru.simulate(pages, frames);

    return 0;
}