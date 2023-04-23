#ifndef UNIVERSITYEMPLOYEE_H
#define UNIVERSITYEMPLOYEE_H
#include "personality.h"

class UniversityEmployee : public Personality
{
private:
    std::string _position{}, _department{}, _responsibilities{};
    double _salary;

public:
    UniversityEmployee
    (std::string position = "не назначена", 
     std::string department = "не назначена", 
     std::string responsibilities = "отсутствуют", 
     double salary = 0.0)
    {
        _position = position;
        _department = department;
        _responsibilities = responsibilities;
        _salary = salary;
    }

    void Show() const override;
    void SetSalary();
    void SetSalaryFromFile(std::istream& input);
    double GetSalary();
    void SetPosition();
    void SetPositionFromFile(std::istream& input);
    std::string GetPosition();
    void SetResponsibilities();
    void SetResponsibilitiesFromFile(std::istream& input);
    std::string GetResponsibilities();
    void SetDepartment();
    void SetDepartmentFromFile(std::istream& input);
    std::string GetDepartment();
    bool IsEmpty();

    ~UniversityEmployee() = default;
};

#endif