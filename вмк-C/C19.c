#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
     char str[20];
     struct node *next;
     struct node *prev;
};

int add_last(struct node* cur, const char * buf,const char * word,const char * word1,int count)
{
     
     struct node *tmp;
     struct node *new;
     
     while(cur->next)         
          cur = cur->next;
     
     new = (struct node *)malloc(sizeof(struct node));
     tmp = (struct node *)malloc(sizeof(struct node));
     
     if( new == NULL) 
          return 1;
          
     strcpy(new->str, buf);
     strcpy(tmp->str, word1);
     
     if (strcmp(new->str, word) == 0)
     {
         if(count==0)
         {
            tmp->prev = cur;
            cur->next = tmp;
            tmp->next = NULL;
         }
         
         if(count==1)
         {
             new->prev = cur;
             cur->next = new;
             new->next = tmp;
             tmp->prev = new;
             tmp->next = NULL;
         }
     }
     else{
         if(count==1)
         {
             new->prev = cur;
             cur->next = new;
             new->next = NULL;
         }
     }
     return 0;
}

void Print_forward(struct node *cur)
{
    if (cur == NULL)
    {
        printf("empty");
        return;
    }
    
    while(cur->next != NULL)
    {
        printf("%s ", cur->str);
        cur = cur->next;
    }
    
    printf("%s\n", cur->str);
}

struct node* Delete_list(struct node * head)
{
    struct node *tmp = head;
    while(head->next != NULL)
    {
        head = head->next;
        free(tmp);
        tmp = head;
    }
    return head;
}

int main (int argc, char *argv[])
{
    struct node *head = NULL;
    char buf[20];

    if (scanf("%19s", buf) != EOF)
    {
        head = (struct node*) malloc(sizeof(struct node));
        if(head == NULL)
            return 1;
        strcpy(head->str,buf);  //做一个元素链表
        head->next = NULL ;
        head->prev = NULL ;
        add_last(head, buf, argv[1], argv[2],0);
    }
	else{ return 0;}

    while( scanf("%19s", buf) != EOF)
    {
        if(add_last(head, buf, argv[1], argv[2],1) == 1) //在链表中加元素
            break;
    } 
    
    Print_forward(head); //打印链表
    
    Delete_list(head); //清空链表
    return 0;
}
