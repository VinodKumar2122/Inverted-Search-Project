#include "invert.h"

int main(int argc, char *argv[])
{
    Slist *head = NULL;
   int a =  read_validate(argc,argv,&head);    //calling the functions
   if(a == 0)
   {
    return 0;
   }

   print_list(head);
    
    hash_t arr[MAX_SIZE];
    create_hash(arr,MAX_SIZE);
  

    int b = 0,u = 0,c = 0;
    int o;
    
    while(1)
    {
        printf("Select your option from given options:\n");

	//options for selection
        printf("1.Create data base\n2.Display Data Base \n3.Search Data\n4.Save Data Base\n5.Update Data Base\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&o);
        switch(o)
        {
            case 1:
            if(b == 0)
            {
            b = create_data_base(arr,head);
            if(b == 1)
            printf("INFO : Database is successfully created\n");
           // printf("\n");
            u = 1;
            }
            else
            printf("INFO : Database is already created\n");
            printf("\n");

            break;
            case 2:
            display_data_base(arr);
            printf("\n");
            break;
            case 3:
            b = search_data(arr);
            if(b == 0)
            {
                printf("INFO : Word is not found in the database\n");
                printf("\n");
            }
            break;
            case 4:
            b = save_data(arr);
            if(b != 0)
            {
                printf("INFO : Database saved successfully\n");
                printf("\n");
            }
            else
            printf("\n");
            break;
            case 5:
            if(u == 0)
            {
                 
                 if(c == 0)
                 {
                    c = update_data(arr,&head);
                    if(c != 0)
                    {
                    printf("INFO : Database is updated successfully\n");
                    printf("\n");
                    print_list(head);
                    }
                 }
                 else
                 {
                    printf("INFO : Database is already updated\n");
                    printf("\n");
                 }
            }
            else
            printf("INFO : Database is already created, So update is not possible\n");
            printf("\n");
            break;
            case 6:
            return 0;
            default :
            printf("Invalid Input:-->>> please Try again...\n");
        }

    }

    return 0;
}

int read_validate(int argc, char *argv[],Slist **head)
{
    int b = 0;
    if(argc < 2)
    {
        printf("INFO : Insufficient arguments\nplease give atleast two arguments\n");
        printf("\n");
        printf("arguments should be like a.out <txt file> <txt file> <txt file>\n");
        printf("\n");
        return 0;
    }
    else
    {
        for(int i = 1; i < argc; i++)
        {
            char *c = strstr(argv[i],".txt");
            if( c == NULL || strcmp(c,".txt") != 0)
            {
                printf("INFO : %s -> This file is not a .txt file \n",argv[i]);
                printf("\n");
                continue;
            }
            FILE *f = fopen(argv[i],"r");
            if(f == NULL)
            {
                printf("INFO : %s-> file is not present \n",argv[i]);
                printf("\n");
                continue;
            }
            else
            {
                fseek(f,0,SEEK_END);
                int a = ftell(f);
                if(a == 0)
                {
                  printf("INFO : %s -> This file is empty \n",argv[i]);
                  printf("\n");
                }
                else
                {
                 int a = insert_last(head,argv[i]);
                 if ( a == 1)
                 {
                    printf("INFO : Successfull: inserting file name %s into file linked list \n",argv[i]);
                    printf("\n");
                 }
                 else
                 {
                    printf("INFO : %s -> This file is repeated, so it will not store into the sll\n",argv[i]);
                    printf("\n");
                 }
                }
            }
            fclose(f);
        }
        return 1;

    }
    
}




void print_list(Slist *head)
{
	if (head == NULL)
	{
		printf("INFO : Files are not there\n");
        printf("Create database is not possible\n");
        printf("->NULL\n");
	}
    else
    {
	    while (head)		
	    {
		    printf("%s -> ", head -> s);
		    head = head -> link;
	    }

	    printf("NULL\n");
        printf("\n");
    }
}


int insert_last(Slist **head, char *s)
{
    Slist *new = malloc(sizeof(Slist));
    if(new == NULL)
    return 0;
    strcpy(new->s,s);
    new->link = NULL;
    if(*head == NULL)
    {
        *head = new;
        return 1;
    }
    Slist *temp = *head;
    while(temp->link != NULL)
    {
        if(strcmp(temp->s,s) == 0)
        return 0;
        temp = temp->link;
    }
    if(strcmp(temp->s,s) == 0)
    return 0;
    temp->link = new;
    return 1;
}





void create_hash(hash_t *HT, int size)
{
    for(int i = 0; i < size; i++)
    {
        HT[i].index = i;
        HT[i].link = NULL;
    }
}
