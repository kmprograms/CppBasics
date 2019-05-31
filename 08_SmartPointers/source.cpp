#include <iostream>
#include <memory>

int main() {
	
	std::shared_ptr<int> sptr1 = std::make_shared<int>(10);
	std::shared_ptr<int> sptr2{ sptr1 };

	int* ptr = new int{ 20 };
	/*
	std::shared_ptr<int> sptr22{ ptr };
	std::shared_ptr<int> sptr33{ ptr };
	*/

	std::cout << "SIZE PTR = " << sizeof(ptr) << std::endl;
	std::cout << "SIZE SPTR = " << sizeof(sptr1) << std::endl;

	std::weak_ptr<int> wptr{ sptr1 };
	// sptr1 = nullptr;
	// sptr2 = nullptr;
	std::cout << "EXPIRED = " << wptr.expired() << std::endl;
	std::cout << "COUNTER = " << wptr.use_count() << std::endl;

	if (std::shared_ptr<int> sptr3 = wptr.lock())
	{
		std::cout << "SPTR3 = " << *sptr3 << std::endl;
	}
	else
	{
		std::cout << "ERROR" << std::endl;
	}

	return 0;
}
