#include <stdio.h>
#include <stdlib.h>
#include"avlTree.h"

typedef struct avltree{
	avl_node_t root;
}avltree;

void setnode(avl_node_t *node){
((node_t *)node)->left=NULL;
((node_t *)node)->right=NULL;
((node_t *)node)->parent=NULL;
}

int main(){


}
