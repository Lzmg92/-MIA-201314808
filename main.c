#include <stdio.h>
#include <stdlib.h>
#include <string.h>

      char *mkVal[4];
      char *rmkVal;
      char *fVal[8];
      char *mountVal[2];
      char *unmountVal;

      int contmk = 0;
      int contf = 0;
      int contmount = 0;
      int contunmount = 0;

int main()
{
  char str[] ="Mkdisk -size::3000 +unit::k -path::\"/home/user/\"\n -name::\"Disco1.dsk\"";

  // convirtiendo todos los caracteres a minusculas
  int iLower = 0;
  for(iLower ; str[iLower]; iLower++){
  str[iLower] = tolower(str[iLower]);
  }

  // recorriendo token por token y guardando datos en vector
    char * pch;
    pch = strtok(str," ");

    int estado = 0;
    char mkdisk[] = "mkdisk";
    char rmdisk[] = "rmdisk";
    char fdisk[] = "fdisk";
    char mount[] = "mount";
    char unmount[] = "unmount";

    char size[] = "-size";
    char unit[] = "+unit";
    char path[] = "-path";
    char name[] = "-name";
    char type[] = "+type";
    char fit[] = "+fit";
    char del[] = "+delete";
    char add[] = "+add";
    char id[] = "id";

  while (pch != NULL)
  {
      switch(estado)
      {
      /*----------------Redirecciona segun la orden--------------*/
      case 0:{

      contmk = 0;
      contf = 0;
      contmount = 0;
      contunmount = 0;

      if(strcmp(pch,mkdisk)==0)
        {
            printf("encontro mkdisk\n");
            estado = 1;
            pch = strtok (NULL, " ");
        }
        else if(strcmp(pch,rmdisk)==0)
        {
            printf("encontro rmkdisk\n");
            pch = strtok (NULL, " ");
            estado =2;
        }
        else if(strcmp(pch,fdisk)==0)
        {
            printf("encontro fdisk\n");
            pch = strtok (NULL, " ");
            estado = 3;
        }
        else if(strcmp(pch,mount)==0)
        {
            printf("encontro mount\n");
            pch = strtok (NULL, " ");
            estado = 3;
        }
        else if(strcmp(pch,unmount)==0)
        {
            printf("encontro unmount\n");
            pch = strtok (NULL, " ");
            estado = 4;
        }
        else
        {
            printf ("%s\n",pch);
            estado = 0;
            pch = strtok (NULL, " ");
        }
        break;
      }
      // ----------------------- en caso de ser mkdisk
      case 1:{
            mkVal[contmk] = pch;
            pch = strtok (NULL, "\r\n ");
            contmk++;
            break;
      }
      //------------------------ en caso de ser rmdisk
      case 2:{
            rmkVal = pch;
            pch = strtok (NULL, "\r\n ");
            break;
      }
      //------------------------- en caso de ser fdisk
      case 3:{
            fVal[contf] = pch;
            contf++;
            pch = strtok (NULL, "\r\n ");
            break;
      }
      //------------------------- en caso e ser mount
      case 4:{
            mountVal[contmount] = pch;
            contmount++;
            pch = strtok (NULL, "\r\n ");
            break;
      }
      //------------------------- en caso de ser unmount
      case 5:{
            mountVal[contunmount] = pch;
            contunmount++;
            pch = strtok (NULL, "\r\n ");
            break;
      }
    } // termina switch
  }// termina while

  int itemp = 0;
  for(itemp; itemp < 4; itemp++){
    printf("En vector %s \n",mkVal[itemp],itemp);
  }
  return 0;
} // termina int main
