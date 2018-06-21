all: sql.c lex.yy.c y.tab.c
	gcc main.c lex.yy.c y.tab.c -o main 

lex.yy.c: sql.l
	flex sql.l
y.tab.c: sql.y
	yacc -d sql.y

clean:
	rm main lex.yy.c y.tab.c y.tab.h sql.c 
