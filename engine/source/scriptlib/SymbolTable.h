/*
 * OpenBOR - http://www.LavaLit.com
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in OpenBOR root for details.
 *
 * Copyright (c) 2004 - 2011 OpenBOR Team
 */

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "ScriptVariant.h"
#include "Instruction.h"
#include "List.h"

typedef struct Symbol
{
   char  name[MAX_STR_LEN+1];
   DWORD dwFlags;
   ScriptVariant var;
   Instruction*  theRef;
}Symbol;


typedef struct SymbolTable
{
   List SymbolList;
   int  nextSymbolCount;
   char name[MAX_STR_LEN+1];
}SymbolTable;

void Symbol_Init(Symbol* symbol, char* theName, DWORD flags, ScriptVariant* pvar, Instruction*  theRef);
void SymbolTable_Init(SymbolTable* stable, char* theName );
void SymbolTable_Clear(SymbolTable* stable);
BOOL SymbolTable_FindSymbol(SymbolTable* stable, char* symbolName, Symbol** pp_theSymbol );
void SymbolTable_AddSymbol(SymbolTable* stable, Symbol* p_theSymbol ) ;

#endif
