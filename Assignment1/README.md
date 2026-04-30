# CE-ESY-assignments
# Assignment 1: Circular Buffer Implementation

## Description
This is an implementation of a Circular Buffer (Ring Buffer) in C.
A circular buffer is a fixed-size data structure that connects the end back to the beginning, allowing efficient use of memory for streaming data.

## Implementation Details
- **Structure**: Used a `struct` containing a character array, a `head` pointer for reading, a `tail` pointer for writing, and a `count` variable to manage state.
- **Modulo Arithmetic**: Implemented the circular wrap-around logic using the `%` (modulo) operator: `(index + 1) % SIZE`.
- **Edge Case Handling**: 
    - **Overflow**: The `write` function checks `isFull()` before inserting data.
    - **Underflow**: The `read` function checks `isEmpty()` before extracting data.

## Testing
I have verified the correctness of the implementation by:
1. **Testing with a large buffer**: Set `SIZE` to 50, which allowed the full name and suffix to be stored and retrieved correctly.
2. **Testing with a small buffer**: Set `SIZE` to 5, which successfully triggered the "Buffer Overflow" error message when the input exceeded the capacity.
3. **Empty Verification**: Confirmed that the buffer returns to an empty state after all characters are read.
