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
static const char *ng0 = "/home/mohamed-esam/sscs2026-conv-accel/tb/tb_power_same_toplevel.v";
static int ng1[] = {0, 0};
static int ng2[] = {8, 0};
static int ng3[] = {1, 0};
static int ng4[] = {2, 0};
static const char *ng5 = "vectors/kernel_sobel_x.hex";
static const char *ng6 = "vectors/img_ramp.hex";
static int ng7[] = {10, 0};
static int ng8[] = {9, 0};
static int ng9[] = {20, 0};
static const char *ng10 = "Post-route power trace complete: %0d pixels, zero-gap, through full UART protocol";
static const char *ng11 = "TIMEOUT";



static int sp_send(char *t1, char *t2)
{
    char t15[8];
    char t19[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 1664);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(28, ng0);

LAB5:    xsi_set_current_line(29, ng0);
    t5 = ((char*)((ng1)));
    t6 = (t1 + 3928);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 1);
    xsi_set_current_line(29, ng0);
    t4 = (t1 + 880);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t6 = (t1 + 9200);
    *((int *)t6) = t10;

LAB6:    t11 = (t1 + 9200);
    if (*((int *)t11) > 0)
        goto LAB7;

LAB8:    xsi_set_current_line(30, ng0);
    xsi_set_current_line(30, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t1 + 5048);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB10:    t4 = (t1 + 5048);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t11 = ((char*)((ng2)));
    memset(t15, 0, 8);
    xsi_vlog_signed_less(t15, 32, t6, 32, t11, 32);
    t12 = (t15 + 4);
    t7 = *((unsigned int *)t12);
    t8 = (~(t7));
    t9 = *((unsigned int *)t15);
    t16 = (t9 & t8);
    t17 = (t16 != 0);
    if (t17 > 0)
        goto LAB11;

LAB12:    xsi_set_current_line(31, ng0);
    t4 = ((char*)((ng3)));
    t5 = (t1 + 3928);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(31, ng0);
    t4 = (t1 + 880);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t6 = (t1 + 9208);
    *((int *)t6) = t10;

LAB18:    t11 = (t1 + 9208);
    if (*((int *)t11) > 0)
        goto LAB19;

LAB20:
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;

LAB1:    return t0;
LAB7:    xsi_set_current_line(29, ng0);
    t12 = (t2 + 88U);
    t13 = *((char **)t12);
    t14 = (t13 + 0U);
    xsi_wp_set_status(t14, 1);
    *((char **)t3) = &&LAB9;
    goto LAB1;

LAB9:    t4 = (t1 + 9200);
    t10 = *((int *)t4);
    *((int *)t4) = (t10 - 1);
    goto LAB6;

LAB11:    xsi_set_current_line(30, ng0);

LAB13:    xsi_set_current_line(30, ng0);
    t13 = (t1 + 4888);
    t14 = (t13 + 56U);
    t18 = *((char **)t14);
    t20 = (t1 + 4888);
    t21 = (t20 + 72U);
    t22 = *((char **)t21);
    t23 = (t1 + 5048);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    xsi_vlog_generic_get_index_select_value(t19, 1, t18, t22, 2, t25, 32, 1);
    t26 = (t1 + 3928);
    xsi_vlogvar_assign_value(t26, t19, 0, 0, 1);
    xsi_set_current_line(30, ng0);
    t4 = (t1 + 880);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t7 = *((unsigned int *)t4);
    t8 = (~(t7));
    t9 = *((unsigned int *)t5);
    t10 = (t9 & t8);
    t6 = (t1 + 9204);
    *((int *)t6) = t10;

LAB14:    t11 = (t1 + 9204);
    if (*((int *)t11) > 0)
        goto LAB15;

LAB16:    xsi_set_current_line(30, ng0);
    t4 = (t1 + 5048);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t11 = ((char*)((ng3)));
    memset(t15, 0, 8);
    xsi_vlog_signed_add(t15, 32, t6, 32, t11, 32);
    t12 = (t1 + 5048);
    xsi_vlogvar_assign_value(t12, t15, 0, 0, 32);
    goto LAB10;

LAB15:    xsi_set_current_line(30, ng0);
    t12 = (t2 + 88U);
    t13 = *((char **)t12);
    t14 = (t13 + 16U);
    xsi_wp_set_status(t14, 1);
    *((char **)t3) = &&LAB17;
    goto LAB1;

LAB17:    t4 = (t1 + 9204);
    t10 = *((int *)t4);
    *((int *)t4) = (t10 - 1);
    goto LAB14;

