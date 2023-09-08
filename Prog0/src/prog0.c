#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

int main (int argc, char *argv[]) {
    //variable set up
    user_t *users; 
    char *username;
    char *password;
    int attempt = 0;
    int index = 0;

    //Reading file 
    int user_count = read_users(&users, "users.txt");
    if(user_count == -1) {
        printf("Could not read user file");
        return 1;
    }

    //Username and password input
    while(attempt < 3) {
        printf("Enter Username: ");
        scanf("%s", username);
        printf("Enter Password: ");
        scanf("%s", password);

        //Find the username
        index = find_user(users, username, password, user_count);
        if(index == -1 && users[index].privilege == ADMIN) {
            break;
        }
        attempt++; //I might need to move this under the printf 
        printf("Username not found. %d attempts left. Please try again.\n", (3-attempt));
    }

    //Closes program after 3 tries to find a username 
    if(attempt == 3) {
        printf("3 attempts have been done. Exiting program... \n");
        return 1;
    }

    int choice;
    int modified = 0;






















    return 0;
}