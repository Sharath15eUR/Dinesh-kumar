# System Programming Concepts

## 1. Child Process - `fork()`

* `fork()` is used to create a new process by duplicating the calling process.
* The child process gets a copy of the parent’s memory, file descriptors, etc.
* Return value: 0 to the child, PID of child to the parent, -1 on failure.

**Use case:** Creating parallel tasks in Unix-based systems.

---

## 2. Handling Common Signals

* Signals are used by the OS to notify processes of events.
* Common signals:

  * `SIGINT`: Interrupt (Ctrl+C)
  * `SIGTERM`: Termination request
  * `SIGKILL`: Forceful kill
  * `SIGSEGV`: Segmentation fault
* Use `signal()` or `sigaction()` to handle them.

**Example:** Gracefully shutting down a server on SIGINT.

---

## 3. Exploring Kernel Crashes

* Kernel crashes (panics) occur due to invalid memory access, hardware faults, or bugs in kernel modules.
* Tools:

  * `dmesg` (logs)
  * `kdump` / `crash` (analyze crash dumps)
* Reasons:

  * Null pointer dereference in kernel
  * Buffer overflows
  * Invalid instruction execution

**Prevention:** Use static analysis, and test kernel code with virtual machines.

---

## 4. Time Complexity

* Measures how the execution time of an algorithm grows with input size.
* Common complexities:

  * O(1): Constant
  * O(log n): Binary Search
  * O(n): Linear
  * O(n²): Nested loops

**Use case:** Optimize code for performance and scalability.

---

## 5. Locking Mechanism - `mutex` / `spinlock`

* Used to protect shared data in concurrent programming.

### Mutex:

* Blocks the thread if the lock is not available.
* Best for user-space and scenarios with longer wait time.

### Spinlock:

* Busy-waits (spins) until the lock is available.
* Best for kernel-space or short critical sections.

**Difference:** Mutex sleeps when locked, spinlock keeps checking.

---