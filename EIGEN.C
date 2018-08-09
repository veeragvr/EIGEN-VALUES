#include<stdio.h>
#include<conio.h>
#include<math.h>

struct eigenn
{
int b[4];
};

struct eigenv
{
int c[3];
};



void accept(int A[10][10],int R)
{
int i,j;
for(i=0;i<R;i++)
{
for(j=0;j<R;j++)
{
printf("\n ENTER ELEMENT [%d][%d] : ",i,j);
scanf("%d",&A[i][j]);
}
}
}

void display(int A[10][10],int R,int C)
{
int i,j;
printf("\t\n");
for(i=0;i<R;i++)
{
for(j=0;j<C;j++)
{
if(A[i][j]<0)
printf("%d\t",A[i][j]);
else
printf(" %d\t",A[i][j]);

}
printf("\t\n");
}
}


struct eigenn ceqn(int A[10][10],int R)
{
struct eigenn S;
char o=224;
int s1,s2,s3;

if(R==2)

{
s1=A[0][0]+A[1][1];
s2=((A[0][0]*A[1][1])-(A[0][1]*A[1][0]));
printf("\n\n\t S1 = %d\t\t S2 = %d ",s1,s2);
printf("\n\n THE CHARACTERSTIC EQUATION IS :\n\n\n\t\t  %c - %d %c + %d = 0 ",o,s1,o,s2);
gotoxy(20,20);
printf("2");
S.b[0]=1;
S.b[1]=s1;
S.b[2]=s2;
}

else if(R==3)
{
s1=A[0][0]+A[1][1]+A[2][2];
s2=((A[1][1]*A[2][2])-(A[1][2]*A[2][1])+(A[0][0]*A[2][2])-(A[0][2]*A[2][0])+(A[0][0]*A[1][1])-(A[0][1]*A[1][0]));
s3=((A[0][0]*((A[1][1]*A[2][2])-(A[1][2]*A[2][1])))-(A[0][1]*((A[1][0]*A[2][2])-(A[1][2]*A[2][0])))+(A[0][2]*((A[1][0]*A[2][1])-(A[1][1]*A[2][0]))));
printf("\n\n\t S1 = %d\t\t S2 = %d\t\t S3 = %d ",s1,s2,s3);
printf("\n\n THE CHARACTERSTIC EQUATION IS :\n\n\n\t\t  %c - %d %c + %d %c - %d = 0 ",o,s1,o,s2,o,s3);
gotoxy(20,24);
printf("3");
gotoxy(26,24);
printf("2");
S.b[0]=1;
S.b[1]=s1;
S.b[2]=s2;
S.b[3]=s3;
}

return S;


}


struct eigenv eigenval(struct eigenn S,int R)
{
char o=224;
struct eigenv x;
int d,i,j=0;

x.c[0]=101;
x.c[1]=101;
x.c[2]=101;

if(R==2)
{
d=((sqrt(((S.b[1]*S.b[1])-(4*S.b[0]*S.b[2]))))/(2*S.b[0]));
x.c[0]=((-1*S.b[1])+d);
x.c[1]=((-1*S.b[1])-d);
printf("\n\n\n\n EIGEN VALUES ARE :\n\n\t\t %c = %d , %d ",o,x.c[0],x.c[1]);
}

else if(R==3)
{

for(i=-40;i<=40;i++)
{
if(((i*i*i)-(S.b[1]*i*i)+(S.b[2]*i)-(S.b[3]))==0)
{
x.c[j]=i;
j++;
}
}
if(((x.c[1]==101)&&(x.c[2]==101)))
{
x.c[1]=x.c[0];
x.c[2]=x.c[0];
}
else if(x.c[1]==101)
x.c[1]=x.c[0];
else if(x.c[2]==101)
x.c[2]=x.c[1];


printf("\n\n\n\n\n EIGEN VALUES ARE :\n\n\t\t %c = %d , %d , %d  ",o,x.c[0],x.c[1],x.c[2]);

}

return x;

}



