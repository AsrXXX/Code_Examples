#ifndef DOUBLELINK_H_INCLUDED
#define DOUBLELINK_H_INCLUDED

typedef struct node {
    struct node * prev;
    struct node * next;
} dllNode_t;

void DLL_init(dllNode_t * head){ //建構一個空的 list
    head->next=head->prev=NULL;
}

int DLL_isEmpty(dllNode_t *head){ // head 是否為空的list
    if(head->next==NULL && head->prev==NULL && (head->data-(int)head->data!= 0)){
        return 1;
    }
    else{
        return NULL;
    }
}

dllNode_t * DLL_next_node(dllNode_t * node){ //(下一個節點)
    return node->next;
}
dllNode_t * DLL_prev_node(dllNode_t * node){ //(上一個節點)
    return node->prev;
}

unsigned int DLL_num_nodes(dllNode_t *head){ //計算List中有幾個node
    dllNode_t *tmp;
    int counter=1;
    tmp=head;
    while(tmp!=NULL){
        tmp=head->next;
        counter++;
    }
    return counter;
}

void DLL_add_before(dllNode_t * new_node, dllNode_t * head){ //(將新node加入到head node的前一個)
    new_node->next=head;
    head->prev=new_node;
}

void DLL_add_tail(dllNode_t * new_node, dllNode_t *head){ //(將新node加入到head node的後一個)
    new_node->prev=head;
    head->next=new_node;
}

void DLL_delete(dllNode_t * node){ //(從node所在的 Linked List 中刪除此點)
    node->prev->next=node->next;
    node->next->prev=node->prev;
    free(node);
}

void DLL_concate(dllNode_t *firstList, dllNode_t * secondList){ //(將secondList 串在firstList之後)
    dllNode_t *tmp,*;
    tmp=firstList;

    firstList->next=secondList;
    secondList->prev=firstList;
}
#endif // DOUBLELINK_H_INCLUDED
