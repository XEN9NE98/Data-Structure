/*
Data Structure Project << DSS3S4 G1 >>
1. Muhammad Haziq Aiman bin Mohd Nazaruddin (CI230058)
2. Niza Atiera Syamimie binti Zawali (AI230095)
3. Nur Shaeira binti Zulfadly (AI230036)
4. Nur 'Alimi Irfan bin Ahmad (CI230023)
*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <time.h>

struct animal { 
    char name_en[20];   
    char name_bm[20]; 
    struct animal *next;
    struct animal *prev;
}; 

struct animal *head = NULL, *current = NULL, *tail= NULL;

void insertFront(const char new_en[], const char new_bm[]) {
    struct animal *new_animal = (struct animal*) malloc(sizeof(struct animal)); // Allocate memory for new animal node

    if (new_animal == NULL) { // Check if memory allocation was successful
        printf("\n  Memory Allocation Error\n");
        return;
    }

    strncpy(new_animal->name_en, new_en, sizeof(new_animal->name_en)); // Copy English name to new node
    strncpy(new_animal->name_bm, new_bm, sizeof(new_animal->name_bm)); // Copy Malay name to new node

    new_animal->next = head; // Set next pointer of new node to current head
    new_animal->prev = NULL;

    if (head == NULL) { // If list is empty, update tail
        tail = new_animal;
    } else {
        head->prev = new_animal; // Update previous pointer of current head
    }

    head = new_animal; // Update head to point to new node
}

void insertBack(const char new_en[], const char new_bm[]) {
    struct animal *new_animal = (struct animal*) malloc(sizeof(struct animal)); // Allocate memory for new animal node

    if (new_animal == NULL) { // Check if memory allocation was successful
        printf("\n  Memory Allocation Error\n");
        return;
    }

    strncpy(new_animal->name_en, new_en, sizeof(new_animal->name_en)); // Copy English name to new node
    strncpy(new_animal->name_bm, new_bm, sizeof(new_animal->name_bm)); // Copy Malay name to new node

    new_animal->prev = tail; // Set previous pointer of new node to current tail
    new_animal->next = NULL;

    if (tail == NULL) { // If list is empty, update head
        head = new_animal;
    } else {
        tail->next = new_animal; // Update next pointer of current tail
    }

    tail = new_animal; // Update tail to point to new node
}

void print () {
    int x = 1;  
    printf("  L -> %-20s %-20s\n\n", "English Name", "Malay Name"); 
    for (current = head; current != NULL; current = current->next) { 
        if (x < 10) { 
            printf("  %d  > %-20s %-20s\n", x, current->name_en, current->name_bm); 
        } else { 
            printf("  %d > %-20s %-20s\n", x, current->name_en, current->name_bm); 
        } 
        x++;  
    } 
}

void deleteAnimal(const char name_ani[], int my_en) {
    struct animal *temp = head;
	
	if (my_en == 1){ // Delete by Malay name
	    while (temp != NULL && strcmp(temp->name_bm, name_ani) != 0) {
	        temp = temp->next;
	    }
	    if (temp == NULL) {
	        printf("\n  Animal '%s' not found.\n", name_ani);
	        return;
	    }
	} else if (my_en == 2){ // Delete by English name
	    while (temp != NULL && strcmp(temp->name_en, name_ani) != 0) {
	        temp = temp->next;
	    }
	    if (temp == NULL) {
	        printf("\n  Animal '%s' not found.\n", name_ani);
	        return;
	    }		
	} else {
		printf("\n  Invalid Input\n");
	}

    if (temp == head) { // If node to delete is the head
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL; // If list becomes empty after deletion
        }
    } else if (temp == tail) { // If node to delete is the tail
        tail = temp->prev;
        tail->next = NULL;
    } else { // Node to delete is in between
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp); // Free memory allocated for the deleted node
    printf("\n  Animal '%s' deleted successfully.\n", name_ani);
}
 
void sortEn(int ascending) {
    struct animal *after;
    char temp_en[20], temp_bm[20];
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Start measuring time

    // Traverse through the list
    for (current = head; current != NULL; current = current->next) {
        struct animal *compare = current;

        // Traverse through the remaining list to find the appropriate element
        for (after = current->next; after != NULL; after = after->next) {
            // Check for ascending order
            if (ascending && strcmp(after->name_en, compare->name_en) < 0) {
                compare = after;
            }
            // Check for descending order
            else if (!ascending && strcmp(after->name_en, compare->name_en) > 0) {
                compare = after;
            }
        }

        // Swap if necessary
        if (compare != current) {
            strcpy(temp_en, current->name_en);
            strcpy(current->name_en, compare->name_en);
            strcpy(compare->name_en, temp_en);

            strcpy(temp_bm, current->name_bm);
            strcpy(current->name_bm, compare->name_bm);
            strcpy(compare->name_bm, temp_bm);
        }
    }

    end = clock(); // Stop measuring time

    // Print the sorted list
    int x = 1;
    printf("\n  %s Order:\n\n", ascending ? "Ascending" : "Descending");
    print();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate time taken
    printf("\n  Time taken to sort: %f seconds\n", cpu_time_used); // Display time taken
}

void sortMy(int ascending) {
    struct animal *after;
    char temp_en[20], temp_bm[20];
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Start measuring time

    // Traverse through the list
    for (current = head; current != NULL; current = current->next) {
        struct animal *compare = current;

        // Traverse through the remaining list to find the appropriate element
        for (after = current->next; after != NULL; after = after->next) {
            // Check for ascending order
            if (ascending && strcmp(after->name_bm, compare->name_bm) < 0) {
                compare = after;
            }
            // Check for descending order
            else if (!ascending && strcmp(after->name_bm, compare->name_bm) > 0) {
                compare = after;
            }
        }

        // Swap if necessary
        if (compare != current) {
            strcpy(temp_en, current->name_en);
            strcpy(current->name_en, compare->name_en);
            strcpy(compare->name_en, temp_en);

            strcpy(temp_bm, current->name_bm);
            strcpy(current->name_bm, compare->name_bm);
            strcpy(compare->name_bm, temp_bm);
        }
    }

    end = clock(); // Stop measuring time

    // Print the sorted list
    printf("\n  %s Order:\n\n", ascending ? "Ascending" : "Descending");
    print();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate time taken
    printf("\n  Time taken to sort: %f seconds\n", cpu_time_used); // Display time taken
}

void searchAnimal(const char name_ani[], int my_en) {
    struct animal *temp = head;
    int x = 1, found = 0;
    printf("\n  Searching for animal '%s':\n\n", name_ani);
    
	if (my_en == 1){ // Search by Malay name
		printf("  L -> %-20s %-20s\n\n", "Malay Name", "English Name");
	    while (temp != NULL) {
	        if (strcmp(temp->name_bm, name_ani) == 0) {
	        	if (x < 10){
	        		printf("  %d  > %-20s %-20s\n", x, temp->name_bm, temp->name_en);
				} else {
					printf("  %d > %-20s %-20s\n", x, temp->name_bm, temp->name_en);
				}
	            found = 1;
	        }
	        temp = temp->next;
	        x++;
	    }
	} else if (my_en == 2){ // Search by English name
		printf("  L -> %-20s %-20s\n\n", "English Name", "Malay Name");
	    while (temp != NULL) {
	        if (strcmp(temp->name_en, name_ani) == 0) {
	        	if (x < 10){
	        		printf("  %d  > %-20s %-20s\n", x, temp->name_en, temp->name_bm);
				} else {
					printf("  %d > %-20s %-20s\n", x, temp->name_en, temp->name_bm);
				}
	            found = 1;
	        }
	        temp = temp->next;
	        x++;
	    }	
	} else {
		printf("\n  Invalid Input\n");
	}
	if (found = 0){
		printf("\n  Animal '%s' not found.\n", name_ani);
	}
}

void list_insertion() {
    // Array of initial data
    const char *animals[][2] = {
        {"rabbit", "arnab"},
        {"cow", "lembu"},
        {"bird", "burung"},
        {"snake", "ular"},
        {"giraffe", "zirafah"},
        {"kangaroo", "kanggaru"},
        {"goat", "kambing"},
        {"tiger", "harimau"},
        {"crocodile", "buaya"},
        {"bat", "kelawar"},
        {"horse", "kuda"},
        {"penguin", "penguin"},
        {"deer", "rusa"},
        {"butterfly", "rama-rama"},
        {"fish", "ikan"}
    };

    // Number of initial data entries
    size_t num_animals = sizeof(animals) / sizeof(animals[0]);

    // Insert each animal into the linked list
    for (size_t i = 0; i < num_animals; i++) {
        insertFront(animals[i][0], animals[i][1]);
    }
}

void pause() {
    printf("\n  Press Enter to continue...");
    while (getchar() != '\n');
    getchar();
}

int main() { 
    int input = 0, x = 1, inputMy = 1, inputEn = 1, inputAdd = 0;

    list_insertion(); // Initialize the linked list with predefined data

    while (x == 1) {
    	system("COLOR 1F"); // Set console text color
    	system("cls"); // Clear screen
        printf(
        "\n  1  > Sort by Malay Name\n"
        "  2  > Sort by English Name\n"
        "  ---------------------------\n"
        "  3  > Add New Data\n"
        "  4  > Delete Existing Data\n"
        "  5  > Search Existing Data\n"
        "  ---------------------------\n"
        "  6  > Terminate Program\n"
        "  ---------------------------\n"
        "  ?  > ");
        scanf("%d", &input); // Read user input
        
        switch (input) {
            case 1:
                system("cls"); // Clear screen
                system("COLOR 1F"); // Set console text color
                int inputSort_My;
                
                printf("\n  Sorting by Malay Name\n"
				"\n  Sort by :\n"
                "  1 > Ascending\n"
                "  2 > Descending\n"
                "  ? > ");
                scanf("%d", &inputSort_My); // Read sorting option
                
                if (inputSort_My == 1) {
                    system("cls"); // Clear screen
                    sortMy(1); // Sort by Malay name in ascending order
                } else if (inputSort_My == 2) {
                    system("cls"); // Clear screen
					sortMy(0); // Sort by Malay name in descending order
                } else {
                	system("COLOR 4F"); // Set console text color to indicate error
                	printf("\n  Invalid Input"); // Display error message
				}
                
                pause(); // Wait for user input before continuing
                break;
                
            case 2:
                system("cls"); // Clear screen
                system("COLOR 1F"); // Set console text color
                int inputSort_En;
                
                printf("\n  Sorting by English Name\n"
				"\n  Sort by :\n"
                "  1 > Ascending\n"
                "  2 > Descending\n"
                "  ? > ");
                scanf("%d", &inputSort_En); // Read sorting option
                
                if (inputSort_En == 1) {
                    system("cls"); // Clear screen
                    sortEn(1); // Sort by English name in ascending order
                } else if (inputSort_En == 2) {
                    system("cls"); // Clear screen
					sortEn(0); // Sort by English name in descending order
                } else {
                	system("COLOR 4F"); // Set console text color to indicate error
                	printf("\n  Invalid Input"); // Display error message
				}
                
                pause(); // Wait for user input before continuing
                break;
                
            case 3:
                system("cls"); // Clear screen
                system("COLOR 1F"); // Set console text color
                char new_en[20], new_bm[20];
                
	            printf("\n  Add New Data\n"
				"\n  Enter English Name of Animal: ");
	            scanf("%s", new_en); // Read English name of new animal
	            printf("  Enter Malay Name of Animal: ");
	            scanf("%s", new_bm); // Read Malay name of new animal
	            
                printf("\n  Add to :\n"
                "  1 > Beginning of the list\n"
                "  2 > End of the list\n"
                "  ? > ");
                scanf("%d", &inputAdd); // Read insertion option
                
                if (inputAdd == 1) {
                    system("cls"); // Clear screen
                    insertFront(new_en, new_bm); // Insert new animal at the beginning
                } else if (inputAdd == 2) {
                    system("cls"); // Clear screen
                    insertBack(new_en, new_bm); // Insert new animal at the end
                } else {
                	system("COLOR 4F"); // Set console text color to indicate error
                	printf("\n  Invalid Input\n"); // Display error message
                	pause(); // Wait for user input before continuing
                	break;
				}
				printf("\n  Updated List:\n\n"); 
				print(); // Print the updated list
				
				printf("\n  Animal '%s' added successfully.\n", new_en); // Display success message
				pause(); // Wait for user input before continuing
                break;
                
            case 4:
			    system("cls"); // Clear screen
			    system("COLOR 1F"); // Set console text color
			    
			    char del[20];
			    int inputDel;
			    
			    printf("\n  Delete Existing Data\n"
				"\n  Delete by :\n"
			           "  1 > Malay Name\n"
			           "  2 > English Name\n"
			           "  ? > ");
			    scanf("%d", &inputDel); // Read deletion option
			    
			    if (inputDel == 1) {
			        printf("\n  Enter Malay name of animal to delete: ");
			        scanf("%s", del); // Read Malay name of animal to delete
			        system("cls"); // Clear screen
			        deleteAnimal(del, inputDel); // Delete animal by Malay name
			    } else if (inputDel == 2) {
			        printf("\n  Enter English name of animal to delete: ");
			        scanf("%s", del); // Read English name of animal to delete
			        system("cls"); // Clear screen
			        deleteAnimal(del, inputDel); // Delete animal by English name    
			    } else {
			    	system("COLOR 4F"); // Set console text color to indicate error
			        printf("\n  Invalid Input\n"); // Display error message
			        pause(); // Wait for user input before continuing
			        break;
			    }
				printf("\n  Updated List:\n\n");    
				print(); // Print the updated list
			    
			    pause(); // Wait for user input before continuing
			    break;
                
            case 5:
                system("cls"); // Clear screen
                char search[20];
                int inputSearch;

			    printf("\n  Search Existing Data\n"
				"\n  Search by :\n"
			           "  1 > Malay Name\n"
			           "  2 > English Name\n"
			           "  ? > ");
			    scanf("%d", &inputSearch); // Read search option
			    
			    if (inputSearch == 1) {
			        printf("\n  Enter Malay name of animal to find: ");
			        scanf("%s", search); // Read Malay name of animal to search
			        system("cls"); // Clear screen
			        searchAnimal(search, inputSearch); // Search for animal by Malay name
			    } else if (inputSearch == 2) {
			        printf("\n  Enter English name of animal to find: ");
			        scanf("%s", search); // Read English name of animal to search
			        system("cls"); // Clear screen
			        searchAnimal(search, inputSearch); // Search for animal by English name
			    } else {
			    	system("COLOR 4F"); // Set console text color to indicate error
			        printf("\n  Invalid Input\n"); // Display error message
			    }			 
                
                pause(); // Wait for user input before continuing
                break;
                
            case 6:
                system("COLOR 0F"); // Set console text color
                printf("\n  << Program Terminated >>"); // Display termination message
                return 0; // Exit program
                
            default:
                system("cls"); // Clear screen
                system("COLOR 4F"); // Set console text color to indicate error
                printf("\n  Invalid Input!"); // Display error message
                break;
        }
    }   
}
