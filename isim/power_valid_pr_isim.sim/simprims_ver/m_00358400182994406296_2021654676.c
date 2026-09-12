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



static void Gate_29_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;

LAB0:    t1 = (t0 + 2496U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 1344U);
    t3 = *((char **)t2);
    t2 = (t0 + 2896);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 4);
    t9 = (t3 + 4);
    if (*((unsigned int *)t9) == 1)
        goto LAB4;

LAB5:    t10 = *((unsigned int *)t3);
    t11 = (t10 & 1);
    *((unsigned int *)t7) = t11;
    t12 = *((unsigned int *)t9);
    t13 = (t12 & 1);
    *((unsigned int *)t8) = t13;

LAB6:    t14 = (t0 + 2896);
    xsi_driver_vfirst_trans(t14, 0, 0);
    t15 = (t0 + 2816);
    *((int *)t15) = 1;

LAB1:    return;
LAB4:    *((unsigned int *)t7) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB6;

}


extern void simprims_ver_m_00358400182994406296_2021654676_init()
{
	static char *pe[] = {(void *)Gate_29_0};
	xsi_register_didat("simprims_ver_m_00358400182994406296_2021654676", "isim/power_valid_pr_isim.sim/simprims_ver/m_00358400182994406296_2021654676.didat");
	xsi_register_executes(pe);
}

extern void simprims_ver_m_00358400182994406296_2021654676_4018009579_init()
{
	static char *pe[] = {(void *)Gate_29_0};
	xsi_register_didat("simprims_ver_m_00358400182994406296_2021654676_4018009579", "isim/power_valid_pr_isim.sim/simprims_ver/m_00358400182994406296_2021654676_4018009579.didat");
	xsi_register_executes(pe);
}

extern void simprims_ver_m_00358400182994406296_2021654676_3858086255_init()
{
	static char *pe[] = {(void *)Gate_29_0};
	xsi_register_didat("simprims_ver_m_00358400182994406296_2021654676_3858086255", "isim/power_valid_pr_isim.sim/simprims_ver/m_00358400182994406296_2021654676_3858086255.didat");
	xsi_register_executes(pe);
}

extern void simprims_ver_m_00358400182994406296_2021654676_2493650221_init()
{
	static char *pe[] = {(void *)Gate_29_0};
	xsi_register_didat("simprims_ver_m_00358400182994406296_2021654676_2493650221", "isim/power_valid_pr_isim.sim/simprims_ver/m_00358400182994406296_2021654676_2493650221.didat");
	xsi_register_executes(pe);
}

extern void simprims_ver_m_00358400182994406296_2021654676_1638245635_init()
{
	static char *pe[] = {(void *)Gate_29_0};
	xsi_register_didat("simprims_ver_m_00358400182994406296_2021654676_1638245635", "isim/power_valid_pr_isim.sim/simprims_ver/m_00358400182994406296_2021654676_1638245635.didat");
	xsi_register_executes(pe);
}

extern void simprims_ver_m_00358400182994406296_2021654676_1897686147_init()
{
	static char *pe[] = {(void *)Gate_29_0};
	xsi_register_didat("simprims_ver_m_00358400182994406296_2021654676_1897686147", "isim/power_valid_pr_isim.sim/simprims_ver/m_00358400182994406296_2021654676_1897686147.didat");
	xsi_register_executes(pe);
}

extern void simprims_ver_m_00358400182994406296_2021654676_0092572940_init()
{
	static char *pe[] = {(void *)Gate_29_0};
	xsi_register_didat("simprims_ver_m_00358400182994406296_2021654676_0092572940", "isim/power_valid_pr_isim.sim/simprims_ver/m_00358400182994406296_2021654676_0092572940.didat");
	xsi_register_executes(pe);
}

extern void simprims_ver_m_00358400182994406296_2021654676_1997542013_init()
{
	static char *pe[] = {(void *)Gate_29_0};
	xsi_register_didat("simprims_ver_m_00358400182994406296_2021654676_1997542013", "isim/power_valid_pr_isim.sim/simprims_ver/m_00358400182994406296_2021654676_1997542013.didat");
	xsi_register_executes(pe);
}

extern void simprims_ver_m_00358400182994406296_2021654676_1914331132_init()
{
	static char *pe[] = {(void *)Gate_29_0};
	xsi_register_didat("simprims_ver_m_00358400182994406296_2021654676_1914331132", "isim/power_valid_pr_isim.sim/simprims_ver/m_00358400182994406296_2021654676_1914331132.didat");
	xsi_register_executes(pe);
}

extern void simprims_ver_m_00358400182994406296_2021654676_3921613715_init()
{
	static char *pe[] = {(void *)Gate_29_0};
	xsi_register_didat("simprims_ver_m_00358400182994406296_2021654676_3921613715", "isim/power_valid_pr_isim.sim/simprims_ver/m_00358400182994406296_2021654676_3921613715.didat");
	xsi_register_executes(pe);
}

extern void simprims_ver_m_00358400182994406296_2021654676_2653012323_init()
{
	static char *pe[] = {(void *)Gate_29_0};
	xsi_register_didat("simprims_ver_m_00358400182994406296_2021654676_2653012323", "isim/power_valid_pr_isim.sim/simprims_ver/m_00358400182994406296_2021654676_2653012323.didat");
	xsi_register_executes(pe);
}

extern void simprims_ver_m_00358400182994406296_2021654676_3938003180_init()
{
	static char *pe[] = {(void *)Gate_29_0};
	xsi_register_didat("simprims_ver_m_00358400182994406296_2021654676_3938003180", "isim/power_valid_pr_isim.sim/simprims_ver/m_00358400182994406296_2021654676_3938003180.didat");
	xsi_register_executes(pe);
}

extern void simprims_ver_m_00358400182994406296_2021654676_2636642844_init()
{
	static char *pe[] = {(void *)Gate_29_0};
	xsi_register_didat("simprims_ver_m_00358400182994406296_2021654676_2636642844", "isim/power_valid_pr_isim.sim/simprims_ver/m_00358400182994406296_2021654676_2636642844.didat");
	xsi_register_executes(pe);
}

extern void simprims_ver_m_00358400182994406296_2021654676_0109229683_init()
{
	static char *pe[] = {(void *)Gate_29_0};
	xsi_register_didat("simprims_ver_m_00358400182994406296_2021654676_0109229683", "isim/power_valid_pr_isim.sim/simprims_ver/m_00358400182994406296_2021654676_0109229683.didat");
	xsi_register_executes(pe);
}
