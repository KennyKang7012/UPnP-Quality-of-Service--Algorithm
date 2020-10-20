#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
   char times[10];
   char count[10];
} Item;

int main()
{
    FILE *fp1, *fp2;
    Item  *vlist;

    fp1 = fopen("Service.txt","r");
    if(fp1 == NULL)
    {    
         printf("fp1檔案開啟失敗\n");
    }
    
	fp2 = fopen("Service1.txt","a+");
    if(fp2 == NULL)
    {    
         printf("fp2檔案開啟失敗\n");
    }
	
    vlist = (Item *) malloc(sizeof(Item));
	
    while(fscanf(fp1, "%s\t\t%s\n",&vlist->times,&vlist->count) != EOF) 
    {	
		if(strcmp(vlist->times," ") == 0 && strcmp(vlist->count," ") == 0)
			 continue;
        printf("%s\t\t%s\n",vlist-> times,vlist->count);
        fprintf(fp2,"%s\t\t%s\n",vlist-> times,vlist->count);
		vlist = (Item *) malloc(sizeof(Item));
    }
	
    fclose(fp1);
    fclose(fp2);
    free(vlist);
    system("pause");
    return 0;
}
