 
#include <iostream>
#include <string>
#include "List.h"

using namespace std;

List::List(){
  head=new ListNode();
  tail=new ListNode();
  head->next=tail;
  tail->previous=head;
  count=0;
}

List::List(const List& source){
  head=new ListNode();
  tail=new ListNode();
  head->next=tail;
  tail->previous=head;
  count=0;

  // Make a deep copy of the list
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

List::~List(){
  makeEmpty();
  delete head;
  delete tail;
}

List& List::operator=(const List& source) {
  if (this == &source) {
    // The two are the same list; no need to do anything
    return *this;
  } else {
    // Clear out anything this list contained
    // before copying over the items from the other list
    makeEmpty();

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}


bool List::isEmpty() const {
  if(this->count == 0){
    return true;
  } else {
    return false;
  }
}

void List::makeEmpty() {
  ListItr y = first();
  for(int i = 0; i < this->count; i++){

    y.moveForward();
    delete y.current->previous;
  }

  head->next = tail;
  tail->previous = head;
  this->count = 0;
}

ListItr List::first() {
  ListItr iter(this->head->next);
  return iter;
}

ListItr List::last() {
  ListItr iter(this->tail->previous);
  return iter;
}

void List::insertAfter(int x, ListItr position) {
  ListNode* n = new ListNode();
  n->value = x;
  position.current->next->previous = n;
  n->next = position.current->next;
  n->previous = position.current;
  position.current->next=n;
  count+=1;
}

void List::insertBefore(int x, ListItr position) {
  ListNode* n = new ListNode();
  n->value = x;
  position.current->previous->next = n;
  n->previous = position.current->previous;
  n->next = position.current;
  position.current->previous = n;
  count+=1;
}

void List::insertAtTail(int x) {
  ListNode* n = new ListNode();
  n->value = x;
  
  tail->previous->next = n;
  n->previous = tail->previous;
  n->next = tail;
  tail->previous = n;
  count+=1;
}
 

ListItr List::find(int x) {
  ListItr y  = first();
  for(int i=0; i < this->size(); i++){
    if(y.retrieve() == x){
      return y;
    } else {
      y.moveForward();
    }
  }
  return y;
  
}

void List::remove(int x) {
  ListItr y = find(x);
  if(!y.isPastEnd()){
    y.current->previous->next=y.current->next;
    y.current->next->previous=y.current->previous;
    delete y.current;
    count-=1;
  }
}

int List::size() const {
  return count;
}

void printList(List& source, bool forward){

  if(forward){
    ListItr x = (source.first());
    for(int i=0; i < source.size(); i++){
      cout << x.retrieve() << " ";
      x.moveForward();
    }
  } else {
    ListItr x = (source.last());
    for(int i=0; i < source.size(); i++){
      cout << x.retrieve() << " ";
      x.moveBackward();
    }
  }
  cout << "\n";
  
}
