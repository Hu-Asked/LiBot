#include "autonselector.hpp"

namespace GHUI {
    lv_obj_t* posLabel;
    lv_obj_t* selectedAutonLabel;

    lv_obj_t* homeScreen;
    lv_obj_t* tabview;

    lv_obj_t* startButton;
    lv_obj_t* noAutonButton;

    lv_obj_t* redAUTONS;
    lv_obj_t* blueAUTONS;
    lv_obj_t* otherAUTONS;
    lv_obj_t* config;
    lv_obj_t* console;

    lv_obj_t* bar;

    std::vector<lv_obj_t*> consoleText(10);

    int selected_auton = 0;
    int numRed = 0;
    int numBlue = 0;
    int numOther = 0;
    std::vector<std::pair<std::pair<std::string, AutonType>, std::function<void()>>> auton_list;
    std::unordered_map<lv_obj_t*, int> auton_map;

    static lv_style_t optionsButtonStyle;
    static lv_style_t redAutonButtonStyle;
    static lv_style_t blueAutonButtonStyle;

    void initialize_auton_selector(std::vector<Auton> autons) {
        load_selected_auton();

        lv_style_init(&optionsButtonStyle);
        lv_style_set_bg_color(&optionsButtonStyle, lv_color_make(255, 255, 255));
        lv_style_set_text_color(&optionsButtonStyle, lv_color_make(0, 0, 0));

        lv_style_init(&redAutonButtonStyle);
        lv_style_set_bg_color(&redAutonButtonStyle, lv_color_make(178, 22, 83));
        
        lv_style_init(&blueAutonButtonStyle);
        lv_style_set_bg_color(&blueAutonButtonStyle, lv_color_make(104, 175, 240));
        
        create_tab_view();

        add_auton([]() {}, "NONE", OTHER);

        for(auto auton : autons) {
            add_auton(auton.auton, auton.auton_name, auton.alliance);
        }
        create_home_screen();
        lv_scr_load(homeScreen);
    }

    void set_button_pos(lv_obj_t* btn, int compare) {
        switch (compare) {
            case 0:
                lv_obj_set_pos(btn, 0, 0);
                break;
            case 1:
                lv_obj_set_pos(btn, 100, 0);
                break;
            case 2:
                lv_obj_set_pos(btn, 200, 0);
                break;
            case 3:
                lv_obj_set_pos(btn, 300, 0);
                break;
            case 4:
                lv_obj_set_pos(btn, 0, 60);
                break;
            case 5:
                lv_obj_set_pos(btn, 100, 60);
                break;
            case 6:
                lv_obj_set_pos(btn, 200, 60);
                break;
            case 7:
                lv_obj_set_pos(btn, 300, 60);
                break;
        }
    }

    void add_auton(std::function<void()> auton, 
                                    std::string auton_name, AutonType alliance) { //Function that runs the auton, Text displayed on the button, Is the auton for the red or blue alliance
        auton_list.push_back(std::make_pair(std::make_pair(auton_name, alliance), auton));
        lv_obj_t* btn = create_button(tabview, 0, 40, 90, 50, 1, auton_name.c_str());
        lv_obj_add_event_cb(btn, change_auton_event, LV_EVENT_CLICKED, NULL);
        auton_map[btn] = auton_list.size() - 1;
        switch (alliance) {
            case RED:
                lv_obj_set_parent(btn, redAUTONS);
                set_button_pos(btn, numRed);
                numRed++;
                lv_obj_add_style(btn, &redAutonButtonStyle, 0);
                break;
            case BLUE:
                lv_obj_set_parent(btn, blueAUTONS);
                set_button_pos(btn, numBlue);
                numBlue++;
                lv_obj_add_style(btn, &blueAutonButtonStyle, 0);
                break;
            case OTHER:
                lv_obj_set_parent(btn, otherAUTONS);
                set_button_pos(btn, numOther);
                numOther++;
                lv_obj_add_style(btn, &optionsButtonStyle, 0);
                break;
        }
    }

    void console_print(std::string text, int line) { //Enter a line from 0 - 9
        if (consoleText[line] != NULL) {
            lv_obj_del(consoleText[line]);
        }
        consoleText[line] = lv_label_create(console);
        lv_label_set_text(consoleText[line], text.c_str());
        lv_obj_align(consoleText[line], LV_ALIGN_TOP_LEFT, 0, (20 * line) - 20);
    }

    void update_pos(double x, double y, double theta) {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(3) << x << ", " << y << ", " << theta;
        std::string pos = ss.str();
        lv_label_set_text(posLabel, pos.c_str());
    }

