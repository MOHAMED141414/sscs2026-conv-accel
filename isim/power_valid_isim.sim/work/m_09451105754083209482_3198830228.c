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
static const char *ng0 = "/home/mohamed-esam/sscs2026-conv-accel/rtl/conv_accel.v";
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
static int ng11[] = {2, 0};
static unsigned int ng12[] = {32767U, 0U};
static unsigned int ng13[] = {4161536U, 0U};
static unsigned int ng14[] = {32768U, 0U};



static void Always_81_0(char *t0)
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

LAB0:    t1 = (t0 + 13752U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(81, ng0);
    t2 = (t0 + 20024);
    *((int *)t2) = 1;
    t3 = (t0 + 13784);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(81, ng0);

LAB5:    xsi_set_current_line(82, ng0);
    t4 = (t0 + 3000U);
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

LAB6:    xsi_set_current_line(82, ng0);

LAB9:    xsi_set_current_line(83, ng0);
    t11 = (t0 + 3160U);
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

LAB11:    xsi_set_current_line(84, ng0);
    t14 = (t0 + 3320U);
    t15 = *((char **)t14);
    t14 = (t0 + 7080);
    xsi_vlogvar_wait_assign_value(t14, t15, 0, 0, 8, 0LL);
    goto LAB31;

LAB13:    xsi_set_current_line(85, ng0);
    t3 = (t0 + 3320U);
    t4 = *((char **)t3);
    t3 = (t0 + 7240);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    goto LAB31;

LAB15:    xsi_set_current_line(86, ng0);
    t3 = (t0 + 3320U);
    t4 = *((char **)t3);
    t3 = (t0 + 7400);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    goto LAB31;

LAB17:    xsi_set_current_line(87, ng0);
    t3 = (t0 + 3320U);
    t4 = *((char **)t3);
    t3 = (t0 + 7560);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    goto LAB31;

LAB19:    xsi_set_current_line(88, ng0);
    t3 = (t0 + 3320U);
    t4 = *((char **)t3);
    t3 = (t0 + 7720);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    goto LAB31;

LAB21:    xsi_set_current_line(89, ng0);
    t3 = (t0 + 3320U);
    t4 = *((char **)t3);
    t3 = (t0 + 7880);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    goto LAB31;

LAB23:    xsi_set_current_line(90, ng0);
    t3 = (t0 + 3320U);
    t4 = *((char **)t3);
    t3 = (t0 + 8040);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    goto LAB31;

LAB25:    xsi_set_current_line(91, ng0);
    t3 = (t0 + 3320U);
    t4 = *((char **)t3);
    t3 = (t0 + 8200);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    goto LAB31;

LAB27:    xsi_set_current_line(92, ng0);
    t3 = (t0 + 3320U);
    t4 = *((char **)t3);
    t3 = (t0 + 8360);
    xsi_vlogvar_wait_assign_value(t3, t4, 0, 0, 8, 0LL);
    goto LAB31;

}

static void NetDecl_104_1(char *t0)
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

LAB0:    t1 = (t0 + 14000U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(104, ng0);
    t2 = (t0 + 8520);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 8520);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 1696);
    t10 = *((char **)t9);
    t9 = ((char*)((ng10)));
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t10, 32, t9, 32);
    t12 = (t0 + 880);
    t13 = *((char **)t12);
    xsi_vlog_get_indexed_partselect(t3, 8, t5, ((int*)(t8)), 2, t11, 32, 1, t13, 32, 1, 0);
    t12 = (t0 + 20488);
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
    t26 = (t0 + 20040);
    *((int *)t26) = 1;

LAB1:    return;
}

static void NetDecl_105_2(char *t0)
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

LAB0:    t1 = (t0 + 14248U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(105, ng0);
    t2 = (t0 + 8680);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 8680);
    t7 = (t6 + 72U);
    t8 = *((char **)t7);
    t9 = (t0 + 1696);
    t10 = *((char **)t9);
    t9 = ((char*)((ng10)));
    memset(t11, 0, 8);
    xsi_vlog_signed_minus(t11, 32, t10, 32, t9, 32);
    t12 = (t0 + 880);
    t13 = *((char **)t12);
    xsi_vlog_get_indexed_partselect(t3, 8, t5, ((int*)(t8)), 2, t11, 32, 1, t13, 32, 1, 0);
    t12 = (t0 + 20552);
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
    t26 = (t0 + 20056);
    *((int *)t26) = 1;

