#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct token
{
    char token_name [100];
    int index;
    unsigned int row,col; //Line numbers.
};
char keywords[][20] = {
        "auto", "break", "case", "char", "const",
        "continue", "default", "do", "double", "else",
        "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return",
        "short", "signed", "sizeof", "static", "struct",
        "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"
    };

int main() {
    struct token tokens[100];
    int numTokens=0;
    char c, buf[10];
    FILE *fp = fopen("input.c", "r");
    int row = 1, col = 1;

    if (fp == NULL) {
        printf("Cannot open file\n");
        exit(0);
    }

    c = fgetc(fp);
    while (c != EOF) {
        if (isspace(c)) {
            if (c == '\n') {
                row++;
                col = 1;
            } else {
                col++;
            }
            c = fgetc(fp);
            continue;
        }

        // Handle rel operators
        int i=0;
        buf[i++] = c;
    buf[i] = '\0'; 

    if (c == '=') {
            c = fgetc(fp);
            if (c == '=') {
                buf[i++] = c;
                buf[i] = '\0';
                strcpy(tokens[numTokens].token_name, buf);
                    tokens[numTokens].row = row;
                    tokens[numTokens].col = col;
                    numTokens++;
         } else {
                strcpy(tokens[numTokens].token_name, buf);
                    tokens[numTokens].row = row;
                    tokens[numTokens].col = col;
                    numTokens++;
         }
    } else if (c == '<' || c == '>' || c == '!') {
            c = fgetc(fp);
            if (c == '=') {
             buf[i++] = c;
            }
            buf[i] = '\0';
         strcpy(tokens[numTokens].token_name, buf);
                    tokens[numTokens].row = row;
                    tokens[numTokens].col = col;
                    numTokens++;
    } else {
         buf[i] = '\0';
    }

        // Handle identifiers and keywords
        int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    if (isspace(c)) {
            if (c == '\n') {
                row++;
                col = 1;
            } else {
                col++;
            }
            c = fgetc(fp);
            continue;
        }
        if (isalpha(c) || c == '_') {
            int i = 0;
            buf[i++] = c;
            c = fgetc(fp);
            while (isalnum(c) || c == '_') {
                buf[i++] = c;
                c = fgetc(fp);
            }
            buf[i] = '\0';

            int isKeyword = 0;
            for (int j = 0; j < numKeywords; j++) {
                if (strcmp(buf, keywords[j]) == 0) {
                    strcpy(tokens[numTokens].token_name, buf);
                    tokens[numTokens].row = row;
                    tokens[numTokens].col = col;
                    numTokens++;
                    isKeyword = 1;
                    break;
                }
            }

            if (!isKeyword) {
                strcpy(tokens[numTokens].token_name, buf);
                    tokens[numTokens].row = row;
                    tokens[numTokens].col = col;
                    numTokens++;
            }

            col += i;
            continue;
        }

        // Handle numerical constants
        if (isdigit(c)) {
            int i = 0;
            buf[i++] = c;
            c = fgetc(fp);
            while (isdigit(c)) {
                buf[i++] = c;
                c = fgetc(fp);
            }
            buf[i] = '\0';
            strcpy(tokens[numTokens].token_name, buf);
                    tokens[numTokens].row = row;
                    tokens[numTokens].col = col;
                    numTokens++;
            col += i;
            continue;
        }

        // Handle string literals
        if (c == '"') {
            int i = 0;
            buf[i++] = c;
            c = fgetc(fp);
            while (c != EOF && c != '"') {
                buf[i++] = c;
                c = fgetc(fp);
            }
            if (c == '"') {
                buf[i++] = c;
                buf[i] = '\0';
                strcpy(tokens[numTokens].token_name, buf);
                    tokens[numTokens].row = row;
                    tokens[numTokens].col = col;
                    numTokens++;
            } else {
                strcpy(tokens[numTokens].token_name, buf);
                    tokens[numTokens].row = row;
                    tokens[numTokens].col = col;
                    numTokens++;
            }
            col += i;
            c = fgetc(fp); // Move past the closing double quote or EOF
            continue;
        }

        col++;
        c = fgetc(fp);
}
    for (int j = 0; j < numTokens; j++) {
        printf("<%s,%d,%d>\n", tokens[j].token_name, tokens[j].row, tokens[j].col);
    }

    fclose(fp);
    return 0;
}
