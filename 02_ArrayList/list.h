#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

template <class T>
class ArrayList
{
private:
	int counter;
	T* items;

public:
	ArrayList() : counter{ 0 }, items{ nullptr } {}	
	T get(int index) const;
	void insert(int index, const T& element);
	int search(const T& element) const;
	void remove(int index);
	int count() const;
	~ArrayList();
};

template <class T>
int ArrayList<T>::count() const {
	return counter;
}

template <class T>
T ArrayList<T>::get(int index) const
{
	if (index < 0 || index > counter) {
		throw std::out_of_range("GET - INDEX OUT OF RANGE");
	}

	return items[index];
}

template <class T>
void ArrayList<T>::insert(int index, const T& element)
{
	if (index < 0 || index > counter) {
		throw std::out_of_range("INSERT - INDEX OUT OF RANGE");
	}

	T * items_copy = items;

	counter++;

	items = new T[counter];

	for (int i = 0, j = 0; i < counter; ++i)
	{
		if (index == i)
		{
			items[i] = element;
		}
		else
		{
			items[i] = items_copy[j];
			++j;
		}
	}

	delete[] items_copy;
}

template <class T>
int ArrayList<T>::search(const T& element) const
{
	for (int i = 0; i < counter; ++i)
	{
		if (items[i] == element)
		{
			return i;
		}
	}

	return -1;
}

template <class T>
void ArrayList<T>::remove(int index)
{
	if (index < 0 || index > counter) {
		throw std::out_of_range("REMOVE - INDEX OUT OF RANGE");
	}
	
	T* items_copy = items;

	counter--;
	
	items = new T[counter];

	for (int i = 0, j = 0; i < counter; ++i, ++j)
	{
		if (index == j)
		{
			++j;
		}

		items[i] = items_copy[j];
	}

	delete[] items_copy;
}


template <class T>
ArrayList<T>::~ArrayList() {
	delete items;
}

#endif // !ARRAY_LIST_H