LAB1:    return;
}

static void Always_107_3(char *t0)
{
    char t11[64];
    char t14[64];
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
    char *t12;
    char *t13;
    char *t15;
    char *t16;
    char *t17;

LAB0:    t1 = (t0 + 14496U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(107, ng0);
    t2 = (t0 + 20072);
    *((int *)t2) = 1;
    t3 = (t0 + 14528);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(107, ng0);

LAB5:    xsi_set_current_line(108, ng0);
    t4 = (t0 + 3800U);
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

LAB6:    xsi_set_current_line(108, ng0);

LAB9:    xsi_set_current_line(109, ng0);
    t12 = (t0 + 3960U);
    t13 = *((char **)t12);
    t12 = (t0 + 8520);
    t15 = (t12 + 56U);
    t16 = *((char **)t15);
    xsi_vlog_get_part_select_value(t14, 248, t16, 247, 0);
    xsi_vlogtype_concat(t11, 256, 256, 2U, t14, 248, t13, 8);
    t17 = (t0 + 8520);
    xsi_vlogvar_wait_assign_value(t17, t11, 0, 0, 256, 0LL);
    xsi_set_current_line(110, ng0);
    t2 = (t0 + 4120U);
    t3 = *((char **)t2);
    t2 = (t0 + 8680);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    xsi_vlog_get_part_select_value(t14, 248, t5, 247, 0);
    xsi_vlogtype_concat(t11, 256, 256, 2U, t14, 248, t3, 8);
    t12 = (t0 + 8680);
    xsi_vlogvar_wait_assign_value(t12, t11, 0, 0, 256, 0LL);
    goto LAB8;

}

static void Always_121_4(char *t0)
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

LAB0:    t1 = (t0 + 14744U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(121, ng0);
    t2 = (t0 + 20088);
    *((int *)t2) = 1;
    t3 = (t0 + 14776);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(121, ng0);

LAB5:    xsi_set_current_line(122, ng0);
    t4 = (t0 + 3800U);
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

LAB6:    xsi_set_current_line(122, ng0);

LAB9:    xsi_set_current_line(123, ng0);
    t11 = (t0 + 9000);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t0 + 8840);
    xsi_vlogvar_wait_assign_value(t14, t13, 0, 0, 8, 0LL);
    xsi_set_current_line(123, ng0);
    t2 = (t0 + 9160);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 9000);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(123, ng0);
    t2 = (t0 + 4280U);
    t3 = *((char **)t2);
    t2 = (t0 + 9160);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 8, 0LL);
    xsi_set_current_line(124, ng0);
    t2 = (t0 + 9480);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 9320);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(124, ng0);
    t2 = (t0 + 9640);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 9480);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(124, ng0);
    t2 = (t0 + 4120U);
    t3 = *((char **)t2);
    t2 = (t0 + 9640);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 8, 0LL);
    xsi_set_current_line(125, ng0);
    t2 = (t0 + 9960);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 9800);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(125, ng0);
    t2 = (t0 + 10120);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 9960);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 8, 0LL);
    xsi_set_current_line(125, ng0);
    t2 = (t0 + 3960U);
    t3 = *((char **)t2);
    t2 = (t0 + 10120);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 8, 0LL);
    goto LAB8;

}

