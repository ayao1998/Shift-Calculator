/**
* Aaron Yao
* Shift Time Calculator
*/

#include <iostream>
#include<fstream>
using namespace std;
int main()
{
    int startingTimeH = 0, startingTimeM = 0, endingTimeH = 0, endingTimeM = 0;
    int totalHours = 0, totalMinutes = 0, differenceH = 0, differenceM = 0;
    int excessMinutes = 0;
    int shift_number = 0;
    string amPmStart;
    string amPmEnd;
    string calcAgain = "y";
    ofstream fileout;
    fileout.open("shiftlog.txt");

    while (calcAgain == "y")
    {
        shift_number++;
        fileout << "SHIFT " << shift_number << " - ";
        cout << "Shift " << shift_number << ":" << endl;
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
                totalHours += differenceH;
                differenceM = 60 + endingTimeM - startingTimeM;
                totalMinutes += differenceM;
            }
            else if (startingTimeM <= endingTimeM)
            {
                differenceH = endingTimeH;
                totalHours += differenceH;
                differenceM = endingTimeM - startingTimeM;
                totalMinutes += differenceM;
            }
        }
        else if (amPmStart == "pm" && amPmEnd == "pm")
        {
            if (startingTimeM > endingTimeM)
            {
                differenceH = endingTimeH - startingTimeH - 1;
                totalHours += differenceH;
                differenceM = 60 + endingTimeM - startingTimeM;
                totalMinutes += differenceM;
            }
            else if (startingTimeM <= endingTimeM)
            {
                differenceH = endingTimeH - startingTimeH;
                totalHours += differenceH;
                differenceM = endingTimeM - startingTimeM;
                totalMinutes += differenceM;
            }
        }
        else if (amPmStart == "am" && amPmEnd == "pm")
        {
            if (startingTimeM > endingTimeM)
            {
                if (endingTimeH == 12)
                {
                    differenceH = endingTimeH - startingTimeH - 1;
                }
                else
                {
                    differenceH = endingTimeH + 12 - startingTimeH - 1;
                }
                totalHours += differenceH;
                differenceM = 60 + endingTimeM - startingTimeM;
                totalMinutes += differenceM;
            }
            else if (startingTimeM <= endingTimeM)
            {
                if (endingTimeH == 12)
                {
                    differenceH = endingTimeH - startingTimeH;
                }
                else
                {
                    differenceH = endingTimeH + 12 - startingTimeH;
                }
                totalHours += differenceH;
                differenceM = endingTimeM - startingTimeM;
                totalMinutes += differenceM;
            }
        }
        else if (amPmStart == "pm" && amPmEnd == "am")
        {
            if (startingTimeM > endingTimeM)
            {
                differenceH = endingTimeH - startingTimeH - 1;
                totalHours += differenceH;
                differenceM = 60 + endingTimeM - startingTimeM;
                totalMinutes += differenceM;
            }
            else if (startingTimeM <= endingTimeM)
            {
                differenceH = endingTimeH - startingTimeH;
                totalHours += differenceH;
                differenceM = endingTimeM - startingTimeM;
                totalMinutes += differenceM;
            }
        }
        excessMinutes = totalMinutes / 60;
        totalHours += excessMinutes;
        totalMinutes %= 60;
        cout << endl;
        if (differenceM < 10)
        {
            cout << "This shift: " << differenceH << ":0" << differenceM << endl;
            fileout << differenceH << ":0" << differenceM << endl;
        }
        else
        {
            cout << "This shift: " << differenceH << ":" << differenceM << endl;
            fileout << differenceH << ":" << differenceM << endl;
        }
        if (totalMinutes < 10)
        {
            cout << "Total time: " << totalHours << ":0" << totalMinutes << endl;
        }
        else
        {
            cout << "Total time: " << totalHours << ":" << totalMinutes << endl;
        }
        if (startingTimeM < 10)
        {
            fileout << "Clocked in - " << startingTimeH << ":0" << startingTimeM << amPmStart << endl;
            fileout << "Clocked out - " << endingTimeH << ":0" << endingTimeM << amPmEnd << endl << endl;
        }
        else
        {
            fileout << "Clocked in - " << startingTimeH << ":" << startingTimeM << amPmStart << endl;
            fileout << "Clocked out - " << endingTimeH << ":" << endingTimeM << amPmEnd << endl << endl;
        }
        cout << "Add another shift? (y/n) ";
        cin >> calcAgain;
        cout << endl;
    }
    if (totalMinutes < 10)
    {
        cout << "Grand total: " << totalHours << ":0" << totalMinutes << endl;
        fileout << "Grand total: " << totalHours << ":0" << totalMinutes << endl;
    }
    else
    {
        cout << "Grand total: " << totalHours << ":" << totalMinutes << endl;
        fileout << "Grand total: " << totalHours << ":" << totalMinutes << endl;
    }
    fileout.close();
}
