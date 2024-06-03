#include <stdio.h>
#include <string.h>


void reverse_in_place(char *, int);
void spin_words(const char *, char *);


int main() {
    char test1[] = "Hey fellow warriors";
    char result1[sizeof(test1)]; // Reserve memory for the result
    spin_words(test1, result1);
    printf("\"%s\" --> \"%s\"\n", test1, result1);

    char test2[] = "This is a test";
    char result2[sizeof(test2)];
    spin_words(test2, result2);
    printf("\"%s\" --> \"%s\"\n", test2, result2);

    char test3[] = "This is another test";
    char result3[sizeof(test3)];
    spin_words(test3, result3);
    printf("\"%s\" --> \"%s\"\n", test3, result3);

    return 0;
}


void reverse_in_place(char *start, int len) {
    char *end = start + len - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}


void spin_words(const char *sentence, char *result) {
    int word_len = 0;
    char *word_start = result;

    // Copying the input string to result
    strcpy(result, sentence);

    // Processing each character of the string
    for (; *result; result++) { 
        if (*result == ' ' || *result == '\0') { // End of the word
            if (word_len >= 5) {
                reverse_in_place(word_start, word_len);
            }
            word_len = 0;
            word_start = result + 1; // The begininng of the new word
        } else { // The word continues
            word_len++;
        }
    }

    // We check the last word in the line, because it does not end with a space
    if (word_len >= 5) {
        reverse_in_place(word_start, word_len);
    }
}