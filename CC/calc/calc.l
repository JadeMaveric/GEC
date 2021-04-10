%{
#include "y.tab.h"
extern void yyerror(char *s);
%}
%%
"print"			{return print;}
"exit"			{return exit_command;}
[a-zA-Z]		{yylval.id = yytext[0]; return identifier;}
[0-9]+			{yylval.num = atoi(yytext); return number;}
[ \n\t]			;
[-+=;]			{return yytext[0];}
.			{ECHO; printf("unexpected character %s\n", yytext); yyerror("unexpected character");}

%%
int yywrap (void) {return 1;}
