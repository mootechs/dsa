#include <iostream>
#include <vector>
#include <utility>

//find_min.cpp
//Finds the smallest and second smallest elements of an unordered 
//array size 2^n using divide and conquer.
template <typename T>
auto find_min(std::vector<T> lines) 
{
  if (lines.size() == 2) {
      
      return lines[0] < lines[1] ?
              std::make_pair(lines[0], lines[1]) :
              std::make_pair(lines[1], lines[0]);
  }
  else {
    T first, second;
    std::size_t const half_size = lines.size() / 2;
    std::vector<T> split_lo(lines.begin(), lines.begin() + half_size);
    std::vector<T> split_hi(lines.begin() + half_size, lines.end());
    auto left = find_min(split_lo);
    auto right = find_min(split_hi);
    first = right.first < left.first ?
            right.first : left.first;

    //Now we are checking for the second smallest
    auto comp1 =  left.first < right.second ? 
                  left.first : right.second;
    auto comp2 =  left.second < right.second ? 
                  left.second : right.second;
    second = comp1 < comp2 ? comp1 : comp2;
    return std::make_pair(first, second);
  }
}

int main()
{
  std::vector<int> lines = { 5,4,0,1,-1,6,5000,-11000};
  auto result = find_min(lines);
  std::cout << result.first << " " << result.second << std::endl;
}
