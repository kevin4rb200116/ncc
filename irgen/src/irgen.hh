
#include "ast.hh"

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/PassManager.h>
#include <llvm/Passes/PassBuilder.h>
#include <llvm/Passes/StandardInstrumentations.h>

namespace irgen {
	using std::string;
	using std::unique_ptr;
	using std::make_unique;
	using std::move;
	using std::vector;
	using std::map;

	using llvm::Value;
	using llvm::LLVMContext;
	using llvm::Module;
	using llvm::IRBuilder;

	using llvm::FunctionPassManager;
	using llvm::LoopAnalysisManager;
	using llvm::FunctionAnalysisManager;
	using llvm::CGSCCAnalysisManager;
	using llvm::ModuleAnalysisManager;
	using llvm::PassInstrumentationCallbacks;
	using llvm::StandardInstrumentations;
	using llvm::PassBuilder;

	typedef struct State {
		string &module_name;
		map<string, Value *> named_values;
		map<string, unique_ptr<ast::Prototype>> prototypes;

		unique_ptr<LLVMContext> context;
		unique_ptr<Module> module;
		unique_ptr<IRBuilder<>> builder;

		unique_ptr<FunctionPassManager> fpm;
		unique_ptr<LoopAnalysisManager> lam;
		unique_ptr<FunctionAnalysisManager> fam;
		unique_ptr<CGSCCAnalysisManager> cgam;
		unique_ptr<ModuleAnalysisManager> mam;
		unique_ptr<PassInstrumentationCallbacks> pic;
		unique_ptr<StandardInstrumentations> si;

		State(string &name);

		llvm::Function *getFunction(string name);
	} State;
} // namespace irgen
