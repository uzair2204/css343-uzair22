//Uzair Ahmad
//CSS 343
//HW 1

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/*
 * Parameters asking user for number of shuffles
 * @return - none
 */
int main(int argc, char** argv)
{
    srand(time(0));

    //Validate number of shuffles to be performed by user. Value should be between 0 and 10
    int totalShuffles = atoi(argv[1]);
    if (!(totalShuffles >= 1 && totalShuffles <= 10))
    {
        cout << "Number of shuffles must be in between [1-10]." << endl;
        exit(-1);
    }

    string digits;

    //Loop do get and validate input from user
    while(true)
    {
        bool isvalid = true;
        cout << "Please input 9 digits to be randomly shuffled:" << endl;
        getline(cin, digits);
        if (digits.size() == 9)
        {
            for (int i = 0; i < digits.size(); i++)
            {
                if (digits[i] < '0' || digits[i] > '9')
                {
                    cout << "Invalid input, try again.\n";
                    isvalid = false;
                    break;
                }
            }
        }
        else
        {
            cout << "Invalid input, try again.\n";
        }
        if (isvalid)
        {
            break;
        }
    }

    //Array used for naming number of shuffles
    string names[10] = { "first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "nineth", "tenth" };

    //Loop for shuffling input and printing output
    for (int t = 0; t < totalShuffles; ++t)
    {
        //Loop to shuffle digits entered by user
        for (int k = 0; k < 100; k++)
        {
            int i = rand() % 9;
            int j = rand() % 9;
            swap(digits[i], digits[j]);
        }

        //Printing out the shuffled digits in required 3x3 format
        cout << "The " << names[t] << " shuffled output is:\n";
        cout << "+-------+\n";
        for (int i = 0; i < 9; i++)
        {
            if (i % 3 == 0)
            {
                cout << "| ";
            }
            cout << digits[i] << " ";
            if (i % 3 == 2)
            {
                cout << "|\n";
            }
        }
        cout << "+-------+\n";
    }

    return 0;
}
