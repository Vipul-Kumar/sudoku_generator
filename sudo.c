/*sudoku puzzle---
this is free for anyone to use :) */

#include<stdio.h>
int board[9][9];
int i,j,k,m,n,valid,error_code;
int r;

void showboard()
{
	int i,j;
		for(i=0;i<9;i++)
		{
		for(j=0;j<9;j++)
		{
			printf("   %d",board[i][j]);
			if(j==2||j==5)
				printf("   |");

		}
		printf("\n\n");
		if(i==2||i==5)
		{
			for(j=0;j<9;j++)
		{
			printf("   -");
			if(j==2||j==5)
				printf("   -");

		}
	        printf("\n\n");
		}
		}
}
int validity(int r,int i,int j)
{
			        error_code=0;
			        valid=1;
				//int r = ( rand() % 9 ) + 1;
				for(k=0;k<9;k++)
				{
					if((board[i][k]==r)||(board[k][j]==r))
					{
						valid=0;
							error_code=1;
						break;
					}
				}
					if(i<=2&&j<=2)
					{
						for(m=0;m<3;m++)
							for(n=0;n<3;n++)
							{
							if(board[m][n]==r)
							{
								valid=0;
								error_code=2;
								break;
							}
							}
					}
					else if(i<=2&&j>2&&j<6)
					{
						for(m=0;m<3;m++)
							for(n=3;n<6;n++)
							{
							if(board[m][n]==r)
							{
								valid=0;
								error_code=3;
								break;
							}
							}
					}
					else if(i<=2&&j>5&&j<9)
					{
						for(m=0;m<3;m++)
							for(n=6;n<9;n++)
							{
							if(board[m][n]==r)
							{
								valid=0;
								error_code=4;
								break;
							}
							}
					}
						else if(i>2&&i<6&&j<3)
					{
						for(m=3;m<6;m++)
							for(n=0;n<3;n++)
							{
							if(board[m][n]==r)
							{
								valid=0;
								error_code=5;
								break;
							}
							}
					}
				                 else if(i>2&&i<6&&j>2&&j<6)
					{
						for(m=3;m<6;m++)
							for(n=3;n<6;n++)
							{
							if(board[m][n]==r)
							{
								valid=0;
								error_code=6;
								break;
							}
							}
					}         
						     else if(i>2&&i<6&&j>5&&j<9)
					{
						for(m=3;m<6;m++)
							for(n=6;n<9;n++)
							{
							if(board[m][n]==r)
							{
								valid=0;
								error_code=7;
								break;
							}
							}
					}         
						     else if(i>5&&j<3)
					{
						for(m=6;m<9;m++)
							for(n=0;n<3;n++)
							{
							if(board[m][n]==r)
							{
								valid=0;
								error_code=8;
								break;
							}
							}
					}
					         else if(i>5&&j>2&&j<6)
					{
						for(m=6;m<9;m++)
							for(n=3;n<6;n++)
							{
							if(board[m][n]==r)
							{
								valid=0;
								error_code=9;
								break;
							}
							}
					}
					         else if(i>5&&j>5&&j<9)
					{
						for(m=6;m<9;m++)
							for(n=6;n<9;n++)
							{
							if(board[m][n]==r)
							{
								valid=0;
								error_code=10;
								break;
							}
							}
     					}

			/*	printf("Wanna see the results press any key");
				scanf("%d",&n);
	   	        	printf("\nvalue of j=%d",j);
				printf("\nvalue of r=%d",r);
				printf("\nvalid=%d",valid);
				printf("\nvalue of error_code=%d",error_code);*/
			
	return valid;

}
int deadlock(int i,int j)
{ 
 	int flag=0,val,x;
        printf("checking whether a deadlock exists or not");
	for(x=1;x<10;x++)
	{
	val=validity(x,i,j);
	flag=flag+val;
	}
	if(flag==0)
		return 1;
	else
		return 0;
}

void main()
{
//	int i,j,k,m,n,valid,error_code;
        for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			board[i][j]=0;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			
			if(!deadlock(i,j))
			{
				valid=0;
				while(valid==0)
				{
					int r = ( rand() % 9 ) + 1;
					valid=validity(r,i,j);
					board[i][j]=r;
				}
					int start;
			/*	printf("Enter the starting number");
				scanf("%d",&start);
				showboard();*/
			}
			else 
			{
				int l=j;
				for(l=j-1;l>=0;l--)
				{
					int temp;
					temp=board[i][l];
					board[i][l]=0;	
					if(validity(temp,i,j))
					{
						board[i][j]=temp;
						if(deadlock(i,l))
						{
						board[i][l]=temp;
						board[i][j]=0;
						continue;
						}


						while(!deadlock(i,l))
						{
						valid=0;
						
						while(valid==0)
						{
								int r = ( rand() % 9 ) + 1;
								valid=validity(r,i,l);
								board[i][l]=r;
						}
						
						break;
						}
						break;
					}
					
					else
					{
						board[i][l]=temp;
						board[i][j]=0;
					}
				}
			}
			
			
						
					
				
		
		}
	}
	printf("\n");
	showboard();
}

