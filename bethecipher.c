#include<stdio.h>
#include<string.h>
void encrypt(char a[][100],int n, int k)
{
	char b[n/2][100];
	int i,l,m,j,s,c,t,x[n];
	m=k;
	l=n/2;
	if(m>26)
	{
		for(i=0;m>26;i++)
		m=m-26;
	}
	for(i=0;i<l;i++){
		strcpy(b[i],a[i]);
		for(j=0;a[i][j]!='\0';j++){
			c=(int)b[i][j];
			if(c>=65&&c<=90)
			{
				if(m<=90-c)
				{
					t=((int)b[i][j])+m;
					b[i][j]=(char)t;
				}
				if(m>90-c)
				{
					t=((int)b[i][j])+m-26;
					b[i][j]=(char)t;
				}
			}
			if(c>=97&&c<=122)
			{
				if(m<=122-c)
				{
					t=((int)b[i][j])+m;
					b[i][j]=(char)t;
				}
				if(m>122-c)
				{
					t=((int)b[i][j])+m-26;
					b[i][j]=(char)t;
				}
			}

		}
		printf("Ciphertext# %d : %s\n",i+1,b[i]);

	}
}
void decrypt(char a[][100],int n, int k)
{
	char b[n/2][100];
	int i,l,m,j,s,c,t;
	m=k;
	l=n/2;
	if(m>26)
	{
		for(i=0;m>26;i++)
		m=m-26;
	}
	for(i=0;i<l;i++){
		strcpy(b[i],a[i+(n/2)]);
		for(j=0;a[i][j]!='\0';j++){
			c=(int)b[i][j];
			if(c>=65&&c<=90)
			{
				if(m<=c-65)
				{
					t=((int)b[i][j])-m;
					b[i][j]=(char)t;
				}
				if(m>c-65)
				{
					t=((int)b[i][j])-m+26;
					b[i][j]=(char)t;
				}
			}
			if(c>=97&&c<=122)
			{
				if(m<=c-97)
				{
					t=((int)b[i][j])-m;
					b[i][j]=(char)t;
				}
				if(m>c-97)
				{
					t=((int)b[i][j])-m+26;
					b[i][j]=(char)t;
				}
			}

		}
		printf("Plaintext# %d : %s\n",l-i+1,b[i]);

	}
}
int main()
{
	int n,k,i,ln[n];
	scanf("%d %d",&n,&k);
	if(n%2==0)
	{
	    char input[n][100],str[100];
		for(i=0;i<n;i++)
		{
			scanf(" %[^\n]s",input[i]);
		}
		encrypt(input,n,k);
		decrypt(input,n,k);
	}
	else
	printf("Invalid input!! No. of test elements should be even");
}

