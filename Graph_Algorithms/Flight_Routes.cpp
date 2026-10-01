input/code.cpp: In function 'int main()':
input/code.cpp:55:29: warning: comparison of integer expressions of different signedness: 'std::priority_queue<long long int>::size_type' {aka 'long unsigned int'} and 'long long int' [-Wsign-compare]
   55 |         if(dist[node].size()==K)
      |            ~~~~~~~~~~~~~~~~~^~~
input/code.cpp:65:30: warning: comparison of integer expressions of different signedness: 'std::priority_queue<long long int>::size_type' {aka 'long unsigned int'} and 'long long int' [-Wsign-compare]
   65 |             if(dist[v].size()<K)
      |                ~~~~~~~~~~~~~~^~
input/code.cpp:70:35: warning: comparison of integer expressions of different signedness: 'std::priority_queue<long long int>::size_type' {aka 'long unsigned int'} and 'long long int' [-Wsign-compare]
   70 |             else if(dist[v].size()==K)
      |                     ~~~~~~~~~~~~~~^~~