LAB19:    xsi_set_current_line(31, ng0);
    t12 = (t2 + 88U);
    t13 = *((char **)t12);
    t14 = (t13 + 32U);
    xsi_wp_set_status(t14, 1);
    *((char **)t3) = &&LAB21;
    goto LAB1;

LAB21:    t4 = (t1 + 9208);
    t10 = *((int *)t4);
    *((int *)t4) = (t10 - 1);
    goto LAB18;

}

static int sp_recv(char *t1, char *t2)
{
    char t8[8];
    char t9[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    unsigned int t26;

LAB0:    t0 = 1;
    t3 = (t2 + 48U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 2096);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(37, ng0);

LAB5:    xsi_set_current_line(38, ng0);
    t5 = (t2 + 88U);
    t6 = *((char **)t5);
    t7 = (t6 + 0U);
    xsi_wp_set_status(t7, 1);
    *((char **)t3) = &&LAB6;

LAB1:    return t0;
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 48U);
    *((char **)t4) = &&LAB2;
    t0 = 0;
    goto LAB1;

LAB6:    xsi_set_current_line(38, ng0);
    t4 = (t1 + 880);
    t5 = *((char **)t4);
    t4 = (t1 + 880);
    t6 = *((char **)t4);
    t4 = ((char*)((ng4)));
    memset(t8, 0, 8);
    xsi_vlog_signed_divide(t8, 32, t6, 32, t4, 32);
    memset(t9, 0, 8);
    xsi_vlog_signed_add(t9, 32, t5, 32, t8, 32);
    t7 = (t9 + 4);
    t10 = *((unsigned int *)t7);
    t11 = (~(t10));
    t12 = *((unsigned int *)t9);
    t13 = (t12 & t11);
    t14 = (t1 + 9212);
    *((int *)t14) = t13;

LAB7:    t15 = (t1 + 9212);
    if (*((int *)t15) > 0)
        goto LAB8;

LAB9:    xsi_set_current_line(39, ng0);
    xsi_set_current_line(39, ng0);
    t4 = ((char*)((ng1)));
    t5 = (t1 + 5368);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 32);

LAB11:    t4 = (t1 + 5368);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng2)));
    memset(t8, 0, 8);
    xsi_vlog_signed_less(t8, 32, t6, 32, t7, 32);
    t14 = (t8 + 4);
    t10 = *((unsigned int *)t14);
    t11 = (~(t10));
    t12 = *((unsigned int *)t8);
    t19 = (t12 & t11);
    t20 = (t19 != 0);
    if (t20 > 0)
        goto LAB12;

LAB13:    goto LAB4;

LAB8:    xsi_set_current_line(38, ng0);
    t16 = (t2 + 88U);
    t17 = *((char **)t16);
    t18 = (t17 + 16U);
    xsi_wp_set_status(t18, 1);
    *((char **)t3) = &&LAB10;
    goto LAB1;

LAB10:    t4 = (t1 + 9212);
    t13 = *((int *)t4);
    *((int *)t4) = (t13 - 1);
    goto LAB7;

LAB12:    xsi_set_current_line(39, ng0);

LAB14:    xsi_set_current_line(39, ng0);
    t15 = (t1 + 2728U);
    t16 = *((char **)t15);
    t15 = (t1 + 5208);
    t17 = (t1 + 5208);
    t18 = (t17 + 72U);
    t21 = *((char **)t18);
    t22 = (t1 + 5368);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    xsi_vlog_generic_convert_bit_index(t9, t21, 2, t24, 32, 1);
    t25 = (t9 + 4);
    t26 = *((unsigned int *)t25);
    t13 = (!(t26));
    if (t13 == 1)
        goto LAB15;

LAB16:    xsi_set_current_line(39, ng0);
    t4 = (t1 + 880);
    t5 = *((char **)t4);
    t4 = (t5 + 4);
    t10 = *((unsigned int *)t4);
    t11 = (~(t10));
    t12 = *((unsigned int *)t5);
    t13 = (t12 & t11);
    t6 = (t1 + 9216);
    *((int *)t6) = t13;

LAB17:    t7 = (t1 + 9216);
    if (*((int *)t7) > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(39, ng0);
    t4 = (t1 + 5368);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng3)));
    memset(t8, 0, 8);
    xsi_vlog_signed_add(t8, 32, t6, 32, t7, 32);
    t14 = (t1 + 5368);
    xsi_vlogvar_assign_value(t14, t8, 0, 0, 32);
    goto LAB11;

