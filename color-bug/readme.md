```
$ CLANG=workspace/llvm-project/build/bin/clang make
mkdir -p bar
rm -rf bar/bar.pic.pcm
workspace/llvm-project/build/bin/clang -iquote . -fmodule-name=bar -fmodule-map-file=bar.cppmap -xc++ -Xclang=-emit-module -fmodules -std=gnu++20 -c bar.cppmap -o bar/bar.pic.pcm
mkdir -p foo
rm -rf foo/foo.pic.pcm
workspace/llvm-project/build/bin/clang -iquote . -fmodule-name=foo -fmodule-map-file=foo.cppmap -xc++ -Xclang=-emit-module -fmodules -std=gnu++20 -c foo.cppmap -o foo/foo.pic.pcm
mkdir -p experiment_context
rm -rf experiment_context/experiment_context.pic.pcm
workspace/llvm-project/build/bin/clang -iquote . -Wuninitialized-const-reference -fmodule-name=experiment_context -fmodule-map-file=experiment_context.cppmap -xc++ -Xclang=-emit-module -fmodules  -Xclang=-fmodule-file=bar/bar.pic.pcm -Xclang=-fmodule-file=foo/foo.pic.pcm -std=gnu++20 -c experiment_context.cppmap -o experiment_context/experiment_context.pic.pcm
mkdir -p experiment_context_test
rm -rf experiment_context_test/experiment_context_test.pic.o
workspace/llvm-project/build/bin/clang -iquote . -Wuninitialized-const-reference -fmodules  -Xclang=-fmodule-file=experiment_context/experiment_context.pic.pcm -std=gnu++20  -c experiment_context_test.cc -o experiment_context_test/experiment_context_test.pic.o
clang: workspace/llvm-project/clang/lib/Sema/SemaTemplateInstantiate.cpp:4560: llvm::PointerUnion<Decl *, LocalInstantiationScope::DeclArgumentPack *> *clang::LocalInstantiationScope::findInstantiationOf(const Decl *): Assertion `isa<LabelDecl>(D) && "declaration not instantiated in this scope"' failed.
PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed source, and associated run script.
Stack dump:
0.      Program arguments: workspace/llvm-project/build/bin/clang -iquote . -Wuninitialized-const-reference -fmodules -Xclang=-fmodule-file=experiment_context/experiment_context.pic.pcm -std=gnu++20 -c experiment_context_test.cc -o experiment_context_test/experiment_context_test.pic.o
1.      <eof> parser at end of file
2.      experiment_context_test.cc:6:6: instantiating function definition 'c9::WaitForCoroutine<void>'
3.      workspace/module-bugs/color-bug/util/c9/lazy.h:8:7: instantiating function definition 'c9::MakeCo<void, (lambda at experiment_context_test.cc:7:13)>'
4.      workspace/module-bugs/color-bug/util/c9/co.h:45:12: instantiating function definition 'c9::internal::CoroutinePromise<void>::CoroutinePromise<(lambda at experiment_context_test.cc:7:13) &>'
 #0 0x000055bbff6ea8d8 llvm::sys::PrintStackTrace(llvm::raw_ostream&, int) workspace/llvm-project/llvm/lib/Support/Unix/Signals.inc:804:13
 #1 0x000055bbff6e87b0 llvm::sys::RunSignalHandlers() workspace/llvm-project/llvm/lib/Support/Signals.cpp:106:18
 #2 0x000055bbff63f786 (anonymous namespace)::CrashRecoveryContextImpl::HandleCrash(int, unsigned long) workspace/llvm-project/llvm/lib/Support/CrashRecoveryContext.cpp:74:5
 #3 0x000055bbff63f786 CrashRecoverySignalHandler(int) workspace/llvm-project/llvm/lib/Support/CrashRecoveryContext.cpp:391:51
 #4 0x00007f5f7ee49df0 (/lib/x86_64-linux-gnu/libc.so.6+0x3fdf0)
 #5 0x00007f5f7ee9e95c __pthread_kill_implementation ./nptl/pthread_kill.c:44:76
 #6 0x00007f5f7ee49cc2 raise ./signal/../sysdeps/posix/raise.c:27:6
 #7 0x00007f5f7ee324ac abort ./stdlib/abort.c:81:3
 #8 0x00007f5f7ee32420 __assert_perror_fail ./assert/assert-perr.c:31:1
 #9 0x000055bc01b29d0f decltype(auto) llvm::dyn_cast<clang::TagDecl, clang::Decl const>(clang::Decl const*) workspace/llvm-project/llvm/include/llvm/Support/Casting.h:662:3
