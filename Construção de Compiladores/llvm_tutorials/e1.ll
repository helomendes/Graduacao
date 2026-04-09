@alloc_0bd83ae4d998a852bdd6080f4dbcd402 = private unnamed_addr constant [16 x i8] c"/app/example.rs\00", align 1
@alloc_f55b6182d74dd7bc5c6dc5a268ab4cc0 = private unnamed_addr constant <{ ptr, [16 x i8] }> <{ ptr @alloc_0bd83ae4d998a852bdd6080f4dbcd402, [16 x i8] c"\0F\00\00\00\00\00\00\00\02\00\00\00\03\00\00\00" }>, align 8

define i32 @example::square::h58a3bead8e2e4c5a(i32 %x) unnamed_addr #0 !dbg !7 {
start:
  %x.dbg.spill = alloca [4 x i8], align 4
  store i32 %x, ptr %x.dbg.spill, align 4
    #dbg_declare(ptr %x.dbg.spill, !14, !DIExpression(), !16)
  %0 = call { i32, i1 } @llvm.smul.with.overflow.i32(i32 %x, i32 %x), !dbg !17
  %_2.0 = extractvalue { i32, i1 } %0, 0, !dbg !17
  %_2.1 = extractvalue { i32, i1 } %0, 1, !dbg !17
  br i1 %_2.1, label %panic, label %bb1, !dbg !17

bb1:
  ret i32 %_2.0, !dbg !18

panic:
  call void @core[bd7107ce196a68c2]::panicking::panic_const::panic_const_mul_overflow(ptr align 8 @alloc_f55b6182d74dd7bc5c6dc5a268ab4cc0) #3, !dbg !17
  unreachable, !dbg !17
}

declare { i32, i1 } @llvm.smul.with.overflow.i32(i32, i32) #1

declare void @core[bd7107ce196a68c2]::panicking::panic_const::panic_const_mul_overflow(ptr align 8) unnamed_addr #2

attributes #0 = { nonlazybind uwtable "probe-stack"="inline-asm" "target-cpu"="x86-64" }
attributes #1 = { nocallback nocreateundeforpoison nofree nosync nounwind speculatable willreturn memory(none) }
attributes #2 = { cold noinline noreturn nonlazybind uwtable "probe-stack"="inline-asm" "target-cpu"="x86-64" }
attributes #3 = { noinline noreturn }
