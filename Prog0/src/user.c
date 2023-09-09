#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "user.h"

void new_password(user_t *u) {
    const char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-=_+";
    int characterLength = sizeof(characters) - 1;
    int passLength = rand() % 3 + 8;
    u->password = malloc(passLength + 1);
    if (u->password == NULL) {
        printf("Memory allocation failed for password.\n");
        exit(1);
    }
    for(int i = 0; i < passLength; i++) {
        u->password[i] = characters[rand() % characterLength];
    }
    u->password[passLength] = '\0';
    printf("The generated password is: %s\n", u->password);
}

int read_users(user_t **user_list, char* filename) {
    // Set up my variables
    char username[100]; // these are buffers
    char password[100];
    int count = 0;
    int accessLvl = 0;
    int maxUsers = 100; // You can adjust this value based on your needs

    // Allocate memory for the user list
    *user_list = malloc(maxUsers * sizeof(user_t));
    if (*user_list == NULL) {
        return -1; // Memory allocation failed
    }

    // Opening the file
    FILE *file = fopen(filename, "r");
    // Checks if the file is there
    if (file == NULL) {
        free(*user_list); // Free the allocated memory
        return -1; // File could not be opened
    }

    while (fscanf(file, "%s %s %d\n", username, password, &accessLvl) != EOF) {
        // Allocate memory and copy the username and password
        (*user_list)[count].username = strdup(username);
        (*user_list)[count].password = strdup(password);

        // Convert the access level to the enum value
        if (accessLvl == 1) {
            (*user_list)[count].privilege = ADMIN;
        } else {
            (*user_list)[count].privilege = USER;
        }
        count++;

    }

    fclose(file);
    return count; // Number of users read from the file
}

int save_users(user_t *user_list, char* filename, int size) {
    // //Opening the file
    // FILE *file = fopen(filename, "w");
    // //Checks if the file is there
    // if(file == NULL) {
    //     return -1; //File could not be opened 
    // }

    // //Saves the file 
    // for(int i = 0; i < size; ++i) {
    //     fprintf(file, "%s %s %d\n", user_list[i].username, user_list[i].password, user_list[i].privilege);
    // }

    // //Closeses the file 
    // fclose(file);
    // return 0; // Writing to the file was successful
    // Opening the file in write mode
    FILE *file = fopen(filename, "w");
    // Checks if the file is there
    if(file == NULL) {
        return -1; // File could not be opened 
    }

    // Saves the file 
    for(int i = 0; i < size; ++i) {
        fprintf(file, "%s %s %d\n", user_list[i].username, user_list[i].password, user_list[i].privilege);
    }

    // Closes the file 
    fclose(file);
    return 0; // Writing to the file was successful
}


int find_user(user_t *user_list, char* username, char* password, int size) {
    for(int i = 0; i < size; i++) {
        //compares the usernames 
        if(strcmp(user_list[i].username, username) == 0) { 
            //If the password is null, return the index for username match 
            if(password == NULL) { 
                return i;
            }
            //If the password isn't null, check if the password matches
            else if(strcmp(user_list[i].password, password) == 0) {
                return i;
            }
            //username matches but the password doesn't
            else {
                return -1; 
            }
        }
    }
    //If the username is not found, return -1
    return -1; 
}

//Frees the memory used by the user list 
void free_user_list(user_t *user_list, int size) {
    for (int i = 0; i < size; ++i) {
        free(user_list[i].username);
        free(user_list[i].password);
    }
    free(user_list);
}