static void NetDecl_134_5(char *t0)
{
    char t4[8];
    char t19[8];
    char t23[8];
    char t31[8];
    char t63[8];
    char t79[8];
    char t83[8];
    char t91[8];
    char *t1;
    char *t2;
    char *t3;
    unsigned int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    char *t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t20;
    char *t21;
    char *t22;
    char *t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    unsigned int t29;
    char *t30;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;
    char *t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    int t55;
    int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    char *t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    char *t70;
    char *t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t76;
    char *t77;
    char *t78;
    char *t80;
    char *t81;
    char *t82;
    char *t84;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    char *t90;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    char *t95;
    char *t96;
    char *t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    char *t105;
    char *t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    int t115;
    int t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    unsigned int t122;
    char *t123;
    char *t124;
    char *t125;
    char *t126;
    char *t127;
    unsigned int t128;
    unsigned int t129;
    char *t130;
    unsigned int t131;
    unsigned int t132;
    char *t133;
    unsigned int t134;
    unsigned int t135;
    char *t136;

LAB0:    t1 = (t0 + 14992U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(134, ng0);
    t2 = (t0 + 3800U);
    t3 = *((char **)t2);
    memset(t4, 0, 8);
    t2 = (t3 + 4);
    t5 = *((unsigned int *)t2);
    t6 = (~(t5));
    t7 = *((unsigned int *)t3);
    t8 = (t7 & t6);
    t9 = (t8 & 1U);
    if (t9 != 0)
        goto LAB4;

LAB5:    if (*((unsigned int *)t2) != 0)
        goto LAB6;

LAB7:    t11 = (t4 + 4);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t11);
    t14 = (t12 || t13);
    if (t14 > 0)
        goto LAB8;

LAB9:    memcpy(t31, t4, 8);

LAB10:    memset(t63, 0, 8);
    t64 = (t31 + 4);
    t65 = *((unsigned int *)t64);
    t66 = (~(t65));
    t67 = *((unsigned int *)t31);
    t68 = (t67 & t66);
    t69 = (t68 & 1U);
    if (t69 != 0)
        goto LAB23;

LAB24:    if (*((unsigned int *)t64) != 0)
        goto LAB25;

LAB26:    t71 = (t63 + 4);
    t72 = *((unsigned int *)t63);
    t73 = *((unsigned int *)t71);
    t74 = (t72 || t73);
    if (t74 > 0)
        goto LAB27;

LAB28:    memcpy(t91, t63, 8);

LAB29:    t123 = (t0 + 20616);
    t124 = (t123 + 56U);
    t125 = *((char **)t124);
    t126 = (t125 + 56U);
    t127 = *((char **)t126);
    memset(t127, 0, 8);
    t128 = 1U;
    t129 = t128;
    t130 = (t91 + 4);
    t131 = *((unsigned int *)t91);
    t128 = (t128 & t131);
    t132 = *((unsigned int *)t130);
    t129 = (t129 & t132);
    t133 = (t127 + 4);
    t134 = *((unsigned int *)t127);
    *((unsigned int *)t127) = (t134 | t128);
    t135 = *((unsigned int *)t133);
    *((unsigned int *)t133) = (t135 | t129);
    xsi_driver_vfirst_trans(t123, 0, 0U);
    t136 = (t0 + 20104);
    *((int *)t136) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t4) = 1;
    goto LAB7;

LAB6:    t10 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t10) = 1;
    goto LAB7;

LAB8:    t15 = (t0 + 10440);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = ((char*)((ng11)));
    memset(t19, 0, 8);
    t20 = (t17 + 4);
    if (*((unsigned int *)t20) != 0)
        goto LAB12;

LAB11:    t21 = (t18 + 4);
    if (*((unsigned int *)t21) != 0)
        goto LAB12;

LAB15:    if (*((unsigned int *)t17) < *((unsigned int *)t18))
        goto LAB14;

LAB13:    *((unsigned int *)t19) = 1;

LAB14:    memset(t23, 0, 8);
    t24 = (t19 + 4);
    t25 = *((unsigned int *)t24);
    t26 = (~(t25));
    t27 = *((unsigned int *)t19);
    t28 = (t27 & t26);
    t29 = (t28 & 1U);
    if (t29 != 0)
        goto LAB16;

LAB17:    if (*((unsigned int *)t24) != 0)
        goto LAB18;

LAB19:    t32 = *((unsigned int *)t4);
    t33 = *((unsigned int *)t23);
    t34 = (t32 & t33);
    *((unsigned int *)t31) = t34;
    t35 = (t4 + 4);
    t36 = (t23 + 4);
    t37 = (t31 + 4);
    t38 = *((unsigned int *)t35);
    t39 = *((unsigned int *)t36);
    t40 = (t38 | t39);
    *((unsigned int *)t37) = t40;
    t41 = *((unsigned int *)t37);
    t42 = (t41 != 0);
    if (t42 == 1)
        goto LAB20;

LAB21:
LAB22:    goto LAB10;

LAB12:    t22 = (t19 + 4);
    *((unsigned int *)t19) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB14;

LAB16:    *((unsigned int *)t23) = 1;
    goto LAB19;

LAB18:    t30 = (t23 + 4);
    *((unsigned int *)t23) = 1;
    *((unsigned int *)t30) = 1;
    goto LAB19;

