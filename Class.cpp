
#include "Student.h"
#include "Tqueue.cpp"
#include "Class.h"

Class::Class(){

    m_name = " ";
    m_section = 0;
}

Class::Class(string name, int section){
    
    m_name = name;
    m_section = section;
}

Class::~Class(){

//delete 

}

void Class::DisplayStudents(){



if(!m_roster.IsEmpty){

for(int i = 0; i < m_roster.Size() ; i++){
    cout << m_roster[i] << endl;
}
cout << "Size: " << m_roster.Size() << endl;

}

if(!m_waitlist.IsEmpty){

for(int i = 0; i < m_waitlist.Size() ; i++){
    cout << m_waitlist[i] << endl;
}

cout << "Size: " << m_waitlist.Size() << endl;

}


}

bool Class::AddStudent(Student* s1){

if(!IsRosterFull()){
    m_roster.Enqueue(s1);
    return true;
}

if(!IsWaitlistFull()){
    m_waitlist.Enqueue(s1);
    return true;
}


    
    return false;

}

void Class::SortStudents(){

m_roster.Sort();
m_waitlist.Sort();

}

string Class::GetName(){

return m_name;

}

void Class::SetName(string name){

m_name = name;

}

int Class::GetSection(){

    return m_section;

}



void Class::SetSection(int section){

    m_section = section;
}

void Class::TransferWaitToRoster(Class& dest){


Tqueue<Student*,WAIT_MAX> tempWait = m_waitlist;

if(IsRosterFull() == true && IsWaitlistFull() == true ){

    for(int i = 0; tempWait.Size(); i++){
    
    dest.m_roster[i] = tempWait[i];
}
    /*
    while(!m_waitlist.IsEmpty()){
        dest.m_roster.Enqueue
    } */
} else {
    return;
}

/*
m_waitlist goes into destination

delete m_waitlist

else 

return

*/

}

bool Class::IsRosterFull(){

    if(m_roster.IsFull() == 1){
        return true;
    }

    return false;

    //return m_roster.IsFull();

}

bool Class::IsWaitlistFull(){

    if(m_waitlist.IsFull() == 1){
        return true;
    }

    return false;
}

bool Class::SearchClass(string item){

Tqueue<Student*,ROSTER_MAX> temp = m_roster;
Tqueue<Student*,WAIT_MAX> tempWait = m_waitlist;

for(int i = 0; temp.Size(); i++){
    if(temp[i]->GetFName() == item || temp[i]->GetLName() == item){
        return true;
    }
}

for(int i = 0; tempWait.Size(); i++){
    if(tempWait[i]->GetFName() == item || tempWait[i]->GetLName() == item){
        return true;
    }
}


return false;
/*


loops from the class
when the name of student it will return true
when m_roster->getName
return true

else return fasle

*/


}

ostream& operator<<(ostream& out,Class& c1){

    out << "Course " << c1.m_name;
    out <<  " Section: " << c1.m_section << endl;

}
