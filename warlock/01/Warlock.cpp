#include <string>
#include <iostream>

#include "ASpell.hpp"
#include "ATarget.hpp"

#include "Warlock.hpp"

/* Warlock( void ) { */
/*   return; */
/* } */

Warlock::Warlock( std::string name, std::string title ) :
  _name( name ),
  _title( title ) {
    std::cout << _name << ": This looks like another boring day.\n";
    return;
  }

/* Warlock( Warlock const& src ) { */
/*   return; */
/* } */

Warlock::~Warlock( void ) {
  std::map<std::string, ASpell*>::iterator it;

  for ( it = _spells.begin(); it != _spells.end(); ++it ) {
    delete it->second; // TODO why "->" ? un iterateur est un pointeur
  }
  std::cout << _name << ": My job here is done!\n";
  return;
}

/* Warlock& operator=( Warlock const& src) { */
/*   return; */
/* } */


std::string const& Warlock::getName( void ) const {
  return _name;
}

std::string const& Warlock::getTitle( void ) const {
  return _title;
}

void Warlock::setTitle( std::string const& title ) {
  _title = title;
  return;
}


void Warlock::introduce( void ) const {
  std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
  return;
}


void Warlock::learnSpell( ASpell* spell ) {
  _spells[spell->getName()] = spell->clone();
  return;
}

void Warlock::forgetSpell( std::string spellName ) {
  std::map<std::string, ASpell*>::iterator it;

  it = _spells.find( spellName );
  if ( it == _spells.end() ) {
    return;
  }
  delete it->second;
  _spells.erase( it );
  return;
}

void Warlock::launchSpell( std::string spellName, ATarget &target ) {
  std::map<std::string, ASpell*>::iterator it;

  it = _spells.find( spellName );
  if ( it == _spells.end() ) {
    return;
  }
  it->second->launch( target ); // ->launch not .launch
  return;
}
