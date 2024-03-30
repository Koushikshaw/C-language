#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char ingredients[200];
    char instructions[200];
} Recipe;

void addRecipe(Recipe *recipes, int *numRecipes, FILE *file);
void searchRecipe(Recipe *recipes, int numRecipes);
void updateRecipe(Recipe *recipes, int numRecipes, FILE *file);

int main() {
    Recipe recipes[100];
    int numRecipes = 0;
    FILE *file = fopen("recipes.txt", "r+");

    if (file == NULL) {
        file = fopen("recipes.txt", "w+");
        if (file == NULL) {
            printf("Error: Unable to open file.\n");
            return 1;
        }
    }

    // Load recipes from file
    while (fread(&recipes[numRecipes], sizeof(Recipe), 1, file)) {
        numRecipes++;
    }

    int choice = 0;
    while (choice != 4) {
        printf("\nRecipe Book\n");
        printf("1. Add Recipe\n");
        printf("2. Search Recipe\n");
        printf("3. Update Recipe\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecipe(recipes, &numRecipes, file);
                break;
            case 2:
                searchRecipe(recipes, numRecipes);
                break;
            case 3:
                updateRecipe(recipes, numRecipes, file);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    // Save recipes to file
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < numRecipes; i++) {
        fwrite(&recipes[i], sizeof(Recipe), 1, file);
    }

    fclose(file);

    return 0;
}

void addRecipe(Recipe *recipes, int *numRecipes, FILE *file) {
    if (*numRecipes >= 100) {
        printf("Error: Recipe book is full.\n");
        return;
    }

    printf("Enter recipe name: ");
    getchar();
    gets(recipes[*numRecipes].name);
    printf("Enter ingredients: ");
    gets(recipes[*numRecipes].ingredients);
    printf("Enter instructions: ");
    gets(recipes[*numRecipes].instructions);

    (*numRecipes)++;

    fwrite(&recipes[*numRecipes - 1], sizeof(Recipe), 1, file);
}

void searchRecipe(Recipe *recipes, int numRecipes) {
    char name[50];
    printf("Enter recipe name: ");
    getchar();
    gets(name);

    for (int i = 0; i < numRecipes; i++) {
        if (strcmp(recipes[i].name, name) == 0) {
            printf("Recipe found:\n");
            printf("Name: %s\n", recipes[i].name);
            printf("Ingredients: %s\n", recipes[i].ingredients);
            printf("Instructions: %s\n", recipes[i].instructions);
            return;
        }
    }
}
void updateRecipe(Recipe *recipes, int numRecipes, FILE *file) {
    char name[50];
    printf("Enter recipe name to update: ");
    getchar();
    gets(name);

    // Find the recipe to update
    int index = -1;
    for (int i = 0; i < numRecipes; i++) {
        if (strcmp(recipes[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Recipe not found.\n");
        return;
    }

    // Update recipe
    printf("Enter new recipe name: ");
    // getchar();
    gets(recipes[index].name);
    printf("Enter new ingredients: ");
    gets(recipes[index].ingredients);
    printf("Enter new instructions: ");
    gets(recipes[index].instructions);

    // Save updated recipe to file
    fseek(file, index * sizeof(Recipe), SEEK_SET);
    fwrite(&recipes[index], sizeof(Recipe), 1, file);
}