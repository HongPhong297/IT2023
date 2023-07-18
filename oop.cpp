#include <iostream>
using std::string;
class AbstractEmployee
{
    virtual void Askforpromotion() = 0;
};
class Employee : AbstractEmployee
{
private:
    // string Name;
    string Company;
    int Age;

protected:
    string Name;

public:
    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }
    void setCompany(string company)
    {
        Company = company;
    }
    string getCompany()
    {
        return Company;
    }
    void setAge(int age)
    {
        Age = age;
    }
    int getAge()
    {
        return Age;
    }
    void Introduce()
    {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
    void Askforpromotion()
    {
        if (Age > 30)
            std::cout << Name << " got promoted" << std::endl;
        else
            std::cout << Name << ", sorry No promotion for you..." << std::endl;
    }
    virtual void Work()
    {
        std::cout << Name << " is checking email...." << std::endl;
    }
};
class Deverloper : public Employee
{
public:
    string FavProgramingLanguege;
    Deverloper(string name, string company, int age, string favProgramingLanguege)
        : Employee(name, company, age)
    {
        FavProgramingLanguege = favProgramingLanguege;
    }
    void Fixbug()
    {
        std::cout << Name << " fixed bug using " << FavProgramingLanguege << std::endl;
    } // Name = getName() ;
    void Work()
    {
        std::cout << Name << " is writting " << FavProgramingLanguege << std::endl;
    }
};
int main()
{
    // Employee 1 shift alt F
    Employee employee1 = Employee("Phong", "FPT", 19);
    // Employee 2
    Employee employee2 = Employee("John", "Viettel", 35);
    employee1.Introduce();
    // employee2.Introduce();
    employee1.Askforpromotion();
    // employee2.Askforpromotion();
    Deverloper d = Deverloper("Javer", "Vinhomes", 27, "C++");
    d.Introduce();
    d.Askforpromotion();
    d.Fixbug();
    d.Work();
    Employee *t = &d;
    t->Work();
    return 0;
}
