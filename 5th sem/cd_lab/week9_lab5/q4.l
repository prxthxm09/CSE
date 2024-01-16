%{
#include <stdio.h>
int scanf_count = 0;
int printf_count = 0;
%}

%%
scanf       { printf("READ"); scanf_count++; }
printf      { printf("WRITE"); printf_count++; }
.           { putchar(yytext[0]); }
\n          { putchar('\n'); }
%%

int main() {
    yylex();
    fprintf(stderr, "Number of scanf statements replaced: %d\n", scanf_count);
    fprintf(stderr, "Number of printf statements replaced: %d\n", printf_count);
    return 0;
}
int yywrap()
{
return 1;
}
