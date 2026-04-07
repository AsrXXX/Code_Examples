#include <stdio.h>
#include <stdlib.h>
#include"dllNode_t.h"
typedef struct Node_t{
    dllNode_t link;
    unsigned int data;
}Node_t;

void add(Node_t * a, Node_t * b, Node_t * c) { //兩數相加
    int carry=0;
    Node_t *t,*t2,*t3;
    int flag=0;
    for(t=a,t2=b;t!=NULL && t2!=NULL;t=DLL_prev_node((dllNode_t *)t),t2=DLL_prev_node((dllNode_t *)t2)){
        //printf("Hi");
        if(flag==0){
            c->data=t->data+t2->data+carry;
            if(c->data<10) {
                carry = 0;
            }
            else { // 進位
                c->data=c->data-10;
                carry=1;
            }
            flag=1;
            continue;
        }
        Node_t *tmp=(Node_t *)malloc(sizeof(Node_t));
        tmp->data=t->data+t2->data+carry;
        DLL_init((dllNode_t *)tmp);
        if(tmp->data<10) {
            carry = 0;
        }
        else { // 進位
            tmp->data=tmp->data-10;
            carry=1;
        }
        DLL_add_tail((dllNode_t *)tmp,(dllNode_t *)c);
    }
    if(t==NULL && t2!=NULL){
        //printf("Hi");
        for(t2;t2!=NULL;t2=DLL_prev_node((dllNode_t *)t2)){
        Node_t *tmp=(Node_t *)malloc(sizeof(Node_t));
        tmp->data=t2->data+carry;
        DLL_init((dllNode_t *)tmp);
        if(tmp->data<10) {
            carry = 0;
        }
        else { // 進位
            tmp->data=tmp->data-10;
            carry=1;
        }
        DLL_add_tail((dllNode_t *)tmp,(dllNode_t *)c);
        }

    }
    else if(t!=NULL && t2==NULL){
        //printf("Hi");
        for(t;t!=NULL;t=DLL_prev_node(t)){
        Node_t *tmp=(Node_t *)malloc(sizeof(Node_t));
        tmp->data=t->data+carry;
        DLL_init((dllNode_t *)tmp);
        if(tmp->data<10) {
            carry = 0;
        }
        else { // 進位
            tmp->data=tmp->data-10;
            carry=1;
        }
        DLL_add_tail((dllNode_t *)tmp,(dllNode_t *)c);
        }
    }
    if(carry>0){
        Node_t *tmp=(Node_t *)malloc(sizeof(Node_t));
        tmp->data=carry;
        DLL_init((dllNode_t *)tmp);
        DLL_add_tail((dllNode_t *)tmp,(dllNode_t *)c);
    }
    for(t3=c;((dllNode_t *)t3)->next!=NULL;t3=DLL_next_node((dllNode_t *)t3));
    if(!DLL_isEmpty((dllNode_t *)c)){
        for(t3;t3!=NULL;t3=DLL_prev_node((dllNode_t *)t3)){
            printf("%d", t3->data);
        }
    }
}
void Print(Node_t *head){
    Node_t *tmp;
    for(tmp=head;tmp!=NULL;tmp=DLL_next_node((dllNode_t *)tmp)){
        printf("%d", tmp->data);
    }
    return;
}
int main(){
char n;
Node_t *head,*head2,*head_ans;
Node_t *top,*top2;
head=(Node_t *)malloc(sizeof(Node_t));
head2=(Node_t *)malloc(sizeof(Node_t));
head_ans=(Node_t *)malloc(sizeof(Node_t));
DLL_init((dllNode_t *)head);
DLL_init((dllNode_t *)head2);
DLL_init((dllNode_t *)head_ans);
top=top2=NULL;
while((n=getchar()) != EOF){
    if(n<48||n>57){
        break;
    }
    if(top==NULL){
        head->data=(n-48);
        top=head;
        continue;
    }
    Node_t *tmp=(Node_t *)malloc(sizeof(Node_t));
    tmp->data=(n-48);
    DLL_init((dllNode_t *)tmp);
    DLL_add_tail((dllNode_t *)tmp,(dllNode_t *)top);
    top=DLL_next_node((dllNode_t *)top);
}

while((n=getchar()) != EOF){
    if(n<48||n>57){
        break;
    }
    if(top2==NULL){
        head2->data=(n-48);
        top2=head2;
        continue;
    }
    Node_t *tmp=(Node_t *)malloc(sizeof(Node_t));
    tmp->data=(n-48);
    DLL_init((dllNode_t *)tmp);
    DLL_add_tail((dllNode_t *)tmp,(dllNode_t *)top2);
    top2=DLL_next_node((dllNode_t *)top2);
}
if(!DLL_isEmpty((dllNode_t *)head)){
    for(top=head;((dllNode_t *)top)->next!=NULL;top=DLL_next_node((dllNode_t *)top)){
        printf("%d", top->data);
    }
    printf("%d", top->data);
}
printf(" + ");
if(!DLL_isEmpty((dllNode_t *)head2)){
    for(top2=head2;((dllNode_t *)top2)->next!=NULL;top2=DLL_next_node((dllNode_t *)top2)){
        printf("%d", top2->data);
    }
    printf("%d", top2->data);
}
printf(" = ");
add(top,top2,head_ans);

}

