// includes
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>

// function prototypes
void string_manipulation();
void vector_manipulation();
void list_manipulation();
void vector_manipulation2();
void queue_manipulation();

void show_vector(std::vector<int> &v1, std::vector<int> &v2);
void show_vector2(std::vector<std::string> &v1, std::vector<std::string> &v2);
void show_list(std::list<double> & l1, std::list<double> & l2);

int main()
{
   // call string function
   std::cout << "_____________________________________________________________strings\n\n";
   string_manipulation();

   // call vector function
   std::cout << "_____________________________________________________________vectors\n\n";
   vector_manipulation();

   // call list function
   std::cout << "_____________________________________________________________lists\n";
   list_manipulation();

   // call vector2 function
   std::cout << "_____________________________________________________________vectors\n";
   vector_manipulation2();

   // call queue function
   std::cout << "_____________________________________________________________queues\n";
   queue_manipulation();

   return 0;
}

void string_manipulation()
{
   //-------------------------------------------------------------------------------------------string
   // initialize string objects
   std::string user_name{"Julian de Kievid"};
   std::string password = "someThing";

   // display strings
   std::cout << "user_name: \t" << user_name << '\n' << "password: \t" << password << "\n\n";

   // insert characters to both strings
   user_name.insert(0, "->");
   user_name.insert(16, "<-");
   password.insert(0, "->");
   password.insert(11, "<-");
   std::cout << "After modifying the strings we get: " << '\n'
             << "user_name: \t" << user_name << '\n' << "password: \t" << password << "\n\n";

   // adapt content of both strings by assigning and erasing characters
   user_name.assign(password, 0, 8);   // assign from place 0 to 8
   password.erase(2, 4);   // erase from place 2 for a lenght of 4 characters
   std::cout << "After adapting the content of the strings we get:  " << '\n'
             << "user_name: \t" << user_name << '\n' << "password: \t" << password << "\n\n";

   // compare strings
   int compare_value = password.compare(user_name);
   if( compare_value != 0)
   {
      std::cout << "Strings aren't equal\n" << compare_value << "\n\n";
   }
   else
   {
      std::cout << "Strings are equal\n" << compare_value << "\n\n";
   }

   // copy strings
   password = user_name;
   std::cout << "After copying the strings we get are:  " << '\n'
             << "user_name: \t" << user_name << '\n' << "password: \t" << password << "\n\n";

   // compare strings
   compare_value = password.compare(user_name);
   if( compare_value != 0)
   {
      std::cout << "strings aren't equal\n" << compare_value << "\n\n";
   }
   else
   {
      std::cout << "strings are equal\n" << compare_value << "\n\n";
   }

   // remove both strings
   user_name.clear();
   password.clear();
   std::cout << "After removing both strings we get:  " << '\n'
             << "user_name: \t" << user_name << '\n' << "password: \t" << password << '\n';
}

void vector_manipulation()
{
   std::vector<int> v1{{0, 1, 2, 3, 4}};
   std::vector<int> v2 = {5, 6, 7, 8, 9};

   // show initial vectors
   show_vector(v1, v2);

   // change content of vectors
   std::cout << "\nChanging content of both vectors gives us: \n";
   v1.assign (5, 1);    // Assign = delete old values and write five 1's
   v2.push_back (0);
   show_vector(v1, v2);

   // compare
   std::cout << "\nComparing vectors gives us: \n";
   if (v1 == v2)
   {
      std::cout << "vector v1 is equal to vector v2\n";
   }
   else {
      std::cout << "vector v1 is not equal to vector v2\n";
   }

   // copy
   std::cout << "\nCopying vectors gives us: \n";
   v1 = v2;
   show_vector(v1, v2);

   // compare
   std::cout << "\nComparing vectors gives us: \n";
   if (v1 == v2)
   {
      std::cout << "vector v1 is equal to vector v2\n";
   }
   else {
      std::cout << "vector v1 is not equal to vector v2\n";
   }

   // remove
   std::cout << "\nRemove vectors gives us: \n";
   v1.clear();
   v2.clear();
   show_vector(v1, v2);
}

void list_manipulation()
{
   std::list<double> list1 = {0, 1, 2, 3};
   std::list<double> list2 = {4, 5, 6, 7};
   show_list(list1, list2);

   std::cout << "\nCompare the lists: ";
   if(list1 == list2)
   {
      std::cout << "\nLists are the same\n";
   }else{std::cout << "\nLists are not the same\n";}

   std::cout << "\nChanging content of both lists gives: ";
   list1.pop_back();
   list1.push_back(0);
   list2.pop_back();
   list2.push_back(0);
   show_list(list1, list2);

   std::cout << "\nRemoving content of both lists and push zeroes at the back of them gives: ";
   list1.clear();
   list2.clear();
   list1.push_back(0);
   list2.push_back(0);
   show_list(list1, list2);

   std::cout << "\nCompare the lists: ";
   if(list1 == list2)
   {
      std::cout << "\nLists are the same\n";
   }else{std::cout << "\nLists are the same\n";}
}

void vector_manipulation2()
{
   std::vector<std::string> vdata1;
   std::vector<std::string> vdata2{"start ", "setspeed 2 ", "stop "};
   vdata1 = vdata2;
   std::cout << "Size of vdata1: " << vdata1.size() << '\n';
   std::cout << vdata1[1] << '\n';
   show_vector2(vdata1, vdata2);
   vdata2.push_back("STOP!!");
   printf("\nPushed 'STOP!!' at the back of the vector\n");
   show_vector2(vdata1, vdata2);
   vdata2.pop_back();
   printf("\nPopped vdata2\n");
   show_vector2(vdata1, vdata2);
   if (!vdata1.empty()) {
      std::cout << "The first character of vdata1 is: " << vdata1.front() << '\n';
   }
   vdata1.clear();
   std::cout << "\nAfter clearing vdata1: \n";
   if (!vdata1.empty()) {
      std::cout << "The first character of vdata1 is: " << vdata1.front() << '\n';
   }else { std::cout << "No characters in vdata1" << '\n';}
}

void queue_manipulation()
{
   std::queue<int> queue1;
   queue1.push(1);
   queue1.push(2);
   queue1.push(3);

   std::cout << "content of queue usergroup1:\n";

   while (!queue1.empty())
   {
     std::cout << queue1.front();
     queue1.pop();
   }

   std::cout << "\n\npushing queue using a range based for loop: \n";
   for (auto i : {4, 5, 6}) queue1.push(i);

   while (!queue1.empty())
   {
     std::cout << queue1.front();
     queue1.pop();
   }
   std::cout << '\n';
}

void show_vector(std::vector<int> & v1, std::vector<int> & v2)
{
   std::cout << "vector 1: ";
   for(auto e: v1)
   {
      std::cout << e;
   }
   std::cout << '\n';
   std::cout << "vector 2: ";
   for(auto e: v2)
   {
      std::cout << e;
   }
   std::cout << '\n';
}

void show_vector2(std::vector<std::string> & v1, std::vector<std::string> & v2)
{
   std::cout << "vector 1: ";
   for(auto e: v1)
   {
      std::cout << e;
   }
   std::cout << '\n';
   std::cout << "vector 2: ";
   for(auto e: v2)
   {
      std::cout << e;
   }
   std::cout << '\n';
}

void show_list(std::list<double> &l1, std::list<double> & l2)
{
   std::cout << "\nlist 1: ";
   for(auto e: l1)
   {
      std::cout << e;
   }
   std::cout << '\n';
   std::cout << "list 2: ";
   for(auto e: l2)
   {
      std::cout << e;
   }
   std::cout << '\n';
}

