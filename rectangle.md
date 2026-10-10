# Rectangle Class Program

## Overview
This program demonstrates the use of a C++ class to model a rectangle. It encapsulates the rectangle’s dimensions (width and length) and provides methods to set those dimensions, retrieve them, and calculate the area and perimeter. The program creates two rectangle objects, sets their dimensions, and displays the results.

## Class Structure: `Rectangle`

### Private Members
- `width` and `length` are private data members of type `double`.
- They are initialized to `0` by default.
- Making them private enforces **encapsulation**: external code cannot directly modify the dimensions. All changes must go through the public setter methods.

### Public Methods

| Method          | Description                                      | Return Type |
|-----------------|--------------------------------------------------|-------------|
| `setWidth()`    | Sets the width of the rectangle                  | `void`      |
| `setLength()`   | Sets the length of the rectangle                 | `void`      |
| `getWidth()`    | Returns the current width                        | `double`    |
| `getLength()`   | Returns the current length                       | `double`    |
| `getArea()`     | Calculates and returns the area (`width * length`) | `double`  |
| `getPerimeter()`| Calculates and returns the perimeter (`2 * (width + length)`) | `double` |

All getter methods are marked `const`, which means they do not modify the object’s state. This is good practice for methods that only read data.

## The `main()` Function

1. **First Rectangle**
   - An object `rectangle1` of type `Rectangle` is created.
   - Its width is set to `5` and its length to `10` using the setter methods.
   - The program then prints the width, length, area, and perimeter.

2. **Second Rectangle**
   - An object `rectangle2` is created.
   - Its width is set to `4` and its length to `6`.
   - The same information is displayed for the second rectangle.

## Key Concepts Demonstrated

- **Classes and Objects**: The `Rectangle` class defines a blueprint; `rectangle1` and `rectangle2` are instances of that class.
- **Encapsulation**: Private data members are protected and accessed only through public methods.
- **Member Functions**: Setters modify the object’s state; getters and calculation methods retrieve or derive information.
- **Const Correctness**: Getter methods are declared `const` to indicate they do not change the object.

## Sample Output
```
Rectangle 1
Width: 5
Length: 10
Area: 50
Perimeter: 30

Rectangle 2
Width: 4
Length: 6
Area: 24
Perimeter: 20
```

## Conclusion
This program provides a simple yet clear example of object-oriented programming in C++. It shows how to design a class that safely manages its own data and exposes useful operations (area and perimeter) to the rest of the program.
