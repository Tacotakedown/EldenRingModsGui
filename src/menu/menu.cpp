//
// Created by Taco on 6/13/2024.
//

#include "menu.h"

Menu::Menu(): m_CurrentTab(1) {
}


void Menu::ShowMenu() {
    ImGui::SetNextWindowSize(ImVec2(660, 920), ImGuiCond_Always);
    ImGui::Begin("Custom Tab Menu Layout", nullptr,
                 ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize |
                 ImGuiWindowFlags_NoTitleBar);
    ImGui::BeginChild("LeftSide", ImVec2(200, 0), false);


    // ImGui::Text("🍆");


    DrawButtonCategoryHeader("Visuals");
    ImGui::SetCursorPos(ImVec2(20.0, 20.0));
    if (ImGui::Button("Tab 1")) {
        m_CurrentTab = 1;
    }

    DrawButtonCategoryHeader("Aim");
    if (ImGui::Button("Tab 2")) {
        m_CurrentTab = 2;
    }

    DrawButtonCategoryHeader("Other");
    if (ImGui::Button("Tab 3")) {
        m_CurrentTab = 3;
    }

    DrawButtonCategoryHeader("Other");


    DrawButtonCategoryHeader("Athenaware");


    ImGui::EndChild();

    ImGui::SameLine();


    ImGui::BeginChild("RightSide", ImVec2(0, 0), false);


    ShowTabContent();

    ImGui::EndChild();

    ImGui::End();
}


void Menu::ShowTabContent() {
    switch (m_CurrentTab) {
        case 1:
            ImGui::Text("This is the content of Tab 1.");
            if (ImGui::Button("Button 1")) {
                ImGui::Text("Button 1 clicked");
            }
            break;
        case 2:
            ImGui::Text("This is the content of Tab 2.");
            if (ImGui::Button("Button 2")) {
                ImGui::Text("Button 2 clicked");
            }
            break;
        case 3:
            ImGui::Text("This is the content of Tab 3.");
            if (ImGui::Button("Button 3")) {
                ImGui::Text("Button 3 clicked");
            }
            break;
        default:
            ImGui::Text("Please select a tab.");
            break;
    }
}

void Menu::DrawButtonCategoryHeader(const char *Categoryname) {
    ImGui::Text(Categoryname);
}
