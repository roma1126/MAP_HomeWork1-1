#include <thread>
#include <iostream>
#include <chrono>
using namespace std::chrono_literals;

void client(unsigned& clients, unsigned& max_clients)
{
    while (max_clients > 0)
    {
        clients++;
        max_clients--;
        //system("cls");
        std::cout << "Осталось обслужить " << max_clients <<" клиента(ов)" << std::endl;
        std::cout << "Клиентов в очереди: " << clients << std::endl;
        std::this_thread::sleep_for(1000ms);

    }
}

void cashier(unsigned& clients, unsigned& max_clients)
{
    while (clients > 0)
    {
        clients--;
        //system("cls");
        std::cout << "Осталось обслужить " << max_clients << " клиента(ов)" << std::endl;
        std::cout << "Клиентов в очереди: " << clients << std::endl;
        std::this_thread::sleep_for(2000ms);

    }
}


int main()
{
    setlocale(LC_ALL, "Rus");

    unsigned max_clients = 0;
    unsigned clients = 0;

    std::cout << "Количество клиентов, которых надо обслужить: ";
    std::cin >> max_clients;
    std::thread t1(client, std::ref(clients), std::ref(max_clients));
    std::thread t2(cashier, std::ref(clients), std::ref(max_clients));
    t1.join();
    t2.join();
}

