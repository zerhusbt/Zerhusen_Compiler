#
# Makefile for Benjamin Zerhsuen's Compiler
# EECE 6083
# 11/15/2013
#

# Flags
CC = g++
CFLAGS = -Wall -g -m32
LDFLAGS = -m elf_i386
TARGET = Compiler

all : ${TARGET}

# Link and build object files from Lexer, ...
${TARGET} : ObjFiles/Lexer/TopLexer.o ObjFiles/Symbols/TopSymbol.o ObjFiles/Inter/TopInter.o
	${CC} ${CFLAGS} ObjFiles/Lexer/TopLexer.o ObjFiles/Symbols/TopSymbol.o ObjFiles/Inter/TopInter.o -o ${TARGET}

# Link all object files for Lexer
ObjFiles/Lexer/TopLexer.o : ObjFiles/Lexer/main.o ObjFiles/Lexer/Tag.o ObjFiles/Lexer/Token.o ObjFiles/Lexer/Num.o ObjFiles/Lexer/Real.o ObjFiles/Lexer/Word.o ObjFiles/Lexer/Lexer.o
	ld ${LDFLAGS} -r ObjFiles/Lexer/main.o ObjFiles/Lexer/Tag.o ObjFiles/Lexer/Token.o ObjFiles/Lexer/Num.o ObjFiles/Lexer/Real.o ObjFiles/Lexer/Word.o ObjFiles/Lexer/Lexer.o -o ObjFiles/Lexer/TopLexer.o

# Link all object files for Symbols
ObjFiles/Symbols/TopSymbol.o : ObjFiles/Symbols/Env.o ObjFiles/Symbols/Type.o ObjFiles/Symbols/Array.o
	ld ${LDFLAGS} -r ObjFiles/Symbols/Env.o ObjFiles/Symbols/Type.o ObjFiles/Symbols/Array.o -o ObjFiles/Symbols/TopSymbol.o

# Link all object files for Inter
ObjFiles/Inter/TopInter.o : ObjFiles/Inter/Node.o ObjFiles/Inter/Expr.o ObjFiles/Inter/Id.o ObjFiles/Inter/Temp.o ObjFiles/Inter/Op.o ObjFiles/Inter/Arith.o ObjFiles/Inter/Unary.o
	ld ${LDFLAGS} -r ObjFiles/Inter/Node.o ObjFiles/Inter/Expr.o ObjFiles/Inter/Id.o ObjFiles/Inter/Temp.o ObjFiles/Inter/Op.o ObjFiles/Inter/Arith.o ObjFiles/Inter/Unary.o -o ObjFiles/Inter/TopInter.o

# Create individual object files for Lexer components
ObjFiles/Lexer/main.o : Src/Lexer/main.cpp Src/Lexer/main.h
	${CC} ${CFLAGS} -c Src/Lexer/main.cpp -o ObjFiles/Lexer/main.o

ObjFiles/Lexer/Tag.o : Src/Lexer/Tag.cpp Src/Lexer/Tag.h
	${CC} ${CFLAGS} -c Src/Lexer/Tag.cpp -o ObjFiles/Lexer/Tag.o

ObjFiles/Lexer/Token.o : Src/Lexer/Token.cpp Src/Lexer/Token.h
	${CC} ${CFLAGS} -c Src/Lexer/Token.cpp -o ObjFiles/Lexer/Token.o

ObjFiles/Lexer/Num.o : Src/Lexer/Num.cpp Src/Lexer/Num.h
	${CC} ${CFLAGS} -c Src/Lexer/Num.cpp -o ObjFiles/Lexer/Num.o

ObjFiles/Lexer/Real.o : Src/Lexer/Real.cpp Src/Lexer/Real.h
	${CC} ${CFLAGS} -c Src/Lexer/Real.cpp -o ObjFiles/Lexer/Real.o

ObjFiles/Lexer/Word.o : Src/Lexer/Word.cpp Src/Lexer/Word.h
	${CC} ${CFLAGS} -c Src/Lexer/Word.cpp -o ObjFiles/Lexer/Word.o

ObjFiles/Lexer/Lexer.o : Src/Lexer/Lexer.cpp Src/Lexer/Lexer.h
	${CC} ${CFLAGS} -c Src/Lexer/Lexer.cpp -o ObjFiles/Lexer/Lexer.o

# Create individual object files for Symbols components
ObjFiles/Symbols/Env.o : Src/Symbols/Env.cpp Src/Symbols/Env.h
	${CC} ${CFLAGS} -c Src/Symbols/Env.cpp -o ObjFiles/Symbols/Env.o

ObjFiles/Symbols/Type.o : Src/Symbols/Type.cpp Src/Symbols/Type.h
	${CC} ${CFLAGS} -c Src/Symbols/Type.cpp -o ObjFiles/Symbols/Type.o

ObjFiles/Symbols/Array.o : Src/Symbols/Array.cpp Src/Symbols/Array.h
	${CC} ${CFLAGS} -c Src/Symbols/Array.cpp -o ObjFiles/Symbols/Array.o

# Create individual object files for Inter components
ObjFiles/Inter/Node.o : Src/Inter/Node.cpp Src/Inter/Node.h
	${CC} ${CFLAGS} -c Src/Inter/Node.cpp -o ObjFiles/Inter/Node.o

ObjFiles/Inter/Expr.o : Src/Inter/Expr.cpp Src/Inter/Expr.h
	${CC} ${CFLAGS} -c Src/Inter/Expr.cpp -o ObjFiles/Inter/Expr.o

ObjFiles/Inter/Id.o : Src/Inter/Id.cpp Src/Inter/Id.h
	${CC} ${CFLAGS} -c Src/Inter/Id.cpp -o ObjFiles/Inter/Id.o

ObjFiles/Inter/Op.o : Src/Inter/Op.cpp Src/Inter/Op.h
	${CC} ${CFLAGS} -c Src/Inter/Op.cpp -o ObjFiles/Inter/Op.o

ObjFiles/Inter/Arith.o : Src/Inter/Arith.cpp Src/Inter/Arith.h
	${CC} ${CFLAGS} -c Src/Inter/Arith.cpp -o ObjFiles/Inter/Arith.o

ObjFiles/Inter/Temp.o : Src/Inter/Temp.cpp Src/Inter/Temp.h
	${CC} ${CFLAGS} -c Src/Inter/Temp.cpp -o ObjFiles/Inter/Temp.o

ObjFiles/Inter/Unary.o : Src/Inter/Unary.cpp Src/Inter/Unary.h
	${CC} ${CFLAGS} -c Src/Inter/Unary.cpp -o ObjFiles/Inter/Unary.o


# Cleanup all object files and the executable
clean :
	rm -rf ObjFiles/Lexer/*o ObjFiles/Symbols/*o ${TARGET} 