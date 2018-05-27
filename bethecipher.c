#include<stdio.h>
#include<string.h>
char cipher(char a, int k){
    int b= (int) a, c;
	if(b>=65&&b<=90){
            c=((b-65+k)%26)+65;
            return (char)c;
	}
    if(b>=97&&b<=122){
            c=((b-97+k)%26)+97;
            return (char)c;
    }
}
void encrypt(char a[], int l, int k){
	int i;
    printf("ciphertext#%d:",l);
    for(i=0;i<strlen(a);i++){
        printf("%c",cipher(a[i],k));
	}
}
void decrypt(char a[], int l, int k){
	int i;
    printf("plaintext#%d:",l);
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
