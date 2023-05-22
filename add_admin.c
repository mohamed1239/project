#include <stdio.h>

typedef struct {
    char username[20];
    char password[20];
} Admin;

int main() {
    printf("Adding an admin\n");

    // Create sample admin
    Admin a1;
    printf("Username: ");
    scanf("%s", a1.username);
    printf("Password: ");
    scanf("%s", a1.password);

    // Write admin to file
    FILE *fp = fopen("admins.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    fprintf(fp, "%s %s\n", a1.username, a1.password);
    fclose(fp);

    printf("The admin has been added successfully\n");

    return 0;
}
