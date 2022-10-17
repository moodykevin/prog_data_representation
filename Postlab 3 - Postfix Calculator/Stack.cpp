#include "Stack.h"

Stack::Stack(){
  head=new stacknode();
  tail=new stacknode();
  head->next=tail;
  tail->previous=head;
  count=0;
}

Stack::~Stack(){
}

bool Stack::empty(){
  if(this->count == 0){
    return true;
  } else {
    return false;
  }
}

void Stack::push(int e){
  stacknode* s = new stacknode();
  s->value = e;

  tail->previous->next = s;
  s->previous = tail->previous;
  s->next = tail;
  tail->previous = s;
  count+=1;
}

void Stack::pop(){
  if(!this->empty()){
    delete tail->previous;
    tail->previous->previous->next = tail;
    tail->previous = tail->previous->previous;
    count--;
  }
}

int Stack::top(){
  return tail->previous->value;
}
    
