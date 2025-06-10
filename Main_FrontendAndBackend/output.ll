; ModuleID = 'GoofyLang'
source_filename = "GoofyLang"

@.str_int = private constant [4 x i8] c"%d\0A\00"
@strlit = private unnamed_addr constant [10 x i8] c"---------\00", align 1
@.str_string = private constant [4 x i8] c"%s\0A\00"
@strlit.1 = private unnamed_addr constant [5 x i8] c"meow\00", align 1
@strlit.2 = private unnamed_addr constant [13 x i8] c"less than 10\00", align 1

define i32 @main() {
global:
  %s = alloca i32, align 4
  %for_iter = alloca i32, align 4
  %number = alloca i32, align 4
  %num = alloca i32, align 4
  %array_iter_index = alloca i32, align 4
  %a = alloca [4 x i32], align 4
  %arrayelem = getelementptr [4 x i32], ptr %a, i32 0, i32 0
  store i32 21, ptr %arrayelem, align 4
  %arrayelem1 = getelementptr [4 x i32], ptr %a, i32 0, i32 1
  store i32 13, ptr %arrayelem1, align 4
  %arrayelem2 = getelementptr [4 x i32], ptr %a, i32 0, i32 2
  store i32 31, ptr %arrayelem2, align 4
  %arrayelem3 = getelementptr [4 x i32], ptr %a, i32 0, i32 3
  store i32 31, ptr %arrayelem3, align 4
  store i32 1, ptr %array_iter_index, align 4
  br label %array_iter.cond

array_iter.cond:                                  ; preds = %array_iter.body, %global
  %cur_index = load i32, ptr %array_iter_index, align 4
  %array_iter_cond = icmp sle i32 %cur_index, 4
  br i1 %array_iter_cond, label %array_iter.body, label %array_iter.after

array_iter.body:                                  ; preds = %array_iter.cond
  %adjusted_index = sub i32 %cur_index, 1
  %array_elem_ptr = getelementptr [4 x i32], ptr %a, i32 0, i32 %adjusted_index
  %array_elem = load i32, ptr %array_elem_ptr, align 4
  store i32 %array_elem, ptr %num, align 4
  %num4 = load i32, ptr %num, align 4
  %0 = call i32 (ptr, ...) @printf(ptr @.str_int, i32 %num4)
  %cur_index5 = load i32, ptr %array_iter_index, align 4
  %next_index = add i32 %cur_index5, 1
  store i32 %next_index, ptr %array_iter_index, align 4
  br label %array_iter.cond

array_iter.after:                                 ; preds = %array_iter.cond
  %1 = call i32 (ptr, ...) @printf(ptr @.str_string, ptr @strlit)
  store i32 1, ptr %number, align 4
  %number6 = load i32, ptr %number, align 4
  store i32 3, ptr %for_iter, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.body, %array_iter.after
  %for_iter7 = load i32, ptr %for_iter, align 4
  %forcond = icmp sle i32 %for_iter7, %number6
  br i1 %forcond, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %2 = call i32 (ptr, ...) @printf(ptr @.str_string, ptr @strlit.1)
  %for_iter8 = load i32, ptr %for_iter, align 4
  %forinc = add i32 %for_iter8, 1
  store i32 %forinc, ptr %for_iter, align 4
  br label %for.cond

for.end:                                          ; preds = %for.cond
  store i32 0, ptr %s, align 4
  %readInt = call i32 @read_int()
  store i32 %readInt, ptr %s, align 4
  %s9 = load i32, ptr %s, align 4
  %cmptmp = icmp slt i32 %s9, 10
  br i1 %cmptmp, label %then, label %ifcont

then:                                             ; preds = %for.end
  %3 = call i32 (ptr, ...) @printf(ptr @.str_string, ptr @strlit.2)
  br label %ifcont

ifcont:                                           ; preds = %then, %for.end
  ret i32 0
}

declare i32 @printf(ptr, ...)

declare i32 @read_int()
