#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<malloc.h>
#include "BST.h"

struct Node
{
    node_t cur;
    int data;
};

int compareMath(void *elementA, void *elementB)
{
    int mathA = ((struct Node *)elementA)->data;
    int mathB = ((struct Node *)elementB)->data;
    //printf("(%d %d)", mathA, mathB);
    if(mathA > mathB)
        return 1;
    else if(mathA < mathB)
        return -1;
    return 0;
}
int samedata(void *rootA, void *rootB)
{
    if(((struct Node *)rootA)->data == ((struct Node *)rootB)->data)
        return 1;
    else
        return 0;
}

void datacover(void **elementA, void **elementB)
{
   // printf("%d %d\n",((struct Node *)*elementA)->data, ((struct Node *)*elementB)->data);
    ((struct Node *)*elementA)->data = ((struct Node *)*elementB)->data;
    //printf("%d %d\n",((struct Node *)*elementA)->data, ((struct Node *)*elementB)->data);
}

void *copyNode(void *element)
{
    void *temp1 = (void *)malloc(sizeof(struct Node));
    if(temp1 != NULL)
    {
        memcpy(temp1, element, sizeof(struct Node));
    }
    else
        return NULL;
}

void print(void *element)
{
    struct Node *temp = (struct Node *)element;
    printf("%d ", temp->data);
    //printf("%p:%d(%p)(%p)(%p) ", temp, temp->data, temp->cur.parent, temp->cur.left, temp->cur.right);
}

int main()
{
    struct Node *tree1 = NULL, *node1, *tree2 = NULL, *node2;
    int j, k, n1 = 0;
    srand(100);

    //測試insert, inorder
    //建立第一棵樹
    for(j = 0; j < 10; j ++)
    {
        node1 = (struct Node *)malloc(sizeof(struct Node));
        node1->data = rand() % 10;
       // printf("insertnode(%d)\n",node1->data);
        node1->cur.left = NULL;
        node1->cur.right = NULL;
        node1->cur.parent = NULL;
        //printf("%d, %p, %p\n", node1->data, node1->cur.left, node1->cur.right);
        insertNode((void *)node1, (node_t **)&tree1, compareMath);
        //printf("%d, %p, %p\n", tree1->data, tree1->cur.left, tree1->cur.right);
        // printf("!\n");
    }
    inorder((node_t *)tree1, print);
    printf("\n");

    //建立第二棵樹
    for(j = 1; j < 11; j ++)
    {
        node2 = (struct Node *)malloc(sizeof(struct Node));
        node2->data = rand() % 10;
        node2->cur.left = NULL;
        node2->cur.right = NULL;
        node2->cur.parent = NULL;
        //printf("%d, %p, %p\n", node->data, node->cur.left, node->cur.right);
        insertNode((void *)node2, (node_t **)(&tree2), compareMath);
        //printf("%d, %p, %p\n", tree->data, tree->cur.left, tree->cur.right);
        //printf("!\n");
    }
    inorder((node_t *)tree2, print);
    printf("\n");

    //測試findmin, findmax
    /*struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = find_Max((node_t *)tree2);
    printf("%d",temp->data);*/

    //測試findnode(對),deletenode
    /*for(j = 0; j < 5; j ++)
    {
        struct Node *l = (struct Node *)malloc(sizeof(struct Node));
        l->data = rand() % 10;
        l->cur.left = NULL;
        l->cur.right = NULL;
        l->cur.parent = NULL;

        printf("%d\n",l->data);

        struct Node **temp = (struct Node *)malloc(sizeof(struct Node));
        *temp =  (struct Node *)find_Node((void *)l, (node_t **)(&tree1), compareMath);
        if(*temp == NULL)
            printf("no find\n");
        else
        {
            printf("find(%d)\n",(*temp)->data);
            deleteNode((node_t **)temp, datacover);
            //inorder((node_t *)tree1, print);
            //printf("@@\n");
        }
    }
    inorder((node_t *)tree1, print);
    printf("\n");*/

    //測試treecopy
    /*struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->cur.left = NULL;
    temp1->cur.right = NULL;
    temp1->cur.parent = NULL;

    temp1 = (struct Node *)treecopy((node_t *)tree1, copyNode);
    inorder((node_t *)temp1, print);*/

    //測試treeequal
    /*int resul = treeEqual((node_t *)tree1, (node_t *)tree2, samedata, &n1, 10);
    printf("%d",resul);*/
}
