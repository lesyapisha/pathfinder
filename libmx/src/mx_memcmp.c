#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n){
   const unsigned char *s1_copy = s1;
   const unsigned char *s2_copy = s2;

   while (n--) {
      if (*s1_copy != *s2_copy) {
         return *s1_copy - *s2_copy;
      }
      s1_copy++;
      s2_copy++;
   }
   return 0;
}
