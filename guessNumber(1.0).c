#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iso646.h>
#include <stdbool.h>
void level1(void);
void cl(void);
int main(void) {
    level1();

    return 0;
}

void level1(void) {
    int smallNumber = 0;
    int bigNumber = 100;
    srand((unsigned int) time(NULL));
    const int numberToGuess = rand() % 101;
    int numberInput = -1;
    typedef enum {notEqual, equal, illegal} Status;
    Status status = notEqual;
    while (numberInput != numberToGuess) {
        if(status == notEqual)
            printf("Please enter a number between %d and %d: ", smallNumber, bigNumber);
        else if(status == equal) {
            printf("You get it! The answer is: %d\n", bigNumber);
            return ;
        } else {
            status = notEqual;
        }
        while (scanf("%d", &numberInput) == 0) {
            printf("Please enter a number!!!\n");
            cl();
        }
        if (numberInput > bigNumber or numberInput < smallNumber) {
            printf("Are you sb? Enter a number between %d and %d!!!\n", smallNumber, bigNumber);
            status = illegal;
        } else {
            if (numberInput < numberToGuess) {
                printf("Too small!\n");
                smallNumber = numberInput + 1;
            } else if (numberInput > numberToGuess) {
                printf("Too big!\n");
                bigNumber = numberInput - 1;
            } else {
                printf("You are a big clever!\n");
                return;
            }
        }
        if(smallNumber == bigNumber) {
            status = equal;
        }
    }


}

void cl(void) {
    char b;
    do {
        scanf("%c", &b);
    } while (b != '\n');
}