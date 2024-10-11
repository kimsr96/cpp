#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
    private:
        Brain *catBrain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);

        void makeSound() const;
        std::string getBrainIdeas(int i) const;
        void        setBrainIdeas(std::string name);
};

#endif