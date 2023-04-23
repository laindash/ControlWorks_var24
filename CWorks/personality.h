#ifndef PERSONALITY_H
#define PERSONALITY_H
#include <iostream>
#include <string>
#include <vector>

struct AddressCW2
{
    std::string city{}, street{}, appart{}, flat{};
};

class Personality
{
protected:
    std::string _surname{}, _gender{};
    AddressCW2 _address{};

public:
    virtual void Show() const;
    void SetSurname();
    void SetSurnameFromFile(std::istream& input);
    void SetGender();
    void SetGenderFromFile(std::istream& input);
    void SetAddress();
    void SetAddressFromFile(std::istream& input);
    std::string GetSurname();
    std::string GetGender();
    AddressCW2 GetAddress();
    void Delete(std::vector<Personality*>& personalities, int id);
    virtual ~Personality() = default;
};

#endif
