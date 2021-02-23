#include <iostream>      
#include <thread>       
using namespace std;

void foo(int &p1) 
{
  for(int i = 0;i < 10000;i++)
     p1++;  
}

void bar(int &p2)
{
  for(int i = 0;i < 20000;i++)
     p2++;
}

int main() 
{
  int p1 = 0, p2 = 0;
  thread first(foo, ref(p1));    
  thread second(bar, ref(p2));  

  cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  cout << "foo and bar completed.\n";
  cout << p1+p2 << endl;
  
  return 0;
}
