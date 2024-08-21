#include<stdio.h>
#include<stdlib.h>

int a=1,b=1;

struct bestfit
{
    int data;
    struct bestfit* link;
}*mptr=NULL,*mhead,*pptr=NULL,*phead;

void display(struct bestfit **head,char c)
{
    struct bestfit *ptr=NULL;
    if(c == 'b')
    {
        ptr=head;
        printf("MEMORY LIST = [");
        while (ptr != NULL)
        {
            printf(" %d,",ptr->data);
            ptr=ptr->link;
        }
        printf("\b]\n");
    }
    else
    {
        ptr=head;
        printf("PROCESS LIST = [");
        while (ptr != NULL)
        {
            printf(" %d,",ptr->data);
            ptr=ptr->link;
        }
        printf("\b]\n");
    }   
}

void insertEnd(struct bestfit **head,struct bestfit *ptr,int x)
{
    struct bestfit *new;
    new=(struct bestfit *)malloc(sizeof(struct bestfit));
    new->data=x;
    new->link=NULL;
    ptr=head;
    
    if (head == NULL)
    {
        *head=new;
    }
    else
    {
        while (ptr->link != NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=new;
    }
}

int get(char c)
{
    int elem;
    if(c=='b')
    {
        printf("Block Memory %d >> ",a);
        scanf("%d",&elem);
        a++;
        return elem;
    }
    else
    {
        printf("Block Process %d >> ",b);
        scanf("%d",&elem);
        b++;
        return elem;
    }
}

void main()
{
    printf("\nBESTFIT USING LINKED LIST\n");
    printf("Enter the number of memory blocks = ");
    int mlim;
    scanf("%d",&mlim);

    printf("Enter the Memory Blocks\n");
    for(int i=0;i<mlim;i++)
    {
        insertEnd(&mhead,&mptr,get('b'));
    }
    display(&mhead,'b');

    printf("Enter the number of process blocks = ");
    int plim;
    scanf("%d",&plim);

    printf("Enter the Memory Blocks\n");
    for(int i=0;i<plim;i++)
    {
        insertEnd(&phead,pptr,get('p'));
    }
    display(&phead,'p');

}




