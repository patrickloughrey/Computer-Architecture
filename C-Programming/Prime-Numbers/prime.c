#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) 
{
    if(argc != 2) {
      printf("You did not provide the correct number of arguments!\n");
      exit(0);
    }

    int num = 0;
    int i = 0;

    /* Converts command line argument from character to an integer */
    num = atoi(argv[1]);

    for(i = 2; i < num; i++) {

      if((num % i) == 0) {
        printf("%d is a composite number!\n", num);
        return 0;
      }

    }

    printf("%d is a prime number!\n", num);
    return 0;

}