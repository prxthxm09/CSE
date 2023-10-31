%{
#include <stdio.h>
#include <ctype.h>
int inside_comment = 0;
%}

%x COMMENT

%%
"/*"     { BEGIN(COMMENT); inside_comment = 1; putchar(yytext[0]); }
<COMMENT>"*/" { BEGIN(INITIAL); inside_comment = 0; putchar(yytext[0]); }
<COMMENT>.  { putchar(yytext[0]); }

<INITIAL>[A-Z] { putchar(tolower(yytext[0])); } // Convert uppercase to lowercase
<INITIAL>.|\n { putchar(yytext[0]); }

%%

int main() {
    yylex();
    return 0;
}
int yywrap()
{
return 1;
}



