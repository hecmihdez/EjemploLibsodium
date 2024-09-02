#include <stdio.h>
#include "sodium.h"
#include "encrypt.h"

int main(void)
{
  unsigned char buf[128];
  if (sodium_init() == -1) {
      return 1;
  }
 
  randombytes_buf(buf, sizeof((buf)));
  printf("%lu\n",sizeof(buf));
  for (int i = 0; i < sizeof(buf); i++)
    printf("%02X",(unsigned int)buf[i]);
  printf("\n");
}
