#
# Makefile for Benjamin Zerhsuen's Compiler
# EECE 6083
# 11/15/2013
#

# Flags
CC = g++
CFLAGS = -Wall -g -m32 -std=c++0x
LDFLAGS = -m elf_i386
TARGET = Compiler

all : ${TARGET}

# Link and build object files from Lexer, Symbols, Inter & Parser
${TARGET} : ObjFiles/Main/TopMain.o ObjFiles/Lexer/TopLexer.o ObjFiles/Symbols/TopSymbol.o ObjFiles/Inter/TopInter.o ObjFiles/Parser/TopParser.o
	${CC} ${CFLAGS} ObjFiles/Main/TopMain.o ObjFiles/Lexer/TopLexer.o ObjFiles/Symbols/TopSymbol.o ObjFiles/Inter/TopInter.o ObjFiles/Parser/TopParser.o -o ${TARGET}

# Link all object files for Main
ObjFiles/Main/TopMain.o : ObjFiles/Main/Main.o ObjFiles/Main/Files.o
	ld ${LDFLAGS} -r ObjFiles/Main/Main.o ObjFiles/Main/Files.o -o ObjFiles/Main/TopMain.o

# Link all object files for Lexer
ObjFiles/Lexer/TopLexer.o : ObjFiles/Lexer/Tag.o ObjFiles/Lexer/Token.o ObjFiles/Lexer/Num.o ObjFiles/Lexer/Real.o ObjFiles/Lexer/Word.o ObjFiles/Lexer/Lexer.o
	ld ${LDFLAGS} -r ObjFiles/Lexer/Tag.o ObjFiles/Lexer/Token.o ObjFiles/Lexer/Num.o ObjFiles/Lexer/Real.o ObjFiles/Lexer/Word.o ObjFiles/Lexer/Lexer.o -o ObjFiles/Lexer/TopLexer.o

# Link all object files for Symbols
ObjFiles/Symbols/TopSymbol.o : ObjFiles/Symbols/Env.o ObjFiles/Symbols/Type.o ObjFiles/Symbols/Array.o
	ld ${LDFLAGS} -r ObjFiles/Symbols/Env.o ObjFiles/Symbols/Type.o ObjFiles/Symbols/Array.o -o ObjFiles/Symbols/TopSymbol.o

# Link all object files for Inter
ObjFiles/Inter/TopInter.o : ObjFiles/Inter/Node.o ObjFiles/Inter/Expr.o ObjFiles/Inter/Id.o ObjFiles/Inter/Temp.o ObjFiles/Inter/Op.o ObjFiles/Inter/Arith.o ObjFiles/Inter/Unary.o ObjFiles/Inter/Constant.o ObjFiles/Inter/Logical.o ObjFiles/Inter/Or.o ObjFiles/Inter/And.o ObjFiles/Inter/Not.o ObjFiles/Inter/Rel.o ObjFiles/Inter/Access.o ObjFiles/Inter/Stmt.o ObjFiles/Inter/If.o ObjFiles/Inter/Else.o ObjFiles/Inter/While.o ObjFiles/Inter/Do.o ObjFiles/Inter/Set.o ObjFiles/Inter/SetElem.o ObjFiles/Inter/Seq.o ObjFiles/Inter/Break.o
	ld ${LDFLAGS} -r ObjFiles/Inter/Node.o ObjFiles/Inter/Expr.o ObjFiles/Inter/Id.o ObjFiles/Inter/Temp.o ObjFiles/Inter/Op.o ObjFiles/Inter/Arith.o ObjFiles/Inter/Unary.o ObjFiles/Inter/Constant.o ObjFiles/Inter/Logical.o ObjFiles/Inter/Or.o ObjFiles/Inter/And.o ObjFiles/Inter/Not.o ObjFiles/Inter/Rel.o ObjFiles/Inter/Access.o ObjFiles/Inter/Stmt.o ObjFiles/Inter/If.o ObjFiles/Inter/Else.o ObjFiles/Inter/While.o ObjFiles/Inter/Do.o ObjFiles/Inter/Set.o ObjFiles/Inter/SetElem.o ObjFiles/Inter/Seq.o ObjFiles/Inter/Break.o -o ObjFiles/Inter/TopInter.o

# Link all object files for Parser
ObjFiles/Parser/TopParser.o : ObjFiles/Parser/Parser.o
	ld ${LDFLAGS} -r ObjFiles/Parser/Parser.o -o ObjFiles/Parser/TopParser.o

