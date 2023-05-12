#pragma once

#include <string>

class Warlock {
  public:
    Warlock( void );
    Warlock( std::string name, std::string title );
    Warlock( Warlock const& src );
    ~Warlock( void );
    Warlock& operator=( Warlock const& src);

    std::string const& getName( void ) const;
    std::string const& getTitle( void ) const;
    void setTitle( std::string const& title );

    void introduce( void ) const;

  private:
    std::string _name;
    std::string _title;
};
