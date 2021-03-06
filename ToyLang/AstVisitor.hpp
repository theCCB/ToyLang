#pragma once
#include "AST.h"

class ExprVisitor
{
public:
    virtual Value visit(ExprBinary* expr) = 0;
    virtual Value visit(ExprUnary* expr) = 0;
    virtual Value visit(ExprLiteral* expr) = 0;
    virtual Value visit(ExprVariableGet* expr) = 0;
    virtual Value visit(ExprVariableSet* expr) = 0;
    virtual Value visit(ExprMemberGet* expr) = 0;
    virtual Value visit(ExprMemberSet* expr) = 0;
    virtual Value visit(ExprArrayGet* expr) = 0;
    virtual Value visit(ExprArraySet* expr) = 0;
    virtual Value visit(ExprCall* expr) = 0;
};

class StmtVisitor
{
public:
    virtual void visit(StmtExpr* stmt) = 0;
    virtual void visit(StmtFunction* stmt) = 0;
    virtual void visit(StmtVarDecl* stmt) = 0;
    virtual void visit(StmtBlock* stmt) = 0;
    virtual void visit(StmtIf* stmt) = 0;
    virtual void visit(StmtWhile* stmt) = 0;
    virtual void visit(StmtReturn* stmt) = 0;
    virtual void visit(StmtClass* stmt) = 0;
};
