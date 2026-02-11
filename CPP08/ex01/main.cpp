/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <hguo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:27:12 by hguo              #+#    #+#             */
/*   Updated: 2026/02/11 16:27:13 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <climits>

static void printLine(const char* msg) {
    std::cout << "\n--- " << msg << " ---\n";
}

int main() {
    // 1) N = 0
    printLine("N=0 should refuse any add");
    try {
        Span sp(0);
        sp.addNumber(1);
        std::cout << "oops: no exception\n";
    } catch (const std::exception& e) {
        std::cout << "ok: " << e.what() << "\n";
    }

    // 2) empty spans
    printLine("empty span -> exception");
    try {
        Span sp(5);
        std::cout << sp.longestSpan() << "\n";
        std::cout << "oops: no exception\n";
    } catch (const std::exception& e) {
        std::cout << "ok: " << e.what() << "\n";
    }

    // 3) only one element
    printLine("one element -> exception");
    try {
        Span sp(1);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << "\n";
        std::cout << "oops: no exception\n";
    } catch (const std::exception& e) {
        std::cout << "ok: " << e.what() << "\n";
    }

    // 4) fill then overflow with addNumber
    printLine("fill then overflow (addNumber)");
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        std::cout << "oops: no exception\n";
    } catch (const std::exception& e) {
        std::cout << "ok: " << e.what() << "\n";
    }

    // 5) overflow with addNumbers
    printLine("overflow (addNumbers)");
    try {
        Span sp(3);
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        sp.addNumbers(v.begin(), v.end());
        std::cout << "oops: no exception\n";
    } catch (const std::exception& e) {
        std::cout << "ok: " << e.what() << "\n";
    }

    // 6) duplicates
    printLine("duplicates => shortest should be 0");
    try {
        Span sp(5);
        sp.addNumber(10);
        sp.addNumber(10);
        sp.addNumber(30);
        std::cout << "shortest = " << sp.shortestSpan() << " (want 0)\n";
        std::cout << "longest  = " << sp.longestSpan()  << " (want 20)\n";
    } catch (const std::exception& e) {
        std::cout << "unexpected: " << e.what() << "\n";
    }

    // 7) negative + mixed
    printLine("negative + mixed values");
    try {
        Span sp(5);
        sp.addNumber(-10);
        sp.addNumber(-3);
        sp.addNumber(7);
        std::cout << "shortest = " << sp.shortestSpan() << " (want 7)\n";
        std::cout << "longest  = " << sp.longestSpan()  << " (want 17)\n";
    } catch (const std::exception& e) {
        std::cout << "unexpected: " << e.what() << "\n";
    }

    // 8) addNumbers empty range
    printLine("addNumbers with empty range should do nothing");
    try {
        Span sp(3);
        std::vector<int> v;
        sp.addNumbers(v.begin(), v.end());
        std::cout << "ok: no exception\n";
        try {
            std::cout << sp.longestSpan() << "\n";
            std::cout << "oops: no exception\n";
        } catch (const std::exception& e) {
            std::cout << "ok (still empty): " << e.what() << "\n";
        }
    } catch (const std::exception& e) {
        std::cout << "unexpected: " << e.what() << "\n";
    }

    // 9) INT_MIN / INT_MAX
    printLine("INT_MIN / INT_MAX sanity check");
    try {
        Span sp(2);
        sp.addNumber(INT_MIN);
        sp.addNumber(INT_MAX);
        std::cout << "longest = " << sp.longestSpan() << "\n";
    } catch (const std::exception& e) {
        std::cout << "exception: " << e.what() << "\n";
    }
	
    return 0;
}
