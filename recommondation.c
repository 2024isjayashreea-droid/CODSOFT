#include <stdio.h>
#include <string.h>

// Define a structure for movies
struct Movie {
    char title[50];
    char genre[20];
};

// Function to recommend movies based on user preference
void recommend(struct Movie movies[], int n, char preference[]) {
    printf("Recommended movies for genre '%s':\n", preference);
    for (int i = 0; i < n; i++) {
        if (strstr(movies[i].genre, preference)) {
            printf("- %s (%s)\n", movies[i].title, movies[i].genre);
        }
    }
}

int main() {
    // Sample dataset
    struct Movie movies[5] = {
        {"Inception", "Sci-Fi"},
        {"Interstellar", "Sci-Fi"},
        {"Titanic", "Romance"},
        {"The Dark Knight", "Action"},
        {"Avengers", "Action"}
    };

    char user_pref[20];
    printf("Enter your preferred genre (e.g., Sci-Fi, Action, Romance): ");
    scanf("%s", user_pref);

    recommend(movies, 5, user_pref);

    return 0;
}