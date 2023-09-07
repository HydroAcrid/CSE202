#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "user.h"

void new_password(user_t *u) {
    //Generate a random number between 8 to 10 characters
    srand(time(NULL));

    //Characters that can be in the password
    const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-=_+";
    int characterLength = sizeof(characters) - 1;

    //Between 8 and 10. % 3 awlays returns from 0 - 2 
    int passLength = rand() % 3 + 8; 

    //Adds the characters into the password once the length is decided 
    for(int i=0; i < passLength; i++) {
        u -> password[i] = characters[rand() % characterLength];
    }

    //Print it out for debuggin
    printf("The generated password is: %s\n", u->password);
}

int read_users(user_t *user_list, char* filemame) {
    FILE *file = fopen(filemame, "r");
    //Checks if the file is there
    if(file == NULL) {
        return -1;
    }
}

