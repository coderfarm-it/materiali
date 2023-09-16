bool works(int b) {
  for (int i = 0; i < n - b; i++) {
    long long sum = 0;
    for (int j = i; j < i + b; j++) {
      sum += v[j];
    }
    if (sum > m) return false;
  }
  return true;
}
