#include<stdio.h>
#include<string.h>
char cipher(char a, int k){
    int b= (int) a, c;
	if(b>=65&&b<=90){
            c=b-65;
            c=(c+k)%26;
            c+=65;
            return (char)c;
	}
    if(b>=97&&b<=122){
            c=b-97;
            c=(c+k)%26;
            c+=97;
            return (char)c;
    }
}
void encrypt(char a[], int n, int k){
	int i;
    printf("ciphertext#%d:",n);
    for(i=0;i<strlen(a);i++){
        printf("%c",cipher(a[i],k));
	}
}
void decrypt(char a[], int n, int k){
	int i;
    printf("plaintext#%d:",n);
    for(i=0;i<strlen(a);i++){
		printf("%c",cipher(a[i],26-k%26));
	}
}
int main()
{
	int n,k,i;
	scanf("%d %d",&n,&k);
	getchar();
	char input[50];
	for(i=1;i<=n;i++){
        fgets(input,sizeof(input),stdin);
        encrypt(input,i,k);
    }
    for(i=1;i<=n;i++){
        fgets(input,sizeof(input),stdin);
        decrypt(input,i,k);
	}
}

