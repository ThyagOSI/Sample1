#include <stdio.h>

void getBinaryRec(unsigned int num)
{
    if (num > 1) getBinaryRec(num >> 1); // or num/2
    printf("%d", num%2);

long getBinary(unsigned int num)//bad implementation
{
    unsigned long bin = 0, ten = 1;
    while (num > 0)
    {
        bin = bin + (num%2)*ten;
        num = num/2;
        ten *= 10;
    }
    return bin;
}

int getNthBit(unsigned int num, int nbit)
{
    return ((num & 1 << nbit) != 0) ? 1 : 0;
}

int setNthBit(unsigned int num, int nbit)
{
    return num | (1 << nbit);
}

int checkIfAllBitsSet(int num)
{
    if ( ((num+1) & num) == 0) return 1; //+1 to get 2^n
    else return 0;
}

void exchangeOddEvenBits(unsigned int num)
{
    // for a 32 bit number
    unsigned int even = num & 0xAAAAAAAA;
    unsigned int odd  = num & 0x55555555;
    unsigned int swapnum = (odd << 1) | (even >> 1);
    printf("\nBits swapped num: %u\t", swapnum);
    getBinaryRec(swapnum);
}

void reverseBitsRec(unsigned int num, unsigned int* rev)
{
    // same idea as printing recursive but the printf first
    *rev = (*rev << 1) + num%2;
    if (num > 1) reverseBitsRec(num/2, rev);
}

unsigned int reverseBits(unsigned int num)
{
    unsigned int rev = 0;
    while (num)
    {
        rev = (rev << 1) + num%2;
        num = num >> 1;
    }
    return rev;
}

unsigned int extractBits(unsigned int num, int hi, int low)
{
    unsigned int mask = 0;
    for (int i = low; i<= hi; i++)
        mask = mask | (1 << i);
    return (num & mask) >> low;
}

int main(void)
{
    unsigned int num;
    //short unsigned int nth;
    printf("Enter a number: ");
    scanf(" %u", &num);

    /*
    getBinaryRec(num);
    //printf ("\n%ld",getBinary(num));

    printf("\nGet nth bit, enter n:\t");
    scanf("%hu", &nth);
    printf("%d", getNthBit(num,nth-1));
    printf("\nSet nth bit, enter n:\t");
    scanf("%hu", &nth);
    num = setNthBit(num,nth-1);
    getBinaryRec(num);
    printf ("\n");
    */

    //check if every bit is set
    /* use n & (n-1) == 0 idea here :) Nice hack
    if every bit is set then number is 2^n -1 */
        /*
    int x;
    printf("\nEnter number to check the bits:\t");
    scanf("%d", &x);
    if (checkIfAllBitsSet(x))
        printf("\nAll the bits are set");
    else
        printf("\nNot all bits are 1s");*/

    /* swapping bits
    // printf("%d",sizeof(unsigned int)); 4 bytes
    unsigned int num;
    printf("Enter a number to swap odd-even bits: ");
    scanf(" %u", &num);
    getBinaryRec(num);
    exchangeOddEvenBits(num);
    */
//    getBinaryRec(num);
//    num = reverseBits(num);
//    printf("\n");
//    getBinaryRec(num);
    int hi = 6;
    int low = 2;
    printf("\n%d ", extractBits(num,hi,low));


    return 0;
}
