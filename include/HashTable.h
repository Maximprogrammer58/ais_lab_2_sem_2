#ifndef LAB_2_INCLUDE_HASHTABLE_H
#define LAB_2_INCLUDE_HASHTABLE_H

#include <iostream>
#include <vector>

template <typename Key, typename Value>
class HashTable {
	struct Pair {
		Key key;
		Value value;
		bool node_empty;

		Pair() : node_empty(true) {}
		Pair(const Key& key, const Value& value) : key(key), value(value), node_empty(false) {}
	};

	std::vector<Pair> _data;
	size_t _size;

	size_t hash(const Key& key, size_t i) {
		return (key + i) % _data.size();

	}

	void grow() {
		std::vector<Pair> new_data;
		new_data.resize(_data.size() * 2);
		std::swap(new_data, _data);
		_size = 0;
		for (Pair& pair : new_data)
			if (!pair.node_empty)
				insert(pair.key, pair.value);
	}

	Pair* find(const Key& key) {
		size_t start_index = hash(key, 0);
		if ((_data[start_index].key == key) && (!_data[start_index].node_empty)) {
			return &_data[start_index];
		}
		size_t i = 1;
		size_t index = hash(key, i);
		while (index != start_index) {
			if ((_data[index].key == key) && (!_data[index].node_empty)) {
				return &_data[index];
			}
			++i;
			index = hash(key, i);
		}
		return nullptr;
	}

public:
	HashTable(size_t capacity) {
		_data.resize(capacity);
		_size = 0;
	}

	HashTable(const HashTable& other) : _data(other._data), _size(other._size) {}

	HashTable& operator=(const HashTable& other) {
		if (this == &other)
			return *this;
		_data = other._data;
		_size = other._size;
	}

	~HashTable() {
		_data.clear();
		_size = 0;
	}

	size_t size() const {
		return _size;
	}

	size_t capacity() const {
		return _data.size();
	}

	bool insert(const Key& key, const Value& value) {
		double load_factor = _size / _data.size();
		if (load_factor > 0.8) { grow(); }
		if (find(key)) {
			return false;
		}
		size_t i = 0;
		size_t index = hash(key, i);
		while (!_data[index].node_empty) {
			++i;
			index = hash(key, i);
		}
		_data[index] = Pair(key, value);
		return true;
	}

	bool insert_or_assign(const Key& key, const Value& value) {
		Pair* find_pair = find(key);
		if (find_pair) {
			find_pair->value = value;
			return false;
		}
		insert(key, value);
	}
};

#endif