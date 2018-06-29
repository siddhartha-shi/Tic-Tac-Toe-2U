#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include<string>
using namespace std;
//int draw_check;//draw check variable
string sid,sid2;
   //static int tic[3][3]={11,12,13,4,5,6,7,8,9};

void disp_tic(int tic[3][3])
{
    char matrix[3][3];
  int t,i,j;

for(i=0;i<3;i++)//print the output
    {
        for(j=0;j<3;j++)
        {
            if(tic[i][j]==0)
            matrix[i][j]='O';
            else if(tic[i][j]==1)
                matrix[i][j]='X';
                else
            matrix[i][j]=' ';
        }
    }

  for(t=0; t<3; t++) {
    printf(" %c | %c | %c ",matrix[t][0],
            matrix[t][1], matrix [t][2]);
    if(t!=2) printf("\n---|---|---\n");
  }
  printf("\n");
}


int check_tic(int aray[3][3])//check if the input if it is match
    {
        int row_add,colom_add,rr = 0,draw_check;
        for(int i=0;i<3;i++)//check adding row and colum
            {
                row_add=0,colom_add=0;
                for(int j=0;j<3;j++)
                    {
                        row_add+=aray[i][j];
                        colom_add+=aray[j][i];
                    }
        if((row_add==0)||(row_add==3))//check row wise
            {
                if(row_add==0)
                    cout<<"congrats \""<<sid<<"\" Row!";
                else
                    cout<<"congrats \""<<sid2<<"\" Row!";
                rr=1;
                break;
            }

           else if((colom_add==0)||(colom_add==3))//check colum wise
            {
                if(colom_add==0)
                    cout<<"congrats \""<<sid<<"\" Colo!";
                else
                    cout<<"congrats \""<<sid2<<"\" Colom!";
                rr=1;
                break;
            }

            else if((aray[0][0]+aray[1][1]+aray[2][2]==3)||(aray[0][0]+aray[1][1]+aray[2][2]==0))//check diagonaly
            {
                if(aray[0][0]+aray[1][1]+aray[2][2]==0)
                    cout<<"congrats \""<<sid<<"\" diagonaly!";
                else
                    cout<<"congrats \""<<sid2<<"\" diagonaly!";
            rr=1;
            break;
            }

            else if((aray[0][2]+aray[1][1]+aray[2][0]==3)||(aray[0][2]+aray[1][1]+aray[2][0]==0))//check diagonaly
            {
                if(aray[0][2]+aray[1][1]+aray[2][0]==0)
                    cout<<"congrats \""<<sid<<"\" Diagonaly!";
                else
                    cout<<"congrats \""<<sid2<<"\" Diagonaly!";
            rr=1;
            break;
            } else
                draw_check=2;

            }
            if(rr==1)
                return 1;
            else
               return draw_check;
    }

int main()
    {
        int u1,u2,row,colum,i,j,p;
        int m,n,ran,check_return;
        //int tic[3][3]={11,12,13,4,5,6,7,8,9};
        char ch;


        srand(time(0));
        ran=rand()%9+1;
    cout<<"Enter First Player Name: ";
    cin>>sid;
    cout<<"Enter Second Player Name: ";
    cin>>sid2;
   do
    {
        int tic[3][3]={11,12,13,4,5,6,7,8,9};
/*
        cout<<"                                      1   /  2  /  3 "<<endl;
        cout<<"                                    -----------------"<<endl;
        cout<<"                                     4  /  5  /  6   "<<endl;
        cout<<"                                    -----------------"<<endl;
        cout<<"                                    7 /  8  /  9   "<<endl;
*/
        for(p=1;p<=9;p++)
            {
                if(ran%2==0)//check if the "<<sid<<" or 2 give the input first
                    {
                        m:
        /**/
                cout<<endl;
        cout<<"                                      1   /  2  /  3 "<<endl;
        cout<<"                                    -----------------"<<endl;
        cout<<"                                     4  /  5  /  6   "<<endl;
        cout<<"                                    -----------------"<<endl;
        cout<<"                                    7 /  8  /  9   "<<endl;
        /**/

                        cout<<"\n"<<sid<<" <1-9>";
                        cin>>u1;
                        if(u1<=0||u1>=10)
                        {
                            cout<<"Please enter a veiled position!";
                            goto m;
                        }
                          row=(u1-1)/3;
                          colum=(u1-1)%3;

                        if(tic[row][colum]!=0 && tic[row][colum]!=1)//storage the input
                                tic[row][colum]=0;
                        else
                            {
                                cout<<"enter a empty place! \n";
                                goto m;
                            }
                    }
                else
                    {
                        n:
                /**/
        cout<<endl;
        cout<<"                                      1   /  2  /  3 "<<endl;
        cout<<"                                    -----------------"<<endl;
        cout<<"                                     4  /  5  /  6   "<<endl;
        cout<<"                                    -----------------"<<endl;
        cout<<"                                    7 /  8  /  9   "<<endl;
            /**/

                        cout<<"\n"<<sid2<<" <1-9>";
                        cin>>u2;
                        if(u2<=0||u2>=10)
                        {
                            cout<<"Please enter a veiled position!";
                            goto n;
                        }
                        row=(u2-1)/3;
                        colum=(u2-1)%3;

                        if(tic[row][colum]!=0 && tic[row][colum]!=1)//storage the input
                                tic[row][colum]=1;
                        else
                            {
                                cout<<"enter a empty place! ";
                                goto n;
                            }
                    }
            cout<<endl;
            disp_tic(tic);
                ran++;//user sequence increase
            check_return=check_tic(tic);
                if(check_return==1)//check tic tac condition
                    break;
            }

        if(check_return==2)
            cout<<"Match Draw!";
    cout<<"\n\nDo you want to play again?(Y/y for YES) ";
    cin>>ch;
  }while(ch=='y'||ch=='Y');
        return 0;
    }
