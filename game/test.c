//
// Created by hossam on 03/10/2021.
//

// scanf demo

#include <stdio.h>
#include <stdlib.h>

// Important: scanf() input specifiers like "%d" (to match integer)
// generally ignore leading spaces, except: "%c". So, you need to use " %c"
// to skip explicitly leading white-space (space, tab, newline, ...).

int main(void)
{
    int r;

    // SCAN OF A SINGLE INTEGER
    printf("> Enter a number?\n");
    unsigned int n = 0;
    r = scanf(" %u", &n); // try to match 1 unsigned int (skipping leading white-space)
    if (r == 1)           // matching success
    {
        printf("Matching success of %u!\n", n);
    }
    else if (r == 0) // matching failure
    {
        printf("Matching failure: this is not an unsigned int!\n");
        exit(EXIT_FAILURE);
    }
    else if (r == EOF) // end of file (or <CTRL+D>)
    {
        printf("End of File!\n");
        exit(EXIT_SUCCESS);
    }

    // SCAN LOOP OF CHARACTERS
    printf("> Enter a sequence of %u characters:\n", n);

    for (unsigned int i = 0; i < n; i++)
    {
        char c;
        printf("[%u] Enter a character?\n", i);
        r = scanf(" %c", &c); // try to match 1 char (skipping leading white-space)
        if (r == 1)           // matching success
        {
            printf("[%u] I read <%c>\n", i, c);
        }
        else if (r == EOF) // end of file (or <CTRL+D>)
        {
            printf("End of File!\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            printf("Matching failure!\n"); // this should never happens...
            // continue...
        }
    }
    printf("End of loop!\n");

    return EXIT_SUCCESS;
}