int l = 0, r = n+1; // [l, r)

while (r - l > 1) {
  int mid = (l + r) / 2;
  if (v[mid]==0) {
    l = mid;
  } else {
    r = mid;
  }
}

// return l;
