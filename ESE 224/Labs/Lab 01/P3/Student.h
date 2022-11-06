#pragma

class Student
{
private:
    std::string name;
    std::string id;
    std::string major;
    std::string email;

public:
    Student();
    Student(std::string initName, std::string initID, std::string initMajor, std::string initEmail);
    std::string getName();
    std::string getID();
    std::string getMajor();
    std::string getEmail();
    void setName(std::string newName);
    void setID(std::string newID);
    void setMajor(std::string newMajor);
    void setEmail(std::string newEmail);
    void printInfo();
};
