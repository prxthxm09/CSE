%{
int posIntCount = 0;
int negIntCount = 0;
int posFloatCount = 0;
int negFloatCount = 0;
%}

%%
[0-9]+         { posIntCount++; }
-[0-9]+        { negIntCount++; }
[0-9]+\.[0-9]+ { posFloatCount++; }
-[0-9]+\.[0-9]+ { negFloatCount++; }
.|\n           ;
%%

int main(void) {
    yylex();
    printf("Positive Integers: %d\n", posIntCount);
    printf("Negativeegers: %d\n", negIntCount);
    printf("Positive Floating Point Numbers: %d\n", posFloatCount);
    printf("Negative Floating Point Numbers: %d\n", negFloatCount);
    return 0;
}
int yywrap()
{
return 1;
}
