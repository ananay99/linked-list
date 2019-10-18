#include<stdio.h>
#include<stdlib.h>
struct clist{
int data;
struct clist * next;
};
struct clist * insertclist(struct clist ** mhead,struct clist * last)
{
    int insertElement=0;
    scanf("%d",&insertElement);
    if((*mhead)!=NULL)
    {
        last->next=(struct clist *)malloc(sizeof(struct clist));
        last=last->next;
        last->data=insertElement;
        last->next=(*mhead);
        return last;
    }
    else
    {
        *mhead=(struct clist *)malloc(sizeof(struct clist));
        (*mhead)->data=insertElement;
        (*mhead)->next=*mhead;
        return(*mhead);
    }
}
struct clist * deleteclist(struct clist ** mhead,struct clist * last)
{
 int delElement=0;
 scanf("%d",&delElement);
 if((*mhead)!=NULL)
 {
     struct clist * prev=*mhead,*head=*mhead;
     if((*mhead)->data==delElement)
     {
         if((*mhead)==last)
         {
             free(*mhead);
             (*mhead)=NULL;
             return NULL;
         }
         else
         {
             *mhead=(*mhead)->next;
              free(prev);
             last->next=(*mhead);
             return last;
         }
     }
     else
     {
          struct clist * chead=head;
          do{
             if((head)->data==delElement)
             {
                 prev->next=(head)->next;
                 free(head);
                 if(prev->next==(*mhead))
                 {
                     last=prev;
                     return prev;
                 }
                 break;
             }
             prev=head;
             head=(head)->next;
            }while(head!=chead);
    }
 }
 return last;
}
void displayclist(struct clist * head)
{
    if(head!=NULL)
    {
    struct clist * chead=head;
    do{
        printf("%d ",head->data);
        head=head->next;
    }while(head!=chead);
    printf("\n\n");
    }
}
int main()
{
struct clist *head=NULL,*last=NULL;
int n=0;
do{
    switch(n)
    {
    case 1:
        last=insertclist(&head,last);
        break;
    case 2:
        last=deleteclist(&head,last);
        break;
    case 3:
        displayclist(head);
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
