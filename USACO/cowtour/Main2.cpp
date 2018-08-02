/*
ID: seifibr1 
PROG: cowtour
LANG: C++
*/
#include <stdio.h>
#include <math.h>
#include <chrono>
#include <iostream>
#define ITF (1e40)
using namespace std;
using namespace std::chrono;
FILE *fi,*fo;
long n;
double dis[200][200],dt[200];
long px[200],py[200];

double dist(long& x1,long& y1,long& x2,long& y2)
{
    return sqrt((double)(x1-x2)*(x1-x2)+(double)(y1-y2)*(y1-y2));
}

void floyed()
{
    long i,j,k;
    for (k=1;k<=n;k++)
    {
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                if (dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }
    for (i=1;i<=n;i++)
        dis[i][i]=ITF;
}

int main(void)
{
    long i,j,a;
    double pmax,pmin,tmp,max=0;
    fi=fopen("cowtour.in","r");
    fo=fopen("cowtour.out","w");
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
    fscanf(fi,"%ld",&n);
    for (i=1;i<=n;i++)
    {
        fscanf(fi,"%ld%ld",&px[i],&py[i]);
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            a=10;
            while (a==10 || a==13)
                a=getc(fi);
            a-=48;
            if (a)
            {
                dis[i][j]=dist(px[i],py[i],px[j],py[j]);
            }
            else
            {
                dis[i][j]=ITF;
            }
        }
    }
    floyed();
    for (i=1;i<=n;i++)
    {
        pmax=0;
        for (j=1;j<=n;j++)
        {
            if (dis[i][j]>pmax && dis[i][j]!=ITF)
                pmax=dis[i][j];
        }
        dt[i]=pmax;
        if (pmax>max) max=pmax;
    }
    pmin=ITF;
    for (i=1;i<=n-1;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            if (dis[i][j]==ITF && i!=j)
            {
                tmp=dist(px[i],py[i],px[j],py[j]);
                if (dt[i]+dt[j]+tmp<pmin)
                    pmin=dt[i]+dt[j]+tmp;
            }
        }
    }
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

    fprintf(fo,"%.6lf\n",pmin>max?pmin:max);
    fclose(fi);
    fclose(fo);
	cout << duration_cast<microseconds>( t2 - t1 ).count() << endl;
    return 0;
}