    void change_auton_event(lv_event_t* e) {
        lv_obj_t* btn = lv_event_get_target(e);
        change_selected_auton(auton_map[btn]);
        std::string display = auton_list[auton_map[btn]].first.first;
        lv_label_set_text(selectedAutonLabel, ("Auton: " + display).c_str());
    }

    void change_selected_auton(int index) {
        selected_auton = index;

        if(!pros::usd::is_installed()) {
            return;
        }

        FILE* file = fopen("/usd/auton.txt", "w");
        if (file) {
            fputs(std::to_string(selected_auton).c_str(), file);
            fclose(file);
        }
    }

    void load_selected_auton() {
        if(!pros::usd::is_installed()) {
            return;
        }
        FILE* file = fopen("/usd/auton.txt", "r");
        if (file) {
            char buffer[10];
            if (fgets(buffer, sizeof(buffer), file)) {
                selected_auton = std::stoi(buffer);
            } else {
                selected_auton = -1; // Default if reading fails
            }
            fclose(file);
        } else {
            selected_auton = -1; // Default if file does not exist
        }
    }
    
    void run_selected_auton() {
        if(selected_auton == -1) {
            return;
        }
        auton_list[selected_auton].second();
    }

    void create_home_screen() {
        homeScreen = lv_obj_create(NULL);

        lv_obj_t* logo = lv_obj_create(homeScreen);
        lv_obj_align(logo, LV_ALIGN_CENTER, 0, -20);
        lv_obj_set_style_bg_color(logo, lv_color_make(0, 0, 0), 0);
        lv_obj_set_size(logo, 470, 200);

        if(pros::usd::is_installed()) {
            static Gif gif("/usd/logo.gif", logo);
        }

        bar = lv_obj_create(homeScreen);
        
        lv_obj_set_size(bar, 480, 40);
        lv_obj_align(bar, LV_ALIGN_BOTTOM_MID, 0, 0);   
    
        startButton = create_button(bar, 0, 0, 70, 25, 1, "");
        lv_obj_set_align(startButton, LV_ALIGN_CENTER);
        lv_obj_set_pos(startButton, 0, 0);
        lv_obj_add_style(startButton, &optionsButtonStyle, 0);

        lv_obj_add_event_cb(startButton, show_tab_view, LV_EVENT_CLICKED, NULL);

        posLabel = lv_label_create(bar);
        lv_label_set_text(posLabel, "0, 0, 0"); 
        lv_obj_align(posLabel, LV_ALIGN_RIGHT_MID, -10, 0);

        selectedAutonLabel = lv_label_create(bar);
        std::string auton_name = "Auton: " + auton_list[selected_auton].first.first;
        lv_label_set_text(selectedAutonLabel, auton_name.c_str());
        lv_obj_align(selectedAutonLabel, LV_ALIGN_LEFT_MID, 10, 0);
        
        lv_obj_set_scrollbar_mode(bar, LV_SCROLLBAR_MODE_OFF);
    }

    void create_tab_view() {
        tabview = lv_tabview_create(NULL, LV_DIR_TOP, 50);

        redAUTONS = lv_tabview_add_tab(tabview, "RED");
        blueAUTONS = lv_tabview_add_tab(tabview, "BLUE");
        otherAUTONS = lv_tabview_add_tab(tabview, "OTHER");
        config = lv_tabview_add_tab(tabview, "CONFIG");
        console = lv_tabview_add_tab(tabview, "CONSOLE");
    }

    void show_home_screen(lv_event_t* e) {
        lv_obj_set_parent(bar, homeScreen);
        lv_obj_remove_event_cb(startButton, show_home_screen);
        lv_obj_add_event_cb(startButton, show_tab_view, LV_EVENT_CLICKED, NULL);

        lv_scr_load(homeScreen);
        return;
    }

    void show_tab_view(lv_event_t* e) {
        lv_obj_set_parent(bar, tabview);
        lv_obj_remove_event_cb(startButton, show_tab_view);
        lv_obj_add_event_cb(startButton, show_home_screen, LV_EVENT_CLICKED, NULL);

        lv_scr_load(tabview);
        return;
    }

    lv_obj_t* create_button(lv_obj_t* parent, lv_coord_t x, 
                                            lv_coord_t y, lv_coord_t width, 
                                            lv_coord_t height, int id, 
                                            const char* text) {
    
        lv_obj_t* btn = lv_btn_create(parent);
        lv_obj_set_size(btn, width, height);
        lv_obj_set_pos(btn, x, y);
        
        lv_obj_t * label = lv_label_create(btn);
        lv_label_set_text(label, text);
        lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    
        return btn;
    }
}