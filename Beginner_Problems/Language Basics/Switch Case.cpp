class Solution
{
public:
    void whichWeekDay(int day)
    {
        if (day > 7 || day < 1)
        {
            cout << "Invalid";
        }
        else
        {
            switch (day)
            {
            case 1:
                cout << "Monday";
                break;
            case 2:
                cout << "Tuesday";
                break;
            case 3:
                cout << "Wednesday";
                break;
            case 4:
                cout << "Thursday";
                break;
            case 5:
                cout << "Friday";
                break;
            case 6:
                cout << "Saturday";
                break;
            case 7:
                cout << "Sunday";
                break;
            }
        }
        cout << "\n";
    }
};