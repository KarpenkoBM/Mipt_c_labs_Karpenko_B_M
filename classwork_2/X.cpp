# include <iostream>

using namespace std;
int main()
{
    cout << "You want to use a float or a double type ? ";
    string type;
    cin >> type;
    int number;
    cout << "Enter a number : ";
    cin >> number;
    if (type == "float")
    {
        float row = 0;
        for (int i = 1; i <= number; i++)
        {
           row += (float)1/(i * i);
        }
        cout <<"Sum of the row : "<< row;
    }
    else if (type == "double")
    {
        double row = 0;
        for (int i = 1; i <= number; i++)
        {
           row += (double)1/(i * i);
        }
        cout <<"Sum of the row : "<< row;
    }
    else
    {
        cout <<"Error";
    }
    return 0;

}
