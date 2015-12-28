#ifndef EMPLOYEE
#define EMPLYOEE

#include <string>

//employee data shouldn't be copied in to other's, so we delete the copy-constructor and assign operator
//if we can copy data then we must define our own to avoid copying over the unique ID

class Employee{
    static unsigned IDNo;
public:
    Employee() { }
    Employee(const std::string& s): name(s) { }
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;
private:
    unsigned id = IDNo++;
    std::string name;
};

unsigned Employee::IDNo = 0;

#endif // EMPLOYEE
