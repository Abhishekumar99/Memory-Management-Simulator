#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <list>
#include <unordered_map>

using namespace std;

struct Result
{
    int pageFaults;
    int pageHits;
};

// ================= FIFO =================

Result runFIFO(vector<int>& pages, int frameCount)
{
    queue<int> q;
    unordered_set<int> frames;

    Result result = {0, 0};

    for (int page : pages)
    {
        if (frames.count(page))
        {
            result.pageHits++;
        }
        else
        {
            result.pageFaults++;

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

                frames.insert(page);
                q.push(page);
            }
        }
    }

    return result;
}

// ================= LRU =================

Result runLRU(vector<int>& pages, int frameCount)
{
    list<int> frames;

    unordered_map<int, list<int>::iterator> pageMap;

    Result result = {0, 0};

    for (int page : pages)
    {
        if (pageMap.count(page))
        {
            result.pageHits++;

            frames.erase(pageMap[page]);

            frames.push_front(page);

            pageMap[page] = frames.begin();
        }
        else
        {
            result.pageFaults++;

            if (frames.size() == frameCount)
            {
                int victim = frames.back();

                frames.pop_back();

                pageMap.erase(victim);
            }

            frames.push_front(page);

            pageMap[page] = frames.begin();
        }
    }

    return result;
}

// ================= OPTIMAL =================

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

Result runOptimal(vector<int>& pages,
                  int frameCount)
{
    vector<int> frames;
    unordered_set<int> frameSet;

    Result result = {0, 0};

    for (int i = 0; i < pages.size(); i++)
    {
        int page = pages[i];

        if (frameSet.count(page))
        {
            result.pageHits++;
        }
        else
        {
            result.pageFaults++;

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

                frameSet.erase(victimPage);

                frames[victimPos] = page;

                frameSet.insert(page);
            }
        }
    }

    return result;
}

// ================= MAIN =================

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

    Result fifo =
        runFIFO(pages, frames);

    Result lru =
        runLRU(pages, frames);

    Result optimal =
        runOptimal(pages, frames);

    cout << "\n=====================================\n";
    cout << "Page Replacement Comparison\n";
    cout << "=====================================\n\n";

    cout << "Reference String : ";

    for (int page : pages)
    {
        cout << page << " ";
    }

    cout << "\nFrames           : "
         << frames << "\n\n";

    cout << "-------------------------------------\n";
    cout << "Algorithm\tFaults\tHits\n";
    cout << "-------------------------------------\n";

    cout << "FIFO\t\t"
         << fifo.pageFaults
         << "\t"
         << fifo.pageHits
         << endl;

    cout << "LRU\t\t"
         << lru.pageFaults
         << "\t"
         << lru.pageHits
         << endl;

    cout << "Optimal\t\t"
         << optimal.pageFaults
         << "\t"
         << optimal.pageHits
         << endl;

    cout << "-------------------------------------\n";

    return 0;
}