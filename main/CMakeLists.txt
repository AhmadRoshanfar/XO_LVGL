set(UI_COMPONENTS 
        "ui/ui_init.c"
        "ui/ui_components/create_xo.c" 
        "ui/ui_components/create_restart_btn.c"
        "ui/ui_components/create_message_box.c"
        "ui/ui_components/create_topbar.c" 
   )

idf_component_register(SRCS  "main.c" "ui/lvgl_xo_game.c" ${UI_COMPONENTS} 
                       INCLUDE_DIRS "." "ui")
