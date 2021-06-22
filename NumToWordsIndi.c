#include<stdio.h>
#include<string.h>
const char *arr1[]={"One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine "};
const char *arr2[]={"Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
const char *arr3[]={"Ten ","Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
const char *units[]={"Units ", "Thousand ","Lakh ","Crore ","Arab","Kharab"};


void function2(int u,int t,int h,int unit)
{ 
    char words[500]="";
    char str[60]="";
    int flag=0;
    if(u==0)
        if(t==0)
            if(h==0)
            {
                strcat(words,"");
                flag=1;
            }
            else
            {
                strcpy(str,arr1[h-1]);
                strcat(str,"hundred ");
                strcat(words,str);
            }
        else
            if(h==0)
                strcpy(words,arr3[t-1]);
            else
            {
                strcpy(str,arr1[h-1]);
                strcat(str,"hundred and ");
                strcat(str,arr3[t-1]);
                strcpy(words,str);
            }
    else
        if(t==0)
            if(h==0)
                strcat(words,arr1[u-1]);
            else
            {
                strcpy(str,arr1[h-1]);
                strcat(str,"hundred and ");
                strcat(str,arr1[u-1]);
                strcat(words,str);
            }
        else
            if(t==1)
                if(h==0)
                    strcat(words,arr2[u-1]);
                else
                {
                    strcpy(str,arr1[h-1]);
                    strcat(str,"hundred and ");
                    strcat(str,arr2[u-1]);
                    strcat(words,str);
                }
            else
                if(h==0)
                {
                    strcat(str,arr3[t-1]);
                    strcat(str,arr1[u-1]);
                    strcpy(words,str);
                }
                else                        
                {
                    strcpy(str,arr1[h-1]);
                    strcat(str,"hundred and ");
                    strcat(str,arr3[t-1]);
                    strcat(str,arr1[u-1]);
                    strcpy(words,str);
                }   
if(flag!=1) strcat(words,units[unit]); 
       
printf("%s",words);
}

void function3(int u,int t,int unit)
{
    char words[1800]="";
    char str[60]="";
    int flag=0; 
    if(u==0)
        if(t==0)
        {
            strcat(words,"");
            flag=1;
        }
        else
            strcat(words,arr3[t-1]);
        
    else
        if(t==0)
            strcat(words,arr1[u-1]);
        else
            if(t==1)
                strcat(words,arr2[u-1]);
        else
        {
            strcpy(str,arr3[t-1]);
            strcat(str,arr1[u-1]);
            strcat(words,str);
        }
if (flag!=1) strcat(words,units[unit]);
printf("%s",words);
}

void function1(int arr[],int size)
{
	int hd,td,ud,i,j,unit=size-1;     
    for(i=size-1;i>=1;i--)
  {
          ud=arr[i]%10;
          td=arr[i]/10;
          function3(ud,td,unit);
          unit--;
  }
   ud=arr[0]%10;
   hd=arr[0]/100;
   j=arr[0]%100;
   td=j/10;
   function2(ud,td,hd,unit);
}

int main()
{ 
    
    long long int num,max=3875820019684212735;
    int i=0,j,temp[7];
    printf("\nEnter the number: ");
    scanf("%lld",&num);
    
    j=num%1000;
    temp[i]=j;
    i++;
    num=num/1000;
    
    while(num>0)
    {
        j=num%100;
        temp[i]=j;
        i++;
        num=num/100;
    }
    int arr[i];

    for(j=0;j<i;j++) arr[j]=temp[j];
    
    if (num<=max)  function1(arr,i);
    else printf("Number out of range!");
	return 0;
}
