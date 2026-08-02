# Lab 06 — Large Number Addition Using Stacks (C++)

**Add large integers or floats digit-by-digit** with a stack-based algorithm — common DSA lab for stack applications beyond parentheses.

## Idea

Convert numbers to digit stacks (and fractional stacks if needed), add from least significant digit with carry, reverse to print the sum. Supports types via **C++ templates**.

## Layout

| Path | Description |
|------|-------------|
| `main.cpp` + `LargeNumberAddition.h` | Menu: integer / float addition |
| `stack-variant/` | Alternate `BigAdder` implementation |

## Quick run

```bash
g++ -std=c++17 -Wall -o add main.cpp && ./add
g++ -std=c++17 -Wall -o add2 stack-variant/main.cpp && ./add2
```

## Related

- Precision stack adder → [`../07-stack-based-big-number-addition`](../07-stack-based-big-number-addition/)
- Stack basics → [`../05-stack-balanced-parentheses`](../05-stack-balanced-parentheses/)
