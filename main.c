#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char str[] ="Mkdisk -size::3000 +unit::k -path::\"/home/user/\"\n -name::\"Disco1.dsk\"";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ");
  }
  return 0;
}
