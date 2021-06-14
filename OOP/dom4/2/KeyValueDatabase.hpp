#pragma once

#include "Object.hpp"
#include<utility>


class KeyValueDatabase : public Object{
public:
    KeyValueDatabase(const std::string& name = "", const std::string& location = "", const std::string& extension = "");

    void add_entry(const std::pair<std::string, int>& entry);
    int get_value(const std::string& key) const;

    bool operator==(const Comparable*) const override;
    bool operator!=(const Comparable*) const override;

    std::string debug_print() const override;

    std::string to_string() const override;
    void from_string(const std::string&) override;

    friend bool is_there(const KeyValueDatabase& db, const std::string& key);

    Object* clone() const override;

private:

    std::vector<std::pair<std::string, int>> db;

};
