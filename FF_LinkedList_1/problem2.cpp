#include <iostream>
#include <string>
using namespace std;

struct toys{
  string name;
  int price;
  toys *next;
};

void addNodeTail(toys *&head, const string &name, int price){
  toys* newToy = new toys; //allocate new memory
  newToy->name = name;
  newToy->price = price;
  newToy->next = nullptr;

  if (!head) { //if the list happens to be empty, we make a new head
    head = newToy;
    return;
  }

  toys* temp = head; // set a temp at head position
  while( temp->next){
    temp = temp->next; //traverse until there is no value after and continue to set value
  }

  temp->next = newToy; //create new node at end
}

void printHead(toys *head) {
  if (!head) {
    cout << "The conveyor belt is empty.\n";
    return;
  }
  cout << "Head toy: " << head->name << " (Price: " << head->price << ")\n";
}

void RemoveReplace(toys *&head1, int a, int b, toys *head2){
  if (!head1) {
    head1 = head2;
    return;
  }
  if (a > b) {
    return;
  }
 // 1 2 b 3 4 a
  toys* prevA = nullptr;      // the node just before index a
  toys* startDelete = head1;  // node at index a
  toys* endDelete = head1;    // node at index b
  toys* afterB = nullptr;     // node after index b

  // Traverse to the node at index a
  int idx = 0;
  while (startDelete && idx < a) {
    prevA = startDelete;
    startDelete = startDelete->next;
    idx++;
  }

  // If startDelete is nullptr here, it means a >= length of list
  if (!startDelete) {
    return; // this means we have nothing to remove so we end
  }

  // Now, find the node at index b
  endDelete = startDelete;
  while (endDelete && idx < b) {
    endDelete = endDelete->next;
    idx++;
  }

  // If endDelete is not nullptr, afterB is endDelete->next
  // This could be null if b is at or beyond the last index
  if (endDelete) {
    afterB = endDelete->next;
  }
 //memory 
  toys* temp = startDelete;
  toys* stop;
  if (endDelete) {
    stop = endDelete->next;
  } else {
    stop = nullptr;
  }
  while (temp != stop) {
    toys* nextNode = temp->next;
    delete temp;
    temp = nextNode;
  }

  //put belt 2 into position a. if its empty, belt2 becomes head
  if (prevA == nullptr) {
    head1 = head2; // The new head
  } else {
    // Link prevA to head2
    prevA->next = head2;
  }

  // If belt2 is not empty, we need to find its tail and connect it to afterB
  if (head2) {
    // Find tail of belt2
    toys* tail2 = head2;
    while (tail2->next) {
      tail2 = tail2->next;
    }
    // Attach tail of belt2 to afterB
    tail2->next = afterB;
  } else {
    // If belt2 is empty, just connect prevA -> afterB
    if (prevA) {
      prevA->next = afterB;
    }
    // If a == 0 and belt2 is empty, the new head is afterB
    else {
      head1 = afterB;
    }
  }
}

int main(){
  toys* belt1 = nullptr;
  toys* belt2 = nullptr;

//here im populating belts using our function to add stuff to end
  addNodeTail(belt1, "Truck", 10);
  addNodeTail(belt1, "Bear", 7);
  addNodeTail(belt1, "Sheep", 20);
  addNodeTail(belt1, "Buzz", 100);
  addNodeTail(belt1, "Bunny", 1000000);

  addNodeTail(belt2, "Greenthing", 90);  
  addNodeTail(belt2, "Turtle", 11);  
  addNodeTail(belt2, "Giraffe?", 6);  
  addNodeTail(belt2, "Rat", 19);  

  RemoveReplace(belt1, 1, 3, belt2);
  printHead(belt1);
  printHead(belt2);

  return 0;
}