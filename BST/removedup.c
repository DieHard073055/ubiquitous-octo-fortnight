#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct BST {
  int data;
  struct BST *l, *r;
}node;

void insert(node *, node *);
int * inorder(node *, int *);
void preorder(node *);
void postorder(node *);
node *getnode();
node *search(node *, int, node **);


int main(){
  int N;
  int i;
  int * values;
  node * new_node;
  node * root=NULL;

  scanf("%d", &N);fflush(stdin);
  printf("data size : %d\n", N);
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
  values = (int*) calloc(1, sizeof(int));
  values[0] = 1;
  values = inorder(root, values);
  for(i=0;i<values[0];i++)printf("%d\n", values[i]);
  free(values);
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


//Recursively reallocates the values array with sorted data.
int * inorder(node *root, int * values){
  int * v = NULL;

  if(root->l != NULL) values = inorder(root->l, values);

  values[0]++;

  v = (int*) realloc (values, values[0] * sizeof(int));

  v[v[0]-1] = root->data;


  if(root->r != NULL) v = inorder(root->r, v);

  return v;
}
void cut_down_the_tree(node *root){
  if(root->l != NULL) cut_down_the_tree(root->l);
  if(root->r != NULL) cut_down_the_tree(root->r);
  free(root);
}
