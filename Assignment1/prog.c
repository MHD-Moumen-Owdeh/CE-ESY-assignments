#include <stdio.h>
#include <string.h>

/*
 * TESTS DONE:

 * Testing "Buffer Overflow":
 *      1- Change SIZE to a small number (e.g., 5)
 *      2- Type a name longer than SIZE - 5 (to account for "CE-ESY") when prompted.
 *
 * Testing "Normal Operation":
 *      1- Change SIZE to a larger number (e.g., 50).
 *      2- Type a name shorter than SIZE - 5 (to account for "CE-ESY") when prompted.
 *
 * SIDENOTE: "Underflow will not be reached in this program
 * since we only read after writing,
 * but read function can be tested by trying to read from an empty buffer."
 */
#define SIZE 10

// Structure definition for the Circular Buffer
typedef struct
{
    char buffer[SIZE];
    int head;  // Points to the next element to be read
    int tail;  // Points to the next position to be written
    int count; // Tracks the current number of elements in the buffer
} CircularBuffer;

// Function to initialize the buffer to an empty state
void init(CircularBuffer *cb)
{
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// Helper function to check if the buffer is empty
int isEmpty(CircularBuffer *cb)
{
    return cb->count == 0;
}

// Helper function to check if the buffer is full
int isFull(CircularBuffer *cb)
{
    return cb->count == SIZE;
}

// Function to write data into the buffer
void write(CircularBuffer *cb, char data)
{
    if (isFull(cb))
    {
        printf("\nBuffer Overflow: Cannot write '%c'\nIt's full, bro.\n", data);
        return;
    }

    cb->buffer[cb->tail] = data;
    cb->count++;

    // Use modulo operator to wrap the tail pointer back to 0 if it reaches SIZE
    cb->tail = (cb->tail + 1) % SIZE;
}

// Function to read data from the buffer
char read(CircularBuffer *cb)
{
    if (isEmpty(cb))
    {
        printf("\nBuffer Underflow\n Nothing to see here bro.\n");
        return '\0'; // Return null character on underflow
    }

    char data = cb->buffer[cb->head];
    cb->count--;

    // Use modulo operator to wrap the head pointer back to 0 if it reaches SIZE
    cb->head = (cb->head + 1) % SIZE;

    return data;
}

int main()
{
    CircularBuffer cb;
    init(&cb);

    char name[50];
    printf("Enter your name: ");
    // %49s prevents buffer overflow of the 'name' array itself
    if (scanf("%49s", name) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    // Appending the suffix "CE-ESY" to the name
    strcat(name, "CE-ESY");

    printf("Writing string \"%s\" to the circular buffer...\n", name);
    for (int i = 0; i < strlen(name); i++)
    {
        write(&cb, name[i]);
    }

    printf("Reading data back from buffer: ");
    while (!isEmpty(&cb))
    {
        printf("%c", read(&cb));
    }
    printf("\n");

    // Ensuring the buffer is empty after the process
    if (isEmpty(&cb))
    {
        printf("Verification: The buffer is now logically empty (count = 0).\n");
    }
    else
    {
        printf("Verification: The buffer still contains data.\n");
    }

    return 0;
}