LAB20:    t43 = *((unsigned int *)t31);
    t44 = *((unsigned int *)t37);
    *((unsigned int *)t31) = (t43 | t44);
    t45 = (t4 + 4);
    t46 = (t23 + 4);
    t47 = *((unsigned int *)t4);
    t48 = (~(t47));
    t49 = *((unsigned int *)t45);
    t50 = (~(t49));
    t51 = *((unsigned int *)t23);
    t52 = (~(t51));
    t53 = *((unsigned int *)t46);
    t54 = (~(t53));
    t55 = (t48 & t50);
    t56 = (t52 & t54);
    t57 = (~(t55));
    t58 = (~(t56));
    t59 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t59 & t57);
    t60 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t60 & t58);
    t61 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t61 & t57);
    t62 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t62 & t58);
    goto LAB22;

LAB23:    *((unsigned int *)t63) = 1;
    goto LAB26;

LAB25:    t70 = (t63 + 4);
    *((unsigned int *)t63) = 1;
    *((unsigned int *)t70) = 1;
    goto LAB26;

LAB27:    t75 = (t0 + 10280);
    t76 = (t75 + 56U);
    t77 = *((char **)t76);
    t78 = ((char*)((ng11)));
    memset(t79, 0, 8);
    t80 = (t77 + 4);
    if (*((unsigned int *)t80) != 0)
        goto LAB31;

LAB30:    t81 = (t78 + 4);
    if (*((unsigned int *)t81) != 0)
        goto LAB31;

LAB34:    if (*((unsigned int *)t77) < *((unsigned int *)t78))
        goto LAB33;

LAB32:    *((unsigned int *)t79) = 1;

LAB33:    memset(t83, 0, 8);
    t84 = (t79 + 4);
    t85 = *((unsigned int *)t84);
    t86 = (~(t85));
    t87 = *((unsigned int *)t79);
    t88 = (t87 & t86);
    t89 = (t88 & 1U);
    if (t89 != 0)
        goto LAB35;

LAB36:    if (*((unsigned int *)t84) != 0)
        goto LAB37;

LAB38:    t92 = *((unsigned int *)t63);
    t93 = *((unsigned int *)t83);
    t94 = (t92 & t93);
    *((unsigned int *)t91) = t94;
    t95 = (t63 + 4);
    t96 = (t83 + 4);
    t97 = (t91 + 4);
    t98 = *((unsigned int *)t95);
    t99 = *((unsigned int *)t96);
    t100 = (t98 | t99);
    *((unsigned int *)t97) = t100;
    t101 = *((unsigned int *)t97);
    t102 = (t101 != 0);
    if (t102 == 1)
        goto LAB39;

LAB40:
LAB41:    goto LAB29;

LAB31:    t82 = (t79 + 4);
    *((unsigned int *)t79) = 1;
    *((unsigned int *)t82) = 1;
    goto LAB33;

LAB35:    *((unsigned int *)t83) = 1;
    goto LAB38;

LAB37:    t90 = (t83 + 4);
    *((unsigned int *)t83) = 1;
    *((unsigned int *)t90) = 1;
    goto LAB38;

LAB39:    t103 = *((unsigned int *)t91);
    t104 = *((unsigned int *)t97);
    *((unsigned int *)t91) = (t103 | t104);
    t105 = (t63 + 4);
    t106 = (t83 + 4);
    t107 = *((unsigned int *)t63);
    t108 = (~(t107));
    t109 = *((unsigned int *)t105);
    t110 = (~(t109));
    t111 = *((unsigned int *)t83);
    t112 = (~(t111));
    t113 = *((unsigned int *)t106);
    t114 = (~(t113));
    t115 = (t108 & t110);
    t116 = (t112 & t114);
    t117 = (~(t115));
    t118 = (~(t116));
    t119 = *((unsigned int *)t97);
    *((unsigned int *)t97) = (t119 & t117);
    t120 = *((unsigned int *)t97);
    *((unsigned int *)t97) = (t120 & t118);
    t121 = *((unsigned int *)t91);
    *((unsigned int *)t91) = (t121 & t117);
    t122 = *((unsigned int *)t91);
    *((unsigned int *)t91) = (t122 & t118);
    goto LAB41;

}

static void Always_136_6(char *t0)
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

LAB0:    t1 = (t0 + 15240U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(136, ng0);
    t2 = (t0 + 20120);
    *((int *)t2) = 1;
    t3 = (t0 + 15272);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(136, ng0);

LAB5:    xsi_set_current_line(137, ng0);
    t4 = (t0 + 2840U);
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

LAB21:    xsi_set_current_line(140, ng0);
    t2 = (t0 + 3800U);
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

LAB10:    t18 = (t0 + 3640U);
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

LAB20:    xsi_set_current_line(137, ng0);

LAB23:    xsi_set_current_line(138, ng0);
    t61 = ((char*)((ng1)));
    t62 = (t0 + 10280);
    xsi_vlogvar_wait_assign_value(t62, t61, 0, 0, 16, 0LL);
    xsi_set_current_line(139, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 10440);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 16, 0LL);
    goto LAB22;

