#ifndef PERSON
#define PERSON

class Person{
    friend istream& read(istream& is, Person& record);
    friend ostream& print(ostream& os, const Person& record);
public:
    Person() = default;
    Person(const string& a, const string& b): name(a), address(b) { }
    explicit Person(istream&);

    string returnName() const { return name; }
    string returnAddress() const {return address; }
private:
    string name;
    string address;



};

istream& read(istream& is, Person& record){

    is >> record.name >> record.address;
    return is;

}

ostream& print(ostream& os, const Person& record){

    os << record.name << " " << record.address;
    return os;

}

Person::Person(istream& is){

    read(is, *this);

}

#endif // PERSON