#10 0x000055bc01b29d0f clang::LocalInstantiationScope::findInstantiationOf(clang::Decl const*) workspace/llvm-project/clang/lib/Sema/SemaTemplateInstantiate.cpp:4522:32
#11 0x000055bc01b6b587 clang::Sema::FindInstantiatedDecl(clang::SourceLocation, clang::NamedDecl*, clang::MultiLevelTemplateArgumentList const&, bool) workspace/llvm-project/clang/lib/Sema/SemaTemplateInstantiateDecl.cpp:6756:16
#12 0x000055bc01b426bd clang::TreeTransform<(anonymous namespace)::TemplateInstantiator>::TransformDeclRefExpr(clang::DeclRefExpr*) workspace/llvm-project/clang/lib/Sema/TreeTransform.h:0:44
#13 0x000055bc01b348f8 clang::ActionResult<clang::Expr*, true>::isInvalid() const workspace/llvm-project/clang/include/clang/Sema/Ownership.h:199:41
#14 0x000055bc01b348f8 clang::TreeTransform<(anonymous namespace)::TemplateInstantiator>::TransformCStyleCastExpr(clang::CStyleCastExpr*) workspace/llvm-project/clang/lib/Sema/TreeTransform.h:13680:15
#15 0x000055bc01b25f88 clang::TreeTransform<(anonymous namespace)::TemplateInstantiator>::TransformStmt(clang::Stmt*, clang::TreeTransform<(anonymous namespace)::TemplateInstantiator>::StmtDiscardKind) workspace/llvm-project/clang/lib/Sema/TreeTransform.h:4310:15
#16 0x000055bc01b3b21d clang::ActionResult<clang::Stmt*, true>::isInvalid() const workspace/llvm-project/clang/include/clang/Sema/Ownership.h:199:41
#17 0x000055bc01b3b21d clang::TreeTransform<(anonymous namespace)::TemplateInstantiator>::TransformCompoundStmt(clang::CompoundStmt*, bool) workspace/llvm-project/clang/lib/Sema/TreeTransform.h:8108:16
#18 0x000055bc01b41c7f clang::TreeTransform<(anonymous namespace)::TemplateInstantiator>::TransformLambdaBody(clang::LambdaExpr*, clang::Stmt*) workspace/llvm-project/clang/lib/Sema/TreeTransform.h:15802:10
#19 0x000055bc01b41c7f (anonymous namespace)::TemplateInstantiator::TransformLambdaBody(clang::LambdaExpr*, clang::Stmt*) workspace/llvm-project/clang/lib/Sema/SemaTemplateInstantiate.cpp:1792:25
#20 0x000055bc01b41c7f clang::TreeTransform<(anonymous namespace)::TemplateInstantiator>::TransformLambdaExpr(clang::LambdaExpr*) workspace/llvm-project/clang/lib/Sema/TreeTransform.h:15733:44
#21 0x000055bc01b32123 (anonymous namespace)::TemplateInstantiator::TransformLambdaExpr(clang::LambdaExpr*) workspace/llvm-project/clang/lib/Sema/SemaTemplateInstantiate.cpp:1748:25
#22 0x000055bc01b34ac3 clang::TreeTransform<(anonymous namespace)::TemplateInstantiator>::TransformCallExpr(clang::CallExpr*) workspace/llvm-project/clang/lib/Sema/TreeTransform.h:0:36
#23 0x000055bc01b25f88 clang::TreeTransform<(anonymous namespace)::TemplateInstantiator>::TransformStmt(clang::Stmt*, clang::TreeTransform<(anonymous namespace)::TemplateInstantiator>::StmtDiscardKind) workspace/llvm-project/clang/lib/Sema/TreeTransform.h:4310:15
#24 0x000055bc01b3b21d clang::ActionResult<clang::Stmt*, true>::isInvalid() const workspace/llvm-project/clang/include/clang/Sema/Ownership.h:199:41
#25 0x000055bc01b3b21d clang::TreeTransform<(anonymous namespace)::TemplateInstantiator>::TransformCompoundStmt(clang::CompoundStmt*, bool) workspace/llvm-project/clang/lib/Sema/TreeTransform.h:8108:16
#26 0x000055bc01b25f1a clang::Sema::SubstStmt(clang::Stmt*, clang::MultiLevelTemplateArgumentList const&) workspace/llvm-project/clang/lib/Sema/SemaTemplateInstantiate.cpp:4376:23
#27 0x000055bc01b7e25c clang::Sema::InstantiateFunctionDefinition(clang::SourceLocation, clang::FunctionDecl*, bool, bool, bool) workspace/llvm-project/clang/lib/Sema/SemaTemplateInstantiateDecl.cpp:5819:14
#28 0x000055bc01b8181e clang::FunctionDecl::isDefined() const workspace/llvm-project/clang/include/clang/AST/Decl.h:2226:12
#29 0x000055bc01b8181e clang::Sema::PerformPendingInstantiations(bool, bool) workspace/llvm-project/clang/lib/Sema/SemaTemplateInstantiateDecl.cpp:7065:23
#30 0x000055bc01b7e35b clang::Sema::InstantiateFunctionDefinition(clang::SourceLocation, clang::FunctionDecl*, bool, bool, bool) workspace/llvm-project/clang/lib/Sema/SemaTemplateInstantiateDecl.cpp:0:24
#31 0x000055bc01b8181e clang::FunctionDecl::isDefined() const workspace/llvm-project/clang/include/clang/AST/Decl.h:2226:12
#32 0x000055bc01b8181e clang::Sema::PerformPendingInstantiations(bool, bool) workspace/llvm-project/clang/lib/Sema/SemaTemplateInstantiateDecl.cpp:7065:23
#33 0x000055bc01b7e35b clang::Sema::InstantiateFunctionDefinition(clang::SourceLocation, clang::FunctionDecl*, bool, bool, bool) workspace/llvm-project/clang/lib/Sema/SemaTemplateInstantiateDecl.cpp:0:24
#34 0x000055bc01b8181e clang::FunctionDecl::isDefined() const workspace/llvm-project/clang/include/clang/AST/Decl.h:2226:12
#35 0x000055bc01b8181e clang::Sema::PerformPendingInstantiations(bool, bool) workspace/llvm-project/clang/lib/Sema/SemaTemplateInstantiateDecl.cpp:7065:23
#36 0x000055bc0138b91e llvm::TimeTraceScope::~TimeTraceScope() workspace/llvm-project/llvm/include/llvm/Support/TimeProfiler.h:198:9
#37 0x000055bc0138b91e clang::Sema::ActOnEndOfTranslationUnitFragment(clang::TUFragmentKind) workspace/llvm-project/clang/lib/Sema/Sema.cpp:1198:3
#38 0x000055bc0138c101 clang::Sema::ActOnEndOfTranslationUnit() workspace/llvm-project/clang/lib/Sema/Sema.cpp:1236:9
#39 0x000055bc012f3ef7 clang::Parser::ParseTopLevelDecl(clang::OpaquePtr<clang::DeclGroupRef>&, clang::Sema::ModuleImportState&) workspace/llvm-project/clang/lib/Parse/Parser.cpp:0:13
#40 0x000055bc012234ae clang::ParseAST(clang::Sema&, bool, bool) workspace/llvm-project/clang/lib/Parse/ParseAST.cpp:170:5
#41 0x000055bc00440076 clang::FrontendAction::Execute() workspace/llvm-project/clang/lib/Frontend/FrontendAction.cpp:1225:10
#42 0x000055bc003b6d1d llvm::Error::getPtr() const workspace/llvm-project/llvm/include/llvm/Support/Error.h:278:42
#43 0x000055bc003b6d1d llvm::Error::operator bool() workspace/llvm-project/llvm/include/llvm/Support/Error.h:241:16
#44 0x000055bc003b6d1d clang::CompilerInstance::ExecuteAction(clang::FrontendAction&) workspace/llvm-project/clang/lib/Frontend/CompilerInstance.cpp:1057:23
#45 0x000055bc004d4452 clang::ExecuteCompilerInvocation(clang::CompilerInstance*) workspace/llvm-project/clang/lib/FrontendTool/ExecuteCompilerInvocation.cpp:300:25
#46 0x000055bbfca56483 cc1_main(llvm::ArrayRef<char const*>, char const*, void*) workspace/llvm-project/clang/tools/driver/cc1_main.cpp:297:15
#47 0x000055bbfca52865 ExecuteCC1Tool(llvm::SmallVectorImpl<char const*>&, llvm::ToolContext const&) workspace/llvm-project/clang/tools/driver/driver.cpp:223:12
```
