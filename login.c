#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <conio.h>


typedef struct {
        char username[20];
        char password[20];
}
Admin;

typedef struct book {
    long long int ISBN;
    char title[50];
    char author[50];
    char publisher[50];
    int publication_date;
    char genre[20];
    int numCopies;
    char availability[20];
    struct book *next;
} Book;

typedef struct Student {
        int numApoge;
        char password[20];
        struct Student * next;
}
Student;

typedef struct queue_node {
        int numApoge;
        long long int isbn;
        struct queue_node * next;
}
QueueNode;

Book * head = NULL; // pointer to the head of the book list
Student * head_student = NULL; // pointer to the head of the students list
QueueNode * queuehead = NULL; // pointer to the head of the reservation queue list

//fonctions prototype 
int student_login(int numApoge, char password[20]);
int student_signup(int numApoge, char password[20]);
int admin_login(char username[20], char password[20]);
void search_by_title(Book * head);
void search_by_author(Book * head);
void search_by_publisher(Book * head);
void search_by_isbn(Book * head);
void display_books_list(Book * head);
Book * add_book(Book * head);
Book * load_books_from_file(); //to save the books 
void save_books_to_file(Book * head); //to load the saved books
void list_students(void);
void book_reservation(Book * head, int numApoge);
void show_queue();

