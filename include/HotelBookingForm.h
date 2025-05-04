#ifndef HOTELBOOKINGFORM_H
#define HOTELBOOKINGFORM_H

#include "BookingForm.h"
class HotelBookingForm : public BookingForm {
public:
    HotelBookingForm(sf::RenderWindow& win, DialogueManager* manager);
    std::string getFormType() const override;
    void render(sf::RenderWindow& window) override;
    void handleInput(sf::Event event) override;
    std::vector<std::string> getArrayChoice();

private:
    void setDefaultValues() override;
    std::vector<std::string> roomTypeSelection = {"Single Room","Double Room","Family Room","Presidential Suite"};
	int selectedRoomType = 0;
    virtual void analyzedVec();
    const int m_numOfFields = 11;
   

};

#endif // HOTELBOOKINGFORM_H
