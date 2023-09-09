#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "user.h"

int main (int argc, char *argv[]) {
     if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    srand(time(NULL));
    //variable set up
    user_t *users; 
    char username[100];
    char password[100];
    int attempt = 0;
    int index = 0;

    //Reading file 
    int user_count = read_users(&users, argv[1]);
    if(user_count == -1) {
        printf("Could not read user file");
        free_user_list(users, user_count);
        return 1;
    }
    else if(user_count != -1) {
        printf("File %s loaded successfully!\n", argv[1]);
        printf("Enter login credentials: \n");
    }
    else {
        printf("Error reading file \n");
        free_user_list(users, user_count);
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
        if(index != -1) {
            if(users[index].privilege == ADMIN) {
                break;
            }
            else {
                printf("You do not have admin rights \n");
            }
        }
        else {
            printf("User not found \n");
        }

        attempt++; //I might need to move this under the printf 
        printf("Username not found. %d attempts left. Please try again.\n", (3-attempt));
    }

    //Closes program after 3 tries to find a username 
    if(attempt == 3) {
        printf("3 attempts have been done. Exiting program... \n");
        free_user_list(users, user_count);
        return 1;
    }

    int choice;
    int modified = 0; //Checks to see if a new user was made or if a password was changed
    int privilege;
    //While true loop
    while(1) {
        printf("1. Add a new user\n 2.Reset Password of an Existing User\n 3.Logout\n Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            //Adding new User 
            case 1:

            //Username Selection
            printf("Enter Username: ");
            scanf("%s", username);

            //Privilege Selection
            printf("Enter user privileges (1 for admin, 0 for user): ");
            scanf("%d", &privilege);

            //Find the username 
            index = find_user(users, username, NULL, user_count);
            if(index == -1) {
                //Add a new user 
                users[user_count].username = strdup(username);
                users[user_count].privilege = privilege ? ADMIN : USER;
                new_password(&users[user_count]);
                printf("User added successfully: %s\n", username);
                user_count++;
                modified = 1;
            }
            else {
                printf("Username already exists.");
            }
            break;

            //Resetting a user's password
            case 2:
            printf("Enter the username of the user whose password you want to reset: ");
            scanf("%s", username);
            index = find_user(users, username, NULL, user_count);
            if (index != -1) {
                printf("Creating new password...");
                new_password(&users[index]);
                printf("New password created.");
                printf("Password reset successfully for user %s.\n", username);
                modified = 1;
            } else {
                printf("Username not found.\n");
            }
            
            break;

            //Logging out
            case 3:
                if(modified) {
                    save_users(users, argv[1], user_count);
                }
            printf("Logging off...");
            free_user_list(users, user_count);
            return 0; 
        }


    }























    return 0;
}