// Copyright (c) 2012, the Dart project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#ifndef VM_FLAG_LIST_H_
#define VM_FLAG_LIST_H_

// List of all flags in the VM.
// Flags can be one of three categories:
// * P roduct flags: Can be set in any of the deployment modes, including in
//   production.
// * D ebug flags: Can only be set in debug VMs, which also have assertions
//   enabled.
// * R elease flags: Generally available flags except when building product.
// * pre C ompile flags: Generally available flags except when building product
//   or precompiled runtime.
//
// Usage:
//   P(name, type, default_value, comment)
//   D(name, type, default_value, comment)
//   R(name, product_value, type, default_value, comment)
//   C(name, precompiled_value, product_value, type, default_value, comment)
#define FLAG_LIST(P, R, D, C)                                                  \
C(allow_absolute_addresses, false, true, bool, true,                           \
  "Allow embedding absolute addresses in generated code.")                     \
C(always_megamorphic_calls, true, false, bool, false,                          \
  "Instance call always as megamorphic.")                                      \
C(background_compilation, false, false, bool, false,                           \
  "Run optimizing compilation in background")                                  \
C(collect_code, false, true, bool, true,                                       \
  "Attempt to GC infrequently used code.")                                     \
C(collect_dynamic_function_names, true, false, bool, false,                    \
  "Collects all dynamic function names to identify unique targets")            \
R(dedup_instructions, true, bool, false,                                       \
  "Canonicalize instructions when precompiling.")                              \
C(deoptimize_alot, false, false, bool, false,                                  \
  "Deoptimizes we are about to return to Dart code from native entries.")      \
C(deoptimize_every, 0, 0, int, 0,                                              \
  "Deoptimize on every N stack overflow checks")                               \
R(disable_alloc_stubs_after_gc, false, bool, false,                            \
  "Stress testing flag.")                                                      \
R(disassemble, false, bool, false,                                             \
  "Disassemble dart code.")                                                    \
R(disassemble_optimized, false, bool, false,                                   \
  "Disassemble optimized code.")                                               \
R(dump_symbol_stats, false, bool, false,                                       \
  "Dump symbol table statistics")                                              \
C(emit_edge_counters, false, true, bool, true,                                 \
  "Emit edge counters")                                                        \
R(enable_asserts, false, bool, false,                                          \
  "Enable assert statements.")                                                 \
C(enable_mirrors, false, false, bool, true,                                    \
  "Disable to make importing dart:mirrors an error.")                          \
R(enable_type_checks, false, bool, false,                                      \
  "Enable type checks.")                                                       \
R(error_on_bad_override, false, bool, false,                                   \
  "Report error for bad overrides.")                                           \
R(error_on_bad_type, false, bool, false,                                       \
  "Report error for malformed types.")                                         \
C(fields_may_be_reset, true, false, bool, false,                               \
  "Don't optimize away static field initialization")                           \
C(force_clone_compiler_objects, false, false, bool, false,                     \
  "Force cloning of objects needed in compiler (ICData and Field).")           \
R(gc_at_alloc, false, bool, false,                                             \
  "GC at every allocation.")                                                   \
P(getter_setter_ratio, int, 13,                                                \
  "Ratio of getter/setter usage used for double field unboxing heuristics")    \
P(guess_icdata_cid, bool, true,                                                \
  "Artificially create type feedback for arithmetic etc. operations")          \
C(ic_range_profiling, false, true, bool, true,                                 \
  "Generate special IC stubs collecting range information ")                   \
C(interpret_irregexp, true, false, bool, false,                                \
  "Use irregexp bytecode interpreter")                                         \
C(lazy_dispatchers, false, true, bool, true,                                   \
  "Generate dispatchers lazily")                                               \
C(link_natives_lazily, true, false, bool, false,                               \
  "Link native calls lazily")                                                  \
C(load_deferred_eagerly, true, true, bool, false,                              \
  "Load deferred libraries eagerly.")                                          \
P(max_polymorphic_checks, int, 4,                                              \
  "Maximum number of polymorphic check, otherwise it is megamorphic.")         \
P(max_equality_polymorphic_checks, int, 32,                                    \
    "Maximum number of polymorphic checks in equality operator,")              \
P(merge_sin_cos, bool, false,                                                  \
  "Merge sin/cos into sincos")                                                 \
P(new_gen_ext_limit, int, 64,                                                  \
  "maximum total external size (MB) in new gen before triggering GC")          \
C(optimization_counter_threshold, -1, 30000, int, 30000,                       \
  "Function's usage-counter value before it is optimized, -1 means never")     \
C(polymorphic_with_deopt, false, true, bool, true,                             \
  "Polymorphic calls with deoptimization / megamorphic call")                  \
C(precompiled_mode, true, false, bool, false,                                  \
  "Precompilation compiler/runtime mode")                                      \
R(pretenure_all, false, bool, false,                                           \
  "Global pretenuring (for testing).")                                         \
P(pretenure_interval, int, 10,                                                 \
  "Back off pretenuring after this many cycles.")                              \
P(pretenure_threshold, int, 98,                                                \
  "Trigger pretenuring when this many percent are promoted.")                  \
C(print_stop_message, false, false, bool, false,                               \
  "Print stop message.")                                                       \
R(profiler, false, bool, true,                                                 \
  "Enable the profiler.")                                                      \
R(support_ast_printer, false, bool, true,                                      \
  "Support the AST printer.")                                                  \
R(support_compiler_stats, false, bool, true,                                   \
  "Support compiler stats.")                                                   \
R(support_debugger, false, bool, true,                                         \
  "Support the debugger.")                                                     \
R(support_disassembler, false, bool, true,                                     \
  "Support the disassembler.")                                                 \
R(support_il_printer, false, bool, true,                                       \
  "Support the IL printer.")                                                   \
R(support_service, false, bool, true,                                          \
  "Support the service protocol.")                                             \
R(support_coverage, false, bool, true,                                         \
  "Support code coverage.")                                                    \
R(support_timeline, false, bool, true,                                         \
  "Support timeline.")                                                         \
D(trace_cha, bool, false,                                                      \
  "Trace CHA operations")                                                      \
D(trace_field_guards, bool, false,                                             \
  "Trace changes in field's cids.")                                            \
D(trace_handles, bool, false,                                                  \
  "Traces allocation of handles.")                                             \
D(trace_optimization, bool, false,                                             \
  "Print optimization details.");                                              \
D(trace_zones, bool, false,                                                    \
  "Traces allocation sizes in the zone.")                                      \
P(truncating_left_shift, bool, true,                                           \
  "Optimize left shift to truncate if possible")                               \
C(use_cha_deopt, false, true, bool, true,                                      \
  "Use class hierarchy analysis even if it can cause deoptimization.")         \
C(use_field_guards, false, true, bool, true,                                   \
  "Use field guards and track field types")                                    \
C(use_osr, false, true, bool, true,                                            \
  "Use OSR")                                                                   \
P(verbose_gc, bool, false,                                                     \
  "Enables verbose GC.")                                                       \
P(verbose_gc_hdr, int, 40,                                                     \
  "Print verbose GC header interval.")                                         \
R(verify_after_gc, false, bool, false,                                         \
  "Enables heap verification after GC.")                                       \
R(verify_before_gc, false, bool, false,                                        \
  "Enables heap verification before GC.")                                      \

#endif  // VM_FLAG_LIST_H_