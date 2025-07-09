
#include "irgen.hh"

#include <llvm/IR/Constants.h>
#include <llvm/ADT/APFloat.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Verifier.h>

namespace irgen {
	State *state;

	State::State(string &name) : module_name(name) {
		module_name = name;

		// Open a new context and module.
		context = make_unique<LLVMContext>();
		module = make_unique<Module>(module_name, *context);
		// module->setDataLayout(jit->getDataLayout());

		// Create a new builder for the module.
		builder = make_unique<IRBuilder<>>(*context);

		// Create new pass and analysis managers.
		//fpm = std::make_unique<FunctionPassManager>();
		//lam = std::make_unique<LoopAnalysisManager>();
		//fam = std::make_unique<FunctionAnalysisManager>();
	  //cgam = std::make_unique<CGSCCAnalysisManager>();
		//mam = std::make_unique<ModuleAnalysisManager>();
		//pic = std::make_unique<PassInstrumentationCallbacks>();
		//si = std::make_unique<StandardInstrumentations>(*context, /*DebugLogging*/ true);
		//si->registerCallbacks(*pic, mam.get());

		// Add transform passes.
		// Do simple "peephole" optimizations and bit-twiddling optzns.
		//fpm->addPass(llvm::InstCombinePass());

		// Reassociate expressions.
		//fpm->addPass(llvm::ReassociatePass());

		// Eliminate Common SubExpressions.
		//fpm->addPass(llvm::GVNPass());

		// Simplify the control flow graph (deleting unreachable blocks, etc).
		//fpm->addPass(llvm::SimplifyCFGPass());

		// Register analysis passes used in these transform passes.
		/* PassBuilder pb;
		pb.registerModuleAnalyses(*mam);
		pb.registerFunctionAnalyses(*fam);
		pb.crossRegisterProxies(*lam, *fam,   *cgam, *mam); */
	}

	llvm::Function *State::getFunction(string name) {
		// First, see if the function has already been added to the current module.
		if (auto *f = module->getFunction(name))
			return f;

		// If not, check whether we can irgen the declaration from some existing
		// prototype.
		auto fi = prototypes.find(name);
		if (fi != prototypes.end())
			return fi->second->codegen();

		// If no existing prototype exists, return null.
		return nullptr;
	}
} // namespace irgen

using llvm::Value;
using llvm::ConstantFP;
using llvm::APFloat;
using llvm::APInt;
using llvm::Type;
using llvm::FunctionType;
using llvm::BasicBlock;

llvm::Value *ast::Number::codegen() {
	switch (kind) {
		case (Number::Kind::BIN_NUMBER):
			return llvm::ConstantInt::get(
				*irgen::state->context,
				APInt(64, strtol((&value[2]), nullptr, 2)));

		case (Number::Kind::OCT_NUMBER):
			return llvm::ConstantInt::get(
				*irgen::state->context,
				APInt(64, strtol((&value[2]), nullptr, 8)));

		case (Number::Kind::DEC_NUMBER):
			return llvm::ConstantInt::get(
				*irgen::state->context,
				APInt(64, strtol(value.c_str(), nullptr, 10)));

		case (Number::Kind::HEX_NUMBER):
			return llvm::ConstantInt::get(
				*irgen::state->context,
				APInt(64, strtol((&value[2]), nullptr, 16)));

		case (Number::Kind::FLOAT_NUMBER):
			return ConstantFP::get(
				*irgen::state->context,
				APFloat(strtod(&value[0], nullptr)));
	}

	return nullptr;
}

llvm::Value *ast::Variable::codegen() {
	// Look this variable up in the function.
	Value* v = irgen::state->named_values[name];

	if (!v)
		exit(-1);

	return v;
}

llvm::Value *ast::Binary::codegen() {
	Value *l = lhs->codegen();
	Value *r = rhs->codegen();

	if (!l || !r)
		return nullptr;

	if (op == "+")
		return irgen::state->builder->CreateFAdd(l, r, "addtmp");

	else if (op == "-")
		return irgen::state->builder->CreateFSub(l, r, "subtmp");

	else if (op == "*")
		return irgen::state->builder->CreateFMul(l, r, "multmp");

	else if (op == "/")
		return irgen::state->builder->CreateFDiv(l, r, "divtmp");

	else
		exit(-1);
}

llvm::Value *ast::Call::codegen() {
	llvm::Function *calleef = irgen::state->getFunction(callee);

	if (!calleef)
		exit(-1);

	if (calleef->arg_size() != args.size())
		exit(-1);

	vector<Value*> argsv;

	for (unsigned i = 0, e = args.size(); i != e; ++i) {
		argsv.push_back(args[i]->codegen());
		if (!argsv.back())
			return nullptr;
	}

	return irgen::state->builder->CreateCall(calleef, argsv, "calltmp");
}

llvm::Function *ast::Prototype::codegen() {
	vector<Type*> doubles(args.size(), Type::getDoubleTy(*irgen::state->context));
	FunctionType *function_type = FunctionType::get(
		Type::getDoubleTy(*irgen::state->context), doubles, false);

	llvm::Function *function=llvm::Function::Create(
		function_type,
		llvm::Function::ExternalLinkage,
		name,
		irgen::state->module.get());

	// Set names for all arguments.
	unsigned idx = 0;
	for (auto &arg : function->args())
		arg.setName(args[idx++]);

	return function;
}

llvm::Function *ast::Function::codegen() {
	// First, check for an existing function from a previous 'extern' declaration.
	llvm::Function *function = irgen::state->module->getFunction(prototype->getName());

	if (!function)
		function = prototype->codegen();

	if (!function)
		return nullptr;

	// Create a new basic block to start insertion into.
	BasicBlock *bb = BasicBlock::Create(*irgen::state->context, "entry", function);
	irgen::state->builder->SetInsertPoint(bb);

	// Record the function arguments in the irgen::state->named_values map.
	irgen::state->named_values.clear();
	for (auto &arg : function->args())
		irgen::state->named_values[std::string(arg.getName())] = &arg;

	if (Value *ret_val = body->codegen()) {
		// Finish off the function.
		irgen::state->builder->CreateRet(ret_val);

		// Validate the generated code, checking for consistency.
		llvm::verifyFunction(*function);

		return function;
	}

	// Error reading body, remove function.
	function->eraseFromParent();
	return nullptr;
}
