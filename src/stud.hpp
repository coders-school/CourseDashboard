 #pragma once
 #include <string>


 class Student
 {
     friend std::ostream &operator << (std::ostream &out, const Student &c);
 protected:
     std::string name {};
     std::string discordName {};
     std::string gitLink{};
     std::string groupName{};
     std::string fireCode{};


 public:
     Student() = default;
     Student(std::string nameVal,
             std::string discordNameVal,
             std::string gitLinkVal,
             std::string groupNameVal,
             std::string fireCodeVal);
     Student(const Student &source) = default;
     void view() const;
     std::string getName()const;
 };

 

