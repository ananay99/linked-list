#include<stdio.h>
#include<stdlib.h>
struct dlist{
int data;
struct dlist * next;
struct dlist * prev;
};
struct dlist * insertdlist(struct dlist ** mhead,struct dlist * last)
{
    int insertElement=0;
    scanf("%d",&insertElement);
    if((*mhead)!=NULL)
    {
        last->next=(struct dlist *)malloc(sizeof(struct dlist));
        (last->next)->prev=last;
        last=last->next;
        last->data=insertElement;
        last->next=NULL;
        return last;
    }
    else
    {
        *mhead=(struct dlist *)malloc(sizeof(struct dlist));
        (*mhead)->data=insertElement;
        (*mhead)->next=NULL;
        (*mhead)->prev=NULL;
        return(*mhead);
    }
}
struct dlist * deletedlist(struct dlist ** mhead,struct dlist * last)
{
 int delElement=0;
 scanf("%d",&delElement);
 if((*mhead)!=NULL)
 {
     struct dlist *head=*mhead;
     if((*mhead)->data==delElement)
     {
         if((*mhead)->next==NULL)
         {
             free(*mhead);
             *mhead=NULL;
             return NULL;
         }
         else
         {
             *mhead=(*mhead)->next;
             free((*mhead)->prev);
             (*mhead)->prev=NULL;
             return last;
         }
     }
     else
     {
         while(head!=NULL)
         {
             if((head)->data==delElement)
             {
                 (head->prev)->next=(head)->next;
                 if(head->next==NULL)
                 {
                     last=head->prev;
                 }
                 free(head);
                 break;
             }
             head=(head)->next;
         }
     }
 }
 return last;
}
void displaydlist(struct dlist * head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n\n");
}
int main()
{
struct dlist *head=NULL,*last=NULL;
int n=0;
do{
    switch(n)
    {
    case 1:
        last=insertdlist(&head,last);
        break;
    case 2:
        last=deletedlist(&head,last);
        break;
    case 3:
        displaydlist(head);
        break;
    case 4:
        exit(0);
    }
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
}while((scanf("%d",&n))!=EOF);
return 0;
}
