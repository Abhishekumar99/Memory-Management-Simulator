#include <iostream>

using namespace std;

void showMemoryLayout()
{
    cout << "\nMemory Layout\n\n";

    cout << "+--------+--------+--------+--------+--------+\n";
    cout << "|   P1   |   P2   |  Free  |   P3   |  Free  |\n";
    cout << "+--------+--------+--------+--------+--------+\n";
}

void showFrames()
{
    cout << "\nFrames\n\n";

    cout << "+-----+-----+-----+\n";
    cout << "|  1  |  5  |  2  |\n";
    cout << "+-----+-----+-----+\n";
}

void runVisualization()
{
    cout << "\n====================================\n";
    cout << "      Memory Visualization\n";
    cout << "====================================\n";

    showMemoryLayout();

    showFrames();

    cout << "\n====================================\n";
}