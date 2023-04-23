#ifndef CW1_FUNCTIONS_H
#define CW1_FUNCTIONS_H

#include "clientclass.h"

bool AllocateArray(Client* clients, int amount);
void ShowClients(Client* clients, int amount);
void FillClients(Client* clients, int amount);
void SearchByAlph(Client* clients, int amount);
void GetCardRange(long long& upBound, long long& lowBound);
bool IsCardInRange(Client current, long long upBound, long long lowBound);
void SearchByCardRange(Client* List, int amount);
bool IsListEmpty(Client* clients, int amount);
Client* AllocMore(Client* clients, int& amount);
bool IsListFull(Client* clients, int amount);
void AddNewClient(Client* clients, int amount);

#endif