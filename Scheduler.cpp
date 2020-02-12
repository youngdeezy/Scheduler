#include "Scheduler.h"

Scheduler::Scheduler()
{

    m_name = " ";
    m_fileName = " ";
}

Scheduler::Scheduler(string fileName)
{

    cout << "What semester?" << endl;
    cin >> m_name;
    m_fileName = fileName;
}

Scheduler::~Scheduler()
{

    m_classes.clear();
}

void Scheduler::LoadFile()
{

    //values set for the foundables

    //string line;

    string first;
    string last;
    string ID;
    string course;

    int counter = 0;
    ifstream myFile(m_fileName);
    bool check = false;
    int num = 0;

    //Room *tempRoom;

    //cout << "Hello" << endl;

    //goes across each line and sets the values for the DecayList that is set apart by semicolon
    while (myFile)
    {

        getline(myFile, first, ',');
        //int idNum = atoi(ID.c_str());
        getline(myFile, last, ',');
        getline(myFile, ID, ',');
        int idNum = atoi(ID.c_str());
        getline(myFile, course);


        Student *tempStudent = new Student(first, last, idNum);
        AddStudent(tempStudent, course);
        /*
        if (myFile.eof())
        {
            break;
        } 

        //Class *tempClass = new Class(course, counter);
        Student *tempStudent = new Student(first, last, idNum);

        for (unsigned int i = 0; i < m_classes.size(); i++)
        {

            if (course == m_classes.at(i)->GetName())
            {
                check = true;
                num = i;
            }
        }
        // for
        // if tempClass = m_classes.at(i)
        // then m_classes.at(i)->AddStduent(tempStudent)
        // else
        //tempClass->AddStudent(tempStudent);
        //m_classes.push_back(tempClass);

        //counter++;

        //class is open
        if (check == true)
        {

            m_classes.at(num)->AddStudent(tempStudent);
        }
        else if (check == true && m_classes.at(num)->IsRosterFull() == true && m_classes.at(num)->IsWaitlistFull() == true)
        {

            int section = m_classes.at(num)->GetSection();

            Class *tempClass = new Class(course, section + 1);

            m_classes.at(num)->TransferWaitToRoster(*tempClass);

            //Student *tempStudent = new Student(first, last, idNum);

            tempClass->AddStudent(tempStudent);

            m_classes.push_back(tempClass);
        }
        else
        {

            Class *tempClass = new Class(course, 1);
            //Student *tempStudent = new Student(first, last, idNum);
            tempClass->AddStudent(tempStudent);
            m_classes.push_back(tempClass);
        }
        //delte this after
        */
    }
    //delete tempRoom;
    myFile.close();
}

//menu
void Scheduler::MainMenu()
{

    int inputNum;

    cout << "Menu" << endl;
    cout << "1. Display all courses" << endl;
    cout << "2. Display specific course" << endl;
    cout << "3. Search for specific student " << endl;
    cout << "4. Sort Roster " << endl;
    cout << "5. Quit" << endl;
    cin >> inputNum;

    switch (inputNum)
    {
    case 1:
        DisplayCourses();
        break;
    case 2:
        DisplaySpecific();
        break;
    case 3:
        SearchStudent();
        break;
    case 4:
        SortRoster();
        break;
    case 5:
        cout << "Exiting" << endl;
        exit(0);
        break;
    }
}

void Scheduler::DisplayCourses()
{

    for (auto i : m_classes)
    {
        cout << "Course: " << i->GetName();
        cout << " Section: " << i->GetSection() << endl;
        ;
    }
}

void Scheduler::DisplaySpecific()
{

    int inputNum;
    cout << " Which course would you like to display?" << endl;
    for (unsigned int i = 0; i < m_classes.size(); i++)
    {
        cout << i + 1 << ". " << m_classes.at(i) << endl;
    }

    cin >> inputNum;
    cout << m_classes.at(inputNum);
    m_classes.at(inputNum)->DisplayStudents();

    /*
    string className;
    cout << "Enter course" << endl;
    cin >> className;

    for (unsigned int i = 0; i < m_classes.size(); i++)
    {
        if (className == m_classes.at(i)->GetName())
        {

            m_classes.at(i)->DisplayStudents();
        }
    }
    /*
    
    for
    if className == m_classes.at(i) 
    then print out

    */
}

