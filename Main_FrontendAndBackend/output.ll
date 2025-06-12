; ModuleID = 'GoofyLang'
source_filename = "GoofyLang"

@.str_int = private constant [4 x i8] c"%d\0A\00"
@strlit = private unnamed_addr constant [19 x i8] c"x is lesser than b\00", align 1
@.str_string = private constant [4 x i8] c"%s\0A\00"

define i32 @main() {
global:
  %x = alloca i32, align 4
  %b = alloca i32, align 4
  %a = alloca i32, align 4
  store i32 645, ptr %a, align 4
  store i32 12943, ptr %b, align 4
  %a1 = load i32, ptr %a, align 4
  %b2 = load i32, ptr %b, align 4
  %addtmp = add i32 %a1, %b2
  %0 = call i32 (ptr, ...) @printf(ptr @.str_int, i32 %addtmp)
  store i32 0, ptr %x, align 4
  %readInt = call i32 @read_int()
  store i32 %readInt, ptr %x, align 4
  %x3 = load i32, ptr %x, align 4
  %b4 = load i32, ptr %b, align 4
  %cmptmp = icmp slt i32 %x3, %b4
  br i1 %cmptmp, label %then, label %ifcont

then:                                             ; preds = %global
  %1 = call i32 (ptr, ...) @printf(ptr @.str_string, ptr @strlit)
  br label %ifcont

ifcont:                                           ; preds = %then, %global
  ret i32 0
}

declare i32 @printf(ptr, ...)

declare i32 @read_int()
