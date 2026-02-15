# Push Swap

*This project has been created as part of the 42 curriculum by doabrour.*

## Description

Push_swap is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations, with the goal of minimizing the number of moves. The program takes a list of integers as input and outputs a series of operations that sort them in ascending order.

The project implements the **Turk Algorithm**, an efficient sorting strategy that:
- Pushes elements strategically from stack A to stack B
- Calculates the cost of moving each element
- Always chooses the "cheapest" move (least total operations)
- Pushes elements back to A in the correct sorted position
- Minimizes rotations by choosing optimal directions (rotate vs reverse rotate)

### Available Operations
- `sa` / `sb` : swap the first two elements of stack A / B
- `pa` / `pb` : push top element from B to A / from A to B
- `ra` / `rb` : rotate stack A / B (shift all elements up by one)
- `rra` / `rrb` : reverse rotate stack A / B (shift all elements down by one)
- `rr` / `rrr` : rotate both stacks simultaneously

### Algorithm Strategy
1. **Initial setup**: Push 2 elements to stack B
2. **Smart pushing**: For remaining elements (until 5 left in A):
   - Calculate cost for each element in A to reach its target position in B
   - Choose the element with minimum total cost
   - Execute the optimal rotation sequence
3. **Sort remaining**: Use optimized algorithm for 5 or fewer elements
4. **Push back**: Return all elements from B to A in sorted order
5. **Final rotation**: Rotate A to position minimum value at top

## Instructions

### Compilation
```bash
make
```

This will compile the project and create the `push_swap` executable.

### Usage
```bash
./push_swap [list of integers]
```

**Examples:**
```bash
# Basic usage
./push_swap 3 2 1 5 4

# Using quotes (space-separated)
./push_swap "3 2 1 5 4"

# Check number of operations
./push_swap 3 2 1 5 4 | wc -l

# Verify sorting with checker (if available)
./push_swap 3 2 1 5 4 | ./checker 3 2 1 5 4
```

### Performance Benchmarks
- **3 numbers**: ≤ 3 operations
- **5 numbers**: ≤ 12 operations
- **100 numbers**: ≤ 700 operations
- **500 numbers**: ≤ 5500 operations

### Error Handling
The program handles various error cases:
- Non-numeric arguments
- Numbers outside INT_MIN/INT_MAX range
- Duplicate numbers
- Empty or invalid input

Errors are displayed as `Error\n` to standard error.

## Resources

### Classic References
- [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer) - Tool to visualize the sorting process
- [Turk Algorithm Explanation](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) - Detailed breakdown of the Turk sorting strategy
- [42 Push Swap Guide](https://www.notion.so/Push-Swap-Tutorial) - Community tutorial on different approaches

### AI Usage
AI (Claude) was used for the following tasks in this project:

**Code Optimization & Refactoring:**
- Reducing functions to meet the 25-line Norminette limit
- Splitting large functions into smaller, reusable helper functions
- Optimizing variable usage to stay within the 5-variable limit
- Identifying and fixing code duplication issues

**Debugging:**
- Finding the critical bug in `find_position` (uninitialized variable)
- Resolving linker errors (duplicate symbol definitions)
- Fixing logical errors in cost calculation and direction setting
- Troubleshooting Norminette compliance issues

**Code Structure:**
- Designing helper functions like `set_cost_and_dir`, `find_position`, `rotate_to_target`
- Creating modular architecture for cost calculation system
- Organizing code to separate concerns (sorting small vs large stacks)

**Algorithm Understanding:**
- Clarifying Turk algorithm implementation details
- Explaining cost optimization (choosing between `ra` and `rra`)
- Understanding target finding logic for maintaining sorted order


## Author

Created with determination, debugging tears, and way too much coffee ☕
