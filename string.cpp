#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int
main ()
{
  string s1, s2, s3;
  s1 = "hello world";
  s2.assign (s1, 0, 5);
  cout << "s2: " << s2 << endl;
  //cout << s1 << endl;
  //s1 = "";
  /*
     char a[5];
     strcpy(a, s1.c_str());
     cout << s1[1] << endl;
   */
  string s4;
  s3.assign (s1, 5, s1.size ());
  s4.append (s2);
  s4.append (s3);
  cout << s4 << endl;

  //find index of s3 in s1
  cout << "index of s3 in s1: " << s1.find (s3, 0) << endl;

  //insert
  s4.insert (s4.size (), "!!");
  cout << "insert '!!': " << s4 << endl;

  //length of string
  cout << "string length: " << s4.size () << endl;

  s4.erase(s4.find("!", 0), s4.size());
  cout<< "erase '!': " << s4 << endl;
  
  s4 = s1 + "!!"; 
  
  s4.replace(s4.find("!", 0), s4.size()-1, "!!!");
  cout << "replace '!!' to '!!!': " << s4 << endl;

  return 0;
}
