#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "BacklogPublisher.hpp"
#include "SimplePublisher.hpp"
#include "PeriodicSampler.hpp"
#include "Repository.hpp"
#include <assert.h>

#include"KeyValueDatabase.hpp"
#include"Document.hpp"

#include<iostream>

// Here's some sample usage of the Subscribers,
// Publishers and the Repository

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , FILE , LINE )
#endif


void testSimplePublisher() {

	Message m(10);

	Repository repo;

	Averager avg1("avg1");
	repo.add(&avg1);

	Averager avg2("avg2");
	repo.add(&avg2);

	SimplePublisher sp;
	sp.subscribe(static_cast<Averager*>(repo.get("avg1")));
	sp.signal({10});
	sp.subscribe((Averager*)repo.get("avg2"));
	sp.signal({0});

	assert(static_cast<Averager*>(repo.get("avg1"))->read() == 5);
	assert(static_cast<Averager*>(repo.get("avg2"))->read() == 0);
	assert(avg1.read() == 0);
}

void testBacklogPublisher() {
	Repository repo;
	Averager avg1("avg1");
	repo.add(&avg1);

	BacklogPublisher bp;
	bp.signal({10});
	bp.signal({0});

	bp.subscribe(static_cast<Averager*>(repo.get("avg1")));
	assert(static_cast<Averager*>(repo.get("avg1"))->read() == 5);
}

void testMovingAverager() {
	Repository repo;
	MovingAverager mavg1("mavg1", 2);
	repo.add(&mavg1);

	SimplePublisher sp;
	sp.subscribe(static_cast<MovingAverager*>(repo.get("mavg1")));
	sp.signal({10});
	sp.signal({0});
	assert(static_cast<MovingAverager*>(repo.get("mavg1"))->read() == 5);

	sp.signal({4});
	assert(static_cast<MovingAverager*>(repo.get("mavg1"))->read() == 2);
}

void testPeriodicSampler() {
	Repository repo;
	PeriodicSampler ps2("ps2", 2);
	repo.add(&ps2);

	SimplePublisher sp;
	sp.subscribe(static_cast<PeriodicSampler*>(repo.get("ps2")));
	sp.signal({10});
	assert(static_cast<PeriodicSampler*>(repo.get("ps2"))->read() == 10);

	sp.signal({0});
	assert(static_cast<PeriodicSampler*>(repo.get("ps2"))->read() == 10);

	sp.signal({4});
	assert(static_cast<PeriodicSampler*>(repo.get("ps2"))->read() == 4);
}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	testSimplePublisher();
	testBacklogPublisher();
	testMovingAverager();
	testPeriodicSampler();

	Document temp("temp", "/tmp", "doc");

	temp.write_line("This is an example doc");
	temp.write_line("This is another example line");
	temp.write_line("This is a third example line");
	temp.write_line("This is a forth example line");

	std::cout << temp.read_line() << std::endl; //This is an example doc
	std::cout << temp.read_line() << std::endl; //This is another example line
	std::cout << temp.read_line(3) << std::endl; //This is a third example line
	std::cout << temp.read_line() << std::endl; //This is a forth example line

	std::cout << temp.read_line(1) << std::endl; //This is an example doc
	std::cout << temp.read_line() << std::endl; //This is another example line
	try {
		std::cout << temp.read_line(5) << std::endl;
	}
	catch (const std::out_of_range& oor) {
		std::cerr << oor.what() << std::endl;
	}
	std::cout << temp.to_string() << std::endl;
	std::cout << temp.debug_print() << std::endl;
	std::string test = "temp1\n/tmp1\ndoc1\nThis is an example doc2\nThis is another example line3";
	temp.from_string(test);
	std::cout << temp.to_string() << std::endl;
	Document* pointD= dynamic_cast<Document*>(temp.clone());
	std::cout << &temp << std::endl << pointD << std::endl;
	std::cout << ( temp != static_cast<Comparable*>(pointD) ) << std::endl;
	delete pointD;

	KeyValueDatabase kvdb("first", "/test", "db");
	std::pair<std::string, int> temp1("first", 10);
	std::pair<std::string, int> temp2("second", 20);
	kvdb.add_entry(temp1);
	kvdb.add_entry(temp2);
	
	try {
		kvdb.add_entry(temp1);
	}
	catch (const std::invalid_argument& ia) {
		std::cerr << ia.what() << std::endl;
	}

	std::cout << kvdb.get_value("first") << std::endl;
	std::cout << kvdb.get_value("second") << std::endl;
	std::cout << kvdb.to_string() << std::endl;
	test = "first2\n/test2\ndb1\nfirst2:30\nsecond2:23";
	kvdb.from_string(test);
	std::cout << kvdb.to_string() << std::endl;

	KeyValueDatabase* pointK = dynamic_cast<KeyValueDatabase*>(kvdb.clone());
	std::cout << &kvdb << std::endl << pointK << std::endl;
	std::cout << (kvdb == static_cast<Comparable*>(pointK)) << std::endl;
	delete pointK;

}
