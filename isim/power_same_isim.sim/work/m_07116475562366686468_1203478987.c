/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/mohamed-esam/sscs2026-conv-accel/rtl/conv_accel_same.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {2U, 0U};
static unsigned int ng4[] = {3U, 0U};
static unsigned int ng5[] = {4U, 0U};
static unsigned int ng6[] = {5U, 0U};
static unsigned int ng7[] = {6U, 0U};
static unsigned int ng8[] = {7U, 0U};
static unsigned int ng9[] = {8U, 0U};
static int ng10[] = {1, 0};
static unsigned int ng11[] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U};
static unsigned int ng12[] = {32767U, 0U};
static unsigned int ng13[] = {4161536U, 0U};
static unsigned int ng14[] = {32768U, 0U};



static void Always_76_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    int t13;
    char *t14;
    char *t15;

LAB0:    t1 = (t0 + 14256U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(76, ng0);
    t2 = (t0 + 21520);
    *((int *)t2) = 1;
    t3 = (t0 + 14288);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(76, ng0);

LAB5:    xsi_set_current_line(77, ng0);
    t4 = (t0 + 2864U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(77, ng0);

LAB9:    xsi_set_current_line(78, ng0);
    t11 = (t0 + 3024U);
    t12 = *((char **)t11);

LAB10:    t11 = ((char*)((ng1)));
    t13 = xsi_vlog_unsigned_case_compare(t12, 4, t11, 4);
    if (t13 == 1)
        goto LAB11;

LAB12:    t2 = ((char*)((ng2)));
    t13 = xsi_vlog_unsigned_case_compare(t12, 4, t2, 4);
    if (t13 == 1)
        goto LAB13;

LAB14:    t2 = ((char*)((ng3)));
    t13 = xsi_vlog_unsigned_case_compare(t12, 4, t2, 4);
    if (t13 == 1)
        goto LAB15;

LAB16:    t2 = ((char*)((ng4)));
    t13 = xsi_vlog_unsigned_case_compare(t12, 4, t2, 4);
    if (t13 == 1)
        goto LAB17;

LAB18:    t2 = ((char*)((ng5)));
    t13 = xsi_vlog_unsigned_case_compare(t12, 4, t2, 4);
    if (t13 == 1)
        goto LAB19;

LAB20:    t2 = ((char*)((ng6)));
    t13 = xsi_vlog_unsigned_case_compare(t12, 4, t2, 4);
    if (t13 == 1)
        goto LAB21;

LAB22:    t2 = ((char*)((ng7)));
    t13 = xsi_vlog_unsigned_case_compare(t12, 4, t2, 4);
    if (t13 == 1)
        goto LAB23;

LAB24:    t2 = ((char*)((ng8)));
    t13 = xsi_vlog_unsigned_case_compare(t12, 4, t2, 4);
    if (t13 == 1)
        goto LAB25;

LAB26:    t2 = ((char*)((ng9)));
    t13 = xsi_vlog_unsigned_case_compare(t12, 4, t2, 4);
    if (t13 == 1)
        goto LAB27;

LAB28:
LAB30:
LAB29:
LAB31:    goto LAB8;

LAB11:    xsi_set_current_line(79, ng0);
    t14 = (t0 + 3184U);
    t15 = *((char **)t14);
    t14 = (t0 + 7424);
    xsi_vlogvar_wait_assign_value(t14, t15, 0, 0, 8, 0LL);
    goto LAB31;

LAB13:    xsi_set_current_line(79, ng0);
    t3 = (t0 + 3184U);
    t4 = *((char **)t3);
    t3 = (t0 + 7584);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    goto LAB31;

LAB15:    xsi_set_current_line(79, ng0);
    t3 = (t0 + 3184U);
    t4 = *((char **)t3);
    t3 = (t0 + 7744);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    goto LAB31;

LAB17:    xsi_set_current_line(80, ng0);
    t3 = (t0 + 3184U);
    t4 = *((char **)t3);
    t3 = (t0 + 7904);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    goto LAB31;

LAB19:    xsi_set_current_line(80, ng0);
    t3 = (t0 + 3184U);
    t4 = *((char **)t3);
    t3 = (t0 + 8064);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    goto LAB31;

LAB21:    xsi_set_current_line(80, ng0);
    t3 = (t0 + 3184U);
    t4 = *((char **)t3);
    t3 = (t0 + 8224);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    goto LAB31;

LAB23:    xsi_set_current_line(81, ng0);
    t3 = (t0 + 3184U);
    t4 = *((char **)t3);
    t3 = (t0 + 8384);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    goto LAB31;

LAB25:    xsi_set_current_line(81, ng0);
    t3 = (t0 + 3184U);
    t4 = *((char **)t3);
    t3 = (t0 + 8544);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    goto LAB31;

LAB27:    xsi_set_current_line(81, ng0);
    t3 = (t0 + 3184U);
    t4 = *((char **)t3);
    t3 = (t0 + 8704);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    goto LAB31;

}

static void NetDecl_91_1(char *t0)
{
    char t3[8];
    char t11[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;

LAB0:    t1 = (t0 + 14504U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(91, ng0);
    t2 = (t0 + 8864);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 8864);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 1560);
    t10 = *((char **)t9);
    t9 = ((char*)((ng10)));
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t10, 32, t9, 32);
    t12 = (t0 + 880);
    t13 = *((char **)t12);
    xsi_vlog_get_indexed_partselect(t3, 8, t5, ((int*)(t8)), 2, t11, 32, 1, t13, 32, 1, 0);
    t12 = (t0 + 22032);
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memset(t17, 0, 8);
    t18 = 255U;
    t19 = t18;
    t20 = (t3 + 4);
    t21 = *((unsigned int *)t3);
    t18 = (t18 & t21);
    t22 = *((unsigned int *)t20);
    t19 = (t19 & t22);
    t23 = (t17 + 4);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t24 | t18);
    t25 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t25 | t19);
    xsi_driver_vfirst_trans(t12, 0, 7U);
    t26 = (t0 + 21536);
    *((int *)t26) = 1;

LAB1:    return;
}

static void NetDecl_92_2(char *t0)
{
    char t3[8];
    char t11[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;

LAB0:    t1 = (t0 + 14752U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(92, ng0);
    t2 = (t0 + 9024);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 9024);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 1560);
    t10 = *((char **)t9);
    t9 = ((char*)((ng10)));
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t10, 32, t9, 32);
    t12 = (t0 + 880);
    t13 = *((char **)t12);
    xsi_vlog_get_indexed_partselect(t3, 8, t5, ((int*)(t8)), 2, t11, 32, 1, t13, 32, 1, 0);
    t12 = (t0 + 22096);
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memset(t17, 0, 8);
    t18 = 255U;
    t19 = t18;
    t20 = (t3 + 4);
    t21 = *((unsigned int *)t3);
    t18 = (t18 & t21);
    t22 = *((unsigned int *)t20);
    t19 = (t19 & t22);
    t23 = (t17 + 4);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t24 | t18);
    t25 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t25 | t19);
    xsi_driver_vfirst_trans(t12, 0, 7U);
    t26 = (t0 + 21552);
    *((int *)t26) = 1;

LAB1:    return;
}

static void Always_94_3(char *t0)
{
    char t6[8];
    char t20[8];
    char t27[8];
    char t63[64];
    char t64[64];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
    char *t62;

LAB0:    t1 = (t0 + 15000U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(94, ng0);
    t2 = (t0 + 21568);
    *((int *)t2) = 1;
    t3 = (t0 + 15032);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(94, ng0);

LAB5:    xsi_set_current_line(95, ng0);
    t4 = (t0 + 2704U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t5 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t4) != 0)
        goto LAB8;

LAB9:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = (!(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB10;

LAB11:    memcpy(t27, t6, 8);

LAB12:    t55 = (t27 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (~(t56));
    t58 = *((unsigned int *)t27);
    t59 = (t58 & t57);
    t60 = (t59 != 0);
    if (t60 > 0)
        goto LAB20;

LAB21:    xsi_set_current_line(98, ng0);
    t2 = (t0 + 3664U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB24;

LAB25:
LAB26:
LAB22:    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB8:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB9;

LAB10:    t18 = (t0 + 3504U);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t19 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t18) != 0)
        goto LAB15;

LAB16:    t28 = *((unsigned int *)t6);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    *((unsigned int *)t27) = t30;
    t31 = (t6 + 4);
    t32 = (t20 + 4);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t31);
    t35 = *((unsigned int *)t32);
    t36 = (t34 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t20) = 1;
    goto LAB16;

LAB15:    t26 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB16;

LAB17:    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t27) = (t39 | t40);
    t41 = (t6 + 4);
    t42 = (t20 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (~(t43));
    t45 = *((unsigned int *)t6);
    t46 = (t45 & t44);
    t47 = *((unsigned int *)t42);
    t48 = (~(t47));
    t49 = *((unsigned int *)t20);
    t50 = (t49 & t48);
    t51 = (~(t46));
    t52 = (~(t50));
    t53 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t53 & t51);
    t54 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t54 & t52);
    goto LAB19;

