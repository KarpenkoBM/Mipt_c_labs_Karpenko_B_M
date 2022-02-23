# include <iostream>

using namespace std;
int main()
{
    int x,supremum =0;
    int n = 0;
    while (x!=0)
    {
        cin >> x;
        if (x > supremum )
        {
            supremum = x;
            n = 1;
        }
        else if (x == supremum)
        {
            n++;
        }
    }
cout <<" number of maximums : "<< n <<endl;
return 0;
}
