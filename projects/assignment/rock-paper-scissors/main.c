#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALWAYS 1
enum Outcome
{
    Tie = 0,
    PlayerWon = 1,
    ComputerWon = 2,
};

enum Options
{
    Rock = 0,
    Paper = 1,
    Scissor = 2,
    Error = 3,
};

enum Options getComputerChoice(int);
void exitGame();
enum Outcome calculateOutcome(enum Options, enum Options);
void displayScoreBoard(int, int, int, int);

void exitGame()
{
    printf("Thanks for playing!\n");
    exit(EXIT_SUCCESS);
}

void displayScoreBoard(int total, int won, int lost, int tied)
{
    printf("-------------------\n");
    printf("Games Played: %d\n", total);
    printf("Games Won: %d\n", won);
    printf("Games Lost: %d\n", lost);
    printf("Games Tied: %d\n", tied);
    printf("-------------------\n\n");
}

enum Options getComputerChoice(int n)
{
    if (n < 33)
    {
        return Rock;
    }
    else if (n > 33 && n < 66)
    {
        return Paper;
    }
    return Scissor;
}

enum Outcome calculateOutcome(enum Options you, enum Options computer)
{
    if (you == computer)
    {
        return Tie;
    }
    else if (you == Rock && computer == Scissor)
    {
        return PlayerWon;
    }
    else if (you == Paper && computer == Rock)
    {
        return PlayerWon;
    }
    else if (you == Scissor && computer == Paper)
    {
        return PlayerWon;
    }
    return ComputerWon;
}

enum Options parsePlayerInput(char player_input)
{
    switch (player_input)
    {
    case 'r':
        return Rock;
    case 'p':
        return Paper;
    case 's':
        return Scissor;
    default:
        return Error;
    }
}

int main(void)
{
    int total_games_played = 0;
    int total_games_won = 0;
    int total_games_lost = 0;
    int total_games_tied = 0;

    char player_input;
    enum Options player_choice;
    enum Options computer_choice;
    enum Outcome game_outcome;

    srand(time(NULL));
    int n;
    while (ALWAYS)
    {
        printf("\nPlease enter:\n'r' for rock\n'p' for paper\n's' for scissors\n'q' to exit\n'b' to display scoreboard\n\n");
        scanf(" %c", &player_input);
        if (player_input == 'q')
        {
            exitGame();
        }
        else if (player_input == 'b')
        {
            displayScoreBoard(total_games_played, total_games_won, total_games_lost, total_games_tied);
        }
        else
        {
            player_choice = parsePlayerInput(player_input);
            if (player_choice == Error)
            {
                printf("You entered an invalid input, please try again\n");
            }
            else
            {
                n = rand() % 100;
                computer_choice = getComputerChoice(n);
                game_outcome = calculateOutcome(player_choice, computer_choice);
                total_games_played++;
                switch (game_outcome)
                {
                case PlayerWon:
                    total_games_won++;
                    printf("You win!\n");
                    break;
                case ComputerWon:
                    total_games_lost++;
                    printf("Computer won!\n");
                    break;
                case Tie:
                    total_games_tied++;
                    printf("It's a tie!\n");
                    break;
                }
            }
        }
    }
    return EXIT_SUCCESS;
}
