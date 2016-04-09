#include "core/profiler.h"
#include "jit/ir/ir_builder.h"
#include "jit/ir/passes/pass_runner.h"

using namespace re::jit::ir;
using namespace re::jit::ir::passes;

PassRunner::PassRunner() {}

void PassRunner::AddPass(std::unique_ptr<Pass> pass) {
  passes_.push_back(std::move(pass));
}

void PassRunner::Run(IRBuilder &builder, bool debug) {
  PROFILER_RUNTIME("PassRunner::Run");

  if (debug) {
    LOG_INFO("original:");
    builder.Dump();
    LOG_INFO("");
  }

  for (auto &pass : passes_) {
    PROFILER_RUNTIME(pass->name());

    pass->Run(builder, debug);

    if (debug) {
      LOG_INFO("%s:", pass->name());
      builder.Dump();
      LOG_INFO("");
    }
  }
}
