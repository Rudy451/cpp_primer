// Exercise 15.34 (pg. 788) Query q = Query("fiery") & Query("bird") | Query("Wind")
// Constructors Executed in Processing Expression:
// Query (x3), BinaryQuery (x2), AndQuery, OrQuery, WordQuery (x3)

// Calls to rep made from cout << q:
// WordQuery("fiery"), WordQuery("bird"), WordQuery("Wind")

// Calls to eval made from q.eval;
// WordQuery("fiery"), WordQuery("bird"), WordQuery("Wind")