LAB20:    xsi_set_current_line(95, ng0);

LAB23:    xsi_set_current_line(96, ng0);
    t61 = ((char*)((ng11)));
    t62 = (t0 + 8864);
    xsi_vlogvar_wait_assign_value(t62, t61, 0, 0, 256, 0LL);
    xsi_set_current_line(97, ng0);
    t2 = ((char*)((ng11)));
    t3 = (t0 + 9024);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 256, 0LL);
    goto LAB22;

LAB24:    xsi_set_current_line(98, ng0);

LAB27:    xsi_set_current_line(99, ng0);
    t4 = (t0 + 3824U);
    t5 = *((char **)t4);
    t4 = (t0 + 8864);
    t12 = (t4 + 56U);
    t13 = *((char **)t12);
    xsi_vlog_get_part_select_value(t64, 248, t13, 247, 0);
    xsi_vlogtype_concat(t63, 256, 256, 2U, t64, 248, t5, 8);
    t18 = (t0 + 8864);
    xsi_vlogvar_wait_assign_value(t18, t63, 0, 0, 256, 0LL);
    xsi_set_current_line(100, ng0);
    t2 = (t0 + 3984U);
    t3 = *((char **)t2);
    t2 = (t0 + 9024);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t64, 248, t5, 247, 0);
    xsi_vlogtype_concat(t63, 256, 256, 2U, t64, 248, t3, 8);
    t12 = (t0 + 9024);
    xsi_vlogvar_wait_assign_value(t12, t63, 0, 0, 256, 0LL);
    goto LAB26;

}

static void Always_111_4(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;

LAB0:    t1 = (t0 + 15248U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(111, ng0);
    t2 = (t0 + 21584);
    *((int *)t2) = 1;
    t3 = (t0 + 15280);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(111, ng0);

LAB5:    xsi_set_current_line(112, ng0);
    t4 = (t0 + 3664U);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t6 = *((unsigned int *)t4);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 != 0);
    if (t10 > 0)
        goto LAB6;

LAB7:
LAB8:    goto LAB2;

LAB6:    xsi_set_current_line(112, ng0);

LAB9:    xsi_set_current_line(113, ng0);
    t11 = (t0 + 9344);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t0 + 9184);
    xsi_vlogvar_wait_assign_value(t14, t13, 0, 0, 8, 0LL);
    xsi_set_current_line(113, ng0);
    t2 = (t0 + 9504);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 9344);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(113, ng0);
    t2 = (t0 + 4144U);
    t3 = *((char **)t2);
    t2 = (t0 + 9504);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 8, 0LL);
    xsi_set_current_line(114, ng0);
    t2 = (t0 + 9824);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 9664);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(114, ng0);
    t2 = (t0 + 9984);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 9824);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(114, ng0);
    t2 = (t0 + 3984U);
    t3 = *((char **)t2);
    t2 = (t0 + 9984);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 8, 0LL);
    xsi_set_current_line(115, ng0);
    t2 = (t0 + 10304);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 10144);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(115, ng0);
    t2 = (t0 + 10464);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 10304);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(115, ng0);
    t2 = (t0 + 3824U);
    t3 = *((char **)t2);
    t2 = (t0 + 10464);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 8, 0LL);
    goto LAB8;

}

static void Always_125_5(char *t0)
{
    char t6[8];
    char t20[8];
    char t27[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
    char *t62;

LAB0:    t1 = (t0 + 15496U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(125, ng0);
    t2 = (t0 + 21600);
    *((int *)t2) = 1;
    t3 = (t0 + 15528);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(125, ng0);

LAB5:    xsi_set_current_line(126, ng0);
    t4 = (t0 + 2704U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t5 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t4) != 0)
        goto LAB8;

LAB9:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = (!(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB10;

LAB11:    memcpy(t27, t6, 8);

LAB12:    t55 = (t27 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (~(t56));
    t58 = *((unsigned int *)t27);
    t59 = (t58 & t57);
    t60 = (t59 != 0);
    if (t60 > 0)
        goto LAB20;

LAB21:    xsi_set_current_line(129, ng0);
    t2 = (t0 + 3664U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB24;

LAB25:
LAB26:
LAB22:    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB8:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB9;

LAB10:    t18 = (t0 + 3504U);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t19 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t18) != 0)
        goto LAB15;

LAB16:    t28 = *((unsigned int *)t6);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    *((unsigned int *)t27) = t30;
    t31 = (t6 + 4);
    t32 = (t20 + 4);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t31);
    t35 = *((unsigned int *)t32);
    t36 = (t34 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t20) = 1;
    goto LAB16;

LAB15:    t26 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB16;

LAB17:    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t27) = (t39 | t40);
    t41 = (t6 + 4);
    t42 = (t20 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (~(t43));
    t45 = *((unsigned int *)t6);
    t46 = (t45 & t44);
    t47 = *((unsigned int *)t42);
    t48 = (~(t47));
    t49 = *((unsigned int *)t20);
    t50 = (t49 & t48);
    t51 = (~(t46));
    t52 = (~(t50));
    t53 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t53 & t51);
    t54 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t54 & t52);
    goto LAB19;

LAB20:    xsi_set_current_line(126, ng0);

LAB23:    xsi_set_current_line(127, ng0);
    t61 = ((char*)((ng1)));
    t62 = (t0 + 10624);
    xsi_vlogvar_wait_assign_value(t62, t61, 0, 0, 16, 0LL);
    xsi_set_current_line(128, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 10784);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 16, 0LL);
    goto LAB22;

LAB24:    xsi_set_current_line(129, ng0);

LAB27:    xsi_set_current_line(130, ng0);
    t4 = (t0 + 10624);
    t5 = (t4 + 56U);
    t12 = *((char **)t5);
    t13 = (t0 + 472);
    t18 = *((char **)t13);
    t13 = ((char*)((ng10)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_minus(t6, 32, t18, 32, t13, 32);
    memset(t20, 0, 8);
    t19 = (t12 + 4);
    t26 = (t6 + 4);
    t14 = *((unsigned int *)t12);
    t15 = *((unsigned int *)t6);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t19);
    t21 = *((unsigned int *)t26);
    t22 = (t17 ^ t21);
    t23 = (t16 | t22);
    t24 = *((unsigned int *)t19);
    t25 = *((unsigned int *)t26);
    t28 = (t24 | t25);
    t29 = (~(t28));
    t30 = (t23 & t29);
    if (t30 != 0)
        goto LAB31;

LAB28:    if (t28 != 0)
        goto LAB30;

LAB29:    *((unsigned int *)t20) = 1;

LAB31:    t32 = (t20 + 4);
    t34 = *((unsigned int *)t32);
    t35 = (~(t34));
    t36 = *((unsigned int *)t20);
    t37 = (t36 & t35);
    t38 = (t37 != 0);
    if (t38 > 0)
        goto LAB32;

LAB33:    xsi_set_current_line(133, ng0);

LAB36:    xsi_set_current_line(134, ng0);
    t2 = (t0 + 10624);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 16, t4, 16, t5, 16);
    t12 = (t0 + 10624);
    xsi_vlogvar_wait_assign_value(t12, t6, 0, 0, 16, 0LL);

LAB34:    goto LAB26;

LAB30:    t31 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB31;

LAB32:    xsi_set_current_line(130, ng0);

LAB35:    xsi_set_current_line(131, ng0);
    t33 = ((char*)((ng1)));
    t41 = (t0 + 10624);
    xsi_vlogvar_wait_assign_value(t41, t33, 0, 0, 16, 0LL);
    xsi_set_current_line(132, ng0);
    t2 = (t0 + 10784);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 16, t4, 16, t5, 16);
    t12 = (t0 + 10784);
    xsi_vlogvar_wait_assign_value(t12, t6, 0, 0, 16, 0LL);
    goto LAB34;

}

static void NetDecl_140_6(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    t1 = (t0 + 15744U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(140, ng0);
    t2 = (t0 + 3664U);
    t3 = *((char **)t2);
    t2 = (t0 + 22160);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 1U;
    t9 = t8;
    t10 = (t3 + 4);
    t11 = *((unsigned int *)t3);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t2, 0, 0U);
    t16 = (t0 + 21616);
    *((int *)t16) = 1;

LAB1:    return;
}

