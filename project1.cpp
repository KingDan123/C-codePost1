#include <iostream>
#include<math.h>
#include<string.h>
using namespace std ;
void encryption();
void decryption();
bool loop=true;
char check;
 char plain[20];
 char cipher[20];
int key[2][2];
char arr[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char arr2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int main(){
     while(loop){
char choise;
cout<<"what do you want?"<<endl;
cout<<"1.Encryption[E]\t\t\t2.Decryption"<<endl;
up:cin>>  choise;
switch(choise){
    case 'e':
    case 'E':
    encryption();
    break;
    case 'd':
    case 'D':
    decryption();
    break;
    default:
    cout<<"please enter the apropriate input"<<endl;
    goto up;
    break;
}
}
}
void encryption(){
cout<<"Enter 2*2 key"<<endl;
for(int i=0;i<2;i++){
    for(int j=0; j<2;j++){
        cout<<"["<<i<<"]"<<"["<<j<<"]:\t";
        cin>>key[i][j];
        }
    }
cout<<"Enter the Plain text:\t";
up:cin>>plain;
if(strlen(plain)%2 != 0){
    cout<<"plain text doesn't match with the key please try an other one"<<endl;
   goto up;
}
  int plainnum[strlen(plain)];
  int enc[strlen(plain)];
int count=0,num=0;
for(int i=0;i<strlen(plain)/2;i++){
    for(int j=count;j<count+2;j++){
        for(int k=0;k<26;k++){
            if(plain[j]==arr[k]){
                plainnum[num]=k;
                num++;
                }
    else if(plain[j]==arr2[k]){
                    plainnum[num]=k;
                    num++;
                    }
            }
        }
        count=count+2;
    }
for(int i=0;i<strlen(plain);i++){
    cout<<plainnum[i]<<"\t";
    }
//Encryption
int cnt=0;
cout<<endl;
for(int k=0;k<strlen(plain)/2;k++){
for(int i=0;i<2;i++){
int    sum=0;
    for(int j=0;j<2;j++){

        sum= sum+key[i][j]*plainnum[cnt+j];
        }
        enc[cnt+i]=sum;
    }

        cnt=cnt+2;
}
/*for(int i=0;i<strlen(plain);i++){
       cout<<enc[i]%26<<"\t";
}*/
cout<<"Encrypted text :\t";
for(int i=0;i<strlen(plain);i++){
    cout<<arr[enc[i]%26];
    }
cout<<"\nwanne try again?"<<endl;
cout<<"1. Yes[y]\t\t 2. No[n]"<<endl;
cin>>check;
switch(check){
    case 'y':
    case 'Y':
    loop=true;
    break;
    case 'n':
    case 'N':
    loop=false;;
    break;
    default:
    break;
}
}


////////////////////decryption


void decryption(){
    cout<<"Note: a matrix with negative even determinants may fail to display the right result"<<endl;
    cout<<"Enter 2*2 key"<<endl;

for(int i=0;i<2;i++){
    for(int j=0; j<2;j++){
        cout<<"["<<i<<"]"<<"["<<j<<"]:\t";
        cin>>key[i][j];
        }
    }
    int determinant=(key[0][0]*key[1][1])-(key[0][1]*key[1][0]);
    cout<<"Determinant= "<<determinant<<endl;;
cout<<"Enter the Cypher text:\t"<<endl;
up:cin>>cipher;

if(strlen(cipher)%2 != 0){
    cout<<"Cipher text doesn't match with the key please try an other one"<<endl;
   goto up;
}

 int ciphernum[strlen(cipher)];
  int dec[strlen(cipher)];
int count=0,num=0;
for(int i=0;i<strlen(cipher)/2;i++){
    for(int j=count;j<count+2;j++){
        for(int k=0;k<=26;k++){
            if(cipher[j]==arr[k]){
                ciphernum[num]=k;
                num++;
                }
                else if(cipher[j]==arr2[k]){
                    ciphernum[num]=k;
                    num++;
                    }
            }
        }
        count=count+2;
    }
/*for(int i=0;i<strlen(cipher);i++){
    cout<<ciphernum[i]<<"\t";
    }*/
key[0][1]= -1*key[0][1];
key[1][0]= -1*key[1][0];
int var=key[0][0];
key[0][0]=key[1][1];
key[1][1]=var;
for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        if(key[i][j]<0)
        key[i][j]=key[i][j]+26;
    }
}
int det=determinant;
int index;
for(int i=0;i<26;i++){
if((abs(determinant)*i)%26==1){
    index=i;
    break;
    }
}
if(det<0){
    index=det+26;
}

//cout<<endl<<index<<endl;
for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        key[i][j]=(key[i][j]*index)%26;
    }
}
/*
for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
     cout<<key[i][j]<<"\t";
    }
    cout<<endl;
}
*/
int cnt=0;
cout<<endl;
for(int k=0;k<strlen(cipher)/2;k++){
for(int i=0;i<2;i++){
int    sum=0;
    for(int j=0;j<2;j++){

        sum= sum+key[i][j]*ciphernum[cnt+j];
        }
        dec[cnt+i]=sum;
    }

        cnt=cnt+2;
}
/*
for(int i=0;i<strlen(cipher);i++){
       cout<<dec[i]%26<<"\t";
}
*/
cout<<endl<<"decrypted text :\t";
for(int i=0;i<strlen(cipher);i++){
    cout<<arr[dec[i]%26];
    }
cout<<"\nwanne try again?"<<endl;
cout<<"1. Yes[y]\t\t 2. No[n]"<<endl;
cin>>check;
switch(check){
    case 'y':
    case 'Y':
    loop=true;
    break;
    case 'n':
    case 'N':
    loop=false;;
    break;
    default:
    break;
}
}
