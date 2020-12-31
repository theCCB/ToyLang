#pragma once
#include "AstVisitor.hpp"

#include <iostream>

class AstDebugger : public ExprVisitor, public StmtVisitor
{
private:
	std::vector<Stmt*> root;
public:
	AstDebugger(std::vector<Stmt*> root)
		: root(root)
	{}

	void debug()
	{
		for (auto& stmt : root)
		{
			stmt->accept(this);
		}
	}

	// (op, lhs, rhs)
	Value visit(ExprBinary* expr) override
	{
		std::cout << "(" << expr->op.getLexeme() << ", ";
		expr->lhs->accept(this);
		std::cout << ", ";
		expr->rhs->accept(this);
		std::cout << ")";
		return Value();
	}

	// (op rhs)
	Value visit(ExprUnary* expr) override
	{
		std::cout << "(" << expr->op.getLexeme();
		expr->rhs->accept(this);
		std::cout << ")";
		return Value();
	}

	Value visit(ExprLiteral* expr) override
	{
		expr->value.print();
		return Value();
	}

	Value visit(ExprVariableGet* expr) override
	{
		std::cout << "(" << expr->name.getLexeme() << ")";
		return Value();
	}

	Value visit(ExprVariableSet* expr) override
	{
		std::cout << "(" << expr->name.getLexeme() << " " << expr->op.getLexeme() << " ";
		expr->setVal->accept(this);
		std::cout << ")";
		return Value();
	}

	Value visit(ExprCall* expr) override
	{
		std::cout << "(";
		expr->callee->accept(this);
		std::cout << "(";
		if (expr->args.size() > 0)
		{
			expr->args[0]->accept(this);
			for (size_t i = 1; i < expr->args.size(); i++)
			{
				std::cout << ", ";
				expr->args[i]->accept(this);
			}
		}
		std::cout << "))";

		return Value();
	}

	void visit(StmtExpr* stmt) override
	{
		stmt->expr->accept(this);
		std::cout << "\n";
	}

	void visit(StmtFunction* stmt) override
	{
		std::cout << "FUNC " << stmt->name.getLexeme() << "(";
		for (auto& p : stmt->params)
			std::cout << " " << p.getLexeme();
		std::cout << ")" << std::endl;
		for (auto& stmt : stmt->stmts)
		{
			stmt->accept(this);
		}

		std::cout << "END FUNC" << std::endl;
	}

	void visit(StmtVarDecl* stmt) override
	{
		std::cout << "DECL " << stmt->name.getLexeme();
		if (stmt->initVal)
		{
			std::cout << " = ";
			stmt->initVal->accept(this);
		}
		std::cout << std::endl;
	}
};