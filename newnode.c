#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node*next;

};

struct Node*createNode(int value){

  struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
  newNode->data=value;
  return newNode;
}

int main(){

  int value;
  printf("enter the value to be printed to the node:\n");
  scanf("%d",&value);
  struct Node*newNode=createNode(value);
  printf("data of creatyed node%d",newNode->data);
  free(newNode);
  return 0;

}