static void Always_158_7(char *t0)
{
    char t6[8];
    char t20[8];
    char t27[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
    char *t62;

LAB0:    t1 = (t0 + 15992U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(158, ng0);
    t2 = (t0 + 21632);
    *((int *)t2) = 1;
    t3 = (t0 + 16024);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(158, ng0);

LAB5:    xsi_set_current_line(159, ng0);
    t4 = (t0 + 2704U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t5 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t4) != 0)
        goto LAB8;

LAB9:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = (!(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB10;

LAB11:    memcpy(t27, t6, 8);

LAB12:    t55 = (t27 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (~(t56));
    t58 = *((unsigned int *)t27);
    t59 = (t58 & t57);
    t60 = (t59 != 0);
    if (t60 > 0)
        goto LAB20;

LAB21:    xsi_set_current_line(161, ng0);
    t2 = (t0 + 3664U);
    t3 = *((char **)t2);
    t2 = (t3 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t3);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB24;

LAB25:
LAB26:
LAB22:    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB8:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB9;

LAB10:    t18 = (t0 + 3504U);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t19 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t18) != 0)
        goto LAB15;

LAB16:    t28 = *((unsigned int *)t6);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    *((unsigned int *)t27) = t30;
    t31 = (t6 + 4);
    t32 = (t20 + 4);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t31);
    t35 = *((unsigned int *)t32);
    t36 = (t34 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t20) = 1;
    goto LAB16;

LAB15:    t26 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB16;

LAB17:    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t27) = (t39 | t40);
    t41 = (t6 + 4);
    t42 = (t20 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (~(t43));
    t45 = *((unsigned int *)t6);
    t46 = (t45 & t44);
    t47 = *((unsigned int *)t42);
    t48 = (~(t47));
    t49 = *((unsigned int *)t20);
    t50 = (t49 & t48);
    t51 = (~(t46));
    t52 = (~(t50));
    t53 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t53 & t51);
    t54 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t54 & t52);
    goto LAB19;

LAB20:    xsi_set_current_line(159, ng0);

LAB23:    xsi_set_current_line(160, ng0);
    t61 = ((char*)((ng1)));
    t62 = (t0 + 11424);
    xsi_vlogvar_wait_assign_value(t62, t61, 0, 0, 2, 0LL);
    goto LAB22;

LAB24:    xsi_set_current_line(161, ng0);

LAB27:    xsi_set_current_line(162, ng0);
    t4 = (t0 + 10624);
    t5 = (t4 + 56U);
    t12 = *((char **)t5);
    t13 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t18 = (t12 + 4);
    t19 = (t13 + 4);
    t14 = *((unsigned int *)t12);
    t15 = *((unsigned int *)t13);
    t16 = (t14 ^ t15);
    t17 = *((unsigned int *)t18);
    t21 = *((unsigned int *)t19);
    t22 = (t17 ^ t21);
    t23 = (t16 | t22);
    t24 = *((unsigned int *)t18);
    t25 = *((unsigned int *)t19);
    t28 = (t24 | t25);
    t29 = (~(t28));
    t30 = (t23 & t29);
    if (t30 != 0)
        goto LAB31;

LAB28:    if (t28 != 0)
        goto LAB30;

LAB29:    *((unsigned int *)t6) = 1;

LAB31:    t31 = (t6 + 4);
    t34 = *((unsigned int *)t31);
    t35 = (~(t34));
    t36 = *((unsigned int *)t6);
    t37 = (t36 & t35);
    t38 = (t37 != 0);
    if (t38 > 0)
        goto LAB32;

LAB33:    xsi_set_current_line(164, ng0);
    t2 = (t0 + 11424);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    t12 = (t4 + 4);
    if (*((unsigned int *)t12) != 0)
        goto LAB36;

LAB35:    t13 = (t5 + 4);
    if (*((unsigned int *)t13) != 0)
        goto LAB36;

LAB39:    if (*((unsigned int *)t4) < *((unsigned int *)t5))
        goto LAB37;

LAB38:    t19 = (t6 + 4);
    t7 = *((unsigned int *)t19);
    t8 = (~(t7));
    t9 = *((unsigned int *)t6);
    t10 = (t9 & t8);
    t11 = (t10 != 0);
    if (t11 > 0)
        goto LAB40;

LAB41:    xsi_set_current_line(167, ng0);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 11424);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 2, 0LL);

LAB42:
LAB34:    goto LAB26;

LAB30:    t26 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB31;

LAB32:    xsi_set_current_line(163, ng0);
    t32 = ((char*)((ng2)));
    t33 = (t0 + 11424);
    xsi_vlogvar_wait_assign_value(t33, t32, 0, 0, 2, 0LL);
    goto LAB34;

LAB36:    t18 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t18) = 1;
    goto LAB38;

LAB37:    *((unsigned int *)t6) = 1;
    goto LAB38;

LAB40:    xsi_set_current_line(165, ng0);
    t26 = (t0 + 11424);
    t31 = (t26 + 56U);
    t32 = *((char **)t31);
    t33 = ((char*)((ng2)));
    memset(t20, 0, 8);
    xsi_vlog_unsigned_add(t20, 2, t32, 2, t33, 2);
    t41 = (t0 + 11424);
    xsi_vlogvar_wait_assign_value(t41, t20, 0, 0, 2, 0LL);
    goto LAB42;

}

static void NetDecl_171_8(char *t0)
{
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;

LAB0:    t1 = (t0 + 16240U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(171, ng0);
    t2 = (t0 + 11424);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB5;

LAB4:    t8 = (t5 + 4);
    if (*((unsigned int *)t8) != 0)
        goto LAB5;

LAB8:    if (*((unsigned int *)t4) < *((unsigned int *)t5))
        goto LAB6;

LAB7:    t10 = (t0 + 22224);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memset(t14, 0, 8);
    t15 = 1U;
    t16 = t15;
    t17 = (t6 + 4);
    t18 = *((unsigned int *)t6);
    t15 = (t15 & t18);
    t19 = *((unsigned int *)t17);
    t16 = (t16 & t19);
    t20 = (t14 + 4);
    t21 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t21 | t15);
    t22 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t22 | t16);
    xsi_driver_vfirst_trans(t10, 0, 0U);
    t23 = (t0 + 21648);
    *((int *)t23) = 1;

LAB1:    return;
LAB5:    t9 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB7;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB7;

}

static void NetDecl_172_9(char *t0)
{
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;

LAB0:    t1 = (t0 + 16488U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(172, ng0);
    t2 = (t0 + 11424);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB5;

LAB4:    t8 = (t5 + 4);
    if (*((unsigned int *)t8) != 0)
        goto LAB5;

LAB8:    if (*((unsigned int *)t4) < *((unsigned int *)t5))
        goto LAB6;

LAB7:    t10 = (t0 + 22288);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memset(t14, 0, 8);
    t15 = 1U;
    t16 = t15;
    t17 = (t6 + 4);
    t18 = *((unsigned int *)t6);
    t15 = (t15 & t18);
    t19 = *((unsigned int *)t17);
    t16 = (t16 & t19);
    t20 = (t14 + 4);
    t21 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t21 | t15);
    t22 = *((unsigned int *)t20);
    *((unsigned int *)t20) = (t22 | t16);
    xsi_driver_vfirst_trans(t10, 0, 0U);
    t23 = (t0 + 21664);
    *((int *)t23) = 1;

LAB1:    return;
LAB5:    t9 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB7;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB7;

}

static void NetDecl_174_10(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;

LAB0:    t1 = (t0 + 16736U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(174, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 22352);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t7, 0, 8);
    t8 = 511U;
    t9 = t8;
    t10 = (t2 + 4);
    t11 = *((unsigned int *)t2);
    t8 = (t8 & t11);
    t12 = *((unsigned int *)t10);
    t9 = (t9 & t12);
    t13 = (t7 + 4);
    t14 = *((unsigned int *)t7);
    *((unsigned int *)t7) = (t14 | t8);
    t15 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t15 | t9);
    xsi_driver_vfirst_trans(t3, 0, 8U);

LAB1:    return;
}

static void NetDecl_175_11(char *t0)
{
    char t3[8];
    char t4[8];
    char t23[8];
    char *t1;
    char *t2;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;

LAB0:    t1 = (t0 + 16984U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(175, ng0);
    t2 = (t0 + 4464U);
    t5 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t5 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t2) != 0)
        goto LAB6;

LAB7:    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t12);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB8;

LAB9:    t18 = *((unsigned int *)t4);
    t19 = (~(t18));
    t20 = *((unsigned int *)t12);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t23, 8);

LAB16:    t27 = (t0 + 22416);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    memset(t31, 0, 8);
    t32 = 511U;
    t33 = t32;
    t34 = (t3 + 4);
    t35 = *((unsigned int *)t3);
    t32 = (t32 & t35);
    t36 = *((unsigned int *)t34);
    t33 = (t33 & t36);
    t37 = (t31 + 4);
    t38 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t38 | t32);
    t39 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t39 | t33);
    xsi_driver_vfirst_trans(t27, 0, 8U);
    t40 = (t0 + 21680);
    *((int *)t40) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB7;

LAB8:    t16 = (t0 + 4784U);
    t17 = *((char **)t16);
    goto LAB9;

LAB10:    t16 = (t0 + 9184);
    t24 = (t16 + 56U);
    t25 = *((char **)t24);
    t26 = ((char*)((ng1)));
    xsi_vlogtype_concat(t23, 9, 9, 2U, t26, 1, t25, 8);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 9, t17, 9, t23, 9);
    goto LAB16;

LAB14:    memcpy(t3, t17, 8);
    goto LAB16;

}

static void NetDecl_176_12(char *t0)
{
    char t3[8];
    char t4[8];
    char t23[8];
    char *t1;
    char *t2;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;

LAB0:    t1 = (t0 + 17232U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(176, ng0);
    t2 = (t0 + 4464U);
    t5 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t5 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t2) != 0)
        goto LAB6;