void Scheduler::SearchStudent()
{

    string name;
    cout << "What name do you want to search for? " << endl;
    cin >> name;

    cout << "Items with " << name << " in them: " << endl;
    for (unsigned int i = 0; i < m_classes.size(); i++)
    {

        if (m_classes.at(i)->SearchClass(name) == true)
        {
            cout << m_classes.at(i) << endl;
        }
        /*
        for(int i = 0; i < m_classes.at(i)->)
        if(m_classes.at(i)->)
        Tqueue<Student*, ROSTER_MAX> temp;
        Tqueue<Student*, WAIT_MAX> tempWait ;
        tempWait.
        //temp->
        m_classes.at(i)->
        cout << m_classes.at(i) << endl;
        for(int i = 0; i < ROSTER_MAX; i++){

        }
        for(int i = 0; i < WAIT_MAX; i++){
            m_classes.at(i)->
        } */
    }
}

void Scheduler::SortRoster()
{

    for (unsigned int i = 0; i < m_classes.size(); i++)
    {
        m_classes.at(i)->SortStudents();
    }
    /*
    string name;
    cout << "Enter student name" << endl;
    cin >> name;

    for (unsigned int i = 0; i < m_classes.size(); i++)
    {
        if (name == m_classes.at(i)->GetName())
        {

            m_classes.at(i)->DisplayStudents();
            m_classes.at(i)[2];
            m_classes.at(i)->SortStudents();
        }
    } */
}

void Scheduler::Start()
{

    cout << "Hello" << endl;
    LoadFile();
    MainMenu();
}

int Scheduler::FindClass(string name)
{

    for (unsigned int i = 0; i < m_classes.size(); i++)
    {
        if (m_classes.at(i)->GetName == name)
        {

            return m_classes.at(i)->GetSection();
        }
    }
}

void Scheduler::AddStudent(Student *s, string className)
{

    // s.pop
    // s.pop
    // findName(name)
    // then s.pop
    // else
    //return

    //1.
    //int section = 1;
    //Class *tempClass = new Class(className, 1);
    if(m_classes.empty()){
            Class *tempClass = new Class(className, 1);
            tempClass->AddStudent(s);
            m_classes.push_back(tempClass);
            
            
    }

    for (unsigned int i = 0; i < m_classes.size(); i++)
    {
        //class and waitlist is full
        if (m_classes.at(i)->GetName() == className && m_classes.at(i)->IsRosterFull == true && m_classes.at(i)->IsWaitlistFull == true)
        {
            int section = m_classes.at(i)->GetSection();
            Class *tempClass = new Class(className, section + 1);
            m_classes.at(i)->TransferWaitToRoster(*tempClass);
            m_classes.push_back(tempClass);
            m_classes.at(i)->AddStudent(s);
        }

        //class and waitlist open
        else if (m_classes.at(i)->GetName() == className && m_classes.at(i)->IsRosterFull == false && m_classes.at(i)->IsWaitlistFull == false)
        {

            int section = m_classes.at(i)->GetSection();
            m_classes.at(i)->AddStudent(s);
            //Class *tempClass = new Class(className, section);
        }

        //class is full, waitlist open
        else if (m_classes.at(i)->GetName() == className && m_classes.at(i)->IsRosterFull == true && m_classes.at(i)->IsWaitlistFull == false)
        {

            int section = m_classes.at(i)->GetSection();
            m_classes.at(i)->AddStudent(s);
            //Class *tempClass = new Class(className, section);
        }

        //new class is made
        else
        {
            Class *tempClass = new Class(className, 1);
            m_classes.push_back(tempClass);
        }
    }
}