LAB24:    xsi_set_current_line(140, ng0);

LAB27:    xsi_set_current_line(141, ng0);
    t4 = (t0 + 10280);
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

LAB33:    xsi_set_current_line(144, ng0);

LAB36:    xsi_set_current_line(145, ng0);
    t2 = (t0 + 10280);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 16, t4, 16, t5, 16);
    t12 = (t0 + 10280);
    xsi_vlogvar_wait_assign_value(t12, t6, 0, 0, 16, 0LL);

LAB34:    goto LAB26;

LAB30:    t31 = (t20 + 4);
    *((unsigned int *)t20) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB31;

LAB32:    xsi_set_current_line(141, ng0);

LAB35:    xsi_set_current_line(142, ng0);
    t33 = ((char*)((ng1)));
    t41 = (t0 + 10280);
    xsi_vlogvar_wait_assign_value(t41, t33, 0, 0, 16, 0LL);
    xsi_set_current_line(143, ng0);
    t2 = (t0 + 10440);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 16, t4, 16, t5, 16);
    t12 = (t0 + 10440);
    xsi_vlogvar_wait_assign_value(t12, t6, 0, 0, 16, 0LL);
    goto LAB34;

}

static void NetDecl_159_7(char *t0)
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

LAB0:    t1 = (t0 + 15488U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(159, ng0);
    t2 = (t0 + 8840);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    xsi_vlogtype_concat(t4, 9, 9, 2U, t7, 1, t6, 8);
    t8 = (t0 + 20680);
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
    t21 = (t0 + 20136);
    *((int *)t21) = 1;

LAB1:    return;
}

static void NetDecl_160_8(char *t0)
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

LAB0:    t1 = (t0 + 15736U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(160, ng0);
    t2 = (t0 + 9000);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    xsi_vlogtype_concat(t4, 9, 9, 2U, t7, 1, t6, 8);
    t8 = (t0 + 20744);
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
    t21 = (t0 + 20152);
    *((int *)t21) = 1;

LAB1:    return;
}

static void NetDecl_161_9(char *t0)
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

LAB0:    t1 = (t0 + 15984U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(161, ng0);
    t2 = (t0 + 9160);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    xsi_vlogtype_concat(t4, 9, 9, 2U, t7, 1, t6, 8);
    t8 = (t0 + 20808);
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
    t21 = (t0 + 20168);
    *((int *)t21) = 1;

LAB1:    return;
}

static void NetDecl_162_10(char *t0)
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

LAB0:    t1 = (t0 + 16232U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(162, ng0);
    t2 = (t0 + 9320);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    xsi_vlogtype_concat(t4, 9, 9, 2U, t7, 1, t6, 8);
    t8 = (t0 + 20872);
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
    t21 = (t0 + 20184);
    *((int *)t21) = 1;

LAB1:    return;
}

static void NetDecl_163_11(char *t0)
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

LAB0:    t1 = (t0 + 16480U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(163, ng0);
    t2 = (t0 + 9480);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    xsi_vlogtype_concat(t4, 9, 9, 2U, t7, 1, t6, 8);
    t8 = (t0 + 20936);
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
    t21 = (t0 + 20200);
    *((int *)t21) = 1;

LAB1:    return;
}

static void NetDecl_164_12(char *t0)
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

LAB0:    t1 = (t0 + 16728U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(164, ng0);
    t2 = (t0 + 9640);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    xsi_vlogtype_concat(t4, 9, 9, 2U, t7, 1, t6, 8);
    t8 = (t0 + 21000);
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
    t21 = (t0 + 20216);
    *((int *)t21) = 1;

LAB1:    return;
}

static void NetDecl_165_13(char *t0)
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

LAB0:    t1 = (t0 + 16976U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(165, ng0);
    t2 = (t0 + 9800);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    xsi_vlogtype_concat(t4, 9, 9, 2U, t7, 1, t6, 8);
    t8 = (t0 + 21064);
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
    t21 = (t0 + 20232);
    *((int *)t21) = 1;

LAB1:    return;
}

static void NetDecl_166_14(char *t0)
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

