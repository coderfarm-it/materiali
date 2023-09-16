bool works(int b) {
  long long sum = 0;
  for (int i = 0; i < b; ++i)
    sum += v[i];
  
  long long max_sum = sum;
  for (int i = b; i < n; ++i) {
    sum += v[i] - v[i - b];
    max_sum = max(max_sum, sum);
  }
  
  return max_sum <= m;
}
