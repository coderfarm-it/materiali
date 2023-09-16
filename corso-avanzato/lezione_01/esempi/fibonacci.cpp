// n-esimo numero di fibonacci
int fib(n) {
  if (n <= 1) {
    return 1;
  }
  return fib(n-1) + fib(n-2);
}
