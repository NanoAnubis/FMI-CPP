#include"Document.hpp"

Document::Document(const std::string& name, const std::string& location, const std::string& extension)
	: Object(name, location, extension), line_counter(0)
{}

void Document::write_line(const std::string& line)
{
	lines.emplace_back(line);
}


std::string Document::read_line()
{
	if (line_counter >= lines.size()) {
		throw(std::out_of_range("Out of range"));
	}
	return lines[line_counter++];
}

std::string Document::read_line(const unsigned line)
{
	if (line == 0 || line - 1 >= lines.size()) {
		throw(std::out_of_range("Out of range"));
	}
	std::string tmp = lines.at(line - 1);
	line_counter = line;
	return tmp;
}


bool Document::operator==(const Comparable* other) const
{
	if (other == nullptr) return false;
	const Document* tmp = dynamic_cast<const Document*>(other);
	if (lines.size() != tmp->lines.size()) return false;
	for (size_t i = 0; i < lines.size(); i++) {
		if (lines[i] != tmp->lines[i]) return false;
	}
	return true;
}

bool Document::operator!=(const Comparable* other) const
{
	return !(this->operator==(other));
}


std::string Document::debug_print() const
{
	std::string tmp;
	for (size_t i = 0; i < lines.size(); i++) {
		tmp += "Line " + std::to_string(i + 1) + ':';
		tmp += lines[i] + '\n';
	}
	return tmp;
}


std::string Document::to_string() const
{
	std::string tmp;
	tmp += name + '\n';
	tmp += location + '\n';
	tmp += extension + '\n';
	for (size_t i = 0; i < lines.size(); i++) {
		tmp += lines[i] + '\n';
	}
	return tmp;
}

void Document::from_string(const std::string& input)
{
	lines.clear();
	lines.shrink_to_fit();
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
		lines.emplace_back(tmp);
	}
}


Object* Document::clone() const {
	return new Document(*this);
}