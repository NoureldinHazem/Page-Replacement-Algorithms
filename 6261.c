#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10000

int pages = 0;
char policy[10];
int number[SIZE];
int numbers;

void method()
{
    scanf("%d",&pages);
    scanf("%s",policy);
    int i;
    int temp;
    numbers=0;
    for(i=0;i<SIZE;i++)
    {
        scanf("%d",&temp);
        if (temp < 0)
        {
            break;
        }
        number[i]=temp;
        numbers=numbers+1;
    }
}

int fifo()
{
    int temp[pages];
    for (int i=0;i<pages;i++)
    {
        temp[i]=-1;
    }
    int count=0;
    int flag;
    int position=0;
    int check=0;
    for(int j=0;j<numbers;j++)
    {
        position=position%pages;
        flag=0;
        for(int k=0;k<pages;k++)
        {
            if (temp[k]==number[j])
            {   
                flag=1;
                break;
            }
        }
        if (flag==1)
        {
            if (number[j]<10)
            {
               printf("0%d     ",number[j]);
            }
            else{
                    printf("%d     ",number[j]);
                }
            
             }
        else{
            if (check<pages)
            {
                if (number[j]<10)
            {
               printf("0%d     ",number[j]);
            }
            else{
                    printf("%d     ",number[j]);
                }
            }
            else{
            if (number[j]<10)
                {
               printf("0%d F   ",number[j]);
                }
            else    {
                    printf("%d F   ",number[j]);
                    }
            }
            count=count+1;
            temp[position]=number[j];
            position=position+1;
            check =check +1;
            
        }
          for (int i = 0; i < pages; i++)
          {
              if(temp[i]<0)
              {
                  continue;
              }
              if (temp[i]<10){
                  printf("0%d ",temp[i]);
              }
              else  {
                    printf("%d ",temp[i]);
                    }
          }
            printf("\n");


    }
    
    return count-pages; 
}


int lru()
{
    int temp[pages];
    int least[pages];
    for (int i=0;i<pages;i++)
    {
        temp[i]=-1;
        least[i]=i-pages;
    }
    int count=0;
    int flag;
    int position=0;
    int check=0;
    int index=0;
    for(int j=0;j<numbers;j++)
    {
        flag=0;
        index=0;
        for(int k=0;k<pages;k++)
        {
            if (temp[k]==number[j])
            {   
                least[k]=j;
                flag=1;
                break;
            }
        }
        if (flag==1)
        {
            if (number[j]<10)
            {
               printf("0%d     ",number[j]);
            }
            else{
                    printf("%d     ",number[j]);
                }
            
             }
        else{
            if (check<pages)
            {
                if (number[j]<10)
            {
               printf("0%d     ",number[j]);
            }
            else{
                    printf("%d     ",number[j]);
                }
            }
            else{
            if (number[j]<10)
                {
               printf("0%d F   ",number[j]);
                }
            else    {
                    printf("%d F   ",number[j]);
                    }
            }
            for (int i = 0; i < pages; i++)
            {
                if (least[i]<least[index])
                {
                    index=i;
                }  
            }
            least[index]=j;
            position=index;
            count=count+1;
            temp[position]=number[j];
            position=position+1;
            check =check +1;
           }
          for (int i = 0; i < pages; i++)
          {
              if(temp[i]<0)
              {
                  continue;
              }
              if (temp[i]<10){
                  printf("0%d ",temp[i]);
              }
              else  {
                    printf("%d ",temp[i]);
                    }
          }
            printf("\n");
    }
    
    return count-pages; 
}

