#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void convertir_date(int date, char d[]) {
    time_t temps = date;
    struct tm *ptemps = localtime(&temps);
    strftime(d, 20, "%d/%m/%Y %H:%M:%S", ptemps);
}
