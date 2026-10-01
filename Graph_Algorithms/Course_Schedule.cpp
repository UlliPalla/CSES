input/code.cpp: In function 'int main()':
input/code.cpp:46:18: warning: comparison of integer expressions of different signedness: 'std::vector<long long int>::size_type' {aka 'long unsigned int'} and 'long long int' [-Wsign-compare]
   46 |     if(sol.size()<(ll)N)
      |        ~~~~~~~~~~^~~~~~
input/code.cpp:51:17: warning: comparison of integer expressions of different signedness: 'long long int' and 'std::vector<long long int>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   51 |     for(ll i=0;i<sol.size();i++)
      |                ~^~~~~~~~~~~