LAB7:    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t12);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB8;

LAB9:    t18 = *((unsigned int *)t4);
    t19 = (~(t18));
    t20 = *((unsigned int *)t12);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t23, 8);

LAB16:    t27 = (t0 + 22480);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    memset(t31, 0, 8);
    t32 = 511U;
    t33 = t32;
    t34 = (t3 + 4);
    t35 = *((unsigned int *)t3);
    t32 = (t32 & t35);
    t36 = *((unsigned int *)t34);
    t33 = (t33 & t36);
    t37 = (t31 + 4);
    t38 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t38 | t32);
    t39 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t39 | t33);
    xsi_driver_vfirst_trans(t27, 0, 8U);
    t40 = (t0 + 21696);
    *((int *)t40) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB7;

LAB8:    t16 = (t0 + 4784U);
    t17 = *((char **)t16);
    goto LAB9;

LAB10:    t16 = (t0 + 9664);
    t24 = (t16 + 56U);
    t25 = *((char **)t24);
    t26 = ((char*)((ng1)));
    xsi_vlogtype_concat(t23, 9, 9, 2U, t26, 1, t25, 8);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 9, t17, 9, t23, 9);
    goto LAB16;

LAB14:    memcpy(t3, t17, 8);
    goto LAB16;

}

static void NetDecl_177_13(char *t0)
{
    char t3[8];
    char t4[8];
    char t23[8];
    char *t1;
    char *t2;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;

LAB0:    t1 = (t0 + 17480U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(177, ng0);
    t2 = (t0 + 4464U);
    t5 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t5 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t2) != 0)
        goto LAB6;

LAB7:    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t12);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB8;

LAB9:    t18 = *((unsigned int *)t4);
    t19 = (~(t18));
    t20 = *((unsigned int *)t12);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t23, 8);

LAB16:    t27 = (t0 + 22544);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    memset(t31, 0, 8);
    t32 = 511U;
    t33 = t32;
    t34 = (t3 + 4);
    t35 = *((unsigned int *)t3);
    t32 = (t32 & t35);
    t36 = *((unsigned int *)t34);
    t33 = (t33 & t36);
    t37 = (t31 + 4);
    t38 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t38 | t32);
    t39 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t39 | t33);
    xsi_driver_vfirst_trans(t27, 0, 8U);
    t40 = (t0 + 21712);
    *((int *)t40) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB7;

LAB8:    t16 = (t0 + 4784U);
    t17 = *((char **)t16);
    goto LAB9;

LAB10:    t16 = (t0 + 10144);
    t24 = (t16 + 56U);
    t25 = *((char **)t24);
    t26 = ((char*)((ng1)));
    xsi_vlogtype_concat(t23, 9, 9, 2U, t26, 1, t25, 8);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 9, t17, 9, t23, 9);
    goto LAB16;

LAB14:    memcpy(t3, t17, 8);
    goto LAB16;

}

static void NetDecl_179_14(char *t0)
{
    char t3[8];
    char t4[8];
    char t23[8];
    char *t1;
    char *t2;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;

LAB0:    t1 = (t0 + 17728U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(179, ng0);
    t2 = (t0 + 4624U);
    t5 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t5 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t2) != 0)
        goto LAB6;

LAB7:    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t12);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB8;

LAB9:    t18 = *((unsigned int *)t4);
    t19 = (~(t18));
    t20 = *((unsigned int *)t12);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t23, 8);

LAB16:    t27 = (t0 + 22608);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    memset(t31, 0, 8);
    t32 = 511U;
    t33 = t32;
    t34 = (t3 + 4);
    t35 = *((unsigned int *)t3);
    t32 = (t32 & t35);
    t36 = *((unsigned int *)t34);
    t33 = (t33 & t36);
    t37 = (t31 + 4);
    t38 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t38 | t32);
    t39 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t39 | t33);
    xsi_driver_vfirst_trans(t27, 0, 8U);
    t40 = (t0 + 21728);
    *((int *)t40) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB7;

LAB8:    t16 = (t0 + 4784U);
    t17 = *((char **)t16);
    goto LAB9;

LAB10:    t16 = (t0 + 9344);
    t24 = (t16 + 56U);
    t25 = *((char **)t24);
    t26 = ((char*)((ng1)));
    xsi_vlogtype_concat(t23, 9, 9, 2U, t26, 1, t25, 8);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 9, t17, 9, t23, 9);
    goto LAB16;

LAB14:    memcpy(t3, t17, 8);
    goto LAB16;

}

static void NetDecl_180_15(char *t0)
{
    char t3[8];
    char t4[8];
    char t23[8];
    char *t1;
    char *t2;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;

LAB0:    t1 = (t0 + 17976U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(180, ng0);
    t2 = (t0 + 4624U);
    t5 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t5 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t2) != 0)
        goto LAB6;

LAB7:    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t12);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB8;

LAB9:    t18 = *((unsigned int *)t4);
    t19 = (~(t18));
    t20 = *((unsigned int *)t12);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t23, 8);

LAB16:    t27 = (t0 + 22672);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    memset(t31, 0, 8);
    t32 = 511U;
    t33 = t32;
    t34 = (t3 + 4);
    t35 = *((unsigned int *)t3);
    t32 = (t32 & t35);
    t36 = *((unsigned int *)t34);
    t33 = (t33 & t36);
    t37 = (t31 + 4);
    t38 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t38 | t32);
    t39 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t39 | t33);
    xsi_driver_vfirst_trans(t27, 0, 8U);
    t40 = (t0 + 21744);
    *((int *)t40) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB7;

LAB8:    t16 = (t0 + 4784U);
    t17 = *((char **)t16);
    goto LAB9;

LAB10:    t16 = (t0 + 9824);
    t24 = (t16 + 56U);
    t25 = *((char **)t24);
    t26 = ((char*)((ng1)));
    xsi_vlogtype_concat(t23, 9, 9, 2U, t26, 1, t25, 8);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 9, t17, 9, t23, 9);
    goto LAB16;

LAB14:    memcpy(t3, t17, 8);
    goto LAB16;

}

static void NetDecl_181_16(char *t0)
{
    char t3[8];
    char t4[8];
    char t23[8];
    char *t1;
    char *t2;
    char *t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    unsigned int t35;
    unsigned int t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    char *t40;

LAB0:    t1 = (t0 + 18224U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(181, ng0);
    t2 = (t0 + 4624U);
    t5 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t5 + 4);
    t6 = *((unsigned int *)t2);
    t7 = (~(t6));
    t8 = *((unsigned int *)t5);
    t9 = (t8 & t7);
    t10 = (t9 & 1U);
    if (t10 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t2) != 0)
        goto LAB6;

LAB7:    t12 = (t4 + 4);
    t13 = *((unsigned int *)t4);
    t14 = *((unsigned int *)t12);
    t15 = (t13 || t14);
    if (t15 > 0)
        goto LAB8;

LAB9:    t18 = *((unsigned int *)t4);
    t19 = (~(t18));
    t20 = *((unsigned int *)t12);
    t21 = (t19 || t20);
    if (t21 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t12) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t23, 8);

LAB16:    t27 = (t0 + 22736);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    memset(t31, 0, 8);
    t32 = 511U;
    t33 = t32;
    t34 = (t3 + 4);
    t35 = *((unsigned int *)t3);
    t32 = (t32 & t35);
    t36 = *((unsigned int *)t34);
    t33 = (t33 & t36);
    t37 = (t31 + 4);
    t38 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t38 | t32);
    t39 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t39 | t33);
    xsi_driver_vfirst_trans(t27, 0, 8U);
    t40 = (t0 + 21760);
    *((int *)t40) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t11 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t11) = 1;
    goto LAB7;

LAB8:    t16 = (t0 + 4784U);
    t17 = *((char **)t16);
    goto LAB9;

LAB10:    t16 = (t0 + 10304);
    t24 = (t16 + 56U);
    t25 = *((char **)t24);
    t26 = ((char*)((ng1)));
    xsi_vlogtype_concat(t23, 9, 9, 2U, t26, 1, t25, 8);
    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 9, t17, 9, t23, 9);
    goto LAB16;

LAB14:    memcpy(t3, t17, 8);
    goto LAB16;

}

static void NetDecl_183_17(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;

LAB0:    t1 = (t0 + 18472U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(183, ng0);
    t2 = (t0 + 9504);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    xsi_vlogtype_concat(t4, 9, 9, 2U, t7, 1, t6, 8);
    t8 = (t0 + 22800);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memset(t12, 0, 8);
    t13 = 511U;
    t14 = t13;
    t15 = (t4 + 4);
    t16 = *((unsigned int *)t4);
    t13 = (t13 & t16);
    t17 = *((unsigned int *)t15);
    t14 = (t14 & t17);
    t18 = (t12 + 4);
    t19 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t19 | t13);
    t20 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t20 | t14);
    xsi_driver_vfirst_trans(t8, 0, 8U);
    t21 = (t0 + 21776);
    *((int *)t21) = 1;

