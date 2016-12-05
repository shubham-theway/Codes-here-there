#include <string>
#include <iostream>

template<typename show>
void permutations(std::string s, show consume, std::size_t start = 0) {
	if (start == s.length()) consume(s);
	for (std::size_t i = start; i < s.length(); i++) {
		std::swap(s[start], s[i]);
		permutations(s, consume, start + 1);
	}
}

int main342525(void) {
	std::string s = "abc";
	permutations(s, [](std::string s) {
		std::cout << s << std::endl;
	});
	system("pause");
	return 0;
}