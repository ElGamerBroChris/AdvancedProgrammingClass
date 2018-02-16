#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n,i; 
    scanf("%d",&n);
    int *a = malloc(sizeof(int) * n);
    int *b=calloc(n,sizeof(int));
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    for(i=0;i<n;i++)
    {
        b[a[i]]++;
    }
    for(i=0;i<101;i++)
        if(b[i]==1)
            printf("%d",i);
    return 0;
}