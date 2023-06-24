

typedef struct {
    char first_name[50];
    char last_name[50];
    char username[50];
    char password[50];
} User;

void registerUser(void);
void loginUser(void);



void registerUser(void) {
    User user;
    FILE* file;

    file = fopen("login.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("=== Registration ===\n");
    printf("Enter First Name: ");
    scanf("%s", user.first_name);
    printf("Enter Last Name: ");
    scanf("%s", user.last_name);
    printf("Enter Username: ");
    scanf("%s", user.username);
    printf("Enter Password: ");
    scanf("%s", user.password);

    fprintf(file, "%s %s %s %s\n", user.first_name, user.last_name, user.username, user.password);
    fclose(file);

    printf("Registration successful.\n");
}

void loginUser(void) {
    char username[50];
    char password[50];
    User user;
    FILE* file;

    file = fopen("login.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\n=== Login ===\n");
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    int isLoggedIn = 0; // Flag to track successful login

    while (fscanf(file, "%s %s %s %s", user.first_name, user.last_name, user.username, user.password) != EOF) {
        if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0) {
            printf("Login successful.\n");
            isLoggedIn = 1;
            break;
        }
    }

    fclose(file);

    if (isLoggedIn==0) {
        printf("Invalid username or password.\n");
        loginUser(); // Restart the login process
    }
    printf("\nEntering The System \n\n");
    printf("Please Wait a Little....");
    sleep(3);
    system("cls");
}

