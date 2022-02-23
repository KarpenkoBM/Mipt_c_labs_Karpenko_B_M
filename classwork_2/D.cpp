# include <iostream>

using namespace std;
int main()
{
    int x,even_supremum =0;
    while (x!=0)
    {
        cin >> x;
        if (x > even_supremum and x % 2 == 0)
        {
            even_supremum = x;
        }
    }
    if (even_supremum  != 0)
    {
        cout <<" maximum even number: "<< even_supremum<<endl;
    }
    else
    {
        cout <<" No even numbers"<< endl;
    }
return 0;
}
