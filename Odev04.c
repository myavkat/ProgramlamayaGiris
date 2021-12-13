#include<stdio.h>
#define arrSize 50
int main(){

    return 0;
}

void toUpper(char src[], char dest[]){
    //97,122
    for (int i = 0; i < arrSize; i++)
    {
        printf("Buyuk harfe cevrilmis dizi : ");
        dest[i]=src[i];
        if(src[i]>=97&&src[i]<=122){
            dest[i]-=32;
        }
        printf("%c", dest[i]);
    }
    
    
}