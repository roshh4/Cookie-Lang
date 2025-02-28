## Basic Syntax

### Print, Input, and Inline

- **print(expression);**
    
    Prints the evaluated value of the expression. If used as `print();`, it simply prints a new line.
    
    **Example:**
    
    ```
    print("Hello, Cookie!");
    print();  // Prints a new line.
    ```
    
- **input(expression);**
    
    Reads input from the user. The expression may serve as a prompt or an initializer for processing the input.
    
    **Example:**
    
    ```
    input("Enter your name: ");
    ```
    
- **inline(expression);**
    
    Evaluates the expression inline. This can be useful for immediate execution of a function or operation.
    
    **Example:**
    
    ```
    cook
    CopyEdit
    inline(2 + 3);
    
    ```
    

### Comments

Cookie supports two forms of single-line comments:

- Lines beginning with `//`
- Lines starting with `comment:`

Both types are ignored by the parser.

**Example:**

```
c
CopyEdit
// This is a single-line comment.
comment: This is another comment.

```

---

## Variable Declaration

Variables can be declared in two ways:

- **Implicit Declaration:** Using the `var` keyword.
- **Typed Declaration:** Using one of the specific data type keywords.

**Examples:**

```
var x = 10;          // Implicit declaration.
int y = 5;           // Declaration of an integer.
float pi = 3.14;     // Declaration of a floating-point number.

```

---

## 3. Data Types

Cookie has five primary data types with auto-detection when using literals:

- **int:** For integer values.
- **float:** For floating-point numbers.
- **bool:** For Boolean values (`true` or `false`).
- **char:** For single characters, enclosed in single quotes.
- **string:** For sequences of characters, enclosed in double quotes.

### Auto-detection & Type Conversions

- **Auto-detection:**
    
    When you write a literal (e.g., `123` or `"Hello"`), Cookie automatically detects its type.
    
- **Type Conversions:**
    
    Explicit conversion is available using a cast-like syntax:
    
    - `int(expression)`
    - `float(expression)`
    - `string(expression)`
    - `char(expression)`

These allow converting between compatible types.

**Example:**

```
int a = 10;
float b = 3.14;
bool flag = true;
char letter = 'c';
string greeting = "Hello";

// Converting a string to an int.
int num = int("123");

// Converting a string to a float.
float value = float("3.14");

```

---

## 4. Operators

### Arithmetic Operators

- **Addition:** `+`
- **Subtraction:** ``
- **Multiplication:** ``
- **Division:** `/`

**Example:**

```
int sum = 5 + 3;
```

### Relational Operators

- **Less than:** `lesser than` or `<`
- **Greater than:** `greater than` or `>`
- **Equals:** `equals` or `==`
- **Not equals:** `not equals` or `!=`
- **Less than or equals:** `lesser than equals` or `<=`
- **Greater than or equals:** `greater than equals` or `>=`

**Example:**

```
if (x lesser than 10) {
  print("x is less than 10");
}

if (y >= 3.14) {
  print("y is greater than or equal to 3.14");
}
```

### Logical Operators

- **And:** `and` or `&&`
- **Or:** `or` or `||`
- **Not:** `not` or `!`

**Example:**

```
if (flag and (x equals 5)) {
  print("Condition met!");
}
```

---

## 5. Control Structures

### Simple If

Executes a block if the condition is true.

**Syntax:**

```
if(condition) {
    // statements
}
```

**Example:**

```
if (x > 0) {
    print("Positive number");
}
```

### If Else

Provides an alternative block if the condition is false.

**Syntax:**

```
if (condition) {
    // if true
} else {
    // if false
}
```

**Example:**

```
if (x > 0) {
    print("Positive number");
} else {
    print("Zero or Negative");
}
```

### Else If Ladder

Chains multiple conditions.

**Syntax:**

**Example:**

```
if (x > 0) {
    print("Positive");
} else if (x < 0) {
    print("Negative");
} else {
    print("Zero");
}
```

### Switch Case

Evaluates an expression and executes code based on matching cases.

**Syntax:**

```
switch (expression) {
    case: value1
        // statements
    case: value2
        // statements
    default:
        // statements
}
```

**Example:**

```
switch (x) {
    case: 1
        print("One");
    case: 2
        print("Two");
    default:
        print("Other");
}
```

### Break Statement in Switch Case

Used to exit a switch-case block prematurely.

**Example:**

```
switch (x) {
    case: 1
        print("One");
        break;
    // further cases...
}
```

---

## 6. Arrays

Arrays are ordered collections of elements. In Cookie, arrays are declared with a specified type and support a built-in size function.

- **Declaration without initializer:**
    
    Specify the type, identifier, and size expression in brackets.
    
    **Example:**
    
    ```
    int numbers[10];
    ```
    
- **Declaration with initializer:**
    
    Use curly braces `{}` to list the elements.
    
    **Example:**
    
    ```
    int numbers[] = {1, 2, 3, 4, 5};
    ```
    

> Note: Array indexing in Cookie starts at 1 (i.e. the first element is at index 1).
> 

- **Size Function:**
    
    Use `size(array)` to get the number of elements.
    
    **Example:**
    
    ```
    int len = size(numbers);
    ```
    

---

## Loops

Cookie supports various loop constructs for fixed iteration, range-based traversal, and condition-based looping.

### Fixed Iteration Loop

Executes a block a fixed number of times.

**Syntax:**

```
loop (expression) {
    // statements
}
```

**Example:**

```
loop (5) {
    print("Iteration");
}
```

### Range-based Loop

Iterates over each element of an array.

**Syntax:**

```
loop identifier : array {
    // statements
}
```

**Example:**

```
loop i : numbers {
    print(i);
}
```

### Loop with Starting Index

By predefining a variable (e.g., *i*), you can start iterating from a specified index. This is useful for skipping initial elements.

**Example:**

```
int i = 2;
loop i : numbers {
    print(i);

```

In this example, iteration begins from the 2nd element of the array.

### Loop Until

Repeats the loop until the specified condition becomes true.

**Syntax:**

```
loop until (condition) {
    // statements
}
```

**Example:**

```
int x = 0;
loop until (x equals 10) {
    x = x + 1;
    print(x);
}
```

---

## 8. Functions

Functions in Cookie are defined using the `fun` keyword. They can either print a value directly or return a value for further use.

**Syntax:**

```
fun functionName(parameter_list) {
    // function body
    return expression;  // Optional, if a value is to be returned.
}
```

**Examples:**

- **Function That Prints a Value:**
    
    ```
    fun greet(name) {
        print("Hello, " + name);
    }
    ```
    
- **Function That Returns a Value:**
    
    ```
    fun add(a, b) {
        return (a + b);
    }
    ```