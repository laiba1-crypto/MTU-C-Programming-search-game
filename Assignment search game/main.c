#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESSES 6
#define WORD_SIZE 5
#define DICT_SIZE 5757

int load_word_list(char words[DICT_SIZE][WORD_SIZE + 1]);

int main() {
     
    char words[DICT_SIZE][WORD_SIZE + 1];  
    int num_words = load_word_list(words);

    
    srand(time(NULL));

   
    int index = rand() % num_words;
    char selected_word[WORD_SIZE + 1];
    strcpy(selected_word, words[index]);
 
    int guesses_remaining = MAX_GUESSES;
    char guess[WORD_SIZE + 1];
    char feedback[WORD_SIZE + 1];
    memset(feedback, '-', WORD_SIZE);
    feedback[WORD_SIZE] = '\0';
    printf("Welcome to the MTU word matching game!\n");
    printf("The select a %d letter word.\n", WORD_SIZE);
    printf("You have %d guesses remaining.\n");
    while (guesses_remaining > 0) {
        printf("You have %d guesses remaining.\n", guesses_remaining);
        printf("Enter your guess: ");
        scanf("%s", guess);
        if (strcmp(guess, selected_word) == 0) {
            printf("Congratulations, you correctly guessed the word \"%s\"!\n", selected_word);
            break;
        } else {
            printf("Sorry, \"%s\" is not the correct word.\n", guess);
  
            int num_correct_letters = 0;
            int i;
            for (i = 0; i < WORD_SIZE; i++) {
                if (guess[i] == selected_word[i]) {
                    feedback[i] = guess[i];
                    num_correct_letters++;
                }
            }
            printf("You guessed %d letters in the correct position.\n", num_correct_letters);
            printf("Feedback: %s\n", feedback);
            guesses_remaining--;
        }
    }
    if (guesses_remaining == 0) {
        printf("Sorry, you ran out of guesses. The correct word was \"%s\".\n", selected_word);
    }

    return 0;
}
