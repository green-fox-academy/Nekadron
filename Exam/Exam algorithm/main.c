/* Write a function which is called "get_fibonacci_number". It returns the "N"th
 * Fibonacci number, where "N" is received as a paramter.
 * For example:
 *  - get_fibonacci_number(1) returns 0
 *  - get_fibonacci_number(2) returns 1
 *  - get_fibonacci_number(3) returns 1
 *  - get_fibonacci_number(4) returns 2
 *  - get_fibonacci_number(5) returns 3
 *  - get_fibonacci_number(6) returns 5
 *
 *  If the function gets invalid parameter it returns -1.
 */
int get_fibonacci_number(int);

int main() {

    int N = get_fibonacci_number(4);
    printf("%d", N);

    return -1;
}
    int get_fibonacci_number(int x) {

    if(x <= 1)

    return 1 - x;

    return get_fibonacci_number(x - 1) + get_fibonacci_number(x - 2);
    }
