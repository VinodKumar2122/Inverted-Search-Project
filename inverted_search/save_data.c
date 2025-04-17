#include"invert.h"


int save_data(hash_t *arr)
{
  char f_name[15];
  printf("Enter the file name to save database: ");
  scanf("%s",f_name);
  char *c = strstr(f_name,".txt");
  if(c == NULL || strcmp(c,".txt") != 0)
  {
    printf("INFO : %s -> This file is not a .txt file\n",f_name);
    return 0;
  } 
  FILE *f = fopen("data.txt","w");
  if(f == NULL)
  {
    printf("file not opened \n");
    return 0;
  }
   for(int i = 0; i < MAX_SIZE; i++)
   {
       if(arr[i].link != NULL)
       {
          Main_node *temp = (arr[i].link);
          while(temp != NULL)
          {
            fprintf(f,"#%d;",i);
            fprintf(f,"%s;%d;",temp->word,temp->file_count);
            Sub_node *temp1 = temp->sub_link;
            while(temp1 != NULL)
            {
                fprintf(f,"%s;%d;",temp1->file_name,temp1->word_count);
                temp1 = temp1->link;
            }
            temp = temp->link;
             fprintf(f,"#\n");
          }
       }
   }
   fclose(f);
   return 1;
}
