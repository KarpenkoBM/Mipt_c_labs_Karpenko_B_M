# include <iostream>
# include <cstring>

struct section
{
    int beginning;
    int ending;

    bool operator^( const section& other) const
    {
        section main = {beginning, ending};

            if(other.beginning < main.beginning
               and main.beginning < other.ending
               or other.beginning < main.ending
               and main.ending < other.ending
               or other.beginning > main.beginning
               and main.beginning> other.ending
               or other.beginning > main.ending
               and main.ending > other.ending
               or main.beginning == other.beginning
               or main.beginning == other.ending
               or main.ending== other.beginning
               or main.ending == other.ending)
            {
                //std::cout<<"b";
                return true;
            }
            else
            {
                //std::cout<<"c";
                return false;
            }
        }
};
int main ()
{
    int N = 0;
    std::cin>>N;
    section *group = new section[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> group[i].beginning >> group[i].ending;
    }
    for (int i = 0; i < N; i++)
    {
        for (int p = i + 1; p < N; p++)
        {
            if ((group[i] ^ group[p]) == false )
            {
                std::cout<<"NO"<<std::endl;
                return 0;
            }
        }
    }
    std::cout<<"YES"<<std::endl;
    delete[] group;
    return 0;
}

