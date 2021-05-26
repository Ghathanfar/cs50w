#include <ctype.h>
#include <cs50.h>

// The following constants were extracted from the ascii table
// There are two series of letters, the uppercase which starts
// at index 65 in decimal notation and and the lowercase which
// starts at index 97 in decimal notation. There are 26 letters
// in each.
// http://www.asciitable.com/

#define UPPERCASE_LETTERS_START 65
#define LOWERCASE_LETTERS_START 97
#define LETTERS_COUNT 26

int main(int argc, string args[])
{
    if (argc != 2)
@@ -12,7 +23,7 @@ int main(int argc, string args[])
        return 1;
    }

    int k = atoi(args[1]) % 26; // if k is > 26, store the division remainder instead
    int k = atoi(args[1]) % LETTERS_COUNT; // if k is > 26, store the division remainder instead
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
@@ -25,10 +36,11 @@ int main(int argc, string args[])
            continue;
        }

        int ascii_offset = isupper(plaintext[i]) ? 65 : 97;
        // Uppercase letter's index has a different offset than the lowercase counterpart in ascii table
        int ascii_offset = isupper(plaintext[i]) ? UPPERCASE_LETTERS_START : LOWERCASE_LETTERS_START;

        int pi = plaintext[i] - ascii_offset;
        int ci = (pi + k) % 26;
        int ci = (pi + k) % LETTERS_COUNT;

        printf("%c", ci + ascii_offset);
    }
0 comments on commit 1355