#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

//TUNAHAN AYDINOĞLU
//   1511012078

int main()
{
  int girilen=0;
  
  pid_t pid;

    do
    {
      printf("Lütfen pozitif bir tam sayi giriniz : \n"); 
        scanf("%d", &girilen);  
    }while (girilen <= 0);

    pid = fork();

    if (pid == 0)
    {
      printf("Child çalışıyor...\n");
      printf("%d\n",girilen);
      while (girilen!=1)
      {
        if (girilen%2 == 0)
        {
          girilen = girilen/2;
        }
        else if (girilen%2 == 1)
        {
          girilen = 3 * (girilen) + 1;
        } 
      
        printf("%d\n",girilen);
      }
    
      printf("Child process bitti..\n");
    }
    else
    {
      printf("Parent process Child processleri bekliyor.\n");
      wait();
      printf("Parent process bitti...\n");
    }
  return 0; 
}