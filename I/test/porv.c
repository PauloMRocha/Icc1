
#include <stdio.h>
#include <string.h>
void main () {
int a[] = {0, 2, 4, 6, 8}, *p = a + 3;
printf ("%d %d", *p, *p + 1);
}
