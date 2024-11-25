

#include <stdio.h>
#include <string.h>

struct player {
    char name[20];
    char team[20];
};

struct bowl {
    char type[10]; // seemer, pacer, spinner// N/A
    // forgot that size of string + 1 for null terminator
    char arm[6]; // left or right
    struct player ply;
};

struct bat {
    char type[10]; // top order, middle order, lower order
    char handed[8]; // lefty or righty
    struct bowl ply2;
};

// Create operations for players
void createPlayer(struct player *p, const char *name, const char *team) {
    strcpy(p->name, name);
    strcpy(p->team, team);
}

// Read operations for players
void readPlayer(const struct player *p) {
    printf("Name: %s, Team: %s\n", p->name, p->team);
}

// Update operations for players
void updatePlayer(struct player *p, const char *name, const char *team) {
    strcpy(p->name, name);
    strcpy(p->team, team);
}

// Delete operations for players
void deletePlayer(struct player *p) {
    strcpy(p->name, "");
    strcpy(p->team, "");
}

// Create operations for bowlers
void createBowler(struct bowl *b, const char *type, const char *arm, const char *name, const char *team) {
    strcpy(b->type, type);
    strcpy(b->arm, arm);
    createPlayer(&b->ply, name, team);
}

// Read operations for bowlers
void readBowler(const struct bowl *b) {
    printf("Type: %s, Arm: %s, ", b->type, b->arm);
    readPlayer(&b->ply);
}

// Update operations for bowlers
void updateBowler(struct bowl *b, const char *type, const char *arm, const char *name, const char *team) {
    strcpy(b->type, type);
    strcpy(b->arm, arm);
    updatePlayer(&b->ply, name, team);
}

// Delete operations for bowlers
void deleteBowler(struct bowl *b) {
    strcpy(b->type, "");
    strcpy(b->arm, "");
    deletePlayer(&b->ply);
}

// Create operations for batsmen
void createBatsman(struct bat *b, const char *type, const char *handed, const char *bowlType, const char *arm, const char *name, const char *team) {
    strcpy(b->type, type);
    strcpy(b->handed, handed);
    createBowler(&b->ply2, bowlType, arm, name, team);
}

// Read operations for batsmen
void readBatsman(const struct bat *b) {
    printf("Type: %s, Handed: %s, ", b->type, b->handed);
    readBowler(&b->ply2);
}

// Update operations for batsmen
void updateBatsman(struct bat *b, const char *type, const char *handed, const char *bowlType, const char *arm, const char *name, const char *team) {
    strcpy(b->type, type);
    strcpy(b->handed, handed);
    updateBowler(&b->ply2, bowlType, arm, name, team);
}

// Delete operations for batsmen
void deleteBatsman(struct bat *b) {
    strcpy(b->type, "");
    strcpy(b->handed, "");
    deleteBowler(&b->ply2);
}

// File operations for players
void storePlayerData(const char *filename, const struct player players[], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %s\n", players[i].name, players[i].team);
    }
    fclose(file);
}

// retrieve player data
void retrievePlayerData(const char *filename, struct player players[], int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }
    *size = 0;
    while (fscanf(file, "%s %s", players[*size].name, players[*size].team) != EOF) {
        (*size)++;
    }
    fclose(file);
}

// File operations for bowlers
void storeBowlerData(const char *filename, const struct bowl bowlers[], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %s %s %s\n", bowlers[i].type, bowlers[i].arm, bowlers[i].ply.name, bowlers[i].ply.team);
    }
    fclose(file);
}

// retrieve bowler data
void retrieveBowlerData(const char *filename, struct bowl bowlers[], int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }
    *size = 0;
    while (fscanf(file, "%s %s %s %s", bowlers[*size].type, bowlers[*size].arm, bowlers[*size].ply.name, bowlers[*size].ply.team) != EOF) {
        (*size)++;
    }
    fclose(file);
}

// File operations for batsmen
void storeBatsmanData(const char *filename, const struct bat batsmen[], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %s %s %s %s %s\n", batsmen[i].type, batsmen[i].handed, batsmen[i].ply2.type, batsmen[i].ply2.arm, batsmen[i].ply2.ply.name, batsmen[i].ply2.ply.team);
    }
    fclose(file);
}

// retrieve batsman data
void retrieveBatsmanData(const char *filename, struct bat batsmen[], int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }
    *size = 0;
    while (fscanf(file, "%s %s %s %s %s %s", batsmen[*size].type, batsmen[*size].handed, batsmen[*size].ply2.type, batsmen[*size].ply2.arm, batsmen[*size].ply2.ply.name, batsmen[*size].ply2.ply.team) != EOF) {
        (*size)++;
    }
    fclose(file);
}

// main function to test
int main() {
    struct player players[5];
    struct bowl bowlers[3];
    struct bat batsmen[2];
    int playerSize, bowlerSize, batsmanSize;

    // Initialize data
    createPlayer(&players[0], "James", "Australia");
    createPlayer(&players[1], "Dahl", "England");
    createPlayer(&players[2], "Virat", "India");
    createPlayer(&players[3], "Jamshed", "Pakistan");
    createPlayer(&players[4], "George", "SouthAfrica");

    createBowler(&bowlers[0], "Seemer", "Right", "Joshua", "Australia");
    createBowler(&bowlers[1], "Pacer", "Left", "David", "England");
    createBowler(&bowlers[2], "Spinner", "Right", "Michael", "India");

    createBatsman(&batsmen[0], "Top-Order", "Lefty", "Seemer", "Right", "John", "Pakistan");
    createBatsman(&batsmen[1], "Middle", "Righty", "Pacer", "Left", "James", "SouthAfrica");

    // Store and retrieve data
    printf("Players:\n");
    storePlayerData("players.txt", players, 5);
    retrievePlayerData("players.txt", players, &playerSize);
    for (int i = 0; i < playerSize; i++) {
        readPlayer(&players[i]);
    }

    printf("\nBowlers:\n");
    storeBowlerData("bowlers.txt", bowlers, 3);
    retrieveBowlerData("bowlers.txt", bowlers, &bowlerSize);
    for (int i = 0; i < bowlerSize; i++) {
        readBowler(&bowlers[i]);
    }

    printf("\nBatsmen:\n");
    storeBatsmanData("batsmen.txt", batsmen, 2);
    retrieveBatsmanData("batsmen.txt", batsmen, &batsmanSize);
    for (int i = 0; i < batsmanSize; i++) {
        readBatsman(&batsmen[i]);
    }

    return 0;
}
