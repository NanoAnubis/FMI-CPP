#include"KeyValueDatabase.hpp"

KeyValueDatabase::KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension)
	: Object(name, location, extension)
{}

bool is_there(const KeyValueDatabase& lhs, const std::string& key){
	for (size_t i = 0; i < lhs.db.size(); i++) {
		if (lhs.db[i].first == key) {
			return true;
		}
	}
	return false;
}

void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry)
{	
	if (is_there(*this, entry.first) == true) {
		throw (std::invalid_argument("Invalid argument"));
	}
	db.push_back(entry);
}

int KeyValueDatabase::get_value(const std::string& key) const
{
	if (is_there(*this, key) == false) {
		throw (std::invalid_argument("Invalid argument"));
	}
	for (size_t i = 0; i < db.size(); i++) {
		if (db[i].first == key) {
			return db[i].second;
		}
	}
	return 0;
}


bool KeyValueDatabase::operator==(const Comparable* other) const
{
	if (other == nullptr) return false;
	const KeyValueDatabase* tmp = dynamic_cast<const KeyValueDatabase*>(other);
	if (db.size() != tmp->db.size()) return false;
	for (size_t i = 0; i < db.size(); i++) {
		if (db[i] != tmp->db[i]) return false;
	}
	return true;
}

bool KeyValueDatabase::operator!=(const Comparable* other) const
{
	return !(this->operator==(other));
}


std::string KeyValueDatabase::debug_print() const
{
	std::string tmp;
	for (size_t i = 0; i < db.size(); i++) {
		tmp += '{' + db[i].first + ':';
		tmp += std::to_string(db[i].second) + '}' +'\n';
	}
	return tmp;
}


std::string KeyValueDatabase::to_string() const
{
	std::string tmp;
	tmp += name + '\n';
	tmp += location + '\n';
	tmp += extension + '\n';
	for (size_t i = 0; i < db.size(); i++) {
		tmp += db[i].first + ':';
		tmp += std::to_string(db[i].second) + '\n';
	}
	return tmp;
}

void KeyValueDatabase::from_string(const std::string& input)
{
	db.clear();
	db.shrink_to_fit();
	std::string tmp;
	std::stringstream ss;
	ss << input;

	std::getline(ss, tmp, '\n');
	name = tmp;
	std::getline(ss, tmp, '\n');
	location = tmp;
	std::getline(ss, tmp, '\n');
	extension = tmp;
	while (std::getline(ss, tmp, '\n')) {
		std::string tmp_nested;
		std::stringstream ss_nested;
		ss_nested << tmp;
		std::string key;
		int value;
		std::getline(ss_nested, tmp_nested, ':');
		key = tmp_nested;
		std::getline(ss_nested, tmp_nested, '\n');
		value = std::stoi(tmp_nested);
		std::pair<std::string, int> out(key, value);
		db.push_back(out);
	}
}



Object* KeyValueDatabase::clone() const {
	return new KeyValueDatabase(*this);
}