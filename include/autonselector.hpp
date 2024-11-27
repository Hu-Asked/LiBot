#pragma once

#include "main.h"
#include "liblvgl/lvgl.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

namespace HuGUI { 
    class AutonSelector{
        public:
            void initialize_auton_selector();       
            void add_auton(std::function<void()> auton, 
                            std::string auton_name, bool isRedAlliance);
            void run_selected_auton();
        private:
            std::vector<std::pair<std::pair<std::string, bool>, 
                                std::function<void()>>> auton_list;
    };

    void update_pos(double x, double y, double theta);
    
    lv_obj_t* create_button(lv_obj_t* parent, lv_coord_t x, 
                            lv_coord_t y, lv_coord_t width, 
                            lv_coord_t height, void* data, const char* text);   
    std::vector<lv_style_t*> create_button_style(lv_color_t pressed, 
                                    lv_color_t released,
                                    lv_color_t tglPressed,
                                    lv_color_t tglReleased, 
                                    lv_color_t outline,
                                    lv_color_t textColor);

    void set_button_style(lv_obj_t* btn, std::vector<lv_style_t*> style);
    void change_auton_event(lv_event_t* e); 
    void change_selected_auton(int index); 
    int selected_auton;
    std::unordered_map<lv_obj_t*, int> auton_map;   
}