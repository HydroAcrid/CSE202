typedef enum {
  USER,
  ADMIN
} ACCESS;

struct User {
    char* username;
    char* password;
    enum ACCESS privilege; 
};

typedef struct User user_t; 

void new_password(user_t *u);
int read_users(user_t *user_list, char* filename);
int save_users(user_t *user_list, char*filename);
int find_user(user_t *user_list, char* username, char* password, int size);
