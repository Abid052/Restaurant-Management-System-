//function Prototype
void display_menu(void);
void save_choices( char* filename, int choices[], int numChoices, float totalAmount, int quantities[], char phoneNumber[]);
void display_file_info( char* filename) ;
void place_order(void);
void generate_bill(void);


//Creating structure
struct MenuItem {
    char name[50];
    float price;
    char category[50];
};

//initializing Array of structure
struct MenuItem menu[] = {
    {"French Fries", 100.0, "Appetizers"},
    {"Samosa", 50.0, "Appetizers"},
    {"Fuchka", 100.0, "Appetizers"},
    {"Chicken MOMO", 200.0, "Appetizers"},
    {"Soup", 250.0, "Appetizers"},
    {"Chips & Dips", 200.0, "Appetizers"},
    {"Club Sandwich", 300.0, "Sandwiches"},
    {"Chicken Burger", 250.0, "Sandwiches"},
    {"Sub Sandwich", 300.0, "Sandwiches"},
    {"Zinger Burger", 400.0, "Sandwiches"},
    {"Butter Chicken", 700.0, "Grills"},
    {"Chicken Tikka", 900.0, "Grills"},
    {"Nun Roti", 700.0, "Grills"},
    {"CocaCola", 60.0, "Drinks"},
    {"7up", 60.0, "Drinks"},
    {"Fanta", 60.0, "Drinks"},
    {"Water", 20.0, "Drinks"},
};


//Function Body
void display_menu(void) {
    printf("          <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< MENU >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   \n\n");
    printf("*********************************** Appetizers **************************************************\n");
    for (int i = 0; i < 17; i++) {
        if (strcmp(menu[i].category, "Appetizers") == 0) {
            printf("\n%d. %20s   Rs.%.2f/-\n", i + 1, menu[i].name, menu[i].price);
        }
    }
    printf("\n************************************ Sandwiches ***********************************************\n");
    for (int i = 0; i < 17; i++) {
        if (strcmp(menu[i].category, "Sandwiches") == 0) {
            printf("\n%d. %20s    Rs.%.2f/-\n", i + 1, menu[i].name, menu[i].price);
        }
    }
    printf("\n**************************************** Grills ***********************************************\n");
    for (int i = 0; i < 17; i++) {
        if (strcmp(menu[i].category, "Grills") == 0) {
            printf("\n%d. %20s    Rs.%.2f/-\n", i + 1, menu[i].name, menu[i].price);
        }
    }
    printf("\n************************************ Soft Drinks **********************************************\n");
    for (int i = 0; i < 17; i++) {
        if (strcmp(menu[i].category, "Drinks") == 0) {
            printf("\n%d. %20s    Rs.%.2f/-\n", i + 1, menu[i].name, menu[i].price);
        }
    }
}

//function Body
// save user Information in a file
void save_choices( char* filename, int choices[], int numChoices, float totalAmount, int quantities[], char phoneNumber[] ) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fprintf(file, "\nYou chose the following items:\n\n");
    for (int i = 0; i < numChoices; i++) {
        int index = choices[i] - 1;
        fprintf(file, "%s - Quantity: %d\n", menu[index].name, quantities[i]);
    }

    fprintf(file, "\nNumber of the items: %d\n", numChoices);
    fprintf(file, "Total Amount: Rs.%.2f\n", totalAmount);
    fprintf(file, "Phone Number: %s\n", phoneNumber);
    fclose(file);
    printf(" ________________________USER CHOICES SAVED SUCCESSFULLY____________________ \n");
}
//function Body
//Read user information from a file
void display_file_info( char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    printf("\n ------------------USER INFORMATION :%s------------------------- \n", filename);

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}
//function Body

void place_order(void) {

    int choice;
    const int maxChoices = 50;
    int choices[maxChoices];
    int numChoices = 0;
    float totalAmount = 0.0;
    int quantities[maxChoices];
    char phoneNumber[15];

    while (numChoices < maxChoices) {
        printf("Enter the number of the item you want to order (0 to stop): ");
        if (scanf("%d", &choice) == 1 && choice != 0) {
            if (choice < 1 || choice > 17) {
                printf("Invalid choice. Please enter a number between 1 and 17.\n");
                continue;
            }
            choices[numChoices] = choice;
            printf("Enter the quantity of the item %d: ", numChoices + 1);
            scanf("%d", &quantities[numChoices]);
            int index = choice - 1;
            totalAmount += menu[index].price * quantities[numChoices];//Calculating Total Ammount
            numChoices++;
        } else {
            break;
        }
    }
    while(1){
     printf(" \n\nEnter  your 11-digit phone number for Bikash payment: ");
     scanf("%s", phoneNumber);
     if(strlen(phoneNumber)!=11)
        { printf("invalid number.Please enter again.");
          continue;
        }
        break;
    }

    save_choices("chosen_items.txt", choices, numChoices, totalAmount, quantities,phoneNumber );

}


void generate_bill(void) {
     char filename[] = "chosen_items.txt";

    display_file_info(filename);
}



