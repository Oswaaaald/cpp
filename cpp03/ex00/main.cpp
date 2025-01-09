#include "ClapTrap.hpp"

int main()
{
		ClapTrap a;

		std::cout << "\033[36mName : " << a.getName() << "\033[0m" << std::endl;
		std::cout << "\033[36mLife : " << a.getLife() << "\033[0m" << std::endl;
		std::cout << "\033[36mEnergy : " << a.getEnergy() << "\033[0m" << std::endl;

		// Check everything when is full life and still has energy
		a.attack("Oswald");
		std::cout << "\033[34m(Life after attack : " << a.getLife() << " || Energy after attack : " << a.getEnergy() << ")\033[0m" << std::endl;
		a.takeDamage(9);
		std::cout << "\033[34m(Life after taking damage : " << a.getLife() << " || Energy after taking damage : " << a.getEnergy() << ")\033[0m" << std::endl;
		a.beRepaired(7);
		std::cout << "\033[34m(Life after repaired : " << a.getLife() << " || Energy after repaired : "  << a.getEnergy() << ")\033[0m" << std::endl;

		// Check repair when already full life
		a.beRepaired(7);
		std::cout << "\033[34m(Life after repaired : " << a.getLife() << " || Energy after repaired : "  << a.getEnergy() << ")\033[0m" << std::endl;

		// Check everything when dead (hp equals 0)
		//a.takeDamage(10);
		//std::cout << "\033[34mLife after taking damage : " << a.getLife() << " Energy after taking damage : " << a.getEnergy() << ")\033[0m" << std::endl;
		a.beRepaired(1);
		std::cout << "\033[34m(Life after repaired : " << a.getLife() << " || Energy after repaired : "  << a.getEnergy() << ")\033[0m" << std::endl;
		a.attack("Oswald");
		std::cout << "\033[34m(Life after attack : " << a.getLife() << " || Energy after attack : " << a.getEnergy() << ")\033[0m" << std::endl;
		
		// Check everything when energy reaches 0
		a.takeDamage(9);
		std::cout << "\033[34m(Life after taking damage : " << a.getLife() << " || Energy after taking damage : " << a.getEnergy() << ")\033[0m" << std::endl;
		a.beRepaired(1);
		std::cout << "\033[34m(Life after repaired : " << a.getLife() << " || Energy after repaired : "  << a.getEnergy() << ")\033[0m" << std::endl;
		a.beRepaired(1);
		std::cout << "\033[34m(Life after repaired : " << a.getLife() << " || Energy after repaired : "  << a.getEnergy() << ")\033[0m" << std::endl;
		a.beRepaired(1);
		std::cout << "\033[34m(Life after repaired : " << a.getLife() << " || Energy after repaired : "  << a.getEnergy() << ")\033[0m" << std::endl;
		a.beRepaired(1);
		std::cout << "\033[34m(Life after repaired : " << a.getLife() << " || Energy after repaired : "  << a.getEnergy() << ")\033[0m" << std::endl;
		a.beRepaired(1);
		std::cout << "\033[34m(Life after repaired : " << a.getLife() << " || Energy after repaired : "  << a.getEnergy() << ")\033[0m" << std::endl;
		a.attack("Oswald");
		std::cout << "\033[34m(Life after attack : " << a.getLife() << " || Energy after attack : " << a.getEnergy() << ")\033[0m" << std::endl;
		a.beRepaired(1);
		std::cout << "\033[34m(Life after repaired : " << a.getLife() << " || Energy after repaired : "  << a.getEnergy() << ")\033[0m" << std::endl;

		// Check everything when dead (hp equals 0)
		a.takeDamage(10);
		std::cout << "\033[34mLife after taking damage : " << a.getLife() << " Energy after taking damage : " << a.getEnergy() << ")\033[0m" << std::endl;
		a.takeDamage(1);
		std::cout << "\033[34mLife after taking damage : " << a.getLife() << " Energy after taking damage : " << a.getEnergy() << ")\033[0m" << std::endl;
		a.beRepaired(1);
		std::cout << "\033[34m(Life after repaired : " << a.getLife() << " || Energy after repaired : "  << a.getEnergy() << ")\033[0m" << std::endl;
		a.attack("Stitch");
		std::cout << "\033[34m(Life after attack : " << a.getLife() << " || Energy after attack : " << a.getEnergy() << ")\033[0m" << std::endl;

		// Check copy constructor and assignation operator

		// Check constructor with name
		ClapTrap b("Bart Simpson");
		std::cout << "\033[36mName : " << b.getName() << "\033[0m" << std::endl;
		std::cout << "\033[36mLife : " << b.getLife() << "\033[0m" << std::endl;
		std::cout << "\033[36mEnergy : " << b.getEnergy() << "\033[0m" << std::endl;

		// Check copy constructor (and assignation operator)
		ClapTrap c(b);
		std::cout << "\033[36mName : " << c.getName() << "\033[0m" << std::endl;
		std::cout << "\033[36mLife : " << c.getLife() << "\033[0m" << std::endl;
		std::cout << "\033[36mEnergy : " << c.getEnergy() << "\033[0m" << std::endl;

		// Check assignation operator
		ClapTrap d;
		d = c;
		std::cout << "\033[36mName : " << d.getName() << "\033[0m" << std::endl;
		std::cout << "\033[36mLife : " << d.getLife() << "\033[0m" << std::endl;
		std::cout << "\033[36mEnergy : " << d.getEnergy() << "\033[0m" << std::endl;

		// Check copy constructor (and assignation operator)
		ClapTrap e = c;
		std::cout << "\033[36mName : " << e.getName() << "\033[0m" << std::endl;
		std::cout << "\033[36mLife : " << e.getLife() << "\033[0m" << std::endl;
		std::cout << "\033[36mEnergy : " << e.getEnergy() << "\033[0m" << std::endl;

		// Check does not copy itself
		d = d;
}