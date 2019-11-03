// program to implement a linked list to construct a tree and count the number of leaves in a tree.
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

int getLeafCount(struct node* root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    else
        return getLeafCount(root->left)+getLeafCount(root->right);
}

int main(int argc, char const *argv[]) {
  int c = 0;
  int v;
  while (c!=3) {
    printf("1. Insert into linked list\n2. get Binary tree leaf count\n3. Exit");
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
      printf("\n Number of leaves in the binary tree is %d\n",getLeafCount(root));

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
