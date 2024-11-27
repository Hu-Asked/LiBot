#include "autonselector.hpp"

namespace HuGUI {
    static lv_obj_t* posLabel;
    static std::vector<lv_style_t*> buttonStyle;
    static lv_obj_t* homeScreen;
    static lv_obj_t* tabview;
    static lv_obj_t* startButton;
    static lv_obj_t* backButton;
    static lv_style_t buttonStyle;
    int selected_auton = 0;
    
    lv_obj_t* create_button(lv_obj_t* parent, lv_coord_t x, 
                                            lv_coord_t y, lv_coord_t width, 
                                            lv_coord_t height, void* data, 
                                            const char* text) {
    
        lv_obj_t* btn = lv_btn_create(parent);
        lv_obj_set_size(btn, width, height);
        lv_obj_set_pos(btn, x, y);
        lv_obj_set_user_data(btn, reinterpret_cast<void*>(data));
        
        lv_obj_t * label = lv_label_create(btn);
        lv_label_set_text(label, text);
        lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    
        return btn;
    }

    std::vector<lv_style_t*> create_button_style(lv_color_t pressed, 
                                    lv_color_t released, 
                                    lv_color_t tglPressed,
                                    lv_color_t tglReleased, 
                                    lv_color_t outline,
                                    lv_color_t textColor) {
        
        std::vector<lv_style_t*> btnStyles(4);
        for(int i = 0; i < 4; i++) {
            btnStyles[i] = new lv_style_t;
            lv_style_init(btnStyles[i]);
        }
        
        lv_style_set_bg_color(btnStyles[0], released);
        lv_style_set_text_color(btnStyles[0], textColor);

        lv_style_set_bg_color(btnStyles[1], pressed);
        lv_style_set_text_color(btnStyles[1], textColor);

        lv_style_set_bg_color(btnStyles[2], tglReleased);
        lv_style_set_border_width(btnStyles[2], 2);
        lv_style_set_border_color(btnStyles[2], outline);
        lv_style_set_text_color(btnStyles[2], textColor);

        lv_style_set_bg_color(btnStyles[3], tglPressed);
        lv_style_set_text_color(btnStyles[3], textColor);

        return btnStyles;
    }
    
    void set_button_style(lv_obj_t* btn, std::vector<lv_style_t*> styles) {
        lv_obj_add_style(btn, styles[0], LV_STATE_DEFAULT);
        lv_obj_add_style(btn, styles[1], LV_STATE_PRESSED);
        lv_obj_add_style(btn, styles[2], LV_STATE_CHECKED);
        lv_obj_add_style(btn, styles[3], LV_STATE_CHECKED | LV_STATE_PRESSED);
    }
    
    void update_pos(double x, double y, double theta) {
        std::string pos = std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(theta);
        lv_label_set_text(posLabel, pos.c_str());
    }
    
    void create_global_info() {
        lv_obj_t* bar = lv_obj_create(lv_scr_act());
        
        lv_obj_set_size(bar, 480, 240 / 5);
        lv_obj_align(bar, LV_ALIGN_BOTTOM_MID, 0, 0);

        lv_obj_t* img = lv_img_create(bar);
        lv_img_set_src(img, "path/to/image");
        lv_obj_align(img, LV_ALIGN_LEFT_MID, 10, 0);

        posLabel = lv_label_create(bar);
        lv_label_set_text(posLabel, "0, 0, 0"); 
        lv_obj_align(posLabel, LV_ALIGN_RIGHT_MID, -10, 0);
    }

    void create_home_screen() {

        homeScreen = lv_obj_create(NULL);
        
        lv_obj_t* logo = lv_img_create(lv_scr_act());
        lv_img_set_src(logo, "path/to/image");
        lv_obj_align(logo, LV_ALIGN_TOP_MID, 0, 0);
        
        buttonStyle = create_button_style(LV_COLOR_MAKE(40, 40, 40),
                                            LV_COLOR_MAKE(0, 0, 0),
                                            LV_COLOR_MAKE(0, 230, 70),
                                            LV_COLOR_MAKE(230, 0, 70),
                                            LV_COLOR_MAKE(0, 0, 0),
                                            LV_COLOR_MAKE(255, 255, 255));
    
        set_button_style(startButton, buttonStyle);
        
        startButton = create_button(homeScreen, 0, 50, 100, 50, show_tab_view, "Start");
    }  

    void create_tab_view() {
        tabview = lv_tabview_create(NULL, LV_DIR_TOP, 50);

        lv_obj_t* autonomousRoutines = lv_tabview_add_tab(tabview, "AUTONS");

        lv_obj_t* autonRoutinesLabel = lv_label_create(autonomousRoutines);
        lv_label_set_text(autonRoutinesLabel, "AUTONS");
        lv_obj_align(autonRoutinesLabel, LV_ALIGN_CENTER, 0, 0);

        backButton = create_button(tabview, 0, 50, 100, 50, show_home_screen, "Home");
    }
    
    void show_home_screen(lv_event_t* e) {
        lv_scr_load(homeScreen);
    }

    void show_tab_view(lv_event_t* e) {
        lv_scr_load(tabview);
    }

    void update_pos(double x, double y, double theta) {
        std::string pos = std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(theta);
        lv_label_set_text(posLabel, pos.c_str());
    }

    void AutonSelector::initialize_auton_selector() {
        create_home_screen();
        create_tab_view();
        lv_scr_load(homeScreen);
    }

    void AutonSelector::add_auton(std::function<void()> auton, 
                                    std::string auton_name, bool isRedAlliance) {
        auton_list.push_back(std::make_pair(std::make_pair(auton_name, isRedAlliance), auton));
        lv_obj_t* btn = create_button(tabview, 0, 50, 100, 50, change_auton_event, auton_name.c_str());
        auton_map[btn] = auton_list.size() - 1;
    }
    
    void change_auton_event(lv_event_t* e) {
        lv_obj_t* btn = lv_event_get_target(e);
        change_selected_auton(auton_map[btn]);
    }

    void change_selected_auton(int index) {
        selected_auton = index;
    }
    void AutonSelector::run_selected_auton() {
        auton_list[selected_auton].second();
    }
}