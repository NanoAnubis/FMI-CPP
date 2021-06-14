#pragma once

#include"Object.hpp"


class Document  : public Object {
public:
    Document(const std::string& name = "", const std::string& location = "", const std::string& extension = "");

    void write_line(const std::string& line);

    std::string read_line();
    std::string read_line(const unsigned line);

    bool operator==(const Comparable*) const override;
    bool operator!=(const Comparable*) const override;

    std::string debug_print() const override;

    std::string to_string() const override;
    void from_string(const std::string&) override;

    Object* clone() const override;

private:
    std::vector<std::string> lines;

    unsigned line_counter;
};
