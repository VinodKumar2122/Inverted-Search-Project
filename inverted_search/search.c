#include"invert.h"



int search_data(hash_t *arr)
{
  char s[40];
  int flag = 0;
  int a;
  printf("Please enter the word to search in database: ");
  scanf("%s",s);
  a = get_index(s);
  if(a < 0 || a > 25)
  a = 26;
  if(arr[a].link != NULL)
  {
    Main_node *m_temp = (arr[a].link);
    while(m_temp != NULL)
    {
     if(strcmp(m_temp->word,s) == 0)
     {
      flag = 1;
      printf("\n");
       printf("Word %s is present in %d files\n",m_temp->word,m_temp->file_count);
       Sub_node *temp = m_temp->sub_link;
       while(temp!=NULL)
       {
          printf("In file: %-12s %-5d times\n",temp->file_name,temp->word_count);
          printf("\n");
          temp = temp->link;
       }
     }
     m_temp = m_temp->link;
    }
  }
  else
  {
    return 0;
  }
  if(flag == 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
