# Advent of Code notes

Things I learn from doing tasks in advent of code.

## How to get input in C++?

Topic: Input/ Output, Files

1. Create an input fstream
2. Check if the file opened correctly otherwize show an error.
3. While we can get a line from the file write the current line from the file to a string.
4. Close the file

```cpp
std::ifstream inputFile("input.txt");
std::string currentLine;

if(inputFile.is_open())
{
    while(std::getline(inputFile, currentLine))
    {
        std::cout << currentLine << std::endl;
    }

    inputFile.close();
}
else
{
    std::cout << "Error: coudn't open file" << std::endl;
}
```

## How to split a string into a vector?

1. Include `sstream`
2. Create a `istringstream` stream and a string to get the current string
3. Use `std::getline` by passing the `istringstream`, `current string` and a `delimiter`.

```cpp
#include <sstream>

void splitString()
{
    std::string inputLine = "Apples Oranges";
    std::istringstream ss (inputline);
    std::string currentLine;
    char delimiter = '';

    while(std::getline(ss, currentline, delimiter))
    {
        std::cout << currentLine << std::endl;
    }
}

```
