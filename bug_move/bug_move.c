#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int ibugmove[8]={-1,0,1,1,1,0,-1,-1};
int jbugmove[8]={1,1,1,0,-1,-1,-1,0};
int m,n,a,b;
void move_bug(int grid[m][n],int k)
{
    int c,d;
    c=a+ibugmove[k];
    d=b+jbugmove[k];
    if(c<m && c>=0 && d>=0 && d<n)
    {
        grid[c][d]++;
        a=c;
        b=d;
    }
}
int check_visited(int grid[m][n])
{
    int flag=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }

}
void print_grid(grid[m][n])
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int k,l;
    printf("Enter the dimensions of the plane: \n");
    scanf("%d %d\n",&m,&n);
    printf("\n\nEnter starting point:\n");
    scanf("%d %d",&a,&b);
    int grid[40][40]={0};
    srand(time(0));
    grid[0][0]=1;
    for(l=0;l<50000;l++)
    {
        k=rand()%8;
        move_bug(grid,k);
        if(check_visited(grid))
        {
            print_grid(grid);
            break;
        }
    }
    printf("\n\n\n %d",l);
}
