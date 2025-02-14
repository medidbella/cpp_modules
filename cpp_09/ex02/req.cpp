#include <iostream>
#include <vector>


void mergeToVector(std::vector<int> &mainVec, std::vector<int> &left, std::vector<int> &right)
{
	unsigned int m = 0, r = 0, l = 0;

	while (m < mainVec.size() && r < right.size() && l < left.size())
	{
		if (left[l] < right[r])
			mainVec[m] = left[l++];
		else
			mainVec[m] = right[r++];
		m++;
	}
	// std::cout << "after loop:\n l = " << l << " r = " << r << '\n';
	while (r < right.size())
		mainVec[m++] = right[r++];
	while (l < left.size())
		mainVec[m++] = left[l++];
}

void recursiveSort(std::vector<int> &vec)
{
	static int i;

	i++;
	if (vec.size() == 1)
		return ;
	int size = vec.size();
	std::vector<int>::iterator it = vec.begin();
	std::vector<int> leftHalf(it, it + size / 2);
	std::vector<int> rightHalf(it + size / 2, vec.end());
	recursiveSort(leftHalf);
	recursiveSort(rightHalf);
	mergeToVector(vec, leftHalf, rightHalf);
}

int main()
{
	int arr[] = {6, 2, 7, 5 ,3 , 9, 10, 8};
	std::vector<int> test(arr, arr+8);
	recursiveSort(test);
	for(unsigned int i = 0;i < test.size();i++)
		std::cout << test[i] << ' ';
	std::cout << '\n';
}
