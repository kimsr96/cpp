#ifndef Dog_HPP
# define Dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
    private:
        Brain *dogBrain;
    public:
        Dog();
        ~Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);

        void        makeSound() const;
        std::string getBrainIdeas(int i) const;
        void        setBrainIdeas(std::string name);
};

#endif