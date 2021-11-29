#include <stdlib.h>
#include <stdint.h>

uint32_t hash(const char *str)
{
  int hash = 5381;
  char c = str[0];
  int i = 1;
  while ( c != '\0') {
    hash = hash*33 + c;
    c = str[i];
    i++;
  }
    return hash;
}

int main(void) {
  return 0;
}