LAB15:    xsi_vlogvar_assign_value(t15, t16, 0, *((unsigned int *)t9), 1);
    goto LAB16;

LAB18:    xsi_set_current_line(39, ng0);
    t14 = (t2 + 88U);
    t15 = *((char **)t14);
    t16 = (t15 + 32U);
    xsi_wp_set_status(t16, 1);
    *((char **)t3) = &&LAB20;
    goto LAB1;

LAB20:    t4 = (t1 + 9216);
    t13 = *((int *)t4);
    *((int *)t4) = (t13 - 1);
    goto LAB17;

}

static void Always_12_0(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 6280U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(12, ng0);
    t2 = (t0 + 6088);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(12, ng0);
    t4 = (t0 + 3448);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB8;

LAB6:    if (*((unsigned int *)t7) == 0)
        goto LAB5;

LAB7:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB8:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB10;

LAB9:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 3448);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB5:    *((unsigned int *)t3) = 1;
    goto LAB8;

LAB10:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB9;

}

static void Initial_43_1(char *t0)
{
    char t12[8];
    char t17[8];
    char *t1;
    char *t2;
    char *t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    int t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;

LAB0:    t1 = (t0 + 6528U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(43, ng0);

LAB4:    xsi_set_current_line(44, ng0);
    t2 = (t0 + 4248);
    xsi_vlogfile_readmemh(ng5, 0, t2, 0, 0, 0, 0);
    xsi_set_current_line(45, ng0);
    t2 = (t0 + 4088);
    xsi_vlogfile_readmemh(ng6, 0, t2, 0, 0, 0, 0);
    xsi_set_current_line(47, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t2 + 4);
    t4 = *((unsigned int *)t3);
    t5 = (~(t4));
    t6 = *((unsigned int *)t2);
    t7 = (t6 & t5);
    t8 = (t0 + 9220);
    *((int *)t8) = t7;

LAB5:    t9 = (t0 + 9220);
    if (*((int *)t9) > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(48, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3608);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(49, ng0);
    t2 = ((char*)((ng7)));
    t3 = (t2 + 4);
    t4 = *((unsigned int *)t3);
    t5 = (~(t4));
    t6 = *((unsigned int *)t2);
    t7 = (t6 & t5);
    t8 = (t0 + 9224);
    *((int *)t8) = t7;

LAB9:    t9 = (t0 + 9224);
    if (*((int *)t9) > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(51, ng0);
    xsi_set_current_line(51, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB13:    t2 = (t0 + 4408);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    t9 = ((char*)((ng8)));
    memset(t12, 0, 8);
    xsi_vlog_signed_less(t12, 32, t8, 32, t9, 32);
    t10 = (t12 + 4);
    t4 = *((unsigned int *)t10);
    t5 = (~(t4));
    t6 = *((unsigned int *)t12);
    t13 = (t6 & t5);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB14;

LAB15:    xsi_set_current_line(52, ng0);
    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB22:    t2 = (t0 + 4408);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    t9 = (t0 + 1152);
    t10 = *((char **)t9);
    memset(t12, 0, 8);
    xsi_vlog_signed_less(t12, 32, t8, 32, t10, 32);
    t9 = (t12 + 4);
    t4 = *((unsigned int *)t9);
    t5 = (~(t4));
    t6 = *((unsigned int *)t12);
    t13 = (t6 & t5);
    t14 = (t13 != 0);
    if (t14 > 0)
        goto LAB23;

LAB24:    xsi_set_current_line(57, ng0);
    t2 = ((char*)((ng9)));
    t3 = (t2 + 4);
    t4 = *((unsigned int *)t3);
    t5 = (~(t4));
    t6 = *((unsigned int *)t2);
    t7 = (t6 & t5);
    t8 = (t0 + 9228);
    *((int *)t8) = t7;

LAB44:    t9 = (t0 + 9228);
    if (*((int *)t9) > 0)
        goto LAB45;

LAB46:    xsi_set_current_line(58, ng0);
    t2 = (t0 + 1152);
    t3 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng10, 2, t0, (char)119, t3, 32);
    xsi_set_current_line(59, ng0);
    xsi_vlog_finish(1);

LAB1:    return;
LAB6:    xsi_set_current_line(47, ng0);
    t10 = (t0 + 7192);
    *((int *)t10) = 1;
    t11 = (t0 + 6560);
    *((char **)t11) = t10;
    *((char **)t1) = &&LAB8;
    goto LAB1;

LAB8:    t2 = (t0 + 9220);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB5;

LAB10:    xsi_set_current_line(49, ng0);
    t10 = (t0 + 7208);
    *((int *)t10) = 1;
    t11 = (t0 + 6560);
    *((char **)t11) = t10;
    *((char **)t1) = &&LAB12;
    goto LAB1;

LAB12:    t2 = (t0 + 9224);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB9;

LAB14:    xsi_set_current_line(51, ng0);
    t11 = (t0 + 4248);
    t15 = (t11 + 56U);
    t16 = *((char **)t15);
    t18 = (t0 + 4248);
    t19 = (t18 + 72U);
    t20 = *((char **)t19);
    t21 = (t0 + 4248);
    t22 = (t21 + 64U);
    t23 = *((char **)t22);
    t24 = (t0 + 4408);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    xsi_vlog_generic_get_array_select_value(t17, 8, t16, t20, t23, 2, 1, t26, 32, 1);
    t27 = (t0 + 6336);
    t28 = (t0 + 1664);
    t29 = xsi_create_subprogram_invocation(t27, 0, t0, t28, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t28, t29);
    t30 = (t0 + 4888);
    xsi_vlogvar_assign_value(t30, t17, 0, 0, 8);

LAB18:    t31 = (t0 + 6432);
    t32 = *((char **)t31);
    t33 = (t32 + 80U);
    t34 = *((char **)t33);
    t35 = (t34 + 272U);
    t36 = *((char **)t35);
    t37 = (t36 + 0U);
    t38 = *((char **)t37);
    t7 = ((int  (*)(char *, char *))t38)(t0, t32);

LAB20:    if (t7 != 0)
        goto LAB21;

LAB16:    t32 = (t0 + 1664);
    xsi_vlog_subprogram_popinvocation(t32);

LAB17:    t39 = (t0 + 6432);
    t40 = *((char **)t39);
    t39 = (t0 + 1664);
    t41 = (t0 + 6336);
    t42 = 0;
    xsi_delete_subprogram_invocation(t39, t40, t0, t41, t42);
    xsi_set_current_line(51, ng0);
    t2 = (t0 + 4408);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    t9 = ((char*)((ng3)));
    memset(t12, 0, 8);
    xsi_vlog_signed_add(t12, 32, t8, 32, t9, 32);
    t10 = (t0 + 4408);
    xsi_vlogvar_assign_value(t10, t12, 0, 0, 32);
    goto LAB13;

LAB19:;
LAB21:    t31 = (t0 + 6528U);
    *((char **)t31) = &&LAB18;
    goto LAB1;

LAB23:    xsi_set_current_line(52, ng0);

LAB25:    xsi_set_current_line(53, ng0);
    t11 = (t0 + 4088);
    t15 = (t11 + 56U);
    t16 = *((char **)t15);
    t18 = (t0 + 4088);
    t19 = (t18 + 72U);
    t20 = *((char **)t19);
    t21 = (t0 + 4088);
    t22 = (t21 + 64U);
    t23 = *((char **)t22);
    t24 = (t0 + 4408);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    xsi_vlog_generic_get_array_select_value(t17, 8, t16, t20, t23, 2, 1, t26, 32, 1);
    t27 = (t0 + 6336);
    t28 = (t0 + 1664);
    t29 = xsi_create_subprogram_invocation(t27, 0, t0, t28, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t28, t29);
    t30 = (t0 + 4888);
    xsi_vlogvar_assign_value(t30, t17, 0, 0, 8);

LAB28:    t31 = (t0 + 6432);
    t32 = *((char **)t31);
    t33 = (t32 + 80U);
    t34 = *((char **)t33);
    t35 = (t34 + 272U);
    t36 = *((char **)t35);
    t37 = (t36 + 0U);
    t38 = *((char **)t37);
    t7 = ((int  (*)(char *, char *))t38)(t0, t32);

LAB30:    if (t7 != 0)
        goto LAB31;

LAB26:    t32 = (t0 + 1664);
    xsi_vlog_subprogram_popinvocation(t32);

LAB27:    t39 = (t0 + 6432);
    t40 = *((char **)t39);
    t39 = (t0 + 1664);
    t41 = (t0 + 6336);
    t42 = 0;
    xsi_delete_subprogram_invocation(t39, t40, t0, t41, t42);
    xsi_set_current_line(54, ng0);
    t2 = (t0 + 6336);
    t3 = (t0 + 2096);
    t8 = xsi_create_subprogram_invocation(t2, 0, t0, t3, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t3, t8);

LAB34:    t9 = (t0 + 6432);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t15 = *((char **)t11);
    t16 = (t15 + 272U);
    t18 = *((char **)t16);
    t19 = (t18 + 0U);
    t20 = *((char **)t19);
    t7 = ((int  (*)(char *, char *))t20)(t0, t10);

LAB36:    if (t7 != 0)
        goto LAB37;

LAB32:    t10 = (t0 + 2096);
    xsi_vlog_subprogram_popinvocation(t10);

LAB33:    t21 = (t0 + 6432);
    t22 = *((char **)t21);
    t21 = (t0 + 5208);
    t23 = (t21 + 56U);
    t24 = *((char **)t23);
    t25 = (t0 + 4568);
    xsi_vlogvar_assign_value(t25, t24, 0, 0, 8);
    t26 = (t0 + 2096);
    t27 = (t0 + 6336);
    t28 = 0;
    xsi_delete_subprogram_invocation(t26, t22, t0, t27, t28);
    xsi_set_current_line(54, ng0);
    t2 = (t0 + 6336);
    t3 = (t0 + 2096);
    t8 = xsi_create_subprogram_invocation(t2, 0, t0, t3, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t3, t8);

LAB40:    t9 = (t0 + 6432);
    t10 = *((char **)t9);
    t11 = (t10 + 80U);
    t15 = *((char **)t11);
    t16 = (t15 + 272U);
    t18 = *((char **)t16);
    t19 = (t18 + 0U);
    t20 = *((char **)t19);
    t7 = ((int  (*)(char *, char *))t20)(t0, t10);

LAB42:    if (t7 != 0)
        goto LAB43;

LAB38:    t10 = (t0 + 2096);
    xsi_vlog_subprogram_popinvocation(t10);

LAB39:    t21 = (t0 + 6432);
    t22 = *((char **)t21);
    t21 = (t0 + 5208);
    t23 = (t21 + 56U);
    t24 = *((char **)t23);
    t25 = (t0 + 4728);
    xsi_vlogvar_assign_value(t25, t24, 0, 0, 8);
    t26 = (t0 + 2096);
    t27 = (t0 + 6336);
    t28 = 0;
    xsi_delete_subprogram_invocation(t26, t22, t0, t27, t28);
    xsi_set_current_line(52, ng0);
    t2 = (t0 + 4408);
    t3 = (t2 + 56U);
    t8 = *((char **)t3);
    t9 = ((char*)((ng3)));
    memset(t12, 0, 8);
    xsi_vlog_signed_add(t12, 32, t8, 32, t9, 32);
    t10 = (t0 + 4408);
    xsi_vlogvar_assign_value(t10, t12, 0, 0, 32);
    goto LAB22;

LAB29:;
LAB31:    t31 = (t0 + 6528U);
    *((char **)t31) = &&LAB28;
    goto LAB1;

LAB35:;
LAB37:    t9 = (t0 + 6528U);
    *((char **)t9) = &&LAB34;
    goto LAB1;

LAB41:;
LAB43:    t9 = (t0 + 6528U);
    *((char **)t9) = &&LAB40;
    goto LAB1;

LAB45:    xsi_set_current_line(57, ng0);
    t10 = (t0 + 7224);
    *((int *)t10) = 1;
    t11 = (t0 + 6560);
    *((char **)t11) = t10;
    *((char **)t1) = &&LAB47;
    goto LAB1;

LAB47:    t2 = (t0 + 9228);
    t7 = *((int *)t2);
    *((int *)t2) = (t7 - 1);
    goto LAB44;

}

static void Initial_62_2(char *t0)
{
    char *t1;
    char *t2;

LAB0:    t1 = (t0 + 6776U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(62, ng0);

LAB4:    xsi_set_current_line(62, ng0);
    t2 = (t0 + 6584);
    xsi_process_wait(t2, 500000000000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(62, ng0);
    xsi_vlogfile_write(1, 0, 0, ng11, 1, t0);
    xsi_set_current_line(62, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

}


extern void work_m_16148357019500143545_1148087835_init()
{
	static char *pe[] = {(void *)Always_12_0,(void *)Initial_43_1,(void *)Initial_62_2};
	static char *se[] = {(void *)sp_send,(void *)sp_recv};
	xsi_register_didat("work_m_16148357019500143545_1148087835", "isim/power_same_pr_isim.sim/work/m_16148357019500143545_1148087835.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
