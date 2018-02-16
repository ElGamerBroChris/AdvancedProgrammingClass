#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
void NoOfCombinations(int *total,int target,int sum)
{
    sum+=1;
    if(sum==target)
    {
        *total=*total+1;
    }
    else if(sum<target)
    {
        NoOfCombinations(total,target,sum);
    }
    sum-=1;
    
    sum+=2;
    if(sum==target)
    {
        *total=*total+1;
    }
    else if(sum<target)
    {
        NoOfCombinations(total,target,sum);
    }
    sum-=2;
    
    sum+=3;
    if(sum==target)
    {
        *total=*total+1;
    }
    else if(sum<target)
    {
        NoOfCombinations(total,target,sum);
    }
    sum-=3;
}
int main(){
    int s,total;
    scanf("%d",&s);
    for(int a0 = 0; a0 < s; a0++)
    {
        int n;
        total=0;
        scanf("%d",&n);
        NoOfCombinations(&total,n,0);
        printf("%d \n",total);
    }
    return 0;
}