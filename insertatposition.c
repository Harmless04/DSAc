#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node*next;
};
struct Node*createNode(int value){
  struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
  newNode->data=value;
  newNode->data=NULL;
  return newNode;
}
void insertAtPosition(struct Node**head,int position,int value){

  struct Node*newNode=createNode(value);
  if(position ==0){
    newNode->next=*head;
    *head=newNode;
    return;
  }
  int count=0;
  struct Node*temp=*head;
  while(count<position-1 && temp!=NULL){
    temp=temp->next;
    count++;
  }
  if(temp==NULL || temp->next==NULL){
    printf("invalid position");
    return;
  }
  newNode->next=temp->next;
  temp->next=newNode;
}

int main(){
  struct Node*head=NULL;
  int position,value,i,n;
  printf("number of elementy is list");
  scanf("%d",&n);
  for(i=0;i<n;i++){

    printf("enter element %d",i+1);
    scanf("%d",&value);
    insertAtPosition(&head,i,value);

  }
  struct Node*temp=head;
  while(temp!=NULL){
    printf("%d",temp->data);
    temp=temp->next;
  }
  return 0;

}
