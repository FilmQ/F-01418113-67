#include <iostream>
using namespace std;

int main() 
{
    int cin_Number, iter_Counter = 0;
    cin >> cin_Number;


    while(1)
    {
        if(cin_Number == 0)
            break;

        if(cin_Number % 2 == 0)
            cin_Number /= 2;
        else
            cin_Number--;
        iter_Counter++;
    }

    cout << iter_Counter << endl;
}