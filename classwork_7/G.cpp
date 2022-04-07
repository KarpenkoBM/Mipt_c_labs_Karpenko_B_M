# include <iostream>
# include <cstring>

struct Atom
{
    std::string name = "OO";
    int mass = 0;
    int charge = 0;
void operator-(const Atom& other)
{
    name = "OO";
    mass = mass - other.mass;
    charge = charge - other.charge;
}
};
Atom name_find(Atom atom,int N, Atom arr[])
{
    for (int i = 0; i < N; i++)
    {
        if (atom.charge == arr[i].charge)
        {
            return arr[i];
        }
    }
    return {"OO", 0, 0};
}
Atom atom_find(Atom atom, int N, Atom arr[])
{
    for (int i =0; i < N; i++)
    {
        if (atom.name == arr[i].name)
        {
            return arr[i];
        }
    }
}
int main()
{
    int N = 0, M = 0 ;
    std::cin>> N;
    Atom *group = new Atom[N];
    std::string type = "OO";
    Atom first = {"OO", 0, 0};
    Atom second = {"OO", 0, 0};
    for (int i =0; i < N; i++)
    {
        std::cin >> group[i].name >> group[i].mass >> group[i].charge;
    }
    std::cin >> M;
    for (int i = 0; i < M; i++)
    {

        std::cin>> first.name >> type;
        first = atom_find(first, N, group);

        if (type == "alpha")
        {
            second.mass = 4;
            second.charge = 2;
        }
        if (type == "beta+")
        {
            second.mass = 0;
            second.charge = 1;
        }
        if (type == "beta-")
        {
            second.mass = 0;
            second.charge = -1;
        }
        first - second;
        first = name_find(first, N, group);
        if (first.name == "OO")
        {
            std::cout <<"NO DATA"<<' ';
        }
        else
        {
             std::cout << first.name<<' ';
        }
    }
    std::cout<<std::endl;
return 0;
}
