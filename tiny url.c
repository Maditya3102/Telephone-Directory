#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

#define MAX_URL_LENGTH 1024
#define HASH_LENGTH 16

void generateShortURL(const char *url, char *shortURL) {
    MD5_CTX context;
    unsigned char digest[HASH_LENGTH];

    MD5_Init(&context);
    MD5_Update(&context, url, strlen(url));
    MD5_Final(digest, &context);

    for (int i = 0; i < HASH_LENGTH; i++) {
        sprintf(&shortURL[i * 2], "%02x", (unsigned int)digest[i]);
    }

    shortURL[8] = '\0';
}

int main() {
    char originalURL[MAX_URL_LENGTH];
    char shortURL[9];

    printf("Enter the URL to shorten: ");
    fgets(originalURL, MAX_URL_LENGTH, stdin);
    originalURL[strcspn(originalURL, "\n")] = '\0';

    generateShortURL(originalURL, shortURL);

    printf("Shortened URL: http://example.com/%s\n", shortURL);

    return 0;
}
