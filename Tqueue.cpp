#ifndef TQUEUE_CPP
#define TQUEUE_CPP

#include <iostream>
#include <cstdlib>
using namespace std;

template <class T, int N>
class Tqueue
{
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue(const Tqueue<T, N> &x); //Copy Constructor
  //Name: Destructor
  //Desc: Empties m_data
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: ClearData
  //Desc: Empties m_data
  //Precondition: Existing Tqueue
  //Postcondition: Empty m_data
  void ClearData();
  //Name: Enqueue
  //Desc: Adds item to the back of queue
  //Precondition: Existing Tqueue
  //Postcondition: Returns true if successful else false
  void Enqueue(T data); //Adds item to queue (to back)
  //Name: Dequeue
  //Desc: Removes item from queue (from front)
  //Precondition: Existing Tqueue
  //Postcondition: Returns true if successful else false
  void Dequeue();
  //Name: Sort
  //Desc: Sorts the contents of the Tqueue
  //NOTE: You may implement to only deal with dereferenced pointers
  //Precondition: Existing Tqueue
  //Postcondition: Contents of Tqueue is sorted (ascending)
  void Sort();
  //Name: IsEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int IsEmpty(); //Returns 1 if queue is empty else 0
  //Name: IsFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int IsFull(); //Returns 1 if queue is full else 0
  //Name: Size
  //Desc: Returns size of queue
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue
  int Size();
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T, N> &operator=(Tqueue<T, N> y); //Overloaded assignment operator for queue
  //Name: Overloaded [] operator
  //Precondition: Existing Tqueue
  //Postcondition: Returns object from Tqueue using []
  T &operator[](int x); //Overloaded [] operator to pull data from queue
private:
  T *m_data;   //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back;  //Back of the queue
};

//**** Add class definition below ****

template <class T, int N>
Tqueue<T, N>::Tqueue()
{
  m_front = 0;
  m_back = 0;
  //m_data = NULL;
  m_data = new T[];
 
}

template <class T, int N>
Tqueue<T, N>::Tqueue(const Tqueue<T, N> &x)
{


    int num = x<N>;
    //delete [] m_data;
    m_data = new T[num]
    m_back = x.m_back;
  //m_data = x.m_data;
  m_front = x.m_front;
    
    for(int i = 0, i < num; i++){
      m_data[i] = x.m_data[i];
    }
    
  
  //m_back = x.m_back;
  //m_data = x.m_data;
  //m_front = x.m_front;

  //return *this;
}

template <class T, int N>
Tqueue<T, N>::~Tqueue()
{

  delete[] m_data;
}

//add to back
template <class T, int N>
void Tqueue<T, N>::Enqueue(T data)
{

  if (IsFull() == 1)
  {
    return;
  }

  else
  {
    m_data[m_back] = data;
    m_back++;
    return;
  }
}

template <class T, int N>
void Tqueue<T, N>::ClearData()
{
}

//remove from front
template <class T, int N>
void Tqueue<T, N>::Dequeue()
{

  if (IsEmpty() == 1)
  {
    return;
  }

  else
  {
    for (int i = 0; i < m_back - 1; i++)
    {
      m_data[i] = m_data[i + 1];
    }
    m_back--;
  }

  return;
}

template <class T, int N>
void Tqueue<T, N>::Sort()
{

  if (IsEmpty() == 1)
  {
    return;
  }

  T temp = m_data[m_front];
  Sort();
  Enqueue(temp);

}

template <class T, int N>
int Tqueue<T, N>::IsEmpty()
{

  if (m_front == m_back)
  {

    return 1;
  }

  else
  {
    return 0;
  }
}

template <class T, int N>
int Tqueue<T, N>::IsFull()
{

  if (N == m_back)
  {

    return 1;
  }

  else
  {
    return 0;
  }
}

template <class T, int N>
int Tqueue<T, N>::Size()
{

  return N;
}


template <class T, int N> 
Tqueue<T, N> &Tqueue<T, N> ::operator=(const Tqueue<T, N> y){

 //if
  return y;

} 

template <class T, int N>
T& Tqueue<T,N> ::operator[](int x){

return m_data[x];

} 

//T &operator[](int x);                                                                                                                                                                                                      
// To test just Lqueue follow these instructions:                                                                                                                                                           
//   1.  Uncomment out int main below                                                                                                                                                                       
//   2.  make Tqueue                                                                                                                                                                                        
//   3.  ./Tqueue (try valgrind too!)                                                                                                                                                                       
                                                                                                                                                                                                            
                                                                                                                                                                                                            
int main () {                                                                                                                                                                                               
  //Test 1 - Default Constructor and Push                                                                                                                                                                   
  cout << "Test 1 - Default Constructor and Push Running" << endl;                                                                                                                                          
  //Test Default Constructor                                                                                                                                                                                
  Tqueue <int, 10> newTQ1;                                                                                                                                                                                  
  //Push 4 nodes into Lqueue                                                                                                                                                                                
  newTQ1.Enqueue(10);                                                                                                                                                                                       
  newTQ1.Enqueue(20);                                                                                                                                                                                       
  newTQ1.Enqueue(30);                                                                                                                                                                                       
  cout << endl;                                                                                                                                                                                             
                                                                                                                                                                                                            
  //Test 2 - Copy Constructor and Assignment Operator                                                                                                                                                       
  cout << "Test 2 - Copy Constructor and Assignment Operator Running" << endl;                                                                                                                              
  //Test Copy constructor                                                                                                                                                                                   
  Tqueue <int, 10> newTQ2(newTQ1);                                                                                                                                                                          
  //Test Overloaded Assignment Operator                                                                                                                                                                     
  Tqueue <int, 10> newTQ3;                                                                                                                                                                                  
  newTQ3 = newTQ1;                                                                                                                                                                                          
  cout << endl;                                                                                                                                                                                             
                                                                                                                                                                                                            
  //Test 3 - Test Dequeue                                                                                                                                                                                   
  cout << "Test 3 - Dequeue" << endl;                                                                                                                                                                       
  cout << newTQ1.Dequeue() << endl;                                                                                                                                                                         
  cout << endl;                                                                                                                                                                                             
                                                                                                                                                                                                            
  //Test 4 - Test Overloaded []                                                                                                                                                                             
  cout << "Test 4 - Test Overloaded []" << endl;                                                                                                                                                            
  for(int i = 0; i < newTQ1.Size(); i++){                                                                                                                                                                   
    cout << newTQ1[i] << endl;    
      }                                                                                                                                                                                                         
                                                                                                                                                                                                            
  //Test 5 - Test Size and ClearData                                                                                                                                                                        
  cout << "Test 5 - Size and ClearData" << endl;                                                                                                                                                            
  //Test GetSize()                                                                                                                                                                                          
  cout << "Outputting the size" << endl;                                                                                                                                                                    
  cout << newTQ1.Size() << endl;                                                                                                                                                                            
  //Test Clear()                                                                                                                                                                                            
  cout << "Clearing all nodes" << endl;                                                                                                                                                                     
  newTQ1.ClearData();                                                                                                                                                                                       
  cout << "Outputting the size" << endl;                                                                                                                                                                    
  cout << newTQ1.Size() << endl;                                                                                                                                                                            
  cout << endl;                                                                                                                                                                                             
                                                                                                                                                                                                            
  return 0;                                                                                                                                                                                                 
}                                                                                                                                                                                                      

#endif