# Create individual object files for Main components
ObjFiles/Main/Main.o : Src/Main/Main.cpp Src/Main/Main.h
	${CC} ${CFLAGS} -c Src/Main/Main.cpp -o ObjFiles/Main/Main.o

ObjFiles/Main/Files.o : Src/Main/Files.cpp Src/Main/Files.h
	${CC} ${CFLAGS} -c Src/Main/Files.cpp -o ObjFiles/Main/Files.o

# Create individual object files for Lexer components
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

ObjFiles/Inter/Constant.o : Src/Inter/Constant.cpp Src/Inter/Constant.h
	${CC} ${CFLAGS} -c Src/Inter/Constant.cpp -o ObjFiles/Inter/Constant.o

ObjFiles/Inter/Logical.o : Src/Inter/Logical.cpp Src/Inter/Logical.h
	${CC} ${CFLAGS} -c Src/Inter/Logical.cpp -o ObjFiles/Inter/Logical.o

ObjFiles/Inter/Or.o : Src/Inter/Or.cpp Src/Inter/Or.h
	${CC} ${CFLAGS} -c Src/Inter/Or.cpp -o ObjFiles/Inter/Or.o

ObjFiles/Inter/And.o : Src/Inter/And.cpp Src/Inter/And.h
	${CC} ${CFLAGS} -c Src/Inter/And.cpp -o ObjFiles/Inter/And.o

ObjFiles/Inter/Not.o : Src/Inter/Not.cpp Src/Inter/Not.h
	${CC} ${CFLAGS} -c Src/Inter/Not.cpp -o ObjFiles/Inter/Not.o

ObjFiles/Inter/Rel.o : Src/Inter/Rel.cpp Src/Inter/Rel.h
	${CC} ${CFLAGS} -c Src/Inter/Rel.cpp -o ObjFiles/Inter/Rel.o

ObjFiles/Inter/Access.o : Src/Inter/Access.cpp Src/Inter/Access.h
	${CC} ${CFLAGS} -c Src/Inter/Access.cpp -o ObjFiles/Inter/Access.o

ObjFiles/Inter/Stmt.o : Src/Inter/Stmt.cpp Src/Inter/Stmt.h
	${CC} ${CFLAGS} -c Src/Inter/Stmt.cpp -o ObjFiles/Inter/Stmt.o

ObjFiles/Inter/If.o : Src/Inter/If.cpp Src/Inter/If.h
	${CC} ${CFLAGS} -c Src/Inter/If.cpp -o ObjFiles/Inter/If.o

ObjFiles/Inter/Else.o : Src/Inter/Else.cpp Src/Inter/Else.h
	${CC} ${CFLAGS} -c Src/Inter/Else.cpp -o ObjFiles/Inter/Else.o

ObjFiles/Inter/While.o : Src/Inter/While.cpp Src/Inter/While.h
	${CC} ${CFLAGS} -c Src/Inter/While.cpp -o ObjFiles/Inter/While.o

ObjFiles/Inter/Do.o : Src/Inter/Do.cpp Src/Inter/Do.h
	${CC} ${CFLAGS} -c Src/Inter/Do.cpp -o ObjFiles/Inter/Do.o

ObjFiles/Inter/Set.o : Src/Inter/Set.cpp Src/Inter/Set.h
	${CC} ${CFLAGS} -c Src/Inter/Set.cpp -o ObjFiles/Inter/Set.o

ObjFiles/Inter/SetElem.o : Src/Inter/SetElem.cpp Src/Inter/SetElem.h
	${CC} ${CFLAGS} -c Src/Inter/SetElem.cpp -o ObjFiles/Inter/SetElem.o

ObjFiles/Inter/Seq.o : Src/Inter/Seq.cpp Src/Inter/Seq.h
	${CC} ${CFLAGS} -c Src/Inter/Seq.cpp -o ObjFiles/Inter/Seq.o

ObjFiles/Inter/Break.o : Src/Inter/Break.cpp Src/Inter/Break.h
	${CC} ${CFLAGS} -c Src/Inter/Break.cpp -o ObjFiles/Inter/Break.o

# Create individual object files for Parser components
ObjFiles/Parser/Parser.o : Src/Parser/Parser.cpp Src/Parser/Parser.h
	${CC} ${CFLAGS} -c Src/Parser/Parser.cpp -o ObjFiles/Parser/Parser.o

# Cleanup all object files and the executable
clean :
	rm -rf ObjFiles/Main/*o ObjFiles/Lexer/*o ObjFiles/Symbols/*o ObjFiles/Inter/*o ObjFiles/Parser/*o ${TARGET} 
