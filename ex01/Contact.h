#include <string>

class Contact {

    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
    public:
        void    setInfo();
        std::string formatDisplay(const std::string& str);
        void    displayBrief(const int index);
        bool isValidInput(const std::string& input);
        std::string getValidInput(const std::string& prompt);
        void    displayall();
};