int main() {

        int choice, choice2, choix, schoix, sschoix, numApoge, check, is_admin, choiceSTUDENT;
        char password[20];
        char username[20];
        int exit2 = 1, exit1 = 1;
        Book * head = load_books_from_file();

        while (1) {
                system("cls");
                printf("==========================================================================================================\n");
                printf("                                              BIENVENUE!                                                  \n");
                printf("==========================================================================================================\n");
                printf("\n");
                printf("Veuillez choisir une option:\n");
                printf("1. Etudiant\n");
                printf("2. Administrateur.\n");
                printf("0. Sortir\n");
                printf("Choix : ");
                scanf("%d", & choice);

                switch (choice) {

                case 1:
                        while (1) {
                                loginstudent:
                                system("cls");
                                printf("Veuillez choisir une option:\n");
                                printf("1. Se connecter\n");
                                printf("2. S'inscrire\n");
                                printf("0. Revenir au menu principal..\n");
                                printf("Choix : ");
                                scanf("%d", & choiceSTUDENT);

                                switch (choiceSTUDENT) {
                                case 0:
                                        break;
                                case 1:
										system("cls");                                		
										printf("Connectez-vous \x61 votre compte\n");

                                        printf("Entrer votre code Apogee: ");
                                        if (scanf("%d", & numApoge) != 1) { // to not go to infinit loop if we enter a string instead of an integer 
                                                printf("Invalide\n");
                                                getchar(); // this clears the string we enter 
                                                break;
                                        }
                                        printf("Entrer votre mot de passe: ");
                                        scanf("%s", password);
                                        system("cls");
                                        check = student_login(numApoge, password);
                                        if (check == 0) {
                                                int exit3 = 1;
                                                while (exit3 == 1) {
                                                        system("cls");
                                                        printf("Menu principal:\n");
                                                        printf("1. Rechercher un livre\n");
                                                        printf("2. Voir la liste des livres disponibles\n");
                                                        printf("3. Emprunter un livre\n");
                                                        printf("0. Se d\x82"
                                                                "connecter\n");
                                                        printf("Choix : ");
                                                        scanf("%d", & choix);
                                                        system("cls");
                                                        switch (choix) {
                                                        case 1:
                                                                while (exit1 == 1) {
                                                                        system("cls");
                                                                        printf("\nSous-menu de recherche :\n");
                                                                        printf("1. Rechercher par titre\n");
                                                                        printf("2. Rechercher par auteur\n");
                                                                        printf("3. Rechercher par \x82"
                                                                                "diteur\n");
                                                                        printf("4. Rechercher par ISBN\n");
                                                                        printf("5. Revenir au menu principal\n");
                                                                        printf("Choix : ");
                                                                        scanf("%d", & schoix);
                                                                        system("cls");

                                                                        switch (schoix) {
                                                                        case 1:
                                                                                printf("Rechercher par titre\n");
                                                                                search_by_title(head);
                                                                                printf("Press any key to continue...\n");
                                                                                getch();
                                                                                break;
                                                                        case 2:
                                                                                printf("Rechercher par auteur\n");
                                                                                search_by_author(head);
                                                                                printf("Press any key to continue...\n");
                                                                                getch();
                                                                                break;
                                                                        case 3:
                                                                                printf("Rechercher par \x82"
                                                                                        "diteur\n");
                                                                                search_by_publisher(head);
                                                                                printf("Press any key to continue...\n");
                                                                                getch();
                                                                                break;
                                                                        case 4:
                                                                                printf("Rechercher par ISBN\n");
                                                                                search_by_isbn(head);
                                                                                printf("Press any key to continue...\n");
                                                                                getch();
                                                                                break;
                                                                        case 5:
                                                                                exit1 = 0;
                                                                                break;
                                                                        default:
                                                                                printf("Choix invalide. Veuillez r\x82"
                                                                                        "essayer.\n");
                                                                                break;
                                                                        }
                                                                        //break;
                                                                }
                                                                exit1 = 1;
                                                                break;
                                                        case 2:
                                                                printf("Voir la liste des livres disponibles:\n");
                                                                display_books_list(head);
                                                                printf("Press any key to continue...\n");
                                                                getch();
                                                                break;
                                                                //goto outer_menu;
                                                        case 3:
                                                                printf("%d\n", numApoge); //debuggimg 
                                                                book_reservation(head, numApoge);
                                                                printf("Press any key to continue...\n");
                                                                getch();
                                                                break;
                                                        case 0:
                                                                printf("Au revoir !\n");
                                                                exit3 = 0;
                                                                break;
                                                        default:
                                                                printf("Choix invalide. Veuillez r\x82"
                                                                        "essayer.\n");
                                                                break;
                                                        }

                                                }
                                                break;
                                        }
                                        break;
                                case 2:
                                		system("cls");
                                		printf("creation de votre compte\n");
                                        printf("Entrer votre code Apogee: ");
                                        scanf("%d", & numApoge);
                                        printf("Entrer votre mot de passe: ");
                                        scanf("%s", password);
                                        system("cls");
                                        student_signup(numApoge, password);
                                        break;

                                default:
                                        system("cls");
                                        printf("Choix invalide \n");
                                        break;
                                }
                                break;
                        }
                        break;
                case 2:
                		system("cls");
                		printf("Connectez-vous \x61 votre compte administrative: \n");
                        printf("Entrer le nom d'utilisateur: ");
                        scanf("%s", username);
                        printf("Entrer le mot de passe: ");
                        scanf("%s", password);
                        system("cls");
                        is_admin = admin_login(username, password);
                        if (is_admin == 0) {
                                int loggedIn = 1;
                                while (loggedIn) {
                                        system("cls");
                                        printf("Menu principal:\n");
                                        printf("1. Rechercher un livre\n");
                                        printf("2. Voir la liste compl\x8Ate des livres\n");
                                        printf("3. Ajouter un livre\n");
                                        printf("4. Voir la liste des \x82tudiants\n");
                                        printf("5. Voir la liste livre emprunter\n");
                                        printf("0. Se d\x82"
                                                "connecter\n");
                                        printf("Entrer votre choix: ");
                                        scanf("%d", & choice);
                                        system("cls");
                                        switch (choice) {
                                        case 0:
                                                printf("Au revoir !\n");
                                                loggedIn = 0; // Set the flag to false to exit the loop
                                                break;
                                        case 1:

                                                while (exit2 == 1) {
                                                        system("cls");
                                                        printf("\nSous-menu de recherche :\n");
                                                        printf("1. Rechercher par titre\n");
                                                        printf("2. Rechercher par auteur\n");
                                                        printf("3. Rechercher par \x82"
                                                                "diteur\n");
                                                        printf("4. Rechercher par ISBN\n");
                                                        printf("5. Revenir au menu principal\n");
                                                        printf("Choix : ");
                                                        scanf("%d", & schoix);
                                                        system("cls");
                                                        switch (schoix) {
                                                        case 1:
                                                                printf("Rechercher par titre\n");
                                                                search_by_title(head);
                                                                printf("Press any key to continue...\n");
                                                                getch();
                                                                break;
                                                        case 2:
                                                                printf("Rechercher par auteur\n");
                                                                search_by_author(head);
                                                                printf("Press any key to continue...\n");
                                                                getch();
                                                                break;
                                                        case 3:
                                                                printf("Rechercher par \x82"
                                                                        "diteur\n");
                                                                search_by_publisher(head);
                                                                printf("Press any key to continue...\n");
                                                                getch();
                                                                break;
                                                        case 4:
                                                                printf("Rechercher par ISBN\n");
                                                                search_by_isbn(head);
                                                                printf("Press any key to continue...\n");
                                                                getch();
                                                                break;
                                                        case 5:
                                                                exit2 = 0;
                                                                break;
                                                        default:
                                                                printf("Choix invalide. Veuillez r\x82"
                                                                        "essayer.\n");
                                                                break;
                                                        }
                                                }
                                                exit2 = 1;
                                                break;
                                        case 2:
                                                display_books_list(head);
                                                printf("Press any key to continue...\n");
                                                getch();
                                                break;
                                        case 3:
                                                head = add_book(head);
                                                printf("Press any key to continue...\n");
                                                getch();
                                                break;
                                        case 4:
                                                printf("liste des \x82tudiants\n");
                                                list_students();
                                                printf("Press any key to continue...\n");
                                                getch();
                                                break;
                                        case 5:
                                                show_queue();
                                                printf("Press any key to continue...\n");
                                                getch();
                                                break;
                                        default:
                                                printf("Choix invalide. Veuillez r\x82"
                                                        "essayer.\n");
                                        }
                                }
                        }
                        break;
                case 0:
                        printf("exiting!\n");
                        printf("Enregistrement de donn\x82"
                                "es...\n");
                        save_books_to_file(head);
                        printf("Les livres ont \x82t\x82 enregistr\x82s avec succ\x8As.\n");
                        return 0;
                default:
                        system("cls");
                        printf("Choix invalide \n");
                        sleep(1);
                        break;
                }
        }
}

