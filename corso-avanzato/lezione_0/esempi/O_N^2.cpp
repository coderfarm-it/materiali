cin >> N;				// O(1)
int somma = 0;			// O(1)

// eseguito O(N) volte
for (int i = 0; i < N; i++){
  
  // eseguito O(N-i) volte
  for (int j = i; i < N; i++){
    somma += i*j;		// O(1)
  }			
}

cout << somma << endl; 	// O(1)

// totale O(1+1+ N*(N+1)/2 +1)
// = O(3+N*(N+1)/2) = O(N^2)