                                                                                                                                                                                                                                                                                                                                                                                                                                                                       disk.c *                                                                                                                                                                                                                                                                                                                                                                                                                                                                               #include<stdio.h>
int getseektime(int a,int b)
{
   if(a>b)
        return a-b;
   return b-a;
}
void sort(int temparr[],int n)
{ int i,j,temp;
   for(i=0;i<n;i++)
        for(j=0;j<n-i-1;j++)
                if(temparr[j]>temparr[j+1])
                {
                temp=temparr[j];
                temparr[j]=temparr[j+1];
                temparr[j+1]=temp;
                }
}
void copy(int arr[],int temp[],int n)
{
   for(int i=0;i<n;i++)
        temp[i]=arr[i];
}
int nextindex(int p,int arr[],int n)
{
        for(int i=0;i<n;i++)
        {
           if(arr[i]>=p)
                return i;
        }
}
void fcfs(int n,int max,int hp,int arr[])
{
   int seektime=0;
   for(int i=0;i<n;i++)
   {
   seektime+=getseektime(hp,arr[i]);
   if(i!=n-1)
   printf("%d=>",arr[i]);
   else
   printf("%d",arr[i]);
   hp=arr[i];
   }
   printf("\nSEEKTIME= %d\n",seektime);
}
void scan(int n,int max,int hp,int arr[])
{
   int i,seektime=0, temp[103];
   copy(arr,temp,n);
   sort(temp,n);
   seektime+=getseektime(hp,max);
   printf("%d=>",hp);
   seektime+=getseektime(max,temp[0]);
   int index=nextindex(hp,temp,n);
   for(i=index;i<n;i++)
   {
        if(i!=n-1)
                printf("%d=>",temp[i]);
        else
                printf("%d\n",temp[i]);
     hp=temp[i];
   }
  // seektime+=getseektime(max,temp[0]);
   for(i=index-1;i>=0;i--)
   {
        if(i!=0)
           printf("%d=>",temp[i]);
        else
           printf("%d",temp[i]);
    hp=temp[i];
   }

  printf("\nSEEKTIME= %d\n",seektime);
}
void cscan(int n,int max,int hp,int arr[])
{
    int i,seektime=0, temp[103];
   copy(arr,temp,n);
   sort(temp,n);
   seektime+=getseektime(hp,max);
   int index=nextindex(hp,temp,n);
   printf("%d=>",hp);
   for(i=index;i<n;i++)
   {
     if(i!=n-1)
        {
           printf("%d=>",temp[i]);
        }
      else
        printf("%d",temp[i]);
   hp=temp[i];
   }
   seektime+=getseektime(max,0);
   for(i=0;i<index;i++)
   {
        if(i!=index-1)
        {
           printf("%d=>",temp[i]);
        }
      else
        printf("%d",temp[i]);
   hp=temp[i];
   }
   seektime+=getseektime(0,temp[index-1]);
    printf("\nSEEKTIME= %d\n",seektime);
}
void main()
{
int i,n,hp,max,arr[10];
printf("Enter the number of requests: ");
scanf("%d",&n);
printf("Enter max : ");
scanf("%d",&max);
printf("Enter the current head position :");
scanf("%d",&hp);
printf("Enter the values :");
for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
fcfs(n,max,hp,arr);
scan(n,max,hp,arr);
cscan(n,max,hp,arr);
}
