#ifndef LAB_2_INCLUDE_HASHTABLE_H
#define LAB_2_INCLUDE_HASHTABLE_H

#include <iostream>
#include <vector>
#include <functional>

#include "../include/Random.h"

template <typename Key, typename Value, typename Hash = std::hash<Key>, typename Comp = std::equal_to<Key>>
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
	Hash hash_func;
	Comp comparator;

	void rehash() {
		std::vector<Pair> new_data(_data.size() * 2);
		std::swap(new_data, _data);
		_size = 0;
		for (Pair& pair : new_data)
			if (!pair.node_empty)
				insert(pair.key, pair.value);
	}

	Pair* find(const Key& key) {
		size_t start_index = hash_func(key) % _data.size();
		if (comparator(_data[start_index].key, key) && (!_data[start_index].node_empty)) {
			return &_data[start_index];
		}
		size_t index = (start_index + 1) % _data.size();
		while (index != start_index) {
			if (comparator(_data[start_index].key, key) && (!_data[index].node_empty)) {
				return &_data[index];
			}
			index = (index + 1) % _data.size();
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
		double load_factor = (double)(_size + 1) / _data.size();
		if (load_factor > 0.8) { 
			rehash(); 
		}
		if (find(key)) {
			return false;
		}
		size_t index = hash_func(key) % _data.size();
		while (!_data[index].node_empty) {
			index = (index + 1) % _data.size();
		}
		_data[index] = Pair(key, value);
		_size++;
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

	bool contains(const Key& key) {
		return find(key);
	}

	Value operator[](const Key& key) const {
		Pair* find_pair = find(key);
		if (find_pair)
			return find_pair->value;
		throw std::out_of_range("Key not found");
	}

	Value& operator[](const Key& key) {
		Pair* find_pair = find(key);
		if (find_pair)
			return find_pair->value;
		throw std::out_of_range("Key not found");
	}

	bool erase(const Key& key) {
		Pair* find_pair = find(key);
		if (!find_pair)
			return false;
		find_pair->node_empty = true;
		return true;
	}

	void print() const {
		for (const Pair& pair : _data) {
			if (!pair.node_empty)
				std::cout << "{" << pair.key << " : " << pair.value << "} ";
		}
		std::cout << std::endl;
	}
};

#endif