LAB0:    t1 = (t0 + 17224U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(166, ng0);
    t2 = (t0 + 9960);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    xsi_vlogtype_concat(t4, 9, 9, 2U, t7, 1, t6, 8);
    t8 = (t0 + 21128);
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
    t21 = (t0 + 20248);
    *((int *)t21) = 1;

LAB1:    return;
}

static void NetDecl_167_15(char *t0)
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

LAB0:    t1 = (t0 + 17472U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(167, ng0);
    t2 = (t0 + 10120);
    t5 = (t2 + 56U);
    t6 = *((char **)t5);
    t7 = ((char*)((ng1)));
    xsi_vlogtype_concat(t4, 9, 9, 2U, t7, 1, t6, 8);
    t8 = (t0 + 21192);
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
    t21 = (t0 + 20264);
    *((int *)t21) = 1;

LAB1:    return;
}

static void Always_171_16(char *t0)
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

LAB0:    t1 = (t0 + 17720U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(171, ng0);
    t2 = (t0 + 20280);
    *((int *)t2) = 1;
    t3 = (t0 + 17752);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(171, ng0);

LAB5:    xsi_set_current_line(172, ng0);
    t4 = (t0 + 4600U);
    t5 = *((char **)t4);
    t4 = (t0 + 7080);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t5, 9, t7, 8);
    t9 = (t0 + 11080);
    xsi_vlogvar_wait_assign_value(t9, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(173, ng0);
    t2 = (t0 + 4760U);
    t3 = *((char **)t2);
    t2 = (t0 + 7240);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t3, 9, t5, 8);
    t6 = (t0 + 11240);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(174, ng0);
    t2 = (t0 + 4920U);
    t3 = *((char **)t2);
    t2 = (t0 + 7400);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t3, 9, t5, 8);
    t6 = (t0 + 11400);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(175, ng0);
    t2 = (t0 + 5080U);
    t3 = *((char **)t2);
    t2 = (t0 + 7560);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t3, 9, t5, 8);
    t6 = (t0 + 11560);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(176, ng0);
    t2 = (t0 + 5240U);
    t3 = *((char **)t2);
    t2 = (t0 + 7720);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t3, 9, t5, 8);
    t6 = (t0 + 11720);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(177, ng0);
    t2 = (t0 + 5400U);
    t3 = *((char **)t2);
    t2 = (t0 + 7880);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t3, 9, t5, 8);
    t6 = (t0 + 11880);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(178, ng0);
    t2 = (t0 + 5560U);
    t3 = *((char **)t2);
    t2 = (t0 + 8040);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t3, 9, t5, 8);
    t6 = (t0 + 12040);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(179, ng0);
    t2 = (t0 + 5720U);
    t3 = *((char **)t2);
    t2 = (t0 + 8200);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t3, 9, t5, 8);
    t6 = (t0 + 12200);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    xsi_set_current_line(180, ng0);
    t2 = (t0 + 5880U);
    t3 = *((char **)t2);
    t2 = (t0 + 8360);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    memset(t8, 0, 8);
    xsi_vlog_signed_multiply(t8, 17, t3, 9, t5, 8);
    t6 = (t0 + 12360);
    xsi_vlogvar_wait_assign_value(t6, t8, 0, 0, 17, 0LL);
    goto LAB2;

}

static void Always_183_17(char *t0)
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

LAB0:    t1 = (t0 + 17968U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(183, ng0);
    t2 = (t0 + 20296);
    *((int *)t2) = 1;
    t3 = (t0 + 18000);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(183, ng0);
    t6 = (t0 + 2840U);
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

LAB31:    t73 = (t0 + 10600);
    xsi_vlogvar_wait_assign_value(t73, t4, 0, 0, 1, 0LL);
    goto LAB2;

LAB5:    *((unsigned int *)t8) = 1;
    goto LAB8;

LAB7:    t14 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB8;

LAB9:    t20 = (t0 + 3640U);
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

LAB25:    t73 = (t0 + 4440U);
    t74 = *((char **)t73);
    goto LAB26;

LAB27:    xsi_vlog_unsigned_bit_combine(t4, 1, t68, 1, t74, 1);
    goto LAB31;

LAB29:    memcpy(t4, t68, 8);
    goto LAB31;

}

static void Always_184_18(char *t0)
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

