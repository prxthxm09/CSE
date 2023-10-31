%{
int vowel_count = 0;
int consonant_count = 0;
%}

%%
[aAeEiIoOuU]   { vowel_count++; }
[^aAeEiIoOuU" "0-9]      { consonant_count++; }
.  {}
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    printf("Vowels: %d\nConsonants: %d\n", vowel_count, consonant_count);
    return 0;
}
