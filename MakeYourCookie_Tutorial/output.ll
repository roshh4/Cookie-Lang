; ModuleID = 'my_module'
source_filename = "my_module"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define i32 @main() {
entry:
  %printtmp = call i32 (ptr, ...) @printf(ptr @0, i32 15)
  ret i32 0
}

declare i32 @printf(ptr, ...)
