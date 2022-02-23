# include <iostream>

using namespace std;
int main()
{
    int number, volume_of_two = 0;
    cin >> number;
    if (number == 0)
    {
        cout << "It is a zero, man."<<endl;
    }
    else
    {
        while (number > 1)
        {

            if (number % 2 == 0)
            {
                number/= 2;
            }
            else
            {
                cout << " NO NO NO"<<endl;
                return 0;
            }
        }
     cout << " YEZ YEZ YEZ"<<endl;
    }
return 0;
}
