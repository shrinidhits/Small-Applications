#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int ikmove[8]={-2,-1,1,2,2,1,-1,-2};
int jkmove[8]={1,2,2,1,-1,-2,-2,-1};
int board[8][8],nexti[8],nextj[8],exits[8];
int minimum,npos,a,b;
int number_adj(int board[8][8],int i,int j)
{
    int count=0;
    for(int n=0;n<8;n++)
    {
        int posi=i+ikmove[n];
        int posj=j+jkmove[n];
        if(posi<8 && posi>=0 && posj<8 && posj>=0)
        {
            if(board[posi][posj]==-1)
            {
                count++;
            }
        }
    }
    return count;
}
void print_board(int board[8][8])
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout<<board[i][j]<<"   ";
        }
        cout<<"\n"<<endl;
    }
}
void create_board()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            board[i][j]=-1;
        }
    }
}
int minimum_indx(int a[])
{
    int minimum1=0;
    for(int i=1;i<npos;i++)
    {
        if(a[minimum1]>a[i])
        {
            minimum1=i;
        }
    }
    return minimum1;
}
int main()
{
    srand(time(NULL));
    create_board();
    a=rand()%8;
    b=rand()%8;
    cout<<a<<" "<<b<<endl;
    board[a][b]=0;
    for(int m=1;m<=63;m++)
    {
        npos=number_adj(board,a,b);
        int g=0;
        if(npos==0)
        {
            print_board(board);
            cout<<"\n"<<endl;
            break;
        }
        for(int n=0;n<8;n++)
        {
            int c=a+ikmove[n];
            int d=b+jkmove[n];
            if(c<8 && c>=0 && d<8 && d>=0 && board[c][d]==-1)
            {
                nexti[g]=c;
                nextj[g]=d;
                g++;
            }
        }
        if(npos==1)
        {
            minimum=0;
            a=nexti[minimum];
            b=nextj[minimum];
            board[a][b]=m;
        }
        else
        {                    
            for(int l=0;l<npos;l++)
            {
                exits[l]=number_adj(board,nexti[l],nextj[l]);
            }
            minimum=minimum_indx(exits);
            a=nexti[minimum];
            b=nextj[minimum];
            board[a][b]=m;
        }
    }                    
    print_board(board);
}