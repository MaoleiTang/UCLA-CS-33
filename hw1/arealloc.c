#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <errno.h>

void *arealloc(void *ptr, size_t nmemb, size_t size)
{
  if(size!=0 && nmemb!=0 && SIZE_MAX/size < nmemb)
    {
      errno=ENOMEM;
      return NULL;
    }
  return realloc(ptr, nmemb*size);
}
