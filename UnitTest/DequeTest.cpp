#include <boost/test/unit_test.hpp>
#include "Deque/Deque.h"
#include "Exception/CollectionEmptyException.h"
#include "Exception/ConcurrentModificationException.h"
#include <iostream>

BOOST_AUTO_TEST_SUITE(DoublyLinkedListTest)

	BOOST_AUTO_TEST_CASE(TestingSizeInitialZero) {
		Deque <int> list = Deque <int>();
		BOOST_CHECK_EQUAL(0, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingisEmpty) {
		Deque <int> list = Deque <int>();
		BOOST_CHECK(list.isEmpty());
	}

	BOOST_AUTO_TEST_CASE (TestingSizeIncrement) {
		Deque <int> list = Deque <int>();
		list.addFirst(2);
		BOOST_CHECK_EQUAL(list.size(), 1);
		const int temp = list.removeFirst();
		BOOST_CHECK_EQUAL(list.size(), 0);
		BOOST_CHECK_EQUAL(2, temp);
	}

	BOOST_AUTO_TEST_CASE(TestingGetWhenEmpty) {
		Deque <int> list = Deque <int>();
		BOOST_CHECK_THROW(list.getFirst(), CollectionEmptyException);
		BOOST_CHECK_THROW(list.getLast(), CollectionEmptyException);
	}

	BOOST_AUTO_TEST_CASE(TestingGetFirst) {
		Deque <int> list = Deque <int>();
		list.addFirst(2);
		BOOST_CHECK_EQUAL(2, list.getFirst());
		list.addFirst(3);
		BOOST_CHECK_EQUAL(3, list.getFirst());
		list.addFirst(4);
		BOOST_CHECK_EQUAL(4, list.getFirst());
		list.addLast(1);
		BOOST_CHECK_EQUAL(4, list.getFirst());
	}

	BOOST_AUTO_TEST_CASE(TestingGetLast) {
		Deque <int> list = Deque <int>();
		list.addLast(2);
		BOOST_CHECK_EQUAL(2, list.getLast());
		list.addLast(3);
		BOOST_CHECK_EQUAL(3, list.getLast());
		list.addLast(4);
		BOOST_CHECK_EQUAL(4, list.getLast());
		list.addFirst(1);
		BOOST_CHECK_EQUAL(4, list.getLast());
	}

	BOOST_AUTO_TEST_CASE(TestingAddFirst) {
		Deque <int> list = Deque <int>();
		for (int i = 0; i < 100; i++) {
			list.addFirst(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingAddLast) {
		Deque <int> list = Deque <int>();
		for (int i = 0; i < 100; i++) {
			list.addLast(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingAdd) {
		Deque <int> list = Deque <int>();
		for (int i = 0; i < 100; i++) {
			list.add(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
		for (int i = 0; i < 100; i++) {
			BOOST_CHECK_EQUAL(i, list.removeFirst());
		}
	}

	BOOST_AUTO_TEST_CASE(TestingADDFirstAddLast) {
		Deque <int> list = Deque <int>();
		for (int i = 0; i < 100; i++) {
			if ((i % 2) == 0) {
				list.addFirst(-i);
			} else {
				list.addLast(i);
			}
		}
		int prev = -5000;
		for (int i = 0; i < 100; i++) {
			int x = list.removeFirst();
			BOOST_CHECK_GT(x, prev);
			prev = x;
		}
		BOOST_CHECK_EQUAL(0, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingAddFirstAndRemoveFirst) {
		Deque <int> list = Deque <int>();
		for (int i = 0; i < 100; i++) {
			list.addFirst(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
		for (int i = 99; i >= 0; i--) {
			BOOST_CHECK_EQUAL(i, list.removeFirst());
		}
		BOOST_CHECK_EQUAL(0, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingAddFirstAndRemoveLast) {
		Deque <int> list = Deque <int>();
		for (int i = 0; i < 100; i++) {
			list.addFirst(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
		for (int i = 0; i < 100; i++) {
			BOOST_CHECK_EQUAL(i, list.removeLast());
		}
		BOOST_CHECK_EQUAL(0, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingAddLastAndRemoveFirst) {
		Deque <int> list = Deque <int>();
		for (int i = 0; i < 100; i++) {
			list.addLast(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
		for (int i = 0; i < 100; i++) {
			BOOST_CHECK_EQUAL(i, list.removeFirst());
		}
		BOOST_CHECK_EQUAL(0, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingAddLastAndRemoveLast) {
		Deque <int> list = Deque <int>();
		for (int i = 0; i < 100; i++) {
			list.addLast(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
		for (int i = 99; i >= 0; i--) {
			BOOST_CHECK_EQUAL(i, list.removeLast());
		}
		BOOST_CHECK_EQUAL(0, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingClear) {
		Deque <int> list = Deque <int>();
		for (int i = 0; i < 100; i++) {
			list.add(i);
		}
		BOOST_CHECK_EQUAL(100, list.size());
		list.clear();
		BOOST_CHECK_THROW(list.getFirst(), CollectionEmptyException);
		BOOST_CHECK_THROW(list.getLast(), CollectionEmptyException);
		BOOST_CHECK_EQUAL(0, list.size());
	}

	BOOST_AUTO_TEST_CASE(TestingQueueMethod) {
		Deque <int> list = Deque <int>();
		for (int i = 0; i < 100; i++) {
			list.enqueue(i);
		}
		for (int i = 0; i < 100; i++) {
			BOOST_CHECK_EQUAL(i, list.peek());
			BOOST_CHECK_EQUAL(i, list.dequeue());
		}
	}

	BOOST_AUTO_TEST_CASE(TestingStackMethod) {
		Deque <int> list = Deque <int>();
		for (int i = 0; i < 100; i++) {
			list.push(i);
		}
		for (int i = 99; i >= 100; i--) {
			BOOST_CHECK_EQUAL(i, list.peek());
			BOOST_CHECK_EQUAL(i, list.pop());
		}
	}

	BOOST_AUTO_TEST_CASE(TestingAddAll) {
		// also concurrent test
		BOOST_CHECK(false); // leave for future
	}

	BOOST_AUTO_TEST_CASE(TestingAddDerivedClass) {
		typedef struct base {
		public:
			int b;

			explicit base (int b): b(b) {
				std::cout << "create base class with " << b << std::endl;
			}

			virtual ~base () {
				std::cout << "base class's destructor" << std::endl;
			}

			virtual void print () {
				std::cout << "i'm base class " << this->b << std::endl;
			}
		} base;
		typedef struct derived : base {
		public:
			int d;

			explicit derived (int b, int d): base(b), d(d) {
				std::cout << "create derived class with " << b << " " << d << std::endl;
			}

			virtual ~derived () {
				std::cout << "derived class's destructor" << std::endl;
			}

			virtual void print () override {
				std::cout << "i'm derived class " << this->b << " and " << this->d << std::endl;
			}
		} derived;

		base b = base(1);
		derived d = derived(2, 3);
		base & baseRef1 = b;
		base & baseRef2 = d;
		baseRef1.print();
		baseRef2.print();
		base baseValue1 = baseRef1;
		base baseValue2 = baseRef2;
		baseValue1.print();
		baseValue2.print();
		Deque <base> list = Deque <base>();
		list.add(b);
		list.add(d);
		base b1 = list.removeFirst();
		base b2 = list.removeFirst();
		b1.print();
		b2.print();
		BOOST_CHECK(false); // leave for future
	}

BOOST_AUTO_TEST_SUITE_END()