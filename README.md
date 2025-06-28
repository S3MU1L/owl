# Owl

Owl is a minimal object-oriented language inspired by Java but designed for scripting-style execution. It allows top-level statements and emphasizes simplicity, dynamic typing (initially), and a clean class-based object model.

## 1. Lexical Elements

### 1.1 Comments
```c
// Single-line comment
/* Multi-line
   comment */
```

## 2. Variables and Types

### 2.1 Variable Declaration
```c
var x = 10;
var name = "Alice";
```

### 2.2 Optional Type Annotations *(planned)*
```c
var x: Int = 10;
```

---

## 3. Expressions and Operators

### 3.1 Arithmetic Operators
- `+`, `-`, `*`, `/`, `%`

### 3.2 Comparison Operators
- `==`, `!=`, `<`, `>`, `<=`, `>=`

### 3.3 Boolean Operators
- `&&`, `||`, `!`

### 3.4 Assignment
- `=`

---

## 4. Control Flow

### 4.1 If Statement
```c
if (x > 0) {
  println("Positive");
} else {
  println("Non-positive");
}
```

### 4.2 While Loop
```c
while (x < 10) {
  x = x + 1;
}
```

### 4.3 For Loop
```c
for (var i = 0; i < 5; i = i + 1) {
  println(i);
}
```

---

## 5. Classes and Objects

### 5.1 Class Definition
```c
class ClassName {
  var field1;
  var field2;

  init(param1, param2) {
    this.field1 = param1;
    this.field2 = param2;
  }

  methodName() {
    // method body
  }
}
```

### 5.2 Object Instantiation
```c
var obj = new ClassName(arg1, arg2);
```

### 5.3 Method Invocation
```c
obj.methodName();
```

---

## 6. Top-Level Code

Owl supports top-level statements and expressions outside any class:
```c
println("Hello, world!");

var x = 10;
println(x);
```

---

## 7. Built-in Functions
- `print(value)` — prints without newline
- `println(value)` — prints with newline

---

## 8. Sample Program
```c
println("Hello, World!");

class Greeter {
  var name;

  init(name) {
    this.name = name;
  }

  greet() {
    println("Hello, " + this.name + "!");
  }
}

var g = new Greeter("Alice");
g.greet();
```

---

## 9. Future Features (Planned)
- Static typing support
- First-class functions and closures
- Module system
- Inheritance
- Lists and dictionaries
- Exception handling---