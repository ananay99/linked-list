#include<stdio.h>
#include<stdlib.h>
struct llist{
int data;
struct llist * next;
};
struct llist * insertLlist(struct llist ** mhead,struct llist * last)
{
    int insertElement=0;
    scanf("%d",&insertElement);
    if((*mhead)!=NULL)
    {
        last->next=(struct llist *)malloc(sizeof(struct llist));
        last=last->next;
        last->data=insertElement;
        last->next=NULL;
        return last;
    }
    else
    {
        *mhead=(struct llist *)malloc(sizeof(struct llist));
        (*mhead)->data=insertElement;
        (*mhead)->next=NULL;
        return(*mhead);
    }
}
struct llist * deleteLlist(struct llist ** mhead,struct llist * last)
{
 int delElement=0;
 scanf("%d",&delElement);
 if((*mhead)!=NULL)
 {
     struct llist * prev=*mhead,*head=*mhead;
     if((*mhead)->data==delElement)
     {
         *mhead=(*mhead)->next;
         free(prev);
         if((*mhead)==NULL)
         {
             return NULL;
         }
         else
         {
             return last;
         }
     }
     else
     {
         while(head!=NULL)
         {
             if((head)->data==delElement)
             {
                 prev->next=(head)->next;
                 free(head);
                 if(prev->next==NULL)
                 {
                     return prev;
                 }
                 break;
             }
             prev=head;
             head=(head)->next;
         }
     }

 }
 return last;
}
void displayLlist(struct llist * head)
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
struct llist *head=NULL,*last=NULL;
int n=0;
do{
    switch(n)
    {
    case 1:
        last=insertLlist(&head,last);
        break;
    case 2:
        last=deleteLlist(&head,last);
        break;
    case 3:
        displayLlist(head);
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
