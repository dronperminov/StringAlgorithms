#pragma once

#include <iostream>
#include <string>

// наиный алгоритм поиска подстроки s1 в строке i
int IndexOfNaive(const std::string &s, const std::string &s1) {
	if (s1.length() > s.length()) // если длина подстроки больше строки
		return -1; // такой строки точно нет

	size_t n = s.length();
	size_t m = s1.length();

	// проверяем каждую подстроку на совпадение с искомой
	for (size_t i = 0; i <= n - m; i++) {
		size_t j = 0;

		while (j < m && s[i + j] == s1[j])
			j++;

		if (j == m) // если дошли до конца искомой подстроки
			return i; // значит совпадают, возвращаем индекс
	}

	return -1; // не нашли, возвращаем -1
}

// алгоритм Кнута-Морриса-Пратта поиска подстроки s1 в строке i
int IndexOfKnutMorrisPratt(const std::string& s, const std::string& s1) {
	if (s1.length() > s.length()) // если длина подстроки больше строки
		return -1; // такой строки точно нет

	size_t n = s.length();
	size_t m = s1.length();
    size_t *function = new size_t[m]; // выделяем память под префикс-функцию

	function[0] = 0;

	// вычисляем префикс функцию
	for (size_t i = 1, j = 0; i < m; i++) {
		while (j > 0 && s1[i] != s1[j])
			j = function[j - 1];

		if (s1[i] == s1[j])
			j++;

		function[i] = j;
	}

	int index = -1;

	// выполняем поиск, используя рассчитанную префикс функцию
	for (size_t i = 0, j = 0; i < n; i++) {
		while (j > 0 && s[i] != s1[j])
			j = function[j - 1];

		if (s1[j] == s[i])
			j++;

		if (j == m) {
			index = i - m + 1; // нашли строку, запоминаем индекс
			break;
		}
	}

	delete[] function;

	return index; // возврашаем индекс
}

// алгоритм Рабина-Карпа поиска подстроки s1 в строке s
int IndexOfRabinKarp(const std::string& s, const std::string& s1) {
	if (s1.length() > s.length()) // если длина подстроки больше строки
		return -1; // такой строки точно нет

	size_t n = s.length();
	size_t m = s1.length();

	size_t d = 31; // основание для полиномиального хеширования

	size_t h = 1;
	size_t p = 0; // хеш подстроки
	size_t hash = 0;

	for (size_t i = 0; i < m - 1; i++) {
		p = d * p + s1[i];
		hash = d * hash + s[i];
		h *= d;
	}

	p = d * p + s1[m - 1];
	hash = d * hash + s[m - 1];

	for (size_t i = 0; i <= n - m; i++) {
		if (p == hash) { // если хеши совпали, проверяем на совпадение подстроки для исключения ложного срабатывания
			size_t j = 0;

			while (j < m && s1[j] == s[i + j])
				j++;

			if (j == m)
				return i;
		}

		if (i < n - m)
			hash = d * (hash - s[i] * h) + s[i + m];
	}

	return -1; // не нашли, возврашаем -1
}