int student_login(int numApoge, char password[20]) {

        // Read student data from file
        FILE * fp = fopen("students.txt", "r");
        if (fp == NULL) {
                printf("Erreur lors de l'ouverture du fichier.\n");
                return -1;
        }
        Student s;
        int found = 0;
        while (fscanf(fp, "%d %s", & s.numApoge, s.password) == 2) {
                if (s.numApoge == numApoge) {
                        found = 1;
                        break;
                }
        }
        fclose(fp);

        // Check student password
        if (found) {
                if (strcmp(s.password, password) == 0) {
                        printf("Connexion r\x82ussie %d\n", s.numApoge);
                        printf("\n");
                        sleep(2);
                        return 0;
                } else {
                        printf("Mot de passe invalide.\n");
                        sleep(2);
                }
        } else {
                printf("Etudiant introuvable.\n");
                sleep(2);
        }

        return 1;
}

int student_signup(int numApoge, char password[20]) {

        // Write student data to file
        FILE * fp = fopen("students.txt", "a");
        if (fp == NULL) {
                printf("Erreur lors de l'ouverture du fichier.\n");
                return -1;
        }
        fprintf(fp, "%d %s\n", numApoge, password);
        fclose(fp);

        printf("Votre compte d'\x82tudiant a \x82t\x82 cr\x82\x82 avec succ\x8As.\n");
        printf("\n");
        sleep(2);

        return 0;
}

int admin_login(char username[20], char password[20]) {

        // Read admin data from file
        FILE * fp = fopen("admins.txt", "r");
        if (fp == NULL) {
                printf("Erreur lors de l'ouverture du fichier.\n");
                return -1;
        }
        Admin a;
        int found = 0;
        while (fscanf(fp, "%s %s", a.username, a.password) == 2) {
                if (strcmp(a.username, username) == 0) {
                        found = 1;
                        break;
                }
        }
        fclose(fp);

        // Check admin password
        if (found) {
                if (strcmp(a.password, password) == 0) {
                        printf("Connexion r\x82ussie pour l'administrateur %s\n", a.username);
                        sleep(2);
                        return 0;
                } else {
                        printf("Mot de passe invalide\n");
                        return 1;
                        sleep(2);
                }
        } else {
                printf("Admin introuvable.\n");
                sleep(2);
                return 1;
        }
}

Book * add_book(Book * head) {
        Book * new_book = (Book * ) malloc(sizeof(Book));

        printf("Saisir ISBN: ");
        scanf("%lld", & (new_book -> ISBN));

        printf("Saisir titre: ");
        getchar();
        scanf("%[^\n]", new_book -> title);

        printf("Saisir auteur: ");
        getchar();
        scanf("%[^\n]", new_book -> author);

        printf("Saisir l'\x82"
                "diteur: ");
        getchar();
        scanf("%[^\n]", new_book -> publisher);

        printf("Saisir date de publication : ");
        scanf("%d", & (new_book -> publication_date));

        printf("Saisir le genre: ");
        getchar();
        scanf("%[^\n]", new_book -> genre);

        printf("Saisir disponibilit\x82: ");
        scanf("%s", new_book -> availability);

        printf("Saisir le nombre de copies: ");
        scanf("%d", & (new_book -> numCopies));

        new_book -> next = NULL;

        if (head == NULL) {
                head = new_book;
        } else {
                Book * current_book = head;
                while (current_book -> next != NULL) {
                        current_book = current_book -> next;
                }
                current_book -> next = new_book;
        }

        printf("Le livre a \x82t\x82 ajout\x82 avec succ\x8As.\n");
        sleep(2);
        printf("\n");
        printf("\n");
        return head;
}

