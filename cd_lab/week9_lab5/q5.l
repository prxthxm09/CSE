%{
#include <stdio.h>
%}

%%
[0-9]+ {
    int decimal = atoi(yytext);
    printf("Decimal: %d, Hexadecimal: 0x%X\n", decimal, decimal);
}
.|\n { putchar(yytext[0]); } 
%%

int main() {
    yylex();
    return 0;
}
int yywrap()
{
return 1;
}
