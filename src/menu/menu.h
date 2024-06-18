//
// Created by Taco on 6/13/2024.
//

#ifndef MENU_H
#define MENU_H


#include "imgui.h"


class Menu {
public:
    Menu();

    void ShowMenu();

private:
    void ShowTabContent();

    void DrawButtonCategoryHeader(const char *Categoryname);

    int m_CurrentTab;
};


#endif //MENU_H
