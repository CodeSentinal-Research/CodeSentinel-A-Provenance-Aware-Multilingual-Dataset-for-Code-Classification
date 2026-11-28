void accept(int X[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&X[i][j]);
		}
	}
}
void display(int X[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		printf("\n[");
		for(j=0;j<3;j++)
		{
			printf(" %d ",X[i][j]);
		}
		printf("]");
	}
}
void add(int X[3][3],int Y[3][3])
{
	int i,j,Z[3][3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			Z[i][j]=X[i][j]+Y[i][j];
		}
	}
	display(Z);
}
void mult(int X[3][3],int Y[3][3])
{
	int i,j,k,sum,XY[3][3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			sum=0;
			for(k=0;k<3;k++)
			{
				sum=sum+X[i][k]*Y[k][j];
			}
			XY[i][j]=sum;
		}
	}
	display(XY);
}
void symmetric(int X[3][3])
{
    int i,j,s;
    for ( i = 0; i < 3; i++)
    {
        s=0;
        for ( j = 0; j < 3; j++)
        {
            if(X[i][j]!=X[j][i])
            {
                s=1;
                break;
            }
        }
        if(s!=0)
        {
            printf("\nGiven matrix is not symmetric\n");
            break;
        }
    }
    if(s==0)
        printf("\nGiven matrix is symmetric\n");
}
void trace(int X[3][3])
{
    int i,j,sum=0;
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            if(i==j)
            sum=sum+X[i][j];
        }
    }
    printf("\nTrace of mtrix =%d\n",sum);
}
void upper(int X[3][3])
{
    int i,j,u;
    for ( i = 0; i < 3; i++)
    {
        u=0;
        for ( j = 0; j < i; j++)
        {
            if (X[i][j]!=0)
            {
                u=1;
                break;
            }
        }
        if(u!=0)
        {
            printf("\nGiven matrix is not upper triangular\n");
            break;
        }
    }
    if (u==0)
    {
        printf("\nGiven matrix is upper triangular\n");
    }
}
void skewsymmetric(int X[3][3])
{
    int i,j,s;
    for ( i = 0; i < 3; i++)
    {
        s=0;
        for ( j = 0; j < 3; j++)
        {
            if(X[i][j]!=-(X[j][i]))
            {
                s=1;
                break;
            }
        }
        if(s!=0)
        {
            printf("\nGiven matrix is not skew symmetric\n");
            break;
        }
    }
    if(s==0)
        printf("\nGiven matrix is skew symmetric\n");
}
void lower(int X[3][3])
{
	int i,j,l;
	for(i=0;i<2;i++)
	{
		l=0;
		for ( j = 1; j < 3; j++)
		{
			if((i!=j) && (X[i][j]!=0))
			{
				l=1;
				break;
			}
		}
		if (l!=0)
		{
			printf("\nGiven matrix is not lower triangular matrix\n");
			break;
		}
	}
	if (l==0)
	{
		printf("\nGiven matrixx is lower triangular matrix\n");
	}
}
void identity(int X[3][3])
{
	int i,j,f=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if ((i==j) && (X[i][j]!=1))
			{
				f=1;
				break;
			}
			if ((i!=j) && (X[i][j]!=0))
			{
				f=1;
				break;
			}
		}
	}
	if (f==0)
	{
		printf("\nGiven matrix is identity matrix\n");
	}
	else
	{
		printf("\nGiven matrix is not identity matrix\n");
	}
}
void rowswap(int A[3][3],int r1,int r2)
{
	int i,temp;
	for ( i = 0; i < 3; i++)
	{
		temp=A[r1][i];
		A[r1][i]=A[r2][i];
		A[r2][i]=temp;
	}
	display(A);
}
void colswap(int A[3][3],int c1,int c2)
{
	int i,temp;
	for ( i = 0; i < 3; i++)
	{
		temp=A[i][c1];
		A[i][c1]=A[i][c2];
		A[i][c2]=temp;
	}
	display(A);
}
void scalarrow(int A[3][3],int k,int r)
{
	int i;
	for ( i = 0; i < 3; i++)
	{
		A[r][i]=k*A[r][i];
	}
	display(A);
}
void scalarcol(int A[3][3],int k,int c)
{
	int i;
	for ( i = 0; i < 3; i++)
	{
		A[i][c]=k*A[i][c];
	}
	display(A);
}
void rowoperation(int A[3][3],int r1,char op,int k,int r2)
{
	int i;
	//for ( i = 0; i < 3; i++)
	//{
		switch (op)
		{
		case '+' :
		for ( i = 0; i < 3; i++)
		{
			A[r1][i]=A[r1][i]+k*A[r2][i];
		}		
			break;
		
		case '-' :
		for ( i = 0; i < 3; i++)
		{
			A[r1][i]=A[r1][i]-k*A[r2][i];
		}		
			break;
		
		default:
			printf("\nInvalid operator !");
			break;
		}
	//}
	display(A);
}