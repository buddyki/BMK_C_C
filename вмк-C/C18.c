#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
 char str[20];
 struct node *next;
 struct node *prev;
};

struct node* Delete_node(struct node *cur, const char * buf){
 struct node* head = cur;
 if (strcmp(cur->str, buf) == 0){
  struct node *tmp = cur;
  if(cur->next == NULL){
   free(cur);
   return NULL;
  }
  cur = cur->next;
  free(tmp);
  cur->prev = NULL;
  return cur;
 }
 while(cur->next != NULL){
  if(strcmp(cur->str, buf) == 0){
   struct node *tmp = cur;
   cur->next->prev = cur->prev;
   cur->prev->next = cur->next;  
   free(tmp);
   return head;
  }
  cur = cur->next;
 }
 if (strcmp(cur->str, buf) == 0){
  cur->prev->next = NULL;
  free(cur);
  return head;
 }
 return head;
}

int add_last(struct node* cur, const char * buf){
 struct node *new;
 while(cur->next)
  cur = cur->next;
 new = (struct node *)malloc(sizeof(struct node));
 if( new == NULL) 
  return 1;
 strcpy(new->str, buf);
 new->prev = cur;
 cur->next = new;
 new->next = NULL;
 return 0;
}

void Print_list(struct node *cur){
 while(cur->next)
  cur = cur->next;
 while(cur->prev){
  printf("%s\n", cur->str);
  cur = cur->prev;
 }
 printf("%s\n", cur->str);
}

void Print_forward(struct node *cur){
 if (cur == NULL){
  printf("empty");
  return;
 }
 while(cur->next != NULL){
  printf("%s ", cur->str);
  cur = cur->next;
 }
 printf("%s\n", cur->str);
}

struct node* Delete_list(struct node * head){
 struct node *tmp = head;
 while(head->next != NULL){
  head = head->next;
  free(tmp);
  tmp = head;
 }
 return head;
}

int main (){
 struct node *head = NULL;
 char buf[20];
 char word[20];
 scanf("%19s", word);
 if (scanf("%19s", buf) != EOF){
  head = (struct node*) malloc(sizeof(struct node));
  if(head == NULL)
   return 1;
  strcpy(head->str,buf);
  head->next = NULL ;
  head->prev = NULL ;
 }
 while(scanf("%19s", buf) != EOF){
  if(add_last(head, buf) == 1)
   break;
 } 
 if (head != NULL){
  head = Delete_node(head, word); 
 }
 Print_forward(head);
 
 if (head != NULL){
  head = Delete_node(head, word);
  free(head);
}return 0;
}