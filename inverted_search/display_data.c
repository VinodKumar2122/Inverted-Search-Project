#include"invert.h"

void display_data_base(hash_t *arr)
{
   //printf("display\n");  
  printf("Index     Word            Filecount    Filename     Wordcount\n");
  printf("\n");
   for(int i = 0; i < MAX_SIZE; i++)
   {
       if(arr[i].link != NULL)
       {
          Main_node *temp = (arr[i].link);
          while(temp != NULL)
          {
            printf("%-10d",i);        
            printf("%-15s %-13d",temp->word,temp->file_count);
            Sub_node *temp1 = temp->sub_link;
            while(temp1 != NULL)
            {
                printf("%-12s %-10d ",temp1->file_name,temp1->word_count);
                temp1 = temp1->link;
            }
            temp = temp->link;
            printf("\n");
          }
       }
   }
}
