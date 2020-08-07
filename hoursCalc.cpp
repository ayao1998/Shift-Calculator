/**
* Aaron Yao
* Shift Time Calculator
*/

#include <iostream>
using namespace std;
int main()
{
    int startingTimeH = 0, startingTimeM = 0, endingTimeH = 0, endingTimeM = 0;
    int totalHours = 0, totalMinutes = 0, differenceH = 0, differenceM = 0;
    int excessMinutes = 0;
    string amPmStart;
    string amPmEnd;
    string calcAgain = "y";
    while (calcAgain == "y")
    {
        cout << "Enter starting time hour: ";
        cin >> startingTimeH;
        cout << "Enter starting time minute: ";
        cin >> startingTimeM;
        cout << "am or pm? ";
        cin >> amPmStart;
        cout << "Enter ending time hour: ";
        cin >> endingTimeH;
        cout << "Enter ending time minute: ";
        cin >> endingTimeM;
        cout << "am or pm? ";
        cin >> amPmEnd;
        if (amPmStart == "pm" && startingTimeH == 12)
        {
            if (startingTimeM > endingTimeM)
            {
                differenceH = endingTimeH;
                totalHours = differenceH + totalHours - 1;
                differenceM = 60 + endingTimeM - startingTimeM;
                totalMinutes += differenceM;
            }
            else if (startingTimeM <= endingTimeM)
            {
                differenceH = endingTimeH;
                totalHours = differenceH + totalHours;
                differenceM = endingTimeM - startingTimeM;
                totalMinutes += differenceM;
            }
        }
        else if (amPmStart == "pm" && amPmEnd == "pm")
        {
            if (startingTimeM > endingTimeM)
            {
                differenceH = endingTimeH - startingTimeH;
                totalHours = differenceH + totalHours - 1;
                differenceM = 60 + endingTimeM - startingTimeM;
                totalMinutes += differenceM;
            }
            else if (startingTimeM <= endingTimeM)
            {
                differenceH = endingTimeH - startingTimeH;
                totalHours = differenceH + totalHours;
                differenceM = endingTimeM - startingTimeM;
                totalMinutes += differenceM;
            }
        }
        else if (amPmStart == "am" && amPmEnd == "pm")
        {
            if (startingTimeM > endingTimeM)
            {
                differenceH = endingTimeH + 12 - startingTimeH;
                totalHours = differenceH + totalHours - 1;
                differenceM = 60 + endingTimeM - startingTimeM;
                totalMinutes += differenceM;
            }
            else if (startingTimeM <= endingTimeM)
            {
                differenceH = endingTimeH + 12 - startingTimeH;
                totalHours = differenceH + totalHours;
                differenceM = endingTimeM - startingTimeM;
                totalMinutes += differenceM;
            }
        }
        else if (amPmStart == "am" && amPmEnd == "pm")
        {
            if (startingTimeM > endingTimeM)
            {
                differenceH = endingTimeH - startingTimeH;
                totalHours = differenceH + totalHours - 1;
                differenceM = 60 + endingTimeM - startingTimeM;
                totalMinutes += differenceM;
            }
            else if (startingTimeM <= endingTimeM)
            {
                differenceH = endingTimeH - startingTimeH;
                totalHours = differenceH + totalHours;
                differenceM = endingTimeM - startingTimeM;
                totalMinutes += differenceM;
            }
        }
        excessMinutes = totalMinutes / 60;
        totalHours += excessMinutes;
        totalMinutes %= 60;
        if (totalMinutes < 10)
        {
            cout << "Time: " << totalHours << ":0" << totalMinutes << endl;
        }
        else
        {
            cout << "Time: " << totalHours << ":" << totalMinutes << endl;
        }
        cout << "Add another shift? (y/n) ";
        cin >> calcAgain;
        /* while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Add another shift? (y/n) ";
            cin >> calcAgain;
        } */
    }
    if (totalMinutes < 10)
    {
        cout << "Total time: " << totalHours << ":0" << totalMinutes << endl;
    }
    else
    {
        cout << "Total time: " << totalHours << ":" << totalMinutes << endl;
    }
}

//Feb 15-30: 36:15 + time and a half pay
//5:07 + 4:35 + 5:10 + 4:13 + 1:33 + 5:14 + 4:50 + 5:29

//51H march beginnig
// 35:30 march end

// i worked 64:15 april pt 1 LUl
