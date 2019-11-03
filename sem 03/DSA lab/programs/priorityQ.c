//priority queue
#include <stdio.h>
#include <stdlib.h>

struct node{
  int val;
  int priority;
  struct node *next;
};

struct node *head;

struct node *newNode(int v,int p){
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->val = v;
  temp->priority = p;
  temp->next = NULL;
}

 void insert(int v,int p){
   struct node *start = head;
   struct node *temp = newNode(v,p);

   if (head->priority > p) {
     temp->next = head;
     head = temp;
   }

   else{
     while (start->next!=NULL && start->next->priority<p) {
       start = start->next;
     }
     temp->next=start->next;
     start->next = temp;
   }
 }

 void delete(){
   if (head==NULL){
     printf("Queue is empty\n");
   }
   else{
     struct node *temp = head;
     head = head->next;
     printf("deleted %d\n\n",temp->val);
     free(temp);
   }
 }

void print(){
  struct node *temp = head;
  while (temp!= NULL) {
    printf("%d -> ",temp->val);
    temp = temp->next;
  }
  printf("NULL\n");
}

 int main(int argc, char const *argv[]) {
   int c = 0;
   int v,p;
   printf("enter a value,priority for head:");
   scanf("%d%d",&v,&p);
   head = newNode(v,p);
   while (c!=4) {
     printf("\n1. Insert 2. Delete 3. Print 4. Exit\n");
     printf(" \t Enter your choice: ");
     scanf("%d",&c);
     if (c == 1) {
       printf("enter a value,priority: ");
       scanf("%d%d",&v,&p);
       insert(v,p);
     }
     else if (c == 2) {
       delete();
     }
     else if (c == 3) {
       print();
     }
     else if (c == 4) {
       printf("Exit");
     }
     else{
       printf("\ninvalid choice\n");
     }
   }
   return 0;
 }
