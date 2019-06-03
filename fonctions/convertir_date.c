#include <stdio.h>
#include <stdlib.h>

void convertir_date(int date,char d[]) {
    int a, m, j, h, min, s;
    a=date/((36525/100)*24*60*60);
    date=date%((36525/100)*24*60*60);
    a=a+1970;
    m=date/((304167/10000)*24*60*60);
    date=date%((304167/10000)*24*60*60);
    j=date/(24*60*60);
    date=date%(24*60*60);
    h=date/(60*60);
    date=date%(60*60);
    min=date/(60);
    s=date%(60);
    sprintf(d,"%i/%i/%i %i:%i:%i",j,m,a,h,min,s);
}
