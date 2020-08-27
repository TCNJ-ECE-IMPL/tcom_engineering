#include <stdio.h>

#include "project.h"
#include "lvgl.h"
#include "home_screen.h"
#include "breath_activity.h"
#include "time_date_activity.h"

//#define DO_IMAGES
#ifdef DO_IMAGES
#include "blow.c"
#include "message.c"
#include "ribbons.c"
#include "team.c"
#endif

const uint8_t tcnj_blue[] = { 41, 63, 111 };
const uint8_t tcnj_gold[] = { 166, 122, 0 };


void home_screen()
{
    //const int icn_sz    = 140;
    
    const int ban_wid = 280;
    const int ban_hgt =  25;
    
    const int h_ban_1 =  20;
    const int h_lab_1 =  10;
    const int h_lab_2 = 170;

    const int v_ban_1 =  10;
    const int v_ban_2 =  35;
    const int v_lab_1 =  70;
    const int v_lab_2 = 280;
    
#ifdef DO_IMAGES
    const int v_img_1 = 120;
    const int v_img_2 = 330;
#endif

    const char co_btn_txt[]  = "Measure\nBreath";
    const char gam_btn_txt[] = "Collect\nRibbons";
    const char msg_btn_txt[] = "Messages\nFor You";
    const char ci_btn_txt[]  = "Check In";
    
    const int  btn_wid       = 140;
    const int  btn_hgt       = 50;
    
    static lv_obj_t *my_label;
    static lv_style_t *lbl_style;
    
    static lv_obj_t *btn1;
    static lv_obj_t *btn2;
    static lv_obj_t *btn3;
    static lv_obj_t *btn4;
    static lv_obj_t *btn_dat;
    static lv_obj_t *btn_tim;
    
    static lv_style_t btn_style1;
    static lv_style_t btn_style2;
    static lv_style_t btn_style3;
    static lv_style_t btn_style4;
    static lv_style_t btn_style_tim_dat;
    
    static lv_obj_t *label1;
    static lv_obj_t *label2;
    static lv_obj_t *label3;
    static lv_obj_t *label4;
    
    static lv_obj_t *label_dat;
    static lv_obj_t *label_tim;
    
    btn1 = lv_btn_create(lv_scr_act(), NULL);                       /*Add a button the current screen*/
    lv_obj_set_pos(btn1, h_lab_1, v_lab_1);                         /*Set its position*/
    lv_obj_set_size(btn1, btn_wid, btn_hgt);                        /*Set its size*/
    lv_obj_set_event_cb(btn1,  breath_activity_action);             /*Assign a callback to the button*/
    label1 = lv_label_create(btn1, NULL);                           /*Add a label to the button*/
    my_label = label1;                                              /*Gets the value of label1*/
    lv_label_set_text(my_label, co_btn_txt);                        /*Set the label's text string*/
    lv_label_set_align(my_label, LV_LABEL_ALIGN_CENTER );           /*Set the label's alignment*/

    lbl_style = lv_label_get_style(my_label, LV_LABEL_STYLE_MAIN);  /*Get a pointer to label1's style.  Since the label's style was NULL, it
                                                                      actually returns the parent's style (i.e. the active screen!)*/
    lbl_style->text.color.full = 0x000000;                          /*Set label1's text color to black*/
    
    btn2 = lv_btn_create(lv_scr_act(), NULL);                       /*Add a button the current screen*/
    lv_obj_set_pos(btn2, h_lab_2, v_lab_1);                         /*Set its position*/
    lv_obj_set_size(btn2, btn_wid, btn_hgt);                        /*Set its size*/
    lv_obj_set_event_cb(btn2,  breath_activity_action);             /*Assign a callback to the button*/
    label2 = lv_label_create(btn2, NULL);                           /*Add a label to the button*/
    my_label = label2;
    lv_label_set_text(my_label, gam_btn_txt);                       /*Set the label's text*/
    lv_label_set_align(my_label, LV_LABEL_ALIGN_CENTER );

    btn3 = lv_btn_create(lv_scr_act(), NULL);                       /*Add a button the current screen*/
    lv_obj_set_pos(btn3, h_lab_1, v_lab_2);                         /*Set its position*/
    lv_obj_set_size(btn3, btn_wid, btn_hgt);                        /*Set its size*/
    lv_obj_set_event_cb(btn3,  breath_activity_action);             /*Assign a callback to the button*/
    label3 = lv_label_create(btn3, NULL);                           /*Add a label to the button*/
    my_label = label3;
    lv_label_set_text(my_label, msg_btn_txt);                       /*Set the label's text*/
    lv_label_set_align(my_label, LV_LABEL_ALIGN_CENTER );

    btn4 = lv_btn_create(lv_scr_act(), NULL);                       /*Add a button the current screen*/
    lv_obj_set_pos(btn4, h_lab_2, v_lab_2);                         /*Set its position*/
    lv_obj_set_size(btn4, btn_wid, btn_hgt);                        /*Set its size*/
    lv_obj_set_event_cb(btn4,  breath_activity_action);             /*Assign a callback to the button*/
    label4 = lv_label_create(btn4, NULL);                           /*Add a label to the button*/
    my_label = label4;
    lv_label_set_text(my_label, ci_btn_txt);                        /*Set the label's text*/
    lv_label_set_align(my_label, LV_LABEL_ALIGN_CENTER );

    lv_style_copy(&btn_style1, lv_obj_get_style(btn1));
    lv_style_copy(&btn_style2, lv_obj_get_style(btn2));
    lv_style_copy(&btn_style3, lv_obj_get_style(btn3));
    lv_style_copy(&btn_style4, lv_obj_get_style(btn4));
    
    btn_style1.body.main_color.full = 0x0040C0;
    btn_style1.body.grad_color.full = btn_style1.body.main_color.full;
    lv_btn_set_style( btn1, LV_BTN_STATE_REL, &btn_style1 );
    
    btn_style2.body.main_color.full = 0xC04000;
    btn_style2.body.grad_color.full = btn_style2.body.main_color.full;
    lv_btn_set_style( btn2, LV_BTN_STATE_REL, &btn_style2 );
    
    btn_style3.body.main_color.full = 0x00C040;
    btn_style3.body.grad_color.full = btn_style3.body.main_color.full;
    lv_btn_set_style( btn3, LV_BTN_STATE_REL, &btn_style3 );
    
    btn_style4.body.main_color.full = 0x40C000;
    btn_style4.body.grad_color.full = btn_style4.body.main_color.full;
    lv_btn_set_style( btn4, LV_BTN_STATE_REL, &btn_style4 );

    btn_dat = lv_btn_create(lv_scr_act(), NULL);                        /*Add a button the current screen*/
    lv_obj_set_pos(btn_dat, h_ban_1, v_ban_1);                          /*Set its position*/
    lv_obj_set_size(btn_dat, ban_wid, ban_hgt);                         /*Set its size*/
    lv_obj_set_event_cb(btn_dat,  date_activity_action);                /*Assign a callback to the button*/
    label_dat = lv_label_create(btn_dat, NULL);
    lv_label_set_text( label_dat, "Wednesday, January 20  2021" );
    lv_obj_align( label_dat, NULL, LV_ALIGN_IN_TOP_MID, 0,0 );
    set_label_dat(label_dat);
    lv_label_set_long_mode(label_dat, LV_LABEL_LONG_EXPAND);
    
    btn_tim = lv_btn_create(lv_scr_act(), NULL);                        /*Add a button the current screen*/
    lv_obj_set_pos(btn_tim, h_ban_1, v_ban_2);                          /*Set its position*/
    lv_obj_set_size(btn_tim, ban_wid, ban_hgt);                         /*Set its size*/
    lv_obj_set_event_cb(btn_tim,  time_activity_action);                /*Assign a callback to the button*/
    label_tim = lv_label_create(btn_tim, NULL);
    lv_label_set_static_text( label_tim, "12:00 AM" );
    lv_obj_align( label_tim, NULL, LV_ALIGN_IN_TOP_MID, 0,0 );
    set_label_tim(label_tim);

    lv_style_copy(&btn_style_tim_dat, lv_obj_get_style(btn_dat));
    btn_style_tim_dat.text.font = &lv_font_roboto_16;
    btn_style_tim_dat.body.main_color.full = 0xFFFFFF;
    btn_style_tim_dat.body.grad_color.full = 0xFFFFFF;
    lv_btn_set_style( btn_dat, LV_BTN_STATE_REL, &btn_style_tim_dat );
    lv_btn_set_style( btn_tim, LV_BTN_STATE_REL, &btn_style_tim_dat );
    
    lv_task_t * task = lv_task_create(update_time_task, 1000, LV_TASK_PRIO_MID, NULL);

#ifdef DO_IMAGES

    static lv_obj_t *img1;
    static lv_obj_t *img2;
    static lv_obj_t *img3;
    static lv_obj_t *img4;
    
    img1 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img1, &blow);
    lv_obj_align(img1, NULL, LV_ALIGN_IN_TOP_LEFT, h_lab_1, v_img_1);
    
    img2 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img2, &ribbons);
    lv_obj_align(img2, NULL, LV_ALIGN_IN_TOP_LEFT, h_lab_2, v_img_1);
    
    img3 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img3, &message);
    lv_obj_align(img3, NULL, LV_ALIGN_IN_TOP_LEFT, h_lab_1, v_img_2);
    
    img4 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img4, &team);
    lv_obj_align(img4, NULL, LV_ALIGN_IN_TOP_LEFT, h_lab_2, v_img_2);

#endif
    
}