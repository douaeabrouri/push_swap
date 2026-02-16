*This project has been created as part of the 42 curriculum by doabrour.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum.

The goal is to sort a stack of integers in ascending order using a restricted set of stack operations, while minimizing the total number of operations.

The program must:
- Take a list of integers as arguments
- Validate input
- Output the smallest possible sequence of instructions to sort them

This project focuses heavily on:
- Algorithm design
- Optimization
- Complexity analysis
- Stack manipulation
- Strategic cost calculation

---

## Project Objectives

- Implement stack-based sorting using only allowed operations
- Handle invalid inputs correctly
- Optimize the number of instructions
- Manage memory safely (no leaks)
- Respect 42 coding norms

---

## Program Rules

The program uses two stacks:

- Stack A (initially contains all numbers)
- Stack B (initially empty)

Allowed operations:

| Operation | Description |
|-----------|------------|
| sa | Swap first two elements of A |
| sb | Swap first two elements of B |
| ss | sa and sb simultaneously |
| pa | Push from B to A |
| pb | Push from A to B |
| ra | Rotate A upward |
| rb | Rotate B upward |
| rr | ra and rb simultaneously |
| rra | Reverse rotate A |
| rrb | Reverse rotate B |
| rrr | rra and rrb simultaneously |

---

## Algorithm Strategy

### Small Input (≤ 5 elements)

For small datasets:

1. Find the smallest element
2. Rotate stack A efficiently (ra or rra)
3. Push it to stack B
4. Sort the remaining 3 elements
5. Push elements back to stack A

This minimizes operations for small stacks.

---

### Large Input (> 5 elements)

For larger datasets, a cost-based strategy (Turk algorithm) is implemented:

1. Push elements from A to B
2. For each element in B:
   - Calculate cost to move it to correct position in A
   - Calculate rotation cost for A and B
3. Choose the move with the smallest total cost
4. Optimize rotations using combined operations (rr / rrr)
5. Repeat until sorted

---

## Cost Calculation Strategy

Each element in stack B has:

- cost_a → number of rotations needed in A
- cost_b → number of rotations needed in B

Total cost:
total_cost = max(|cost_a|, |cost_b|) if same direction
total_cost = |cost_a| + |cost_b| if opposite directions

We compare positions with `size / 2` to determine whether to use:

- rotate (ra/rb)
- reverse rotate (rra/rrb)

This ensures minimum movement inside stacks.



---

## Error Handling

The program handles:

- Non-numeric arguments
- Duplicate numbers
- Integer overflow
- Empty input
- Invalid formatting

In case of error, the program outputs:


---

## Instructions

### Compilation

To compile the project, run:
```bash
make
```

This will generate the `push_swap` executable.

### Execution
```bash
./push_swap [space-separated integers]
```

**Examples:**
```bash
# Sort a simple list
./push_swap 3 2 1 5 4

# Using quotes for multiple numbers
./push_swap "42 8 15 23 4 16"

# Count the number of operations
./push_swap 3 2 1 5 4 | wc -l

# Verify the result with checker (if available)
./push_swap 3 2 1 | ./checker 3 2 1
```

## Resources

### Classic References
- [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer) - Tool to visualize the sorting process
- [Turk Algorithm Explanation](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) - Detailed breakdown of the Turk sorting strategy
- [42 Push Swap Guide](https://www.notion.so/Push-Swap-Tutorial) - Community tutorial on different approaches
