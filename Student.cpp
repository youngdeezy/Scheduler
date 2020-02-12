#include "Student.h"

Student::Student(){
    m_fName = " ";
    m_lName = " ";
    m_id = 0;
}

Student::Student(string fName, string lName, int id){
    m_fName = fName;
    m_lName = lName;
    m_id = id;
}

string Student::GetFName(){
    return m_fName;
}

string Student::GetLName(){
    return m_lName;
}

int Student::GetID(){
    return m_id;
}

void Student::SetFName(string fName){
      m_fName = fName;
}
void Student::SetLName(string lName){
      m_lName = lName;
}
void Student::SetID(int id){
      m_id = id;
}

ostream& operator<< (ostream&out, Student&s1){

    out << s1.GetFName << endl;
    out << s1.GetLName << endl;
    out << s1.GetID << endl;
    return out;
}

bool operator<(const Student &s1, const Student &s2){

//s1.m_lName.compare(s2.m_lName);  

return s1.m_lName < s2.m_lName;
if(s1.m_lName == s2.m_lName){
    return (s1.m_fName < s2.m_fName);
}

}

