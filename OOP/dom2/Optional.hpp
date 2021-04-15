#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

template <typename T>
class Optional {
public:

    Optional();
    Optional(const T& value);

    bool is_none() const;
    T get_value() const;

private:
    T element;
};

template <typename T>
Optional<T>::Optional() : element(T())
{
}

template <typename T>
Optional<T>::Optional(const T& value)
{
    element = value;
}

template <typename T>
bool Optional<T>::is_none() const
{
    return element == T() ;
}

template <typename T>
T Optional<T>::get_value() const
{
    return element;
}







