#include<stdio.h>
#include<string.h>
#define NUM 5
int c_replace(char *cache[],char str[][80],char *temp)  
{  
int i;
char *t;
   for(i=0;i<NUM&&cache[i]!=NULL;i++)
        if(strcmp(cache[i],temp)==0)  return 1;          
   if(i<NUM&&cache[i]==NULL) { 
       	strcpy(str[i],temp);
        cache[i]=str[i];
   }
   else{
       	t=cache[0];
        for(i=NUM-2;i>=1;i--)      
            cache[i]=cache[i+1];
        cache[NUM-1]=t;
        strcpy(cache[NUM-1],temp);
    }
    return 0;
}
int main(void)
{   
    char * cache[NUM]={0},str[NUM][80];
    char input[80];
    int i,count=0;
	float hit;
    for(i=0;i<10;i++)
	{
       	gets(input);
        count+=c_replace(cache,str,input);
    }
    hit=(float)count/10;
    for(i=0;i<NUM;i++)
    printf("%s  ",cache[i]);
    printf("hit=%f\n",hit); 
    getchar();
	return 0;
}
