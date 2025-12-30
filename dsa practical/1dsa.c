#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};
int isfull(struct node * head){
    struct node * p = (struct node *)malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }
    else{
        free(p);
        return 0;
    }
}
int isempty(struct node * head){
    if(head==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void linkedlisttraversal(struct node * head){
    struct node * p = head;
    if(head==NULL){
        printf("List is empty");
        return;
    }
    do{
        printf("Element: %d\n",p->data);
        p=p->next;
    }while(p!=head);
}
struct node * insertatend(struct node * head,int data){
    struct node * p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    if(head==NULL){
        p->next = p;
        return p;
    }
    struct node * q = head;
    while(q->next!=head){
        q=q->next;
    }
    q->next = p;
    p->next = head;
    return head;
}
struct node * insertbeforeindex(struct node * head,int data,int index){
    struct node * p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    if(index==0){
        struct node * q = head;
        while(q->next!=head){
            q=q->next;
        }
        q->next = p;
        p->next = head;
        return p;
    }
    struct node * q = head;
    for(int i=0;i<index-1 && q->next!=head;i++){
        q=q->next;
    }
    if(q->next==head){
        printf("Index out of bounds\n");
        free(p);
        return head;
    }
    p->next = q->next;
    q->next = p;
    return head;
}   

int main(){
    struct node * head = (struct node *)malloc(sizeof(struct node));
    struct node * second = (struct node *)malloc(sizeof(struct node));
    struct node * third = (struct node *)malloc(sizeof(struct node));           
    struct node * fourth = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->next = second;        
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = head;    
    linkedlisttraversal(head);
    head = insertatend(head,45);
    head = insertatend(head,55);
    head = insertatend(head,65);
    printf("After insertion\n");
    linkedlisttraversal(head);       
    
}