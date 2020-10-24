/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 19:01:31 by jjosephi          #+#    #+#             */
/*   Updated: 2020/05/01 23:19:51 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include "list.hpp"
#include <assert.h>
#include <string>

int main()
{
	ft::vector<int> vec(5,10);
	ft::vector<int> vec2(5,20);
	

	printf("Vector tests'''''''''''''''''''''''''''''''''''''''''''''''''''\n\n");
	printf("Size should be 5;\nSize is: %zu\nArray : ", vec.size());
	
	for (size_t i = 0; i < vec2.size(); i++)
	{
		printf("%d ", vec2[i]);
	}
	printf("\n");
	
	vec2[1] = 42;
	printf("Change 2nd elem to 42\n");
	
	for (size_t i = 0; i < vec2.size(); i++)
	{
		printf("%d ", vec2[i]);
	}
	printf("\n");
	
	printf("Second vector is\n");
	for (size_t i = 0; i < vec.size(); i++)
	{
		printf("%d ", vec[i]);
	}
	printf("\n");
	
	printf("Operator= \nVect1: ");
	vec.operator=(vec2);

	for (size_t i = 0; i < vec2.size(); i++)
	{
		printf("%d ", vec2[i]);
	}
	printf("\nVect2: ");
	
	for (size_t i = 0; i < vec2.size(); i++)
	{
		printf("%d ", vec2[i]);
	}
	printf("\n");
	
	printf("Is vec2 empty? %d\n", vec2.empty());
	vec2.clear();
	printf("Cleared vec2. Is empty? %d\n", vec2.empty());
	printf("Size is: %zu\n", vec2.size());
	vec2.reserve(20);
	printf("Reserved 20; Size of vector : %zu\n", vec2.capacity());

	vec2.assign(20,42);
	
	printf("Filled vec2 with 42. Size = %zu\n", vec2.size());

	printf("\nVec2:");
	for (size_t i = 0; i < vec2.size(); i++)
	{
		printf("%d ", vec2[i]);
	}
	printf("\n");
	
	vec2.insert(18, 69);
	printf("Inserted 69 at pos 17 %d\n",vec2[18]);
	
	for (size_t i = 0; i < vec2.size(); i++)
	{
		printf("%d ", vec2[i]);
	}
	printf("\n");
	
	vec2.push_back(3);
	printf("Pushed 3 at back\n");

	printf("\nVec2:");
	for (size_t i = 0; i < vec2.size(); i++)
	{
		printf("%d ", vec2[i]);
	}
	printf("\n");
	
	vec2.pop_back();
	printf("Removed elem at back\n");
	
	printf("\nVec2:");
	for (size_t i = 0; i < vec2.size(); i++)
	{
		printf("%d ", vec2[i]);
	}
	printf("\n");
	
	vec2.erase(18);
	
	printf("Removed element 17\n");


	printf("\nVec2:");
	for (size_t i = 0; i < vec2.size(); i++)
	{
		printf("%d ", vec2[i]);
	}
	printf("\n");

	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i] = i;
	}
	
	printf("Swapping vec1 and vec2\n\nBefore :\nVec1: ");
	for (size_t i = 0; i < vec.size(); i++)
	{
		printf("%d ", vec[i]);
	}
	printf("\nVec2:");
	for (size_t i = 0; i < vec2.size(); i++)
	{
		printf("%d ", vec2[i]);
	}
	printf("\n");
	vec2.swap(vec);
	printf("After :\nVec1: ");
	for (size_t i = 0; i < vec.size(); i++)
	{
		printf("%d ", vec[i]);
	}
	printf("\nVec2:");
	for (size_t i = 0; i < vec2.size(); i++)
	{
		printf("%d ", vec2[i]);
	}
	printf("\n");
	
	printf("printing first elem %d\n", vec2.front());
	printf("printing elem at back %d\n", vec2.back());
//```````````````````````````````````````````````````````````````````````````
	printf("\n\nList tests---------------------------------------\n\n");
	ft::list<int> lst(3,42);

	ft::list<int>::Iterator it1;
	ft::list<int>::Iterator end;

	
	it1 = lst.begin();
	printf("First elem in list %d\n", *it1.operator->());
	lst.push_back(69);
	end = lst.end();
	printf("List size: %zu\n", lst.size());

	for (; it1.operator!=(end) ; it1.operator++() )
	{
		printf("%d ", *it1.operator->());
	}
	printf("%d ", *it1.operator->());

	lst.assign(1, 420);
	it1 = lst.begin();
	end = lst.end();
	printf("\nAssigning 420 to element 2\n");
	for (; it1.operator!=(end) ; it1.operator++())
	{
		printf("%d ", *it1.operator->());
	}
	printf("%d ", *it1.operator->());

	lst.resize(2);


	it1 = lst.begin();
	end = lst.end();
	printf("\n Resized list to 2 elements %zu\n", lst.size());
	for (; it1.operator!=(end) ; it1.operator++() )
	{
		printf("%d ", *it1.operator->());
	}
	printf("%d ", *it1.operator->());

	
	lst.erase(lst.begin());

	it1 = lst.begin();
	end = lst.end();
	printf("\nRemoved first element; size: %zu\n", lst.size());
	for (; it1.operator!=(end) ; it1.operator++() )
	{
		printf("%d ", *it1.operator->());
	}
	printf("%d ", *it1.operator->());
	lst.push_back(35);
	lst.push_front(53);

	it1 = lst.begin();
	end = lst.end();
	printf("\nPushed 53 front, 35 back; size: %zu\n", lst.size());
	for (; it1.operator!=(end) ; it1.operator++() )
	{
		printf("%d ", *it1.operator->());
	}
	printf("%d ", *it1.operator->());
	lst.pop_back();
	lst.pop_front();

	it1 = lst.begin();
	end = lst.end();
	printf("\nPoped front and back; size: %zu\n", lst.size());
	for (; it1.operator!=(end) ; it1.operator++() )
	{
		printf("%d ", *it1.operator->());
	}
	printf("%d ", *it1.operator->());
	
	ft::list<int> lst2(5,42);
	lst2.assign(1, 430);
	lst2.assign(2, 69);
	lst2.assign(4, 1);

	it1 = lst2.begin();
	end = lst2.end();
	printf("\n;New list: size: %zu\n", lst2.size());
	for (; it1.operator!=(end) ; it1.operator++() )
	{
		printf("%d ", *it1.operator->());
	}
	printf("%d ", *it1.operator->());

	lst2.unique();


	it1 = lst2.begin();
	end = lst2.end();
	printf("\nRemoved duplicates: size: %zu\n", lst2.size());
	for (; it1.operator!=(end) ; it1.operator++() )
	{
		printf("%d ", *it1.operator->());
	}
	printf("%d ", *it1.operator->());

	lst2.sort();

	
	it1 = lst2.begin();
	end = lst2.end();
	printf("\nSorted list; size: %zu\n", lst2.size());
	for (; it1.operator!=(end) ; it1.operator++() )
	{
		printf("%d ", *it1.operator->());
	}
	printf("%d ", *it1.operator->());
	lst2.reverse();

it1 = lst2.begin();
	end = lst2.end();
	printf("\nReverse list; size: %zu\n", lst2.size());
	for (; it1.operator!=(end) ; it1.operator++() )
	{
		printf("%d ", *it1.operator->());
	}
	printf("%d ", *it1.operator->());
	

	it1 = lst.begin();
	end = lst.end();
	printf("\nSwap list; size: %zu\n Before\n lst1 :", lst2.size());
	for (; it1.operator!=(end) ; it1.operator++() )
	{
		printf("%d ", *it1.operator->());
	}
	printf("%d\n list2:", *it1.operator->());

	it1 = lst2.begin();
	end = lst2.end();
	for (; it1.operator!=(end) ; it1.operator++() )
	{
		printf("%d ", *it1.operator->());
	}
	printf("%d ", *it1.operator->());
	lst2.swap(lst);


it1 = lst.begin();
	end = lst.end();
	printf("\n After\n lst1 : ");
	for (; it1.operator!=(end) ; it1.operator++() )
	{
		printf("%d ", *it1.operator->());
	}
	printf("%d\n list2:", *it1.operator->());

	it1 = lst2.begin();
	end = lst2.end();
	for (; it1.operator!=(end) ; it1.operator++() )
	{
		printf("%d ", *it1.operator->());
	}
	printf("%d \n Merge lists:", *it1.operator->());
	
	lst2.merge(lst);
	
	it1 = lst2.begin();
	end = lst2.end();
	for (size_t i = 0; i < lst2.size() ; i++)
	{
		printf("%d ", *it1.operator->());
		it1.operator++();
	}

	
	printf("\n\nMap tests---------------------------------------\n\n");

	ft::map<int, int> mp;
	ft::map<int, int> mp2;
	ft::map<int, int>::Iterator it;
	ft::map<int, int>::Iterator en;
	mp.insert(42, 1);
	mp.insert(32, 2);
	mp.insert(12, 3);
	mp.insert(22, 4);
	it = mp.begin();

	mp2.insert(24, 42);
	mp2.insert(23, 43);
	
	printf("Inserted 4 elements in map1; Size %zu\n", mp.size());
	for (size_t i = 0; i < mp.size() ; i++)
	{
	//	printf("(Key : %d Value : %d)\n", *it.operator->(), mp.operator[](0));
		printf("(Key : %d Value : %d)  ", *it.operator->(), mp.operator[](*it.operator->()));
		it.operator++();
	}
	
	it = mp2.begin();
	printf("\nInserted 2 elements in map2; Size %zu\n", mp2.size());
	for (size_t i = 0; i < mp2.size() ; i++)
	{
		printf("(Key : %d Value : %d)  ", *it.operator->(), mp2.operator[](*it.operator->()));
		it.operator++();
	}
	printf("\nValue of key 12: %d\n",mp.operator[](12));
	printf("Number of key55 : %zu, number of key 32 %zu\n", mp.count(55), mp.count(32));
	mp.erase(32);
	printf("Erased key 32\n");

	it = mp.begin();
	for (size_t i = 0; i < mp.size() ; i++)
	{
		printf("Key : %d Value : %d   ", *it.operator->(), mp.operator[](*it.operator->()));
		it.operator++();
	}

	printf("\nOperator = (map1 = map2)\n");

	printf("Before :\n Map1: ");
	it = mp.begin();
	for (size_t i = 0; i < mp.size() ; i++)
	{
		printf("Key : %d Value : %d   ", *it.operator->(), mp.operator[](*it.operator->()));
		it.operator++();
	}

	printf("\nMap2: ");
	it = mp2.begin();
	for (size_t i = 0; i < mp2.size() ; i++)
	{
		printf("Key : %d Value : %d   ", *it.operator->(), mp2.operator[](*it.operator->()));
		it.operator++();
	}

	 
	mp.operator=(mp2);

	printf("\nAfter :\n Map1: ");
	it = mp.begin();
	for (size_t i = 0; i < mp.size() ; i++)
	{
		printf("Key : %d Value : %d   ", *it.operator->(), mp.operator[](*it.operator->()));
		it.operator++();
	}

printf("\nMap2: ");
	it = mp2.begin();
	for (size_t i = 0; i < mp2.size() ; i++)
	{
		printf("Key : %d Value : %d   ", *it.operator->(), mp2.operator[](*it.operator->()));
		it.operator++();
	}
	printf("Clearing map2\n");
	mp2.clear();
	it = mp.begin();
	en = mp.end();
		printf("Is map 2 empty? %d\n",mp2.empty());

	
	printf("\n\nStack tests---------------------------------------\n\n");

	ft::stack<int> tea(1);

	printf("Is the queue empty? %d\n",tea.empty());
	tea.push(42);
	tea.push(69);
	printf("Pushed 42 and 69. Size = %zu\n",tea.size());
	printf("Front value %d\n", tea.front());
	printf("back Value %d\n", tea.back());
	tea.pop();
	printf("Pop() teat. First : %d, last: %d , size : %zu\n", tea.front(), tea.back(), tea.size());
	
	printf("\n\nQueue tests---------------------------------------\n\n");

	ft::queue<int> tes(0);

	printf("Is the queue empty? %d\n",tes.empty());
	tes.push(42);
	tes.push(69);
	printf("Pushed 42 and 69. Size = %zu\n",tes.size());
 	printf("Front value %d\n", tes.front());
	printf("back Value %d\n", tes.back());
 	tes.pop();
	printf("Pop() test. First : %d, last: %d , size : %zu\n", tes.front(), tes.back(), tes.size());
}
