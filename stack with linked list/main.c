#include <stdio.h>
#include <stdlib.h>
typedef struct n{
    struct n* next;
    int data;
}node;

node* root=NULL;
node** p=&root;

node* pop(node* root,int data){
    if(root==NULL){
        root=(node*)malloc(sizeof(node));
        root->data=data;
        root->next=NULL;
        return root;
    }
    node* temp=root;
    while(temp->next!=NULL)
        temp=temp->next;
    node* iter=(node*)malloc(sizeof(node));
    temp->next=iter;
    iter->next=NULL;
    iter->data=data;
    return root;
}

void bastir(node* root){
    node* temp=root;
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}

int push(node* root){
    node* temp=root;
    node* iter=root;
    int data;
    if(root==NULL){
        printf("Stack is empty!!!!\n");
        return-1;
    }
    if(root->next==NULL){//tek deger kaldigi zaman
        data=root->data;
        *p=NULL;
        return data;
    }
    while(temp->next!=NULL)
        temp=temp->next;
    data=temp->data;
    while(iter->next!=temp)
        iter=iter->next;
    free(temp);
    iter->next=NULL;
    return data;

}

int main()
{
    root=pop(root,4);
    root=pop(root,8);
    root=pop(root,45);
    root=pop(root,95);
    root=pop(root,543);
    bastir(root);
    printf("%d  ",push(root));
    printf("%d  ",push(root));
    printf("%d  ",push(root));
    printf("%d  ",push(root));
    printf("%d  ",push(root));
    printf("%d  ",push(root));
    printf("%d  ",push(root));
    printf("%d  ",push(root));
    root=pop(root,8);
    bastir(root);
    return 0;
}
