# include <iostream>
# include <random>
# include <fstream>
# include <ctime>
using namespace std;

int main()
{
    mt19937 generator(time(0));
    uniform_int_distribution<int> distr(1, 4);
    //int cristl[101][101]= {0};
    int step_direction = 0, number_of_steps = 0;
    ofstream file ("experiment1.txt");
    for (int i = 0; i <= 1000; i++)
    {
        int sum_of_steps = 0;
        for (int k = 1; k <= 100; k++)
        {
            int dispos_x = ceil(i/2);
            int dispos_y = ceil(i/2);
            while (abs(dispos_x) < i and abs(dispos_y) < i)
            {
                step_direction = distr(generator);
                number_of_steps++;
                if (step_direction == 1 )
                {
                    dispos_x++;
                }
                else if (step_direction == 2 )
                {
                    dispos_x--;
                }
                else if (step_direction == 3 )
                {
                    dispos_y++;
                }
                else if (step_direction == 4)
                {
                    dispos_y--;
                }
            }
            sum_of_steps+= number_of_steps;
            number_of_steps = 0;
        }
        float average_number_of_steps = sum_of_steps / 100.0;
        cout << i << ' ' << average_number_of_steps << endl;
        //file << average_number_of_steps  << endl;
    }

file.close();
return 0;
}
