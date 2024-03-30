#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50];
    char ingredients[200];
    char instructions[200];
} Recipe;

void addRecipe(Recipe *recipes, int *numRecipes, FILE *file);
void searchRecipe(Recipe *recipes, int numRecipes);
void updateRecipe(Recipe *recipes, int numRecipes, FILE *file);

int main()
{
    Recipe recipes[100];
    int numRecipes = 0;
    FILE *file = fopen("recipes.txt", "r+");

    if (file == NULL)
    {
        file = fopen("recipes.txt", "w+");
        if (file == NULL)
        {
            printf("Error: Unable to open file.\n");
            return 1;
        }
    }

    // Load recipes from file
    while (fread(&recipes[numRecipes], sizeof(Recipe), 1, file))
    {
        numRecipes++;
    }

    int choice = 0;
        printf("\t\tRECIPIE BOOK\n");
    while (choice != 4)
    {
        printf("\tYOU CAN PERFORM THESE: \n");
        printf("1. Add Recipe\n");
        printf("2. Search Recipe\n");
        printf("3. Update Recipe\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("You choosed to Add a new recipie!\n");
            addRecipe(recipes, &numRecipes, file);
            break;
        case 2:
            printf("You choosed to search a recipie from the book!\n");
            searchRecipe(recipes, numRecipes);
            break;
        case 3:
            printf("You choosed to modify a recipie alredy in the book!\n");
            updateRecipe(recipes, numRecipes, file);
            break;
        case 4:
            printf("Programm is ending!!");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    // Save recipes to file
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < numRecipes; i++)
    {
        fwrite(&recipes[i], sizeof(Recipe), 1, file);
    }

    fclose(file);

    return 0;
}

void addRecipe(Recipe *recipes, int *numRecipes, FILE *file)
{
    if (*numRecipes >= 100)
    {
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

void searchRecipe(Recipe *recipes, int numRecipes)
{
    char name[50];
    printf("Enter recipe name: ");
    getchar();
    gets(name);

    int found = 0;
    for (int i = 0; i < numRecipes; i++)
    {
        if (strcmp(recipes[i].name, name) == 0)
        {
            found = 1;
            printf("Recipe found:\n\n");
            printf("Name: %s\n", recipes[i].name);
            printf("\n");
            printf("Ingredients:\n%s\n", recipes[i].ingredients);
            printf("\n");
            printf("Instructions:\n%s\n", recipes[i].instructions);
            break;
        }
    }

    if (!found)
    {
        printf("Recipe not found!\n");
    }
}
void updateRecipe(Recipe *recipes, int numRecipes, FILE *file)
{
    char name[50];
    printf("Enter recipe name to update: ");
    getchar();
    gets(name);

    // Find the recipe to update
    int index = -1;
    for (int i = 0; i < numRecipes; i++)
    {
        if (strcmp(recipes[i].name, name) == 0)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Recipe not found.\n");
        return;
    }

    // Update recipe
    int choice = 0;
    while (choice != 4)
    {
        printf("\nWhat would you like to update?\n");
        printf("1. Recipe name\n");
        printf("2. Ingredients\n");
        printf("3. Instructions\n");
        printf("4. Finish updating\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter new recipe name: ");
            getchar();
            gets(recipes[index].name);
            break;
        case 2:
            printf("Enter new ingredients: ");
            getchar();
            gets(recipes[index].ingredients);
            break;
        case 3:
            printf("Enter new instructions: ");
            getchar();
            gets(recipes[index].instructions);
            break;
        case 4:
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
        // Save updated recipe to file
        fseek(file, index * sizeof(Recipe), SEEK_SET);
        fwrite(&recipes[index], sizeof(Recipe), 1, file);
}