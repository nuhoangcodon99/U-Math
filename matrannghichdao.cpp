
/* DINH THUC VA MA TRAN NGHICH DAO */

#include<stdio.h>
#include<conio.h>

void main()
{
int i,j,k,m,n,na;
double det,x,tam;
double a[10][10],b[10][10];
clrscr();
printf("\n TMU.Ngoccoder - TINH DINH THUC VA MA TRAN NGHICH DAO");
printf("\n");
printf("\n NHAP CAP MA TRAN:"); scanf("%d",&n);
na=2*n;//so cot ma tran chuyen tiep.
//Nhap ma tran A.-----------------------------------------------------------
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        {
        printf("\n a[%d][%d]=",i+1,j+1);
        scanf("%lf",&a[i][j]);
        }

//Tao ma tran lien ket.-----------------------------------------------------
for(i=0;i<n;i++)
    for(j=n;j<na;j++)
        {
        if(i==(j-n)) a[i][j]=1;
        else a[i][j]=0;
        }

//In ma tran chuyen tiep.----------------------------------------------------
printf("\n MA TRAN MO RONG (A/I)\n");
for(i=0;i<n;i++)
    {
    for(j=0;j<na;j++) printf("%5.1lf ",a[i][j]);
    printf("\n");
    }

//Ham giai phuong trinh.------------------------------------------------------
//Dung phep BDSC dua Aij ve ma tran cheo.
for(j=0;j<n;j++)
    {
    for(i=n-1;i>=j;i--)
        {
        if(a[i][j]==0) continue;
        if((i>j)&&(a[i][j]!=0))
            {
            k=i-1;
            while((k>=j)&&(a[k][j]==0)) k--;
            if(k<j)
                {
                //Doi cho hang thu i va j.------------------------
                for(m=0;m<na;m++)
                    {
                    tam=a[i][m];
                    a[i][m]=a[j][m];
                    a[j][m]=tam;
                    }
                }
            if((k>=j)&&(k>=0))
                {
                x=-a[i][j]/a[k][j];
                //Nhan dong thu (i-1) cho x roi cong vao dong thu i.
                for(m=0;m<na;m++)
                    a[i][m]+=a[k][m]*x;
                }
            }
        }
    }
for(j=n-1;j>=0;j--)
    {
    for(i=0;i<=j;i++)
    if(a[i][j]==0) continue;
    if((i<j)&&(a[i][j]!=0))
        {
        k=i+1;
        while((k<=j)&&(a[k][j]==0)) k++;
        if((k<=j)&&(k<na))
            {
            x=-a[i][j]/a[k][j];
            //Nhan dong thu (i+1) voi x roi cong vao dong thu i.-------
            for(m=0;m<na;m++)
                a[i][m]+=a[k][m]*x;
            }
        }
    }
//Tinh dinh thuc.--------------------------------------------------------------------
det=1;
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        if(i==j) det*=a[i][j];
printf("\n Det=%5.2lf",det);
//Tinh ma tran nghich dao.-----------------------------------------------------------
if(det!=0)
    {
    for(i=0;i<n;i++)
        for(j=n;j<na;j++)
            {
            a[i][j]=a[i][j]/a[i][i];
            }

    //In ma tran chuyen tiep.----------------------------------------------------
    printf("\n MA TRAN NGHICH DAO MO RONG\n");
    for(i=0;i<n;i++)
        {
        for(j=0;j<na;j++) printf("%5.1lf ",a[i][j]);
            printf("\n");
        }
    for(i=0;i<n;i++)
        for(j=n;j<na;j++)
            {
            b[i][j-n]=a[i][j];
            }
    //In ra ma tran nghich dao.---------------------------------------------------
    printf("\n MA TRAN NGHICH DAO CUA A:\n");
    for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
            printf("%5.1lf",b[i][j]);
        printf("\n");
        }
    }
else printf("\n KHONG CO MA TRAN NGHICH DAO.");
getch();
}
