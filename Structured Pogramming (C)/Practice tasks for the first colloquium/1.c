/*Благ број е број што е составен само од парни цифри (0, 2, 4, 6, 8). Во зададен опсег (почетокот m и крајот на опегот n се цели броеви чија вредност се внесува од тастатура), да се најде и испечати најмалиот „благ број“. Ако не постои таков број, да се испечати NE. */
#include <stdio.h> 
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=m;i<=n;i++)
    {
        int blag=i;
        while(blag!=0)
        {
            if(blag%10%2!=0)
            {
                break;
            }
            blag/=10;
        }
        if(blag==0)
        {
            printf("%d", i);
            break;
        }
        else if(i==n)
        {
            printf("NE");
        }
        
    }
    return 0;
}