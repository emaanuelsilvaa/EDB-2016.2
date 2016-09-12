#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>

template <typename BidirIt, typename Compare = std::less<>>
void merge_sort(BidirIt first, BidirIt last, Compare cmp = Compare {})
{
    const auto n = std::distance(first, last);
    
    if (n > 1) {
        const auto middle = std::next(first, n / 2);
        
        merge_sort(first, middle, cmp);
        merge_sort(middle, last, cmp);
        
        std::inplace_merge(first, middle, last, cmp);
    }
}

#include <vector>

int main()
{
    std::vector<int> v {3, -2, 1, 5, -9, 10, 3, -3, 2};
    
	std::cout << "[ ";
	for(int &e: v)
		std::cout << e << " "; 
	std::cout << "]\n";
    merge_sort(std::begin(v), std::end(v)); // sort increasing
	std::cout << "[ ";
	for(int &e: v)
		std::cout << e << " "; 
	std::cout << "]\n";
    merge_sort(std::begin(v), std::end(v), std::greater<> {}); // sort decreasing
}
