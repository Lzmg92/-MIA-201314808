#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char str[] ="Mkdisk -size::3000 +unit::k -path::\"/home/user/\"\n -name::\"Disco1.dsk\"";

  // convirtiendo todos los caracteres a minusculas
  int iLower = 0;
  for(iLower ; str[iLower]; iLower++){
  str[iLower] = tolower(str[iLower]);
  }

  char * pch;
  printf ("Separando por espacios en blanco \n\"%s\"\n\n",str);
  pch = strtok (str," \n");

  // recorriendo token por token y guardando datos en vector
    char mkdisk[] = "mkdisk";
    char rmdisk[] = "rmdisk";
    char fdisk[] = "fdisk";
    char mount[] = "mount";
    char unmount[] = "unmount";
  while (pch != NULL)
  {
      if(strcmp(pch,mkdisk)==0)
        {
            printf("encontro mkdisk\n");
            pch = strtok (NULL, " ");
        }
        else if(strcmp(pch,rmdisk)==0)
        {
            printf("encontro rmkdisk\n");
            pch = strtok (NULL, " ");
        }
        else if(strcmp(pch,fdisk)==0)
        {
            printf("encontro fdisk\n");
            pch = strtok (NULL, " ");
        }
        else if(strcmp(pch,mount)==0)
        {
            printf("encontro mount\n");
            pch = strtok (NULL, " ");
        }
        else if(strcmp(pch,unmount)==0)
        {
            printf("encontro unmount\n");
            pch = strtok (NULL, " ");
        }
        else
        {
            printf ("%s\n",pch);
            pch = strtok (NULL, " ");
        }
  }
  return 0;
}
