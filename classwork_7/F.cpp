# include <iostream>
# include <cstring>

enum Status
{
    Continue = 100, OK = 200, Created = 201, Accepted = 202,
    Bad_Request = 400,Unauthorized = 401, Not_Found = 404,
    Method_Not_Allowed = 405, Internal_Server_Error = 500,
    Not_Implemented = 501, Bad_Gateway = 502
};
void Status_printing(Status state)
{
    switch (state)
    {
    case Status::Continue:
        std::cout << "Continue" << std::endl;
        break;

    case Status::OK:
        std::cout << "OK" << std::endl;
        break;
    case Status::Created:
        std::cout << "Created" << std::endl;
        break;
    case Status::Accepted:
        std::cout << "Accepted" << std::endl;
        break;
    case Status::Bad_Request:
        std::cout << "Bad Request" << std::endl;
        break;
    case Status::Unauthorized:
        std::cout << "Unauthorized" << std::endl;
        break;
    case Status::Not_Found:
        std::cout << "Not Found" << std::endl;
        break;
    case Status::Method_Not_Allowed:
        std::cout << "Method Not Allowed" << std::endl;
        break;
    case Status::Internal_Server_Error:
        std::cout << "Internal Server Error" << std::endl;
        break;
    case Status::Not_Implemented:
        std::cout << "Not Implemented" << std::endl;
        break;
    case Status::Bad_Gateway:
        std::cout << "Bad Gateway" << std::endl;
        break;
    default:
        std::cout << std::endl;
        break;
    }
}
int main()
{
    int i = 0;
    int arr[20] = {0};
    std::cin >> arr[i];
    while (arr[i] != 0)
    {
        i++;
        std::cin >> arr[i];
    }
    for (int p = 0; p < i; p++)
    {
        Status_printing(static_cast<Status>(arr[p]));
    }
}