void eigenvec(int A[10][10],struct eigenv E,int R)
{

int i,j,temp,k=0;
int x[10][10];
int B[10][10];

if(R==2)
{

while(k<2)
{

for(i=0;i<R;i++)
{
for(j=0;j<R;j++)
{
B[i][j]=A[i][j];
}
}


B[0][0]=B[0][0]-E.c[k];
B[1][1]=B[1][1]-E.c[k];

x[0][0]=(-1*B[0][1]);
x[1][0]=B[0][0];

for(i=30;i>=2;i--)
{
if((x[0][0]%i==0)&&(x[1][0]%i==0))
{
x[0][0]=x[0][0]/i;
x[1][0]=x[1][0]/i;
}
}
printf("X%d=\n",k+1);
display(x,R,1);
++k;


}
}

else if(R==3)
{

while(k<3)
{

for(i=0;i<R;i++)
{
for(j=0;j<R;j++)
{
B[i][j]=A[i][j];
}
}

B[0][0]=B[0][0]-E.c[k];
B[1][1]=B[1][1]-E.c[k];
B[2][2]=B[2][2]-E.c[k];

x[0][0]=((B[0][1]*B[1][2])-(B[0][2]*B[1][1]));
x[1][0]=(-1*((B[0][0]*B[1][2])-(B[0][2]*B[1][0])));
x[2][0]=((B[0][0]*B[1][1])-(B[0][1]*B[1][0]));

if((x[0][0]==0)&&(x[1][0]==0)&&(x[2][0]==0))
{

x[0][0]=((B[1][1]*B[2][2])-(B[1][2]*B[2][1]));
x[1][0]=(-1*((B[1][0]*B[2][2])-(B[1][2]*B[2][0])));
x[2][0]=((B[1][0]*B[2][1])-(B[1][1]*B[2][0]));

if((x[0][0]==0)&&(x[1][0]==0)&&(x[2][0]==0))
{
 x[0][0]=(-1*B[0][1]);
 x[1][0]=B[0][0];
 x[2][0]=0;


}

}

for(i=30;i>=2;i--)
{
if((x[0][0]%i==0)&&(x[1][0]%i==0)&&(x[2][0]%i==0))
{
x[0][0]=x[0][0]/i;
x[1][0]=x[1][0]/i;
x[2][0]=x[2][0]/i;
}
}
printf("X%d=\n",k+1);
display(x,R,1);

++k;
}

}

}

void diagonal(struct eigenv E,int r)
{

int b[10][10];
int i,j,k=0;

for(i=0;i<r;i++)
{
for(j=0;j<r;j++)
{
b[i][j]=0;
if(i==j)
{
b[i][j]=E.c[k];
k++;
}

}
}

printf("\n DIAGONALISED MATRIX IS :\n");
display(b,r,r);

}


void canon(struct eigenv E,int R)
{
int r=0,p=0,s=0,i;
if(R==2)
{
printf("\n CANONICAL FORM IS :\n ");
printf("%d y1^2 + %d y2^2 ",E.c[0],E.c[1]);
if((E.c[0]==0)||(E.c[1]==0))
r=1;
else
r=2;
if((E.c[0]<=0)||(E.c[1]<=0))
p=1;
else
p=2;

s=((2*p)-r);
printf("\n RANK = %d\n INDEX = %d\n SIGNATURE = %d ",r,p,s);

}

else if(R==3)
{
printf("\n CANONICAL FORM IS :\n ");
printf("%d y1^2 + %d y2^2 + %d y3^2",E.c[0],E.c[1],E.c[2]);
for(i=0;i<3;i++)
{
if(E.c[i]!=0)
r++;
if(!(E.c[i]<=0))
p++;
}


s=((2*p)-r);
printf("\n RANK = %d\n INDEX = %d\n SIGNATURE = %d ",r,p,s);

}

}

void nature(struct eigenv E,int R)
{
if(R==2)
{
if((E.c[0]>0)&&(E.c[1]>0))
printf("\n NATURE IS : POSITIVE DEFINITE ");
else if((E.c[0]<0)&&(E.c[1]<0))
printf("\n NATURE IS : NEGATIVE DEFINITE ");
else if((E.c[0]==0)||(E.c[1]==0))
{
if((E.c[0]>0)||(E.c[1]>0))
printf("\n NATURE IS : POSITIVE SEMIDEFINITE ");
else
printf("\n NATURE IS : NEGATIVE SEMIDEFINITE ");
}
else
printf("\n NATURE IS : INDEFINITE ");
}

else if(R==3)
{

if((E.c[0]>0)&&(E.c[1]>0)&&(E.c[2]>0))
printf("\n NATURE IS : POSITIVE DEFINITE ");
else if((E.c[0]<0)&&(E.c[1]<0)&&(E.c[2]<0))
printf("\n NATURE IS : NEGATIVE DEFINITE ");
else if((E.c[0]==0)||(E.c[1]==0)||(E.c[2]==0))
{
if((E.c[0]>=0)&&(E.c[1]>=0)&&(E.c[2]>=0))
printf("\n NATURE IS : POSITIVE SEMIDEFINITE ");
else if((E.c[0]<=0)&&(E.c[1]<=0)&&(E.c[2]<=0))
printf("\n NATURE IS : NEGATIVE SEMIDEFINITE ");
}
else
printf("\n NATURE IS : INDEFINITE ");

}

}



void menu()
{
struct eigenn s;
struct eigenv v;
int a[10][10],r;
clrscr();
printf("\n ENTER ORDER ");
scanf("%d",&r);
accept(a,r);
printf("\n \t\t");
display(a,r,r);
s=ceqn(a,r);
getch();
getch();
clrscr();
v=eigenval(s,r);
eigenvec(a,v,r);
diagonal(v,r);
canon(v,r);
nature(v,r);
getch();

}

void main()
{
menu();
}