void search_by_title(Book *head) {
    char search_title[50];
    printf("Saisir le titre \x85 rechercher: ");
    getchar();  // Consume the newline character from previous input
    scanf("%[^\n]", search_title);

    Book *current_book = head;
    while (current_book != NULL) {
        if (strcmp(current_book->title, search_title) == 0) {
            printf("Livre trouv\x82:\n");
            printf("ISBN: %lld\n", current_book->ISBN);
            printf("Titre: %s\n", current_book->title);
            printf("Auteur: %s\n", current_book->author);
            printf("Editeur: %s\n", current_book->publisher);
            printf("Date de publication: %d\n", current_book->publication_date);
            printf("Genre: %s\n", current_book->genre);
            printf("Disponibilit\x82: %s\n", current_book->availability);
            printf("\n");

            return;
        }
        current_book = current_book->next;
    }
    printf("Livre introuvable.\n");
}



void search_by_author(Book *head) {
    char author[50];
    int count = 0;
    Book *current = head;

    printf("Saisir l'auteur \x85 rechercher: ");
    getchar();  // Consume the newline character
    scanf("%[^\n]", author);

    while (current != NULL) {
        if (strcmp(current->author, author) == 0) {
            printf("Livre trouv\x82:\n");
            printf("ISBN: %lld\n", current->ISBN);
            printf("Titre: %s\n", current->title);
            printf("Auteur: %s\n", current->author);
            printf("Editeur: %s\n", current->publisher);
            printf("Date de publication: %d\n", current->publication_date);
            printf("Genre: %s\n", current->genre);
            printf("Disponibilit\x82: %s\n", current->availability);
            printf("\n");
            count++;
        }
        current = current->next;
    }

    if (count == 0) {
        printf("Aucun livre trouv\x82 de l'auteur '%s'.\n", author);
    } else {
        printf("Nombre de livres trouv\x82s de l'auteur '%s': %d\n", author, count);
    }
}


void search_by_publisher(Book *head) {
    char publisher[50];
    printf("Saisir l'\x82diteur \x85 chercher: ");
    getchar();  // Consume the newline character
    scanf("%[^\n]", publisher);

    Book *current = head;
    int count = 0;

    while (current != NULL) {
        if (strcmp(current->publisher, publisher) == 0) {
            printf("Livre trouv\x82:\n");
            printf("ISBN: %lld\n", current->ISBN);
            printf("Titre: %s\n", current->title);
            printf("Auteur: %s\n", current->author);
            printf("Editeur: %s\n", current->publisher);
            printf("Date de publication: %d\n", current->publication_date);
            printf("Genre: %s\n", current->genre);
            printf("Disponibilit\x82: %s\n", current->availability);
            printf("\n");
            count++;
        }
        current = current->next;
    }

    if (count == 0) {
        printf("Aucun livre trouv\x82 de cet éditeur.\n");
    } else {
        printf("Nombre de livres trouv\x82s de l'\x82diteur '%s': %d\n", publisher, count);
    }
}


void search_by_isbn(Book * head) {
        long long int isbn;
        printf("Saisir ISBN: ");
        scanf("%lld", & isbn);

        Book * current = head;
        while (current != NULL) {
                if (current -> ISBN == isbn) { 
                        printf("Titre: %s\n", current -> title);
                        printf("Auteur: %s\n", current -> author);
                        printf("Editeur: %s\n", current -> publisher);
                        printf("Date de publication: %d\n", current -> publication_date);
                        printf("Genre: %s\n", current -> genre);
                        printf("Disponibilit\x82: %s\n", current -> availability);
                        printf("\n");
                        return;
                }
                current = current -> next;
        }

        printf("Livre introuvable.\n");
}

void display_books_list(Book * head) {
        if (head == NULL) {
                printf("Aucun livre \x85 afficher.\n\n");
                return;
        }

        printf("%-15s %-30s %-30s %-30s %-20s %-15s %-20s %-15s\n", "ISBN", "Titre", "Auteur", "Editeur", "Date de publication", "Genre", "Nombre de copies", "Disponibilit\x82");
        printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n");

        Book * current_book = head;
        while (current_book != NULL) {
                printf("%-15lld %-30s %-30s %-30s %-20d %-15s %-20d %-15s\n", current_book -> ISBN, current_book -> title, current_book -> author, current_book -> publisher, current_book -> publication_date, current_book -> genre, current_book -> numCopies, current_book -> availability);
                current_book = current_book -> next;
        }

        printf("\n");
        printf("\n");
        printf("\n");
}

