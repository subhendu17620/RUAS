// inserting and deleteing before and after an element
#include <stdio.h>
#include <stdlib.h>

struct node{
  int val;
  struct node *next;
};

struct node *head = NULL;

struct node *newNode(int v){
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->val = v;
  temp->next = NULL;
}

void insert_after(int key,int val){
  struct node *temp = head,*new = newNode(val);
  if (head == NULL) {
    head = new;
    head->next = NULL;
  }
  else{
    while (temp != NULL && temp->val !=key) {
      temp = temp->next;
    }
    if (temp == NULL) return;
    new->next = temp->next;
    temp->next = new;
  }
}

void insert_before(int key, int val){
  struct node *temp = head,*new = newNode(val), *prev = NULL;
  if (head == NULL) {
    head = new;
    head->next = NULL;
  }
  else{
  while (temp != NULL && temp->val != key) {
      prev = temp;
      temp = temp->next;
  }
  if (temp == NULL || prev == NULL) return;
  prev->next = new;
  new->next = temp;
  }
}

void delete_after(int key){
  struct node *temp = head,*del;
  while (temp->val!=key && temp!=NULL){
    temp = temp->next;
  }
  if (temp==NULL) return;
  del = temp->next;
  temp->next = del->next;
  free(del);
}

void delete_before(int key){
  struct node *temp = head,*prev;
  while (temp->next->val!=key && temp->next!=NULL){
    prev = temp;
    temp = temp->next;
  }
  prev->next = temp->next;
  free(temp);
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
  int v,k;
  while (c!=6) {
    printf("1. Insert after 2. Insert before 3. Print 4. Delete after 5. Delete before 6. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&c);
    if (c == 1) {
      printf("enter a key,value: ");
      scanf("%d%d",&k,&v);
      insert_after(k,v);
    }
    else if (c == 2) {
      printf("enter a key,value: ");
      scanf("%d%d",&k,&v);
      insert_before(k,v);
    }
    else if (c == 3) {
      print();
    }
    else if (c == 4) {
      printf("enter a value: ");
      scanf("%d",&v);
      delete_after(v);
    }
    else if (c == 5) {
      printf("enter a value: ");
      scanf("%d",&v);
      delete_before(v);
    }
    else if (c == 6) {
      printf("Exit");
    }
    else{
      printf("\ninvalid choice\n");
    }
  }
  return 0;
}
