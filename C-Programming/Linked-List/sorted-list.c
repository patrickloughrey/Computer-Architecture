#include <stdio.h>
#include <stdlib.h>
#include "sorted-list.h"



int main(int argc, char **argv)
{
    struct Node *head;

    /* If no file was provided */
    if(argc != 2) {
      printf("You have to provide a file!\n");
      exit(0);
    }

    FILE *fp = fopen(argv[1], "r");

    /* File is blank */
    if(fp == NULL) {
        printf("There is nothing in this file!\n");
        exit(0);
    }

    char action;
    int num = 0;

    while(fscanf(fp, "%c\t%d", &action, &num) == 2) {

        /* If line parsed is an insert */
        if(action == 'i') {
          head = insert(head, num);

        } else if(action == 'd') {
          head = delete(head, num);

        } else {
          printf("Not a valid action!\n");
          return 0;
        }
    }

    /* If file pointer did not reach the end of file, an error occurred */
    if(!feof(fp)) {
      printf("There was an error with the format or type of file..\n");
      exit(0);
    }

    while(head != null) {
      printf("%d\t", head->x);
      head = head->next;

    }

    printf("\n");
    fclose(fp);
    free(head);

    return 0;
    
}