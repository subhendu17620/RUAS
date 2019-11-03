// program to construct a binary search tree and perform the Preorder, post order and in order traversal
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct node{
  int info;
  struct node *left,*right;
};

struct node *newTreeNode(int val){
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->info = val;
  temp->left= temp->right = NULL;
}

struct node *insert(struct node *root, int key){
  if (root == NULL) {
    return newTreeNode(key);
  }
  if (key<root->info) {
    root->left = insert(root->left,key);
  } else if (key>root->info) {
    root->right = insert(root->right,key);
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
  int a[] = {2,5,84,15,36,4,10};
  struct node *root = NULL;
  root = insert(root,a[0]);
  for (size_t i = 1; i < 7; i++) {
    insert(root,a[i]);
  }
  printf("InOrder:\n");
  inorder(root);

  printf("\nPreOrder:\n");
  preorder(root);

  printf("\nPostOrder:\n");
  postorder(root);
  return 0;
}
