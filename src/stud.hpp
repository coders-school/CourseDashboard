 #pragma once
 #include <string>


 class Student
 {
 protected:
     std::string name {};
     std::string discordName {};
     std::string gitLink{};
     std::string groupName{};

 
 public:
     Student()=default;
     Student (std::string nameVal, std::string discordNameVal, std::string gitLinkVal, std::string groupNameVal);
     Student (const Student &source)=default;
     void view() const;
 };

 

