#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char str[20];
    struct node *next;
    struct node *prev;
};
int add_first(struct node* cur,const char *buf)
{
    struct node *new;
    while(cur->prev)
        cur = cur->prev;
        new=(struct node*)malloc(sizeof(struct node));
        if(new==NULL)return 1;
        strcpy(new->str,buf);
        new->next = cur;
        cur->prev = new;
        new->prev = NULL;
        return 0;
}
void Print_list(struct node *cur)
{
    while(cur->prev)
        cur = cur->prev;
    while(cur->next)
    {
        printf("%s\n",cur->str);
        cur=cur->next;
    }
    printf("%s\n",cur->str);
}

struct node*Delete_list(struct node *head){
    struct node *tmp =head;
    while(head->next !=NULL){
        head =head->next;
        free(tmp);
        tmp=head;
    }
}

int main()
{
    struct node *head = NULL;
    char buf[20];
    if (scanf("%19s",buf)!=EOF)
    {
        head = (struct node*)malloc(sizeof(struct node));
    
    if(head == NULL)
        return 1;
    strcpy(head->str,buf);
    head->next = NULL;
    head->prev = NULL;
    }
    while(scanf("%19s",buf)!=EOF)
    {
        if(add_first(head,buf))
            break;

    }
    Print_list(head);
    Delete_list(head);
    return 0;
}