LAB0:    t1 = (t0 + 18216U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(184, ng0);
    t2 = (t0 + 20312);
    *((int *)t2) = 1;
    t3 = (t0 + 18248);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(184, ng0);
    t6 = (t0 + 2840U);
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

LAB31:    t76 = (t0 + 10760);
    xsi_vlogvar_wait_assign_value(t76, t4, 0, 0, 1, 0LL);
    goto LAB2;

LAB5:    *((unsigned int *)t8) = 1;
    goto LAB8;

LAB7:    t14 = (t8 + 4);
    *((unsigned int *)t8) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB8;

LAB9:    t20 = (t0 + 3640U);
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

LAB25:    t73 = (t0 + 10600);
    t74 = (t73 + 56U);
    t75 = *((char **)t74);
    goto LAB26;

LAB27:    xsi_vlog_unsigned_bit_combine(t4, 1, t68, 1, t75, 1);
    goto LAB31;

LAB29:    memcpy(t4, t68, 8);
    goto LAB31;

}

static void Always_191_19(char *t0)
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

LAB0:    t1 = (t0 + 18464U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(191, ng0);
    t2 = (t0 + 20328);
    *((int *)t2) = 1;
    t3 = (t0 + 18496);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(191, ng0);

LAB5:    xsi_set_current_line(192, ng0);
    t4 = (t0 + 11080);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t0 + 11240);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 22, t6, 17, t9, 17);
    t11 = (t0 + 11400);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memset(t14, 0, 8);
    xsi_vlog_signed_add(t14, 22, t10, 22, t13, 17);
    t15 = (t0 + 12520);
    xsi_vlogvar_wait_assign_value(t15, t14, 0, 0, 22, 0LL);
    xsi_set_current_line(193, ng0);
    t2 = (t0 + 11560);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 11720);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 22, t4, 17, t7, 17);
    t8 = (t0 + 11880);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    memset(t14, 0, 8);
    xsi_vlog_signed_add(t14, 22, t10, 22, t11, 17);
    t12 = (t0 + 12680);
    xsi_vlogvar_wait_assign_value(t12, t14, 0, 0, 22, 0LL);
    xsi_set_current_line(194, ng0);
    t2 = (t0 + 12040);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 12200);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t10, 0, 8);
    xsi_vlog_signed_add(t10, 22, t4, 17, t7, 17);
    t8 = (t0 + 12360);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    memset(t14, 0, 8);
    xsi_vlog_signed_add(t14, 22, t10, 22, t11, 17);
    t12 = (t0 + 12840);
    xsi_vlogvar_wait_assign_value(t12, t14, 0, 0, 22, 0LL);
    goto LAB2;

}

static void Always_197_20(char *t0)
{
    char t4[8];
    char t5[8];
    char *t1;
    char *t2;
    char *t3;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;

LAB0:    t1 = (t0 + 18712U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(197, ng0);
    t2 = (t0 + 20344);
    *((int *)t2) = 1;
    t3 = (t0 + 18744);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(197, ng0);
    t6 = (t0 + 2840U);
    t7 = *((char **)t6);
    memset(t5, 0, 8);
    t6 = (t7 + 4);
    t8 = *((unsigned int *)t6);
    t9 = (~(t8));
    t10 = *((unsigned int *)t7);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB5;

LAB6:    if (*((unsigned int *)t6) != 0)
        goto LAB7;

LAB8:    t14 = (t5 + 4);
    t15 = *((unsigned int *)t5);
    t16 = *((unsigned int *)t14);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB9;

LAB10:    t19 = *((unsigned int *)t5);
    t20 = (~(t19));
    t21 = *((unsigned int *)t14);
    t22 = (t20 || t21);
    if (t22 > 0)
        goto LAB11;

LAB12:    if (*((unsigned int *)t14) > 0)
        goto LAB13;

LAB14:    if (*((unsigned int *)t5) > 0)
        goto LAB15;

LAB16:    memcpy(t4, t25, 8);

LAB17:    t26 = (t0 + 10920);
    xsi_vlogvar_wait_assign_value(t26, t4, 0, 0, 1, 0LL);
    goto LAB2;

LAB5:    *((unsigned int *)t5) = 1;
    goto LAB8;

LAB7:    t13 = (t5 + 4);
    *((unsigned int *)t5) = 1;
    *((unsigned int *)t13) = 1;
    goto LAB8;

LAB9:    t18 = ((char*)((ng1)));
    goto LAB10;

LAB11:    t23 = (t0 + 10760);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    goto LAB12;

LAB13:    xsi_vlog_unsigned_bit_combine(t4, 1, t18, 1, t25, 1);
    goto LAB17;

LAB15:    memcpy(t4, t18, 8);
    goto LAB17;

}

static void NetDecl_202_21(char *t0)
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

LAB0:    t1 = (t0 + 18960U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(202, ng0);
    t2 = (t0 + 12520);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 12680);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memset(t8, 0, 8);
    xsi_vlog_signed_add(t8, 22, t4, 22, t7, 22);
    t9 = (t0 + 12840);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memset(t12, 0, 8);
    xsi_vlog_signed_add(t12, 22, t8, 22, t11, 22);
    t13 = (t0 + 21256);
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
    t26 = (t0 + 20360);
    *((int *)t26) = 1;

LAB1:    return;
}

