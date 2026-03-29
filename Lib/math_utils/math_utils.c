/**
 * @file math_utils.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-03-24
 * 
 * 
 */

/* C Standard Library Includes -----------------------------------*/
#include "math.h"
/* HAL Includes --------------------------------------------------*/

/* Private Includes ----------------------------------------------*/
#include "math_utils.h"
/* =============================================================== */

/* Defines ------------------------------------------------*/

/* Variables ----------------------------------------------*/

/* Objects ------------------------------------------------*/

/* =============================================================== */

/* Internal Functions ---------------------------------------------*/

/* =============================================================== */

/* External Functions ---------------------------------------------*/

/**
 * @brief 对称限幅函数 输出范围：[-limit, +limit]
 * 
 * @param x 输入值
 * @param limit 正限幅值
 * @return float 输出结果
 */
float clamp(float x, float limit) {
    if (x > limit) return limit;
    if (x < -limit) return -limit;
    return x;
}

/**
 * @brief 模空间最小差值计算（环空间差分）
 *
 * 计算在模空间（周期为 mod）下，从 y 到 x 的最短差值，
 * 并将结果映射到区间 (-mod/2, mod/2] 内。
 *
 * 常用于编码器、角度、相位等“环形量”的连续化处理（unwrap）。
 *
 * @param x 当前值（current）
 * @param y 上一时刻值（previous）
 * @param mod 模（周期），例如 8192 或 2π
 * @return float 最小差值（已消除跳变）
 */
float wrap_delta(float x, float y, float mod) {
    float delta = x - y;

    if (delta > mod * 0.5f)
        delta -= mod;
    else if (delta < -mod * 0.5f)
        delta += mod;

    return delta;
}

/* Test -----------------------------------------------------------*/
