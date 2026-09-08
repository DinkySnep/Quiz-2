#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

int countLines(ifstream &file);
void moveDial(int &dial, int clicks, char direction, int &timePassedZero);
void moveDialPartTwo(int &dial, int clicks, char direction, int &timePassedZero);

int main()
{
    int dialVal = 50;
    int dialValTwo = 50;
    int answerOne = 0;
    int answerTwo = 0;

    const string PASSWORD = "DayOnePasswordOne.txt";

    ifstream puzzleInput;
    puzzleInput.open(PASSWORD);

    if (puzzleInput.is_open())
        cout << "File exists and is open.\n";
    else
        cout << "File did not oppen.\n";
    if (puzzleInput.fail() == true)
        cout << "Error With File.\n";

    int moves = countLines(puzzleInput);
    while (moves > 0)
    {
        string currMove;
        getline(puzzleInput, currMove);
        cout << "Current Dial Position: " << dialVal << endl;
        cout << "Current line: " << currMove << " - ";
        char dir = currMove.at(0);
        currMove.erase(0, 1);
        int clickValue = stoi(currMove);
        moveDial(dialVal, clickValue, dir, answerOne);
        moveDialPartTwo(dialValTwo, clickValue, dir, answerTwo);
        cout << "New Dial Position: " << dialVal << endl;

        moves--;
    }

    cout << "The Answer For Part One Should Be " << answerOne << endl;
    cout << "The Answer For Part Two Should Be " << answerTwo << endl;

    puzzleInput.close();

    return 0;
}

int countLines(ifstream &file)
{
    string currLine;
    int lineCount = 0;
    while (getline(file, currLine))
    {
        lineCount++;
    }
    file.clear();
    file.seekg(0);
    return lineCount;
}

void moveDial(int &dial, int clicks, char direction, int &timePassedZero)
{
    switch (direction)
    {
    case 'R':
        cout << "Moved dial " << clicks << " to the Right.\n";
        while (clicks > 0)
        {
            dial++;
            if (dial == 100)
            {
                dial = 0;
            }
            clicks--;
        }
        if (dial == 0)
            timePassedZero++;
        break;
    case 'L':
        cout << "Moved dial " << clicks << " to the Left.\n";
        while (clicks > 0)
        {
            dial--;
            if (dial == -1)
            {
                dial = 99;
            }
            clicks--;
        }
        if (dial == 0)
            timePassedZero++;
        break;
    }
}
void moveDialPartTwo(int &dial, int clicks, char direction, int &timePassedZero)
{
    switch (direction)
    {
    case 'R':
        while (clicks > 0)
        {
            dial++;
            if (dial == 100)
            {
                dial = 0;
                timePassedZero++;
            }
            clicks--;
        }
        break;
    case 'L':
        while (clicks > 0)
        {
            dial--;
            if (dial == -1)
            {
                dial = 99;
            }
            if (dial == 0)
                timePassedZero++;
            clicks--;
        }
        break;
    }
}