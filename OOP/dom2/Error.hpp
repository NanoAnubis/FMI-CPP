#pragma once

#include <string>

class Error {
public:

    Error(const std::string& message = "");
    std::string get_message() const;

    bool operator==(const Error&) const;

private:

    std::string message;
};