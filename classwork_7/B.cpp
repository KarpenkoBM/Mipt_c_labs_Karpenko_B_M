# include <iostream>
# include <cstring>

struct student
{
    char name[20];
    unsigned int mean_points;

 bool operator<(const student& other) const
{
       if ( mean_points < other.mean_points)
       {
           return true;
       }
       if ( mean_points == other.mean_points)
       {
           int i = 0;
             for (i ; name[i] != '\0' and other.name[i] != '\0'; i++)
            {
                if (name[i] > other.name[i])
                {
                    return false;
                }
                if (name[i] < other.name[i])
                {
                    return true;
                }
            }
            if (name[i] != '\0')
            {

                return true;
            }
        }
        return false;
    }
};

void swap(student &a, student &b)
{
    student temp = a;
    a = b;
    b = temp;
}

void quick_sort(student *array, int left, int right)
{
    if (left < right)
    {
        int i = left;
        int j = right;
        student pivot = array[(i + j) / 2];

        while (true)
        {
            while (array[i] < pivot)
            {
                i++;
            }
            while (pivot < array[j])
            {
                j--;
            }
            if (i >= j)
            {
                pivot.mean_points = j;
                break;
            }
            swap(array[i],array[j]);
            i++;
            j++;
        }
        quick_sort(array, left, pivot.mean_points);
        quick_sort(array, pivot.mean_points + 1, right);
}

    }



int main()
{
    unsigned int M = 0, N = 0;
    std::cin>>N;
    student *group = new student[N];
    for (int i = 0; i < N; i++)
    {
        std::cin >> group[i].name >> group[i].mean_points;
    }
    std::cin>> M;
    quick_sort(group, 0 , N-1);
    for (int i = 0; i < N; i++)
    {
        if (group[i].mean_points >= M)
        {
            std::cout<<group[i].name<<' ';
        }
    }
     std::cout<<std::endl;
     delete[] group;
    return 0;
}
