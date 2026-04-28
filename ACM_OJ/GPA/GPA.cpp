#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string line;
    while (getline(cin, line))
    {
        stringstream ss(line);
        string grade;
        double sum = 0;
        int count = 0;
        bool valid = true;
        while (ss >> grade)
        {
            if (grade == "A") sum += 4;
            else if (grade == "B") sum += 3;
            else if (grade == "C") sum += 2;
            else if (grade == "D") sum += 1;
            else if (grade == "F") sum += 0;
            else 
            {
                valid = false;
                break;
            }
            count++;
        }
        if (!valid || count == 0)
            cout << "Unknown" << endl;
        else
            cout << fixed << setprecision(2) << sum / count << endl;
    }
    return 0;
}