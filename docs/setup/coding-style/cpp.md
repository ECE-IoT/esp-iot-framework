# C++ coding style

Next to consistency as a main aspect of good code, the second most important aspect is a certain style which the average `c++` programmer is capable to read and understand properly. Therefore the following documents states the essential naming conventions. 

!!! HINT
    > Here is a link for a more detailed dive into [`c++ core guidelines'](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md)

    > Style guide by the Barr Group: [Style Guide](https://barrgroup.com/embedded-systems/books/embedded-c-coding-standard)

## Naming conventions

### Variables

The name of a variable should be as accurate as possible and as short as possible at the same time.

*Example:*
```cpp
// don't
int x; 
x = 10 + 5;
// do
int sum
sum = 10 + 5;
```
A variable can be used in two different scenarios.

**Global/Local variables**
Global/Local variables should be defined in a `snake_case` style.

*Example:*
```cpp
int global_variable; 
```

**Private variables**
Private variables should be defined the same way as global variables. The main difference for private variables is a defined prefix `_`. 

*Example:*
```cpp
int _private_variable; 
```

### Constants & Preprocessor Values 
Constants are expression with a fixed value. They are defined with the *key* `const. The naming convention for constants and preprocessor values prescribes that all letters are upper case letters with snake case subdivision

*Example:*
```cpp
const int PI_VALUE = 3.14159; 
```

### Functions
A function is a block of code which runs when it's called. Data in form of parameters can be passed into a function. Functions can be written as *non-returning* and *returning* type. Functions should start with a **lower case** letter. The following word should be **upper case**. This method is called *camelCase*

*Example:*
```cpp
void exampleFunktion()
{
   // do some stuff
}
```

### Classes (Types, Template parameters) 
`C++` is a object-oriented programming language. Therefore it's all about creating objects which contain both data and functions for a certain task.

![iu.png](https://bitbucket.org/repo/g5EKkgo/images/4149841531-iu.png)

In the example picture shown above, there is the *class* `car` defined, which has certain *methods* and *attributes*. This *class* can be used to create different objects which share the same *set* of properties with different values.

A class should be defined with **all upper case** (PascalCase) notation.

*Example:*
```cpp
class Car 
{
  public:
    string brand; 
    int max_speed; 
    int power;
    Car(string ini_brand, int ini_speed, ini_power)
    {
       brand = ini_brand; 
       max_speed = ini_speed; 
       power = ini_power; 
    }
  
  private: 
    int _current_speed; 
};

void GeneralCar::setSpeed(int new_speed)
{
    _current_speed = new_speed; 
}

int main()
{
   // declaration of two objects
   Car car1("Auto1", 200, 100); 
   Car car2("Auto2", 300, 200); 
   
   //setting the speed
   car1.setSpeed(250);
   
   return 0;   
}
```

### Braces 

In order to get a clear structure the following braces scheme should be taking into account when programming. Every left brace (`{`) should be appear by itself on the line below it the block it opens. The corresponding right brace (`}`) should be placed by itself in the same position th appropriate number of lines later in the file. 

*Example*
```cpp
if(car.speed == "fast")
{
   car.price = "high"; 
}
else
{
   car.price = "low"; 
}
```

The indentation should always be made with a `tab`. For every hierarchy step one `tab` has to be added. 

*Example*
```cpp
if(car.speed == "fast")
{
   car.price = "high";
   if(car.weight >= 1000)
   {
      car.type = "Truck"; 
   }
}
else
{
   car.price = "low"; 
}
```


### Comments
If the section of code is not clearly understandable there should be a short description of the current function in form of a comment. For commenting block `//` should be used. 

!!! WARNING
    Inline comments should be used with caution, because they can cause chaotic code. 

*Example {==DON'T==}*
```cpp
// divides up two double values
double division(double dividend, double divisor)
{
   // this is the result variable
   double div; 
   // the result is calculated here:
   div = dividend / divisor; 
   // here the result is given back
   return div;
}
```
