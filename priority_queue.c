#include <stdio.h>
#include <string.h>
#include "priority_queue.h"

typedef struct myElement {
    int id;
    int grade;
} student_t;


int compare(void *elementA, void *elementB) {
   int gradeA = ((student_t *)elementA)->grade;
   int gradeB = ((student_t *)elementB)->grade;
   if(gradeA>gradeB) {
        return 1;
   }else if(gradeA<gradeB){
        return -1;
   }
   return 0;
}

void same(void *a,void *b){
    ((student_t *)a)->id=((student_t *)b)->id;
    ((student_t *)a)->grade=((student_t *)b)->grade;
}

void change(void *a,void *b){
    student_t tmp;
    tmp.id=((student_t *)a)->id;
    tmp.grade=((student_t *)a)->grade;
    ((student_t *)a)->id=((student_t *)b)->id;
    ((student_t *)a)->grade=((student_t *)b)->grade;
    ((student_t *)b)->id=tmp.id;
    ((student_t *)b)->grade=tmp.grade;
}

void print(PQ_t *pq) {
    student_t *temp;
    for (int i=0; i<pq->heap.numElements;i++){
        temp = (student_t *)(pq->heap.elements+i*sizeof(student_t));
        printf("index=%d, id=%d, grade=%d\n",i,temp->id, temp->grade);
    }
}

int main() {
student_t node[6]={
        {1211, 70},
        {1212, 60},
        {1213, 80},
        {1214, 65},
        {1215, 10},
        {1216, 90}
};
student_t n[100];
PQ_t maxPQ;
createPQ(&maxPQ, MAXHEAP, sizeof(student_t), 100, &compare);
for(int i=0;i<6;i++){
    Enqueue(&maxPQ, &node[i],same,change);
}
print(&maxPQ);
printf("\n");
Dequeue(&maxPQ,same,change);
print(&maxPQ);
printf("\n");

PQ_t PQ;
int num,g,m;
printf("maxheap(1) or minheap(0): ");
scanf("%d",&m);
if(m==1){
    createPQ(&PQ, MAXHEAP, sizeof(student_t), 10, &compare);
}
else{
    createPQ(&PQ, MINHEAP, sizeof(student_t), 10, &compare);
}
printf("number of elements: ");
scanf("%d",&num);
for(int i=0;i<num;i++){
    printf("grade: ");
    scanf("%d",&g);
    n[i].id=i;
    n[i].grade=g;
}
for(int i=0;i<num;i++){
    Enqueue(&PQ, &n[i],same,change);
}
printf("Isempty: %d, Isefull: %d\n",IsEmpty(&PQ),IsFull(&PQ));
print(&PQ);
printf("\n");
Dequeue(&PQ,same,change);
print(&PQ);
}

