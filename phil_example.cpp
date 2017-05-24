//
// Created by Maria.Baburina on 5/24/2017.
//

#include <experimental/optional>
#include <string>
#include <iostream>
#include <sstream>

using std::experimental::optional;

template<typename T>
struct add_optionality { using type = optional<T>; };

template<typename T>
struct add_optionality<optional<T>> { using type = optional<T>; };

template<typename T>
using add_optionality_t = typename add_optionality<T>::type;


template<typename T, typename L>
auto operator | ( optional<T> const& opt, L const& withFun ) ->  add_optionality_t<decltype(withFun(*opt))> {
    if( opt )
        return withFun( *opt );
    else
        return {};
}

template<typename T, typename L>
optional<T> const& operator >> ( optional<T> const& opt, L const& withFun ) {
    if( opt )
        withFun( *opt );
    return opt;
}
template<typename T, typename L>
optional<T> const& operator || ( optional<T> const& opt, L const& withoutFun ) {
    if( !opt )
        withoutFun();
    return opt;
}

auto processOptional( optional<int> const& opt ) {
    return opt
           | []( auto x ){ return x*2; }
           | []( auto x ){ return (x>10) ? x : optional<int>(); }
           | []( auto x ){ return "(" + std::to_string( x ) + ")"; }
            ;
}

auto stringToInt( std::string const& str ) -> optional<int> {
    int i;
    std::stringstream ss;
    ss << str;
    ss >> i;
    if( ss.fail() )
        return {};
    else
        return i;
}

auto processOptional( optional<std::string> const& opt ) {
    auto optInt = opt
                  | []( auto x ){ return stringToInt( x ); };
    return processOptional( optInt );
}

void useOptional( optional<int> const& opt ) {
    std::string noValueString =
            ( opt
              | []( auto x ){ return "initial value: " + std::to_string( x ) + " - no final value"; }
            ).value_or( "- no value -" );
    processOptional( opt )
            >> []( auto x ){ std::cout << x << std::endl; }
    || [defaultString = std::move(noValueString)]{ std::cout << defaultString << std::endl; };
}
void useOptional( optional<std::string> const& opt ) {
    auto optInt = opt | []( auto x ){ return stringToInt( x ); };
    return useOptional( optInt );
}

void f() {

    using namespace std::string_literals;

    useOptional( 7 );
    useOptional( 4 );
    useOptional( optional<int>() );
    useOptional( "42"s );
    useOptional( "badger"s );
}