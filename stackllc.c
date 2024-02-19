#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
  
};
struct Stack{
  struct Node*top;
};
struct Stack*initStack(){
  struct Stack*stack=(struct Stack*)malloc(sizeof(struct Stack*));
  stack->top=NULL;
  return;


}
void push(struct Stack*stack,int data){
  struct Node*newNode=(struct Node*)malloc(sizeof(struct Stack*));  
  newNode->data=data;
  newNode->next=stack->top;
  stack->top=newNode;

}
int pop(struct Stack*stack){

  if(stack->top==NULL){

    printf("stack is empty\n");
    return -1;
  }
  int data = stack->top->data;
  struct Node*temp=stack->top;
  stack->top=stack->top->next;
  free(temp);
  return data;

}
void display(struct Stack* stack){
  struct Node*current=stack->top;
  printf("staxk:");
  while(current!=NULL){
    printf("%d",current->data);
    current = current->next;
  }
  printf("\n");
}
  int main(){
    struct Stack*stack=initStack();
    push(stack,10);
    push(stack,20);
    push(stack,30);
    int poppedElement = pop(stack);
    printf("popperd element %d\n",poppedElement);
     display(stack);
    return 0;
  }
