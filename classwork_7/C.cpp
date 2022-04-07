# include <iostream>
# include <cstring>

struct time
{
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;

    time operator+( const time& other) const
    {
        time summ = {0, 0, 0};
        summ.seconds = other.seconds + seconds;
        summ.minutes = other.minutes + minutes;
        summ.hours = other.hours + hours;
        if (summ.seconds > 59)
        {
            summ.seconds -= 60;
            summ.minutes += 1;
        }
        if (summ.minutes > 59)
        {
            summ.minutes -= 60;
            summ.hours += 1;
        }
        if (summ.hours > 23)
        {
            summ.hours -= 24;
        }


        return summ;
    }
};
int main ()
{
    time real_time = {0, 0, 0};
    time break_time = {0, 0, 0};
    std:: cin >> real_time.hours >> real_time.minutes
    >> real_time.seconds >> break_time.hours
    >> break_time.minutes >> break_time.seconds;
    time summ = real_time + break_time;
    std:: cout << summ.hours << ':'<< summ.minutes <<':'<< summ.seconds << std::endl;
    return 0;
}
