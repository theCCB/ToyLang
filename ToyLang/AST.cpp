#include "AST.h"
#include "AstVisitor.hpp"
#include "Callable.hpp"

Value ExprBinary::accept(ExprVisitor* visitor)
{
	return visitor->visit(this);
}

Value ExprUnary::accept(ExprVisitor* visitor)
{
	return visitor->visit(this);
}

Value ExprLiteral::accept(ExprVisitor* visitor)
{
	return visitor->visit(this);
}

Value ExprVariableGet::accept(ExprVisitor* visitor)
{
	return visitor->visit(this);
}

Value ExprVariableSet::accept(ExprVisitor* visitor)
{
	return visitor->visit(this);
}

Value ExprMemberGet::accept(ExprVisitor* visitor)
{
	return visitor->visit(this);
}

Value ExprMemberSet::accept(ExprVisitor* visitor)
{
	return visitor->visit(this);
}

Value ExprArrayGet::accept(ExprVisitor* visitor)
{
	return visitor->visit(this);
}

Value ExprArraySet::accept(ExprVisitor* visitor)
{
	return visitor->visit(this);
}

Value ExprCall::accept(ExprVisitor* visitor)
{
	return visitor->visit(this);
}

void StmtExpr::accept(StmtVisitor* visitor)
{
	return visitor->visit(this);
}

void StmtFunction::accept(StmtVisitor* visitor)
{
	return visitor->visit(this);
}

void StmtVarDecl::accept(StmtVisitor* visitor)
{
	return visitor->visit(this);
}

void StmtBlock::accept(StmtVisitor* visitor)
{
	return visitor->visit(this);
}

void StmtIf::accept(StmtVisitor* visitor)
{
	return visitor->visit(this);
}

void StmtWhile::accept(StmtVisitor* visitor)
{
	return visitor->visit(this);
}

void StmtReturn::accept(StmtVisitor* visitor)
{
	return visitor->visit(this);
}

void StmtClass::accept(StmtVisitor* visitor)
{
	return visitor->visit(this);
}
