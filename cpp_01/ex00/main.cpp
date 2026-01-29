#include "Zombie.hpp"

int main()
{
    Zombie* z = newZombie("Bob");
    z->announce();
    delete z;

    randomChump("Alice");
    return 0;
}
/*main()
│
│  Appelle newZombie("Bob")
▼
newZombie(std::string name)
name = "Bob"
│
│  Crée un zombie sur le HEAP :
│      new Zombie("Bob")
▼
Zombie::Zombie(std::string name)
name = "Bob"
│
│  Met le nom dans l’attribut :
│      n_Zombie = "Bob"
▼
Retourne l'adresse du zombie (exemple : 0xABC123)
│
▼
main()
Zombie* z = (adresse 0xABC123)
│
│  z->announce();
▼
Zombie::announce()
lit n_Zombie = "Bob"
│
▼
Affiche :
"Bob: BraiiiiiiinnnzzzZ..."
│
│  delete z;
▼
Zombie::~Zombie()
Affiche :
"Bob destroyed"
*/


/*main()
│
│  Appelle randomChump("Alice")
▼
randomChump(std::string name)
name = "Alice"
│
│  Crée un zombie sur la STACK :
│      Zombie z("Alice")
▼
Zombie::Zombie(std::string name)
name = "Alice"
│
│  n_Zombie = "Alice"
▼
z.announce()
▼
Affiche :
"Alice: BraiiiiiiinnnzzzZ..."
│
Fin de randomChump() → z sort du scope
▼
Zombie::~Zombie()
Affiche :
"Alice destroyed"
*/