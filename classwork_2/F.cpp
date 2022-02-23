# include <iostream>

using namespace std;
int main()
{
    int i, number = 0;
    cin >> number;
    for (i=2;i*i < number; i++ )
    {
        if (number % i == 0)
        {
            cout<<"NO NO NO"<<endl;
            return 0;
        }
    }
    cout <<"YEZ YEZ YEZ"<<endl;
    return 0;
}
