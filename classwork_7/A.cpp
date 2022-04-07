# include <iostream>
# include <cstring>

struct student
{
    char name[20];
    unsigned int mean_points;
};

int main()
{
    unsigned int M = 0;
    student *group = new student[10];
    for (int i = 0; i < 10; i++)
    {
        std::cin >> group[i].name >> group[i].mean_points;
    }
    std::cin>> M;
    for (int i = 0; i < 10; i++)
    {
        if (group[i].mean_points >= M)
        {
            std::cout<<group[i].name<< ' ';
        }
    }
     std::cout<<std::endl;
    delete[] group;
    return 0;
}
