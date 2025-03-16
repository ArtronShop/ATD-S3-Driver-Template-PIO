SET(SOURCES screens/ui_Index.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    fonts/ui_font_Kanit40.c)

add_library(ui ${SOURCES})
