#include"invert.h"




int update_data(hash_t *arr,Slist **head)
{
  char f_name[10];
  printf("Please enter the file name : ");
  scanf("%s",f_name);
  char *c = strstr(f_name,".txt");
  if(c == NULL || strcmp(c,".txt") != 0)
  {
   printf("INFO : %s -> This file is not a .txt file\n",f_name);
    return 0;
  }
  FILE *f;
  if((f = open_files(f_name)) == NULL)
  return 0;
  char  ch = getc(f),ch1;
  fseek(f,0,SEEK_END);
  int a = ftell(f);
  fseek(f,a-2,SEEK_SET);
  ch1 = getc(f);
  if(ch != '#' || ch1 != '#')
  {
   printf("INFO : %s -> This file is not a data file\n",f_name);
    return 0;
  }
  fseek(f,0,SEEK_SET);
  int file_count,word_count,index;
  char word[100],file_name[12];
  while(fscanf(f,"#%d;%[^;];%d;",&index,word,&file_count) > 0)
  {
    update_create_main(&(arr[index].link),word,file_count);
    for(int i = 0; i < file_count; i++)
    {
      fscanf(f,"%[^;];%d;",file_name,&word_count);
      update_subnode(&(arr[index].link),file_name,word_count,word);
    }
    sl_delete_element(head,file_name);
    fscanf(f,"#\n");
  }
  fclose(f);
  return 1;

}




int update_create_main(Main_node **head,char word[],int file_count)
{
  Main_node *new = malloc(sizeof(Main_node));
  if(new == NULL)
  {
    return 0;
  }
  new->file_count = file_count;
  strcpy(new->word,word);
  new->sub_link = NULL;
  new->link = NULL;
  if(*head == NULL)
  {
    *head = new;
    return 0;
  }
  Main_node *temp = *head;
  while(temp->link != NULL)
  {
    temp = temp->link;
    
  }
  temp->link = new;
}




int update_subnode(Main_node **head,char file_name[],int word_count,char word[])
{
  Sub_node *new = malloc(sizeof(Sub_node));
  if(new == NULL)
  {
    return 0;
  }
  new->word_count = word_count;
  strcpy(new->file_name,file_name);
  new->link = NULL;
  if((*head)->sub_link == NULL)
  {
    (*head)->sub_link= new;
    return 0;
  }
  Sub_node *temp = (*head)->sub_link;
  if((strcmp((*head)->word,word) == 0))
  {
  while(temp->link != NULL)
  {
    temp = temp->link;
  }
  temp->link = new;
  }
  else
  {
    Main_node *temp1 = (*head);
    while(temp1->link != NULL)
    {
      temp1 = temp1->link;
    }
    if(temp1->sub_link == NULL)
    temp1->sub_link = new;
    else
    {
      temp = temp1->sub_link;
      while(temp->link !=  NULL)
      {
        temp = temp->link;
      }
      temp->link = new;
    }
  }
  return 0;
  
}





int sl_delete_element(Slist **head, char f_name[])
{
  
   if(*head == NULL)
   return 0;
   Slist *temp = *head;
   if((strcmp(temp->s,f_name) == 0) && temp == *head)
   {
       *head = (*head)->link;
       free(temp);
       return 1;
   }
   Slist *p = NULL;
   while(temp != NULL)
   {
       if(strcmp(temp->s,f_name) == 0)
       {
           p->link = temp->link;
           free(temp);
           return 1;
       }
       else
       {
           p = temp;
           temp = temp->link;
       }
   }
   return 1;
}


