## SAST Tools

[PVS-Studio](https://pvs-studio.com/pvs-studio/?utm_source=website&utm_medium=github&utm_campaign=open_source) - static analyzer for C, C++, C#, and Java code.

## Test Suite for Static Analysis

### Available Test Files (CWE types):

1. **buffer_overflow.cpp** - CWE-120: Buffer overflow (stack-based)
2. **command_injection.cpp** - CWE-78: OS command injection
3. **use_after_free.cpp** - CWE-416: Use after free
4. **weak_crypto.cpp** - CWE-327: Use of weak cryptographic algorithm (MD5, DES)
5. **hardcoded_secrets.cpp** - CWE-798: Use of hardcoded credentials
6. **integer_overflow.cpp** - CWE-190: Integer overflow
7. **memory_leak.cpp** - CWE-401: Memory leak
8. **invalid_free.cpp** - CWE-590: Free of memory not on heap, double free, use-after-free via alias
9. **out_of_bounds.cpp** - CWE-787: Out-of-bounds write
10. **divide_zero.cpp** - CWE-369: Divide by zero
11. **null_pointer.cpp** - CWE-476: Null pointer dereference
12. **heap_overflow.cpp** - CWE-122: Heap-based buffer overflow
13. **malware_code.cpp** - CWE-78/CWE-1335: Malware patterns — suspicious commands, hidden payloads, covert file operations
14. **incorrect_calculation.cpp** - CWE-480/CWE-682/CWE-644: Wrong operator (`=` vs `==`), off-by-one, logic error, infinite loop (step=0)
15. **integer_underflow.cpp** - CWE-191/CWE-787: Integer underflow, unsigned wrapping, pointer underflow, unsigned comparison error

### Running the Tests

```bash
mkdir -p build && cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -G "Unix Makefiles" ..
cmake --build .
./security_test
```