// save the linked list of books to a file;so when u close the progarm the data get saved from lists to the files
void save_books_to_file(Book * head) {
        FILE * fp = fopen("books.txt", "w");
        if (fp == NULL) {
                printf("Erreur lors de l'ouverture du fichier.\n");
                return;
        }

        Book * current_book = head;
        while (current_book != NULL) {
                fprintf(fp, "%lld,%s,%s,%s,%d,%s,%s,%d\n",
                        current_book -> ISBN,
                        current_book -> title,
                        current_book -> author,
                        current_book -> publisher,
                        current_book -> publication_date,
                        current_book -> genre,
                        current_book -> availability,
                        current_book -> numCopies
                );
                current_book = current_book -> next;
        }
        fclose(fp);
}

//load the linked list of books from a file ; so that when we reopendthe program the data get transfered from the file to the lists
Book *load_books_from_file() {
    Book *head = NULL;
    FILE *fp = fopen("books.txt", "r");
    if (fp == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return NULL;
    }
    char line[200];
    while (fgets(line, sizeof(line), fp) != NULL) {
        Book *new_book = (Book *)malloc(sizeof(Book));
        sscanf(line, "%lld,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%d\n",
               &(new_book->ISBN),
               new_book->title,
               new_book->author,
               new_book->publisher,
               &(new_book->publication_date),
               new_book->genre,
               new_book->availability,
               &(new_book->numCopies));

        new_book->next = head;
        head = new_book;
    }
    fclose(fp);
    return head;
}




void list_students() {
        FILE * fp;
        int numApoge;
        char password[20];
        int count = 0;

        fp = fopen("students.txt", "r");
        if (fp == NULL) {
                printf("Erreur lors de l'ouverture du fichier.\n");
                return;
        }

        printf("Liste des \x82tudiants:\n");
        printf("%-20s %-20s\n", "Code Apogee", "Mot de passe");
        printf("------------------------------------------\n");

        // Read student data from file and display
        while (fscanf(fp, "%d %s", & numApoge, password) == 2) {
                printf("%-20d %-20s\n", numApoge, password);
                count++;
        }

        if (count == 0) {
                printf("Aucun \x82tudiant trouv\x82.\n");
        }

        fclose(fp);
}

// Function to borrow/reserve a book by a student
void book_reservation(Book * head, int numApoge) {
        long long int isbn;
        printf("Entrer l'ISBN du livre que vous souhaitez r\x82server: ");
        scanf("%lld", & isbn);

        // Check if the book exists
        Book * current = head;
        while (current != NULL) {
                if (current -> ISBN == isbn) {
                        break;
                }
                current = current -> next;
        }

        if (current == NULL) {
                printf("Ce livre n'existe pas.\n");
                return;
        }

        // Check the availability of the book
        if (strcmp(current -> availability, "reserver") == 0) {
                printf("Ce livre est indisponible.\n");
                return;
        }

        // Decrement the number of copies
        current -> numCopies--;

        // If the number of copies is 0, change the availability to "reserved"
        if (current -> numCopies == 0) {
                strcpy(current -> availability, "reserver");
        }

        // Add the student's ID number to the queue
        struct queue_node * new_node = (struct queue_node * ) malloc(sizeof(struct queue_node));
        new_node -> numApoge = numApoge;
        new_node -> isbn = isbn;
        new_node -> next = NULL;

        // Add the node to the queue
        if (queuehead == NULL) {
                queuehead = new_node;
        } else {
                struct queue_node * current = queuehead;
                while (current -> next != NULL) {
                        current = current -> next;
                }
                current -> next = new_node;
        }

        printf("Le livre a \x82t\x82 r\x82serv\x82 avec succ\x8As.\n");
}

void show_queue() {
        if (queuehead == NULL) {
                printf("Aucun livre n'est r\x82serv\x82.\n");
                return;
        }

        printf("Liste des livres r\x82serv\x82s:\n");
        printf("%-20s %-20lld\n", "NumApoge", "ISBN");
        printf("------------------------------------------\n");

        // Iterate through the queue and print the student's ID number and the ISBN of the book
        struct queue_node * current = queuehead;
        while (current != NULL) {
                printf("%-20lld %-20lld\n", current -> numApoge, current -> isbn);
                current = current -> next;
        }
}