static void NetDecl_204_22(char *t0)
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

LAB0:    t1 = (t0 + 19208U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(204, ng0);
    t2 = (t0 + 6040U);
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

LAB16:    t56 = (t0 + 21320);
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
    t69 = (t0 + 20376);
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

LAB10:    t26 = (t0 + 6040U);
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

LAB23:    t47 = (t0 + 6040U);
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

static void NetDecl_209_23(char *t0)
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

LAB0:    t1 = (t0 + 19456U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(209, ng0);
    t2 = (t0 + 3480U);
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

LAB30:    t83 = (t0 + 21384);
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
    t97 = (t0 + 20392);
    *((int *)t97) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t6) = 1;
    goto LAB7;

LAB6:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB7;

LAB8:    t17 = (t0 + 6200U);
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

LAB24:    t83 = (t0 + 6200U);
    t84 = *((char **)t83);
    goto LAB25;

LAB26:    xsi_vlog_unsigned_bit_combine(t3, 16, t78, 16, t84, 16);
    goto LAB30;

LAB28:    memcpy(t3, t78, 8);
    goto LAB30;

}

static void Always_211_24(char *t0)
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

LAB0:    t1 = (t0 + 19704U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(211, ng0);
    t2 = (t0 + 20408);
    *((int *)t2) = 1;
    t3 = (t0 + 19736);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(211, ng0);

LAB5:    xsi_set_current_line(212, ng0);
    t4 = (t0 + 2840U);
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

LAB21:    xsi_set_current_line(215, ng0);

LAB24:    xsi_set_current_line(216, ng0);
    t2 = (t0 + 10920);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t0 + 6760);
    xsi_vlogvar_wait_assign_value(t5, t4, 0, 0, 1, 0LL);
    xsi_set_current_line(217, ng0);
    t2 = (t0 + 6360U);
    t3 = *((char **)t2);
    t2 = (t0 + 6920);
    xsi_vlogvar_wait_assign_value(t2, t3, 0, 0, 16, 0LL);

LAB22:    goto LAB2;

LAB6:    *((unsigned int *)t6) = 1;
    goto LAB9;

LAB8:    t12 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t12) = 1;
    goto LAB9;

LAB10:    t18 = (t0 + 3640U);
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

LAB20:    xsi_set_current_line(212, ng0);

LAB23:    xsi_set_current_line(213, ng0);
    t61 = ((char*)((ng1)));
    t62 = (t0 + 6760);
    xsi_vlogvar_wait_assign_value(t62, t61, 0, 0, 1, 0LL);
    xsi_set_current_line(214, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 6920);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 16, 0LL);
    goto LAB22;

}


extern void work_m_09451105754083209482_3198830228_init()
{
	static char *pe[] = {(void *)Always_81_0,(void *)NetDecl_104_1,(void *)NetDecl_105_2,(void *)Always_107_3,(void *)Always_121_4,(void *)NetDecl_134_5,(void *)Always_136_6,(void *)NetDecl_159_7,(void *)NetDecl_160_8,(void *)NetDecl_161_9,(void *)NetDecl_162_10,(void *)NetDecl_163_11,(void *)NetDecl_164_12,(void *)NetDecl_165_13,(void *)NetDecl_166_14,(void *)NetDecl_167_15,(void *)Always_171_16,(void *)Always_183_17,(void *)Always_184_18,(void *)Always_191_19,(void *)Always_197_20,(void *)NetDecl_202_21,(void *)NetDecl_204_22,(void *)NetDecl_209_23,(void *)Always_211_24};
	xsi_register_didat("work_m_09451105754083209482_3198830228", "isim/power_valid_isim.sim/work/m_09451105754083209482_3198830228.didat");
	xsi_register_executes(pe);
}
