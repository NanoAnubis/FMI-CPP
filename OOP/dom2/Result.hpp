#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

#include "Error.hpp"
#include "Optional.hpp"

template<typename T>
class Result {
public:
    Result();
    Result(const T& result);
    Result(const std::string& error_message);

    Optional<T> get_result() const;
    Optional<Error> get_error() const;

    bool operator==(const T&) const;
    bool operator==(const Error&) const;

private:

    T result;
    Error error;

};

template<typename T>
Result<T>::Result() : result(T()), error(Error())
{
}

template<typename T>
Result<T>::Result(const T& result) : error(Error())
{
    this->result = result;
}

template<typename T>
Result<T>::Result(const std::string& error_message) : result(T())
{
    error = Error(error_message);
}

template<typename T>
Optional<T> Result<T>::get_result() const
{
    return Optional<T>(result);
}

template<typename T>
Optional<Error> Result<T>::get_error() const
{
    return Optional<Error>(error);
}

template<typename T>
bool Result<T>::operator==(const T&) const
{
    if (error == Error() && result == T()) return false; // if Result is empty alway false

    return error == Error();
}

template<typename T>
bool Result<T>::operator==(const Error&) const
{
    if (error == Error() && result == T()) return false; // if Result is empty alway false

    return result == T();
}