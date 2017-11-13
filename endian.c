#include <stdio.h>

/*
	higher memory 32 bit machine
          ----->
    +----+----+----+----+
    |0x01|0x00|0x00|0x00|
    +----+----+----+----+
    A &i
  */

int main(void)
{
    unsigned int i = 1; // first bit is sign bit so use max 127
    unsigned char* p = (unsigned char*)&i;
    *p == 1 ? printf("%s\n", "little endian") : printf("%s\n", "big endian");

    printf("%p\n",(void*) &i);
    printf("%d\n", (int)(*p));
    printf("\n");
    unsigned int j = 0xAABBCCDD;
    //int k;
    unsigned char* q = (unsigned char*)&j;
    //printf("%d\n",  (unsigned char)strtol(q, NULL, 16));
    int k;
    for (k=0; k < 4; k++)
    	printf("%x\n",*(q + k));

    return 0;
}
