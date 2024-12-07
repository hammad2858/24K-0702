#include <stdio.h>
#include <string.h>

#define BALLS 12


typedef struct {
    char playerName[50];
    int ballScores[BALLS];
    int totalScore;
} Player;


void playGame(Player* player);
int validateScore(int score);
void findWinner(Player player1, Player player2);
void displayMatchScoreboard(Player player1, Player player2);

int main() {
    
    Player player1, player2;

    
    player1.totalScore = 0;
    player2.totalScore = 0;

    
    printf("Enter Player 1's name: ");
    fgets(player1.playerName, sizeof(player1.playerName), stdin);
    strtok(player1.playerName, "\n"); 

    printf("Enter Player 2's name: ");
    fgets(player2.playerName, sizeof(player2.playerName), stdin);
    strtok(player2.playerName, "\n"); 

    
    printf("\n--- %s's Turn ---\n", player1.playerName);
    playGame(&player1);

    printf("\n--- %s's Turn ---\n", player2.playerName);
    playGame(&player2);

   
    displayMatchScoreboard(player1, player2);
    findWinner(player1, player2);

    return 0;
}


void playGame(Player* player) {
    printf("Enter scores for each ball (0-6):\n");
    for (int i = 0; i < BALLS; i++) {
        int score;
        printf("Ball %d: ", i + 1);
        scanf("%d", &score);
        player->ballScores[i] = validateScore(score);
        player->totalScore += player->ballScores[i];
    }
}


int validateScore(int score) {
    if (score < 0 || score > 6) {
        printf("Invalid score! Ball marked, but no runs added.\n");
        return 0;
    }
    return score;
}


void findWinner(Player player1, Player player2) {
    printf("\n--- Match Result ---\n");
    if (player1.totalScore > player2.totalScore) {
        printf("%s wins with %d runs!\n", player1.playerName, player1.totalScore);
    } else if (player2.totalScore > player1.totalScore) {
        printf("%s wins with %d runs!\n", player2.playerName, player2.totalScore);
    } else {
        printf("It's a tie! Both players scored %d runs.\n", player1.totalScore);
    }
}


void displayMatchScoreboard(Player player1, Player player2) {
    printf("\n--- Match Scoreboard ---\n");

    for (int i = 0; i < 2; i++) {
        Player player = i == 0 ? player1 : player2;
        printf("\n%s's Performance:\n", player.playerName);
        printf("Ball Scores: ");
        for (int j = 0; j < BALLS; j++) {
            printf("%d ", player.ballScores[j]);
        }
        double averageScore = (double)player.totalScore / BALLS;
        printf("\nTotal Score: %d\n", player.totalScore);
        printf("Average Score: %.2f\n", averageScore);
    }
}
