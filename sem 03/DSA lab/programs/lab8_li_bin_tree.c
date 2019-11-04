// Implement a linked list to create and print a binary tree. 
#include <stdio.h>
#include <stdlib.h>

struct li_node{
  int val;
  struct li_node *next;
};

struct li_node *head = NULL; 

struct li_node *newNode(int v){
  struct li_node *temp = (struct li_node *)malloc(sizeof(struct li_node));
  temp->val = v;
  temp->next = NULL;
}

void push (int v){
  struct li_node *temp = newNode(v);
  if (head == NULL) {
    head = temp;
    head->next = NULL;
  }
  else{
    temp->next = head;
    head = temp;
  }
}

void print(){
  struct li_node *temp = head;
  while (temp!= NULL) {
    printf("%d -> ",temp->val);
    temp = temp->next;
  }
  printf("NULL\n");
}

struct node{
  int info;
  int count;
  struct node *left,*right;
};

struct node *newTreeNode(int val){
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->info = val;
  temp->count = 0;
  temp->left= temp->right = NULL;
}

struct node *insert(struct node *root, int key){
  if (root == NULL) {
    return newTreeNode(key);
  }
  if (root->left == NULL) {
    root->left = newTreeNode(key);
    root->count +=1;
  }
  else if (root->right == NULL) {
    root->right = newTreeNode(key);
    root->count +=1;
  }
  else {
    struct node *temp = root->left;
    if (temp->count!=2)
      insert(root->left,key);
    else{
      temp = root->right;
      if (temp->count!=2)
        insert(root->right,key);
      else
        insert(root->left,key);
    }
    }
  return root;
}

void inorder(struct node *root){
  if (root->left != NULL) {
    inorder(root->left);
  }
  printf("%d-",root->info);
  if (root->right != NULL) {
    inorder(root->right);
  }
}

void postorder(struct node *root){
  if (root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  printf("%d-",root->info);
}

void preorder(struct node *root){
  if (root == NULL) return;
  printf("%d-",root->info);
  preorder(root->left);
  preorder(root->right);
}

int main(int argc, char const *argv[]) {
  int c = 0;
  int v;
  while (c!=3) {
    printf("1. Insert into linked list\n2. Print Binary tree\n3. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&c);
    if (c == 1) {
      printf("enter a value:");
      scanf("%d",&v);
      push(v);
    }
    else if (c == 2) {
      printf("\nThe linked List is: ");
      print();
      struct node *root = NULL;
      root = insert(root,head->val);
      struct li_node *temp =head->next;
      for (size_t i = 1; temp!=NULL; i++) {
        insert(root,temp->val);
        temp = temp->next;
      }
      printf("\nthe binary tree in: \npreOrder:\n");
      preorder(root);

      printf("\npostOrder:\n");
      postorder(root);

      printf("\nInOrder:\n");
      inorder(root);
      printf("\n");
    }
    else if (c == 3) {
      printf("Exit");
    }
    else{
      printf("\ninvalid choice\n");
    }
  }
  return 0;
}
