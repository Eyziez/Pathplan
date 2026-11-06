#pragma once
#include<iostream>
#include<vector>
#include<utility>

using std::vector;
using std::pair;

template<typename T>

vector < std::pair<T, T>> cartesian_product(const vector<T>& A, const vector<T>& B)
{
	vector<pair<T, T>> result;

	result.reserve(A.size() * B.size());

	for (const auto& a : A)
		for (const auto& b : B)
			result.emplace_back(a, b);
	return result;
}