LAB1:    return;
}

static void NetDecl_184_18(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;

LAB0:    t1 = (t0 + 18720U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(184, ng0);
    t2 = (t0 + 9984);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    xsi_vlogtype_concat(t4, 9, 9, 2U, t7, 1, t6, 8);
    t8 = (t0 + 22864);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memset(t12, 0, 8);
    t13 = 511U;
    t14 = t13;
    t15 = (t4 + 4);
    t16 = *((unsigned int *)t4);
    t13 = (t13 & t16);
    t17 = *((unsigned int *)t15);
    t14 = (t14 & t17);
    t18 = (t12 + 4);
    t19 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t19 | t13);
    t20 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t20 | t14);
    xsi_driver_vfirst_trans(t8, 0, 8U);
    t21 = (t0 + 21792);
    *((int *)t21) = 1;

LAB1:    return;
}

static void NetDecl_185_19(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;

LAB0:    t1 = (t0 + 18968U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(185, ng0);
    t2 = (t0 + 10464);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    xsi_vlogtype_concat(t4, 9, 9, 2U, t7, 1, t6, 8);
    t8 = (t0 + 22928);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memset(t12, 0, 8);
    t13 = 511U;
    t14 = t13;
    t15 = (t4 + 4);
    t16 = *((unsigned int *)t4);
    t13 = (t13 & t16);
    t17 = *((unsigned int *)t15);
    t14 = (t14 & t17);
    t18 = (t12 + 4);
    t19 = *((unsigned int *)t12);
    *((unsigned int *)t12) = (t19 | t13);
    t20 = *((unsigned int *)t18);
    *((unsigned int *)t18) = (t20 | t14);
    xsi_driver_vfirst_trans(t8, 0, 8U);
    t21 = (t0 + 21808);
    *((int *)t21) = 1;

LAB1:    return;
}

static void Always_192_20(char *t0)
{
    char t8[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;

LAB0:    t1 = (t0 + 19216U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(192, ng0);
    t2 = (t0 + 21824);
    *((int *)t2) = 1;
    t3 = (t0 + 19248);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(192, ng0);

LAB5:    xsi_set_current_line(193, ng0);
    t4 = (t0 + 4944U);
    t5 = *((char **)t4);
    t4 = (t0 + 7424);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t5, 9, t7, 8);
    t9 = (t0 + 11584);
    xsi_vlogvar_wait_assign_value(t9, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(193, ng0);
    t2 = (t0 + 5424U);
    t3 = *((char **)t2);
    t2 = (t0 + 7584);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t3, 9, t5, 8);
    t6 = (t0 + 11744);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(193, ng0);
    t2 = (t0 + 5904U);
    t3 = *((char **)t2);
    t2 = (t0 + 7744);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t3, 9, t5, 8);
    t6 = (t0 + 11904);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(194, ng0);
    t2 = (t0 + 5104U);
    t3 = *((char **)t2);
    t2 = (t0 + 7904);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t3, 9, t5, 8);
    t6 = (t0 + 12064);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(194, ng0);
    t2 = (t0 + 5584U);
    t3 = *((char **)t2);
    t2 = (t0 + 8064);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t3, 9, t5, 8);
    t6 = (t0 + 12224);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(194, ng0);
    t2 = (t0 + 6064U);
    t3 = *((char **)t2);
    t2 = (t0 + 8224);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t3, 9, t5, 8);
    t6 = (t0 + 12384);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(195, ng0);
    t2 = (t0 + 5264U);
    t3 = *((char **)t2);
    t2 = (t0 + 8384);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t3, 9, t5, 8);
    t6 = (t0 + 12544);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(195, ng0);
    t2 = (t0 + 5744U);
    t3 = *((char **)t2);
    t2 = (t0 + 8544);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t3, 9, t5, 8);
    t6 = (t0 + 12704);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(195, ng0);
    t2 = (t0 + 6224U);
    t3 = *((char **)t2);
    t2 = (t0 + 8704);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t3, 9, t5, 8);
    t6 = (t0 + 12864);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    goto LAB2;

}

static void Always_198_21(char *t0)
{
    char t4[8];
    char t5[8];
    char t8[8];
    char t22[8];
    char t29[8];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    char *t7;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    char *t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    char *t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    char *t74;

LAB0:    t1 = (t0 + 19464U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(198, ng0);
    t2 = (t0 + 21840);
    *((int *)t2) = 1;
    t3 = (t0 + 19496);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(198, ng0);
    t6 = (t0 + 2704U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    t6 = (t7 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB5;

LAB6:    if (*((unsigned int *)t6) != 0)
        goto LAB7;

LAB8:    t15 = (t8 + 4);
    t16 = *((unsigned int *)t8);
    t17 = (!(t16));
    t18 = *((unsigned int *)t15);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB9;

LAB10:    memcpy(t29, t8, 8);

LAB11:    memset(t5, 0, 8);
    t57 = (t29 + 4);
    t58 = *((unsigned int *)t57);
    t59 = (~(t58));
    t60 = *((unsigned int *)t29);
    t61 = (t60 & t59);
    t62 = (t61 & 1U);
    if (t62 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t57) != 0)
        goto LAB21;

LAB22:    t64 = (t5 + 4);
    t65 = *((unsigned int *)t5);
    t66 = *((unsigned int *)t64);
    t67 = (t65 || t66);
    if (t67 > 0)
        goto LAB23;

LAB24:    t69 = *((unsigned int *)t5);
    t70 = (~(t69));
    t71 = *((unsigned int *)t64);
    t72 = (t70 || t71);
    if (t72 > 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t64) > 0)
        goto LAB27;

LAB28:    if (*((unsigned int *)t5) > 0)
        goto LAB29;

LAB30:    memcpy(t4, t74, 8);

LAB31:    t73 = (t0 + 10944);
    xsi_vlogvar_wait_assign_value(t73, t4, 0, 0, 1, 0LL);
    goto LAB2;

LAB5:    *((unsigned int *)t8) = 1;
    goto LAB8;

LAB7:    t14 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB8;

LAB9:    t20 = (t0 + 3504U);
    t21 = *((char **)t20);
    memset(t22, 0, 8);
    t20 = (t21 + 4);
    t23 = *((unsigned int *)t20);
    t24 = (~(t23));
    t25 = *((unsigned int *)t21);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t20) != 0)
        goto LAB14;

LAB15:    t30 = *((unsigned int *)t8);
    t31 = *((unsigned int *)t22);
    t32 = (t30 | t31);
    *((unsigned int *)t29) = t32;
    t33 = (t8 + 4);
    t34 = (t22 + 4);
    t35 = (t29 + 4);
    t36 = *((unsigned int *)t33);
    t37 = *((unsigned int *)t34);
    t38 = (t36 | t37);
    *((unsigned int *)t35) = t38;
    t39 = *((unsigned int *)t35);
    t40 = (t39 != 0);
    if (t40 == 1)
        goto LAB16;

LAB17:
LAB18:    goto LAB11;

LAB12:    *((unsigned int *)t22) = 1;
    goto LAB15;

LAB14:    t28 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB15;

LAB16:    t41 = *((unsigned int *)t29);
    t42 = *((unsigned int *)t35);
    *((unsigned int *)t29) = (t41 | t42);
    t43 = (t8 + 4);
    t44 = (t22 + 4);
    t45 = *((unsigned int *)t43);
    t46 = (~(t45));
    t47 = *((unsigned int *)t8);
    t48 = (t47 & t46);
    t49 = *((unsigned int *)t44);
    t50 = (~(t49));
    t51 = *((unsigned int *)t22);
    t52 = (t51 & t50);
    t53 = (~(t48));
    t54 = (~(t52));
    t55 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t55 & t53);
    t56 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t56 & t54);
    goto LAB18;

LAB19:    *((unsigned int *)t5) = 1;
    goto LAB22;

LAB21:    t63 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t63) = 1;
    goto LAB22;

LAB23:    t68 = ((char*)((ng1)));
    goto LAB24;

LAB25:    t73 = (t0 + 4304U);
    t74 = *((char **)t73);
    goto LAB26;

LAB27:    xsi_vlog_unsigned_bit_combine(t4, 1, t68, 1, t74, 1);
    goto LAB31;

LAB29:    memcpy(t4, t68, 8);
    goto LAB31;

}

