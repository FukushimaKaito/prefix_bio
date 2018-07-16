/*-----------------
小数点 2 桁を含めた出力に改修し，
2進接頭辞に
------------------*/
#include <stdio.h>
#include <stdlib.h>

int decimalprefix(char *dst, int dlen, char *srcstr)
{
    int srcnum;
    float tmpnum;
    srcnum = atoi(srcstr);
    if (srcnum >= 1024 * 1024)
    {
        tmpnum = srcnum / (1024.0 * 1024.0);
        sprintf(dst, "%.2fMi", tmpnum);
    }
    else if (srcnum >= 1024)
    {
        tmpnum = srcnum / 1024.0;
        sprintf(dst, "%.2fKi", tmpnum);
    }
    else
    {
        sprintf(dst, "%d", srcnum);
    }
    return 0;
}
int main()
{
    int ik;
    char ibuf[BUFSIZ];
    char obuf[BUFSIZ];
    while (fgets(ibuf, BUFSIZ, stdin))
    {
        ik = decimalprefix(obuf, BUFSIZ, ibuf);
        fprintf(stdout, "%*s <- %s", 8, obuf, ibuf);
    }
}
