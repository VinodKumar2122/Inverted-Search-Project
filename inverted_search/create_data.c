#include"invert.h"


int create_data_base(hash_t *arr,Slist *head)
{
    if(head == NULL)
    {
        printf("INFO : No files are not their to creating the database\nCreating the database is not possible\n->NULL\n");
        return 0;
    }
    Slist *temp = head;
    FILE *f;
    int index;
    char word[30];
    int val;
    while (temp != NULL)
    {
        if((f = open_files(temp->s)) == NULL)
        {
            return 0;
        }
        while(fscanf(f,"%s",word) > 0)
        {
            char ch = getc(f);
            index = get_index(word);            
            if(index < 0 || index > 25)
            index = 26;

                 val = check_word(word,(arr[index].link));
                 if(val == 1)
                 {
                   val = check_file(&(arr[index].link),temp->s,word);
                    if(val == 0)
                    {
                       val =  file_count(&(arr[index].link),temp->s,word);
                    }
                 }
                 else
                 {
                   int a =  create_mainnode(&(arr[index].link),word,temp->s);
                 }

                
        }
        temp = temp->link;
    }
    return 1;
}
FILE  *open_files(char s[])
{
    FILE *f = fopen(s,"r");
    if(f == NULL)
    {
        printf("Error : file not their \n");
        return NULL;
    }
    fseek(f,0,SEEK_SET);
    return f;
}

int get_index(char word[])
{
   if(word[0] >= 'A' && word[0] <= 'Z')
   { 
     return ((word[0]+32) - 97);
   }
   else
   return (word[0] - 97);
}

int check_word(char s[],Main_node *head)
{

    if(head == NULL)
    {
        return 0;
    }
    Main_node *temp = head;
    while(temp!=NULL)
    {
        if(strcmp(s,temp->word) == 0)
        {
            return  1;
        }
        temp = temp->link;
    }
    return 0;

}

int create_mainnode(Main_node **head, char word[], char f_name[])
{
    Main_node *new = malloc(sizeof(Main_node));
    if(new == NULL)
    {
        return 0;
    }
    new->file_count = 1;
    strcpy(new->word,word);
    new->sub_link = create_subnode(f_name);
    new->link = NULL;
    if(*head == NULL)
    {
        *head = new;
        return 1;
    }
    Main_node *temp = *head;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = new;
    return 1;

}

Sub_node *create_subnode(char f_name[])
{
    Sub_node *new = malloc(sizeof(Sub_node));
    if(new == NULL)
    {
        return NULL;
    }
    new->word_count = 1;
    strcpy(new->file_name,f_name);
    new->link = NULL;
    return new;

}

int check_file(Main_node **head,char f_name[],char word[])
{
    int flag = 0;
    Main_node *temp = *head;
    while(temp != NULL)
    {
        if(strcmp(temp->word,word) == 0)
        {
            Sub_node *temp1 = temp->sub_link;
            while(temp1 != NULL)
            {
               if(strcmp(temp1->file_name,f_name) == 0)
               {
                  temp1->word_count += 1;
                  flag = 1;
               }
               temp1 = temp1->link; 
            }

        }
        temp = temp->link;
    }
  if(flag == 0)
  return 0;
  else
  return 1;

}

int file_count(Main_node **head,char f_name[],char word[])
{
    Main_node *temp = *head;
    while(temp != NULL)
    {
        if(strcmp(temp->word ,word) == 0)
        {
            Sub_node *temp1 = temp->sub_link;
            while(temp1->link != NULL)
            {
                temp1 = temp1->link;
            }
            temp1->link = create_subnode(f_name);
            temp->file_count += 1;
        }
        temp = temp->link;
    }
    return 1;
}
