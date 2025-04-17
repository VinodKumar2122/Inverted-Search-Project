#ifndef INV_H
#define INV_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 26

typedef struct node
{
    char s[30];
    struct  node *link;
}Slist;

typedef struct sub
{
    int word_count;
    char file_name[30];
    struct sub *link;
}Sub_node;

typedef struct node1
{
   int file_count;
   char word[1090];
   Sub_node *sub_link;
   struct node1 *link;
}Main_node;

typedef struct hash
{
    int index;
    Main_node *link;
}hash_t;

int read_validate(int argc, char *argv[],Slist **head);

int insert_last(Slist **head,char *s);

void print_list(Slist *head);

void create_hash(hash_t *HT,int size);

int create_data_base(hash_t *arr,Slist *head);

FILE *open_files(char s[]);

int get_index(char word[]);

//int insert_into_hash(hash_t *arr,int index);

int check_word(char s[],Main_node *head);

int create_mainnode(Main_node **head,char word[], char f_name[]);

Sub_node *create_subnode(char f_name[]);

int check_file(Main_node **head,char f_name[],char word[]);

int file_count(Main_node **head,char f_name[],char word[]);


void display_data_base(hash_t *arr);

int search_data(hash_t *arr);

int save_data(hash_t *arr);

int update_data(hash_t *arr,Slist **head);

int update_create_main(Main_node **head,char word[],int file_count);

int update_subnode(Main_node **head,char file_name[],int word_count,char word[]);

int sl_delete_element(Slist **head, char f_name[]);


#endif
