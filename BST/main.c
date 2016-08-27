#include <stdio.h>
#include <stdlib.h>


typedef struct BST {
  int data;
  struct BST *l, *r;
}node;

void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *getnode();
node *search(node *, int, node **);


int main(){
  int N;
  int i;
  node * new_node;
  node * root=NULL;

  scanf("%d", &N);fflush(stdin);
  //printf("data size : %d\n", N);
  for(i=0;i<N;i++){
     new_node = getnode();
     scanf("%d", &new_node->data);
     //printf("data: %d\n", new_node->data);
     if (root == NULL) /* Tree is not Created */
        root = new_node;
     else
        insert(root, new_node);
  }
  //printf("\nThe Inorder display : ");
  inorder(root);
  printf("\n");
  return 0;
}


node *getnode(){
  node * temp;
  temp = (node*) malloc(sizeof(node));
  temp->l = NULL;
  temp->r = NULL;
  return temp;
}

void insert(node * root, node * n){

  if(n->data < root->data){
    if(root->l == NULL){
      root->l = n;
      //printf("inserting element %d to the left of %d \n", n->data, root->data);
    }else
      insert(root->l, n);
  }else if(n->data > root->data){
    if(root->r == NULL){
      root->r = n;
      //printf("inserting element %d to the right of %d \n", n->data, root->data);
    }else
      insert(root->r, n);
  }

}

node *search(node * root, int key, node **parent){
  node * temp = root;

  while(temp != NULL){
    if(temp->data == key){
      return temp;
    }

    if(key < temp->data ){
      temp = temp->l;
    }else{
      temp = temp->r;
    }
  }

  return NULL;
}

void inorder(node *root){
  if(root->l != NULL) inorder(root->l);
  printf("%i ", root->data);
  if(root->r != NULL) inorder(root->r);
}
void cut_down_the_tree(node *root){
  if(root->l != NULL) cut_down_the_tree(root->l);
  if(root->r != NULL) cut_down_the_tree(root->r);
  free(root);
}