int optimal()
{
    int temp[pages];
    int optimal[pages];
    int flag=0;
    int found1=0;
    int found2=0;
    int next=0;
    int check=0;
    int index=0;
    int count = 0;
    for (int i = 0; i < pages; i++)
    {
        temp[i]=-1;
        optimal[i]=1000000-i;
    }
    for (int j = 0; j < numbers; j++)
    {
        flag=0;
        found1=0;
        found2=0;
        next=0;
        index=0;
        for (int i = 0; i < pages; i++)
        {
            if (temp[i]== number[j])
            {
                flag=1;
                for (int k = j+1; k < numbers; k++)
                {
                    if (number[j]==number[k])
                    {
                        found1=1;
                        next=k-j;
                        break;
                    }
                }
                if (found1==0)
                {
                    next=numbers-j;
                }
                optimal[i]=next;
                break;
            }
        }
        if (flag==1)
        {
            if (number[j]<10)
            {
               printf("0%d     ",number[j]);
            }
            else{
                    printf("%d     ",number[j]);
                }
        }
        else
        {
            if (check<pages)
            {
                if (number[j]<10)
            {
               printf("0%d     ",number[j]);
            }
            else{
                    printf("%d     ",number[j]);
                }
            }
            else{
            if (number[j]<10)
                {
               printf("0%d F   ",number[j]);
                }
            else    {
                    printf("%d F   ",number[j]);
                    }
            }
            for (int i = 0; i < pages; i++)
            {
                if (optimal[i]>optimal[index])
                {
                    index=i;
                }
                
            }
            for (int k = j+1 ; k < numbers; k++)
            {
                if (number[j]==number[k])
                {
                    found2=1;
                    next=j-k;
                    break;
                }
                if (found2==0)
                {
                    next=numbers-j;
                }
            }
            check = check+1;
            temp[index]=number[j];
            optimal[index]=next;
            count =count+1;  
        }
        for (int i = 0; i < pages; i++)
          {
              if(temp[i]<0)
              {
                  continue;
              }
              if (temp[i]<10){
                  printf("0%d ",temp[i]);
              }
              else  {
                    printf("%d ",temp[i]);
                    }
                    optimal[i]=optimal[i]-1;
          }
            printf("\n");
        
    }
    return count-pages; 
}

int clock()
{
    int count=0;
    int position=0;
    int temp[pages];
    int use[pages];
    int flag=0;
    int check=0;
    int index=0;
    int found=0;
    int cycle=0;
    for (int i = 0; i < pages; i++)
    {
        temp[i]=-1;
        use[i]=0;
    }
    for (int j = 0; j < numbers ; j++)
    {
        flag=0;
        index=0;
        found=0;
        cycle=0;
        for (int i = 0; i < pages; i++)
        {
            if (temp[i]==number[j])
            {
                use[i]=1;
                flag=1;
                break;
            }
        }
        if (flag==1)
        {
            if (number[j]<10)
            {
               printf("0%d     ",number[j]);
            }
            else{
                    printf("%d     ",number[j]);
                } 
        }
        else
        {
            if (check<pages)
            {
                if (number[j]<10)
            {
               printf("0%d     ",number[j]);
            }
            else{
                    printf("%d     ",number[j]);
                }
            }
            else{
            if (number[j]<10)
                {
               printf("0%d F   ",number[j]);
                }
            else    {
                    printf("%d F   ",number[j]);
                    }
            }
            for (int i = position; cycle < pages; i++)
            {
                i=i%pages;
                if (use[i]==1)
                {
                    use[i]=0;
                }else{
                    found=1;
                    index=i;
                    break;
                     }
                cycle=cycle+1; 
            }
            if (found==1)
            {
                position=index;
            }
                temp[position]=number[j];
                use[position]=1;
                check=check+1;
                position=position+1;
                position=position%pages;
                count=count+1;
        }
        for (int i = 0; i < pages; i++)
          {
              if(temp[i]<0)
              {
                  continue;
              }
              if (temp[i]<10){
                  printf("0%d ",temp[i]);
              }
              else  {
                    printf("%d ",temp[i]);
                    }
          }
            printf("\n");
    }
    return count-pages;
}

int main()
{
    int faults =0;
    method();
    printf("Replacement Policy = %s\n",policy);
    printf("-------------------------------------\n");
    printf("Page   Content of Frames\n");
    printf("----   -----------------\n");
    
    if (strcasecmp(policy,"fifo")==0)
    {
        faults=fifo();
    }
    else if (strcasecmp(policy,"CLOCK")==0)
    {
        faults=clock();
    }
    else if (strcasecmp(policy,"LRU")==0)
    {
       faults=lru();
    }
    else if (strcasecmp(policy,"OPTIMAL")==0)
    {
        faults=optimal();
    }
    printf("-------------------------------------\n");
    printf("Number of page faults = %d\n",faults);
    

return 0;
}