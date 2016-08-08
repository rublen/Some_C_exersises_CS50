#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Wrong number of arguments\n");
        return 1;
    }
    int k = atoi(argv[1]);
    string text = GetString();
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (islower(text[i])) {
            printf("%c", 'a' + (text[i] - 'a' + k) % 26);
        } else if (isupper(text[i])) {
            printf("%c",  'A' + (text[i] - 'A' + k) % 26);
        } else printf("%c", text[i]);
    }
    printf("\n");
    return 0;
}
