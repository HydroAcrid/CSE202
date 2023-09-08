#ifndef USER_H
#define USER_H

typedef enum {
  USER,
  ADMIN
} ACCESS;

struct User {
  char* username;
  char* password;
  ACCESS privilege;
};

typedef struct User user_t; 

void new_password(user_t *u);
int read_users(user_t *user_list, char* filename);
int save_users(user_t *user_list, char*filename, int size);
int find_user(user_t *user_list, char* username, char* password, int size);
void free_user_list(user_t *user_list, int size);

#endif