static void Always_199_22(char *t0)
{
    char t4[8];
    char t5[8];
    char t8[8];
    char t22[8];
    char t29[8];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    char *t7;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    char *t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    char *t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    char *t74;
    char *t75;
    char *t76;

LAB0:    t1 = (t0 + 19712U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(199, ng0);
    t2 = (t0 + 21856);
    *((int *)t2) = 1;
    t3 = (t0 + 19744);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(199, ng0);
    t6 = (t0 + 2704U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    t6 = (t7 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB5;

LAB6:    if (*((unsigned int *)t6) != 0)
        goto LAB7;

LAB8:    t15 = (t8 + 4);
    t16 = *((unsigned int *)t8);
    t17 = (!(t16));
    t18 = *((unsigned int *)t15);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB9;

LAB10:    memcpy(t29, t8, 8);

LAB11:    memset(t5, 0, 8);
    t57 = (t29 + 4);
    t58 = *((unsigned int *)t57);
    t59 = (~(t58));
    t60 = *((unsigned int *)t29);
    t61 = (t60 & t59);
    t62 = (t61 & 1U);
    if (t62 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t57) != 0)
        goto LAB21;

LAB22:    t64 = (t5 + 4);
    t65 = *((unsigned int *)t5);
    t66 = *((unsigned int *)t64);
    t67 = (t65 || t66);
    if (t67 > 0)
        goto LAB23;

LAB24:    t69 = *((unsigned int *)t5);
    t70 = (~(t69));
    t71 = *((unsigned int *)t64);
    t72 = (t70 || t71);
    if (t72 > 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t64) > 0)
        goto LAB27;

LAB28:    if (*((unsigned int *)t5) > 0)
        goto LAB29;

LAB30:    memcpy(t4, t75, 8);

LAB31:    t76 = (t0 + 11104);
    xsi_vlogvar_wait_assign_value(t76, t4, 0, 0, 1, 0LL);
    goto LAB2;

LAB5:    *((unsigned int *)t8) = 1;
    goto LAB8;

LAB7:    t14 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB8;

LAB9:    t20 = (t0 + 3504U);
    t21 = *((char **)t20);
    memset(t22, 0, 8);
    t20 = (t21 + 4);
    t23 = *((unsigned int *)t20);
    t24 = (~(t23));
    t25 = *((unsigned int *)t21);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t20) != 0)
        goto LAB14;

LAB15:    t30 = *((unsigned int *)t8);
    t31 = *((unsigned int *)t22);
    t32 = (t30 | t31);
    *((unsigned int *)t29) = t32;
    t33 = (t8 + 4);
    t34 = (t22 + 4);
    t35 = (t29 + 4);
    t36 = *((unsigned int *)t33);
    t37 = *((unsigned int *)t34);
    t38 = (t36 | t37);
    *((unsigned int *)t35) = t38;
    t39 = *((unsigned int *)t35);
    t40 = (t39 != 0);
    if (t40 == 1)
        goto LAB16;

LAB17:
LAB18:    goto LAB11;

LAB12:    *((unsigned int *)t22) = 1;
    goto LAB15;

LAB14:    t28 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB15;

LAB16:    t41 = *((unsigned int *)t29);
    t42 = *((unsigned int *)t35);
    *((unsigned int *)t29) = (t41 | t42);
    t43 = (t8 + 4);
    t44 = (t22 + 4);
    t45 = *((unsigned int *)t43);
    t46 = (~(t45));
    t47 = *((unsigned int *)t8);
    t48 = (t47 & t46);
    t49 = *((unsigned int *)t44);
    t50 = (~(t49));
    t51 = *((unsigned int *)t22);
    t52 = (t51 & t50);
    t53 = (~(t48));
    t54 = (~(t52));
    t55 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t55 & t53);
    t56 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t56 & t54);
    goto LAB18;

LAB19:    *((unsigned int *)t5) = 1;
    goto LAB22;

LAB21:    t63 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t63) = 1;
    goto LAB22;

LAB23:    t68 = ((char*)((ng1)));
    goto LAB24;

LAB25:    t73 = (t0 + 10944);
    t74 = (t73 + 56U);
    t75 = *((char **)t74);
    goto LAB26;

LAB27:    xsi_vlog_unsigned_bit_combine(t4, 1, t68, 1, t75, 1);
    goto LAB31;

LAB29:    memcpy(t4, t68, 8);
    goto LAB31;

}

static void Always_206_23(char *t0)
{
    char t10[8];
    char t14[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t11;
    char *t12;
    char *t13;
    char *t15;

LAB0:    t1 = (t0 + 19960U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(206, ng0);
    t2 = (t0 + 21872);
    *((int *)t2) = 1;
    t3 = (t0 + 19992);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(206, ng0);

LAB5:    xsi_set_current_line(207, ng0);
    t4 = (t0 + 11584);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 11744);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 22, t6, 17, t9, 17);
    t11 = (t0 + 11904);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memset(t14, 0, 8);
    xsi_vlog_signed_add(t14, 22, t10, 22, t13, 17);
    t15 = (t0 + 13024);
    xsi_vlogvar_wait_assign_value(t15, t14, 0, 0, 22, 0LL);
    xsi_set_current_line(208, ng0);
    t2 = (t0 + 12064);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 12224);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 22, t4, 17, t7, 17);
    t8 = (t0 + 12384);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    memset(t14, 0, 8);
    xsi_vlog_signed_add(t14, 22, t10, 22, t11, 17);
    t12 = (t0 + 13184);
    xsi_vlogvar_wait_assign_value(t12, t14, 0, 0, 22, 0LL);
    xsi_set_current_line(209, ng0);
    t2 = (t0 + 12544);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 12704);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 22, t4, 17, t7, 17);
    t8 = (t0 + 12864);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    memset(t14, 0, 8);
    xsi_vlog_signed_add(t14, 22, t10, 22, t11, 17);
    t12 = (t0 + 13344);
    xsi_vlogvar_wait_assign_value(t12, t14, 0, 0, 22, 0LL);
    goto LAB2;

}

static void Always_212_24(char *t0)
{
    char t4[8];
    char t5[8];
    char t8[8];
    char t22[8];
    char t29[8];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    char *t7;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    char *t33;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    char *t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    char *t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    char *t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    char *t74;
    char *t75;
    char *t76;

LAB0:    t1 = (t0 + 20208U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(212, ng0);
    t2 = (t0 + 21888);
    *((int *)t2) = 1;
    t3 = (t0 + 20240);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(212, ng0);
    t6 = (t0 + 2704U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    t6 = (t7 + 4);
    t9 = *((unsigned int *)t6);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB5;

LAB6:    if (*((unsigned int *)t6) != 0)
        goto LAB7;

LAB8:    t15 = (t8 + 4);
    t16 = *((unsigned int *)t8);
    t17 = (!(t16));
    t18 = *((unsigned int *)t15);
    t19 = (t17 || t18);
    if (t19 > 0)
        goto LAB9;

LAB10:    memcpy(t29, t8, 8);

LAB11:    memset(t5, 0, 8);
    t57 = (t29 + 4);
    t58 = *((unsigned int *)t57);
    t59 = (~(t58));
    t60 = *((unsigned int *)t29);
    t61 = (t60 & t59);
    t62 = (t61 & 1U);
    if (t62 != 0)
        goto LAB19;

LAB20:    if (*((unsigned int *)t57) != 0)
        goto LAB21;

LAB22:    t64 = (t5 + 4);
    t65 = *((unsigned int *)t5);
    t66 = *((unsigned int *)t64);
    t67 = (t65 || t66);
    if (t67 > 0)
        goto LAB23;

LAB24:    t69 = *((unsigned int *)t5);
    t70 = (~(t69));
    t71 = *((unsigned int *)t64);
    t72 = (t70 || t71);
    if (t72 > 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t64) > 0)
        goto LAB27;

LAB28:    if (*((unsigned int *)t5) > 0)
        goto LAB29;

LAB30:    memcpy(t4, t75, 8);

LAB31:    t76 = (t0 + 11264);
    xsi_vlogvar_wait_assign_value(t76, t4, 0, 0, 1, 0LL);
    goto LAB2;

LAB5:    *((unsigned int *)t8) = 1;
    goto LAB8;

LAB7:    t14 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB8;

LAB9:    t20 = (t0 + 3504U);
    t21 = *((char **)t20);
    memset(t22, 0, 8);
    t20 = (t21 + 4);
    t23 = *((unsigned int *)t20);
    t24 = (~(t23));
    t25 = *((unsigned int *)t21);
    t26 = (t25 & t24);
    t27 = (t26 & 1U);
    if (t27 != 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t20) != 0)
        goto LAB14;

LAB15:    t30 = *((unsigned int *)t8);
    t31 = *((unsigned int *)t22);
    t32 = (t30 | t31);
    *((unsigned int *)t29) = t32;
    t33 = (t8 + 4);
    t34 = (t22 + 4);
    t35 = (t29 + 4);
    t36 = *((unsigned int *)t33);
    t37 = *((unsigned int *)t34);
    t38 = (t36 | t37);
    *((unsigned int *)t35) = t38;
    t39 = *((unsigned int *)t35);
    t40 = (t39 != 0);
    if (t40 == 1)
        goto LAB16;

LAB17:
LAB18:    goto LAB11;

LAB12:    *((unsigned int *)t22) = 1;
    goto LAB15;

LAB14:    t28 = (t22 + 4);
    *((unsigned int *)t22) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB15;

LAB16:    t41 = *((unsigned int *)t29);
    t42 = *((unsigned int *)t35);
    *((unsigned int *)t29) = (t41 | t42);
    t43 = (t8 + 4);
    t44 = (t22 + 4);
    t45 = *((unsigned int *)t43);
    t46 = (~(t45));
    t47 = *((unsigned int *)t8);
    t48 = (t47 & t46);
    t49 = *((unsigned int *)t44);
    t50 = (~(t49));
    t51 = *((unsigned int *)t22);
    t52 = (t51 & t50);
    t53 = (~(t48));
    t54 = (~(t52));
    t55 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t55 & t53);
    t56 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t56 & t54);
    goto LAB18;

