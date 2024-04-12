#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Human {
  char *name, *surname;
  unsigned int height;
} Human;

int main() {
  unsigned int n = 0;
  int error = 0;
  if(scanf("%u", &n)) {
    Human *storage = (Human *)calloc(n, sizeof(Human));
    if(!storage) {
     printf("n/a");
    } else {
      for(size_t i = 0;i < n;++i) {
        char name[100], surname[100];
        unsigned int height = 0;
        if(scanf("%s%s%u", name, surname, &height) != 3) {
          printf("n/a");
          error = 1;
          break;
        } else {
          storage[i].name = strdup(name);
          storage[i].surname = strdup(surname);
          storage[i].height = height;
        }
      }
      unsigned int standart = 0;
      if(!error && scanf("%u", &standart)) {
        size_t printed = 0;
        for(size_t i = 0;i < n;++i) {
          if(storage[i].height >= standart) {
            if(printed == 0) printf("%s %s", storage[i].name, storage[i].surname);
            else printf(", %s %s", storage[i].name, storage[i].surname); 
            printed = 1;
          }
        }
        if(!printed) printf("Nothing");
        for (size_t i = 0; i < n; ++i) {
          free(storage[i].name);
          free(storage[i].surname);
        }
        free(storage);
      } else{
       printf("n/a");
      }
    }
  } else {
    printf("n/a");
  }
  return 0;
}