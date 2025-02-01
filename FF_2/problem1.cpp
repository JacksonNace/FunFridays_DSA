#include <iostream>
using namespace std;

struct node {
  int number;
  node *next;
};

node* buildLL() {
  int values[] = {1, 2, 3, 2, 1};
  int nodeNumber = sizeof(values) / sizeof(values[0]); // this takes the bits in an array and finds how many nodes are in it

  node* head = nullptr;
  node* tail = nullptr;

  for (int i = 0; i < nodeNumber; i++) {
    node* newNode = new node;
    newNode->number = values[i];
    newNode->next = nullptr;

    if (!head) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }
  return head;
}

node* findMiddle(node* head) {
  node* slow = head;
  node* fast = head;
  
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

node* reverseList(node* head) {
  node* prev = nullptr;
  node* curr = head;

  while (curr) {
    node* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
  }

  return prev;
}

bool isaPalindrome(node* head) {
  if (!head || !head->next) return true;

  node* mid = findMiddle(head);
  node* secondHalf = reverseList(mid);

  node* firstPtr = head;
  node* secondPtr = secondHalf;

  while (secondPtr) {  
    if (firstPtr->number != secondPtr->number) {
      return false;
    }
    firstPtr = firstPtr->next;
    secondPtr = secondPtr->next;
  }

  return true;
}

int main() {
  node* head = buildLL();

  if (isaPalindrome(head)) {
    cout << "This list is a palindrome!";
  } else {
    cout << "not a palindrome";
  }

  return 0;
}