# include <iostream>
# include <cstring>

struct road
{
    int beginning_x;
    int beginning_y;
    int ending_x;
    int ending_y;
    int x_vec = ending_x - beginning_x;
    int y_vec = ending_y - beginning_y;
    bool operator&(const road& other)const
    {
        return ((other.beginning_x - beginning_x)
                * y_vec
                - (other.beginning_y - beginning_y)
                * x_vec == 0 ) or
                ((other.ending_x - beginning_x)
                * y_vec
                - (other.ending_y - beginning_y)
                * x_vec == 0 ) ;
    }
    bool operator%(const road& other)const
    {
        return ((other.beginning_x - beginning_x)
                * y_vec
                - (other.beginning_y - beginning_y)
                * x_vec > 0 ) and
                ((other.ending_x - beginning_x)
                * y_vec
                - (other.ending_y - beginning_y)
                * x_vec < 0 );
    }
    bool operator*(const road& other)const
    {
        return ((other.beginning_x - beginning_x)
                * y_vec
                - (other.beginning_y - beginning_y)
                * x_vec < 0 ) and
                ((other.ending_x - beginning_x)
                * y_vec
                - (other.ending_y - beginning_y)
                * x_vec > 0 );
    }
    bool operator^( const road& other) const
    {
        road main = {beginning_x, beginning_y, ending_x, ending_y };
        if (main.x_vec * other.y_vec - main.y_vec * other.x_vec != 0)
        {
            //std::cout<<"a";
            if ((main % other or main * other
            or main & other) and(other % main or other * main
            or other & main ))
            {
                return true;
            }
            return false;
        }
        else
        {
            if(other.beginning_x < main.beginning_x
               and main.beginning_x < other.ending_x
               or other.beginning_x < main.ending_x
               and main.ending_x < other.ending_x
               or other.beginning_x > main.beginning_x
               and main.beginning_x > other.ending_x
               or other.beginning_x > main.ending_x  and main.ending_x > other.ending_x
               or main.beginning_x == other.beginning_x
               or main.beginning_x == other.ending_x
               or main.ending_x == other.beginning_x
               or main.ending_x == other.ending_x)
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
    }
};
int main ()
{
    road first = {0, 0, 0, 0};
    road second = {0, 0, 0, 0};
    std::cin>> first.beginning_x >> first.beginning_y
    >> first.ending_x >> first.ending_y >> second.beginning_x
     >> second.beginning_y >> second.ending_x >> second.ending_y;
     first.x_vec = first.ending_x - first.beginning_x;
     first.y_vec = first.ending_y - first.beginning_y;
     second.x_vec = second.ending_x - second.beginning_x;
     second.y_vec = second.ending_y - second.beginning_y;
    if (first ^ second)
    {
        std::cout<<"NO"<<std::endl;
    }
    else
    {
        std::cout <<"YES"<<std::endl;
    }
    return 0;
}

