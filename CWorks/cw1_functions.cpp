#include "input.h"
#include "filefunctions_cw1.h"
#include <algorithm>

bool AllocateArray(Client* clients , int amount)  // checking the possibility of adding a client
{
    if (amount == 0)
    {
        std::cout << "Ошибка выделения памяти: нельзя выделять память для 0 элементов" << std::endl;
        return false;
    }

    try
    {
        clients = new Client[amount];
    }
    catch (const std::bad_alloc& error)
    {
        std::cout
            << "Ошибка выделения памяти: " << error.what() << std::endl
            << "Попробуйте изменить количество клиентов" << std::endl;
        return false;
    }
    return true;
}

void ShowClients(Client* clients, int amount)
{
    int client_id = 1;
    for (int i = 0; i < amount; i++, client_id++)
    {
        std::cout << "ID " << client_id;
        clients[i].ShowClient();
    }
}

void FillClients(Client* clients, int amount)
{
    std::cout << std::endl;
    int client_id = 1;
    for (int i = 0; i < amount; i++, client_id++) 
    {
        if (!clients[i].IsEmpty())
            continue;
        std::cout << "Заполните информацию о клиенте # " << client_id << "." << std::endl;
        clients[i].SetName();
        clients[i].SetAddress();
        clients[i].SetContact();
        std::cout << std::endl;
    }
}

void SearchByAlph(Client* clients, int amount)
{
    Client temp{};

    Name Name1{}, Name2{};
    std::string fullName1{}, fullName2{};

    for (int i = 0; i < amount; i++)
        for (int j = 0; j < amount - 1; j++)
        {
            Name1 = clients[j].GetName();
            Name2 = clients[j + 1].GetName();

            fullName1 = Name1.first_name + Name1.last_name + Name1.patronymic;
            fullName2 = Name2.first_name + Name2.last_name + Name2.patronymic;

            if (fullName1 > fullName2)
            {
                temp = clients[j];
                clients[j] = clients[j + 1];
                clients[j + 1] = temp;
            }
        }
    ShowClients(clients, amount);
}

void GetCardRange(long long& upBound, long long& lowBound)
{
    bool isCorrectRange{};
    do
    {
        std::cout << "Введите нижнюю границу." << std::endl;
        lowBound = GetPosLongLong();
        
        std::cout << "Введите верхнюю границу." << std::endl;
        upBound = GetPosLongLong();

        std::cout << std::endl;
        if (lowBound > upBound)
        {
            std::cout << "Нижняя граница не должна быть больше верхней!" << std::endl;
            continue;
        }
        else
            isCorrectRange = true;
    } 
    while (!isCorrectRange);
    std::cout << std::endl;
}

bool IsCardInRange(Client current, long long upBound, long long lowBound)
{
    Contact ClientContact = current.GetContact();
    if ((lowBound <= ClientContact.card_num) && (ClientContact.card_num <= upBound))
        return true;
    else
        return false;
}

void SearchByCardRange(Client* clients, int amount)
{
    long long upBound{}, lowBound{};
    GetCardRange(upBound, lowBound);
    int client_id = 1, counter = 0;
    bool isThereAtLeastOne = false;
    std::cout << "Клиенты, номер карты которых находится в интервале от " << lowBound << " до " << upBound << std::endl;
    for (int i = 0; i < amount; i++, client_id++)
    {
        if (IsCardInRange(clients[i], upBound, lowBound))
        {
            isThereAtLeastOne = true;
            std::cout << "ID " << client_id;
            clients[i].ShowClient();
            counter++;
            std::cout << std::endl;
        }
    }
    if (!isThereAtLeastOne)
        std::cout << "клиентов в заданном диапазоне нет" << std::endl;
    if (isThereAtLeastOne)
    {
        std::cout << "Записать результат в файл?" << std::endl;
        std::cout << "1 - Да, 2 - Нет. ESC - выход из программы." << std::endl;
        int user_choice = GetKey(YES, NO);
        if (user_choice == YES)
        {
            Client* listToSave = new Client[counter];

            for (int i = 0, j = 0; i < amount && j < counter; i++)
                if (IsCardInRange(clients[i], upBound, lowBound))
                {
                    listToSave[j] = clients[i];
                    j++;
                }
            SaveToFile(listToSave, counter);

            delete[] listToSave;
            listToSave = nullptr;
        }
        else if (user_choice == QUIT)
            exit(EXIT_SUCCESS);
    }
}

bool IsListEmpty(Client* clients, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        if (!clients[i].IsEmpty())
            return false;
    }
    return true;
}

Client* AllocMore(Client *clients, int& amount)
{
    int add{};
    int new_amount{};
    Client* new_clients = nullptr;
    do
    {
        std::cout << "Введите, сколько клиентов добавить: " << std::endl;
        add = GetPosInt();
        new_amount = (amount + add);
        if (new_amount > INT_MAX)
        {
            std::cout << "Произошла ошибка, попробуйте изменить количество добавляемых клиентов." << std::endl;
            continue;
        }
        if (AllocateArray(clients, new_amount))
        {
            new_clients = new Client[new_amount];
            std::copy(clients, clients + amount, new_clients);
        }
        else
            std::cout << "Произошла ошибка, попробуйте изменить количество добавляемых клиентов." << std::endl;
    }
    while (!AllocateArray(clients, new_amount));

    amount = new_amount;
    delete[] clients;
    clients = nullptr;

    return new_clients;
}

bool IsListFull(Client *clients, int amount)
{
    for (int i = 0; i < amount; i++)
    {
        if (!clients[i].IsEmpty())
            continue;
        else
            return false;
    }
    return true;
}

void AddNewClient(Client *clients, int amount)
{
    if (!IsListFull(clients, amount))
        for (int i = 0; i < amount; i++)
            FillClients(clients, amount);
    else
        std::cout << "Список переполнен!" << std::endl;
}