LAB19:    *((unsigned int *)t5) = 1;
    goto LAB22;

LAB21:    t63 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t63) = 1;
    goto LAB22;

LAB23:    t68 = ((char*)((ng1)));
    goto LAB24;

LAB25:    t73 = (t0 + 11104);
    t74 = (t73 + 56U);
    t75 = *((char **)t74);
    goto LAB26;

LAB27:    xsi_vlog_unsigned_bit_combine(t4, 1, t68, 1, t75, 1);
    goto LAB31;

LAB29:    memcpy(t4, t68, 8);
    goto LAB31;

}

static void NetDecl_217_25(char *t0)
{
    char t8[8];
    char t12[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    char *t11;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;

LAB0:    t1 = (t0 + 20456U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(217, ng0);
    t2 = (t0 + 13024);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 13184);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    xsi_vlog_signed_add(t8, 22, t4, 22, t7, 22);
    t9 = (t0 + 13344);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memset(t12, 0, 8);
    xsi_vlog_signed_add(t12, 22, t8, 22, t11, 22);
    t13 = (t0 + 22992);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memset(t17, 0, 8);
    t18 = 4194303U;
    t19 = t18;
    t20 = (t12 + 4);
    t21 = *((unsigned int *)t12);
    t18 = (t18 & t21);
    t22 = *((unsigned int *)t20);
    t19 = (t19 & t22);
    t23 = (t17 + 4);
    t24 = *((unsigned int *)t17);
    *((unsigned int *)t17) = (t24 | t18);
    t25 = *((unsigned int *)t23);
    *((unsigned int *)t23) = (t25 | t19);
    xsi_driver_vfirst_trans(t13, 0, 21U);
    t26 = (t0 + 21904);
    *((int *)t26) = 1;

LAB1:    return;
}

static void NetDecl_219_26(char *t0)
{
    char t3[8];
    char t4[8];
    char t7[8];
    char t24[8];
    char t25[8];
    char t29[8];
    char t46[8];
    char *t1;
    char *t2;
    char *t5;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t26;
    char *t27;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    char *t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    char *t47;
    char *t48;
    char *t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    unsigned int t61;
    unsigned int t62;
    char *t63;
    unsigned int t64;
    unsigned int t65;
    char *t66;
    unsigned int t67;
    unsigned int t68;
    char *t69;

LAB0:    t1 = (t0 + 20704U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(219, ng0);
    t2 = (t0 + 6384U);
    t5 = *((char **)t2);
    t2 = ((char*)((ng12)));
    memset(t7, 0, 8);
    xsi_vlog_signed_greater(t7, 22, t5, 22, t2, 22);
    memset(t4, 0, 8);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t8);
    t10 = (~(t9));
    t11 = *((unsigned int *)t7);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t8) != 0)
        goto LAB6;

LAB7:    t15 = (t4 + 4);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t15);
    t18 = (t16 || t17);
    if (t18 > 0)
        goto LAB8;

LAB9:    t20 = *((unsigned int *)t4);
    t21 = (~(t20));
    t22 = *((unsigned int *)t15);
    t23 = (t21 || t22);
    if (t23 > 0)
        goto LAB10;

LAB11:    if (*((unsigned int *)t15) > 0)
        goto LAB12;

LAB13:    if (*((unsigned int *)t4) > 0)
        goto LAB14;

LAB15:    memcpy(t3, t24, 8);

LAB16:    t56 = (t0 + 23056);
    t57 = (t56 + 56U);
    t58 = *((char **)t57);
    t59 = (t58 + 56U);
    t60 = *((char **)t59);
    memset(t60, 0, 8);
    t61 = 65535U;
    t62 = t61;
    t63 = (t3 + 4);
    t64 = *((unsigned int *)t3);
    t61 = (t61 & t64);
    t65 = *((unsigned int *)t63);
    t62 = (t62 & t65);
    t66 = (t60 + 4);
    t67 = *((unsigned int *)t60);
    *((unsigned int *)t60) = (t67 | t61);
    t68 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t68 | t62);
    xsi_driver_vfirst_trans(t56, 0, 15U);
    t69 = (t0 + 21920);
    *((int *)t69) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t14 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB7;

LAB8:    t19 = ((char*)((ng12)));
    goto LAB9;

LAB10:    t26 = (t0 + 6384U);
    t27 = *((char **)t26);
    t26 = ((char*)((ng13)));
    memset(t29, 0, 8);
    xsi_vlog_signed_less(t29, 22, t27, 22, t26, 22);
    memset(t25, 0, 8);
    t30 = (t29 + 4);
    t31 = *((unsigned int *)t30);
    t32 = (~(t31));
    t33 = *((unsigned int *)t29);
    t34 = (t33 & t32);
    t35 = (t34 & 1U);
    if (t35 != 0)
        goto LAB17;

LAB18:    if (*((unsigned int *)t30) != 0)
        goto LAB19;

LAB20:    t37 = (t25 + 4);
    t38 = *((unsigned int *)t25);
    t39 = *((unsigned int *)t37);
    t40 = (t38 || t39);
    if (t40 > 0)
        goto LAB21;

LAB22:    t42 = *((unsigned int *)t25);
    t43 = (~(t42));
    t44 = *((unsigned int *)t37);
    t45 = (t43 || t44);
    if (t45 > 0)
        goto LAB23;

LAB24:    if (*((unsigned int *)t37) > 0)
        goto LAB25;

LAB26:    if (*((unsigned int *)t25) > 0)
        goto LAB27;

LAB28:    memcpy(t24, t46, 8);

LAB29:    goto LAB11;

LAB12:    xsi_vlog_unsigned_bit_combine(t3, 16, t19, 16, t24, 16);
    goto LAB16;

LAB14:    memcpy(t3, t19, 8);
    goto LAB16;

LAB17:    *((unsigned int *)t25) = 1;
    goto LAB20;

LAB19:    t36 = (t25 + 4);
    *((unsigned int *)t25) = 1;
    *((unsigned int *)t36) = 1;
    goto LAB20;

LAB21:    t41 = ((char*)((ng14)));
    goto LAB22;

LAB23:    t47 = (t0 + 6384U);
    t48 = *((char **)t47);
    memset(t46, 0, 8);
    t47 = (t46 + 4);
    t49 = (t48 + 4);
    t50 = *((unsigned int *)t48);
    t51 = (t50 >> 0);
    *((unsigned int *)t46) = t51;
    t52 = *((unsigned int *)t49);
    t53 = (t52 >> 0);
    *((unsigned int *)t47) = t53;
    t54 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t54 & 65535U);
    t55 = *((unsigned int *)t47);
    *((unsigned int *)t47) = (t55 & 65535U);
    goto LAB24;

LAB25:    xsi_vlog_unsigned_bit_combine(t24, 16, t41, 16, t46, 16);
    goto LAB29;

LAB27:    memcpy(t24, t41, 8);
    goto LAB29;

}

static void NetDecl_224_27(char *t0)
{
    char t3[8];
    char t4[8];
    char t6[8];
    char t19[8];
    char t27[8];
    char t35[8];
    char *t1;
    char *t2;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    char *t34;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    char *t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    char *t49;
    char *t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    int t59;
    int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    char *t73;
    char *t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    char *t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    char *t88;
    unsigned int t89;
    unsigned int t90;
    char *t91;
    unsigned int t92;
    unsigned int t93;
    char *t94;
    unsigned int t95;
    unsigned int t96;
    char *t97;

LAB0:    t1 = (t0 + 20952U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(224, ng0);
    t2 = (t0 + 3344U);
    t5 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t5 + 4);
    t7 = *((unsigned int *)t2);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t2) != 0)
        goto LAB6;

LAB7:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = *((unsigned int *)t13);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB8;

LAB9:    memcpy(t35, t6, 8);

LAB10:    memset(t4, 0, 8);
    t67 = (t35 + 4);
    t68 = *((unsigned int *)t67);
    t69 = (~(t68));
    t70 = *((unsigned int *)t35);
    t71 = (t70 & t69);
    t72 = (t71 & 1U);
    if (t72 != 0)
        goto LAB18;

LAB19:    if (*((unsigned int *)t67) != 0)
        goto LAB20;

LAB21:    t74 = (t4 + 4);
    t75 = *((unsigned int *)t4);
    t76 = *((unsigned int *)t74);
    t77 = (t75 || t76);
    if (t77 > 0)
        goto LAB22;

LAB23:    t79 = *((unsigned int *)t4);
    t80 = (~(t79));
    t81 = *((unsigned int *)t74);
    t82 = (t80 || t81);
    if (t82 > 0)
        goto LAB24;

LAB25:    if (*((unsigned int *)t74) > 0)
        goto LAB26;

