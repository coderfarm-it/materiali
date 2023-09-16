cin >> N;				// O(1)
int somma = 0;			// O(1)

// eseguito O(N) volte
for(int i = 0; i < N; i++){
  int a;				// O(1)
  cin >> a;				// O(1)
  somma += a;			// O(1)
}

cout<<somma<<endl; 		// O(1)

// totale O(1+1+ N*(1+1+1) +1)
// = O(2+3*N+1) = O(N)