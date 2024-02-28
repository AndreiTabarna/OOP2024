#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    char words[20][20];
    int i, j, k, count, len;

    scanf("%[^\n]s", sentence);

    len = strlen(sentence);
    count = 0;

    for (i = 0; i < len; i++) {
        if (sentence[i] == ' ') {
            words[count][k] = '\0';
            count++;
            k = 0;
        } else {
            words[count][k++] = sentence[i];
        }
    }
    words[count][k] = '\0';
    count++;

    for (i = 0; i < count-1; i++) {
        for (j = i+1; j < count; j++) {
            if (strlen(words[i]) < strlen(words[j]) || (strlen(words[i]) == strlen(words[j]) && strcmp(words[i], words[j]) > 0)) {
                char temp[20];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    for (i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}