LAB27:    if (*((unsigned int *)t4) > 0)
        goto LAB28;

LAB29:    memcpy(t3, t84, 8);

LAB30:    t83 = (t0 + 23120);
    t85 = (t83 + 56U);
    t86 = *((char **)t85);
    t87 = (t86 + 56U);
    t88 = *((char **)t87);
    memset(t88, 0, 8);
    t89 = 65535U;
    t90 = t89;
    t91 = (t3 + 4);
    t92 = *((unsigned int *)t3);
    t89 = (t89 & t92);
    t93 = *((unsigned int *)t91);
    t90 = (t90 & t93);
    t94 = (t88 + 4);
    t95 = *((unsigned int *)t88);
    *((unsigned int *)t88) = (t95 | t89);
    t96 = *((unsigned int *)t94);
    *((unsigned int *)t94) = (t96 | t90);
    xsi_driver_vfirst_trans(t83, 0, 15U);
    t97 = (t0 + 21936);
    *((int *)t97) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t6) = 1;
    goto LAB7;

LAB6:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB8:    t17 = (t0 + 6544U);
    t18 = *((char **)t17);
    memset(t19, 0, 8);
    t17 = (t19 + 4);
    t20 = (t18 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (t21 >> 15);
    t23 = (t22 & 1);
    *((unsigned int *)t19) = t23;
    t24 = *((unsigned int *)t20);
    t25 = (t24 >> 15);
    t26 = (t25 & 1);
    *((unsigned int *)t17) = t26;
    memset(t27, 0, 8);
    t28 = (t19 + 4);
    t29 = *((unsigned int *)t28);
    t30 = (~(t29));
    t31 = *((unsigned int *)t19);
    t32 = (t31 & t30);
    t33 = (t32 & 1U);
    if (t33 != 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t28) != 0)
        goto LAB13;

LAB14:    t36 = *((unsigned int *)t6);
    t37 = *((unsigned int *)t27);
    t38 = (t36 & t37);
    *((unsigned int *)t35) = t38;
    t39 = (t6 + 4);
    t40 = (t27 + 4);
    t41 = (t35 + 4);
    t42 = *((unsigned int *)t39);
    t43 = *((unsigned int *)t40);
    t44 = (t42 | t43);
    *((unsigned int *)t41) = t44;
    t45 = *((unsigned int *)t41);
    t46 = (t45 != 0);
    if (t46 == 1)
        goto LAB15;

LAB16:
LAB17:    goto LAB10;

LAB11:    *((unsigned int *)t27) = 1;
    goto LAB14;

LAB13:    t34 = (t27 + 4);
    *((unsigned int *)t27) = 1;
    *((unsigned int *)t34) = 1;
    goto LAB14;

LAB15:    t47 = *((unsigned int *)t35);
    t48 = *((unsigned int *)t41);
    *((unsigned int *)t35) = (t47 | t48);
    t49 = (t6 + 4);
    t50 = (t27 + 4);
    t51 = *((unsigned int *)t6);
    t52 = (~(t51));
    t53 = *((unsigned int *)t49);
    t54 = (~(t53));
    t55 = *((unsigned int *)t27);
    t56 = (~(t55));
    t57 = *((unsigned int *)t50);
    t58 = (~(t57));
    t59 = (t52 & t54);
    t60 = (t56 & t58);
    t61 = (~(t59));
    t62 = (~(t60));
    t63 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t63 & t61);
    t64 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t64 & t62);
    t65 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t65 & t61);
    t66 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t66 & t62);
    goto LAB17;

LAB18:    *((unsigned int *)t4) = 1;
    goto LAB21;

LAB20:    t73 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t73) = 1;
    goto LAB21;

LAB22:    t78 = ((char*)((ng1)));
    goto LAB23;

LAB24:    t83 = (t0 + 6544U);
    t84 = *((char **)t83);
    goto LAB25;

LAB26:    xsi_vlog_unsigned_bit_combine(t3, 16, t78, 16, t84, 16);
    goto LAB30;

LAB28:    memcpy(t3, t78, 8);
    goto LAB30;

}

static void Always_226_28(char *t0)
{
    char t6[8];
    char t20[8];
    char t27[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    unsigned int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    char *t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;
    char *t62;

LAB0:    t1 = (t0 + 21200U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(226, ng0);
    t2 = (t0 + 21952);
    *((int *)t2) = 1;
    t3 = (t0 + 21232);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(226, ng0);

LAB5:    xsi_set_current_line(227, ng0);
    t4 = (t0 + 2704U);
    t5 = *((char **)t4);
    memset(t6, 0, 8);
    t4 = (t5 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t11 = (t10 & 1U);
    if (t11 != 0)
        goto LAB6;

LAB7:    if (*((unsigned int *)t4) != 0)
        goto LAB8;

LAB9:    t13 = (t6 + 4);
    t14 = *((unsigned int *)t6);
    t15 = (!(t14));
    t16 = *((unsigned int *)t13);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB10;

LAB11:    memcpy(t27, t6, 8);

LAB12:    t55 = (t27 + 4);
    t56 = *((unsigned int *)t55);
    t57 = (~(t56));
    t58 = *((unsigned int *)t27);
    t59 = (t58 & t57);
    t60 = (t59 != 0);
    if (t60 > 0)
        goto LAB20;

LAB21:    xsi_set_current_line(230, ng0);

LAB24:    xsi_set_current_line(231, ng0);
    t2 = (t0 + 11264);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 7104);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(232, ng0);
    t2 = (t0 + 6704U);
    t3 = *((char **)t2);
    t2 = (t0 + 7264);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 16, 0LL);

LAB22:    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB8:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB9;

LAB10:    t18 = (t0 + 3504U);
    t19 = *((char **)t18);
    memset(t20, 0, 8);
    t18 = (t19 + 4);
    t21 = *((unsigned int *)t18);
    t22 = (~(t21));
    t23 = *((unsigned int *)t19);
    t24 = (t23 & t22);
    t25 = (t24 & 1U);
    if (t25 != 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t18) != 0)
        goto LAB15;

LAB16:    t28 = *((unsigned int *)t6);
    t29 = *((unsigned int *)t20);
    t30 = (t28 | t29);
    *((unsigned int *)t27) = t30;
    t31 = (t6 + 4);
    t32 = (t20 + 4);
    t33 = (t27 + 4);
    t34 = *((unsigned int *)t31);
    t35 = *((unsigned int *)t32);
    t36 = (t34 | t35);
    *((unsigned int *)t33) = t36;
    t37 = *((unsigned int *)t33);
    t38 = (t37 != 0);
    if (t38 == 1)
        goto LAB17;

LAB18:
LAB19:    goto LAB12;

LAB13:    *((unsigned int *)t20) = 1;
    goto LAB16;

LAB15:    t26 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t26) = 1;
    goto LAB16;

LAB17:    t39 = *((unsigned int *)t27);
    t40 = *((unsigned int *)t33);
    *((unsigned int *)t27) = (t39 | t40);
    t41 = (t6 + 4);
    t42 = (t20 + 4);
    t43 = *((unsigned int *)t41);
    t44 = (~(t43));
    t45 = *((unsigned int *)t6);
    t46 = (t45 & t44);
    t47 = *((unsigned int *)t42);
    t48 = (~(t47));
    t49 = *((unsigned int *)t20);
    t50 = (t49 & t48);
    t51 = (~(t46));
    t52 = (~(t50));
    t53 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t53 & t51);
    t54 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t54 & t52);
    goto LAB19;

LAB20:    xsi_set_current_line(227, ng0);

LAB23:    xsi_set_current_line(228, ng0);
    t61 = ((char*)((ng1)));
    t62 = (t0 + 7104);
    xsi_vlogvar_wait_assign_value(t62, t61, 0, 0, 1, 0LL);
    xsi_set_current_line(229, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 7264);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 16, 0LL);
    goto LAB22;

}


extern void work_m_07116475562366686468_1203478987_init()
{
	static char *pe[] = {(void *)Always_76_0,(void *)NetDecl_91_1,(void *)NetDecl_92_2,(void *)Always_94_3,(void *)Always_111_4,(void *)Always_125_5,(void *)NetDecl_140_6,(void *)Always_158_7,(void *)NetDecl_171_8,(void *)NetDecl_172_9,(void *)NetDecl_174_10,(void *)NetDecl_175_11,(void *)NetDecl_176_12,(void *)NetDecl_177_13,(void *)NetDecl_179_14,(void *)NetDecl_180_15,(void *)NetDecl_181_16,(void *)NetDecl_183_17,(void *)NetDecl_184_18,(void *)NetDecl_185_19,(void *)Always_192_20,(void *)Always_198_21,(void *)Always_199_22,(void *)Always_206_23,(void *)Always_212_24,(void *)NetDecl_217_25,(void *)NetDecl_219_26,(void *)NetDecl_224_27,(void *)Always_226_28};
	xsi_register_didat("work_m_07116475562366686468_1203478987", "isim/power_same_isim.sim/work/m_07116475562366686468_1203478987.didat");
	xsi_register_executes(pe);
}
