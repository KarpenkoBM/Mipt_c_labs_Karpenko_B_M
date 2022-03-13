# include <iostream>
# include <random>
# include <fstream>
# include <ctime>
#include <iomanip>
using namespace std;

const int MAX = 100;
const long int DIS_MAX = MAX * MAX;

mt19937 generator(time(0));
uniform_int_distribution<int> distr(1, 4);

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void start_positions(short (&cristal)[MAX][MAX], int (&dislocation_cor)[DIS_MAX][2], const int N, const int Number_of_dislocations)
{
     uniform_int_distribution<int> dislocation_generate(0, N - 1);
    for (int dislocation = 0; dislocation < Number_of_dislocations; dislocation++)
        {
                int dislocation_x = dislocation_generate(generator);
                int dislocation_y = dislocation_generate(generator);
                while (cristal[dislocation_x][dislocation_y] > 0)
                {
                    dislocation_x = dislocation_generate(generator);
                    dislocation_y = dislocation_generate(generator);
                }
                if (cristal[dislocation_x][dislocation_y] == 0)
                {
                    cristal[dislocation_x][dislocation_y] = 1;
                    dislocation_cor[dislocation][0] = dislocation_x;
                    dislocation_cor[dislocation][1] = dislocation_y;
                }
                //cout << dislocation_cor[dislocation][0] <<' ' << dislocation_cor[dislocation][1]<< endl;
        }
}

short congluation_check(short (&arr)[MAX][MAX], int new_x, int new_y, int x, int y, const int Number_of_cells, bool somebody_is_around)
    {
        short dead_dislocations = 0;
        if (arr[new_x][new_y] > 0)
        {
            arr[new_x][new_y] = 2;
            dead_dislocations++;
            if (somebody_is_around)
            {
                arr[x][y] = 2;
                dead_dislocations++;
            }
        }
        return dead_dislocations;
    }

long long int movement(short (&arr)[MAX][MAX], int (&dislocation_cor)[DIS_MAX][2],int Number_of_dislocations, int Number_of_cells)
{
    int n = Number_of_dislocations;
    long long int number_of_steps = 0;
        for (int dislocation = 0; dislocation < Number_of_dislocations; dislocation++)
        {
            int x = dislocation_cor[dislocation][0];
            int y = dislocation_cor[dislocation][1];
            if (arr[x][y] == 1)
            {
                if (x == 0 or x == Number_of_cells - 1 or y == 0 or y == Number_of_cells - 1)
                {
                    arr[x][y] = 2;
                    n = n - 1;
                    //cout <<"WALLE"<<endl;
                }
                else
                {
                    bool somebody_is_around = true;
                    n = n - congluation_check( arr, x + 1, y, x, y, Number_of_cells, somebody_is_around);
                    n = n - congluation_check( arr, x - 1, y, x, y, Number_of_cells, somebody_is_around);
                    n = n - congluation_check( arr, x , y + 1, x, y, Number_of_cells, somebody_is_around);
                    n = n - congluation_check( arr, x , y - 1, x, y, Number_of_cells, somebody_is_around);
                    //cout <<"LOL "<< n << endl;

                }
            }
        }
    while (n > 0)
    {
        for (int dislocation = 0; dislocation < Number_of_dislocations; dislocation++)
        {
            int x = dislocation_cor[dislocation][0];
            int y = dislocation_cor[dislocation][1];
            if (arr[x][y] == 1)
            {
                int step_direction = distr(generator);
                int new_y = y, new_x = x;
                if (step_direction == 1 )
                {
                    new_x = x + 1;
                }
                else if (step_direction == 2 )
                {
                    new_x = x - 1;
                }
                else if (step_direction == 3 )
                {
                    new_y = y + 1;
                }
                else if (step_direction == 4)
                {
                    new_y = y - 1;
                }
                if (arr[new_x][new_y] == 0)
                {
                    swap(arr[x][y], arr[new_x][new_y]);
                }
                else
                {
                    new_x = x;
                    new_y = y;
                }
                dislocation_cor[dislocation][0] = new_x;
                dislocation_cor[dislocation][1] = new_y;
                //cout << dislocation_cor[dislocation][0] <<' '<< dislocation_cor[dislocation][1] << endl;
            }
        }
            for (int dislocation = 0; dislocation < Number_of_dislocations; dislocation++)
        {
            int x = dislocation_cor[dislocation][0];
            int y = dislocation_cor[dislocation][1];
            if (arr[x][y] == 1)
            {
                if (x == 0 or x == Number_of_cells - 1 or y == 0 or y == Number_of_cells - 1)
                {
                    arr[x][y] = 2;
                    n =  n - 1;
                    //cout <<"WALLE"<<endl;
                }
                else
                {
                    bool somebody_is_around = true;
                    n = n - congluation_check( arr, x + 1, y, x, y, Number_of_cells, somebody_is_around);
                    n = n - congluation_check( arr, x - 1, y, x, y, Number_of_cells, somebody_is_around);
                    n = n - congluation_check( arr, x , y + 1, x, y, Number_of_cells, somebody_is_around);
                    n = n - congluation_check( arr, x , y - 1, x, y, Number_of_cells, somebody_is_around);
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
    ofstream file("experiment2.txt");
    int n = MAX;
     for (int dislocation = 1; dislocation <= DIS_MAX; dislocation++)
    {
        sum = 0;
        for (int i = 0; i < 100; i++)
        {
            short int cristal[MAX][MAX] = {0};
            int dislocation_cor[DIS_MAX][2] = {0};
            start_positions(cristal, dislocation_cor, n, dislocation);;
            sum += movement(cristal, dislocation_cor, dislocation, n);
            //cout <<"LOL"<<endl;
        }
        sum /= 100.0;
        file <<dislocation <<' ' << sum << endl;
        cout << fixed;
        cout <<dislocation <<' ' <<setprecision(5) << sum << endl;
    }
    file.close();
    return 0;
}

