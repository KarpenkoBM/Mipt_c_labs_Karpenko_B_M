# include <iostream>
# include <random>
# include <fstream>
# include <ctime>
#include <iomanip>
using namespace std;

const int MAX = 100;

mt19937 generator(time(0));
uniform_int_distribution<int> distr(1, 2);

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void start_positions(short (&cristal)[MAX], int (&dislocation_cor)[MAX], const int N, const int Number_of_dislocations)
{
     uniform_int_distribution<int> dislocation_generate(0, N - 1);
    for (int dislocation = 0; dislocation < Number_of_dislocations; dislocation++)
        {
                int dislocation_x = dislocation_generate(generator);
                while (cristal[dislocation_x] > 0)
                {
                    dislocation_x = dislocation_generate(generator);
                }
                if (cristal[dislocation_x] == 0)
                {
                    cristal[dislocation_x] = 1;
                    dislocation_cor[dislocation] = dislocation_x;
                }
                //cout << dislocation_cor[dislocation][0] <<' ' << dislocation_cor[dislocation][1]<< endl;
        }
}

short congluation_check(short (&arr)[MAX], int new_x, int x, const int Number_of_cells, bool somebody_is_around)
    {
        short dead_dislocations = 0;
        if (arr[new_x] > 0)
        {
            arr[new_x] = 2;
            dead_dislocations++;
            if (somebody_is_around)
            {
                arr[x] = 2;
                dead_dislocations++;
            }
        }
        return dead_dislocations;
    }

long long int movement(short (&arr)[MAX], int (&dislocation_cor)[MAX],int Number_of_dislocations, int Number_of_cells)
{
    int n = Number_of_dislocations;
    long long int number_of_steps = 0;
        for (int dislocation = 0; dislocation < Number_of_dislocations; dislocation++)
        {
            int x = dislocation_cor[dislocation];
            if (arr[x] == 1)
            {
                if (x == 0 or x == Number_of_cells - 1 )
                {
                    arr[x] = 2;
                    n = n - 1;
                    //cout <<"WALLE"<<endl;
                }
                else
                {
                    bool somebody_is_around = true;
                    n = n - congluation_check( arr, x + 1, x, Number_of_cells, somebody_is_around);
                    n = n - congluation_check( arr, x - 1, x, Number_of_cells, somebody_is_around);
                    //cout <<"LOL "<< n << endl;

                }
            }
        }
    while (n > 0)
    {
        for (int dislocation = 0; dislocation < Number_of_dislocations; dislocation++)
        {
            int x = dislocation_cor[dislocation];
            if (arr[x] == 1)
            {
                int step_direction = distr(generator);
                int new_x = x;
                if (step_direction == 1 )
                {
                    new_x = x + 1;
                }
                else if (step_direction == 2 )
                {
                    new_x = x - 1;
                }
                if (arr[new_x] == 0)
                {
                    swap(arr[x], arr[new_x]);
                }
                else
                {
                    new_x = x;
                }
                dislocation_cor[dislocation] = new_x;
                //cout << dislocation_cor[dislocation][0] <<' '<< dislocation_cor[dislocation][1] << endl;
            }
        }
            for (int dislocation = 0; dislocation < Number_of_dislocations; dislocation++)
        {
            int x = dislocation_cor[dislocation];
            if (arr[x] == 1)
            {
                if (x == 0 or x == Number_of_cells - 1 )
                {
                    arr[x] = 2;
                    n =  n - 1;
                    //cout <<"WALLE"<<endl;
                }
                else
                {
                    bool somebody_is_around = true;
                    n = n - congluation_check( arr, x + 1, x, Number_of_cells, somebody_is_around);
                    n = n - congluation_check( arr, x - 1, x, Number_of_cells, somebody_is_around);
                    //cout <<"LOL "<< n << endl;

                }
            }
        }
            number_of_steps++;
            //cout << number_of_steps<<' '<< n << endl;
    }
    return number_of_steps;
}
int main()
{
    float sum = 0;
    ofstream file("experiment3.txt");
    int n = MAX;
     for (int dislocation = 1; dislocation <= MAX; dislocation++)
    {
        sum = 0;
        for (int i = 0; i < 100; i++)
        {
            short int cristal[MAX] = {0};
            int dislocation_cor[MAX] = {0};
            start_positions(cristal, dislocation_cor, n, dislocation);;
            sum += movement(cristal, dislocation_cor, dislocation, n);
            //cout <<"LOL"<<endl;
        }
        sum /= 100.00;
        file << sum << endl;
        cout << fixed;
        cout <<dislocation <<' ' <<setprecision(5) << sum << endl;
    }
    file.close();
    return 0;
}
