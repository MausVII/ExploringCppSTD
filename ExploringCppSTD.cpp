#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <ostream>

template<class Container>
void write_to_cout(const Container& container, const char* delimiter = " ") {
	std::copy(container.begin(), container.end(),
		std::ostream_iterator<Container::value_type>(std::cout, delimiter));
}

int main() {
	//////////////////////////		 Copy
	std::vector<std::string> a = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
	std::vector<std::string> b = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
	// Initial States
	write_to_cout(a);
	std::cout << std::endl;
	write_to_cout(b);
	std::cout << std::endl;
	// Test algorithm
	// You cannot copy to a destination that is within the range you are copying from
	std::copy(a.begin() + 3, a.begin() + 7, b.begin() + 6);
	std::copy(a.begin() + 2, a.begin() + 5, a.begin() + 7);
	// Write result
	write_to_cout(b);
	std::cout << std::endl;
	write_to_cout(a);
	std::cout << std::endl << std::endl;

	////////////////////////	Copy_n
	a = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
	b = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
	// Test
	std::copy_n(b.begin(), 4, b.begin() + 5);

	std::cout << "Enter four values typed out (one instead of 1) ";
	std::copy_n(std::istream_iterator<std::string>(std::cin), 4, a.begin());

	std::cout << std::endl;
	std::cout << "Copy_n from b.begin(), size = 4, to b.begin() + 5:\n";
	write_to_cout(b);
	std::cout << std::endl;
	std::cout << "Copy_n from cin, size = 4, to a.begin():\n";
	write_to_cout(a);
	std::cout << std::endl;

	////////////////////////	Copy_if
	std::string str1 = "Fun Times with the Capital Letters";
	std::string str2 = "wE hAvE bEeN oVeRtAkEn bY tHe cApItAl lEtTeRs";

	// Initial States
	std::cout << "Initial States: " << std::endl;
	write_to_cout(str1);
	std::cout << std::endl;
	write_to_cout(str2);
	std::cout << std::endl;

	// Test 

	std::string uppers;
	std::copy_if(str1.begin(), str1.end(), std::back_inserter(uppers), std::isupper);
	std::copy_if(str2.begin(), str2.end(), std::back_inserter(uppers), std::isupper);

	// Result
	std::cout << "Copied all uppercases into a new string with copy_if: " << std::endl;
	write_to_cout(uppers);

	////////////////////////	Move
	a = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
	b = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

	// Initial states
	std::cout << std::endl << std::endl;
	write_to_cout(a);
	std::cout << std::endl;
	write_to_cout(b);

	// Test
	std::move(a.begin(), a.begin() + 3, b.begin());
	std::copy_if(std::make_move_iterator(a.begin()), std::make_move_iterator(a.end()), b.begin(), [](const std::string& str) {return str.size() > 3; });

	// Results
	std::cout << std::endl;
	write_to_cout(a, " | ");
	std::cout << std::endl;
	write_to_cout(b);

	////////////////////////	 swap_range
	a = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
	b = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

	// Initial States
	std::cout << std::endl << std::endl;
	write_to_cout(a);
	std::cout << std::endl;
	write_to_cout(b);

	// Test
	std::swap_ranges(a.begin(), a.begin() + 4, b.begin());


	// Results
	std::cout << std::endl;
	write_to_cout(a);
	std::cout << std::endl;
	write_to_cout(b);

	return 0;
}